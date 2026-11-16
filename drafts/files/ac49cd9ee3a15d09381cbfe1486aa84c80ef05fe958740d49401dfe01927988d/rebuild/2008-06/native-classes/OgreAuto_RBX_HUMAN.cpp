// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/AppUnit664/HumanoidForceLimits.h"

namespace RBX {
G3D::Vector3 HUMAN::maxMoveForce()
{
	static G3D::Vector3 v(1000.0f, 10000.0f, 1000.0f);
	return v;
}
}

namespace RBX {
G3D::Vector3 HUMAN::minMoveForce()
{
    static G3D::Vector3 value(-1000.0f, 0.0f, -1000.0f);
    return value;
}
}

