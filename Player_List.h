//
//  Player_List.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Player_List_h
#define Player_List_h

#include <stdio.h>
#include "Player.h"

class Player_List{
    vector<Player> players;

public:
    
    void addPlayer(Player player);           // check to see if player exists, if not add new
                                                        // player otherwise add score to existing player
    vector<Player> outputVector();

    Player highestPlayer() const;

    //Player get_top_player() const;                      // return player with highest score
    
};

#endif /* Player_List_hpp */
