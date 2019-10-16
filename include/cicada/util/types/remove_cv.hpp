#ifndef CICADA_UTIL_TYPES_REMOVE_CV_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_CV_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "remove_const.hpp"
# include "remove_volatile.hpp"
# include "type_identity.hpp"

namespace ccd {
	template<typename T>
	struct remove_cv
		: public type_identity<remove_const_t<remove_volatile_t<T>>>
	{};

	template<typename T>
	using remove_cv_t = typename remove_cv<T>::type;
}

#endif