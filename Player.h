#pragma once
#include "Bullet.h"
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>

using namespace sf;
using namespace std;



class Player
{
private:
	int hp;
	int maxhp;
	
	int damageEnemy;
	int score = 0;
	int point;

	float dualShoot;

	Sprite playerSprite;
	Texture *playerTexture;
	Vector2f velocity;

	Texture *bulletTexture;
	vector<Bullet>bullets;
	float movementSpeed;

	Vector2f PlayerPos;
	Vector2f MousePos;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	float shootTimer;
	float shootTimerMax;


public:

	Player(Texture *texture,Texture *bulletTexture);
	virtual ~Player();
	inline FloatRect getGlobalBounds() const { return this->playerSprite.getGlobalBounds(); }
	//Bullet
	inline vector<Bullet>& getBullets() { return this->bullets; }

	//ค่าตีปีศาจ
	inline int getDamageEnemy() { return this->damageEnemy; }


	//โดนโจมตี
	inline void takeDamage(int damage,int pointattrack)
	{
		hp -= damage;
		point -= pointattrack;
		if (point <= 0)
		{
			point = 0;
		}
	}


	//เก็บไอเทมได้
	inline void getItem(int item)
	{
		hp += item;
	}

	//ส่งhp
	inline int getHp() { return this->hp; }

	//โจมตีได้
	inline void getPoint(int pointkill)
	{
		point += pointkill;
	}



	//ส่งแต้ม
	inline int getPoint() { return this->point; }

	//setHp
	inline void setHp()
	{
		hp = maxhp;
	}

	inline void setDualShoot(float time) { dualShoot = time; }

	//Function
	void shoot();
	void movement(float deltaTime);
	void update(float deltaTime);
	void render(RenderWindow& target);
};

