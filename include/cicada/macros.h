#ifndef CICADA_MACROS_HEADER_GUARDS
# define CICADA_MACROS_HEADER_GUARDS (1)

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

// Compiler

# ifndef CICADA_COMPILER_DETECTED
#  ifdef _MSC_VER
#   define CICADA_COMPILER_MSVC
#   define CICADA_COMPILER_DETECTED (1)
#  else
#   define CICADA_COMPILER_DETECTED (0)
#  endif
# endif

// C++ standard

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

// Operating system

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

// Architecture

# ifndef CICADA_CPP_ARCHITECTURE_DETECTED
#  ifdef CICADA_COMPILER_MSVC
#   ifdef _WIN64
#    define CICADA_ARCHITECTURE_X64
#   else
#    define CICADA_ARCHITECTURE_X32
#   endif
#  endif

#  if defined(CICADA_ARCHITECTURE_X64) || defined(CICADA_ARCHITECTURE_X32)
#   define CICADA_CPP_ARCHITECTURE_DETECTED (1)
#  else
#   define CICADA_CPP_ARCHITECTURE_DETECTED (0)
#  endif
# endif

// Debug level

# ifndef CICADA_DEBUG_LEVEL
#  ifdef CICADA_COMPILER_MSVC
#   ifdef _DEBUG
#    define CICADA_DEBUG_LEVEL (1)
#   else
#    define CICADA_DEBUG_LEVEL (0)
#   endif
#  endif
# endif

// C++ features

# ifndef CICADA_NODISCARD
#  if !defined(CICADA_SUPPRESS_NODISCARD) && (defined(CICADA_CPP_STANDARD_17) || (defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)))
#   define CICADA_NODISCARD [[nodiscard]]
#  else
#   define CICADA_NODISCARD
#  endif
# endif

# ifndef CICADA_DEPRECATED
#  if !defined(CICADA_SUPPRESS_DEPRECATED) && ((defined(CICADA_CPP_STANDARD_14) || defined(CICADA_CPP_STANDARD_17)) || (defined(__has_cpp_attribute) && __has_cpp_attribute(deprecated)))
#   define CICADA_DEPRECATED(msg) [[deprecated(msg)]]
#  else
#   define CICADA_DEPRECATED(msg)
#  endif
# endif

// Compiler-specific extensions

# ifndef CICADA_DISABLE_COMPILER_EXTENSIONS

#  ifndef CICADA_FORCEINLINE

#   ifdef CICADA_COMPILER_MSVC
#    define CICADA_FORCEINLINE __forceinline
#   else
#    define CICADA_FORCEINLINE inline
#   endif
#  endif

// TODO correct usage of CICADA_API

#  ifndef CICADA_NOINLINE
#   ifdef CICADA_COMPILER_MSVC
#    define CICADA_NOINLINE __declspec(noinline)
#   else
#    define CICADA_NOINLINE
#   endif
#  endif

#  ifndef CICADA_NOVTABLE
#   ifdef CICADA_COMPILER_MSVC
#    define CICADA_NOVTABLE __declspec(novtable)
#   else
#    define CICADA_NOVTABLE
#   endif
#  endif

# else

#  ifndef CICADA_FORCEINLINE
#   define CICADA_FORCEINLINE
#  endif

#  ifndef CICADA_API
#   define CICADA_API
#  endif

#  ifndef CICADA_NOINLINE
#   define CICADA_NOINLINE
#  endif

#  ifndef CICADA_NOVTABLE
#   define CICADA_NOVTABLE
#  endif

# endif

#endif