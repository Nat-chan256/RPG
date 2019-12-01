#include "Layer.hpp"

// Временный конструктор для тестов
Layer::Layer()
{
	m_matrix =
	{
		{0, 1, 1, 2, 0, 1, 1, 0},
		{0, 0, 1, 0, 2, 2, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1}
	};
}

TileId Layer::getTile(sf::Vector2i position) const
{
	return getTile(position.x, position.y);
}

TileId Layer::getTile(size_t x, size_t y) const
{
	// Использую at для того, чтобы генерировались исключения
	return m_matrix.at(y).at(x);
}

void Layer::setTile(sf::Vector2i position, TileId newTile)
{
	setTile(position.x, position.y, newTile);
}

void Layer::setTile(size_t x, size_t y, TileId newTile)
{
	m_matrix.at(y).at(x) = newTile;
}

void Layer::bindTextures(std::shared_ptr<TexturesMenager> menager)
{
	m_textures = menager;
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite;
	sf::Vector2f position;

	for (const auto i : m_matrix)
	{
		for (const auto j : i)
		{
			if (j != Tile::Empty)
			{
				sprite.setTexture(m_textures->get(j));
				sprite.setPosition(position);
				target.draw(sprite);
			}

			position.x += 32;
		}

		position.y += 32;
		position.x = 0;
	}
}
