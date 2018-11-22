#ifndef ANIE_HEADER_LAYER_HPP
#define ANIE_HEADER_LAYER_HPP
#include <anie/config.hpp>

#include <anie/math/vector.hpp>

#include <memory>

namespace anie
{
	class ANIE_EXPORT layer
	{
	public:
		layer(const layer& layer) = delete;
		layer(layer&& layer) = delete;
		virtual ~layer() = default;

	protected:
		layer() noexcept = default;

	public:
		layer& operator=(const layer& layer) = delete;
		layer& operator=(layer&& layer) = delete;
		bool operator==(const layer& layer) = delete;
		bool operator!=(const layer& layer) = delete;

	public:
		virtual vector forward(const vector& vector) const = 0;
	};

	using layer_ptr = std::shared_ptr<layer>;
}

#endif