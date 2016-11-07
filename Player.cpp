//
//  Player.cpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include "Player.h"
Player::Player(string n, int s, string i){
	name = n;
	image = i;
	scores.push_back(s);
}

Player::Player(string n, string i){
	name = n;
	image = i;
	scores.push_back(0);
}

string Player::getScores() const{
	string scores_all;
	for(auto playerscores : scores){
		scores_all = scores_all + to_string(playerscores) + " ";
	}
	return scores_all;
}

int Player::getHighScore() const{
	int score = -99;
	for(auto playerscores : scores){
		if(playerscores	> score){score = playerscores;}
	}
	return score;
}

bool operator == (const Player& a, const Player& b){
	return a.getName() == b.getName();
}

ostream& operator<<(ostream& os, Player p){
	os << p.getName() << endl << p.getScores() << endl << p.getImage() << endl;
	return os;
}