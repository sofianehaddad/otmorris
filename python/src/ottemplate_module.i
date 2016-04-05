// SWIG file ottemplate_module.i

%module(docstring="ottemplate module") ottemplate

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
%include ottemplate/OTTemplateprivate.hxx
%include MyClassImplementation.i
%include MyClass.i


