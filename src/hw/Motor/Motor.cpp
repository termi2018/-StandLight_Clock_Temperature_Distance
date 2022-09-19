#include "Motor.h"
#include <wiringPi.h>
#include <softPwm.h>

Motor::Motor(int pin) 
    : pinNumber(pin)
{
    wiringPiSetup();
    softPwmCreate(pin, 0, 100);
}

Motor::~Motor()
{

}

void Motor::mOnOff(int ps)           // ps : persent, dl : delay
{
    softPwmWrite(pinNumber, ps); // duty : ps%
}