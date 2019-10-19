#ifndef CICADA_UTIL_TYPES_IS_BOOL_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_BOOL_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "is_same.hpp"
# include "remove_cv.hpp"

namespace ccd {
	template<typename T>
	struct is_bool
		: public is_same<remove_cv_t<T>, bool>
	{};

	template<typename T>
	constexpr bool is_bool_v = is_bool<T>::value;
}

#endif