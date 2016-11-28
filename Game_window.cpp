//
//  Game_window.cpp
//  CSCE121_Project_current
//
//  Created by Ryan Leitner on 11/2/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include "Game_window.h"

string rand_char(){
    int n = rand() % 26;
    char c = (char)(n+65);
    string s;
    s.push_back(c);
    return s;
}


Game_window::Game_window(Point xy, int w, int h, const string& title, int grid_sz, const map<char, vector<string>>& dict) : Window(xy, w, h, title),
    
    dictionary(dict),

    enter_button(Point(400,240),50, 20, "ENTER", cb_enter),

    clear_button(Point(400,270),50, 20, "CLEAR", cb_clear),

    quit_button(Point(400,300), 50, 20, "QUIT", cb_quit),

    word_display(Point(100,300), 100, 20, "Word:"),

    highscore_display(Point(500, 20), 50, 20, "High score:"),

    tile1(Point(30,10),50,50,rand_char(),cb_tile1),
    tile2(Point(90,10),50,50,rand_char(),cb_tile2),
    tile3(Point(150,10),50,50,rand_char(),cb_tile3),
    tile4(Point(210,10),50,50,rand_char(),cb_tile4),
    tile5(Point(270,10),50,50,rand_char(),cb_tile5),
    tile6(Point(30,70),50,50,rand_char(),cb_tile6),
    tile7(Point(90,70),50,50,rand_char(),cb_tile7),
    tile8(Point(150,70),50,50,rand_char(),cb_tile8),
    tile9(Point(210,70),50,50,rand_char(),cb_tile9),
    tile10(Point(270,70),50,50,rand_char(),cb_tile10),
    tile11(Point(30,130),50,50,rand_char(),cb_tile11),
    tile12(Point(90,130),50,50,rand_char(),cb_tile12),
    tile13(Point(150,130),50,50,rand_char(),cb_tile13),
    tile14(Point(210,130),50,50,rand_char(),cb_tile14),
    tile15(Point(270,130),50,50,rand_char(),cb_tile15),
    tile16(Point(30,190),50,50,rand_char(),cb_tile16),
    tile17(Point(90,190),50,50,rand_char(),cb_tile17),
    tile18(Point(150,190),50,50,rand_char(),cb_tile18),
    tile19(Point(210,190),50,50,rand_char(),cb_tile19),
    tile20(Point(270,190),50,50,rand_char(),cb_tile20),
    tile21(Point(30,250),50,50,rand_char(),cb_tile21),
    tile22(Point(90,250),50,50,rand_char(),cb_tile22),
    tile23(Point(150,250),50,50,rand_char(),cb_tile23),
    tile24(Point(210,250),50,50,rand_char(),cb_tile24),
    tile25(Point(270,250),50,50,rand_char(),cb_tile25),

    current_display(Point(500, 50), 50, 20, "Score"){
    
    //Create the grid of tiles

    /*
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
    */

        attach(tile1);
        attach(tile2);
        attach(tile3);
        attach(tile4);
        attach(tile5);
        attach(tile6);
        attach(tile7);
        attach(tile8);
        attach(tile9);
        attach(tile10);
        attach(tile11);
        attach(tile12);
        attach(tile13);
        attach(tile14);
        attach(tile15);
        attach(tile16);
        attach(tile17);
        attach(tile18);
        attach(tile19);
        attach(tile20);
        attach(tile21);
        attach(tile22);
        attach(tile23);
        attach(tile24);
        attach(tile25);
        attach(enter_button);
        attach(clear_button);
        attach(quit_button);
        attach(word_display);
        attach(highscore_display);
        attach(current_display);
        current_display.put("0");
        word_display.put("Enter Letters");
   
}
vector<string> allwords;
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
    if(current_word==""){return;}           // if the user inputs nothing
    transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower); //Changes the inputted word from uppercase to lower
    for(auto words : allwords){
        if(current_word == words){
            current_word = "";
            word_display.put(current_word);
            return;
        }
    }
    char first_letter = current_word[0];                                                
    vector<string> first = dictionary[first_letter];                        
    for(auto word : first)  {                //iterates through the map The first character of the word is the key
        if(word == current_word){
            allwords.push_back(current_word);       
            current_score++;                // updates the score
            current_display.put(to_string(current_score));
        }   
    }    
current_word = "";                  // reset the current word

word_display.put(current_word);
    
}
//----------------------------------------------

//what to do when a tile is pressed

void Game_window::tile1_pressed(){
    current_word += tile1.label;
    word_display.put(current_word);
    tile1.hide();
}
void Game_window::tile2_pressed(){
    current_word += tile2.label;
    word_display.put(current_word);
    tile2.hide();
}
void Game_window::tile3_pressed(){
    current_word += tile3.label;
    word_display.put(current_word);
    tile3.hide();
}
void Game_window::tile4_pressed(){
    current_word += tile4.label;
    word_display.put(current_word);
    tile4.hide();
}
void Game_window::tile5_pressed(){
    current_word += tile5.label;
    word_display.put(current_word);
    tile5.hide();
}
void Game_window::tile6_pressed(){
    current_word += tile6.label;
    word_display.put(current_word);
    tile6.hide();
}
void Game_window::tile7_pressed(){
    current_word += tile7.label;
    word_display.put(current_word);
    tile7.hide();
}
void Game_window::tile8_pressed(){
    current_word += tile8.label;
    word_display.put(current_word);
    tile8.hide();
}
void Game_window::tile9_pressed(){
    current_word += tile9.label;
    word_display.put(current_word);
    tile9.hide();
}
void Game_window::tile10_pressed(){
    current_word += tile10.label;
    word_display.put(current_word);
    tile10.hide();
}
void Game_window::tile11_pressed(){
    current_word += tile11.label;
    word_display.put(current_word);
    tile11.hide();
}
void Game_window::tile12_pressed(){
    current_word += tile12.label;
    word_display.put(current_word);
    tile12.hide();
}
void Game_window::tile13_pressed(){
    current_word += tile13.label;
    word_display.put(current_word);
    tile13.hide();
}
void Game_window::tile14_pressed(){
    current_word += tile14.label;
    word_display.put(current_word);
    tile14.hide();
}
void Game_window::tile15_pressed(){
    current_word += tile15.label;
    word_display.put(current_word);
    tile15.hide();
}
void Game_window::tile16_pressed(){
    current_word += tile16.label;
    word_display.put(current_word);
    tile16.hide();
}
void Game_window::tile17_pressed(){
    current_word += tile17.label;
    word_display.put(current_word);
    tile17.hide();
}
void Game_window::tile18_pressed(){
    current_word += tile18.label;
    word_display.put(current_word);
    tile18.hide();
}
void Game_window::tile19_pressed(){
    current_word += tile19.label;
    word_display.put(current_word);
    tile19.hide();
}
void Game_window::tile20_pressed(){
    current_word += tile20.label;
    word_display.put(current_word);
    tile20.hide();
}
void Game_window::tile21_pressed(){
    current_word += tile21.label;
    word_display.put(current_word);
    tile21.hide();
}
void Game_window::tile22_pressed(){
    current_word += tile22.label;
    word_display.put(current_word);
    tile22.hide();
}
void Game_window::tile23_pressed(){
    current_word += tile23.label;
    word_display.put(current_word);
    tile23.hide();
}
void Game_window::tile24_pressed(){
    current_word += tile24.label;
    word_display.put(current_word);
    tile24.hide();
}
void Game_window::tile25_pressed(){
    current_word += tile25.label;
    word_display.put(current_word);
    tile25.hide();
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

void Game_window::cb_tile1(Address, Address pw){
    reference_to<Game_window>(pw).tile1_pressed();
}
void Game_window::cb_tile2(Address, Address pw){
    reference_to<Game_window>(pw).tile2_pressed();
}
void Game_window::cb_tile3(Address, Address pw){
    reference_to<Game_window>(pw).tile3_pressed();
}
void Game_window::cb_tile4(Address, Address pw){
    reference_to<Game_window>(pw).tile4_pressed();
}
void Game_window::cb_tile5(Address, Address pw){
    reference_to<Game_window>(pw).tile5_pressed();
}
void Game_window::cb_tile6(Address, Address pw){
    reference_to<Game_window>(pw).tile6_pressed();
}
void Game_window::cb_tile7(Address, Address pw){
    reference_to<Game_window>(pw).tile7_pressed();
}
void Game_window::cb_tile8(Address, Address pw){
    reference_to<Game_window>(pw).tile8_pressed();
}
void Game_window::cb_tile9(Address, Address pw){
    reference_to<Game_window>(pw).tile9_pressed();
}
void Game_window::cb_tile10(Address, Address pw){
    reference_to<Game_window>(pw).tile10_pressed();
}
void Game_window::cb_tile11(Address, Address pw){
    reference_to<Game_window>(pw).tile11_pressed();
}
void Game_window::cb_tile12(Address, Address pw){
    reference_to<Game_window>(pw).tile12_pressed();
}
void Game_window::cb_tile13(Address, Address pw){
    reference_to<Game_window>(pw).tile13_pressed();
}
void Game_window::cb_tile14(Address, Address pw){
    reference_to<Game_window>(pw).tile14_pressed();
}
void Game_window::cb_tile15(Address, Address pw){
    reference_to<Game_window>(pw).tile15_pressed();
}
void Game_window::cb_tile16(Address, Address pw){
    reference_to<Game_window>(pw).tile16_pressed();
}
void Game_window::cb_tile17(Address, Address pw){
    reference_to<Game_window>(pw).tile17_pressed();
}
void Game_window::cb_tile18(Address, Address pw){
    reference_to<Game_window>(pw).tile18_pressed();
}
void Game_window::cb_tile19(Address, Address pw){
    reference_to<Game_window>(pw).tile19_pressed();
}
void Game_window::cb_tile20(Address, Address pw){
    reference_to<Game_window>(pw).tile20_pressed();
}
void Game_window::cb_tile21(Address, Address pw){
    reference_to<Game_window>(pw).tile21_pressed();
}
void Game_window::cb_tile22(Address, Address pw){
    reference_to<Game_window>(pw).tile22_pressed();
}
void Game_window::cb_tile23(Address, Address pw){
    reference_to<Game_window>(pw).tile23_pressed();
}
void Game_window::cb_tile24(Address, Address pw){
    reference_to<Game_window>(pw).tile24_pressed();
}
void Game_window::cb_tile25(Address, Address pw){
    reference_to<Game_window>(pw).tile25_pressed();
}


int main(){
srand (time(NULL)); 
  try {
    // construct the GUI window
    
    //vector<string> d;
    map<char, vector<string>> dict;
    input_dictonary(dict);
    cout << dict.size() << endl;

    Game_window win(Point(100,100),600,400,"lines",3,dict);
    return gui_main();  // inherited from Window; calls FLTK's run
  }
  catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch(...) {
    cerr << "some exception\n";
    return 2;
  }
}

