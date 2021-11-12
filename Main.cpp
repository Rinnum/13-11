#include <iostream>
#include "Game.h"
#include"Player.h"
#include"Menu.h"
#include<time.h>
#include"ScoreList.h"

int sceneIndex = 0;

int main()
{
    ScoreList score_list;
    score_list.loadFromFile();
    RenderWindow window(VideoMode(1920,1080), "Don't Touch My Town", Style::Titlebar | Style::Close);
    window.setFramerateLimit(144);
   
    //Init srand
    std::cout << "Hello im running" << std::endl;
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game Engine

     Game game(&score_list);
     game.setWindow(&window);
     Menu menu(1920, 1080, &score_list);
     menu.setWindow(&window);
     

     //เชื่อมเข้าด้วยกันใช้scene
     vector <Scene*> scenes;
     scenes.push_back(&menu);
     scenes.push_back(&game);


     float deltaTime;
     Clock clock;
    //Game loop
     while (game.running())
     {
         deltaTime = clock.restart().asSeconds();
         //Update
         scenes[sceneIndex]->update(deltaTime);
         //Render
         scenes[sceneIndex]->render();
         //menu.render();

     }
     //End of application
     score_list.saveToFile();
    return 0;
}