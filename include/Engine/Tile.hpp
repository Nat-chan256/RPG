#ifndef __TILE_HPP
#define __TILE_HPP

#include <memory>

#include <SFML/Graphics/Texture.hpp>

#include <Engine/IntegerTypes.hpp>

class Tile
{
public:
	Tile(TileId _id, std::weak_ptr<sf::Texture> _texture, sf::IntRect _textureRect = sf::IntRect(0, 0, 0, 0)) :
		m_id(_id),
		m_texture(_texture),
		m_textureRect(_textureRect) { };

	~Tile() = default;

	TileId getId() const noexcept;
	std::weak_ptr<sf::Texture> getTexture() const noexcept;
	const sf::IntRect& getTextureRect() const noexcept;

public:
	static const TileId Empty = 0;

protected:
	sf::IntRect m_textureRect;
	TileId m_id;
	std::weak_ptr<sf::Texture> m_texture;
};

#endif /* __TILE_HPP */
