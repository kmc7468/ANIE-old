#include <anie/device.hpp>

namespace anie
{
	clwrap::buffer device::create_buffer_instance(void* main_memory) noexcept
	{
		return { this, main_memory };
	}
	clwrap::buffer device::create_buffer_instance(cl_mem video_memory) noexcept
	{
		return { this, video_memory };
	}
}