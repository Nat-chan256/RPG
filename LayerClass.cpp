#include "LayerClass.h"
#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>

std::vector<int> Layer::operator [](int index)
{
	return tile_map[index];
}

void Layer::addTile(sf::Texture t, float x, float y, float w, float h)
{
	sf::Sprite s;
	s.setTexture(t);
	sf::IntRect rect(x, y, w, h);
	s.setTextureRect(rect);

	sprites.push_back(s);
}

void Layer::addTile(sf::Texture t, sf::Vector2i v1, sf::Vector2i v2)
{

	sf::Sprite s;
	s.setTexture(t);
	sf::IntRect rect(v1, v2);
	s.setTextureRect(rect);

	sprites.push_back(s);
}

void main()
{}