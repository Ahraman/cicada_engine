#ifndef CICADA_UTIL_TYPES_IS_FLOATING_POINT_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_FLOATING_POINT_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "integral_constant.hpp"
# include "is_same.hpp"
# include "remove_cv.hpp"

namespace ccd {
	template<typename T>
	struct is_floating_point
		: public disjunction<
		is_same<remove_cv_t<T>, float>,
		is_same<remove_cv_t<T>, double>,
		is_same<remove_cv_t<T>, long double>>
	{};

	template<typename T>
	constexpr bool is_integer_v = is_integer<T>::value;
}

#endif