// SWIG file otmorris_module.i

%module(docstring="otmorris module") otmorris

%{
#include <openturns/OT.hxx>
#include <openturns/PythonWrappingFunctions.hxx>
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include otmorris/OTMORRISprivate.hxx
%include MorrisExperiment.i
%include MorrisExperimentGrid.i
%include MorrisExperimentLHS.i
%include Morris.i

