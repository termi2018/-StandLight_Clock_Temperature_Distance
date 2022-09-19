#ifndef __TEMPHUMIDVIEW_H__
#define __TEMPHUMIDVIEW_H__

#include "LCD.h"
#include "Motor.h"
#include "View.h"

class TempHumidView
{
private:
    LCD *lcd;
    View *view;
    Motor *motor;

public:
    TempHumidView(LCD *lcd, Motor *motor, View *view);
    virtual ~TempHumidView();
    void setTempHumidData(float temp, float humid);
};

#endif /* __TEMPHUMIDVIEW_H__ */