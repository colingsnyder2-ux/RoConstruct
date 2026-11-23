// =============================================================================
// quaternion.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/quaternion.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "util/Quaternion.h"

extern "C" double __cdecl sqrt(double);
namespace RBX
{
	Quaternion& Quaternion::operator=(const Quaternion& other)               // 005dd550
	{
		this->w = other.w;
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return *this;
	}

	Quaternion::Quaternion(const G3D::Matrix3& rot)                          // 005dd570
	{
		float fTrace = rot[0][0] + rot[1][1] + rot[2][2];
		float fRoot;

		if (fTrace > 0.0f)
		{
			fRoot = sqrt(fTrace + 1);
			this->w = 0.5f * fRoot;
			fRoot = 0.5f / fRoot;
			this->x = (rot[2][1] - rot[1][2]) * fRoot;
			this->y = (rot[0][2] - rot[2][0]) * fRoot;
			this->z = (rot[1][0] - rot[0][1]) * fRoot;
		}
		else
		{
			if (rot[0][0] > rot[1][1] && rot[0][0] > rot[2][2])
			{
				fRoot = -sqrt(1.0f + rot[0][0] - rot[1][1] - rot[2][2]);
				this->x = 0.5f * fRoot;
				fRoot = 0.5f / fRoot;
				this->y = (rot[1][0] + rot[0][1]) * fRoot;
				this->z = (rot[2][0] + rot[0][2]) * fRoot;
				this->w = (rot[2][1] - rot[1][2]) * fRoot;
			}
			else
			{
				if (rot[1][1] > rot[2][2])
				{
					fRoot = -sqrt(1.0f + rot[1][1] - rot[0][0] - rot[2][2]);
					this->y = 0.5f * fRoot;
					fRoot = 0.5f / fRoot;
					this->x = (rot[1][0] + rot[0][1]) * fRoot;
					this->z = (rot[2][1] + rot[1][2]) * fRoot;
					this->w = (rot[0][2] - rot[2][0]) * fRoot;
				}
				else
				{
					fRoot = -sqrt(1.0f + rot[2][2] - rot[0][0] - rot[1][1]);
					this->z = 0.5f * fRoot;
					fRoot = 0.5f / fRoot;
					this->x = (rot[2][0] + rot[0][2]) * fRoot;
					this->y = (rot[2][1] + rot[1][2]) * fRoot;
					this->w = (rot[1][0] - rot[0][1]) * fRoot;
				}
			}
		}
	}

	void Quaternion::toRotationMatrix(G3D::Matrix3& rot) const        // 005dd6d0
	{
		float fTx  = 2.0f * this->x;
		float fTy  = 2.0f * this->y;
		float fTz  = 2.0f * this->z;
		float fTxx = fTx * this->x;
		float fTxy = fTy * this->x;
		float fTxz = fTz * this->x;
		float fTwx = fTx * this->w;
		float fTwy = fTy * this->w;
		float fTwz = fTz * this->w;
		float fTyy = fTy * this->y;
		float fTyz = fTz * this->y;
		float fTzz = fTz * this->z;

		rot[0][0] = 1.0 - (fTyy + fTzz);
		rot[0][1] = fTxy - fTwz;
		rot[0][2] = fTxz + fTwy;
		rot[1][0] = fTxy + fTwz;
		rot[1][1] = 1.0 - (fTxx + fTzz);
		rot[1][2] = fTyz - fTwx;
		rot[2][0] = fTxz - fTwy;
		rot[2][1] = fTyz + fTwx;
		rot[2][2] = 1.0 - (fTxx + fTyy);
	}
}

namespace RBX
{
void Quaternion::normalize()
{
	float inverse = 1.0f / (float)sqrt(x * x + y * y + z * z + w * w);
	x *= inverse;
	y *= inverse;
	z *= inverse;
	w *= inverse;
}
}

// INFERRED: returns the largest of |x|, |y|, |z|, |w|; body derived from the 2008-06 binary.

#include <math.h>
#include <algorithm>

namespace RBX
{
	float Quaternion::maxComponent() const
	{
		return std::max(std::max(fabs(x), fabs(y)), std::max(fabs(z), fabs(w)));
	}
}
