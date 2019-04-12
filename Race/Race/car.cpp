#include "car.h"
#include <iostream>

car::car(const char* tex, sf::Color color, float _xPos, float _yPos, float _tilt):
	xPos(_xPos),
	yPos(_yPos),
	tilt(_tilt),
	speed(0)
{
	texture.loadFromFile(tex);
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(0.05f, 0.05f);
	sprite.setColor(color);
}


void car::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void car::gas(float vel) {
	float rad = ((sprite.getRotation() * 3.14) / 180);
	float xSpeed = cos(rad)*vel;
	float ySpeed = sin(rad)*vel;
	sprite.move(xSpeed, ySpeed);
}

void car::turn(float vel) {
	sprite.rotate(vel);
}