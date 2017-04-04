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
#include "otmorris/MorrisExperimentGrid.hxx"
#include "otmorris/MorrisExperimentLHS.hxx"

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(MorrisExperiment);


/** Default constructor */
MorrisExperiment::MorrisExperiment()
  : TypedInterfaceObject<MorrisExperimentImplementation>(new MorrisExperimentImplementation())
{
  // Nothing to do
}

/** Default constructor */
MorrisExperiment::MorrisExperiment(const MorrisExperimentImplementation & implementation)
  : TypedInterfaceObject<MorrisExperimentImplementation>(implementation.clone())
{
  // Nothing to do
}

/** Constructor from implementation */
MorrisExperiment::MorrisExperiment(const Implementation & p_implementation)
  : TypedInterfaceObject<MorrisExperimentImplementation>(p_implementation)
{
  // Nothing to do
}

/** Constructor from implementation pointer */
MorrisExperiment::MorrisExperiment(MorrisExperimentImplementation * p_implementation)
  : TypedInterfaceObject<MorrisExperimentImplementation>(p_implementation)
{
  // Initialize any other class members here
  // At last, allocate memory space if needed, but go to destructor to free it
}


/** Constructor using a p-level grid  - Uniform(0,1)^d */
MorrisExperiment::MorrisExperiment(const Indices & levels, const UnsignedInteger N)
  : TypedInterfaceObject<MorrisExperimentImplementation>(new MorrisExperimentGrid(levels, N))
{
  // Nothing to do
}

/** Constructor using a p-level grid and intervals*/
MorrisExperiment::MorrisExperiment(const Indices & levels, const Interval & interval, const UnsignedInteger N)
  : TypedInterfaceObject<MorrisExperimentImplementation>(new MorrisExperimentGrid(levels, interval, N))
{
  // Nothing to do
}

/** Constructor using Sample, which is supposed to be an LHS design - Uniform(0,1)^d*/
MorrisExperiment::MorrisExperiment(const Sample & lhsDesign, const UnsignedInteger N)
  : TypedInterfaceObject<MorrisExperimentImplementation>(new MorrisExperimentLHS(lhsDesign, N))
{
  // Nothing to do
}

/** Constructor using Sample, which is supposed to be an LHS design */
MorrisExperiment::MorrisExperiment(const Sample & lhsDesign, const Interval & interval, const UnsignedInteger N)
  : TypedInterfaceObject<MorrisExperimentImplementation>(new MorrisExperimentLHS(lhsDesign, interval, N))
{
  // Nothing to do
}

/* Virtual constructor method */
MorrisExperiment * MorrisExperiment::clone() const
{
  return new MorrisExperiment(*this);
}

/** Generate method */
Sample MorrisExperiment::generate() const
{
  return getImplementation()->generate();
}


/* String converter */
String MorrisExperiment::__repr__() const
{
  return getImplementation()->__repr__();
}


} /* namespace OTMORRIS */
