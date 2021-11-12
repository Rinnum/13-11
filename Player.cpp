#include "Player.h"


Player::Player(Texture* texture, Texture* bulletTexture)
{
	this->maxhp = 100;
	this->hp = maxhp;
	this->point = 0;
	this->damageEnemy = 50;

	this->dualShoot = 0; //กำหนดเวลายิงคู่

	this->playerTexture = texture;
	this->bulletTexture = bulletTexture;
	this->playerSprite.setTexture(*this->playerTexture);
	this->movementSpeed = 1000.f;
	this->playerSprite.setPosition(900.f, 560.f);
	this->playerSprite.setScale(0.1f, 0.1f);

	this->shootTimer = 0;
	this->shootTimerMax = 25.f;
}

Player::~Player()
{

}

void Player::shoot()
{
	//วาดกระสุน

	if (Mouse::isButtonPressed(Mouse::Left) && this->shootTimer < 0)
	{
		if (dualShoot > 0)
		{
			Bullet bullet(this->bulletTexture, 500.f, this->playerSprite.getPosition()-Vector2f(50, 0));
			Bullet bullet2(this->bulletTexture, 500.f, this->playerSprite.getPosition()+Vector2f(50,0));
			this->bullets.push_back(bullet);
			this->bullets.push_back(bullet2);
			this->shootTimer = this->shootTimerMax;
		}
		else 
		{
			//ความเร็วbullet
			Bullet bullet(this->bulletTexture, 500.f, this->playerSprite.getPosition());
			this->bullets.push_back(bullet);
			this->shootTimer = this->shootTimerMax;
		}
	}
	else this->shootTimer--;
}


void Player::movement(float deltaTime)
{
	//Game player
	velocity.y = 0.f;
	velocity.x = 0.f;

	if (dualShoot > 0)
	{
		dualShoot -= deltaTime;
	}
	//Move Player
	if (Keyboard::isKeyPressed(Keyboard::Key::A))
		velocity.x += -movementSpeed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
		velocity.x += movementSpeed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
		velocity.y += -movementSpeed * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
		velocity.y += movementSpeed * deltaTime;
	//Left
	if (this->playerSprite.getPosition().x < 0.f)
		this->playerSprite.setPosition(0.f, playerSprite.getPosition().y);
	//Top
	if (this->playerSprite.getPosition().y < 0.f)
		this->playerSprite.setPosition(playerSprite.getPosition().x, 0.f);
	//Right
	if (this->playerSprite.getPosition().x + playerSprite.getGlobalBounds().width > 1920)
		this->playerSprite.setPosition(1920 - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
	//Bottom
	if (this->playerSprite.getPosition().y + playerSprite.getGlobalBounds().height > 1080)
		this->playerSprite.setPosition(playerSprite.getPosition().x, 1080 - playerSprite.getGlobalBounds().height);
	this->playerSprite.move(velocity);

}


//Function
void Player::update(float deltaTime)
{
	this->movement(deltaTime);
	shoot();
}

void Player::render(RenderWindow& target)
{
	target.draw(this->playerSprite);

	//Draw bullet
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].render(target);

	}
}
