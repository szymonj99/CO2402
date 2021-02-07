#include "CPoint.h"

#pragma once

CPoint::CPoint()
{
	mfX = gkfX;
	mfY = gkfY;
}

CPoint::CPoint(const float x, const float y)
{
	mfX = x;
	mfY = y;
}

void CPoint::SetPoints(const float x, const float y)
{
	mfX = x;
	mfY = y;
}

void CPoint::GetPoints(float& x, float& y)
{
	x = mfX;
	y = mfY;
}