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
{
  // Nothing to do
}

/** Constructor using a p-level grid  - Uniform(0,1)^d */
MorrisExperiment::MorrisExperiment(const Indices & levels, const UnsignedInteger N)
  : WeightedExperiment()
{
  // Nothing to do
}

/** Constructor using a p-level grid and intervals*/
MorrisExperiment::MorrisExperiment(const Indices & levels, const Interval & interval, const UnsignedInteger N)
  : WeightedExperiment()
{
  // Nothing to do
}

/** Constructor using NumericalSample, which is supposed to be an LHS design - Uniform(0,1)^d*/
MorrisExperiment::MorrisExperiment(const NumericalSample & lhsDesign, const UnsignedInteger N)
  : WeightedExperiment()
{
  // Nothing to do
}

/** Constructor using NumericalSample, which is supposed to be an LHS design */
MorrisExperiment::MorrisExperiment(const NumericalSample & lhsDesign, const Interval & interval, const UnsignedInteger N)
  : WeightedExperiment()
{
  // Nothing to do
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
  adv.saveAttribute( "N_", N_ );
}

/* Method load() reloads the object from the StorageManager */
void MorrisExperiment::load(Advocate & adv)
{
  WeightedExperiment::load( adv );
  adv.loadAttribute( "interval_", interval_ );
  adv.loadAttribute( "N_", N_ );
}


} /* namespace OTMORRIS */
