//Main_window class, used to get name, grid size, and provide options to view high score window or exit the game
//Main_window.h
//Created on 11/2/16 by Alyssa Schaeffer
//Updated last 10:42 AM 12/2/16

#ifndef Main_window_h
#define Main_window_h

#include "std_lib_facilities_4.h"
#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"
#include "Player.h"
#include "Game_window.h"



struct Main_window : Graph_lib::Window {
	//constructor
	Main_window(Point xy, int w, int h, const string& title, map<char,vector<string>> dict, vector<Player*>& players);
	
	//functions to get info for other menus
	string get_name(); //Get the name from the In box
	int get_size() {return size;}
	
    
	
	private:
    
    //dictionary that holds valid words
    map<char,vector<string>> dictionary;
	
	vector<Player*> players;
	
	//default name and size
	string name = "";
	int size = 0;
    
	
	bool existing_err = false; //checks if there is already an error box on the menu

	//widgets
	In_box enter_name;
	Button three;
	Button four;
	Button five;
	Button start;
	Button highscore;
	Button quit;
	Out_box err;
	
	//function members

	void three_pressed() {
		size = 3;
	}
	
	void four_pressed() {
		size = 4;
	}
	
	void five_pressed() {
		size = 5;
	}
	
	void start_pressed() {
		name = get_name(); //gets name from in box 
		if(name == "" || size == 0) { //displays error message if info not inputted
			if(existing_err == false) {
				err.put("Name or size not entered, please try again");
				existing_err = true;
			}
		}
		else {
			if(existing_err == true) err.put("Please enter your name and size of the grid");
			existing_err = false;
			hide();
			newPlayer(name,players);
            Game_window game(Point(100,100),600,400,"Game Window",size,dictionary,players);
            
            game.wait_for_button();
            this->show();
            name = "";
            size = 0;
            enter_name.put(name);
			set_label("Word Search Game");

		}
	}

	void highscore_pressed() {
        hide();
        High_Player_window highscorewin(Point(100,100),600,400,"High Score Player",players);
        highscorewin.wait_for_button();
        this->show();
	}
	
	void quit_pressed() {
		hide(); //exits game
	}
	
	//callback functions
	static void cb_three(Address, Address);
	static void cb_four(Address, Address);
	static void cb_five(Address, Address);
	static void cb_start(Address, Address);
	static void cb_highscore(Address, Address);
	static void cb_quit(Address, Address);
};

//constructor:
Main_window::Main_window(Point xy, int w, int h, const string& title,map<char,vector<string>> dict ,vector<Player*>& players) :

	//initialization
	Window(xy,w,h,title),

    dictionary(dict),
	
	players(players),
	
	enter_name(Point((x_max()-x_max()/2-45),75),90,20, "Name:"),
	three(Point((x_max()-x_max()/2)-35,100),70,20,"3x3",cb_three),
	four(Point((x_max()-x_max()/2)-35,125),70,20,"4x4",cb_four),
	five(Point((x_max()-x_max()/2)-35,150),70,20,"5x5",cb_five),
	start(Point((x_max()-x_max()/2)-45,195),90,20,"Start Game",cb_start),	
	highscore(Point((x_max()-x_max()/2)-65,280),130,20,"Current High Score",cb_highscore), //
	quit(Point((x_max()-x_max()/2)-45,320),90,20,"Exit Game",cb_quit), //
	err(Point((x_max()-x_max()/2-140),240),300,20,"")
	
{
	attach(enter_name);
	attach(three);
	attach(four);
	attach(five);
	attach(start);
	attach(highscore);
	attach(quit);
	attach(err);
	
	err.put("Please enter your name and size of the grid");;
}

string Main_window::get_name() {
	string name = enter_name.get_string();
	return name;
}

//callbacks
void Main_window::cb_three(Address, Address pw){
	reference_to<Main_window>(pw).three_pressed();
}
	
void Main_window::cb_four(Address, Address pw){
	reference_to<Main_window>(pw).four_pressed();
}

void Main_window::cb_five(Address, Address pw){
	reference_to<Main_window>(pw).five_pressed();
}

void Main_window::cb_start(Address, Address pw){
	reference_to<Main_window>(pw).start_pressed();
}

void Main_window::cb_highscore(Address, Address pw){
	reference_to<Main_window>(pw).highscore_pressed();
}

void Main_window::cb_quit(Address, Address pw){
	reference_to<Main_window>(pw).quit_pressed();
}

#endif

//Problem is that there is no way to detach a box that has already been attached.
//Possible solution: have the blank box there at all times