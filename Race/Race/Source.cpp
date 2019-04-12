#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	//car mainCar("gamedata/textures/car2.jpg", sf::Color::Blue, 10, 10, 0);
	sf::Texture texture;
	texture.loadFromFile("car.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}