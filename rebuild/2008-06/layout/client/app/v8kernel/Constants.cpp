#include "v8kernel/Constants.h"
#include "util/Math.h"

namespace RBX
{
	__forceinline G3D::Vector3 getClippedSortedSize(const G3D::Vector3& v)
	{
		return v.max(G3D::Vector3(1.0f, 1.0f, 1.0f));
	}

	const float Constants::getJointK(const G3D::Vector3& gridSize, bool ball)
	{
		G3D::Vector3 sortedSize = Math::sortVector3(gridSize);
		G3D::Vector3 clippedSize = getClippedSortedSize(sortedSize);

		float JointKMultiplier = getJointKMultiplier(clippedSize, ball);

		if (sortedSize.x < 1.0)
			JointKMultiplier *= sortedSize.x;

		return JointKMultiplier * 960000.0f;
	}
}

#include <G3D/Vector3int16.h>

namespace RBX
{
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
