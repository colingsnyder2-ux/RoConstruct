// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 Extents methods recovered from Mew fork 5fe2214e131d.
#include "util/Extents.h"
#include "util/Math.h"
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

	bool Extents::containedByFrustum(const G3D::GCamera::Frustum& frustum) const
	{
		for (int i = 0; i < frustum.faceArray.size(); i++)
		{
			const G3D::Plane& plane = (frustum.faceArray.getCArray() + i)->plane;
			for (int j = 0; j < 8; j++)
			{
				G3D::Vector3 corner = getCorner(j);
				if (!plane.halfSpaceContains(corner))
				{
					return false;
				}
			}
		}

		return true;
	}

	Extents Extents::toWorldSpace(const G3D::CoordinateFrame& localCoord)
	{
		G3D::Vector3 minC(Math::inf(), Math::inf(), Math::inf());
		G3D::Vector3 maxC(-Math::inf(), -Math::inf(), -Math::inf());

		for (int i = 0; i < 8; i++)
		{
			G3D::Vector3 corner = getCorner(i);
			G3D::Vector3 world = localCoord.pointToWorldSpace(corner);

			minC = minC.min(world);
			maxC = maxC.max(world);
		}

		return vv(minC, maxC);
	}

	G3D::Plane Extents::getPlane(NormalId normalId) const
	{
		G3D::Vector3 point = faceCenter(normalId);
		G3D::Vector3 normal = normalIdToVector3(normalId);

		return G3D::Plane(normal, point);
	}

	void Extents::getFaceCorners(NormalId faceId, G3D::Vector3& v0, G3D::Vector3& v1, G3D::Vector3& v2, G3D::Vector3& v3) const
	{
		switch (faceId)
		{
		case NORM_X:
			v0 = getCorner(4);
			v1 = getCorner(6);
			v2 = getCorner(7);
			v3 = getCorner(5);
			break;
		case NORM_Y:
			v0 = getCorner(2);
			v1 = getCorner(3);
			v2 = getCorner(7);
			v3 = getCorner(6);
			break;
		case NORM_Z:
			v0 = getCorner(1);
			v1 = getCorner(5);
			v2 = getCorner(7);
			v3 = getCorner(3);
			break;
		case NORM_X_NEG:
			v0 = getCorner(0);
			v1 = getCorner(1);
			v2 = getCorner(3);
			v3 = getCorner(2);
			break;
		case NORM_Y_NEG:
			v0 = getCorner(0);
			v1 = getCorner(4);
			v2 = getCorner(5);
			v3 = getCorner(1);
			break;
		case NORM_Z_NEG:
			v0 = getCorner(0);
			v1 = getCorner(2);
			v2 = getCorner(6);
			v3 = getCorner(4);
			break;
		}
	}
}
