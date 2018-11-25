#ifndef ANIE_HEADER_MATH_MATRIX_HPP
#define ANIE_HEADER_MATH_MATRIX_HPP
#include <anie/config.hpp>

#include <anie/mutex.hpp>

#include <cstddef>
#include <initializer_list>
#include <vector>

namespace anie
{
	class ANIE_EXPORT matrix final
	{
	public:
		matrix() noexcept = default;
		explicit matrix(mutex_base_ptr&& mutex) noexcept;
		explicit matrix(std::size_t size);
		matrix(std::size_t width, std::size_t height);
		matrix(mutex_base_ptr&& mutex, std::size_t size);
		matrix(mutex_base_ptr&& mutex, std::size_t width, std::size_t height);
		matrix(const std::vector<arithemtic_type>& vector, std::size_t width, std::size_t height);
		matrix(std::vector<arithemtic_type>&& vector, std::size_t width, std::size_t height);
		matrix(const std::vector<std::vector<arithemtic_type>>& vector);
		matrix(const matrix& matrix);
		matrix(matrix&& matrix) noexcept;
		matrix(std::initializer_list<std::initializer_list<arithemtic_type>> ilist);
		~matrix() = default;

	public:
		matrix& operator=(const std::vector<std::vector<arithemtic_type>>& vector);
		matrix& operator=(const matrix& matrix);
		matrix& operator=(matrix&& matrix) noexcept;
		matrix& operator=(std::initializer_list<std::initializer_list<arithemtic_type>> ilist);
		bool operator==(const matrix& matrix) = delete;
		bool operator!=(const matrix& matrix) = delete;

	public:
		void clear() noexcept;
		void swap(matrix& matrix) noexcept;
		bool empty() const noexcept;
		std::size_t width() const noexcept;
		std::size_t height() const noexcept;

	public:
		mutex_base_ptr mutex = make_empty_mutex();

	private:
		std::vector<arithemtic_type> data_;
		std::size_t height_ = 0;
	};
}

#endif