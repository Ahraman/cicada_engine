#ifndef CICADA_CICADA_MACROS_HEADER_GUARDS
# define CICADA_CICADA_MACROS_HEADER_GUARDS (1)

# ifndef CICADA_PRAGMA_ONCE
#  if defined(_MSC_VER) && (_MSC_VER >= 1020)
#   define CICADA_PRAGMA_ONCE (1)
#  else
#   define CICADA_PRAGMA_ONCE (0)
#  endif
# endif

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifndef CICADA_COMPILER_DETECTED
#  ifdef _MSC_VER
#   define CICADA_COMPILER_MSVC
#   define CICADA_COMPILER_DETECTED (1)
#  else
#   define CICADA_COMPILER_DETECTED (0)
#  endif
# endif

# ifndef CICADA_CPP_STANDARD_DETECTED
#  ifdef CICADA_COMPILER_MSVC
#   ifdef _MSVC_LANG
#    if (_MSVC_LANG >= 201703L)
#     define CICADA_CPP_STANDARD_17
#    elif (_MSVC_LANG >= 201402L)
#     define CICADA_CPP_STANDARD_14
#    elif (_MSVC_LANG >= 201103L)
#     define CICADA_CPP_STANDARD_11
#    else
#     define CICADA_CPP_STANDARD_03
#    endif
#   endif
#  else
#   if (__cplusplus >= 201703L)
#    define CICADA_CPP_STANDARD_17
#   elif (__cplusplus >= 201402L)
#    define CICADA_CPP_STANDARD_14
#   elif (__cplusplus >= 201103L)
#    define CICADA_CPP_STANDARD_11
#   else
#    define CICADA_CPP_STANDARD_03
#   endif
#  endif

#    if defined(CICADA_CPP_STANDARD_17) || defined(CICADA_CPP_STANDARD_14) || defined(CICADA_CPP_STANDARD_11) || defined(CICADA_CPP_STANDARD_03)
#	  define CICADA_CPP_STANDARD_DETECTED (1)
#    else
#     define CICADA_CPP_STANDARD_DETECTED (0)
#    endif
# endif

# ifndef CICADA_CPP_OS_DETECTED
#  ifdef _WIN32
#   define CICADA_OS_WINDOWS
#  endif

#  if defined(CICADA_OS_WINDOWS)
#   define CICADA_CPP_OS_DETECTED (1)
#  else
#   define CICADA_CPP_OS_DETECTED (0)
#  endif
# endif

# ifndef CICADA_CPP_ARCHITECTURE_DETECTED
#  ifdef CICADA_COMPILER_MSVC
#   ifdef _WIN64
#    define CICADA_ARCHITECTURE_X64
#   endif
#  endif

#  if defined(CICADA_ARCHITECTURE_X64)
#   define CICADA_CPP_ARCHITECTURE_DETECTED (1)
#  else
#   define CICADA_CPP_ARCHITECTURE_DETECTED (0)
#  endif
# endif

# ifndef CICADA_DEBUG_LEVEL
#  ifdef CICADA_COMPILER_MSVC
#   ifdef _DEBUG
#    define CICADA_DEBUG_LEVEL (1)
#   else
#    define CICADA_DEBUG_LEVEL (0)
#   endif
#  endif
# endif

# ifndef CICADA_API
#  ifdef CICADA_COMPILER_MSVC
#   ifdef CICADA_EXPORT
#     define CICADA_API __declspec(dllexport)
#   else
#     define CICADA_API __declspec(dllimport)
#   endif
#  endif
# endif

# ifndef CICADA_NODISCARD
#  if !defined(CICADA_SUPPRESS_NODISCARD) && defined(CICADA_CPP_STANDARD_17)
#   define CICADA_NODISCARD [[nodiscard]]
#  else
#   define CICADA_NODISCARD
#  endif
# endif

#endif