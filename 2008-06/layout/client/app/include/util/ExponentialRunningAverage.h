// =============================================================================
// ExponentialRunningAverage.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/ExponentialRunningAverage.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <g3d/Vector3.h>

namespace RBX
{
	// These classes are only used in ICharacterSubject (found in v8datamodel).
	// Since the constructors of these classes are completely inlined in all builds of RBXGS, their implementation is guessed.

	class floatERA
	{
		float weight;
		float avg;

	public:
		floatERA(float weight)
			: weight(weight)
		{
			reset();
		}

		floatERA()
			: weight(1.0f)
		{
			reset();
		}

		void reset();
		float pushAndGetAverage(float value);
		float getAverage();
	};

	class Vector3ERA
	{
		float weight;
		float x, y, z;

	public:
		Vector3ERA(float weight)
			: weight(weight)
		{
			reset();
		}

		Vector3ERA()
			: weight(1.0f)
		{
			reset();
		}

		void reset();
		G3D::Vector3 pushAndGetAverage(G3D::Vector3 value);
		G3D::Vector3 getAverage();
	};
}
