#ifndef CICADA_UTIL_TYPES_IS_SAME_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_SAME_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename A, typename B>
	struct is_same
		: public false_type
	{};

	template<typename T>
	struct is_same<T, T>
		: public true_type
	{};

	template<typename A, typename B>
	constexpr bool is_same_v = is_same<A, B>::value;
}

#endif