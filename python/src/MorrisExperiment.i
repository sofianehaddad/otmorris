// SWIG file MorrisExperiment.i

%{
#include "otmorris/MorrisExperiment.hxx"
%}

%include MorrisExperiment_doc.i

%template(MorrisExperimentImplementationTypedInterfaceObject) OT::TypedInterfaceObject<OTMORRIS::MorrisExperimentImplementation>;

%typemap(in) const OTMORRIS::MorrisExperiment & {
  void * ptr = 0;
  if (SWIG_IsOK(SWIG_ConvertPtr($input, (void **) &$1, $1_descriptor, 0))) {
    // From interface class, ok
  } else if (SWIG_IsOK(SWIG_ConvertPtr($input, &ptr, SWIGTYPE_p_OTMORRIS__MorrisExperimentImplementation, 0))) {
    // From Implementation*
    OTMORRIS::MorrisExperimentImplementation * p_impl = reinterpret_cast< OTMORRIS::MorrisExperimentImplementation * >( ptr );
    $1 = new OTMORRIS::MorrisExperiment( *p_impl );
  } else if (SWIG_IsOK(SWIG_ConvertPtr($input, &ptr, SWIG_TypeQuery("OT::Pointer<OTMORRIS::MorrisExperimentImplementation> *"), 0))) {
    // From Pointer<Implementation>
    OT::Pointer<OTMORRIS::MorrisExperimentImplementation> * p_impl = reinterpret_cast< OT::Pointer<OTMORRIS::MorrisExperimentImplementation> * >( ptr );
    $1 = new OTMORRIS::MorrisExperiment( **p_impl );
  } else {
    SWIG_exception(SWIG_TypeError, "Object passed as argument is not convertible to a MorrisExperiment");
  }
}

%typemap(typecheck,precedence=SWIG_TYPECHECK_POINTER) const OTMORRIS::MorrisExperiment & {
  $1 = SWIG_IsOK(SWIG_ConvertPtr($input, NULL, $1_descriptor, 0))
    || SWIG_IsOK(SWIG_ConvertPtr($input, NULL, SWIGTYPE_p_OTMORRIS__MorrisExperimentImplementation, 0))
    || SWIG_IsOK(SWIG_ConvertPtr($input, NULL, SWIG_TypeQuery("OT::Pointer<OTMORRIS::MorrisExperimentImplementation> *"), 0));
}

%include otmorris/MorrisExperiment.hxx
namespace OTMORRIS { %extend MorrisExperiment { MorrisExperiment(const MorrisExperiment & other) { return new OTMORRIS::MorrisExperiment(other); } } }

