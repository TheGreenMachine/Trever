#include "FilteredGamepad.h"

typedef std::vector<smartptr<GamepadFilter> >::iterator iter;

float FilteredGamepad::GetLeftX()
{
	float result = GamepadL::GetLeftX();
	for (iter i = filters.begin(); i != filters.end(); ++i)
	{
		result = (*i)->LeftX(result);
	}
	return result;
}

float FilteredGamepad::GetLeftY()
{
	float result = GamepadL::GetLeftY();
	for (iter i = filters.begin(); i != filters.end(); ++i)
	{
		result = (*i)->LeftY(result);
	}
	return result;
}

float FilteredGamepad::GetRightX()
{
	float result = GamepadL::GetRightX();
	for (iter i = filters.begin(); i != filters.end(); ++i)
	{
		result = (*i)->RightX(result);
	}
	return result;
}

float FilteredGamepad::GetRightY()
{
	float result = GamepadL::GetRightY();
	for (iter i = filters.begin(); i != filters.end(); ++i)
	{
		result = (*i)->RightY(result);
	}
	return result;
}

