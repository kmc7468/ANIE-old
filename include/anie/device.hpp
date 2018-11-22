#ifndef ANIE_HEADER_DEVICE_HPP
#define ANIE_HEADER_DEVICE_HPP
#include <anie/config.hpp>

#include <anie/command.hpp>

#include <any>
#include <future>
#include <memory>

namespace anie
{
	class ANIE_EXPORT device
	{
	public:
		device(const device& device) = delete;
		device(device&& device) = delete;
		virtual ~device() = default;

	protected:
		device() noexcept = default;

	public:
		device& operator=(const device& device) = delete;
		device& operator=(device&& device) = delete;
		bool operator==(const device& device) = delete;
		bool operator!=(const device& device) = delete;

	public:
		virtual std::future<std::any> enqueue(const command& command) = 0;
	};

	using device_ptr = std::shared_ptr<device>;
}

//#include <anie/devices/cpu_seq_device.hpp>
#endif