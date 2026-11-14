// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	inline const G3D::Vector3& Face::operator[](int i) const
	{
		return ((G3D::Vector3*)this)[i];
	}

	inline G3D::Vector3& Face::operator[](int i)
	{
		return ((G3D::Vector3*)this)[i];
	}

	void Face::snapToGrid(float grid)
	{
		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3& v = (*this)[i];
			v = Math::toGrid(v, grid);
		}
	}

	Face Face::toWorldSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
			face[i] = objectCoord.pointToWorldSpace((*this)[i]);
		return face;
	}

	Face Face::toObjectSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
			face[i] = objectCoord.pointToObjectSpace((*this)[i]);
		return face;
	}
}
