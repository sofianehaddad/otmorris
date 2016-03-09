
#ifndef OTMORRIS_PRIVATE_HXX
#define OTMORRIS_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTMORRIS_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTMORRIS_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTMORRIS_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTMORRIS_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTMORRIS_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTMORRIS_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTMORRIS_HELPER_DLL_IMPORT
#define OTMORRIS_HELPER_DLL_EXPORT
#define OTMORRIS_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTMORRIS_API and OTMORRIS_LOCAL.
 * OTMORRIS_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTMORRIS_LOCAL is used for non-api symbols. */

#ifndef OTMORRIS_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTMORRIS_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTMORRIS_API OTMORRIS_HELPER_DLL_EXPORT
#else
#define OTMORRIS_API OTMORRIS_HELPER_DLL_IMPORT
#endif /* OTMORRIS_DLL_EXPORTS */
#define OTMORRIS_LOCAL OTMORRIS_HELPER_DLL_LOCAL
#else /* OTMORRIS_STATIC is defined: this means OT is a static lib. */
#define OTMORRIS_API
#define OTMORRIS_LOCAL
#endif /* !OTMORRIS_STATIC */


#endif // OTMORRIS_PRIVATE_HXX

