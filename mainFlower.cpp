#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
using namespace std;
class flower{
  int x;
  int y;
public:
  flower(){
    x = 0;
    y = 0;
  }
  float getx(){
    return x;
  }
  float gety(){
    return y;
  }
  void putx(int x0){
    x=x0;
  }
  void puty(int y0){
    y=y0;
  }
};
class lamp{
  string mode;
public:
  string getmode(){
    return mode;
  }
  void switchmode(int onoff){
    if (onoff==1)
      mode = "ON";
    else
      mode = "OFF";
  }
  void show(){
   cout << "Lamp is " << mode << endl; 
  }
}
void lampmode(cloud &c, sun &s, flower &f, lamp &l){
  int x1 = c.getx();
  int y1 = y2 = c.gety();
  int x2 = x1 + c.getlengh();
  float k = tan (s.getangle()*3.14/180);
  if(((y1-k*x1)*(y2-k*x2)) <= 0 ){
    l.switchmode(1);
  }
  else
    l.switchmode(0);
}
int main(){
  cloud cld;
  sun sun;
  flower flw;
  lamp lmp;
  sf::Thread threadsun(&sun::sunposition, &sun);
  sf::Thread threadcloud(&cloud::cloudposition, &cld);
  sf::Thread threadlamp(lampmode, cld, sun, flw, lmp);
  threadsun.launch();
  threadcloud.launch();
  threadlamp.launch();
  do{
   if ((int t=clock()/CLOCKS_PER_SEC)%10==0)
     l.show();
  }
  while (t=clock()/CLOCKS_PER_SEC<200);
}
