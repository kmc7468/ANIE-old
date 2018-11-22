#ifndef ANIE_HEADER_COMMAND_QUEUE_HPP
#define ANIE_HEADER_COMMAND_QUEUE_HPP
#include <anie/config.hpp>

#include <anie/device.hpp>

#include <memory>

namespace anie
{
	class command_queue final
	{
	public:
		explicit command_queue(const device_ptr& device);
		explicit command_queue(device_ptr&& device);
		command_queue(const command_queue& queue) = delete;
		command_queue(command_queue&& queue) = delete;
		~command_queue() = default;

	public:
		command_queue& operator=(const command_queue& queue) = delete;
		command_queue& operator=(command_queue&& queue) = delete;
		bool operator==(const command_queue& queue) = delete;
		bool operator!=(const command_queue& queue) = delete;

	public:
		device_ptr device() const noexcept;

	private:
		device_ptr device_;
	};

	using command_queue_ptr = std::shared_ptr<command_queue>;
}

#endif