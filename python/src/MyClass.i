// SWIG file

%{
#include "MyClass.hxx"
%}

%include MyClass_doc.i

%include MyClass.hxx
namespace OTTEMPLATE { %extend MyClass { MyClass(const MyClass & other) { return new OTTEMPLATE::MyClass(other); } } }
