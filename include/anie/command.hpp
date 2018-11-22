#ifndef ANIE_HEADER_COMMAND_HPP
#define ANIE_HEADER_COMMAND_HPP
#include <anie/config.hpp>

#include <any>
#include <string_view>

namespace anie
{
	class ANIE_EXPORT command
	{
	public:
		command(const command& command) = delete;
		command(command&& command) = delete;
		virtual ~command() = default;

	protected:
		command() noexcept = default;
		
	public:
		command& operator=(const command& command) = delete;
		command& operator=(command&& command) = delete;
		bool operator==(const command& command) = delete;
		bool operator!=(const command& command) = delete;

	public:
		virtual std::any run() const = 0;
		virtual std::string_view kernel() const = 0;
	};
}

#endif