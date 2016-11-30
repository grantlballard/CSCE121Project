//Player.cpp 

#include "Player.h"

//CONSTRUCTORS
Player::Player(string n, vector<int> s){
	name = n;
	scores = s;
}

Player::Player(string n){
	name = n;
}

HighestPlayer::HighestPlayer(string n, vector<int> s, string i):
    Player(n,s), image(i){}

/*----------------------------------------------------------------------------------------*/

// PRINT FUNCTIONS
string Player::printScores() const{
	string scores_all;
	for(auto playerscores : scores){
		scores_all = scores_all + to_string(playerscores) + " ";
	}
	return scores_all;
}

void HighestPlayer::print(ofstream& ofs){
    vector<int> scores = getScoresVector();
    ofs << getIdentifier() << endl
        << getName() << endl;
    for(auto s : scores){
        ofs << s << " ";
    }
    ofs << endl << getImage();
}

void Player::print(ofstream& ofs){
    vector<int> scores = getScoresVector();
    ofs << getIdentifier() << endl
        << getName() << endl;
    for(auto s : scores){
        ofs << s << " ";
    }
    ofs << endl;
}

/*----------------------------------------------------------------------------------------*/

int Player::getHighScore() const{
	int score = -99;
	for(auto playerscores : scores){
		if(playerscores	> score){score = playerscores;}
	}
	return score;
}

/*----------------------------------------------------------------------------------------*/

//OVERLOADED OPERATOR
bool operator == (const Player& a, const Player& b){
	return a.getName() == b.getName();
}

ostream& operator<<(ostream& os, Player p){
	os << p.getName() << endl << p.printScores() << endl;
	return os;
}

ostream& operator<<(ostream& os, HighestPlayer h){
	os  << h.getName() << endl 
		<< h.printScores() << endl
		<< h.getImage() << endl;
	return os;
}

/*----------------------------------------------------------------------------------------*/

//INPUT DATA FROM TEXT FILE
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
        //ifs.ignore();
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

/*----------------------------------------------------------------------------------------*/

//CHECK IF PLAYER ALREADY EXISTS
bool uniquePlayer(string name, const vector<Player*>& player){
    for (auto p : player){
        if (p -> getName() == name) {return false;}
    }
    return true;
}

/*----------------------------------------------------------------------------------------*/

//ADD NEW PLAYER TO THE VECTOR IF IT IS UNIQUE
void newPlayer(string name, vector<Player*>& player){
    if (!uniquePlayer(name, player)) {
        //Player already exists
        //start the game
        return;
    }

    player.push_back(new Player(name));
    cout << "New player added" << endl;
    return;
}

/*----------------------------------------------------------------------------------------*/

//DELETE HIGHEST PLAYER AND SET AS REGULAR PLAYER
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


//SET NEW PLAYER AS THE HIGHEST PLAYER
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
    delete player[element];
    player.erase(player.begin()+element);
    cout << "New highest player" << endl;

}


//CHECK IF THE HIGHEST PLAYER IS ACTUALLY THE HIGHEST SCORE
bool checkHighest(vector<Player*>& player){
    int highest = -99;
    int element;
    for (unsigned int i = 0; i < player.size(); ++i) {
        if (player[i] -> getHighScore() > highest){
            highest = player[i] -> getHighScore();
            element = i;
        }
    }

    if (player[element]->getIdentifier() == 'H'){return true;}
    else {
        deleteHighest(player);
        setHighest(player);
        return false;
    }

}

/*----------------------------------------------------------------------------------------*/

//OUTPUT THE HIGHEST PLAYER'S NAME
string outputHighest(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getName();
        }
    }
}

//OUTPUT THE HIGHEST PLAYER'S SCORE
int outputHighestScore(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getHighScore();
        }
    }
}

//OUTPUT THE HIGHEST PLAYER'S IMAGE NAME
string outputImage(vector<Player*> player){
    for(auto p : player){
        if(p->getIdentifier() == 'H'){
            return p->getImage();
        }
    }
}

/*----------------------------------------------------------------------------------------*/

//OUTPUT THE VECTOR TO THE TEXT FILE IT READ FROM
void output_data(const vector<Player*>& player) 
{
  ofstream ofs("vector.txt");
  //uses virtual function to output the information of each element
  for (auto p : player) {
    if(p->getIdentifier() == 'P'){
      p->print(ofs);
      //delete p;
    }
  }
  for (auto p : player) {
    if(p->getIdentifier() == 'H'){
      p->print(ofs);
      //delete p;
    }
  }
}

/*----------------------------------------------------------------------------------------*/

//ADD A NEW SCORE TO A PLAYER
void newScore(string name, int score, vector<Player*>& player)
{
    if(!uniquePlayer(name, player)){
        int iterator = 0;
        for(auto p : player){
            if(p->getName() == name){
                break;
            }
            cout << iterator << endl;
          iterator++;
        }
        cout << "The person's name is " << player[iterator] -> getName() << endl;
        player[iterator]->addScore(score);
        
    }
}
