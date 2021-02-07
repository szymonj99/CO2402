#pragma once
#include "Globals.h"

class CPoint
{
private:
	float mfX;
	float mfY;

public:
	CPoint();
	CPoint(const float x, const float y);
	void SetPoints(const float x, const float y);
	void GetPoints(float& x, float& y);
};