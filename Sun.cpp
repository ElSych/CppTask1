#include "Sun.hpp"
  Sun :: Sun(){
    angle = 0;
    rad = 1000;
  }
  float Sun :: getangle(){
    return angle;
  }
  int Sun :: getrad(){
    return rad;
  }
  void Sun :: putangle(float a){
    angle = a;
  }
  void Sun :: putrad(int r){
    rad = r;
  }
  void Sun :: sunposition(){
    for(int i=1; i<180; i++){
      sleep(1);
    }
  }
};
