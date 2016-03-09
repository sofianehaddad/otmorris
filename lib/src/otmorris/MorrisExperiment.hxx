//                                               -*- C++ -*-
/**
 *  @file  MorrisExperiment.hxx
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
#ifndef OTMORRIS_MORRISEXPERIMENT_HXX
#define OTMORRIS_MORRISEXPERIMENT_HXX

#include <openturns/TypedInterfaceObject.hxx>
#include <openturns/StorageManager.hxx>
#include <openturns/NumericalPoint.hxx>
#include <openturns/Interval.hxx>
#include <openturns/Indices.hxx>
#include <openturns/NumericalSample.hxx>
#include "otmorris/OTMORRISprivate.hxx"
#include <openturns/WeightedExperiment.hxx>

namespace OTMORRIS
{

/* forward declaration */
class MorrisExperiment;

/**
 * @class MorrisExperiment
 *
 * MorrisExperiment enables to build experiments for the Morris method
 */
class OTMORRIS_API MorrisExperiment
  : public OT::WeightedExperiment
{
  CLASSNAME;

public:

  /** Default constructor */
  MorrisExperiment();

  /** Constructor using a p-level grid - Uniform(0,1)^d */
  MorrisExperiment(OT::Indices & levels, OT::UnsignedInteger N);

  /** Constructor using a p-level grid and intervals*/
  MorrisExperiment(OT::Indices & levels, OT::UnsignedInteger N, OT::Interval & interval);

  /** Constructor using NumericalSample, which is supposed to be an LHS design -  - Uniform(0,1)^d*/
  MorrisExperiment(OT::NumericalSample & lhsDesign, OT::UnsignedInteger N);

  /** Constructor using NumericalSample, which is supposed to be an LHS design */
  MorrisExperiment(OT::NumericalSample & lhsDesign, OT::UnsignedInteger N, OT::Interval & interval);

  /** Virtual constructor method */
  MorrisExperiment * clone() const;

  /** Generate method */
  OT::NumericalSample generate() const;

  /** String converter */
  OT::String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

private:

  // Bounds
  OT::Interval interval_;

  // Number of trajectories
  OT::UnsignedInteger N_;

}; /* class MorrisExperiment */

} /* namespace OTMORRIS */

#endif /* OTMORRIS_MORRISEXPERIMENT_HXX */
