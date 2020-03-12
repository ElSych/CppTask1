#pragma once

#include "MyMosq.hpp"
#include "Lamp.hpp"
#include "Cloud.hpp"
#include "Sun.hpp"
#include "Flower.hpp"
#include <thread>
using namespace MQTTW;
namespace MQTTFlower{
    void MQTTFlowerLoop(MyMosq* MQTT)
    void InitMQTT(MyMosq* MQTT);
    void SendData(Lamp* lamp, Sun* sun, MyMosq* MQTT);
}
