#pragma once

#include <inttypes.h>

using TileId = uint16_t;

class Tile
{
public:
	Tile(/* args */) {}
	~Tile() {}

	static const TileId Empty = 0;
};
