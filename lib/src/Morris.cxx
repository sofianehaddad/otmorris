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
#include "otmorris/Morris.hxx"
#include <openturns/PersistentObjectFactory.hxx>

using namespace OT;

namespace OTMORRIS
{

CLASSNAMEINIT(Morris);

static Factory<Morris> RegisteredFactory;


/* Default constructor */
Morris::Morris()
  : PersistentObject()
{
  // Nothing to do
}

/** Standard constructor */
Morris::Morris(NumericalSample & inputSample, NumericalSample & outputSample)
  : PersistentObject()
{
  // Nothing to do
}

/* Virtual constructor method */
Morris * Morris::clone() const
{
  return new Morris(*this);
}

/* Mean effects */
NumericalPoint Morris::getMeanEffects() const
{
  throw NotYetImplementedException(HERE);
}

/* Standard deviation effects */
NumericalPoint Morris::getStandardDeviationEffects() const
{
  throw NotYetImplementedException(HERE);
}

/* String converter */
String Morris::__repr__() const
{
  OSS oss;
  oss << "class=" << Morris::GetClassName();
  return oss;
}

/* Method save() stores the object through the StorageManager */
void Morris::save(Advocate & adv) const
{
  PersistentObject::save( adv );
  adv.saveAttribute( "inputSample_", inputSample_ );
  adv.saveAttribute( "outputSample_", outputSample_ );
  adv.saveAttribute( "elementaryEffects_", elementaryEffects_ );
  adv.saveAttribute( "N_", N_ );
}

/* Method load() reloads the object from the StorageManager */
void Morris::load(Advocate & adv)
{
  PersistentObject::load( adv );
  adv.loadAttribute( "inputSample_", inputSample_ );
  adv.loadAttribute( "outputSample_", outputSample_ );
  adv.loadAttribute( "elementaryEffects_", elementaryEffects_ );
  adv.loadAttribute( "N_", N_ );
}


} /* namespace OTMORRIS */
