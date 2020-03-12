#include "Cloud.hpp"

    Cloud :: Cloud(){
      х = rand() % 61 - 30;
      y = 5 + rand() % 11;
      lengh = y = 5 + rand() % 6;
      windspeed = rand() % 11 - 5;
    }
    float Cloud :: getlengh(){
      return lengh;
    }
    float Cloud :: getx(){
      return x;
    }
    float Cloud :: gety(){
      return y;
    }
    void Cloud :: putx(int x0){
      x=x0;
    }
    void Cloud :: puty(int y0){
      y=y0;
    }
    void Cloud :: cloudposition(){
      if(windspeed<0){
        do{
          x += windspeed;
        }
        while (x!=-40);
        windspeed *= -1;
      }
      else{
        do{
          x += windspeed;
        }
        while (x!=40);
        windspeed *= -1;
      }
     cloudposition();
    }
  };
