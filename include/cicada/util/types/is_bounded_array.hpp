#ifndef CICADA_UTIL_TYPES_IS_BOUNDED_ARRAY_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_BOUNDED_ARRAY_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct is_bounded_array
		: public false_type
	{};

	template<typename T, size_t N>
	struct is_bounded_array<T[N]>
		: public true_type
	{};

	template<typename T>
	constexpr bool is_bounded_array_v = is_bounded_array<T>::value;
}

#endif