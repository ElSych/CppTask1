#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
#include "MQTTFlowerLamp.hpp"
using namespace std;
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
  MyMosq* MyMQTT = new MyMosq("flower", "test.mosquitto.org", 1883);
  InitMQTT(MyMQTT);
  do{
   if ((int t=clock()/CLOCKS_PER_SEC)%10==0)
     SendData(lamp, sun, MyMQTT);
  }
  while (t=clock()/CLOCKS_PER_SEC<200);
    delete lamp;
}
