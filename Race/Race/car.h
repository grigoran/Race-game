#pragma once
#include <SFML/Graphics.hpp>

class car : public sf::Drawable {
public:
	car(const char* _tex,sf::Color color, float _xPos, float _yPos,  float _tilt);
private:
	sf::Sprite sprite;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void gas(float vel);
	void brake(float vel);
	float xPos;
	float yPos;
	float tilt;
	float speed;
};