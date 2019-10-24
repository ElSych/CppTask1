#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstdlib>
#include <vector>
#include <thread>
using namespace std; 
const float g = 9.8;
class ball;
class base;
class game;
class player{
	int money;
	string name;
	float res;
public:
	player(){
		cout << "Enter name:" << endl;
		cin >> name;
		money = 100; 
	}
	void setmoney(int mon){
		money = mon;
	}
	int getmoney(){
		return money;
	}
	void setres(float result){
		res = result;
	}
	float getres(){
		return res;
	}
	string getname(){
		return name;
	}
	string setname(string &sname){
		name = sname;
	}
	void showplayer(){ 
		cout << "Name: " << name << endl; 
		cout << "Money: " << money << endl; 
	}
	void easybot(float x){
		name = "Easybot";
		money = 50;
		float speed = pow(x, 0.5);
		srand(time(NULL)); 
		float chance=(rand()%120 + 80)/(100*1.0); 
		speed *= chance;
		res = pow(speed, 2)*sin(30*0.017)/g;
	}
	void mediumbot(float x){
		name = "Mediumbot";
		money = 100;
		money -= 10;
		float speed = pow(x, 0.5);
		srand(time(NULL)); 
		float chance=(rand()%105 + 95)/(100*1.0); 
		speed *= chance;
		res = pow(speed, 2)*sin(30*0.017)/g;
	}
	void hardbot(float x){
		name = "Hardbot";
		money = 150;
		money -= 15;
		float speed = pow(x, 0.5);
		srand(time(NULL)); 
		float chance=(rand()%105 + 95)/(100*1.0); 
		speed *= chance;
		res = pow(speed, 2)*sin(30*0.017)/g;
	}
};
class ball{
	float rad;
	float angle;
	float speed;
public:
	int ballsize(vector<player>& players, int i){
		int size;
		cout << "Choose ball:" << endl << "1: small: 0.04m rad, price: free"<< endl << "2: medium: 0.07m rad, price: 10"<< endl << "3: big: 0.1m rad, price: 15" << endl;
		cin >> size;
		switch(size){
			case 1:
			rad = 0.04;
			break;
			case 2:
			rad = 0.07;
			players[i].setmoney(players[i].getmoney() - 10);
			break;
			case 3:
			rad = 0.1;
			players[i].setmoney(players[i].getmoney() - 15);
			break;
			default:
			cout << "Error, enter 1, 2 or 3" << endl;
			break;
		}
	}
	float getrad(){
		return rad;
	}
	float setrad(float r){
		rad = r;
	}
	float getspeed(){
		return speed;
	}
	void setspeed(float sp){
		speed = sp;
	}
	float getangle(){
		return angle;
	}
	void setangle(float ag){
		angle = ag;
	}
	int result(vector<player>& players, int i){
		cout << "Player №" << i << ", enter speed:" << endl; 
		cin >> speed; 
		cout << "Player №" << i << ", enter angle:" << endl; 
		cin >> angle; 
		float result = pow(speed, 2)*sin(2*angle*0.017)/g;
		players[i].setres(result);
	}
};
class base{  
	float x; 
	float d; 
public:
	base(){
		srand(time(NULL)); 
		x = rand()%100 + 10; 
		d = x*0.02; 
			cout << "Range is " << x << endl; 
			cout << "Area is " << d << endl; 
	} 
	float getx(){
		return x;
	}
	float getd(){
		return d;
	}
};
class game{
int bank;
	public:
	int gameinit(int n, int bn, vector<player>& players, vector<ball>& balls){
	double chance;
		for (int i = 0; i < n; i++){
			players[i].setmoney(players[i].getmoney() - 50);
			bank += players[i].getmoney(); 
			balls[i].ballsize(players, i);
			balls[i].result(players, i);
			cout << "Player " << i << ":" << endl;
			players[i].showplayer();
			cout << endl; 
			srand(time(NULL)); 
			chance=(rand()%105 + 95)/(100*1.0); 
			balls[i].setspeed(balls[i].getspeed() * chance); 
		} 
	}
	int botinit(int n, int bn, vector<player>& players, base *bs, vector<ball>& balls){
		for(int i = n; i < bn+n; i++){
		    int choice;
			cout << "Choose the difficulty of " << (i-n) << " bot" << endl;
			cout << "1: Easy"<< endl << "2: Medium"<< endl << "3: Hard" << endl;
			cin >> choice;
			switch(choice){
			    case 1:
			    float x1;
			    x1 = (bs->getx()*g/sin(30*0.017));
			 	players[i].easybot(x1);
			 	balls[i].setrad(0.04);
			 	players[i].setmoney(players[i].getmoney() - 50);
			 	players[i].showplayer();
			    break;
			    case 2:
			    float x2;
			    x2 = (bs->getx()*g/sin(30*0.017));
			    players[i].mediumbot(x2);
			    balls[i].setrad(0.07);
			    players[i].setmoney(players[i].getmoney() - 50);
			    players[i].showplayer();
			    break;
			    case 3:
			    float x3;
			    x3 = (bs->getx()*g/sin(30*0.017));
			    players[i].hardbot(x3);
			    balls[i].setrad(0.1);
			    players[i].setmoney(players[i].getmoney() - 50);
			    players[i].showplayer();
			    default:
			    cout << "Error, enter 1, 2 or 3" << endl;
			    break;
			}
		}
	}
	int gamestart(int n, int bn, vector<player>& players, base *bs, vector<ball>& balls){
		for (int i = 0; i < (n+bn); i++){ 
			if(((players[i].getres()-balls[i].getrad()) < (bs->getx()+bs->getd())) && ((players[i].getres()+balls[i].getrad()) > (bs->getx()-bs->getd()))){
				cout << "Good hit, " << players[i].getname() <<" money is yours" << endl; 
				players[i].setmoney(players[i].getmoney() + bank); 
				bank=0; 
			}
		} 
		if (bank != 0){
			vector <float> winrange(n+bn);
			float min;
			for (int i = 0; i < (n+bn); i++){
				if(((players[i].getres()+balls[i].getrad()) < bs->getx()-bs->getd())){
					winrange[i] = (bs->getx()-bs->getd()) - players[i].getres();
				}
				else{
					winrange[i] = players[i].getres() - (bs->getx()+bs->getd());	
				}
			}
			for (int i = 1; i < (n+bn); i++){
				min = winrange[0];
				if(winrange[i-1] > winrange[i])
					min = winrange[i];
			}
			for (int i = 0; i < (n+bn); i++){
				if(winrange[i] == min)
					cout << "Winner is " << players[i].getname() << endl; 
					players[i].setmoney(players[i].getmoney() + bank); 
					bank=0;
			}
		}
	}
};
int main(){
int choice;
int num;
int botnum;
base bs;
	cout << "How many players?" << endl; 
	cin >> num;
	cout << "Any bots?" << endl <<"1: Yes" << endl << "2: No"<< endl;
	cin >> choice;
	switch(choice){
	    case 1:
	    cout << "How many?" << endl;
	    cin >> botnum;
	    break;
	    case 2:
	    "Okay";
	    botnum = 0;
	    break;
	    default:
	    cout << "Error, enter 1 or 2" << endl;
	    break;
	}
vector<player> players(num+botnum);
vector<ball> balls(num+botnum);
game gm;
	gm.gameinit(num, botnum, players, balls);
	if(botnum !=0){
		gm.botinit(num, botnum, players, &bs, balls);
	}
	cout << "Game started" << endl;
	gm.gamestart(num, botnum, players, &bs, balls);
    cout << "Another match?" << endl <<"1: Yes" << endl << "2: No"<< endl;
	cin >> choice;
	switch(choice){
	    case 1:
	    gm.gameinit(num, botnum, players, balls);
	    if(botnum !=0){
	        gm.botinit(num, botnum, players, &bs, balls);
	    }
		gm.gamestart(num, botnum, players, &bs, balls);
	    break;
	    case 2:
	    "Okay";
	    break;
	    default:
	    cout << "Error, enter 1 or 2" << endl;
	    break;
	}
}
}

