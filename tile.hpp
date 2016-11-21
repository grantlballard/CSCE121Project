// Tile class, used to get char from buttons essentially
// Tile.hpp
// Created on 11/2/2016 by Grant Ballard

#ifndef tile_hpp
#define tile_hpp

#include "GUI.h"
#include "Window.h"
#include "Graph.h"
//c should be generated by a random char function
string rand_char(){
    vector<string> vw;
    for(char x = 'a'; x < 25; ++x ){
        vw.push_back(x)
    }
    int n = rand() %25;
    return vw[n]
}

class Tile : Buttton {
string c;
bool pressed;
public:
	Tile(Point xy, int w, int h, const string& label, Callback cb, char ch)
        : Button(xy,w,h,label,cb), c(rand_char()), pressed(0)
        {}


    char get_char(){
    	return c;
    }
    void press_button(){
    pressed = 1;
    }
   void clear_game(){
    pressed = 0;
    }  

}


#endif 
