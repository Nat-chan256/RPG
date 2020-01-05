#ifndef __MAP_HPP
#define __MAP_HPP

#include <vector>

#include <Engine/IntegerTypes.hpp>
#include <Engine/Tile.hpp>
#include <Engine/Layer.hpp>

class Map
{
public:
	Map(); // Крутой тестовый уровень
	~Map();

	const Layer& getLayer(size_t _index) const;
	Layer& editLayer(size_t _index);
	size_t getLayersNumber() const noexcept;

protected:
	std::vector<Layer> m_layers;
};

#endif /* __MAP_HPP */
