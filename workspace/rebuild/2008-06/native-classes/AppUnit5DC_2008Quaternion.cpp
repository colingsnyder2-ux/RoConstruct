// 2008-06 native RBX::Quaternion rows of the util/Quaternion.cpp unit 005dd550..005dd77f inside the application range
// 005dc000..005e8000 (inactive). Declarations: the donor util/Quaternion.h (read-only; no native header declares
// RBX::Quaternion). Layout: four floats x, y, z, w (0x10): operator= 005dd550 copies +0xc, +0x0, +0x4, +0x8 in that
// order (w, x, y, z), the Matrix3 constructor 005dd570 and toRotationMatrix 005dd6d0 read / write only those four.
// The unit holds only these three bodies, in this order; built with /fp:fast. Verified by
// tests/record_native_app_unit5dc_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// AppUnit5DC_2008Quaternion | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto (chatgpt:gpt-6.1-sol)
// <<< native-status | src 6800dd85 | roc native-status --write
#include "util/Quaternion.h"

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
