#include "MyMQTT.hpp"
#include <thread>
#include <string>
namespace MQTTFlower{
    void MQTTFlowerLoop(MyMosq* MQTT){
        MQTT->loop_forever();
    }
    void InitMQTT(MyMosq* MQTT){
        mosqpp::lib_init();
        std::thread t = std::thread(MQTTFlowerLoop, MQTT);
        t.detach();
    }
    void SendData(Lamp* lamp, Sun* sun, MyMosq* MQTT){
        std::string sunangle = "Солнце под углом " + std::to_string(sun->angle);
        std::string lampmode = "Lamp is " + lamp->getmode();
        MQTT->send_message(sunangle.c_str());
        MQTT->send_message(lampmode.c_str());
    }
}
