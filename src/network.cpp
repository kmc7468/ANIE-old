#include <anie/network.hpp>

#include <utility>

namespace anie
{
	network& network::operator<<(const layer_ptr& layer)
	{
		return layers_.push_back(layer), *this;
	}
	network& network::operator<<(layer_ptr&& layer)
	{
		return layers_.push_back(std::move(layer)), *this;
	}

	vector network::compute(const vector& input) const
	{
		vector y = input;
		
		for (const layer_ptr& layer : layers_)
		{
			y = layer->forward(y);
		}

		return y;
	}
}