// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 util/Face.cpp rows (inactive): Face::snapToGrid 006497e0, Face::toWorldSpace 00649970 and
// Face::toObjectSpace 00649af0, declared by util/Face.h (four Vector3 corners c0..c3, 0x30 bytes: both space
// conversions zero all twelve floats of the returned Face (Face() inline) before writing the corners).
#include "util/Face.h"
#include "util/Math.h"

namespace RBX
{
	// The 2008 binary has no out-of-line Face::operator[] (no row in the identity registry; snapToGrid 006497e0 steps a
	// corner pointer by 0xc inside its loop and toWorldSpace / toObjectSpace address c0..c3 directly), so the 2008
	// header defined both accessors inline. The donor util/Face.h only declares them (header proposal); they are
	// defined inline here, before their first use, with the donor body.
	inline const G3D::Vector3& Face::operator[](int i) const
	{
		return ((G3D::Vector3*)this)[i];
	}

	inline G3D::Vector3& Face::operator[](int i)
	{
		return ((G3D::Vector3*)this)[i];
	}

	// 006497e0: Math::toGrid(Vector3, float) 005dee90 for each of the four corners
	void Face::snapToGrid(float grid)
	{
		for (int i = 0; i < 4; ++i)
		{
			G3D::Vector3& v = (*this)[i];
			v = Math::toGrid(v, grid);
		}
	}

	// 00649970: CoordinateFrame::pointToWorldSpace inline
	Face Face::toWorldSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
		{
			face[i] = objectCoord.pointToWorldSpace((*this)[i]);
		}
		return face;
	}

	// 00649af0: CoordinateFrame::pointToObjectSpace inline
	Face Face::toObjectSpace(const G3D::CoordinateFrame& objectCoord) const
	{
		Face face;
		for (int i = 0; i < 4; ++i)
		{
			face[i] = objectCoord.pointToObjectSpace((*this)[i]);
		}
		return face;
	}
}
