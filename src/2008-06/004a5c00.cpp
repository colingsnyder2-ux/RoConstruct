// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>

// RBX::Network::isBrickLocation (2008-06 Networking/Streaming.cpp), self-contained:
// only the G3D::Vector3 field layout (x,y,z at +0,+4,+8) matters for the codegen.
// The 2008-06 build compares v.y against a float literal: the double 204.8 is
// folded to a float compare, and x87 keeps the products in extended precision.
struct Vector3
{
	float x;
	float y;
	float z;
};

static __declspec(noinline) bool brickEq(float a, float b)
{
	return a == b || fabs(a - b) <= 0.0005f;
}

static bool isBrickLocation(const Vector3& v, short& x, unsigned short& y, short& z)
{
	if (v.x >= 512.0f)
		return false;

	if (v.x <= -512.0f)
		return false;

	if (v.z >= 512.0f)
		return false;

	if (v.z <= -512.0f)
		return false;

	if (v.y >= 204.8f)
		return false;

	if (v.y < 0.0f)
		return false;

	float dx = v.x * 2.0f;
	x = (short)dx;

	if ((float)x != dx)
		return false;

	float dz = v.z * 2.0f;
	z = (short)dz;

	if ((float)z != dz)
		return false;

	float dy = v.y * 10.0f;
	y = (unsigned short)dy;

	if (!brickEq((float)y, dy))
		return false;

	return true;
}

// Keeps the internal-linkage definition above alive without changing its body.
bool isBrickLocationEntry(const Vector3& v, short& x, unsigned short& y, short& z)
{
	return isBrickLocation(v, x, y, z);
}