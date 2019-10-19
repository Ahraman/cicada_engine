#ifndef CICADA_UTIL_TYPES_IS_MEMBER_POINTER_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_MEMBER_POINTER_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"
# include "remove_cv.hpp"

namespace ccd {
	namespace detail {
		template<typename T>
		struct is_member_pointer_impl
			: public false_type
		{};

		template<typename T, typename U>
		struct is_member_pointer_impl<T U::*>
			: public true_type
		{};
	}

	template<typename T>
	using is_member_pointer = detail::is_member_pointer_impl<remove_cv_t<T>>;

	template<typename T>
	constexpr bool is_member_pointer_v = is_member_pointer<T>::value;
}

#endif