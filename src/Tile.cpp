#include <Engine/Tile.hpp>

TileId Tile::getId() const noexcept
{
	return m_id;
}

std::weak_ptr<sf::Texture> Tile::getTexture() const noexcept
{
	return m_texture;
}

const sf::IntRect& Tile::getTextureRect() const noexcept
{
	return m_textureRect;
}
