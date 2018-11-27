#ifndef ANIE_HEADER_DEVICES_CPU_SEQ_HPP
#define ANIE_HEADER_DEVICES_CPU_SEQ_HPP
#include <anie/config.hpp>

#include <anie/command.hpp>
#include <anie/device.hpp>
#include <anie/clwrap/buffer.hpp>

#include <any>
#include <future>

namespace anie
{
	namespace details
	{
		class ANIE_EXPORT cpu_seq_t final : public device
		{
		public:
			cpu_seq_t() noexcept = default;
			cpu_seq_t(const cpu_seq_t& device) = delete;
			cpu_seq_t(cpu_seq_t&& device) = delete;
			virtual ~cpu_seq_t() override = default;

		public:
			cpu_seq_t& operator=(const cpu_seq_t& device) = delete;
			cpu_seq_t& operator=(cpu_seq_t&& device) = delete;
			bool operator==(const cpu_seq_t& device) = delete;
			bool operator!=(const cpu_seq_t& device) = delete;

		public:
			virtual std::future<std::any> enqueue(const command& command) override;
			virtual clwrap::buffer create_buffer(std::size_t size) override;
			virtual void release_buffer(void* buffer) noexcept override;
		};
	}

	static inline device* const cpu_seq = new details::cpu_seq_t();
}

#endif