#ifndef CICADA_RENDER_MACROS_HEADER_GUARD
# define CICADA_RENDER_MACROS_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# ifndef CICADA_DISABLE_COMPILER_EXTENSIONS

#  ifndef CICADA_RENDER_API
#   ifdef CICADA_COMPILER_MSVC
#    ifdef CICADA_RENDER_EXPORT
#     define CICADA_RENDER_API __declspec(dllexport)
#    else
#     define CICADA_RENDER_API __declspec(dllimport)
#    endif
#   else
#    define CICADA_RENDER_API
#   endif
#  endif

# else

#  ifndef CICADA_RENDER_API
#   define CICADA_RENDER_API
#  endif

# endif

#endif