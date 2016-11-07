//
//  Player_List.cpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include "Player_List.h"


void Player_List::addPlayer(Player player){
	for(auto allplayers : Player_List::players){
		if(player == allplayers){
			cout << "Person is already a user!" << endl;
			return;
		}
	}
	Player_List::players.push_back(player);
	return;
}

Player Player_List::highestPlayer() const{
	int highestscore = -99;
	Player highestplayer;
	for(auto p : players){
		if(p.getHighScore() > highestscore ){
			highestscore = p.getHighScore();
			highestplayer = p;
		}
	}
	return highestplayer;
};
