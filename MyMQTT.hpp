#pragma once

#include "MyMosq.hpp"
#include "Lamp.hpp"
#include "Cloud.hpp"
#include "Sun.hpp"
#include <thread>
    void InitMQTT(MyMosq* MQTT);
    void SendData(Lamp* lamp, Sun* sun, MyMosq* MQTT);
