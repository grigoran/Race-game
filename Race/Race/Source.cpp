#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	car mainCar("gamedata/textures/car.png", sf::Color::White, 10, 10, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(mainCar);
		window.display();
	}

	return 0;
}