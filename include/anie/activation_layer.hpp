#ifndef ANIE_HEADER_ACTIVATION_LAYER_HPP
#define ANIE_HEADER_ACTIVATION_LAYER_HPP
#include <anie/config.hpp>

#include <anie/layer.hpp>
#include <anie/math/vector.hpp>

namespace anie
{
	class ANIE_EXPORT activation_layer : public layer
	{
	public:
		activation_layer(const activation_layer& layer) = delete;
		activation_layer(activation_layer&& layer) = delete;
		virtual ~activation_layer() override = default;

	protected:
		activation_layer() noexcept = default;

	public:
		activation_layer& operator=(const activation_layer& layer) = delete;
		activation_layer& operator=(activation_layer&& layer) = delete;
		bool operator==(const activation_layer& layer) = delete;
		bool operator!=(const activation_layer& layer) = delete;

	public:
		virtual vector forward(const vector& vector) const override;

	protected:
		virtual vector function(const vector& vector) const = 0;
	};
}

#endif