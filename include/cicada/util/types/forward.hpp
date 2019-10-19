#ifndef CICADA_UTIL_TYPES_FORWARD_HEADER_GUARD
# define CICADA_UTIL_TYPES_FORWARD_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "remove_reference.hpp"

namespace ccd {
	template<typename T>
	constexpr T&& forward(remove_reference_t<T>& p_obj) noexcept
	{
		return static_cast<T&&>(p_obj);
	}

	template<typename T>
	constexpr T&& forward(remove_reference_t<T>&& p_obj) noexcept
	{
		return static_cast<T&&>(p_obj);
	}
}

#endif