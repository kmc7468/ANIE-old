#include <anie/activation_layers/sigmoid.hpp>

#include <algorithm>
#include <cmath>

namespace anie
{
	vector sigmoid_layer::function(const vector& vector) const
	{
		anie::vector result = vector;
		std::transform(result.begin(), result.end(), result.begin(), [](const arithemtic_type& x)
		{
			return arithemtic_type(1) / (arithemtic_type(1) + std::exp(-x));
		});

		return result;
	}
}