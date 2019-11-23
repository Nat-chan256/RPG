#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Layer
{
private:
	std::vector<std::vector<int>> tile_map;
	std::vector<sf::Sprite> sprites;

public:
	Layer()
	{}

	std::vector<int> operator [](int);

	void addTile(sf::Texture, float, float, float, float);

	void addTile(sf::Texture, sf::Vector2i, sf::Vector2i);
};
