// SWIG file

%module(docstring="ottemplate module") ottemplate
%feature("autodoc","1");

%{
#include "OT.hxx"
#include "PythonWrappingFunctions.hxx"
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include OTTemplateprivate.hxx
%include MyClassImplementation.i
%include MyClass.i


