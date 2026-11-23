// =============================================================================
// RunningAverage.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/RunningAverage.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/CoordinateFrame.h>
#include "util/Quaternion.h"

namespace RBX
{
	class RunningAverageState
	{
	private:
		G3D::Vector3 position;
		Quaternion angles;

	public:
		//RunningAverageState(const RunningAverageState&);
		RunningAverageState()
			: position(),
			  angles()
		{
		}
		void update(const G3D::CoordinateFrame& cofm, float radius);
		bool withinTolerance(const G3D::CoordinateFrame& cofm, float radius, float tolerance);
		//RunningAverageState& operator=(const RunningAverageState&);

	private:
		static float weight();
	public:
		static int stepsToSleep();
	};
}
