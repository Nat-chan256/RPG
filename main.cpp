#include <iostream>

#include <SFML/Graphics.hpp>

#include "Layer.hpp"

/*
	Небольшой тест на утечки памяти в менеджере ресурсов.
*/

int main(int argc, char const *argv[])
{
	sf::Image i1;
	i1.create(32, 32, sf::Color::Cyan);
	sf::Image i2;
	i2.create(32, 32, sf::Color::Red);

	auto t1 = std::make_shared<sf::Texture>();
	t1->loadFromImage(i1, sf::IntRect(0, 0, 32, 32));
	auto t2 = std::make_shared<sf::Texture>();
	t2->loadFromImage(i2, sf::IntRect(0, 0, 32, 32));

	Layer layer;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Memory test");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		auto texturesMenager = std::make_shared<TexturesMenager>();
		texturesMenager->add(t1);
		texturesMenager->add(t2);

		auto tilesMenager = std::make_shared<TilesMenager>();
		tilesMenager->add(std::make_shared<Tile>(1, texturesMenager->give(1)));
		tilesMenager->add(std::make_shared<Tile>(2, texturesMenager->give(2)));
		layer.bindTiles(tilesMenager);

		window.clear(sf::Color::White);
		window.draw(layer);
		window.display();
	}
	return 0;
}
