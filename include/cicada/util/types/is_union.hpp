#ifndef CICADA_UTIL_TYPES_IS_UNION_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_UNION_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct is_union
		: public bool_constant<__is_union(T)>
	{};

	template<typename T>
	constexpr bool is_union_v = is_union<T>::value;
}

#endif