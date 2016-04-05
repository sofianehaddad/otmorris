// SWIG file MyClass.i

%{
#include "ottemplate/MyClass.hxx"
%}

%include MyClass_doc.i

%template(MyClassImplementationTypedInterfaceObject) OT::TypedInterfaceObject<OTTEMPLATE::MyClassImplementation>;

%typemap(in) const OTTEMPLATE::MyClass & {
  void * ptr = 0;
  if (SWIG_IsOK(SWIG_ConvertPtr($input, (void **) &$1, $1_descriptor, 0))) {
    // From interface class, ok
  } else if (SWIG_IsOK(SWIG_ConvertPtr($input, &ptr, SWIGTYPE_p_OTTEMPLATE__MyClassImplementation, 0))) {
    // From Implementation*
    OTTEMPLATE::MyClassImplementation * p_impl = reinterpret_cast< OTTEMPLATE::MyClassImplementation * >( ptr );
    $1 = new OTTEMPLATE::MyClass( *p_impl );
  } else if (SWIG_IsOK(SWIG_ConvertPtr($input, &ptr, SWIG_TypeQuery("OT::Pointer<OTTEMPLATE::MyClassImplementation> *"), 0))) {
    // From Pointer<Implementation>
    OT::Pointer<OTTEMPLATE::MyClassImplementation> * p_impl = reinterpret_cast< OT::Pointer<OTTEMPLATE::MyClassImplementation> * >( ptr );
    $1 = new OTTEMPLATE::MyClass( **p_impl );
  } else {
    SWIG_exception(SWIG_TypeError, "Object passed as argument is not convertible to a MyClass");
  }
}

%typemap(typecheck,precedence=SWIG_TYPECHECK_POINTER) const OTTEMPLATE::MyClass & {
  $1 = SWIG_IsOK(SWIG_ConvertPtr($input, NULL, $1_descriptor, 0))
    || SWIG_IsOK(SWIG_ConvertPtr($input, NULL, SWIGTYPE_p_OTTEMPLATE__MyClassImplementation, 0))
    || SWIG_IsOK(SWIG_ConvertPtr($input, NULL, SWIG_TypeQuery("OT::Pointer<OTTEMPLATE::MyClassImplementation> *"), 0));
}

%include ottemplate/MyClass.hxx
namespace OTTEMPLATE { %extend MyClass { MyClass(const MyClass & other) { return new OTTEMPLATE::MyClass(other); } } }
