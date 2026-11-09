// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#undef _RELEASEASSERT
#include "util/Math.h"
#include "util/Debug.h"
#include <cmath>
#define LODWORD(x) (*(DWORD*)(&x))
namespace RBX {
	bool Math::isDenormal(float f)                                                   // 005dd7b0
	{
		return (LODWORD(f) & 0x7F800000) == 0 && (LODWORD(f) & 0x7FFFFF) != 0;
	}

	bool Math::fixDenorm(G3D::Vector3& v)                                             // 005dd940
	{
		bool fixed = false;

		float x = v.x;
		if (Math::isDenormal(x))
		{
			v.x = 0;
			fixed = true;
		}

		float y = v.y;
		if (Math::isDenormal(y))
		{
			v.y = 0;
			fixed = true;
		}

		float z = v.z;
		if (Math::isDenormal(z))
		{
			v.z = 0;
			fixed = true;
		}

		return fixed;
	}

	G3D::Vector3 Math::toDiagonal(const G3D::Matrix3& m)                               // 005ddbb0
	{
		return G3D::Vector3(m[0][0], m[1][1], m[2][2]);
	}

	G3D::Vector3 Math::iRoundVector3(const G3D::Vector3& point)                        // 005de090
	{
		return G3D::Vector3(Math::iRound(point.x), Math::iRound(point.y), Math::iRound(point.z));
	}

	NormalId Math::getClosestObjectNormalId(const G3D::Vector3& worldV, const G3D::Matrix3& objectR)  // 005de560
	{
		G3D::Vector3 worldObjMul = worldV * objectR;
		float absX = fabs(worldObjMul.x);
		float absY = fabs(worldObjMul.y);
		float absZ = fabs(worldObjMul.z);
		if (absX > absY)
		{
			if (absX > absZ)
			{
				return worldObjMul.x > 0 ? NORM_X : NORM_X_NEG;
			}
			else
			{
				return worldObjMul.z > 0 ? NORM_Z : NORM_Z_NEG;
			}
		}
		else if (absY > absZ)
		{
			return worldObjMul.y > 0 ? NORM_Y : NORM_Y_NEG;
		}
		return worldObjMul.z > 0 ? NORM_Z : NORM_Z_NEG;
	}

	G3D::Vector3 Math::vector3Abs(const G3D::Vector3& v)                               // 005de630
	{
		return G3D::Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
	}

	float Math::getHeading(const G3D::Vector3& look)                                   // 005de650
	{
		return atan2(-look.x, -look.z);
	}

	G3D::Vector3 Math::toGrid(const G3D::Vector3& v, const G3D::Vector3& grid)          // 005dee10
	{
		G3D::Vector3 units = v / grid;
		return grid * Math::iRoundVector3(units);
	}





	G3D::Vector3 Math::sortVector3(const G3D::Vector3& v)                              // 005df1b0
	{
		G3D::Vector3 result = v;

		if (result.z < result.y)
		{
			std::swap(result.z, result.y);
		}

		if (result.y < result.x)
		{
			std::swap(result.y, result.x);
		}

		if (result.z < result.y)
		{
			std::swap(result.z, result.y);
		}

		return result;
	}

	float Math::maxAxisLength(const G3D::Vector3& v)                                   // 005df220
	{
		G3D::Vector3 vAbs = G3D::Vector3(fabs(v.x), fabs(v.y), fabs(v.z));
		return std::max(vAbs.x, std::max(vAbs.y, vAbs.z));
	}
}
