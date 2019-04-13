#pragma once
#include <SFML/Graphics.hpp>

class car : public sf::Drawable {
public:
	car(const char* _tex,sf::Color color, float _xPos, float _yPos,  float _tilt);
	void gas(float vel,sf::Time deltatime);
	void brake(float vel);
	void turn(float vel);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float xPos;
	float yPos;
	float tilt;
	float speed;
	const float maxSpeed;
	const float brakes;
	const float inert;
};