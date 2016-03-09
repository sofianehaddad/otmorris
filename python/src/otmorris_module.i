// SWIG file otmorris_module.i

%module(docstring="otmorris module") otmorris

%{
#include <OT.hxx>
#include <PythonWrappingFunctions.hxx>
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
%include MorrisImplementation.i
%include Morris.i


