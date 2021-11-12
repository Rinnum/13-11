#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>

using namespace sf;

class Enemy
{
private:

	//Game logic
	//float enemySpawnTimer;
	//float enemySpawnTimerMax;
	//int maxEnemies;

	int hp;
	int hpMax;
	int damage;
	int pointattrack;
	int pointkill;


	//int level;
	//Game objects
	//enemy
	Sprite enemySprite;



public:
	int type;
	Enemy(float pos_x, float pos_y, Texture* texture, int type);
	virtual ~Enemy();

	//ส่งค่าโดนปีศาจตี
	inline int getDamage() { return this->damage, this->pointattrack;}

	//แต้มที่ฆ่าได้
	inline int takePoint() { return this->pointkill; }

	//โดนคนตี
	inline bool IsDead() { return this->hp <= 0; }

	//ค่าตีปีศาจ
	inline void takeDamageEnemy(int damageEnemy)
	{
		hp -= damageEnemy; //เลือดลด
	}

	

	//Accessor
	inline Vector2f getPos()
	{
		return this->enemySprite.getPosition();
	}
	inline FloatRect getGlobalBounds() const {return this->enemySprite.getGlobalBounds();}

	//Function

	void update();
	void render(RenderTarget* target);

};


#endif //ENEMY_H