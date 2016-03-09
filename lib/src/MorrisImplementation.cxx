//                                               -*- C++ -*-
/**
 *  @brief MorrisImplementation
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
#include "otmorris/MorrisImplementation.hxx"
#include <PersistentObjectFactory.hxx>

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(MorrisImplementation);

static Factory<MorrisImplementation> RegisteredFactory;


/* Default constructor */
MorrisImplementation::MorrisImplementation()
  : PersistentObject()
{
  // Nothing to do
}

/* Virtual constructor method */
MorrisImplementation * MorrisImplementation::clone() const
{
  return new MorrisImplementation(*this);
}

/* example of a func that return a point squared. */
NumericalPoint MorrisImplementation::square(NumericalPoint& p) const
{

  NumericalPoint p_out(p.getSize());
  for(UnsignedInteger i = 0; i < p.getSize(); ++ i)
  {
    p_out[i] = p[i] * p[i];
  }
  return p_out;
}

/* String converter */
String MorrisImplementation::__repr__() const
{
  OSS oss;
  oss << "class=" << MorrisImplementation::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void MorrisImplementation::save(Advocate & adv) const
{
  PersistentObject::save( adv );
}

/* Method load() reloads the object from the StorageManager */
void MorrisImplementation::load(Advocate & adv)
{
  PersistentObject::load( adv );
}


} /* namespace OTMORRIS */
