
#ifndef OTTEMPLATE_PRIVATE_HXX
#define OTTEMPLATE_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTTEMPLATE_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTTEMPLATE_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTTEMPLATE_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTTEMPLATE_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTTEMPLATE_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTTEMPLATE_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTTEMPLATE_HELPER_DLL_IMPORT
#define OTTEMPLATE_HELPER_DLL_EXPORT
#define OTTEMPLATE_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTTEMPLATE_API and OTTEMPLATE_LOCAL.
 * OTTEMPLATE_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTTEMPLATE_LOCAL is used for non-api symbols. */

#ifndef OTTEMPLATE_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTTEMPLATE_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTTEMPLATE_API OTTEMPLATE_HELPER_DLL_EXPORT
#else
#define OTTEMPLATE_API OTTEMPLATE_HELPER_DLL_IMPORT
#endif /* OTTEMPLATE_DLL_EXPORTS */
#define OTTEMPLATE_LOCAL OTTEMPLATE_HELPER_DLL_LOCAL
#else /* OTTEMPLATE_STATIC is defined: this means OT is a static lib. */
#define OTTEMPLATE_API
#define OTTEMPLATE_LOCAL
#endif /* !OTTEMPLATE_STATIC */


#endif // OTTEMPLATE_PRIVATE_HXX

