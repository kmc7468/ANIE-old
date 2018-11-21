#include <anie/math/vector.hpp>

#include <utility>

namespace anie
{
	vector::vector() noexcept
	{}
	vector::vector(std::size_t size)
		: data_(size)
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
}