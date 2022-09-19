#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "ClockCheck.h"
#include "Controller.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"

class Listener
{
private :
    Button *modeButton;
    Button *powerButton;
    Button *fanOnOffButton;
    ClockCheck *clockCheck;
    Controller *controller;
    DHT11 *dht11;
    UltraSonic *ultrasSonic;

public:
    Listener(Button *modeButton, Button *powerButton, Button *fanOnOffButton,
             Controller *control, ClockCheck *clock, DHT11 *dht11,
             UltraSonic *ultrasSonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */
