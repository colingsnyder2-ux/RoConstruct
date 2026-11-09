#include "util/ExponentialRunningAverage.h"

namespace RBX
{
	void floatERA::reset()
	{
		avg = 0.0f;
	}

	float floatERA::pushAndGetAverage(float value)
	{
		avg = (value - avg) * weight + avg;
		return avg;
	}

	float floatERA::getAverage()
	{
		return avg;
	}

	void Vector3ERA::reset()
	{
		z = 0.0f;
		y = 0.0f;
		x = 0.0f;
	}

	G3D::Vector3 Vector3ERA::pushAndGetAverage(G3D::Vector3 value)
	{
		x = (value.x - x) * weight + x;
		y = (value.y - y) * weight + y;
		z = (value.z - z) * weight + z;

		return G3D::Vector3(x, y, z);
	}

	G3D::Vector3 Vector3ERA::getAverage()
	{
		return G3D::Vector3(x, y, z);
	}
}