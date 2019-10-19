#ifndef CICADA_UTIL_STRING_STRING_LITERAL_HEADER_GUARD
# define CICADA_UTIL_STRING_STRING_LITERAL_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <string>

# include "cicada/util/algorithm/compare.hpp"

# include "cicada/util/iterators/array_iterator.hpp"

# include <assert.h> // TODO use exceptions

namespace ccd {
	template<typename CharT, typename Traits = std::char_traits<CharT>> // TODO use my own char_traits
	class basic_string_literal
	{
	public:
		using my_type = basic_string_literal<CharT, Traits>;
		
		using traits_type = Traits;

		using value_type = typename traits_type::char_type;
		using pointer = const value_type*;
		using reference = const value_type&;

		using size_type = size_t;
		using difference_type = ptrdiff_t;

		using iterator = const_array_iterator<value_type>;
		using const_iterator = const_array_iterator<value_type>;

		using reverse_iterator = std::reverse_iterator<iterator>; // TODO use my own reverse_iterator
		using const_reverse_iterator = std::reverse_iterator<const_iterator>; // TODO use my own reverse_iterator

		CICADA_FORCEINLINE constexpr basic_string_literal() noexcept
			: m_val()
		{}

		CICADA_FORCEINLINE constexpr basic_string_literal(pointer p_val) noexcept
			: m_val(p_val)
		{}

		CICADA_FORCEINLINE constexpr basic_string_literal& operator=(pointer p_val) noexcept
		{
			this->m_val = p_val;
			return (*this);
		}

		CICADA_FORCEINLINE constexpr basic_string_literal(const basic_string_literal& p_other) noexcept
			: m_val(p_other.m_val)
		{}

		CICADA_FORCEINLINE constexpr basic_string_literal& operator=(const basic_string_literal& p_other) noexcept
		{
			this->m_val = p_other.m_val;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer c_str() const noexcept
		{
			return this->m_val;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer data() const noexcept
		{
			return this->m_val;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator[](difference_type p_offset) noexcept
		{
			return (*(this->m_val + p_offset));
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference at(size_type p_offset) noexcept
		{
			assert(p_offset <= this->size());
			return (*(this->m_val + p_offset));
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference front() noexcept
		{
			return (*this->m_val);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference back() noexcept
		{
			return (*(this->m_val + this->size() - 1));
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr size_type length() const noexcept
		{
			return traits_type::length(this->m_val);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr size_type size() const noexcept
		{
			return traits_type::length(this->m_val);
		}

		// TODO max_size

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool empty() const noexcept
		{
			return !(*this->m_val);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr iterator begin() const noexcept
		{
			return iterator(this->m_val);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr iterator end() const noexcept
		{
			return iterator(this->m_val + this->size());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_iterator cbegin() const noexcept
		{
			return iterator(this->m_val);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_iterator cend() const noexcept
		{
			return iterator(this->m_val + this->size());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator rbegin() const noexcept
		{
			return reverse_iterator(this->end());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reverse_iterator rend() const noexcept
		{
			return reverse_iterator(this->begin());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_reverse_iterator crbegin() const noexcept
		{
			return const_reverse_iterator(this->cend());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_reverse_iterator crend() const noexcept
		{
			return const_reverse_iterator(this->cbegin());
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(const basic_string_literal& p_other) const noexcept
		{
			constexpr size_type _s1 = this->size(), _s2 = p_other.size();
			return (_s1 != _s2) ? false : !traits_type::compare(this->m_val, p_other.m_val, _s1);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr bool operator==(pointer p_other) const noexcept
		{
			constexpr size_type _s1 = this->size(), _s2 = traits_type::length(p_other);
			return (_s1 != _s2) ? false : !traits_type::compare(this->m_val, p_other, _s1);
		}
	private:
		pointer m_val;
	};

	using string_literal = basic_string_literal<char>;
	using wstring_literal = basic_string_literal<wchar_t>;
	using u16string_literal = basic_string_literal<char16_t>;
	using u32string_literal = basic_string_literal<char32_t>;
# ifdef __cpp_char8_t
	using u8string_literal = basic_string_literal<char8_t>;
# endif

	inline namespace literals {
		CICADA_FORCEINLINE constexpr string_literal operator""sl(const char* p_str, size_t) noexcept
		{
			return string_literal(p_str);
		}

		CICADA_FORCEINLINE constexpr wstring_literal operator""sl(const wchar_t* p_str, size_t) noexcept
		{
			return wstring_literal(p_str);
		}

		CICADA_FORCEINLINE constexpr u16string_literal operator""sl(const char16_t* p_str, size_t) noexcept
		{
			return u16string_literal(p_str);
		}

		CICADA_FORCEINLINE constexpr u32string_literal operator""sl(const char32_t* p_str, size_t) noexcept
		{
			return u32string_literal(p_str);
		}

# ifdef __cpp_char8_t
		CICADA_FORCEINLINE constexpr u8string_literal operator""sl(const char8_t* p_str, size_t) noexcept
		{
			return u8string_literal(p_str);
		}
# endif
	}
}

#endif