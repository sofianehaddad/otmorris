//                                               -*- C++ -*-
/**
 *  @file  MorrisExperimentImplementation.hxx
 *  @brief Generation of experiments for the Morris method
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
#ifndef OTMORRIS_MORRISEXPERIMENTIMPLEMENTATION_HXX
#define OTMORRIS_MORRISEXPERIMENTIMPLEMENTATION_HXX

#include <openturns/TypedInterfaceObject.hxx>
#include <openturns/StorageManager.hxx>
#include <openturns/NumericalPoint.hxx>
#include <openturns/Interval.hxx>
#include <openturns/Indices.hxx>
#include <openturns/Matrix.hxx>
#include <openturns/WeightedExperiment.hxx>
#include "otmorris/OTMORRISprivate.hxx"

namespace OTMORRIS
{
/**
 * @class MorrisExperimentImplementation
 *
 * MorrisExperiment enables to build experiments for the Morris method
 */
class OTMORRIS_API MorrisExperimentImplementation
  : public OT::WeightedExperimentImplementation
{
  CLASSNAME;

public:

  /** Default constructor */
  MorrisExperimentImplementation();

  /** Standard constructors */
  MorrisExperimentImplementation(const OT::NumericalPoint & delta, const OT::Interval & interval, const OT::UnsignedInteger N);

  MorrisExperimentImplementation(const OT::NumericalPoint & delta, const OT::UnsignedInteger N);

  /** Virtual constructor method */
  MorrisExperimentImplementation * clone() const;

  /** Generate method */
  virtual OT::NumericalSample generate() const;

  /** String converter */
  OT::String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

protected:

  // Build the p-th column of an orientation matrix
  OT::NumericalPoint getOrientationMatrixColumn(const OT::UnsignedInteger p) const;

  // Bounds
  OT::Interval interval_;

  // Delta step
  OT::NumericalPoint delta_;

  // Number of trajectories
  OT::UnsignedInteger N_;

}; /* class MorrisExperiment */

} /* namespace OTMORRIS */

#endif /* OTMORRIS_MORRISEXPERIMENTIMPLEMENTATION_HXX */
