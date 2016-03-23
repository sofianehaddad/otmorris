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
#include "otmorris/MorrisExperiment.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(MorrisExperiment);

static Factory<MorrisExperiment> RegisteredFactory;


/* Default constructor */
MorrisExperiment::MorrisExperiment()
  : WeightedExperiment()
  , interval_()
  , experiment_()
  , step_()
  , orientationMatrix_()
  , permutationMatrix_()
  , directionMatrix_()
  , N_()
{
  // Nothing to do
}

/** Constructor using a p-level grid  - Uniform(0,1)^d */
MorrisExperiment::MorrisExperiment(const Indices & levels, const UnsignedInteger N)
  : WeightedExperiment()
  , interval_(levels.getSize())
  , experiment_()
  , step_ (levels.getSize())
  , orientationMatrix_(Matrix(levels.getSize() + 1, levels.getSize()))
  , permutationMatrix_(levels.getSize())
  , directionMatrix_(levels.getSize())
  , N_(N)
{
  // Compute step
  for (UnsignedInteger k = 0; k < levels.getSize(); ++k)
  {
    if (levels[k] <= 1)
      throw InvalidArgumentException(HERE) << "Levels should be at least 2; levels[" << k << "]=" << levels[k];
    step_[k] = 1.0 / (levels[k] - 1.0);
  }
}

/** Constructor using a p-level grid and intervals*/
MorrisExperiment::MorrisExperiment(const Indices & levels, const Interval & interval, const UnsignedInteger N)
  : WeightedExperiment()
  , interval_(interval)
  , experiment_()
  , step_ (levels.getSize())
  , orientationMatrix_(Matrix(levels.getSize() + 1, levels.getSize()))
  , permutationMatrix_(levels.getSize())
  , directionMatrix_(levels.getSize())
  , N_(N)
{
  if (levels.getSize() != interval.getDimension())
    throw InvalidArgumentException(HERE) << "Levels and interval should be of same size. Here, level's size=" << levels.getSize()
                                         <<", interval's size=" << interval.getDimension();
  // Compute step
  for (UnsignedInteger k = 0; k < levels.getSize(); ++k)
  {
    if (levels[k] <= 1)
      throw InvalidArgumentException(HERE) << "Levels should be at least 2; levels[" << k << "]=" << levels[k];
    step_[k] = 1.0 / (levels[k] - 1.0);
  }
}

/** Constructor using NumericalSample, which is supposed to be an LHS design - Uniform(0,1)^d*/
MorrisExperiment::MorrisExperiment(const NumericalSample & lhsDesign, const UnsignedInteger N)
  : WeightedExperiment()
  , interval_(lhsDesign.getDimension())
  , experiment_(lhsDesign)
  , step_(NumericalPoint(lhsDesign.getDimension(), 1.0 / lhsDesign.getSize()))
  , orientationMatrix_(lhsDesign.getDimension() + 1, lhsDesign.getDimension())
  , permutationMatrix_(lhsDesign.getDimension())
  , directionMatrix_(lhsDesign.getDimension())
  , N_(N)
{
  // Nothing to do
}

/** Constructor using NumericalSample, which is supposed to be an LHS design */
MorrisExperiment::MorrisExperiment(const NumericalSample & lhsDesign, const Interval & interval, const UnsignedInteger N)
  : WeightedExperiment()
  , interval_(interval)
  , experiment_(lhsDesign)
  , step_(NumericalPoint(lhsDesign.getDimension(), 1.0 / lhsDesign.getSize()))
  , orientationMatrix_(lhsDesign.getDimension() + 1, lhsDesign.getDimension())
  , permutationMatrix_(lhsDesign.getDimension())
  , directionMatrix_(lhsDesign.getDimension())
  , N_(N)

{
  if (lhsDesign.getDimension() != interval.getDimension())
    throw InvalidArgumentException(HERE) << "Levels and design should have same dimension. Here, design's dimension=" << lhsDesign.getDimension()
                                         <<", interval's size=" << interval.getDimension();
}

/* Virtual constructor method */
MorrisExperiment * MorrisExperiment::clone() const
{
  return new MorrisExperiment(*this);
}

/** Generate method */
NumericalSample MorrisExperiment::generate() const
{
  throw NotYetImplementedException(HERE);
}

/* String converter */
String MorrisExperiment::__repr__() const
{
  OSS oss;
  oss << "class=" << MorrisExperiment::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void MorrisExperiment::save(Advocate & adv) const
{
  WeightedExperiment::save( adv );
  adv.saveAttribute( "interval_", interval_ );
  adv.saveAttribute( "experiment_", experiment_ );
  adv.saveAttribute( "step_", step_ );
  adv.saveAttribute( "orientationMatrix_", orientationMatrix_ );
  adv.saveAttribute( "permutationMatrix_", permutationMatrix_ );
  adv.saveAttribute( "directionMatrix_", directionMatrix_);
  adv.saveAttribute( "N_", N_ );
}

/* Method load() reloads the object from the StorageManager */
void MorrisExperiment::load(Advocate & adv)
{
  WeightedExperiment::load( adv );
  adv.loadAttribute( "interval_", interval_ );
  adv.loadAttribute( "experiment_", experiment_ );
  adv.loadAttribute( "step_", step_ );
  adv.loadAttribute( "orientationMatrix_", orientationMatrix_ );
  adv.loadAttribute( "permutationMatrix_", permutationMatrix_ );
  adv.loadAttribute( "directionMatrix_", directionMatrix_ );
  adv.loadAttribute( "N_", N_ );
}


} /* namespace OTMORRIS */
