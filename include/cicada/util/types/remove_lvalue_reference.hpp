#ifndef CICADA_UTIL_TYPES_REMOVE_LVALUE_REFERENCE_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_LVALUE_REFERENCE_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "type_identity.hpp"

namespace ccd {
	template<typename T>
	struct remove_lvalue_reference
		: public type_identity<T>
	{};

	template<typename T>
	struct remove_lvalue_reference<T&>
		: public type_identity<T>
	{};

	template<typename T>
	using remove_lvalue_reference_t = typename remove_lvalue_reference<T>::type;
}

#endif