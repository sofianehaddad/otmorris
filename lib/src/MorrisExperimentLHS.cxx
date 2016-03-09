//                                               -*- C++ -*-
/**
 *  @file  MorrisExperiment.cxx
 *  @brief MorrisExperiment
 *
 *  Copyright 2005-2015 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License.
 *
 *  This library is distributed in the hope that it will be useful
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 *  @author: schueller
 */
#include "otmorris/MorrisExperimentLHS.hxx"
#include <openturns/PersistentObjectFactory.hxx>
#include <openturns/KPermutationsDistribution.hxx>
#include <openturns/UserDefined.hxx>
#include <openturns/RandomGenerator.hxx>
#include <openturns/Log.hxx>

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(MorrisExperimentLHS);

static Factory<MorrisExperimentLHS> RegisteredFactory;


/** Constructor using NumericalSample, which is supposed to be an LHS design - Uniform(0,1)^d*/
MorrisExperimentLHS::MorrisExperimentLHS(const NumericalSample & lhsDesign, const UnsignedInteger N)
  : MorrisExperimentImplementation(NumericalPoint(lhsDesign.getDimension(), 1.0 / lhsDesign.getSize()), Interval(lhsDesign.getDimension()), N)
  , experiment_(lhsDesign)
{
  // Nothing to do
}

/** Constructor using NumericalSample, which is supposed to be an LHS design */
MorrisExperimentLHS::MorrisExperimentLHS(const NumericalSample & lhsDesign, const Interval & interval, const UnsignedInteger N)
  : MorrisExperimentImplementation(NumericalPoint(lhsDesign.getDimension(), 1.0 / lhsDesign.getSize()), interval, N)
  , experiment_()

{
  if (lhsDesign.getDimension() != interval.getDimension())
    throw InvalidArgumentException(HERE) << "Levels and design should have same dimension. Here, design's dimension=" << lhsDesign.getDimension()
                                         <<", interval's size=" << interval.getDimension();
  // lhs should be defined in [0,1]^d
  const NumericalPoint lowerBound(interval_.getLowerBound());
  const NumericalPoint upperBound(interval_.getUpperBound());
  const NumericalPoint delta(upperBound - lowerBound);
  // Standard experiment
  experiment_ = lhsDesign - lowerBound;
  experiment_ /= delta;
}

/* Virtual constructor method */
MorrisExperimentLHS * MorrisExperimentLHS::clone() const
{
  return new MorrisExperimentLHS(*this);
}

/** Generate method */
NumericalSample MorrisExperimentLHS::generate() const
{
  const UnsignedInteger dimension(delta_.getDimension());
  // Distribution that defines the permutations
  const KPermutationsDistribution permutationDistribution(dimension, dimension);
  // Distribution that defines the direction
  NumericalSample admissibleDirections(2, 1);
  admissibleDirections[0][0] = 1.0;
  admissibleDirections[1][0] = -1.0;
  const UserDefined directionDistribution(admissibleDirections);
  // Interval parameters
  const NumericalPoint lowerBound(interval_.getLowerBound());
  const NumericalPoint upperBound(interval_.getUpperBound());
  const NumericalPoint deltaBounds(upperBound - lowerBound);
  // Support sample for realizations
  NumericalSample realizations(N_ * (dimension + 1), dimension);
  NumericalPoint delta(delta_);
  for (UnsignedInteger k = 0; k < N_; ++k)
  {
    /* Generation of the k-th trajectory :
      1) Generation of an "xbase" point
      2) Generation of an orientation matrix B of size (dimension + 1) x dimension
      3) Generation of a permutation matrix P of size dimension x dimension
      4) Generation of a direction matrix D of size dimension x dimension
      5) Evaluate Z = (B * P * D + 1) * 0.5
      6) Compute Z * diag(step) + xbase
    */
    // First generate point
    // Perform point from LHS
    const UnsignedInteger size(experiment_.getSize());
    const UnsignedInteger index(RandomGenerator::IntegerGenerate(size));
    Log::Info(OSS() << "Sorted point from design = " << experiment_[index]);
    NumericalPoint xBase(experiment_[index]);
    // Here we combine steps 2 to 6 as B * P permutes the columns of B
    // Define the permutations
    const NumericalPoint permutations(permutationDistribution.getRealization());
    // Define the direction
    NumericalPoint directions(directionDistribution.getSample(dimension).getImplementation()->getData());

    for (UnsignedInteger i = 0; i < dimension + 1; ++i)
    {
      // Steps  2 and 3  B * P ==> permutation of the orientation matrix

      // Steps 5 and 6
      for (UnsignedInteger p = 0; p < dimension; ++p)
      {
        const NumericalPoint orientationMatrixColumn(getOrientationMatrixColumn(p));
        NumericalScalar value((orientationMatrixColumn[i] * directions[p] + 1.0) * 0.5 * delta[p]);
        // Check that direction is admissible
        if ( (value + xBase[p] > 1.0) || (value + xBase[p] < 0.0))
        {
          value *= -1.0;
        }
        realizations[k * (dimension + 1) + i][p] = deltaBounds[p] * (value + xBase[p] ) + lowerBound[p];
      }
    }
  }
  // Filter replicate trajectories
  NumericalSample uniqueTrajectories(N_, dimension * (dimension + 1));
  uniqueTrajectories.getImplementation()->setData(  realizations.getImplementation()->getData());
  // Sort and keep unique data
  uniqueTrajectories = uniqueTrajectories.sortUnique();
  realizations = NumericalSample(uniqueTrajectories.getSize() * (dimension + 1), dimension);
  realizations.getImplementation()->setData(uniqueTrajectories.getImplementation()->getData());
  // LogWarn if N_ differ
  // Care N_ should not be updated
  // Other possibility is to add number of missing trajectories (N_ - uniqueTrajectories.getSize())
  if (uniqueTrajectories.getSize() != N_)
    LOGWARN(OSS() << (N_ - uniqueTrajectories.getSize()) << " duplicate trajectories removed");
  // return sample
  return realizations;
}


/* String converter */
String MorrisExperimentLHS::__repr__() const
{
  OSS oss;
  oss << "class=" << MorrisExperimentLHS::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void MorrisExperimentLHS::save(Advocate & adv) const
{
  MorrisExperimentImplementation::save( adv );
  adv.saveAttribute( "experiment_", experiment_ );
}

/* Method load() reloads the object from the StorageManager */
void MorrisExperimentLHS::load(Advocate & adv)
{
  MorrisExperimentImplementation::load( adv );
  adv.loadAttribute( "experiment_", experiment_ );
}


} /* namespace OTMORRIS */
