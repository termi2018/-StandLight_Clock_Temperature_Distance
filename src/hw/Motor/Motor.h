#ifndef MOTOR_H
#define MOTOR_H

#pragma once

class Motor
{
private:
    int pinNumber;

public:
    Motor(int pin);
    ~Motor();
    void mOnOff(int ps);
};

#endif