#ifndef CICADA_UTIL_TYPES_DISJUNCTION_HEADER_GUARD
# define CICADA_UTIL_TYPES_DISJUNCTION_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T, typename... Rest>
	struct disjunction
		: public bool_constant<T::value || disjunction<Rest...>::value>
	{};

	template<typename T>
	struct disjunction<T>
		: public bool_constant<T::value>
	{};

	template<typename... Traits>
	constexpr bool disjunction_v = disjunction<Traits...>::value;
}

#endif