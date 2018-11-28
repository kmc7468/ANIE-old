#include <anie/devices/cpu_seq.hpp>

#include <algorithm>
#include <cstdint>
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
	void cpu_seq_t::copy_buffer_to_main_memory(const clwrap::buffer& buffer, void* address, std::size_t size)
	{
		if (buffer.empty()) return;

		const std::uint8_t* const buffer_b = reinterpret_cast<const std::uint8_t*>(buffer.address());
		std::copy(buffer_b, buffer_b + size, reinterpret_cast<std::uint8_t*>(address));
	}
	void cpu_seq_t::copy_main_memory_to_buffer(clwrap::buffer& buffer, const void* address, std::size_t size)
	{
		if (buffer.empty()) return;

		const std::uint8_t* const address_b = reinterpret_cast<const std::uint8_t*>(address);
		std::copy(address_b, address_b + size, reinterpret_cast<std::uint8_t*>(buffer.address()));
	}
}