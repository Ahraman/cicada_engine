#ifndef CICADA_UTIL_TYPES_EXCLUSIVE_DISJUNCTION_HEADER_GUARD
# define CICADA_UTIL_TYPES_EXCLUSIVE_DISJUNCTION_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T, typename... Rest>
	struct exclusive_disjunction
		: public bool_constant<T::value != disjunction<Rest...>::value>
	{};

	template<typename T>
	struct exclusive_disjunction<T>
		: public bool_constant<T::value>
	{};

	template<typename... Traits>
	constexpr bool exclusive_disjunction_v = exclusive_disjunction<Traits...>::value;
}

#endif