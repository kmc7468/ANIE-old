#ifndef ANIE_HEADER_NETWORK_HPP
#define ANIE_HEADER_NETWORK_HPP
#include <anie/config.hpp>

#include <anie/layer.hpp>
#include <anie/math/vector.hpp>

#include <vector>

namespace anie
{
	class ANIE_EXPORT network final
	{
	public:
		network() = default;
		network(const network& network) = delete;
		network(network&& network) = delete;
		~network() = default;

	public:
		network& operator=(const network& network) = delete;
		network& operator=(network&& network) = delete;
		bool operator==(const network& network) = delete;
		bool operator!=(const network& network) = delete;
		network& operator<<(const layer_ptr& layer);
		network& operator<<(layer_ptr&& layer);

	public:
		vector compute(const vector& input) const;

	private:
		std::vector<layer_ptr> layers_;
	};
}

#endif