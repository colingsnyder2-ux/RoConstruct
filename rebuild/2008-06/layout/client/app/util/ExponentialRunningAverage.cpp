// =============================================================================
// ExponentialRunningAverage.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/util/ExponentialRunningAverage.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
