#include "High_Player_window.h"
#include "Player.h"
High_Player_window::High_Player_window(Point xy, int w, int h, const string& title, const vector<Player*> play) : Window(xy, w, h, title),
	
	players(play),

	title_caption(Point(175,40), "Highest Player"),

	name_display(Point(250,75),150,30,"Name:"),

	score_display(Point(250,125),60,30,"Score: "),

	playerpic(Point(135,175), outputImage(players)),

	return_button(Point(515,10), 80, 20, "RETURN", cb_return)

	{
//-----------------------------------------------------------------------------------------------------
		title_caption.set_font_size(40);								//set the font and size
		title_caption.set_font(Graph_lib::Font::screen_bold);
		attach(title_caption);										//attach the title
		attach(name_display);										//attach the outbox for the name
		attach(score_display);										//attach the outbox for the score
		attach(return_button);										//attach the return button
		name_display.put(outputHighest(players));					//set the name in the outbox
		score_display.put(to_string(outputHighestScore(players)));	//set the score in the outbox
		playerpic.resize(320,220);									//resize the picture
		attach(playerpic);											//attach the image
	}

//-----------------------------------------------------------------------------------------------------
	void High_Player_window::return_button_pressed(){	
		//return to main window
	}

//-----------------------------------------------------------------------------------------------------
	//callback
	void High_Player_window::cb_return(Address, Address pw){
		reference_to<High_Player_window>(pw).return_button_pressed();
	}

int main(){
	try{
		vector<Player*> players;
		input_data(players);
		High_Player_window win(Point(100,100),600,400,"Player",players);
		return gui_main();
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