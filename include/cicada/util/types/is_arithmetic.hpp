#ifndef CICADA_UTIL_TYPES_IS_ARITHMETIC_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_ARITHMETIC_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "is_floating_point.hpp"
# include "is_integral.hpp"

namespace ccd {
	template<typename T>
	struct is_arithmetic
		: public disjunction<
		is_integral<T>,
		is_floating_point<T>>
	{};

	template<typename T>
	constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
}

#endif