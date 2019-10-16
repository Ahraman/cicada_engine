#ifndef CICADA_UTIL_TYPES_CONJUNCTION_HEADER_GUARD
# define CICADA_UTIL_TYPES_CONJUNCTION_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T, typename... Rest>
	struct conjunction
		: public bool_constant<T::value && conjunction<Rest...>::value>
	{};

	template<typename T>
	struct conjunction<T>
		: public bool_constant<T::value>
	{};

	template<typename... Traits>
	constexpr bool conjunction_v = conjunction<Traits...>::value;
}

#endif