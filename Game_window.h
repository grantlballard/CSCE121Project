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
#include "Player.h"
#include "Image_window.h"

using namespace Graph_lib;
using namespace std;

//---------------------------------------------
// define a struct for the game window
//void input_dictonary(map<char, vector<string>>& dict){
//    ifstream ifs("wordsEna.txt");
//    while(true){
//        string word;
//        char key;
//        ifs>>word;
//        if(ifs.eof() == true){return;}
//        else{
//            key = word[0];
//            dict[key].push_back(word);
//        }
//    }
//    cout << dict.size() << endl;
//}

struct Game_window : Graph_lib::Window {
    
    Game_window(Point xy, int w, int h, const string& title, int size, const map<char, vector<string>>& dict, vector<Player*> play, string username); // should possibly take in the players name in order to save the player score once game is finished
    // or take reference to a player object to update score when game is finished
    
    bool wait_for_button();                 //allows the game window to stay open
    
private:
    // vector<string> words                         // save the words entered by player, no duplicates
 //   Vector_ref<Button> tiles;             // holds the tiles that will be displayed
    Button tile1;
    Button tile2;
    Button tile3;
    Button tile4;
    Button tile5;
    Button tile6;
    Button tile7;
    Button tile8;
    Button tile9;
    Button tile10;
    Button tile11;
    Button tile12;
    Button tile13;
    Button tile14;
    Button tile15;
    Button tile16;
    Button tile17;
    Button tile18;
    Button tile19;
    Button tile20;
    Button tile21;
    Button tile22;
    Button tile23;
    Button tile24;
    Button tile25;

    Button enter_button;                        // button to submit word
    Button clear_button;                        // button to clear input box
    Button quit_button;                         // button to quit the game
    Out_box word_display;                       // display for currently selected letters
    Out_box highscore_display;                  // display the current highscore
    Out_box current_display;                    // display the current gamescore
    Out_box log_display;
    int current_score = 0;                      // users score
    int high_score;                             // high score from the database
    string current_word = "";                   // holds the current word the user is inputting
    map<char, vector<string>> dictionary;
    vector<Player*> players;
    bool button_pushed = false;
    int highest_score;
    int grid_sz;
    string username;
    // In_box image_name;
    //Button enter_image_name;
    //string newimage = "";
    //bool isbuttonpressed;

    void create_tiles(int size);
    
    // should check the dictionary to see if it is an actual word
    void enter_button_pressed();
    
    // clear the word_display box
    void clear_button_pressed();
    
    //show all the tiles
    void show_buttons();
    
    // should update the player list and scores, end the current game
    //program should return to main window
    void quit();
    
    // void enter_image_pressed();

    void tile1_pressed();
    void tile2_pressed();
    void tile3_pressed();
    void tile4_pressed();
    void tile5_pressed();
    void tile6_pressed();
    void tile7_pressed();
    void tile8_pressed();
    void tile9_pressed();
    void tile10_pressed();
    void tile11_pressed();
    void tile12_pressed();
    void tile13_pressed();
    void tile14_pressed();
    void tile15_pressed();
    void tile16_pressed();
    void tile17_pressed();
    void tile18_pressed();
    void tile19_pressed();
    void tile20_pressed();
    void tile21_pressed();
    void tile22_pressed();
    void tile23_pressed();
    void tile24_pressed();
    void tile25_pressed();


    

    static void cb_enter(Address, Address);
    static void cb_clear(Address, Address);
    static void cb_quit(Address, Address);
    // static void cb_enter_image(Address, Address);

    static void cb_tile1(Address, Address);
    static void cb_tile2(Address, Address);
    static void cb_tile3(Address, Address);
    static void cb_tile4(Address, Address);
    static void cb_tile5(Address, Address);
    static void cb_tile6(Address, Address);
    static void cb_tile7(Address, Address);
    static void cb_tile8(Address, Address);
    static void cb_tile9(Address, Address);
    static void cb_tile10(Address, Address);
    static void cb_tile11(Address, Address);
    static void cb_tile12(Address, Address);
    static void cb_tile13(Address, Address);
    static void cb_tile14(Address, Address);
    static void cb_tile15(Address, Address);
    static void cb_tile16(Address, Address);
    static void cb_tile17(Address, Address);
    static void cb_tile18(Address, Address);
    static void cb_tile19(Address, Address);
    static void cb_tile20(Address, Address);
    static void cb_tile21(Address, Address);
    static void cb_tile22(Address, Address);
    static void cb_tile23(Address, Address);
    static void cb_tile24(Address, Address);
    static void cb_tile25(Address, Address);
    
    
};

#endif /* Game_window_hpp */