#include "Bullet.h"



Bullet::Bullet(Texture* texture, float movement_speed, Vector2f position)
{
	this->bulletTexture = texture;
	this->bulletSprite.setTexture(*this->bulletTexture);
	this->position = position;
	this->bulletSprite.setPosition(this->position.x + 45, this->position.y);
	this->bulletSprite.setScale(0.05f, 0.05f);
	this->movementSpeed = movement_speed;
}

//Accessor
const FloatRect Bullet::getGlobalBounds() const
{
	return this->bulletSprite.getGlobalBounds();
}

Bullet::~Bullet()
{

}


void Bullet::update(float deltaTime)
{
	//update bullet
	this->bulletSprite.move(0, deltaTime * -this->movementSpeed);
}

void Bullet::render(RenderTarget& target)
{
	target.draw(this->bulletSprite);
}
