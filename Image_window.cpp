//Window to appear whenever the player that is currently playing obtains a score that is higher than the current highest score
//Parameters that must be passed through to the window: vector<Player*> players, username, and an empty string

#include "Image_window.h"

Image_window::Image_window(Point xy, int w, int h, const string& title, vector<Player*> play, string name, string* im) : Window(xy, w, h, title),

	image(im),					//pointer to image name (empty when entered)

	players(play), 				//vector of Player*

	username(name),				//Player's name

	enter_image(Point(255,50), 50, 20, "ENTER", cb_enter),	//Button to enter the image name

	image_name(Point(150, 50), 100, 25, "Enter image file: ")			//Inbox to enter new image file name

	{
		attach(enter_image);
		attach(image_name);
	}

/*-----------------------------------------------------------------------------------------------*/

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

/*-----------------------------------------------------------------------------------------------*/
//ENTER BUTTON IS PRESSED - CHECKS VALIDITY OF THE IMAGE NAME INSERTED

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

/*-----------------------------------------------------------------------------------------------*/
//CALLBACK FUNCTION
void Image_window::cb_enter(Address, Address pw){
	reference_to<Image_window>(pw).enter_image_pressed();
}
