// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// util/Face.cpp rows (inactive): Face::snapToGrid 006497e0, Face::toWorldSpace 00649970, Face::toObjectSpace 00649af0.
// The binary has no out-of-line Face::operator[], so both accessors are defined inline here.
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

	// 006497e0
	void Face::snapToGrid(float grid)
	{
		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3& v = (*this)[i];
			v = Math::toGrid(v, grid);
		}
	}

	// 00649970
	Face Face::toWorldSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
			face[i] = objectCoord.pointToWorldSpace((*this)[i]);
		return face;
	}

	// 00649af0
	Face Face::toObjectSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
			face[i] = objectCoord.pointToObjectSpace((*this)[i]);
		return face;
	}
}
