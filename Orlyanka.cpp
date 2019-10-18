#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstdlib> 
using namespace std; 
const float g = 9.8;
class ball;
class base;
class game;
class player{
	int money;
public: 
	string name;
	int res;
public:
		friend ball;
		friend game;
	player(){
		cout << "Enter name:" << endl;
		cin >> name;
		money = 100; 
		}
	void showplayer(){ 
		cout << "Name: " << name << endl; 
		cout << "Money: " << money << endl; 
	}
	};
class ball{
public:
	float rad;
	float angle;
	float speed;
public:
	int ballsize(player *arr[], int i){
		int size;
		cout << "Choose ball:" << endl << "1: small: 0.04m rad, price: free"<< endl << "2: medium: 0.07m rad, price: 10"<< endl << "3: big: 0.1m rad, price: 15" << endl;
		cin >> size;
		switch(size){
			case 1:
			rad = 0.04;
			break;
			case 2:
			rad = 0.07;
			arr[i]->money -=10;
			break;
			case 3:
			rad = 0.1;
			arr[i]->money -=15;
			break;
		}
	}
	int result(player *arr[], int i){
		cout << "Player №" << i << ", enter speed:" << endl; 
		cin >> speed; 
		cout << "Player №" << i << ", enter angle:" << endl; 
		cin >> angle; 
		arr[i]->res = speed*speed*sin(2*angle*0.017)/g;
	}
};
class base{ 
public: 
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
}; 
class game{
        int bank;
public:
	game(int n, player *arr[], base *bs, ball *balls[]){
                for (int i = 0; i < n; i++){
			bank += arr[i]->money; 
			arr[i]->money -= 50;
		}
		for (int i = 0; i < n; i++){ 
		if(((arr[i]->res-balls[i]->rad) < bs->x+bs->d) && ((arr[i]->res+balls[i]->rad) > bs->x-bs->d)){ 
			cout << "Good hit, money is yours" << endl; 
			arr[i]->money += bank; 
			bank=0; 
		} 
		else{ 
			cout << "Try again later" << endl; 
			}; 
		} 
		if (bank != 0) 
		cout << "There is no winner" << endl;
	}
}; 
int main(){
int choice;
int num;
	cout << "How many players?" << endl; 
	cin >> num;
player *players = new player[num];
ball *balls = new ball[num];
base bs();
  gamestart:
	for (int i = 0; i < num; i++){
		balls[i].ballsize(&players, i);
		balls[i].result(&players, i);
		cout << "Player " << i << ":" << endl;
		players[i].showplayer();
		cout << endl; 
double chance; 
  srand(time(NULL)); 
	chance=(rand()%105 + 95)/(100*1.0); 
	balls[i].speed *= chance; 
	}; 
 cout << "Game started" << endl; 
 game gm(num, &players, &bs, &balls);
    cout << "Another match?" << endl <<"1: Yes" << endl << "2: No"<< endl;
	cin >> choice;
	switch(choice){
	    case 1:
	    goto gamestart;
	    break;
	    case 2:
	    "Okay";
	    delete []players;
	    delete []balls;
	    break;
	}
}


