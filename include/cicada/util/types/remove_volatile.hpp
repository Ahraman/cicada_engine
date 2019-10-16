#ifndef CICADA_UTIL_TYPES_REMOVE_VOLATILE_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_VOLATILE_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "type_identity.hpp"

namespace ccd {
	template<typename T>
	struct remove_volatile
		: public type_identity<T>
	{};

	template<typename T>
	struct remove_volatile<volatile T>
		: public type_identity<T>
	{};

	template<typename T>
	using remove_volatile_t = typename remove_volatile<T>::type;
}

#endif