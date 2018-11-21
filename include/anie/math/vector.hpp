#ifndef ANIE_HEADER_MATH_VECTOR_HPP
#define ANIE_HEADER_MATH_VECTOR_HPP
#include <anie/config.hpp>

#include <cstddef>
#include <initializer_list>
#include <vector>

namespace anie
{
	class ANIE_EXPORT vector final
	{
	public:
		using value_type = arithemtic_type;
		using iterator = std::vector<arithemtic_type>::iterator;
		using const_iterator = std::vector<arithemtic_type>::const_iterator;
		using reverse_iterator = std::vector<arithemtic_type>::reverse_iterator;
		using const_reverse_iterator = std::vector<arithemtic_type>::const_reverse_iterator;
		using pointer = std::vector<arithemtic_type>::pointer;
		using const_pointer = std::vector<arithemtic_type>::const_pointer;
		using reference = std::vector<arithemtic_type>::reference;
		using const_reference = std::vector<arithemtic_type>::const_reference;

	public:
		vector() noexcept;
		explicit vector(std::size_t size);
		vector(const std::vector<arithemtic_type>& vector);
		vector(std::vector<arithemtic_type>&& vector) noexcept;
		vector(const vector& vector);
		vector(vector&& vector) noexcept;
		vector(std::initializer_list<arithemtic_type> ilist);
		~vector() = default;

	public:
		vector& operator=(const std::vector<arithemtic_type>& vector);
		vector& operator=(std::vector<arithemtic_type>&& vector) noexcept;
		vector& operator=(const vector& vector);
		vector& operator=(vector&& vector) noexcept;
		vector& operator=(std::initializer_list<arithemtic_type> ilist);
		bool operator==(const vector& vector) = delete;
		bool operator!=(const vector& vector) = delete;
		const arithemtic_type& operator[](std::size_t index) const noexcept;
		arithemtic_type& operator[](std::size_t index) noexcept;

	public:
		void clear() noexcept;
		void swap(vector& vector) noexcept;
		bool empty() const noexcept;
		std::size_t size() const noexcept;

		const arithemtic_type& at(std::size_t index) const;
		arithemtic_type& at(std::size_t index);
		iterator begin() noexcept;
		const_iterator begin() const noexcept;
		const_iterator cbegin() const noexcept;
		iterator end() noexcept;
		const_iterator end() const noexcept;
		const_iterator cend() const noexcept;
		reverse_iterator rbegin() noexcept;
		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator crbegin() const noexcept;
		reverse_iterator rend() noexcept;
		const_reverse_iterator rend() const noexcept;
		const_reverse_iterator crend() const noexcept;

	private:
		std::vector<arithemtic_type> data_;
	};
}

#endif