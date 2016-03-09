// SWIG file

%{
#include "otmorris/MorrisExperiment.hxx"
%}

%include MorrisExperiment_doc.i

%include otmorris/MorrisExperiment.hxx
namespace OTMORRIS { %extend MorrisExperiment { MorrisExperiment(const MorrisExperiment & other) { return new OTMORRIS::MorrisExperiment(other); } } }
