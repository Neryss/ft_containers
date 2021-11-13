#pragma once

#include <cstdlib>

struct cmpValues
{
	bool operator()(const int &a, const int &b) const
	{
		// return a < b;
		return a > b;
	}
};