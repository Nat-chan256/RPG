#include "Tile.hpp"

Tile::Tile(TileId new_id, std::shared_ptr<sf::Texture> new_t)
{
	id = new_id;
	texture = new_t;
}

void Tile::setTile(TileId new_id, std::shared_ptr<sf::Texture> t_ptr)
{
	id = new_id;
	texture = t_ptr;
}

TileId Tile::getId() const
{
	return id;
}

std::shared_ptr<sf::Texture> Tile::getTexture() const
{
	return texture;
}
