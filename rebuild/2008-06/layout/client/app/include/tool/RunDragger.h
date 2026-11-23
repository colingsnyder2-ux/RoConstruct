// =============================================================================
// RunDragger.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/RunDragger.h
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
#include <G3D/Array.h>
#include <G3D/Ray.h>
#include <boost/weak_ptr.hpp>
#include "util/NormalId.h"

namespace RBX
{
	class PartInstance;
	class Workspace;
	class Primitive;
	class Contact;

	class RunDragger
	{
	public:
		class SnapInfo
		{
		public:
			Primitive* snap;
			NormalId surface;
			G3D::Vector3 hitWorld;
			G3D::Vector3 lastDragSnap;

			SnapInfo()
				: surface(NORM_UNDEFINED),
				  hitWorld(G3D::Vector3::inf()),
				  lastDragSnap(G3D::Vector3::inf()),
				  snap(NULL)
			{
			}

			void updateHitFromSurface(const G3D::Ray& mouseRay);
			void updateSurfaceFromHit();
			float hitOutsideExtents();
		};

	private:
		boost::weak_ptr<PartInstance> dragPart;
		boost::weak_ptr<PartInstance> snapPart;
		Workspace* workspace;
		Primitive* drag;
		G3D::Vector3 dragPointLocal;
		SnapInfo snapInfo;
		G3D::Ray mouseRay;
		NormalId dragSurface;
		G3D::Vector3 dragHitLocal;

	private:
		SnapInfo createSnapSurface(Primitive* snap, G3D::Array<NormalId>* ignore);
		bool moveDragPart();
		bool snapDragPart();
		void findSafeY();
		bool notTried(Primitive* check, const G3D::Array<Primitive*>& tried);
		bool adjacent(Primitive* p0, Primitive* p1);
		SnapInfo rayHitsPart(const G3D::Array<Primitive*>& triedSnap, bool forceAdjacent);
		SnapInfo bestProximatePart(const G3D::Array<Primitive*>& triedSnap, bool (Contact::* proximityTest)(float));
		bool fallOffEdge();
		bool fallOffPart(bool& snapped);
		bool colliding();
		bool rayHitsCloserPart();
		bool tooCloseToCamera();
		SnapInfo findSnap(const G3D::Array<Primitive*>& triedSnap);
		void findNoSnapPosition(const G3D::CoordinateFrame& original);
		void smartPtrHackPre();
		void smartPtrHackPost();
	public:
		RunDragger();
		~RunDragger();
		void init(Workspace* _workspace, boost::weak_ptr<PartInstance> _dragPart, const G3D::Vector3& _dragPointWorld);
		bool snap(const G3D::Ray& _mouseRay);

	public:
		static void turnUpright(PartInstance* part);
		static void rotatePart(PartInstance* part);
		static void tiltPart(PartInstance* part, const G3D::CoordinateFrame& camera);
	};
}
