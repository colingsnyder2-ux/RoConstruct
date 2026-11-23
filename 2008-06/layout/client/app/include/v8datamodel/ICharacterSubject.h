// =============================================================================
// ICharacterSubject.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/ICharacterSubject.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <vector>
#include "util/ICameraSubject.h"
#include "util/ExponentialRunningAverage.h"

namespace RBX
{
	class Primitive;
	class ContactManager;

	class __declspec(novtable) ICharacterSubject : public ICameraSubject
	{
	private:
		Vector3ERA focusERA;
		Vector3ERA focusOffsetERA;
		G3D::Vector3 lastOffset;
		floatERA rotationERA;
		bool cursorLocked;
		bool wasOccluded;
		float unoccludedDistance;
		bool hasGoalInFocus;
		G3D::Vector3 goalInFocus;

	private:
		G3D::CoordinateFrame getFocusLookingAtGoal(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal);
		bool testOcclusion(const G3D::CoordinateFrame& cameraFocus, const G3D::CoordinateFrame& cameraGoal, float& distance);
		G3D::CoordinateFrame goalFromDistance(
			const G3D::CoordinateFrame& cameraFocus,
			const G3D::CoordinateFrame& cameraGoal,
			const float distance);
		virtual bool zoom(const float in, G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus);
		virtual void stepGoalAndFocus(G3D::CoordinateFrame&, G3D::CoordinateFrame&, bool);
	public:
		ICharacterSubject();
	public:
		virtual ContactManager* getContactManager() = 0;
		virtual void getIgnorePrims(std::vector<const Primitive*>&);
		virtual void tellCameraNear(float);
		virtual G3D::Vector3 getIntendedMovementVector() = 0;
		virtual float getIntendedRotationAboutYAxis() = 0;
		virtual void cameraSetWalkOrientation(float, bool) = 0;
		float panAdjust();
		void onHeartBeat(G3D::CoordinateFrame& cameraGoal, G3D::CoordinateFrame& cameraFocus);
		void setCursorCenterLocked(bool);
		bool getCursorCenterLocked() const { return cursorLocked; }  // inline in the target: mov al,[eax+0x3c] (cursorLocked is at +0x3c)
	};
}
