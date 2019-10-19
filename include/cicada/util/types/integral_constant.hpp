#ifndef CICADA_UTIL_TYPES_INTEGRAL_CONSTANT_HEADER_GUARD
# define CICADA_UTIL_TYPES_INTEGRAL_CONSTANT_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	template<typename T, T Value>
	struct integral_constant
	{
		using my_type = integral_constant<T, Value>;

		using value_type = T;

		static constexpr value_type value = Value;

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr operator value_type() const noexcept
		{
			return value;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr value_type operator()() const noexcept
		{
			return value;
		}
	};

	template<bool Value>
	using bool_constant = integral_constant<bool, Value>;

	using false_type = bool_constant<false>;
	using true_type = bool_constant<true>;
}

#endif