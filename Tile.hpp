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

	Tile(TileId, std::shared_ptr<sf::Texture>);

	void setTile(TileId, std::shared_ptr<sf::Texture>);

	TileId getId();

	std::shared_ptr<sf::Texturee> getTexture();

	~Tile();

	static const TileId Empty = 0;

private:
	TileId id;
	std::shared_ptr<sf::Texture> texture;
};

#endif 
