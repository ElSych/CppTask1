#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
int g = 9.8;
class player{
	public:
	char name[15];
	int money;
	int sp;
	float a;
	int res;
	public:
	player(){
        cout << "Enter name:" << endl; 
        cin >> name;
        cout << "Enter money:" << endl;
        cin >> money;
	}
	void showplayer(){
        cout << "Name:" << name << endl;
        cout << "Money:" << money << endl;
        cout << "Speed:" << sp << endl;
        cout << "Angle:" << a << endl;
    }
};
class base{
	int bank;
	public:
	float x;
	float d;
	public:
	int hit(int n, player *arr[]){
	    for (int i = 0; i < n; i++){
	    bank += arr[i]->money;
	    arr[i]->money = 0;
		if((arr[i]->res < x+d) && (arr[i]->res > x-d)){
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
int initbase(base b){
    srand(time(NULL));
    b.x = rand()%100 + 10;
    b.d = b.x*0.02;
    cout << "Range is " << b.x << endl;
    cout << "Area is " << b.d << endl;
}
int location(int speed, float angle, int n, player *arr[]){
    for (int i = 0; i < n; i++){
	arr[i]->res = 2*speed*sin(angle*0.017)/g;
    }
    }
int main(){
	int num;
	base bs;
	cout << "How many players?" << endl;
	cin >> num;
	player *mas = new player[num];
	initbase(bs);
    for (int i = 0; i < num; i++){
        cout << "Enter speed:" << endl;
        cin >> mas[i].sp;
        cout << "Enter angle:" << endl;
    	cin >> mas[i].a;
        cout << "Player " << i << ":" << endl;
        double r;
        srand(time(NULL));
        r=(rand()%110 + 90)/(100*1.0);
        mas[i].sp *= r;
        mas[i].showplayer();
        cout << endl;
    };
    cout << "Game started" << endl;
    for (int j = 0; j < num; j++){
    location(mas[j].sp, mas[j].a, num, &mas);
	bs.hit(num, &mas);
	};
}
