#ifndef CICADA_UTIL_TYPES_IS_INTEGER_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_INTEGER_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "integral_constant.hpp"
# include "is_same.hpp"
# include "remove_cv.hpp"

namespace ccd {
	namespace detail {
# ifdef CICADA_COMPILER_MSVC
		template<typename T>
		struct is_extension_integer
			: public disjunction<
			is_same<remove_cv_t<T>, signed __int8>,
			is_same<remove_cv_t<T>, signed __int16>,
			is_same<remove_cv_t<T>, signed __int32>,
			is_same<remove_cv_t<T>, signed __int64>,
			is_same<remove_cv_t<T>, unsigned __int8>,
			is_same<remove_cv_t<T>, unsigned __int16>,
			is_same<remove_cv_t<T>, unsigned __int32>,
			is_same<remove_cv_t<T>, unsigned __int64>>
		{};
# else
		template<typename T>
		struct is_extension_integer
			: public false_type
		{};
# endif
	}

	template<typename T>
	struct is_integer
		: public disjunction<
		is_same<remove_cv_t<T>, signed char>,
		is_same<remove_cv_t<T>, signed short>,
		is_same<remove_cv_t<T>, signed int>,
		is_same<remove_cv_t<T>, signed long>,
		is_same<remove_cv_t<T>, signed long long>,
		is_same<remove_cv_t<T>, unsigned char>,
		is_same<remove_cv_t<T>, unsigned short>,
		is_same<remove_cv_t<T>, unsigned int>,
		is_same<remove_cv_t<T>, unsigned long>,
		is_same<remove_cv_t<T>, unsigned long long>,
		detail::is_extension_integer<T>>
	{};

	template<typename T>
	constexpr bool is_integer_v = is_integer<T>::value;
}

#endif