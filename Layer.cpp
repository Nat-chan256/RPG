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

TileId Layer::getTile(sf::Vector2i position_) const noexcept
{
	return getTile(position_.x, position_.y);
}

TileId Layer::getTile(size_t x_, size_t y_) const noexcept
{
	// Использую at для того, чтобы генерировались исключения
	return m_matrix.at(y_).at(x_);
}

void Layer::setTile(sf::Vector2i position_, TileId newTile_)
{
	setTile(position_.x, position_.y, newTile_);
}

void Layer::setTile(size_t x_, size_t y_, TileId newTile_)
{
	m_matrix.at(y_).at(x_) = newTile_;
}

void Layer::bindTiles(std::shared_ptr<TilesMenager> menager_) noexcept
{
	m_tilesMenager = menager_;
}

void Layer::draw(sf::RenderTarget& target_, sf::RenderStates states_) const
{
	sf::Sprite sprite;
	sf::Vector2f position;

	for (const auto i : m_matrix)
	{
		for (const auto j : i)
		{
			if (j != Tile::Empty)
			{
				const Tile& tile = m_tilesMenager->get(j);
				const auto texturePtr = tile.getTexture().lock();

				sprite.setTexture(*texturePtr);
				sprite.setPosition(position);
				target_.draw(sprite);
			}

			position.x += 32;
		}

		position.y += 32;
		position.x = 0;
	}
}
