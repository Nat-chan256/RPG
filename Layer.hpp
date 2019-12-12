#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "ResourcesMenager.hpp"

class Layer : virtual public sf::Drawable
{
public:
	Layer(); // Тут задается единственный вариант слоя на данный момент. Потом добавлю загрузку с файлика
	~Layer() = default;

	TileId getTile(sf::Vector2i position_) const noexcept;
	TileId getTile(size_t x_, size_t y_) const noexcept;

	void setTile(sf::Vector2i position_, TileId newTile_);
	void setTile(size_t x_, size_t y_, TileId newTile_);

	void bindTiles(std::shared_ptr<TilesMenager> menager_) noexcept;

	void draw(sf::RenderTarget& target_, sf::RenderStates states_) const;

private:
	std::vector<std::vector<TileId>> m_matrix;
	std::shared_ptr<TilesMenager> m_tilesMenager;
};
