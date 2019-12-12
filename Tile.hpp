#pragma once

#include <inttypes.h>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

using TileId = uint16_t;

class Tile
{
public:
	Tile(TileId id_, std::weak_ptr<sf::Texture> texture_) :
		m_id(id_),
		m_texture(texture_) {}

	~Tile() = default;

	TileId getId() const noexcept;
	std::weak_ptr<sf::Texture> getTexture() const noexcept;

	static const TileId Empty = 0;

private:
	TileId m_id;
	std::weak_ptr<sf::Texture> m_texture;
};
