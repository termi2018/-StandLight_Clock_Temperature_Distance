#ifndef __CLOCKSERVICE_H__
#define __CLOCKSERVICE_H__

#include <time.h>
#include "ClockView.h"

class ClockService
{
private:
    int timerState;
    time_t curTime;
    ClockView *clockView;

public:
    ClockService(ClockView *view);
    virtual ~ClockService();
    void updateEvent();
    void updateTimer();
};

#endif /* __CLOCKSERVICE_H__ */