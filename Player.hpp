//
//  Player.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp


#include <stdio.h>
#include "std_lib_facilities_4.h"

class Player {
    string name;
    vector<int> scores;
    // variable for player image
    
public:
    Player(string n, int s);
    
    int get_high_score() const;
    
    void add_score(int s);
    
    void set_image(string i);
    
    
};

#endif /* Player_hpp */
