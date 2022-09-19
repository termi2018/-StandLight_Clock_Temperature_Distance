#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *modeButton, Button *powerButton, Button *fanOnOffButton,
Controller *control, ClockCheck *clock, DHT11 *dht11,
UltraSonic *ultrasSonic)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->fanOnOffButton = fanOnOffButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultrasSonic = ultrasSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (fanOnOffButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("fanOnOffButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if (millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltraSonicTime = 0;
    if (millis() - prevUltraSonicTime > 1000)
    {
        prevUltraSonicTime = millis();
        int distance = ultrasSonic->readDistance();
        controller->updateDistance(distance);
    }
}