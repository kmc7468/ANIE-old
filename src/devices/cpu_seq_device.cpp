#include <anie/devices/cpu_seq_device.hpp>

#include <cstdlib>

namespace anie::details
{
	std::future<std::any> cpu_seq_device_t::enqueue(const command& command)
	{
		std::promise<std::any> promise;
		std::future<std::any> future = promise.get_future();

		promise.set_value(command.run());
		return future;
	}
	clwrap::buffer cpu_seq_device_t::create_buffer(std::size_t size)
	{
		return create_buffer_instance(std::malloc(size));
	}
	void cpu_seq_device_t::release_buffer(void* buffer)
	{
		std::free(buffer);
	}
}