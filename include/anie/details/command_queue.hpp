#ifndef ANIE_HEADER_DETAILS_COMMAND_QUEUE_HPP
#define ANIE_HEADER_DETAILS_COMMAND_QUEUE_HPP

#include <utility>

namespace anie
{
	template<typename ...Args_>
	command_queue_ptr make_command_queue(Args_&&... args)
	{
		return std::make_shared<command_queue>(std::forward<Args_>(args)...);
	}
}

#endif