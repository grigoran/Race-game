#include "car.h"
#include <iostream>

car::car(const char* tex, sf::Color color, float _xPos, float _yPos, float _tilt):
	xPos(_xPos),
	yPos(_yPos),
	tilt(_tilt),
	speed(0),
	maxSpeed(400)
{
	texture.loadFromFile(tex);
	sprite.setTexture(texture);
	sprite.setPosition(xPos, yPos);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(0.03f, 0.03f);
	sprite.setColor(color);
}


void car::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}

void car::gas(float vel,sf::Time deltatime) {
	std::cout <<"speed "<<fabs(speed) / speed << " vel "<<fabs(vel)/vel<<std::endl;
	if(fabs(speed)<maxSpeed||(fabs(speed)/speed)!=(fabs(vel)/vel)) speed += vel*deltatime.asSeconds();
	if (vel == 0) {
		speed -= speed * deltatime.asSeconds();
	}
	float rad = ((sprite.getRotation() * 3.14) / 180);
	float xSpeed = cos(rad) * speed * deltatime.asSeconds();
	float ySpeed = sin(rad)*speed*deltatime.asSeconds();
	sprite.move(xSpeed, ySpeed);
}

void car::turn(float vel) {
	sprite.rotate(vel*speed /maxSpeed);
}