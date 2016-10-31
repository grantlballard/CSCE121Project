//
//  Letter_Tile.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Letter_Tile_hpp
#define Letter_Tile_hpp

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"

class Letter_Tile{
    Button button_unpressed;            // button for the user to press
    Button button_pressed;              // button for the user to press
    string letter;                      // string for the letter to be displayed on the button
    int x_position;                     // x position for where the button will be displayed on the window
    int y_position;                     // y position for where the button will be displayed on the window
    bool pressed = false;
    
public:
    Letter_Tile(string i_letter,int i_x_position, int i_y_position);
    
    Button get_button() const;          // return the button to be displayed on the window
    
    void toggle_button();               // toggle the button from not pressed to pressed
    
    bool is_pressed();                  // return value of the pressed boolean
    
    
    
private:
    void create_button();               // creates Button using x and y posiitions and letter
    
    
    
};

#endif /* Letter_Tile_hpp */
