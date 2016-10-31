//
//  Player_List.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Player_List_hpp
#define Player_List_hpp

#include <stdio.h>
#include "Player.hpp"

class Player_List{
    vector<Player> players;

public:
    Player_List();
    
    void add_player(string name, int score);            // check to see if player exists, if not add new
                                                        // player otherwise add score to existing player
    
    Player get_top_player() const;                      // return player with highest score
    
    
    
};

#endif /* Player_List_hpp */
