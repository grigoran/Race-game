#include <SFML/Graphics.hpp>
#include <iostream>
#include "car.h"

int main()
{
	sf::Clock clock;
	sf::Time deltaTime;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	//window.setFramerateLimit(120);
	car mainCar("gamedata/textures/car.png", sf::Color::White, 200, 200, 0);
	bool mainMooved = 0;
	const float tiltSpeed=250;
	const float speed = 250;

	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime();
		clock.restart();
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
		mainMooved = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			mainCar.gas(speed,deltaTime);
			mainMooved = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			mainCar.gas(-speed,deltaTime);
			mainMooved = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			mainCar.turn(-tiltSpeed*deltaTime.asSeconds());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			mainCar.turn(tiltSpeed*deltaTime.asSeconds());
		}
		if(!mainMooved) mainCar.gas(0,deltaTime);

		window.clear(sf::Color::White);
		window.draw(mainCar);
		window.display();

	}

	return 0;
}