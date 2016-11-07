//
//  Game_window.hpp
//  CSCE121_Project_current
//
//  Created by Ryan Leitner on 11/2/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#ifndef Game_window_h
#define Game_window_h

#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"
#include <map>
#include <cassert>
#include <vector>
#include <fstream>

using namespace Graph_lib;
using namespace std;

//---------------------------------------------
// define a struct for the game window
void input_dictonary(map<char, vector<string>>& dict){
    ifstream ifs("wordsEna.txt");
    while(true){
        string word;
        char key;
        ifs>>word;
        if(ifs.eof() == true){return;}
        else{
            key = word[0];
            dict[key].push_back(word);
        }
    }
    cout << dict.size() << endl;
}

struct Game_window : Graph_lib::Window {
    
    Game_window(Point xy, int w, int h, const string& title, int grid_sz, const map<char, vector<string>>& dict); // should possibly take in the players name in order to save the player score once game is finished
    // or take reference to a player object to update score when game is finished
    
private:
    // vector<string> words                         // save the words entered by player, no duplicates
    Vector_ref<Button> tiles;             // holds the tiles that will be displayed
    Button enter_button;                        // button to submit word
    Button clear_button;                        // button to clear input box
    Button quit_button;                         // button to quit the game
    Out_box word_display;                       // display for currently selected letters
    Out_box highscore_display;                  // display the current highscore
    Out_box current_display;                    // display the current gamescore
    int current_score = 0;                      // users score
    int high_score;                             // high score from the database
    string current_word = "some word";                   // holds the current word the user is inputting
    map<char, vector<string>> dictionary;
    
    void create_tiles(int size);
    
    // should check the dictionary to see if it is an actual word
    void enter_button_pressed();
    
    // clear the word_display box
    void clear_button_pressed();
    
    // should update the player list and scores, end the current game
    //program should return to main window
    void quit();
    
    void tile_pressed();
    
    static void cb_enter(Address, Address);
    static void cb_clear(Address, Address);
    static void cb_quit(Address, Address);
    static void cb_tile(Address, Address);
    
    
};

#endif /* Game_window_hpp */
