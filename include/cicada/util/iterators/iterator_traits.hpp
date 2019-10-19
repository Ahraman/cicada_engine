#ifndef CICADA_UTIL_ITERATORS_ITERATOR_TRAITS_HEADER_GUARD
# define CICADA_UTIL_ITERATORS_ITERATOR_TRAITS_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

namespace ccd {
	template<typename Iterator>
	struct iterator_traits
	{
		using iterator_type = Iterator;
	};

	template<typename T>
	struct iterator_traits<T*>
	{
		using iterator_type = T*;
	};
}

#endif