//Window to appear whenever the player that is currently playing obtains a score that is higher than the current highest score
//Parameters that must be passed through to the window -> vector<Player*> players, 

#ifndef image_window_h
#define image_window_h

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

using namespace Graph_lib;
using namespace std;

struct Image_window : Graph_lib::Window {

	Image_window(Point xy, int w, int h, const string& title, vector<Player*> play, string username, string* image);

	bool wait_for_button();

private:
	In_box image_name;
	vector<Player*> players;
	string username;
	Button enter_image;
	string* image;
	// Button quit_button;

	bool button_pushed = false;

	void enter_image_pressed();

	// void quit();

	static void cb_enter(Address, Address);

	// static void cb_quit(Address, Address);

};












#endif