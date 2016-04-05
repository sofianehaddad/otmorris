// SWIG file MyClassImplementation.i

%{
#include "ottemplate/MyClassImplementation.hxx"
%}

%include MyClassImplementation_doc.i

%template(MyClassImplementationdInterfaceObject)           OT::TypedInterfaceObject<OTTEMPLATE::MyClassImplementation>;

%include ottemplate/MyClassImplementation.hxx
namespace OTTEMPLATE { %extend MyClassImplementation { MyClassImplementation(const MyClassImplementation & other) { return new OTTEMPLATE::MyClassImplementation(other); } } }
