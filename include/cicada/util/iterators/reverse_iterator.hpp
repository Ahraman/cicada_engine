#ifndef CICADA_UTIL_ITERATOR_ITERATOR_REVERSE_ITERATOR_HEADER_GUARD
# define CICADA_UTIL_ITERATOR_ITERATOR_REVERSE_ITERATOR_HEADER_GUARD (1)

# include "cicada/cicada_macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <iterator>

# include "cicada/util/types/declval.hpp"

namespace ccd {
	template<typename It, typename Traits = std::iterator_traits<It>>
	class reverse_iterator
	{
	public:
		using base_type = It;
		using base_traits_type = Traits;

		using value_type = typename base_traits_type::value_type;
		using pointer = typename base_traits_type::pointer;
		using reference = typename base_traits_type::reference;

		using difference_type = typename base_traits_type::difference_type;

		using iterator_categry = typename base_traits_type::iterator_category;

		CICADA_FORCEINLINE constexpr reverse_iterator()
			: m_base()
		{}

		CICADA_FORCEINLINE constexpr explicit reverse_iterator(const base_type& p_base)
			: m_base(p_base)
		{}

		template<typename Other>
		CICADA_FORCEINLINE constexpr reverse_iterator(const reverse_iterator<Other>& p_other)
			: m_base(p_other.m_base)
		{}

		template<typename Other>
		CICADA_FORCEINLINE constexpr reverse_iterator& operator=(const reverse_iterator<Other>& p_other)
		{
			this->m_base = p_other.m_base;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr base_type& base() noexcept
		{
			return (this->m_base);
		}

		CICADA_FORCEINLINE constexpr const base_type& base() const noexcept
		{
			return (this->m_base);
		}

		CICADA_FORCEINLINE constexpr reference operator*() const noexcept
		{
			base_type _temp(this->m_base);
			return (*--_temp);
		}
	private:
		base_type m_base;
	};
}

#endif