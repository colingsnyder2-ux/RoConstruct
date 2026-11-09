// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 Extents methods recovered from Mew fork 5fe2214e131d.
#include "util/Extents.h"
namespace RBX
{
	NormalId Extents::closestFace(const G3D::Vector3& point)
	{
		NormalId faceId = NORM_X;

		float hy = fabs(point.y - this->high.y);
		float hz = fabs(point.z - this->high.z);
		float lx = fabs(point.x - this->low.x);
		float ly = fabs(point.y - this->low.y);
		float lz = fabs(point.z - this->low.z);

		float hx = fabs(point.x - this->high.x);
		if (hx > hy)
		{
			faceId = NORM_Y;
		}
		else
		{
			hy = hx;
		}

		if (hz < hy)
		{
			hy = hz;
			faceId = NORM_Z;
		}

		if (lx < hy)
		{
			hy = lx;
			faceId = NORM_X_NEG;
		}

		if (ly < hy)
		{
			hy = ly;
			faceId = NORM_Y_NEG;
		}

		if (lz < hy)
		{
			faceId = NORM_Z_NEG;
		}

		return faceId;
	}

	G3D::Vector3 Extents::getCorner(int i) const
	{
		return G3D::Vector3(
			this->low[0 + 3 * (i / 4)],
			this->low[1 + 3 * (i / 2 % 2)],
			this->low[2 + 3 * (i % 2)]
		);
	}

	G3D::Vector3 Extents::faceCenter(NormalId faceId) const
	{
		G3D::Vector3 v = this->center();

		int i = faceId % 3;
		if (faceId < NORM_X_NEG)
		{
			v[i] = this->high[i];
		}
		else
		{
			v[i] = this->low[i];
		}

		return v;
	}

	Extents Extents::vv(const G3D::Vector3& v0, const G3D::Vector3& v1)
	{
		Extents result;

		result.low = v0.min(v1);
		result.high = v0.max(v1);

		return result;
	}
}
