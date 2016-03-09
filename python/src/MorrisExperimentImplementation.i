// SWIG file

%{
#include "otmorris/MorrisExperimentImplementation.hxx"
%}

%include MorrisExperimentImplementation_doc.i

%template(MorrisExperimentImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTMORRIS::MorrisExperimentImplementation>;

%include otmorris/MorrisExperimentImplementation.hxx
namespace OTMORRIS { %extend MorrisExperimentImplementation { MorrisExperimentImplementation(const MorrisExperimentImplementation & other) { return new OTMORRIS::MorrisExperimentImplementation(other); } } }
