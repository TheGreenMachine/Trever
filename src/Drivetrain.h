#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "WPILib.h"

class Drivetrain
{
public:
	Drivetrain(int leftJaguar, int rightJaguar);
	void SetSpeed(double move, double rotate);
	virtual ~Drivetrain() {}

private:
	RobotDrive drivetrain;
};
#endif
