#include "/usr/local/include/mosquittopp.h"
#include "MyMosq.hpp"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <locale>
#include <vector>
#include <string>
namespace MQTTW{
   myMosq::myMosq(const char *id, const char *host, int port) : mosquittopp(id){
      int keepalive = 60;
      connect(host, port, keepalive);
      printf("Создал MQTT\n");
       };
    };
    myMosq::~myMosq() {
      loop_stop();
      mosqpp::lib_cleanup();
    }
    bool myMosq::send_message(const  char * message){
     int ret = publish(NULL,"M30-212B-18/Game",(int)strlen(message),message,2,false);
       return ( ret == MOSQ_ERR_SUCCESS );
    }
    void myMosq::on_connect(int rc){
     if (rc == 0){
       subscribe(NULL, "M30-212B-18/FlowerLamp");
     }
   }
     else {
      std::cout << ">> myMosq - Impossible to connect with server(" << rc << ")" << std::endl;
     }
    }
    void myMosq::on_publish(const struct mosquitto_message *message){
      setlocale(LC_CTYPE, "rus");
      if(!strcmp(message->topic, "M30-212B-18/FlowerLamp")){
         std::cout<<message->payload<<std::endl;
      }
    }
}
