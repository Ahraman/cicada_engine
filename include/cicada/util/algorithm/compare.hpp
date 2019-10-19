#ifndef CICADA_UTIL_ALGORITHM_COMPARE_HEADER_GUARD
# define CICADA_UTIL_ALGORITHM_COMPARE_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# undef max
# undef min

# include "cicada/util/types/declval.hpp"

namespace ccd {
	template<typename T> // TODO use concepts
	CICADA_FORCEINLINE constexpr T (min)(const T& p_left, const T& p_right)
	{
		return (p_left < p_right) ? p_left : p_right
	}

	template<typename T, typename Compare> // TODO use concepts
	CICADA_FORCEINLINE constexpr T (min)(const T& p_left, const T& p_right, Compare p_comp) noexcept(noexcept((declval<Compare>())(declval<T>(), declval<T>())))
	{
		return (p_comp(p_left, p_right)) ? p_left : p_right;
	}
}

#endif