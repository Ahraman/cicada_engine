#ifndef CICADA_UTIL_TYPES_IS_UNBOUNDED_ARRAY_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_UNBOUNDED_ARRAY_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct is_unbounded_array
		: public false_type
	{};

	template<typename T>
	struct is_unbounded_array<T[]>
		: public true_type
	{};

	template<typename T>
	constexpr bool is_unbounded_array_v = is_unbounded_array<T>::value;
}

#endif