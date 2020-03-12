#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
using namespace std;
    class Sun{
      float angle;
      int rad;
    public:
      sun();
      float getangle();
      int getrad();
      void putangle(float a);
      void putrad(int r);
      void sunposition();
    };
