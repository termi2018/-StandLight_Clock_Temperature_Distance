#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
    distanceOffCounter = 0;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            // if (strState == "powerButton") {
            //     lightState = LIGHT_OFF;
            // }
            if(bDistanceLight){
                view->setState(lightState);
            } else { //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            // if (strState == "powerButton") {
            //     lightState = LIGHT_OFF;
            // }
            if(bDistanceLight){
                view->setState(lightState);
            } else { //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            // if (strState == "powerButton") {
            //     lightState = LIGHT_OFF;
            // }
            if(bDistanceLight){
                view->setState(lightState);
            } else { //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            // if (strState == "powerButton") {
            //     lightState = LIGHT_OFF;
            // }
            if(bDistanceLight){
                view->setState(lightState);
            } else { //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            // if (strState == "powerButton") {
            //     lightState = LIGHT_OFF;
            // }
            if(bDistanceLight){
                view->setState(lightState);
            } else { //거리 범위 밖
                view->setState(LIGHT_OFF);
            }
        break;
    }

    if (strState == "fanOnOffButton") {
        motorState = !motorState;
        view->setMotor(motorState);
    }
}

void Service::updateDistance(int distance)
{
    if(distance < 0)
    {
        //light off
        distanceOffCounter++;
        if(distanceOffCounter >= 10)
        {
            bDistanceLight = false;
            view->setState(LIGHT_OFF);
        }
    } else {
        //light on
        distanceOffCounter = 0;
        bDistanceLight = true;
        view->setState(lightState);
    }
    //printf("distance : %d, %d\n", distance, distanceOffCounter);
}