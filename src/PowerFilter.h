#ifndef POWER_FILTER_H
#define POWER_FILTER_H
#include "GamepadFilter.h"
#include <cstdlib>
#include <cmath>

class PowerFilter: public GamepadFilter
{
public:
	PowerFilter(float p)
	{
		power = p;
	}
    float LeftX(float x)
    {
    	return pow(abs(x),power)*sign(x);
    }
    float LeftY(float x)
    {
    	return pow(abs(x),power)*sign(x);
    }
    float RightX(float x)
    {
    	return pow(abs(x),power)*sign(x);
    }
    float RightY(float x)
    {
    	return pow(abs(x),power)*sign(x);
    }

private:
    float power;
    template <typename T> int sign(T val)
    {
    	return (T(0) < val) - (val < T(0));
    }
};
#endif


