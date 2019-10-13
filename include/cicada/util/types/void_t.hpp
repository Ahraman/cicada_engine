#ifndef CICADA_UTIL_TYPES_VOID_T_HEADER_GUARD
# define CICADA_UTIL_TYPES_VOID_T_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	template<typename... Args>
	using void_t = void;
}

#endif