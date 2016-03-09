//                                               -*- C++ -*-
/**
 *  @brief Morris
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
#ifndef OTMORRIS_MORRIS_HXX
#define OTMORRIS_MORRIS_HXX

#include <TypedInterfaceObject.hxx>
#include <StorageManager.hxx>
#include <NumericalPoint.hxx>
#include "otmorris/OTMORRISprivate.hxx"

namespace OTMORRIS
{

/* forward declaration */
class MorrisImplementation;

/**
 * @class Morris
 *
 * Morris is some morris type to illustrate how to add some classes in Open TURNS
 */
class OTMORRIS_API Morris
  : public OT::TypedInterfaceObject<MorrisImplementation>
{
  CLASSNAME;

public:

  /** Default constructor */
  Morris();

  /** Constructor from implementation */
  Morris(const MorrisImplementation & implementation);

  /** a func that return a point squared. **/
  OT::NumericalPoint square(OT::NumericalPoint& p) const;

  /** String converter */
  OT::String __repr__() const;

private:

}; /* class Morris */

} /* namespace OTMORRIS */

#endif /* OTMORRIS_MORRIS_HXX */
