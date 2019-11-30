#include "Tile.h"

Tile::Tile(TileId new_id, std::shared_ptr<sf::Sprite> new_s)
{
	id = new_id;
	sprite = new_s;
}

Tile::~Tile()
{
	sprite.reset();
	id = Empty;
}

void Tile::setTile(TileId new_id, std::shared_ptr<sf::Sprite> s_ptr)
{
	id = new_id;
	sprite = s_ptr;
}

TileId Tile::getId()
{
	return id;
}

std::shared_ptr<sf::Sprite> Tile::getSprite()
{
	return sprite;
}


