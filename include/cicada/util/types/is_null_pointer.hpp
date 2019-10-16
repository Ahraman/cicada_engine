#ifndef CICADA_UTIL_TYPES_IS_NULL_POINTER_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_NULL_POINTER_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"
# include "is_same.hpp"
# include "remove_cv.hpp"

namespace ccd {
	template<typename T>
	using is_null_pointer = is_same<remove_cv_t<T>, decltype(nullptr)>;

	template<typename T>
	constexpr bool is_null_pointer_v = is_null_pointer<T>::value;
}

#endif