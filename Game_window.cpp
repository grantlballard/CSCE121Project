//
//  Game_window.cpp
//  CSCE121_Project_current
//
//  Created by Ryan Leitner on 11/2/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include "Game_window.hpp"


Game_window::Game_window(Point xy, int w, int h, const string& title, int grid_sz) : Window(xy, w, h, title),

    enter_button(Point(400,240),50, 20, "ENTER", cb_enter),

    clear_button(Point(400,270),50, 20, "CLEAR", cb_clear),

    quit_button(Point(400,300), 50, 20, "QUIT", cb_quit),

    word_display(Point(100,300), 100, 20, "Word:"),

    highscore_display(Point(500, 20), 50, 20, "High score:"),

    current_display(Point(500, 50), 50, 20, "Score"){
    
    // create the grid
        int x = 30;
        int y = 10;
        for (int i =0;i<5;i++){
            for (int j = 0;j<5;j++){
                tiles.push_back(new Button(Point(x,y),50,50,"A",cb_tile));
                attach(tiles[tiles.size()-1]);
                y+=60;
            }
            x+=60;
            y=10;
        }
    // attach the grid
        attach(enter_button);
        attach(clear_button);
        attach(quit_button);
        attach(word_display);
        attach(highscore_display);
        attach(current_display);
        current_display.put("0");
        word_display.put("Enter Letters");
    
    
    
}

//----------------------------------------------
// function to create the letter tiles for the game
void Game_window::create_tiles(int size){
    //creates the letter grid
}

//----------------------------------------------

//clears the Word display out_box when clear button is pressed
void Game_window::clear_button_pressed(){
    current_word = "";
    word_display.put(current_word);
    
}

//----------------------------------------------

// checks the word against the dictionary, updates score, clears word display,
//untoggle the letter tiles
void Game_window::enter_button_pressed(){
    // check dictionary to see if word is actually a word
    {// if it is a word
        current_score++;                // update the score
        current_display.put(to_string(current_score)); // update the current score display
    }
    current_word = "";                  // reset the current word
    
    word_display.put(current_word);
    
}
//----------------------------------------------

//what to do when a tile is pressed
void Game_window::tile_pressed(){
    current_word += "A";
    word_display.put(current_word);
}



//----------------------------------------------

//callback for when the enter button is pressed
void Game_window::cb_enter(Address, Address pw){
    reference_to<Game_window>(pw).enter_button_pressed();
}

//----------------------------------------------

//callback for when the clear button is pressed
void Game_window::cb_clear(Address, Address pw){
    reference_to<Game_window>(pw).clear_button_pressed();
}

//----------------------------------------------

//callback for when the quit button is pressed
void Game_window::cb_quit(Address, Address pw){
    reference_to<Game_window>(pw).quit();
}

//----------------------------------------------

// return the current score, close the game window
void Game_window::quit(){
    // store the score for the current player
    hide();                       // close the window
}

void Game_window::cb_tile(Address, Address pw){
    reference_to<Game_window>(pw).tile_pressed();
}









