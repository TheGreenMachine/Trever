#include "Drivetrain.h"\

Drivetrain::Drivetrain(int leftJaguar, int rightJaguar) :
	drivetrain(leftJaguar, rightJaguar)
{
	drivetrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	drivetrain.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
}

void Drivetrain::SetSpeed(double move, double rotate)
{
	drivetrain.ArcadeDrive(move, rotate);
}
