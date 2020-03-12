#include <iostream>
#include <cmath>
#include <ctime>
#include <SFML/System.hpp>
#include <string>
using namespace std;
  class Cloud{
    float lengh;
    int x;
    int y;
    int windspeed;
  public:
    cloud();
    float getlengh();
    float getx();
    float gety();
    void putx(int x0);
    void puty(int y0);
    void cloudposition();
  };
