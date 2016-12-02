//
//  Player.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Player_h
#define Player_h


#include <stdio.h>
#include "std_lib_facilities_4.h"
//#include <ifstream>

class Player {
    string name;
    vector<int> scores;
    
public:
    Player(string name, vector<int> score);

    Player(string name);

    string getName()const {return name;}

    vector<int> getScoresVector()const {return scores;}

    string printScores() const;
    
    int getHighScore() const;
    
    void addScore(int s) {scores.push_back(s);}

    virtual char getIdentifier() const {return 'P';}

    virtual void print(ofstream& ofs);

    virtual string getImage() const {return "";}
    
    virtual ~Player() {};
     
};

bool operator == (const Player& a, const Player& b);
ostream& operator<<(ostream& os, Player p);



//there is a player whose is already going to be a part of the Player_List vector. 
    //they are already going to have 
    //it's going to go through and search for the highest score
    //when it finds the highest score, it's going to save the name and vector of scores
    //of that player and then create a new Player of this derived class

class HighestPlayer: public Player {
    string image;

public: 
    HighestPlayer(string name, vector<int> scores, string image);

    char getIdentifier() const {return 'H';}

    void print(ofstream& ofs);

    string getImage() const {return image;}
};

ostream& operator<<(ostream& os, HighestPlayer h);

/*
Going to have a vector of players and one of them is going to be the highest player
vector<Player*> players
set highest player and delete corresponding player
    loop through and do getHighScore
    if person.getHighScore has person.identifier = 'H', do nothing
    if person.getHighScore ~= person.Identifier 'H', delete(oldhighest player)
        create new highest player
delete highest player and set player
    loop through and find the identifier 'H' create a new Player, delete highest player
find highest player name and score and image title
*/

//to check if the player already exist
bool checkHighest(vector<Player*>& player);
void setHighest(vector<Player*>& player);
void deleteHighest(vector<Player*>& player);
string outputHighest(vector<Player*> player);
void input_data(vector<Player*>& player);
int outputHighestScore(vector<Player*> player);
string outputImage(vector<Player*> player);
void output_data(const vector<Player*>& player);
void newPlayer(string name, vector<Player*>& player);
void newScore(string name, int score, vector<Player*>& player);


#endif /* Player_h */
