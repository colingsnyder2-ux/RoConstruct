// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../../../tools/rbxgs/Client/App/include/util/Math.h"

namespace RBX {
const G3D::Matrix3& Math::getAxisRotationMatrix(int face)
{
	static G3D::Matrix3 y = G3D::Matrix3::fromEulerAnglesXYZ(0, 0, G3D::halfPi());
	static G3D::Matrix3 z = G3D::Matrix3::fromEulerAnglesXYZ(0, G3D::halfPi(), 0);
	static G3D::Matrix3 y_neg = G3D::Matrix3(y);
	static G3D::Matrix3 z_neg = G3D::Matrix3(z);

	switch (face)
	{
	case 0:
		return G3D::Matrix3::identity();
	case 1:
		return y;
	case 2:
		return z;
	case 4:
		return y_neg;
	case 5:
		return z_neg;
	default:
		return G3D::Matrix3::identity();
	}
}
}
