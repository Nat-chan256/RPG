#ifndef TILE_H
#define TILE_H

#include <inttypes.h>
#include <memory>
#include <SFML\Graphics.hpp>

using TileId = uint16_t;

class Tile
{
public:

	Tile() = default;

	Tile(TileId, std::shared_ptr<sf::Sprite>);

	void setTile(TileId, std::shared_ptr<sf::Sprite>);

	TileId getId();

	std::shared_ptr<sf::Sprite> getSprite();

	~Tile();

	static const TileId Empty = 0;

private:
	TileId id;
	std::shared_ptr<sf::Sprite> sprite;
};

#endif 