#include "Menu.h"

Menu::Menu(float width, float height,ScoreList* score_list)
{
	if (!font.loadFromFile("Fonts/Cheeky_Rabbit.ttf"))
		printf("Can't load");


	window = nullptr;

	//Don't Touch My Town
	menu[3].setFont(font);
	menu[3].setFillColor(Color::Blue);
	menu[3].setString("Don't Touch My Town");
	menu[3].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[3].setCharacterSize(100);
	menu[3].setPosition(520, 50);

	//64010997 Arisara Ngamchawiworawet
	menu[4].setFont(font);
	menu[4].setFillColor(Color::White);
	menu[4].setString("64010997 Arisara Ngamchawiworawet");
	menu[4].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[4].setCharacterSize(40);
	menu[4].setPosition(50, 990);
	//Play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setCharacterSize(100);
	menu[0].setPosition(850,300);

	//Score
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("SCORE");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setCharacterSize(100);
	menu[1].setPosition(830,500);

	//EXIT
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString(" EXIT");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setCharacterSize(100);
	menu[2].setPosition(830,650);

	mainMenuSelected = 0;
}

void Menu::update(float deltaTime)
{
	pollEvent();
	this->bgTexture.loadFromFile("character/bgs1.png");
	this->bgSprite.setTexture(bgTexture);

}

Menu::~Menu()
{

}

void Menu::pollEvent()
{
	Event ev;
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::KeyReleased:
			switch (ev.key.code)
			{
			case Keyboard::Up:
				moveUp();
				break;
			case Keyboard::Down:
				moveDown();
				break;
			case Keyboard::Enter:
				select();
				break;
			}
			break;
		case  Event::Closed:
			window->close();
			break;
		}
	}
}


void Menu::render()
{
	this->window->clear();
	this->window->draw(this->bgSprite);

	for (int i = 0; i < 5; i++)
	{
		window->draw(menu[i]);
	}
	this->window->display();
}


void Menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		menu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		menu[mainMenuSelected].setFillColor(Color::Red);

	}
}

void Menu::moveDown()
{

	if (mainMenuSelected + 1 <= Max_menu)
	{
		menu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		menu[mainMenuSelected].setFillColor(Color::Red);
	}
}

void Menu::select()
{
	if (mainMenuSelected == 0)
	{
		sceneIndex = 1;
	}
	else if (mainMenuSelected == 2)
	{
		window->close();
	}
}