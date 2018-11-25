#ifndef ANIE_HEADER_DEVICES_CPU_SEQ_DEVICE_HPP
#define ANIE_HEADER_DEVICES_CPU_SEQ_DEVICE_HPP
#include <anie/config.hpp>

#include <anie/command.hpp>
#include <anie/device.hpp>

#include <any>
#include <future>

namespace anie
{
	namespace details
	{
		class ANIE_EXPORT cpu_seq_device_t final : public device
		{
		public:
			cpu_seq_device_t() noexcept = default;
			cpu_seq_device_t(const cpu_seq_device_t& device) = delete;
			cpu_seq_device_t(cpu_seq_device_t&& device) = delete;
			virtual ~cpu_seq_device_t() override = default;

		public:
			cpu_seq_device_t& operator=(const cpu_seq_device_t& device) = delete;
			cpu_seq_device_t& operator=(cpu_seq_device_t&& device) = delete;
			bool operator==(const cpu_seq_device_t& device) = delete;
			bool operator!=(const cpu_seq_device_t& device) = delete;

		public:
			virtual std::future<std::any> enqueue(const command& command) override;
			virtual void* create_buffer(std::size_t size) override;
			virtual void release_buffer(void* buffer) override;
		};
	}

	static inline const device_ptr cpu_seq_device = std::make_shared<details::cpu_seq_device_t>();
}

#endif