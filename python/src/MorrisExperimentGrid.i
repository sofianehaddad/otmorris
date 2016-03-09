// SWIG file

%{
#include "otmorris/MorrisExperimentGrid.hxx"
%}

%include MorrisExperimentGrid_doc.i

%include otmorris/MorrisExperimentGrid.hxx
namespace OTMORRIS { %extend MorrisExperimentGrid { MorrisExperimentGrid(const MorrisExperimentGrid & other) { return new OTMORRIS::MorrisExperimentGrid(other); } } }
