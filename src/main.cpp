#include <Engine/Map.hpp>

/*
	Небольшой редактор карт для теста. Потом будет все в json пихать.
*/

int main(int argc, char const *argv[])
{
	auto menager = std::make_shared<ResourcesMenager<Tile>>();
	Layer layer;
	layer.loadTestLayer({{1, 2, 3}, {3, 2, 1}, {2, 3, 1}});
	layer.bindTilesData(menager);

	sf::RenderWindow window(sf::VideoMode(340, 340), "DrawNya");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
