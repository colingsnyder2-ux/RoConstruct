// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// RBX::Constants::getJointKMultiplier, 2008-06 v8kernel Constants unit (getElasticMultiplier 00649320,
// getJointKMultiplier 00649390, getKmsMaxJointForce 00649670). The size is truncated to G3D::Vector3int16
// (Vector3int16(const Vector3&) 007bbdc0); ball sizes use a jump table on x, blocks switch on x, y and z.
#include "v8kernel/Constants.h"
#include <G3D/Vector3int16.h>

namespace RBX
{
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
}
