#include <anie/devices/cpu_seq_device.hpp>

namespace anie::details
{
	std::future<std::any> cpu_seq_device_t::enqueue(const command& command)
	{
		std::promise<std::any> promise;
		std::future<std::any> future = promise.get_future();

		promise.set_value(command.run());
		return future;
	}
}