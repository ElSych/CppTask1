#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
using namespace std;
    class Flower{
      int x;
      int y;
    public:
      Flower();
      float getx();
      float gety();
      void putx(int x0);
      void puty(int y0);
    };
