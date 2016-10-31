//
//  Word_Search.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Word_Search_hpp
#define Word_Search_hpp

#include <stdio.h>
#include "Letter_Grid.hpp"
#include "Player_List.hpp"

class Word_Search {
    Letter_Grid letters;            // creates the letter tiles
    Button reset_button;            // button to reset the pressed tiles
    Player_List all_players;        // holds a list of players
    int player score;               // keep a current score
    int high_score;                 // keep high score
    
public:
    Word_Search();                  // constructor, probably take a file as a parameter
                                    // should create letter_grid, reset_button, display for word, display for score, enter button (to submit a word)
    

};

#endif /* Word_Search_hpp */
