// SWIG file

%{
#include "MyClassImplementation.hxx"
%}

%include MyClassImplementation_doc.i

%template(MyClassImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTTEMPLATE::MyClassImplementation>;

%include MyClassImplementation.hxx
namespace OTTEMPLATE { %extend MyClassImplementation { MyClassImplementation(const MyClassImplementation & other) { return new OTTEMPLATE::MyClassImplementation(other); } } }
