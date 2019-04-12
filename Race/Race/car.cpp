#include "car.h"

car::car(const char* tex, sf::Color color, float _xPos, float _yPos, float _tilt):
	xPos(_xPos),
	yPos(_yPos),
	tilt(_tilt),
	speed(0)
{
	sf::Texture texture;
	texture.loadFromFile(tex);
	sprite.setTexture(texture);
	//sprite.setColor(color);
}


void car::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite);
}