#ifndef TREVER_H
#define TREVER_H
#include "WPILib.h"
#include "Components.h"

class Trever: public SimpleRobot
{
public:
    Trever();
    void Autonomous();
    void OperatorControl();
    void MechanismSet();
private:
    float speedMove;
    float speedRotate;
    static const double AUTO_DRIVE_TIME = 1.0;
    static const double AUTO_ROTATE_TIME = 5.0;
};
#endif
