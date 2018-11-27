#include <anie/clwrap/buffer.hpp>

#include <anie/device.hpp>

#include <utility>

namespace anie::clwrap
{
	buffer::buffer(buffer&& buffer) noexcept
		: device_(std::move(buffer.device_)), data_(std::move(buffer.data_))
	{}
	buffer::~buffer()
	{
		release();
	}

	buffer::buffer(anie::device* device, void* main_memory) noexcept
		: device_(device), data_(main_memory)
	{}
	buffer::buffer(anie::device* device, cl_mem main_memory) noexcept
		: device_(device), data_(main_memory)
	{}

	buffer& buffer::operator=(buffer&& buffer) noexcept
	{
		release();

		device_ = std::move(buffer.device_);
		data_ = std::move(buffer.data_);

		return *this;
	}
	buffer::operator bool() const noexcept
	{
		return data_.index() != 0;
	}

	bool buffer::empty() const noexcept
	{
		return data_.index() == 0;
	}
	void buffer::release() noexcept
	{
		switch (data_.index())
		{
		case 1:
			device_->release_buffer(std::get<1>(data_));
			break;

		case 2:
			device_->release_buffer(std::get<2>(data_));
			break;
		}

		device_ = nullptr;
		data_ = std::monostate();
	}
	bool buffer::main_memory() const noexcept
	{
		return data_.index() == 1;
	}
	bool buffer::video_memory() const noexcept
	{
		return data_.index() == 2;
	}

	device* buffer::device() const noexcept
	{
		return device_;
	}
	void* buffer::address() const noexcept
	{
		if (main_memory()) return std::get<1>(data_);
		else return nullptr;
	}
	cl_mem buffer::handle() const noexcept
	{
		if (video_memory()) return std::get<2>(data_);
		else return nullptr;
	}
}