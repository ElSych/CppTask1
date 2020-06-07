#include <iostream>
using namespace std;
class door {
  class State *current;
  public:
    door(){
      current = new OFF();
      cout << '\n';
    };
    void setCurrent(State *s){
        current = s;
    }
    void on(){
      current->on(this);
    }
    void off(){
      current->off(this);
    }
};
 
class State {
  public:
    virtual void on(door *m) {
        cout << "   already ON\n";
    }
    virtual void off(door *m) {
        cout << "   already OFF\n";
    }
};
 
class ON: public State {
  public:
    ON() {
        cout << "ON-constructor\n";
    };
    ~ON() {
        cout << "destructor-ON\n";
    };
    void off(door *m){
      cout << "   going from ON to OFF\n";
      m->setCurrent(new OFF());
      delete this;
};
};
 
class OFF: public State {
  public:
    OFF() {
        cout << "OFF-constructor\n";
    };
    ~OFF() {
        cout << "destructor-OFF\n";
    };
    void on(door *m){
        cout << "going from OFF to ON\n";
        m->setCurrent(new ON());
        delete this;
    }
};