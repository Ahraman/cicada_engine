#ifndef CICADA_UTIL_TYPES_TYPE_IDENTITY_HEADER_GUARD
# define CICADA_UTIL_TYPES_TYPE_IDENTITY_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	template<typename T>
	struct type_identity
	{
		using type = T;
	};

	template<typename T>
	using type_identity_t = typename type_identity<T>::type;
}

#endif