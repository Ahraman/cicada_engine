#ifndef CICADA_UTIL_ITERATORS_ARRAY_ITERATOR_HEADER_GUARD
# define CICADA_UTIL_ITERATORS_ARRAY_ITERATOR_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <iterator> // TODO use my own header

namespace ccd {
	template<typename Elem>
	class const_array_iterator;

	template<typename Elem>
	class array_iterator
	{
	public:
		using value_type = Elem;
		using pointer = value_type*;
		using reference = value_type&;

		using difference_type = ptrdiff_t;
		
		using iterator_category = std::random_access_iterator_tag;

		CICADA_FORCEINLINE constexpr array_iterator() noexcept
			: m_ptr()
		{}

		CICADA_FORCEINLINE constexpr explicit array_iterator(pointer p_ptr) noexcept
			: m_ptr(p_ptr)
		{}

		CICADA_FORCEINLINE constexpr array_iterator(const array_iterator& p_other) noexcept
			: m_ptr(p_other.m_ptr)
		{}

		CICADA_FORCEINLINE constexpr array_iterator& operator=(const array_iterator& p_other) noexcept
		{
			this->m_ptr = p_other.m_ptr;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer ptr() const noexcept
		{
			return this->m_ptr;
		}

		CICADA_FORCEINLINE constexpr void swap(array_iterator& p_other) noexcept
		{
			array_iterator::pointer _temp(this->m_ptr);
			this->m_ptr = p_other.m_ptr;
			p_other.m_ptr = _temp;
		}

		friend CICADA_FORCEINLINE constexpr void swap(array_iterator& p_left, array_iterator& p_right) noexcept
		{
			array_iterator::pointer _temp(p_left.m_ptr);
			p_left.m_ptr = p_right.m_ptr;
			p_right.m_ptr = _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator*() const
		{
			return (*this->m_ptr);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator[](difference_type p_offset) const
		{
			return (*(this->m_ptr + p_offset));
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer operator->() const
		{
			return this->m_ptr;
		}

		CICADA_FORCEINLINE constexpr array_iterator& operator++() noexcept
		{
			++this->m_ptr;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr array_iterator operator++(int) noexcept
		{
			array_iterator _temp(*this);
			++this->m_ptr;
			return _temp;
		}

		CICADA_FORCEINLINE constexpr array_iterator& operator--() noexcept
		{
			--this->m_ptr;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr array_iterator operator--(int) noexcept
		{
			array_iterator _temp(*this);
			--this->m_ptr;
			return _temp;
		}

		CICADA_FORCEINLINE constexpr array_iterator& operator+=(difference_type p_offset) noexcept
		{
			this->m_ptr += p_offset;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr array_iterator& operator-=(difference_type p_offset) noexcept
		{
			this->m_ptr -= p_offset;
			return (*this);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr array_iterator operator+(const array_iterator& p_iterator, difference_type p_offset) noexcept
		{
			return array_iterator(p_iterator.m_ptr + p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr array_iterator operator+(difference_type p_offset, const array_iterator& p_iterator) noexcept
		{
			return array_iterator(p_iterator.m_ptr + p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr array_iterator operator-(const array_iterator& p_iterator, difference_type p_offset) noexcept
		{
			return array_iterator(p_iterator.m_ptr - p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr difference_type operator-(const array_iterator& p_left, const array_iterator& p_right) noexcept
		{
			return p_left.m_ptr - p_right.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr == p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator!=(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr != p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr < p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr > p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>=(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr >= p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<=(const array_iterator& p_other) const noexcept
		{
			return this->m_ptr <= p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr == p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator!=(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr != p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr < p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr > p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>=(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr >= p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<=(const const_array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr <= p_other.ptr();
		}
	private:
		pointer m_ptr;
	};

	template<typename Elem>
	class const_array_iterator
	{
	public:		
		using value_type = Elem;
		using pointer = const value_type*;
		using reference = const value_type&;

		using difference_type = ptrdiff_t;
		
		constexpr const_array_iterator() noexcept
			: m_ptr()
		{}

		constexpr explicit const_array_iterator(pointer p_ptr) noexcept
			: m_ptr(p_ptr)
		{}

		CICADA_FORCEINLINE constexpr const_array_iterator(const const_array_iterator& p_other) noexcept
			: m_ptr(p_other.m_ptr)
		{}

		CICADA_FORCEINLINE constexpr const_array_iterator(const array_iterator<value_type>& p_other) noexcept
			: m_ptr(p_other.ptr())
		{}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator=(const const_array_iterator& p_other) noexcept
		{
			this->m_ptr = p_other.m_ptr;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator=(const array_iterator<value_type>& p_other) noexcept
		{
			this->m_ptr = p_other.ptr();
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer ptr() const noexcept
		{
			return this->m_ptr;
		}

		CICADA_FORCEINLINE constexpr void swap(const_array_iterator& p_other) noexcept
		{
			const_array_iterator::pointer _temp(this->m_ptr);
			this->m_ptr = p_other.m_ptr;
			p_other.m_ptr = _temp;
		}

		friend CICADA_FORCEINLINE constexpr void swap(const_array_iterator& p_left, const_array_iterator& p_right) noexcept
		{
			const_array_iterator::pointer _temp(p_left.m_ptr);
			p_left.m_ptr = p_right.m_ptr;
			p_right.m_ptr = _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator*() const
		{
			return (*this->m_ptr);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator[](difference_type p_offset) const
		{
			return (*(this->m_ptr + p_offset));
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer operator->() const
		{
			return this->m_ptr;
		}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator++() noexcept
		{
			++this->m_ptr;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr const_array_iterator operator++(int) noexcept
		{
			const_array_iterator _temp(*this);
			++this->m_ptr;
			return _temp;
		}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator--() noexcept
		{
			--this->m_ptr;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr const_array_iterator operator--(int) noexcept
		{
			const_array_iterator _temp(*this);
			--this->m_ptr;
			return _temp;
		}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator+=(difference_type p_offset) noexcept
		{
			this->m_ptr += p_offset;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr const_array_iterator& operator-=(difference_type p_offset) noexcept
		{
			this->m_ptr -= p_offset;
			return (*this);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr const_array_iterator operator+(const const_array_iterator& p_iterator, difference_type p_offset) noexcept
		{
			return const_array_iterator(p_iterator.m_ptr + p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr const_array_iterator operator+(difference_type p_offset, const const_array_iterator& p_iterator) noexcept
		{
			return const_array_iterator(p_iterator.m_ptr + p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr const_array_iterator operator-(const const_array_iterator& p_iterator, difference_type p_offset) noexcept
		{
			return const_array_iterator(p_iterator.m_ptr - p_offset);
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr difference_type operator-(const const_array_iterator& p_left, const const_array_iterator& p_right) noexcept
		{
			return p_left.m_ptr - p_right.m_ptr;
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr difference_type operator-(const array_iterator<Elem>& p_left, const const_array_iterator& p_right) noexcept
		{
			return p_left.ptr() - p_right.m_ptr;
		}

		CICADA_NODISCARD friend CICADA_FORCEINLINE constexpr difference_type operator-(const const_array_iterator& p_left, const array_iterator<Elem>& p_right) noexcept
		{
			return p_left.m_ptr - p_right.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr == p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator!=(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr != p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr < p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr > p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>=(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr >= p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<=(const const_array_iterator& p_other) const noexcept
		{
			return this->m_ptr <= p_other.m_ptr;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr == p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator!=(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr != p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr < p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr > p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator>=(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr >= p_other.ptr();
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator<=(const array_iterator<value_type>& p_other) const noexcept
		{
			return this->m_ptr <= p_other.ptr();
		}
	private:
		pointer m_ptr;
	};
}

#endif