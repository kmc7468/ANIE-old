#include <anie/activation_layers/sigmoid.hpp>

#include <cmath>

namespace anie
{
	arithemtic_type sigmoid_layer::function(const arithemtic_type& x) const
	{
		return arithemtic_type(1) / (arithemtic_type(1) + std::exp(-x));
	}
}