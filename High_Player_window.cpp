#include "High_Player_window.h"
#include "Player.h"
High_Player_window::High_Player_window(Point xy, int w, int h, const string& title, const vector<Player*> play) : Window(xy, w, h, title),
	
	players(play),

	title_caption(Point(175,40), "Highest Player"),

	name_display(Point(250,75),150,30,"Name:"),

	score_display(Point(250,125),60,30,"Score: "),

	playerpic(Point(135,175), play.size()==0 ? "highestplayer.jpg" : outputImage(play)),

	return_button(Point(515,10), 80, 20, "RETURN", cb_return)

	{
//-----------------------------------------------------------------------------------------------------
		title_caption.set_font_size(40);								//set the font and size
		title_caption.set_font(Graph_lib::Font::screen_bold);
		attach(title_caption);										//attach the title
		attach(name_display);										//attach the outbox for the name
		attach(score_display);										//attach the outbox for the score
		attach(return_button);										//attach the return button
		if(players.size() == 0){
			name_display.put("No Highest Player");
			score_display.put("0");
			playerpic.resize(320,220);
		}
		else{
			name_display.put(outputHighest(players));					//set the name in the outbox
			score_display.put(to_string(outputHighestScore(players)));	//set the score in the outbox
			playerpic.resize(320,220);									//resize the picture
		}
		attach(playerpic);
	}


//-----------------------------------------------------------------------------------------------------

bool High_Player_window::wait_for_button()
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


//-----------------------------------------------------------------------------------------------------
	void High_Player_window::return_button_pressed(){	
        button_pushed = true;
        hide();					//return to main window
	}

//-----------------------------------------------------------------------------------------------------
	//callback
	void High_Player_window::cb_return(Address, Address pw){
		reference_to<High_Player_window>(pw).return_button_pressed();
	}