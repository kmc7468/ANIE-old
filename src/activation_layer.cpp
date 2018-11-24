#include <anie/activation_layer.hpp>

#include <algorithm>

namespace anie
{
	vector activation_layer::forward(const vector& vector) const
	{
		anie::vector result = vector;
		std::transform(result.begin(), result.end(), result.begin(), [this](arithemtic_type x)
		{
			return function(x);
		}); // TODO

		return result;
	}
}