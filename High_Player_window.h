#ifndef High_player_window_h
#define High_player_window_h

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
#include "High_Player_window.h"
#include "std_lib_facilities_4.h"
using namespace Graph_lib;
using namespace std;
//---------------------------------------------
// define a struct for the high_player window

struct High_Player_window : Graph_lib::Window{
	High_Player_window(Point xy, int w, int h, const string& title,const vector<Player*> play);
    
    //allows for window to stay open
    bool wait_for_button();
    
private:
	vector<Player*> players;		//vector of pointers to Player
	Out_box name_display;			//display the highest players name
	Out_box score_display;			//display the highest score
	Image playerpic;				//image for the highest player
	Button return_button;			//button to return to the main page
	Text title_caption;				//title for the window
    
    bool button_pushed = false;     //used in wait_for_button();
    
	//to return to the home window
	void return_button_pressed();

	//callback function
	static void cb_return(Address, Address);

};

#endif