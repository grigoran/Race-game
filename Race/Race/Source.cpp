#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	car mainCar("gamedata/textures/car.png", sf::Color::White, 200, 200, 0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			mainCar.gas(0.4);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			mainCar.gas(-0.4);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			mainCar.turn(-0.3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			mainCar.turn(0.3);
		}

		window.clear(sf::Color::White);
		window.draw(mainCar);
		window.display();
	}

	return 0;
}