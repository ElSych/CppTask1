#include "Lamp.hpp"
    string Lamp:: getmode(){
      return mode;
    }
    void Lamp:: switchmode(int onoff){
      if (onoff==1)
        mode = "ON";
      else
        mode = "OFF";
    }
    void Lamp:: show(){
     cout << "Lamp is " << mode << endl; 
    }
