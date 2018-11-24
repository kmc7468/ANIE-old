#ifndef ANIE_HEADER_ACTIVATION_LAYERS_SIGMOID_HPP
#define ANIE_HEADER_ACTIVATION_LAYERS_SIGMOID_HPP
#include <anie/config.hpp>

#include <anie/activation_layer.hpp>
#include <anie/math/vector.hpp>

#include <memory>

namespace anie
{
	class ANIE_EXPORT sigmoid_layer final : public activation_layer
	{
	public:
		sigmoid_layer() noexcept = default;
		sigmoid_layer(const sigmoid_layer& layer) = delete;
		sigmoid_layer(sigmoid_layer&& layer) = delete;
		virtual ~sigmoid_layer() override = default;

	public:
		sigmoid_layer& operator=(const sigmoid_layer& layer) = delete;
		sigmoid_layer& operator=(sigmoid_layer&& layer) = delete;
		bool operator==(const sigmoid_layer& layer) = delete;
		bool operator!=(const sigmoid_layer& layer) = delete;

	protected:
		virtual arithemtic_type function(const arithemtic_type& x) const override;
	};

	static inline const layer_ptr sigmoid = std::make_shared<sigmoid_layer>();
}

#endif