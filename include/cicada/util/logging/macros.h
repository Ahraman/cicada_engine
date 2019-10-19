#ifndef CICADA_UTIL_LOGGING_MACROS_HEADER_GUARD
# define CICADA_UTIL_LOGGING_MACROS_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifndef CICADA_DISABLE_COMPILER_EXTENSIONS

#  ifndef CICADA_UTIL_LOGGING_API
#   ifdef CICADA_COMPILER_MSVC
#    ifdef CICADA_UTIL_LOGGING_EXPORT
#     define CICADA_UTIL_LOGGING_API __declspec(dllexport)
#    else
#     define CICADA_UTIL_LOGGING_API __declspec(dllimport)
#    endif
#   else
#    define CICADA_UTIL_LOGGING_API
#   endif
#  endif

# else
#  ifndef CICADA_UTIL_LOGGING_API
#   define CICADA_UTIL_LOGGING_API
#  endif

# endif

#endif