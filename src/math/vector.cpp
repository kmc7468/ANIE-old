#include <anie/math/vector.hpp>

#include <cassert>
#include <stdexcept>
#include <utility>

namespace anie::details // vector_scalar_product
{
	vector_scalar_product::vector_scalar_product(const vector& lhs, const vector& rhs) noexcept
		: lhs_(lhs), rhs_(rhs)
	{}

	std::any vector_scalar_product::run() const
	{
		reader_lock_guard lhs_guard(lhs_.mutex);
		reader_lock_guard rhs_guard(rhs_.mutex);

		arithemtic_type result = 0;

		for (std::size_t i = 0; i < lhs_.size(); ++i)
		{
			result += lhs_[i] * rhs_[i];
		}

		return result;
	}
	std::string_view vector_scalar_product::kernel() const
	{
		return std::string_view(); // TODO
	}
}

namespace anie // vector
{
	vector::vector() noexcept
	{}
	vector::vector(mutex_base_ptr&& mutex)
		: mutex(std::move(mutex))
	{}
	vector::vector(std::size_t size)
		: data_(size)
	{}
	vector::vector(mutex_base_ptr&& mutex, std::size_t size)
		: mutex(std::move(mutex)), data_(size)
	{}
	vector::vector(const std::vector<arithemtic_type>& vector)
		: data_(vector)
	{}
	vector::vector(std::vector<arithemtic_type>&& vector) noexcept
		: data_(std::move(vector))
	{}
	vector::vector(const vector& vector)
		: data_(vector.data_)
	{}
	vector::vector(vector&& vector) noexcept
		: data_(std::move(vector.data_))
	{}
	vector::vector(std::initializer_list<arithemtic_type> ilist)
		: data_(ilist)
	{}

	vector& vector::operator=(const std::vector<arithemtic_type>& vector)
	{
		data_ = vector;
		return *this;
	}
	vector& vector::operator=(std::vector<arithemtic_type>&& vector) noexcept
	{
		data_ = std::move(vector);
		return *this;
	}
	vector& vector::operator=(const vector& vector)
	{
		data_ = vector.data_;
		return *this;
	}
	vector& vector::operator=(vector&& vector) noexcept
	{
		data_ = std::move(vector.data_);
		return *this;
	}
	vector& vector::operator=(std::initializer_list<arithemtic_type> ilist)
	{
		data_ = ilist;
		return *this;
	}
	details::vector_scalar_product vector::operator*(const vector& vector) const noexcept
	{
		assert(size() == vector.size());
		return { *this, vector };
	}
	const arithemtic_type& vector::operator[](std::size_t index) const noexcept
	{
		return data_[index];
	}
	arithemtic_type& vector::operator[](std::size_t index) noexcept
	{
		return data_[index];
	}

	void vector::clear() noexcept
	{
		data_.clear();
	}
	void vector::swap(vector& vector) noexcept
	{
		data_.swap(vector.data_);
	}
	bool vector::empty() const noexcept
	{
		return data_.empty();
	}
	std::size_t vector::size() const noexcept
	{
		return data_.size();
	}

	const arithemtic_type& vector::at(std::size_t index) const
	{
		return data_.at(index);
	}
	arithemtic_type& vector::at(std::size_t index)
	{
		return data_.at(index);
	}
	vector::iterator vector::begin() noexcept
	{
		return data_.begin();
	}
	vector::const_iterator vector::begin() const noexcept
	{
		return data_.begin();
	}
	vector::const_iterator vector::cbegin() const noexcept
	{
		return data_.cbegin();
	}
	vector::iterator vector::end() noexcept
	{
		return data_.end();
	}
	vector::const_iterator vector::end() const noexcept
	{
		return data_.end();
	}
	vector::const_iterator vector::cend() const noexcept
	{
		return data_.cend();
	}
	vector::reverse_iterator vector::rbegin() noexcept
	{
		return data_.rbegin();
	}
	vector::const_reverse_iterator vector::rbegin() const noexcept
	{
		return data_.rbegin();
	}
	vector::const_reverse_iterator vector::crbegin() const noexcept
	{
		return data_.crbegin();
	}
	vector::reverse_iterator vector::rend() noexcept
	{
		return data_.rend();
	}
	vector::const_reverse_iterator vector::rend() const noexcept
	{
		return data_.rend();
	}
	vector::const_reverse_iterator vector::crend() const noexcept
	{
		return data_.crend();
	}

	details::vector_scalar_product vector::scalar_product(const vector& vector) const
	{
		if (size() != vector.size())
			throw std::invalid_argument("size() == vector.size()");

		return { *this, vector };
	}
}