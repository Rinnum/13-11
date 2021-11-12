#include "Entry.h"


Entry::Entry()
{
	
}
string Entry:: getName()
{
	return this->str;
}
void Entry::setName(string name)
{
	this->str = name;
}
void Entry::setup(Vector2f Position, Vector2f Size, Font* font,ScoreList* score_list)
{
	this->font = font;
	this->Keynew = false;
	this->delay = -1;
	this->GameEnd = false;
	this->score_list = score_list;

	text.setFont(*font);
	text.setPosition(830, 500);
	text.setCharacterSize(200);
	text.setFillColor(Color::Black);
	charlimit = 10;
	isActive = false;
	isSelect = false;
	haslimit = false;

}

void Entry::setFontSize(int size)
{
	text.setCharacterSize(size);
}

void Entry::setCharLimit(int limit)
{
	charlimit = limit;
}


void Entry::update(Event ev)
{
	if (ev.type != Event::TextEntered || !isActive || !isSelect || (haslimit && str.length() >= charlimit && ev.text.unicode != 8))
	{
		return;
	}
	switch (ev.text.unicode)
	{
	case 8: //ปุ่มลบ
		if (str.length() > 0)
		{
			str = str.substr(0, str.length() - 1); //ลบ
		}
		break;
	default:
		str += (char)ev.text.unicode; //พิมพ์ลงไป
		break;
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter) && !Keynew) 
	{
		this->Keynew = true;
	}
}
void Entry::setgameEnd(bool isGameEnd)
{
	this->GameEnd = isGameEnd;
}

bool Entry:: isGameEnd()
{
	return this->GameEnd;
}

string Entry::getString()
{
	return str;
}

void Entry::render(RenderWindow& window)
{
	window.draw(text);

	if (!Keyboard::isKeyPressed(Keyboard::Enter) && Keynew)
	{

		this->Keynew = false;
		this->GameEnd = true;

		return;
	}

	if (!isActive)
	{
		return;
	}
	
	if (isSelect)
	{
		this->text.setString(str + "_");
	}
	else
	{
		this->text.setString(str);
	}

}
