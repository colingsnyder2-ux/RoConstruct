// =============================================================================
// ICameraSubject.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/ICameraSubject.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <g3d/coordinateframe.h>
#include "util/ILocation.h"

namespace RBX
{
	class Primitive;
	class __declspec(novtable) ICameraSubject : public virtual ILocation
	{
	public:
		ICameraSubject()
		{
		}
		virtual ~ICameraSubject()
		{
		}
	public:
		virtual void onCameraNear(float distance)
		{
		}
		virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives)
		{
		}
		virtual float getLerp() const
		{
			return 0.9f;
		}
		virtual bool zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus)
		{
			return false;
		}
		// TODO: check match
		virtual void stepGoalAndFocus(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus, bool cameraExternallyAdjusted)
		{
			cameraFocus = getLocation();
		}
	};
}
