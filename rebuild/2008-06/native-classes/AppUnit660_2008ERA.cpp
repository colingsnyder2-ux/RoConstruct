// Inactive native recovery of the RBX exponential running average unit 00666240..006662e5 (2008-06), between the
// PartDragTool unit and the HUMAN::Running state unit. The classes are declared by util/ExponentialRunningAverage.h
// (donor header, read-only): floatERA {weight +0, avg +4} and Vector3ERA {weight +0, x/y/z +4/+8/+0xc}, the offsets
// every body below reads (reset 00666240 / 00666280 store +4 / +4..+0xc, pushAndGetAverage multiplies by [ecx]).
// See tests/record_native_app_unit660_2008.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// AppUnit660_2008ERA | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by auto (+1) (deepseek:deepseek-flash)
// <<< native-status | src 632921e9 | roc native-status --write
#include "util/ExponentialRunningAverage.h"

namespace RBX
{
	void floatERA::reset()                                   // 00666240
	{
		avg = 0.0f;
	}

	float floatERA::pushAndGetAverage(float value)           // 00666250
	{
		avg = (value - avg) * weight + avg;
		return avg;
	}

	float floatERA::getAverage()                             // 00666270
	{
		return avg;
	}

	void Vector3ERA::reset()                                 // 00666280: stores +0xc, +8, +4 in that order
	{
		z = 0.0f;
		y = 0.0f;
		x = 0.0f;
	}

	G3D::Vector3 Vector3ERA::pushAndGetAverage(G3D::Vector3 value)   // 00666290
	{
		x = (value.x - x) * weight + x;
		y = (value.y - y) * weight + y;
		z = (value.z - z) * weight + z;
		return G3D::Vector3(x, y, z);
	}

	G3D::Vector3 Vector3ERA::getAverage()                    // 006662d0
	{
		return G3D::Vector3(x, y, z);
	}
}
