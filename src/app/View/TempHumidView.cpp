#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *lcd, Motor *motor, View *view)
{
    this->view = view;
    this->lcd = lcd;
    this->motor = motor;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char buff[30];
    sprintf(buff, "%.1f'C%%", temp);
    lcd->WriteStringXY(0, 10, buff);     //0, 10
    sprintf(buff, "%.1f%%", humid);
    lcd->WriteStringXY(1, 10, buff);     //0, 10

    printf("motorState : %d\n", view->getMotor());
    if(temp > 31)
    {
        view->setMotor(1);
    }
    else {
        view->setMotor(0);
    }

    printf("%.1f'C, %.1f%%\n",temp, humid);
}
