#ifndef CICADA_UTIL_TYPES_REMOVE_REFERENCE_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_REFERENCE_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "remove_lvalue_reference.hpp"
# include "remove_rvalue_reference.hpp"

namespace ccd {
	template<typename T>
	using remove_reference = remove_lvalue_reference<remove_rvalue_reference_t<T>>;

	template<typename T>
	using remove_reference_t = typename remove_reference<T>::type;
}

#endif