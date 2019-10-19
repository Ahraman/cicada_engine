#ifndef CICADA_UTIL_TYPES_REMOVE_CVREF_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_CVREF_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "remove_cv.hpp"
# include "remove_reference.hpp"

namespace ccd {
	template<typename T>
	using remove_cvref = remove_cv<remove_reference_t<T>>;

	template<typename T>
	using remove_cvref_t = typename remove_cvref<T>::type;
}

#endif