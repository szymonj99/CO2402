#pragma once
#include "CPoint.h"

class CPoint3D : public CPoint
{
private:
	float mfZ;

public:
	CPoint3D();
	CPoint3D(const float x, const float y, const float z);
	void Set3DPoints(const float x, const float y, const float z);
	void Get3DPoints(float& x, float& y, float& z);
};