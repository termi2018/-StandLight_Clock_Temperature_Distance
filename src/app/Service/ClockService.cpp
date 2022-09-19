#include "ClockService.h"

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    timerState = 0;
    clockView = view;
}

ClockService::~ClockService()
{}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    if(!timerState)
    {
        clockView->updateTime(timeDate);
    }
    else
    {
        clockView->lcdTimer();
    }
}

void ClockService::updateTimer()
{
    timerState = !timerState;
}