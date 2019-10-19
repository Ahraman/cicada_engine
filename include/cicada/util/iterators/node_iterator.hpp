#ifndef CICADA_UTIL_ITERATORS_NODE_ITERATOR_HEADER_GUARD
# define CICADA_UTIL_ITERATORS_NODE_ITERATOR_HEADER_GUARD (1)

# include "cicada/macros.h"

# ifdef CICADA_PRAGMA_ONCE
#  pragma once
# endif

# include <iterator> // TODO use my own header

namespace ccd {
	template<typename T, typename Node, T Node::* Value, Node* Node::* Next, Node * Node::* Prev>
	class const_node_iterator;

	template<typename T, typename Node, T Node::*Value, Node* Node::*Next, Node* Node::*Prev>
	class node_iterator
	{
	public:
		using value_type = T;
		using reference = T&;
		using pointer = T*;

		using node_type = Node;
		using node_ptr = node_type*;

		using difference_type = ptrdiff_t;

		using iterator_category = std::bidirectional_iterator_tag;

		CICADA_FORCEINLINE constexpr node_iterator() noexcept
			: m_node()
		{}

		CICADA_FORCEINLINE constexpr explicit node_iterator(node_ptr p_node) noexcept
			: m_node(p_node)
		{}

		CICADA_FORCEINLINE constexpr node_iterator(node_iterator p_other) noexcept
			: m_node(p_other.m_node)
		{}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_ptr node() const noexcept
		{
			return this->m_node;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator*() const noexcept
		{
			return (this->m_node->*Value);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer operator->() const noexcept
		{
			return &(this->m_node->*Value);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_iterator& operator++() noexcept
		{
			this->m_node = this->m_node->*Next;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_iterator operator++(int) noexcept
		{
			node_iterator _temp(*this);
			this->m_node = this->m_node->*Next;
			return _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_iterator& operator--() noexcept
		{
			this->m_node = this->m_node->*Prev;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_iterator operator--(int) noexcept
		{
			node_iterator _temp(*this);
			this->m_node = this->m_node->*Prev;
			return _temp;
		}
	private:
		node_ptr m_node;
	};

	template<typename T, typename Node, T Node::* Value, Node * Node::* Next, Node * Node::* Prev>
	class const_node_iterator
	{
	public:
		using value_type = T;
		using reference = const T&;
		using pointer = const T*;

		using node_type = Node;
		using node_ptr = const node_type*;

		using difference_type = ptrdiff_t;

		using iterator_category = std::bidirectional_iterator_tag;

		CICADA_FORCEINLINE constexpr const_node_iterator() noexcept
			: m_node()
		{}

		CICADA_FORCEINLINE constexpr explicit const_node_iterator(node_ptr p_node) noexcept
			: m_node(p_node)
		{}

		CICADA_FORCEINLINE constexpr const_node_iterator(const_node_iterator p_other) noexcept
			: m_node(p_other.m_node)
		{}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr node_ptr node() const noexcept
		{
			return this->m_node;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr reference operator*() const noexcept
		{
			return (this->m_node->*Value);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr pointer operator->() const noexcept
		{
			return &(this->m_node->*Value);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_node_iterator& operator++() noexcept
		{
			this->m_node = this->m_node->*Next;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_node_iterator operator++(int) noexcept
		{
			node_iterator _temp(*this);
			this->m_node = this->m_node->*Next;
			return _temp;
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_node_iterator& operator--() noexcept
		{
			this->m_node = this->m_node->*Prev;
			return (*this);
		}

		CICADA_NODISCARD CICADA_FORCEINLINE constexpr const_node_iterator operator--(int) noexcept
		{
			node_iterator _temp(*this);
			this->m_node = this->m_node->*Prev;
			return _temp;
		}
	private:
		node_ptr m_node;
	};
}

#endif