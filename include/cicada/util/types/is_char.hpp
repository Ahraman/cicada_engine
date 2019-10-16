#ifndef CICADA_UTIL_TYPES_IS_CHAR_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_CHAR_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "integral_constant.hpp"
# include "disjunction.hpp"
# include "is_same.hpp"

namespace ccd {
	namespace detail {
# ifdef __cpp_char8_t
		template<typename T>
		struct is_char8
			: public is_same<remove_cv_t<T>, char8_t>
		{};
#else
		template<typename T>
		struct is_char8
			: public false_type
		{};
# endif
	}

	template<typename T>
	struct is_char
		: public disjunction<
			is_same<remove_cv_t<T>, char>,
			is_same<remove_cv_t<T>, char16_t>,
			is_same<remove_cv_t<T>, char32_t>,
			is_same<remove_cv_t<T>, wchar_t>,
			detail::is_char8<T>>
	{};

	template<typename T>
	constexpr bool is_char_v = is_char<T>::value;
}

#endif