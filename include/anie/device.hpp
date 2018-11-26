#ifndef ANIE_HEADER_DEVICE_HPP
#define ANIE_HEADER_DEVICE_HPP
#include <anie/config.hpp>

#include <anie/command.hpp>
#include <anie/clwrap/buffer.hpp>

#include <any>
#include <cstddef>
#include <future>
#include <memory>
#include <CL/cl.h>

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
		virtual clwrap::buffer create_buffer(std::size_t size) = 0;
		virtual void release_buffer(void* buffer) = 0;

	protected:
		clwrap::buffer create_buffer_instance(void* main_memory);
		clwrap::buffer create_buffer_instance(cl_mem main_memory);
	};
}

#include <anie/devices/cpu_seq.hpp>
#endif