// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// RBX::Constants::getJointKMultiplier, 2008-06 v8kernel Constants unit (getElasticMultiplier 00649320,
// getJointKMultiplier 00649390, getKmsMaxJointForce 00649670). The size is truncated to G3D::Vector3int16
// (Vector3int16(const Vector3&) 007bbdc0); ball sizes use a jump table on x, blocks switch on x, y and z.
#include "v8kernel/Constants.h"
#include <G3D/Vector3int16.h>
#include <G3D/g3dmath.h>
#include <algorithm>

namespace RBX
{
	// 00649320: identity from the decorated name ?getElasticMultiplier@Constants@RBX@@SA?BMM@Z (registry) and its
	// only caller Contact::onPrimitiveContactParametersChanged 00607ad0 (call 00607baf, matching the
	// ContactUnit2008Contact.cpp use). Thresholds/results read from .rdata: 0.05 0081c430, 0.26 0084afe8,
	// 0.51 00843768, 0.76 0084afdc -> 0.28 0084afec, 0.42 0084afe4, 0.57 0084afe0, 0.8 00819b48, else 1.0 (fld1).
	const float Constants::getElasticMultiplier(float elasticity)
	{
		if (elasticity < 0.05f)
			return 0.28f;
		else if (elasticity < 0.26f)
			return 0.42f;
		else if (elasticity < 0.51f)
			return 0.57f;
		else if (elasticity < 0.76f)
			return 0.8f;
		else
			return 1.0f;
	}

	// 00649390
	const float Constants::getJointKMultiplier(const G3D::Vector3& clippedSortedSize, bool ball)
	{
		G3D::Vector3int16 size(clippedSortedSize);

		if (ball)
		{
			switch (size.x)
			{
			case 1:
				return 0.23f;
			case 2:
				return 1.49f;
			case 3:
				return 4.43f;
			case 4:
				return 11.5f;
			default:
				return (float)(size.x * size.x * size.x) * 0.175f;
			}
		}

		int x = size.x;

		switch (x)
		{
		case 1:
			switch (size.y)
			{
			case 1:
				switch (size.z)
				{
				case 1:
					return 0.91f;
				case 2:
					return 1.61f;
				case 3:
					return 2.0f;
				case 4:
					return 2.13f;
				default:
					return (float)size.z * 0.4f;
				}
			case 2:
			{
				int z = size.z;

				switch (z)
				{
				case 2:
					return 3.5f;
				case 3:
					return 4.16f;
				case 4:
					return 4.79f;
				}

				return (float)z < 15.0f ? (float)z * 0.9f : (float)z * 0.75f;
			}
			case 3:
				return (float)size.z < 7.0f ? (float)size.z * 1.66f : (float)size.z * 1.18f;
			case 4:
				return (float)size.z < 7.0f ? (float)size.z * 2.26f : (float)size.z * 1.53f;
			default:
				return ((float)size.y * 0.3f + 0.66f) * (float)size.z;
			}
		case 2:
			break;
		default:
			return (float)(size.z * size.y * x) * 0.25f;
		}

		int y = size.y;
		float value;

		switch (y)
		{
		case 2:
		{
			int z = size.z;

			switch (z)
			{
			case 2:
				return 7.34f;
			case 3:
				return 9.9f;
			case 4:
				return 11.22f;
			}

			value = (float)z;
			if (value < 15.0f)
				return value * 1.9f;
			break;
		}
		case 3:
		{
			int z = size.z;

			switch (z)
			{
			case 3:
				return 15.0f;
			case 4:
				return 19.0f;
			}

			value = (float)z;
			if (value < 15.0f)
				return value + value;
			break;
		}
		default:
			return ((float)y * 0.66f) * size.z;
		}

		return value * 1.5f;
	}

	// 00649670 (placeholder func_00649670; caller GlueJoint::getMaxForce 00646c10): openrbx v8kernel/Constants.cpp
	// getKmsMaxJointForce. G3D::iRound (fistp) of both grid sizes clamped to at least 1, width = max, overlap = min;
	// 1/7 (0084ac8c), 0.5 (00819bac), 7500 (0084b034).
	const float Constants::getKmsMaxJointForce(float grid1, float grid2)
	{
		int grid1int = std::max(1, G3D::iRound(grid1));
		int grid2int = std::max(1, G3D::iRound(grid2));

		int width = std::max(grid1int, grid2int);
		int overlap = std::min(grid1int, grid2int);

		float force;

		if (width < 7)
		{
			force = MAX_LEGO_JOINT_FORCES_MEASURED[width];
		}
		else
		{
			force = width * (1.0f / 7.0f) * MAX_LEGO_JOINT_FORCES_MEASURED[6];
		}

		force = force * 0.5f;

		return force * overlap * 7500.0f;
	}

	// 0084afbc (7 floats, .rdata: 0, 1.098, 2.134, 2.427, 3.191, 4.571, 4.681), read by getKmsMaxJointForce 00649670
	// (`fld [edx*4 + 0x84afbc]`, [6] at 0084afd4). openrbx v8kernel/Constants.cpp MAX_LEGO_JOINT_FORCES_MEASURED.
	// Defined after its reader: 0064970d still loads [6] from the table (`fmul [0084afd4]`), so the initializer was not
	// visible to the front end when getKmsMaxJointForce was compiled (defined before it, VC9 folds [6] * 0.5f).
	const float Constants::MAX_LEGO_JOINT_FORCES_MEASURED[7] = {0.0f, 1.098f, 2.134f, 2.427f, 3.191f, 4.571f, 4.681f};
}
