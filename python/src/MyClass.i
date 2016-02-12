// SWIG file

%{
#include "ottemplate/MyClass.hxx"
%}

%include MyClass_doc.i

%include ottemplate/MyClass.hxx
namespace OTTEMPLATE { %extend MyClass { MyClass(const MyClass & other) { return new OTTEMPLATE::MyClass(other); } } }
