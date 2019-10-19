#ifndef CICADA_UTIL_TYPES_DECLVAL_HEADER_GUARD
# define CICADA_UTIL_TYPES_DECLVAL_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "add_rvalue_reference.hpp"

namespace ccd {
	template<typename T>
	typename add_rvalue_reference_t<T> declval() noexcept;
}

#endif