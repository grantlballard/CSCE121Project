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

class Player {
    string name;
    vector<int> scores;
    string image;
    
public:
    Player(string name, int score, string image);

    Player(string name, string image);

    string getName()const {return name;}

    vector<int> getScoresVector()const {return scores;}

    string getScores() const;
    
    int getHighScore() const;
    
    void addScore(int s){scores.push_back(s);}

    string getImage() const {return image;}
    
    //void set_image(string i);
    
    
};

bool operator == (const Player& a, const Player& b);
ostream& operator<<(ostream& os, Player p);

#endif /* Player_hpp */
