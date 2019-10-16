#ifndef CICADA_UTIL_TYPES_IS_CLASS_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_CLASS_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct is_class
		: public bool_constant<__is_class(T)>
	{};

	template<typename T>
	constexpr bool is_class_v = is_class<T>::value;
}

#endif