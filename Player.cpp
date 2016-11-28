//
//  Player.cpp
//  WordCombonationsGame
//
//  Created by Ryan Leitner on 10/31/16.
//  Copyright © 2016 Ryan Leitner. All rights reserved.
//

#include "Player.h"
Player::Player(string n, vector<int> s){
	name = n;
	scores = s;
}

Player::Player(string n){
	name = n;
}

string Player::printScores() const{
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

void Player::print(ofstream& ofs){
	vector<int> scores = getScoresVector();
	ofs << getIdentifier() << endl
        << getName() << endl;
    for(auto s : scores){
    	ofs << s << endl;
    }
}

bool operator == (const Player& a, const Player& b){
	return a.getName() == b.getName();
}

ostream& operator<<(ostream& os, Player p){
	os << p.getName() << endl << p.printScores() << endl;
	return os;
}

HighestPlayer::HighestPlayer(string n, vector<int> s, string i):
	Player(n,s), image(i){}

void HighestPlayer::print(ofstream& ofs){
	vector<int> scores = getScoresVector();
	ofs << getIdentifier() << endl
        << getName() << endl;
    for(auto s : scores){
    	ofs << s << endl;
    }
    ofs << getImage() << endl;
}

ostream& operator<<(ostream& os, HighestPlayer h){
	os  << h.getName() << endl 
		<< h.printScores() << endl
		<< h.getImage() << endl;
	return os;
}

void input_data(vector<Player*>& player){
    ifstream ifs("vector.txt");
    while(ifs){
        string stringin;
        int scores;
        vector<int> allscores;
        char kind;
        string id;
        string imagename;
        ifs >> id;
        ifs.ignore();
        if(!id.empty() && id[id.size()-1] == '\r'){
            id = id.erase(id.size()-1);
        }
        kind = id[0];
        ifs.ignore();
        string name;
        getline(ifs,name);  //uses getline to deal with spaces
        //deals with end line characters
        if(!name.empty() && name[name.size()-1] == '\r'){
            name = name.erase(name.size()-1);
        }
        getline(ifs, stringin);
        stringstream ss;
        ss << stringin;
        while(ss >> scores){
            allscores.push_back(scores);
        }

        if (kind == 'P'){
            player.push_back(new Player(name, allscores));
        }

        else if(kind == 'H'){
            getline(ifs, imagename);
            player.push_back(new HighestPlayer(name, allscores,imagename));
        }
        if(ifs.eof()){return;}
    }
    return;
}

//to check if the player already exist
bool uniquePlayer(string name, const vector<Player*>& player){
    for (auto p : player){
        if (p -> getName() == name) {return false;}
    }
    return true;
}

//if the player is unique, add the new player to the vector
void newPlayer(string name, vector<Player*>& player){
    if (!uniquePlayer(name, player)) {
        //Player already exists
        //start the game
        return;
    }

    player.push_back(new Player(name));
    return;
}

//Delete the current highest player and set them as a regular player
void deleteHighest(vector<Player*>& player){
    for (unsigned int i = 0; i < player.size(); ++i) {
        if (player[i] -> getIdentifier() == 'H'){
            player.push_back(new Player(player[i]->getName(), player[i]->getScoresVector()));
            delete player[i];
            player.erase(player.begin()+i);
            return;
        }
    }
}


//set a player to the highest player. Queries user to input image name
void setHighest(vector<Player*>& player){
    int highest = -99;
    int element;
    for (unsigned int i = 0; i < player.size(); ++i) {
        if (player[i] -> getHighScore() > highest){
            highest = player[i] -> getHighScore();
            element = i;
        }
    }
    //change this to an in-box to take in the image name
    cout << "Please enter your image file" << endl;
    string image;
    cin >> image;
    player.push_back(new HighestPlayer(player[element]->getName(), player[element]->getScoresVector(), image));
    cout << "New highest player" << endl;

}


//find the highest score in the vector of players
void checkHighest(vector<Player*>& player){
    int highest = -99;
    int element;
    for (unsigned int i = 0; i < player.size(); ++i) {
        if (player[i] -> getHighScore() > highest){
            highest = player[i] -> getHighScore();
            element = i;
        }
    }

    if (player[element]->getIdentifier() == 'H'){return;}
    else {
        deleteHighest(player);
        setHighest(player);
    }

}

string outputHighest(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getName();
        }
    }
}

int outputHighestScore(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getHighScore();
        }
    }
}

string outputImage(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getImage();
        }
    }
}

