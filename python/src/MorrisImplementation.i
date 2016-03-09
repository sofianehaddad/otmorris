// SWIG file

%{
#include "otmorris/MorrisImplementation.hxx"
%}

%include MorrisImplementation_doc.i

%template(MorrisImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTMORRIS::MorrisImplementation>;

%include otmorris/MorrisImplementation.hxx
namespace OTMORRIS { %extend MorrisImplementation { MorrisImplementation(const MorrisImplementation & other) { return new OTMORRIS::MorrisImplementation(other); } } }
