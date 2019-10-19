#ifndef CICADA_CORE_MACROS_HEADER_GUARD
# define CICADA_CORE_MACROS_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifndef CICADA_DISABLE_COMPILER_EXTENSIONS

#  ifndef CICADA_CORE_API
#   ifdef CICADA_COMPILER_MSVC
#    ifdef CICADA_CORE_EXPORT
#     define CICADA_CORE_API __declspec(dllexport)
#    else
#     define CICADA_CORE_API __declspec(dllimport)
#    endif
#   else
#    define CICADA_CORE_API
#   endif
#  endif

# else
#  ifndef CICADA_CORE_API
#   define CICADA_CORE_API
#  endif

# endif

#endif