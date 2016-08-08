// SWIG file MorrisExperiment.i

%{
#include "otmorris/MorrisExperiment.hxx"
%}

%include MorrisExperiment_doc.i

TypedInterfaceObjectImplementationHelper(OTMORRIS, MorrisExperiment, MorrisExperimentImplementation)

%include otmorris/MorrisExperiment.hxx
namespace OTMORRIS { %extend MorrisExperiment { MorrisExperiment(const MorrisExperiment & other) { return new OTMORRIS::MorrisExperiment(other); } } }

