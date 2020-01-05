#ifndef __LAYER_HPP
#define __LAYER_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <Engine/IntegerTypes.hpp>
#include <Engine/Tile.hpp>
#include <Engine/ResourcesMenager.hpp>

// Слой, состоящий из слоев? Было бы полезно для уровней с этажами.

class Layer : public sf::Drawable
{
public:
	Layer() = default;
	~Layer() = default;

	// void loadFromJson(нелохмужик::джейсон);
	void loadTestLayer(const std::vector<std::vector<TileId>>& coolLayer); // то, что тут нет _ мазолит глаз, ня

	TileId getTile(size_t _x, size_t _y) const;
	TileId getTile(sf::Vector2i _position) const;

	void setTile(size_t _x, size_t _y, TileId _id);
	void setTile(sf::Vector2i _position, TileId _id);

	void bindTilesData(std::weak_ptr<ResourcesMenager<Tile>> _ptr);

	sf::Vector2i getSizes() const noexcept;

public:
	void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

private:
	std::vector<std::vector<TileId>> m_matrix;
	std::weak_ptr<ResourcesMenager<Tile>> m_tilesData;
};

#endif /* __LAYER_HPP */
