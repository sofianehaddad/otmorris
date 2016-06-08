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
#include <openturns/PersistentObjectFactory.hxx>
#include "otmorris/MorrisExperimentImplementation.hxx"
#include <openturns/KPermutationsDistribution.hxx>
#include <openturns/Exception.hxx>
#include <openturns/Log.hxx>

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(MorrisExperimentImplementation);

static Factory<MorrisExperimentImplementation> RegisteredFactory;

/** Default constructor */
MorrisExperimentImplementation::MorrisExperimentImplementation()
  : WeightedExperimentImplementation()
  , interval_()
  , delta_ ()
  , N_(0)
{
  // Nothing to do
}

/** Constructor using a p-level grid  - Uniform(0,1)^d */
MorrisExperimentImplementation::MorrisExperimentImplementation(const NumericalPoint & delta, const UnsignedInteger N)
  : WeightedExperimentImplementation()
  , interval_(delta.getSize())
  , delta_ (delta)
  , N_(N)
{
  // Nothing to do
}

/** Constructor using a p-level grid and intervals*/
MorrisExperimentImplementation::MorrisExperimentImplementation(const NumericalPoint & delta, const Interval & interval, const UnsignedInteger N)
  : WeightedExperimentImplementation()
  , interval_(interval)
  , delta_ (delta)
  , N_(N)
{
  if (delta.getSize() != interval.getDimension())
    throw InvalidArgumentException(HERE) << "Levels and interval should be of same size. Here, level's size=" << delta.getSize()
                                         <<", interval's size=" << interval.getDimension();
}

/* Virtual constructor method */
MorrisExperimentImplementation * MorrisExperimentImplementation::clone() const
{
  return new MorrisExperimentImplementation(*this);
}


// Build the p-th column of the orientation matrix
NumericalPoint MorrisExperimentImplementation::getOrientationMatrixColumn(const UnsignedInteger p) const
{
  const UnsignedInteger dimension(delta_.getDimension());
  if (p >= dimension)
    throw InvalidArgumentException(HERE) << "Could not build the column";
  NumericalPoint orientation(dimension + 1, 1.0);
  for (UnsignedInteger i = 0; i <= p; ++i) orientation[i] = -1.0;
  return orientation;
}

/** Generate method */
NumericalSample MorrisExperimentImplementation::generate() const
{
  throw NotYetImplementedException(HERE);
}

/* String converter */
String MorrisExperimentImplementation::__repr__() const
{
  OSS oss;
  oss << "class=" << MorrisExperimentImplementation::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void MorrisExperimentImplementation::save(Advocate & adv) const
{
  WeightedExperimentImplementation::save( adv );
  adv.saveAttribute( "interval_", interval_ );
  adv.saveAttribute( "delta_", delta_ );
  adv.saveAttribute( "N_", N_ );
}

/* Method load() reloads the object from the StorageManager */
void MorrisExperimentImplementation::load(Advocate & adv)
{
  WeightedExperimentImplementation::load( adv );
  adv.loadAttribute( "interval_", interval_ );
  adv.loadAttribute( "delta_", delta_ );
  adv.loadAttribute( "N_", N_ );
}


} /* namespace OTMORRIS */
