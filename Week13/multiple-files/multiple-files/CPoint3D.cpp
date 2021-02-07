#include "CPoint3D.h"

CPoint3D::CPoint3D()
{
	Set3DPoints(gkfX, gkfY, gkfZ);
}

CPoint3D::CPoint3D(const float x, const float y, const float z)
{
	SetPoints(x, y);
	mfZ = z;
}

void CPoint3D::Get3DPoints(float& x, float& y, float& z)
{
	GetPoints(x, y);
	z = mfZ;
}

void CPoint3D::Set3DPoints(const float x, const float y, const float z)
{
	SetPoints(x, y);
	mfZ = z;
}