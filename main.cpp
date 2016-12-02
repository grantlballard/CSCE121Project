//
//  main.cpp
//  graphicsProjectCurrent
//
//  Created by Ryan Leitner on 11/28/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include <iostream>
#include "Game_window.h"
#include "High_Player_window.h"
#include "Main_window.h"


void input_dictonary(map<char, vector<string>>& dict){
    ifstream ifs("wordsEna.txt");
    while(true){
        string word;
        char key;
        ifs>>word;
        if(ifs.eof() == true){return;}
        else{
            key = word[0];
            dict[key].push_back(word);
        }
    }
    cout << dict.size() << endl;
}


int main() {
    try {
        vector<Player*> players;
        input_data(players);
       // cout << "The first player is " << players[0]->getName()<< endl;
        map<char, vector<string>> dict;
        input_dictonary(dict);
        Main_window main_win(Point(50,50),600,400,"Word Search Game",dict,players);
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
    
    return 0;
}
