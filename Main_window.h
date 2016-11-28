#ifndef Main_window_h
#define Main_window_h

#include "std_lib_facilities_4.h"
#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include "Simple_window.h"

struct Main_window : Graph_lib::Window {
	//constructor
	Main_window(Point xy, int w, int h, const string& title);
	
	//functions to get info for other menus
	string get_name(); //Get the name from the In box
	int get_size() {return size;}
	
	private:
	
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
				Out_box err(Point((x_max()-x_max()/2-140),250),300,20,"");
				attach(err);
				err.put("Please enter your name and choose grid size");
				existing_err = true;
			}
		}
		else {
			hide();
			//need to open game window
			Simple_window win(Point(100,100),100,100,"window"); //dummy window
			win.wait_for_button();
		}
	}

	void highscore_pressed() {
		//need to open high score window, but leave main window open
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
Main_window::Main_window(Point xy, int w, int h, const string& title) :

	//initialization
	Window(xy,w,h,title),
	
	enter_name(Point((x_max()-x_max()/2-45),75),90,20, "Enter your name:"),
	three(Point((x_max()-x_max()/2)-35,100),70,20,"3x3",cb_three),
	four(Point((x_max()-x_max()/2)-35,125),70,20,"4x4",cb_four),
	five(Point((x_max()-x_max()/2)-35,150),70,20,"5x5",cb_five),
	start(Point((x_max()-x_max()/2)-45,200),90,20,"Start Game",cb_start),
	highscore(Point((x_max()-x_max()/2)+70,25),130,20,"Current High Score",cb_start),
	quit(Point(5,25),90,20,"Exit Game",cb_quit)
	
{
	attach(enter_name);
	attach(three);
	attach(four);
	attach(five);
	attach(start);
	attach(highscore);
	attach(quit);
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