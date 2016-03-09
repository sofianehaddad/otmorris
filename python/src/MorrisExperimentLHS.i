// SWIG file

%{
#include "otmorris/MorrisExperimentLHS.hxx"
%}

%include MorrisExperimentLHS_doc.i

%template(MorrisExperimentLHSdInterfaceObject)           OT::TypedInterfaceObject<OTMORRIS::MorrisExperimentLHS>;

%include otmorris/MorrisExperimentLHS.hxx
namespace OTMORRIS { %extend MorrisExperimentLHS { MorrisExperimentLHS(const MorrisExperimentLHS & other) { return new OTMORRIS::MorrisExperimentLHS(other); } } }
