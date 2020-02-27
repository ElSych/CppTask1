#include <iostream>
#include <cmath>
#include <ctime> 
using namespace std;

class cloud{
  float lengh;
  int x;
  int y;
public:
  float getlengh(){
    return lengh;
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
class sun{
  float angle;
  int rad;
public:
  sun(){
    angle = 0;
    rad = 1000;
  }
  float getangle(){
    return angle;
  }
  int getrad(){
    return rad;
  }
  void putangle(float a){
    angle = a;
  }
  void putrad(int r){
    rad = r;
  }
  int sunposition(){
  }
};

class flower {
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

int main(){
  cloud cloud;
  sun sun;
  flower flower;
  
}
