#ifndef COMPONENTS_H
#define COMPONENTS_H
#include "utils.h"
#include "WPILib.h"
#include "Drivetrain.h"


class Components
{
public:
	static Components& getInstance()
	{
		static Components instance;
		return instance;
	}

	Drivetrain drivetrain;
	FilteredGamepad gamepad;


private:
	static const unsigned short GAMEPAD_PORT = 1;
	static const unsigned short LEFT_JAGUAR = 1;
	static const unsigned short RIGHT_JAGUAR = 2;

	Components() :
		drivetrain(LEFT_JAGUAR, RIGHT_JAGUAR),
		gamepad(GAMEPAD_PORT)
	{
		DeadzoneFilter* df = new DeadzoneFilter();
		gamepad.addFilter(smartptr<GamepadFilter>(df));

		PowerFilter* sf = new PowerFilter(2);
		gamepad.addFilter(smartptr<GamepadFilter>(sf));
	}
};
#endif
