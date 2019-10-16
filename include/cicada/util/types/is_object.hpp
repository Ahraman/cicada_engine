#ifndef CICADA_UTIL_TYPES_IS_OBJECT_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_OBJECT_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "is_array.hpp"
# include "is_class.hpp"
# include "is_scalar.hpp"
# include "is_union.hpp"

namespace ccd {
	template<typename T>
	using is_object = disjunction<
		is_scalar<T>,
		is_array<T>,
		is_class<T>,
		is_union<T>>;

	template<typename T>
	constexpr bool is_object_v = is_object<T>::value;
}

#endif