#progma once

#include <inttypes.h>
#include <memory>
#include <SFML/Graphics.hpp>

using TileId = uint16_t;

class Tile
{
public:

	Tile() = default;
	~Tile();

	Tile(TileId, std::shared_ptr<sf::Texture>);

	void setTile(TileId, std::shared_ptr<sf::Texture>);

	TileId getId() const;

	std::shared_ptr<sf::Texturee> getTexture() const;

	static const TileId Empty = 0;

private:
	TileId id;
	std::shared_ptr<sf::Texture> texture;
};

