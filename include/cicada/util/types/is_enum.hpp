#ifndef CICADA_UTIL_TYPES_IS_ENUM_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_ENUM_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct is_enum
		: public bool_constant<__is_enum(T)>
	{};

	template<typename T>
	constexpr bool is_enum_v = is_enum<T>::value;
}

#endif