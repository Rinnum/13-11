#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include"Scene.h"
#include"ScoreList.h"

using namespace sf;
using namespace std;

class Entry
{
private:
	RenderWindow* window;

	RectangleShape frame;
	Texture frameTexture;
	Sprite frameSprite;

	Text text;
	Font* font;
	string str;
	size_t charlimit;
	ScoreList* score_list;


public:
	bool isActive; //การแสดงผลบนจอ
	bool isSelect; //โดนเลือก
	bool haslimit; //เช็คจำกัดตัวอักษร
	bool Keynew;
	bool GameEnd;
	
	int delay;

	Entry();
	string getName();
	void setName(string name);
	void setgameEnd(bool isGameEnd);
	bool isGameEnd();
	void setup(Vector2f Position, Vector2f Size, Font* font, ScoreList* score_list); //set ตัวแปร
	void setFontSize(int size);
	void setCharLimit(int limit);
	void update(Event ev);
	string getString();
	void render(RenderWindow& window);

};

