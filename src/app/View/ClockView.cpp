#include "ClockView.h"

ClockView::ClockView(LCD *lcd)
{
    timer=0;
    this->lcd = lcd;
    //timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "         ");
    lcd->WriteStringXY(1, 0, buff);

    sprintf(buff, "%02d:%02d:%02d",
            timeData->tm_hour,
            timeData->tm_min,
            timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}

void ClockView::lcdTimer()
{
    char buff[30];
    
    if(timer >= 1000)
    {
        timer = 0;
    }

    //printf("%d\n", timer);
    sprintf(buff, "Timer:%3d", timer++);
    lcd->WriteStringXY(1, 0, buff);
}
