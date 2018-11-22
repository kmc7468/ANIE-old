#ifndef ANIE_HEADER_FULLY_CONNECTED_LAYER_HPP
#define ANIE_HEADER_FULLY_CONNECTED_LAYER_HPP
#include <anie/config.hpp>

#include <anie/layer.hpp>
#include <anie/math/vector.hpp>

#include <cstddef>
#include <vector>

namespace anie
{
	class ANIE_EXPORT fully_connected_layer final : public layer
	{
	public:
		fully_connected_layer(std::size_t input, std::size_t unit);
		fully_connected_layer(const fully_connected_layer& layer) = delete;
		fully_connected_layer(fully_connected_layer&& layer) = delete;
		virtual ~fully_connected_layer() override = default;

	public:
		fully_connected_layer& operator=(const fully_connected_layer& layer) = delete;
		fully_connected_layer& operator=(fully_connected_layer&& layer) = delete;
		bool operator==(const fully_connected_layer& layer) = delete;
		bool operator!=(const fully_connected_layer& layer) = delete;

	public:
		void clear() noexcept;

		virtual vector forward(const vector& vector) const override;

	private:
		std::vector<vector> weights_;
		vector bias_;
	};

	layer_ptr fc(std::size_t input, std::size_t unit);
}

#endif