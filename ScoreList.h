#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Score {
public:
    string name;
    int score;
    Score(string name, int score);
};


class ScoreList {
private:

    vector <Score> score_list;
public:
   
    void loadFromFile();
    void saveToFile();
    void addScoreToList(Score player);
    vector <Score> getScoreList();
};
