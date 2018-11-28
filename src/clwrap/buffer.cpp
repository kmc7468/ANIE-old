#include <anie/clwrap/buffer.hpp>

#include <anie/device.hpp>
#include <anie/devices/cpu_seq.hpp>

#include <algorithm>
#include <cstdint>
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

	void buffer::copy_to(buffer& buffer, std::size_t size) const
	{
		switch (buffer.data_.index())
		{
		case 1:
			device_->copy_buffer_to_main_memory(*this, buffer.address(), size);
			break;

		case 2:
		{
			switch (data_.index())
			{
			case 1:
				buffer.device_->copy_main_memory_to_buffer(buffer, address(), size);
				break;

			case 2:
				clwrap::buffer cpu_buf = cpu_seq->create_buffer(size);
				device_->copy_buffer_to_main_memory(*this, buffer.address(), size);
				buffer.device_->copy_main_memory_to_buffer(buffer, cpu_buf.address(), size);
				break;
			}
		}
		}
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