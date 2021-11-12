#pragma once
#include<iostream>
#include<vector>
#include <string>
#include"Player.h"
#include"Enemy.h"
#include "Bullet.h"
#include"Scene.h"
#include"Item.h"
#include"Entry.h"
#include<ctime>
#include"ScoreList.h"


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
/*
	Class that acts the game engine
*/

class Game : public Scene
{
private:
	//Window
	RenderWindow* window;
	Texture bgTexture;
	Sprite bgSprite;
	Event ev;

	ScoreList* score_list;

	Entry entry;
	Texture frameTexture;
	Sprite frameSprite;
	Font font;

	//Hp
	Text HpText;

	bool isPause;
	bool KeyPause;

	int score = 0;
	Text ScoreText;
	

	bool Showgameover;
	Text GameOverText;

	bool Showgamewon;
	Text GameWonText;

	bool Pausegame;
	Text PauseText;

	int total;


	//Bullet
	vector<Bullet> bullets;

	//Player
	Texture playerTexture;
	vector<Player> player;

	//Enemies
	float spawmTimer;
	float spawmTimerMax;
	int maxEnemies;


	vector<Enemy> enemies;
	Texture enemyTexture; 
	Texture bossTexture;
	Texture bulletTexture;

	float spawmITimer;
	float spawmITimerMax;
	
	vector<Item> items;
	Texture ItemTexture;
	Texture bTexture;
	

	int level;
	int count;
	int countItem;
	int maxItem;



	//Private function
	void initVariables();
	void initWindow();

	void initPlayer();
	void initEnemies();
	void initItem();

public:
	//Constructor/Destructors
	Game(ScoreList* score_list);
	virtual ~Game();
	inline void setWindow(RenderWindow* window) { this->window = window; }

	//Accessors
	const bool running() const;


	//Function 
	void update(float deltaTime);
	int randomIntRange(int a, int b);
	void ResetGame();
	void GameOver();
	void updateItem(int playerIndex);
	void Won();
	void pollEvents();
	void updateEnemies(int playerIndex);
	void updateCombat(int playerIndex, float deltaTime);
	void levelUp();
	
	void render();
};
