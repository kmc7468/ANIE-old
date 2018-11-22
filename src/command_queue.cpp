#include <anie/command_queue.hpp>

#include <stdexcept>
#include <utility>

namespace anie
{
	command_queue::command_queue(const device_ptr& device)
		: device_(device)
	{
		if (!device_)
			throw std::invalid_argument("!device");
	}
	command_queue::command_queue(device_ptr&& device)
		: device_(std::move(device))
	{
		if (!device_)
			throw std::invalid_argument("!device");
	}

	device_ptr command_queue::device() const noexcept
	{
		return device_;
	}
}