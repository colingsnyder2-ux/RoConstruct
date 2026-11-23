// =============================================================================
// Dragger.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/Dragger.h
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
#include <G3D/Matrix3.h>
#include <G3D/Array.h>
#include <vector>
#include "util/Extents.h"

namespace RBX
{
	class Primitive;
	class ContactManager;
	class PVInstance;

	class Dragger
	{
	private:
		static void primitivesFromInstances(const std::vector<PVInstance*>&, G3D::Array<Primitive*>&);
		static bool intersectingWorldOrOthers(const G3D::Array<Primitive*>& primitives, ContactManager& contactManager);
		static void movePrimitives(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& delta);
		static void movePrimitivesDelta(const G3D::Array<Primitive*>& primitives, const G3D::Vector3& delta, G3D::Vector3& movedSoFar);
		static void movePrimitivesGoal(const G3D::Array<Primitive*>&, const G3D::Vector3&, G3D::Vector3&);
		static void safePlaceAlongLine(
			const G3D::Array<Primitive*>&,
			const G3D::Vector3&,
			const G3D::Vector3&,
			G3D::Vector3&,
			ContactManager&);
		static void searchUpFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager);
		static void searchDownFine(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager);
		static void searchUpGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager);
		static void searchDownGross(const G3D::Array<Primitive*>& primitives, G3D::Vector3& movedSoFar, ContactManager& contactManager);
	public:
		static const G3D::Vector3& dragSnap()
		{
			static G3D::Vector3 v(1, 0.1, 1);
			return v;
		}
		static G3D::Vector3 toGrid(const G3D::Vector3& v);
		static G3D::Vector3 safeMoveNoDrop(
			const G3D::Array<Primitive*>& primitives,
			const G3D::Vector3& tryMove,
			ContactManager& contactManager);
		static G3D::Vector3 safeMoveYDrop(
			const G3D::Array<Primitive*>& primitives,
			const G3D::Vector3& tryMove,
			ContactManager& contactManager);
		static G3D::Vector3 safeMoveAlongLine(const G3D::Array<Primitive*>&, const G3D::Vector3&, ContactManager&);
		static void safeRotate(const G3D::Array<Primitive*>& primitives, const G3D::Matrix3& rotate, ContactManager& contactManager);
		static Extents computeExtents(const std::vector<PVInstance*>&);
		static Extents computeExtents(const G3D::Array<Primitive*>& primitives);
		static Extents computeExtents(const std::vector<Primitive*>&);
	};
}
