#ifndef CICADA_UTIL_TYPES_IS_ARRAY_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_ARRAY_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "is_bounded_array.hpp"
# include "is_unbounded_array.hpp"

namespace ccd {
	template<typename T>
	using is_array = disjunction<
		is_bounded_array<T>,
		is_unbounded_array<T>>;

	template<typename T>
	constexpr bool is_array_v = is_array<T>::value;
}

#endif