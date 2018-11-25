#ifndef ANIE_HEADER_CLWRAP_BUFFER_HPP
#define ANIE_HEADER_CLWRAP_BUFFER_HPP
#include <anie/config.hpp>

#include <anie/device.hpp>

#include <memory>
#include <variant>
#include <CL/cl.h>

namespace anie::clwrap
{
	class ANIE_EXPORT buffer final
	{
	public:
		buffer() noexcept = default;
		buffer(const buffer& buffer) = delete;
		buffer(buffer&& buffer) noexcept;
		~buffer();

	public:
		buffer& operator=(const buffer& buffer) = delete;
		buffer& operator=(buffer&& buffer) noexcept;
		bool operator==(const buffer& buffer) = delete;
		bool operator!=(const buffer& buffer) = delete;
		operator bool() const noexcept;

	public:
		bool empty() const noexcept;
		void release() noexcept;
		bool main_memory() const noexcept;

	private:
		device_ptr device_;
		std::variant<std::monostate, void*, cl_mem> data_;
	};
}

#endif