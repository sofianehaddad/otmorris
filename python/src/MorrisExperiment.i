// SWIG file

%{
#include "otmorris/MorrisExperiment.hxx"
%}

%include MorrisExperiment_doc.i

%template(MorrisExperimentImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTMORRIS::MorrisExperiment>;

%include otmorris/MorrisExperiment.hxx
namespace OTMORRIS { %extend MorrisExperiment { MorrisExperiment(const MorrisExperiment & other) { return new OTMORRIS::MorrisExperiment(other); } } }
