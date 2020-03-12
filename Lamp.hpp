#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
using namespace std;
    class Lamp{
      string mode;
    public:
      string getmode();
      void switchmode(int onoff);
      void show();
    };
