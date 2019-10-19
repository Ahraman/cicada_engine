#ifndef CICADA_UTIL_TYPES_NEGATION_HEADER_GUARD
# define CICADA_UTIL_TYPES_NEGATION_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"

namespace ccd {
	template<typename T>
	struct negation
		: public bool_constant<!T::value>
	{};

	template<typename T>
	constexpr bool negation_v = negation<T>::value;
}

#endif