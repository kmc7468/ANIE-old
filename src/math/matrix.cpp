#include <anie/math/matrix.hpp>

#include <utility>

namespace anie
{
	matrix::matrix(mutex_base_ptr&& mutex) noexcept
		: mutex(std::move(mutex))
	{}
	matrix::matrix(std::size_t size)
		: data_(size * size), height_(size)
	{}
	matrix::matrix(std::size_t width, std::size_t height)
		: data_(width * height), height_(height)
	{}
	matrix::matrix(mutex_base_ptr&& mutex, std::size_t size)
		: mutex(std::move(mutex)), data_(size * size), height_(size)
	{}
	matrix::matrix(mutex_base_ptr&& mutex, std::size_t width, std::size_t height)
		: mutex(std::move(mutex)), data_(width * height), height_(height)
	{}
	matrix::matrix(const std::vector<arithemtic_type>& vector, std::size_t width, std::size_t height)
		: data_(vector), height_(height)
	{
		if (width * height != data_.size())
			throw std::invalid_argument("width * height == data_.size()");
	}
	matrix::matrix(std::vector<arithemtic_type>&& vector, std::size_t width, std::size_t height)
		: data_(std::move(vector)), height_(height)
	{
		if (width * height != data_.size())
			throw std::invalid_argument("width * height == data_.size()");
	}
	matrix::matrix(const std::vector<std::vector<arithemtic_type>>& vector)
		: height_(vector.size())
	{
		if (!height_) return;

		const std::size_t width = vector.front().size();
		data_.resize(width * height_);

		for (std::size_t i = 0; i < height_; ++i)
		{
			std::copy(vector[i].begin(), vector[i].end(), data_.begin() + i * width);
		}
	}
	matrix::matrix(const matrix& matrix)
		: data_(matrix.data_), height_(matrix.height_)
	{}
	matrix::matrix(matrix&& matrix) noexcept
		: data_(std::move(matrix.data_)), height_(matrix.height_)
	{
		matrix.height_ = 0;
	}
	matrix::matrix(std::initializer_list<std::initializer_list<arithemtic_type>> ilist)
		: height_(ilist.size())
	{
		if (!height_) return;

		const std::size_t width = ilist.begin()->size();
		data_.resize(width * height_);

		std::size_t i = 0;
		const std::initializer_list<arithemtic_type>* iter = ilist.begin();

		for (; iter != ilist.end(); ++iter, ++i)
		{
			std::copy(iter->begin(), iter->end(), data_.begin() + i * width);
		}
	}

	matrix& matrix::operator=(const std::vector<std::vector<arithemtic_type>>& vector)
	{
		if (!(height_ = vector.size())) return *this;

		const std::size_t width = vector.front().size();
		data_.resize(width * height_);

		for (std::size_t i = 0; i < height_; ++i)
		{
			std::copy(vector[i].begin(), vector[i].end(), data_.begin() + i * width);
		}

		return *this;
	}
	matrix& matrix::operator=(const matrix& matrix)
	{
		data_ = matrix.data_;
		height_ = matrix.height_;

		return *this;
	}
	matrix& matrix::operator=(matrix&& matrix) noexcept
	{
		data_ = std::move(matrix.data_);
		height_ = matrix.height_;

		matrix.height_ = 0;

		return *this;
	}
	matrix& matrix::operator=(std::initializer_list<std::initializer_list<arithemtic_type>> ilist)
	{
		if (!(height_ = ilist.size())) return *this;

		const std::size_t width = ilist.begin()->size();
		data_.resize(width * height_);

		std::size_t i = 0;
		const std::initializer_list<arithemtic_type>* iter = ilist.begin();

		for (; iter != ilist.end(); ++iter, ++i)
		{
			std::copy(iter->begin(), iter->end(), data_.begin() + i * width);
		}

		return *this;
	}

	void matrix::clear() noexcept
	{
		data_.clear();
		height_ = 0;
	}
	void matrix::swap(matrix& matrix) noexcept
	{
		data_.swap(matrix.data_);
		std::swap(height_, matrix.height_);
	}
	bool matrix::empty() const noexcept
	{
		return height_ == 0;
	}
	std::size_t matrix::width() const noexcept
	{
		return data_.size() / height_;
	}
	std::size_t matrix::height() const noexcept
	{
		return height_;
	}
}