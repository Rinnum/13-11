#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <iostream>

using namespace sf;

#define ITEM_HEAL 0
#define ITEM_BULLET 1

class Item
{
private:

	Sprite ItemSprite;

public:

	int type;
	

	Item(float pos_x, float pos_y, Texture* texture, int type);

	//Accessor
	inline Vector2f getPos()
	{
		return this->ItemSprite.getPosition();
	}
	inline FloatRect getGlobalBounds() const { return this->ItemSprite.getGlobalBounds(); }

	//Function

	void update();
	void render(RenderTarget* target);

};


