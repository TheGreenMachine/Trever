#ifndef FILTEREDGAMEPAD_H
#define FILTEREDGAMEPAD_H
#include "GamepadL.h"
#include "GamepadFilter.h"
#include "smartptr.h"
#include <vector>

class FilteredGamepad : GamepadL
{
public:
	FilteredGamepad(unsigned int port) : GamepadL(port)
	{
	}

	void addFilter(smartptr<GamepadFilter> filter)
	{
		filters.push_back(filter);
	}

	virtual float GetLeftX();
	virtual float GetLeftY();
	virtual float GetRightX();
	virtual float GetRightY();
private:
	std::vector<smartptr<GamepadFilter> > filters;
};
#endif
