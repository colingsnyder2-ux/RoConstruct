// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../../../tools/rbxgs/Client/App/include/util/Face.h"

namespace RBX {
void Face::minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const
{
	min = 1.0e10;
	max = -1.0e10;
	for (int i = 0; i < 4; ++i)
	{
		const G3D::Vector3& v = (&c0)[i];
		G3D::Vector3 d = v - point;
		float temp = d.x * normal.x;
		temp += d.y * normal.y;
		temp += d.z * normal.z;
		min = G3D::min(min, temp);
		max = G3D::max(max, temp);
	}
}
}
