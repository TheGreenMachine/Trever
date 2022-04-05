#ifndef DEADZONE_FILTER_H
#define DEADZONE_FILTER_H
#include "GamepadFilter.h"

class DeadzoneFilter: public GamepadFilter
{
public:
    float LeftX(float x)
    {
        return coerceInRange(x);
    }
    float LeftY(float x)
    {
        return coerceInRange(x);
    }
    float RightX(float x)
    {
        return coerceInRange(x);
    }
    float RightY(float x)
    {
        return coerceInRange(x);
    }
private:
    float coerceInRange(float x)
    {
        return x < 0.1 && x > -0.1 ? 0 : x;
    }
};
#endif

