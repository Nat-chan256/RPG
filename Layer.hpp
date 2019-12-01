#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "ResourcesMenager.hpp"

class Layer : public sf::Drawable
{
public:
	Layer(); // Тут задается единственный вариант слоя на данный момент. Потом добавлю загрузку с файлика
	~Layer() = default;

	TileId getTile(sf::Vector2i position) const;
	TileId getTile(size_t x, size_t y) const;

	void setTile(sf::Vector2i position, TileId newTile);
	void setTile(size_t x, size_t y, TileId newTile);

	void bindTextures(std::shared_ptr<TexturesMenager> menager);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<std::vector<TileId>> m_matrix;
	std::shared_ptr<TexturesMenager> m_textures;
};
