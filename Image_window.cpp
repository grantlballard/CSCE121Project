#include "Image_window.h"

Image_window::Image_window(Point xy, int w, int h, const string& title, vector<Player*> play, string name, string* im) : Window(xy, w, h, title),

	image(im),

	players(play), 

	username(name),

	enter_image(Point(255,50), 50, 20, "ENTER", cb_enter),

	image_name(Point(150, 50), 100, 25, "Image: ")

	// quit_button(Point(300, 20), 50, 20, "QUIT", cb_quit)

	{
		// attach(quit_button);
		attach(enter_image);
		attach(image_name);
	}

bool Image_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
   // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

void Image_window::enter_image_pressed(){
	*image = image_name.get_string();
	if(*image == ""){
		Out_box err(Point(100,28),200,20,"");
		attach(err);
		err.put("Please enter proper image file");
	}
	else{
		Out_box err(Point(100,28),200,20,"");
		attach(err);
		err.put("Image file accepted");
		button_pushed=true;
		hide();
		//return image;
	}

}

// void Image_window::quit(){
// 	button_pushed=true;
// 	hide();
// }

void Image_window::cb_enter(Address, Address pw){
	reference_to<Image_window>(pw).enter_image_pressed();
}

// void Image_window::cb_quit(Address, Address pw){
// 	reference_to<Image_window>(pw).quit();
// }


// int main() {
//     try {
//         vector<Player*> players;
//         input_data(players);
//        // cout << "The first player is " << players[0]->getName()<< endl;
//         //map<char, vector<string>> dict;
//         //input_dictonary(dict);
//         string name = "amanda";
//         string image = "";
//         Image_window main_win(Point(400,50),400,100,"New Highest!",players,name, image);
//         return gui_main();
//         cout << image << endl;

        
//     }
//     catch(exception& e) {
//             cerr << "exception: " << e.what() << '\n';
//             return 1;
//         	}
//     catch(...) {
//         	cerr << "some exception\n";
//         	return 2;
//         	}
    
//     return 0;
// }