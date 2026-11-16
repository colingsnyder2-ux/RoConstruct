// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /GS-
#include "../native-headers/v8datamodel/Tool.h"

namespace RBX {
void Tool::setGripUp(const G3D::Vector3& v)
{
	G3D::CoordinateFrame c = grip;
	G3D::Vector3 col0 = c.rotation.getColumn(0);
	G3D::Vector3 oldZ = c.rotation.getColumn(2);

	G3D::Vector3 y = v.direction();
	G3D::Vector3 yc = y;
	G3D::Vector3 oldX = col0;

	G3D::Vector3 z = oldX.cross(yc);
	z.unitize();

	G3D::Vector3 yy = y;
	G3D::Vector3 zc = z;
	G3D::Vector3 x = yy.cross(zc);
	x.unitize();

	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);

	setGrip(c);
}
}

namespace RBX {
void Tool::setGripRight(const G3D::Vector3& v)
{
	G3D::CoordinateFrame c = grip;
	G3D::Vector3 col1 = c.rotation.getColumn(1);
	G3D::Vector3 oldZ = c.rotation.getColumn(2);

	G3D::Vector3 x = v.direction();
	G3D::Vector3 xc = x;
	G3D::Vector3 oldY = col1;

	G3D::Vector3 z = xc.cross(oldY);
	z.unitize();

	G3D::Vector3 xx = x;
	G3D::Vector3 zc = z;
	G3D::Vector3 y = zc.cross(xx);
	y.unitize();

	c.rotation.setColumn(0, x);
	c.rotation.setColumn(1, y);
	c.rotation.setColumn(2, z);

	setGrip(c);
}
}

