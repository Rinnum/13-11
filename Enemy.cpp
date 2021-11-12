#include "Enemy.h"



Enemy::Enemy(float pos_x, float pos_y, Texture* texture, int type)
{
	this->type = type;
	this->enemySprite.setPosition(pos_x, pos_y);
	this->enemySprite.setTexture(*texture);
	this->enemySprite.setScale(0.05f, 0.05f);
	this->hpMax = 1;
	this->hp = this->hpMax;
	this->pointkill = 10;
	this->pointattrack = 10;
	this->damage = 10;
	if (type == 1)
	{
		this->enemySprite.setScale(0.08f, 0.08f);
		this->hpMax = 3;
		this->hp = this->hpMax;
		this->pointkill = 50;
		this->pointattrack = 30;
		this->damage = 30;

	}

}

Enemy::~Enemy()
{

}



//Function

void Enemy::update()
{
	this->enemySprite.move(0.f, 3.5f);
}

void Enemy::render(RenderTarget* target)
{
	target->draw(this->enemySprite);
}

