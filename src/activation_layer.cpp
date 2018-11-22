#include <anie/activation_layer.hpp>

namespace anie
{
	vector activation_layer::forward(const vector& vector) const
	{
		return function(vector);
	}
}