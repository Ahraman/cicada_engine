#ifndef CICADA_UTIL_TYPES_IS_INTEGRAL_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_INTEGRAL_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "is_bool.hpp"
# include "is_char.hpp"
# include "is_integer.hpp"

namespace ccd {
	template<typename T>
	struct is_integral
		: public disjunction<
		is_bool<T>,
		is_char<T>,
		is_integer<T>>
	{};

	template<typename T>
	constexpr bool is_integral_v = is_integral<T>::value;
}

#endif