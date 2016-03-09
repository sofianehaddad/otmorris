//                                               -*- C++ -*-
/**
 *  @brief MyClassImplementation
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
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
 */
#ifndef OTMORRIS_MORRISIMPLEMENTATION_HXX
#define OTMORRIS_MORRISIMPLEMENTATION_HXX

#include <PersistentObject.hxx>
#include <StorageManager.hxx>
#include <NumericalPoint.hxx>
#include "otmorris/OTMORRISprivate.hxx"

namespace OTMORRIS
{

/**
 * @class MorrisImplementation
 *
 * MorrisImplementation is some morris type to illustrate how to add some classes in OpenTURNS
 */
class OTMORRIS_API MorrisImplementation
  : public OT::PersistentObject
{
  CLASSNAME;

public:
  /** Default constructor */
  MorrisImplementation();

  /** Virtual constructor method */
  MorrisImplementation * clone() const;

  /** example of a func that return a point squared. **/
  OT::NumericalPoint square(OT::NumericalPoint& p) const;

  /** String converter */
  OT::String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(OT::Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(OT::Advocate & adv);

private:

}; /* class MorrisImplementation */

} /* namespace OTMORRIS */

#endif /* OTMORRIS_MORRISIMPLEMENTATION_HXX */
