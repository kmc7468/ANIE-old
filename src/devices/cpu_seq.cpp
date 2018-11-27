#include <anie/devices/cpu_seq.hpp>

#include <cstdlib>
#include <new>

namespace anie::details
{
	std::future<std::any> cpu_seq_t::enqueue(const command& command)
	{
		std::promise<std::any> promise;
		std::future<std::any> future = promise.get_future();

		promise.set_value(command.run());
		return future;
	}
	clwrap::buffer cpu_seq_t::create_buffer(std::size_t size)
	{
		if (void* const buffer = std::malloc(size); buffer)
			return create_buffer_instance(buffer);
		
		throw std::bad_alloc();
	}
	void cpu_seq_t::release_buffer(void* buffer) noexcept
	{
		if (buffer)
		{
			std::free(buffer);
		}
	}
}