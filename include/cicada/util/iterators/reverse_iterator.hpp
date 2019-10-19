#ifndef CICADA_UTIL_ITERATORS_REVERSE_ITERATOR_HEADER_GUARD
# define CICADA_UTIL_ITERATORS_REVERSE_ITERATOR_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <iterator>

# include "cicada/util/types/declval.hpp"
# include "cicada/util/types/forward.hpp"
# include "cicada/util/types/integral_constant.hpp"
# include "cicada/util/types/is_pointer.hpp"

namespace ccd {
	namespace detail {
		template<typename T>
		CICADA_NODISCARD CICADA_FORCEINLINE constexpr T get_arrow_ptr(T p_obj, true_type)
		{
			return p_obj;
		}

		template<typename T>
		CICADA_NODISCARD CICADA_FORCEINLINE constexpr decltype(auto) get_arrow_ptr(T&& p_obj, false_type)
		{
			return forward<T>(p_obj).operator->();
		}
	}

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

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr base_type base() const
		{
			return this->m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator*() const
		{
			base_type _temp(this->m_base);
			return (*--_temp);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer operator->() const
		{
			base_type _temp(this->m_base);
			--_temp;
			return detail::get_arrow_ptr(_temp, is_pointer<base_type>());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator[](difference_type p_offset) const
		{
			return (this->m_base[-p_offset - 1]);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator& operator++()
		{
			--this->m_base;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator operator++(int)
		{
			reverse_iterator _temp(*this);
			--this->m_base;
			return _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator& operator--()
		{
			++this->m_base;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator operator--(int)
		{
			reverse_iterator _temp(*this);
			++this->m_base;
			return _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator& operator+=(difference_type p_offset)
		{
			this->m_base -= p_offset;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator& operator-=(difference_type p_offset)
		{
			this->m_base += p_offset;
			return (*this);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr reverse_iterator operator+(const reverse_iterator& p_it, difference_type p_offset)
		{
			reverse_iterator<T> _temp(p_it);
			return _temp += p_offset;
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr reverse_iterator operator+(difference_type p_offset, const reverse_iterator& p_it)
		{
			reverse_iterator<T> _temp(p_it);
			return _temp += p_offset;
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr reverse_iterator operator-(const reverse_iterator& p_it, difference_type p_offset)
		{
			reverse_iterator<T> _temp(p_it);
			return _temp -= p_offset;
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr difference_type operator-(const reverse_iterator& p_left, const reverse_iterator& p_right)
		{
			return p_left.m_base - p_right.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const reverse_iterator& p_other) noexcept
		{
			return this->m_base == p_other.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator!=(const reverse_iterator& p_other) noexcept
		{
			return this->m_base != p_other.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<(const reverse_iterator& p_other) noexcept
		{
			return this->m_base < p_other.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>(const reverse_iterator& p_other) noexcept
		{
			return this->m_base > p_other.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>=(const reverse_iterator& p_other) noexcept
		{
			return this->m_base >= p_other.m_base;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<=(const reverse_iterator& p_other) noexcept
		{
			return this->m_base <= p_other.m_base;
		}
	protected:
		base_type m_base;
	};
}

#endif