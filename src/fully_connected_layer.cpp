#include <anie/fully_connected_layer.hpp>

#include <anie/devices/cpu_seq.hpp>

#include <any>
#include <random>

namespace anie
{
	fully_connected_layer::fully_connected_layer(std::size_t input, std::size_t unit)
		: weights_(unit), bias_(unit)
	{
		for (vector& weights : weights_)
		{
			weights = vector(input);
		}

		clear();
	}

	void fully_connected_layer::clear() noexcept
	{
		std::random_device seed_gen;
		std::mt19937_64 rand(seed_gen());
		std::uniform_real_distribution<arithemtic_type> dist(-1, 1);

		for (vector& weights : weights_)
		{
			for (arithemtic_type& weight : weights)
			{
				weight = dist(rand);
			}
		}

		for (arithemtic_type& bias : bias_)
		{
			bias = dist(rand);
		}
	}

	vector fully_connected_layer::forward(const vector& vector) const
	{
		anie::vector result(bias_.size());

		for (std::size_t i = 0; i < result.size(); ++i)
		{
			result[i] = std::any_cast<arithemtic_type>(cpu_seq->enqueue(weights_[i] * vector).get()) + bias_[i]; // TODO
		}

		return result;
	}

	layer_ptr fc(std::size_t input, std::size_t unit)
	{
		return std::make_shared<fully_connected_layer>(input, unit);
	}
}