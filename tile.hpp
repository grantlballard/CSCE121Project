// Tile class, used to get char from buttons essentially
// Tile.hpp
// Created on 11/2/2016 by Grant Ballard

#ifndef tile_hpp
#define tile_hpp

#include "GUI.h"
#include "Window.h"
#include "Graph.h"

class Tile : Buttton {
char c;

public:
	Tile(Point xy, int w, int h, const string& label, Callback cb)
        : Button(xy,w,h,label,cb), c(GenerateRandomChar())
        {}

    void attach(Window&);

    char get_char(){
    	return c;
    }

}


