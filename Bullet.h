#pragma once
#ifndef BULLET_H
#define BULLET_H
#define _USE_MATH_DEFINES
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;

class Bullet
{
private:

	Sprite bulletSprite;
	Texture* bulletTexture;

	Vector2f direction;
	float movementSpeed;
	Vector2f position;


public:
	Bullet(Texture *texture, float movement_speed,Vector2f position);
	virtual ~Bullet();

	//Accessor
	const FloatRect getGlobalBounds() const;

	void update(float deltaTime);
	void render(RenderTarget& target);
};

#endif // !BULLET_H