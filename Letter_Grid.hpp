//
//  Letter_Grid.hpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Letter_Grid_hpp
#define Letter_Grid_hpp

#include <stdio.h>
#include "Letter_Tile.hpp"

class Letter_Grid {
    Vector_ref<Letter_Tile> tiles;      // container to hold letter_tiles
    int grid_size = 3;                  // default grid size
    
public:
    
    Letter_Grid(int size);              // Constructor with parameter size to set grid_size
    
    void reset_grid();                  // resets the grid to untoggle boxes when the reset button pressed
    
    void attach_tiles(Window& win);     // attach letter_tiles to the window
    
    
    
};

#endif /* Letter_Grid_hpp */
