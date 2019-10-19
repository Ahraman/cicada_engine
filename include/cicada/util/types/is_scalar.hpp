#ifndef CICADA_UTIL_TYPES_IS_SCALAR_HEADER_GUARD
# define CICADA_UTIL_TYPES_IS_SCALAR_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include "disjunction.hpp"
# include "is_arithmetic.hpp"
# include "is_enum.hpp"
# include "is_member_pointer.hpp"
# include "is_null_pointer.hpp"
# include "is_pointer.hpp"

namespace ccd {
	template<typename T>
	using is_scalar = disjunction<
		is_arithmetic<T>,
		is_enum<T>,
		is_pointer<T>,
		is_member_pointer<T>,
		is_null_pointer<T>>;

	template<typename T>
	constexpr bool is_scalar_v = is_scalar<T>::value;
}

#endif