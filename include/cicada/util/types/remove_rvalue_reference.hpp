#ifndef CICADA_UTIL_TYPES_REMOVE_RVALUE_REFERENCE_HEADER_GUARD
# define CICADA_UTIL_TYPES_REMOVE_RVALUE_REFERENCE_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "type_identity.hpp"

namespace ccd {
	template<typename T>
	struct remove_rvalue_reference
		: public type_identity<T>
	{};

	template<typename T>
	struct remove_rvalue_reference<T&&>
		: public type_identity<T>
	{};

	template<typename T>
	using remove_rvalue_reference_t = typename remove_rvalue_reference<T>::type;
}

#endif