#ifndef CICADA_UTIL_TYPES_IS_POINTER_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_POINTER_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"
# include "remove_cv.hpp"

namespace ccd {
	namespace detail {
		template<typename T>
		struct is_pointer_impl
			: public false_type
		{};

		template<typename T>
		struct is_pointer_impl<T*>
			: public true_type
		{};
	}

	template<typename T>
	using is_pointer = detail::is_pointer_impl<remove_cv_t<T>>;

	template<typename T>
	constexpr bool is_pointer_v = is_pointer<T>::value;
}

#endif