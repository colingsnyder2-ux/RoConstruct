// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Primitive state setters of v8world/Primitive.cpp, application range 005e8000.. (inactive):
// getNextJoint 005e7ba0, getNextContact 005e7be0, setDragging 005e8050, setAnchor 005e80d0, setJointAnchored 005e8140, clipToSafeSize 005e83c0,
// setGridSize 005e8470, setPV 005e85b0, getAssembly 005e7570 and setCoordinateFrame 005e8200.
// Flags: the sibling rows of native-classes/AppUnit5E4Primitive.cpp (/fp:fast).
//
// RBX::EdgeList / RBX::Primitive are native-headers/v8world/Primitive2008.h and RBX::World is
// native-headers/v8world/World2008.h (they replaced the earlier unit-local redeclarations of this unit, batch 18).
// RBX::Edge (getIndex), RBX::Joint and RBX::Contact for getNextJoint 005e7ba0 / getNextContact 005e7be0 come from
// native-headers/AppUnit658/Edge.h, v8world/Joints2008.h and v8world/Contact2008.h (native 2008 Edge over
// IPipelined2008.h). getAssembly 005e7570 and setCoordinateFrame 005e8200 use the native 2008 RBX::Clump /
// RBX::Assembly of v8world/AssemblyLayout.h (NATIVE_CLUMP_DECL: Clump +0x24 assembly, the assembly's +0x24 -> +0x1c
// root primitive, Clump-unit notifyMoved 005e6170). The donor Clump.h puts assembly at +0x20; the native-world
// openrbx port Clump.h / Assembly.h carries the WEBSERVICE layout. Rejected first form: getAssembly as
// `clump ? reinterpret_cast<...>(clump)->assembly : NULL` -> 180 bytes, the `xor edi, edi` NULL arm was jump-threaded
// away; the nested inline Clump::getAssembly reproduces it. IMoving::notifyMoved 00614be0 is the donor
// v8world/IMoving.h declaration (its body is native-classes/IMovingManager.cpp). RBX::getJoint 0064ca60 belongs to the
// ClumpStage unit (next to 0064cc40 / 0064ccf0) and already has a body in native-world/App/v8world/ClumpStage.cpp: not
// duplicated. The Body is the native 2008 Body (native-headers/v8kernel/Body2008.h): setVelocity 00614040.
#include <math.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"
#include "util/PV.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Contact2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"
#include "v8world/World2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 005e7ba0: the index of prev in this primitive's list (+0x14 when this is prim0 +0xc, else +0x18) plus one, checked
	// against joints.edges.size() (+0x3c), returns joints.edges[i] (+0x38) or NULL. Caller: RBX::getJoint 0064ca60.
	Joint* Primitive::getNextJoint(Joint* prev) const
	{
		int i = prev->getIndex(this) + 1;
		return i < joints.edges.size() ? static_cast<Joint*>(joints.edges[i]) : NULL;
	}

	// 005e7be0: as getNextJoint, on contacts (edges.size() +0x20, data +0x1c).
	Contact* Primitive::getNextContact(Contact* prev)
	{
		int i = prev->getIndex(this) + 1;
		return i < contacts.edges.size() ? static_cast<Contact*>(contacts.edges[i]) : NULL;
	}

	// 005e8050: the anchored state `dragging || anchored || jointAnchored` (+0xa8 / +0xa9 / +0xaa) before and after
	// the store; on a change the world (+0x58) is told 005e94a0 (now anchored) or 005e94e0 (no longer), as tail jumps.
	void Primitive::setDragging(bool _dragging)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (dragging != _dragging)
		{
			dragging = _dragging;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	// 005e80d0: as setDragging, on anchored (+0xa9).
	void Primitive::setAnchor(bool _anchored)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (anchored != _anchored)
		{
			anchored = _anchored;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	// 005e8140: as setDragging, on jointAnchored (+0xaa); analog name.
	void Primitive::setJointAnchored(bool _jointAnchored)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (jointAnchored != _jointAnchored)
		{
			jointAnchored = _jointAnchored;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	// 005e83c0: each axis clipped to 512 ([00823c70], Vector3::min: z, y, x order of the G3D::min arguments), then a
	// volume above 1e6 ([00823e04]) shrinks y to floor(1e6 / (x * z)) (MSVCR90 floor).
	G3D::Vector3 Primitive::clipToSafeSize(const G3D::Vector3& newSize)
	{
		G3D::Vector3 answer = newSize.min(G3D::Vector3(512.0f, 512.0f, 512.0f));
		const float maxVolume = 1000000.0f;
		if (answer.x * answer.y * answer.z > maxVolume)
			answer.y = floor(maxVolume / (answer.x * answer.z));
		return answer;
	}

	// 005e8000 (registry func_005e8000; only caller setGridSize 005e8470): Body::setMass 006140b0, geometry (+0x9c)
	// slot 6 getMoment(mass) into a Matrix3 temporary, Body::setMoment 00614110, JointK dirty (+0xf0) = true.
	void Primitive::setMassInertia(float mass)
	{
		body->setMass(mass);
		body->setMoment(geometry->getMoment(mass));
		JointK.setDirty();
	}

	// 005e8470: on a changed clipped size: fuzzyExtentsStateId (+0x98) = -2, geometry (+0x9c) slot 3 setGridSize,
	// setMassInertia 005e8000 of slot 7 getGridVolume, world 005e91c0, JointK dirty (+0xf0).
	void Primitive::setGridSize(const G3D::Vector3& gridSize)
	{
		G3D::Vector3 safe = clipToSafeSize(gridSize);
		if (safe != geometry->getGridSize())
		{
			fuzzyExtentsStateId = -2;
			geometry->setGridSize(safe);
			setMassInertia(geometry->getGridVolume());
			if (world)
				world->onPrimitiveExtentsChanged(this);
			JointK.setDirty();
		}
	}

	// 005e85b0: body (+0xa0) Body::setVelocity 00614040 of pv.velocity (+0x30), then setCoordinateFrame 005e8200 of
	// pv.position.
	void Primitive::setPV(const PV& pv)
	{
		body->setVelocity(pv.velocity);
		setCoordinateFrame(pv.position);
	}

	// 005e7570: clump (+0x5c) ? clump->assembly (+0x24, the 2008 Clump of v8world/AssemblyLayout.h) : NULL (donor body).
	Assembly* Primitive::getAssembly() const
	{
		return clump ? clump->getAssembly() : NULL;
	}

	// 005e86f0: donor tools/rbxgs v8world/Primitive.cpp setPrimitiveType (asserts compiled out). On a changed type
	// (geometry +0x9c slot 2 getGeometryType): keep the grid size (+4 / +8 / +0xc), delete the geometry (slot 1 with
	// 1), newGeometry 005e7d80, World::onPrimitiveGeometryTypeChanged 005e9230 (call at 005e874b) when world (+0x58)
	// is set, setGridSize 005e8470 of the old size, JointK dirty (+0xf0).
	void Primitive::setPrimitiveType(Geometry::GeometryType geometryType)
	{
		if (geometry->getGeometryType() != geometryType)
		{
			G3D::Vector3 oldSize = geometry->getGridSize();
			if (geometry)
				delete geometry;

			geometry = newGeometry(geometryType);

			if (world)
				world->onPrimitiveGeometryTypeChanged(this);

			setGridSize(oldSize);
			JointK.setDirty();
		}
	}

	// 005e8200: donor tools/rbxgs v8world/Primitive.cpp body. CoordinateFrame != 004765e0 against the body's frame (updatePV
	// 00599360, pv +0x94); no assembly: Body::setCoordinateFrame 00614400, myOwner (+0xa4) IMoving::notifyMoved 00614be0,
	// world (+0x58) 005e91c0; with one whose root clump's root primitive (+0x24 -> +0x1c) is this: setCoordinateFrame,
	// Assembly 005e6170, World 005e91d0, then World::ticklePrimitive 005e9410 (this, 0) unless dragging / anchored /
	// jointAnchored (+0xa8..+0xaa).
	void Primitive::setCoordinateFrame(const G3D::CoordinateFrame& value)
	{
		if (value != body->getCoordinateFrame())
		{
			Assembly* assembly = getAssembly();
			if (!assembly)
			{
				body->setCoordinateFrame(value);
				myOwner->notifyMoved();
				if (world)
					world->onPrimitiveExtentsChanged(this);
			}
			else
			{
				if (assembly->getRootClump()->getRootPrimitive() == this)
				{
					body->setCoordinateFrame(value);
					assembly->notifyMoved();
					world->onAssemblyExtentsChanged(assembly);
					if (!(dragging || anchored || jointAnchored))
						world->ticklePrimitive(this, 0);
				}
			}
		}
	}
}

// Batch 42: further Primitive.cpp rows of the same unit (donor tools/rbxgs / openrbx v8world/Primitive.cpp bodies).
// Blocked only by declarations: native-headers/v8world/Primitive2008.h (not assigned) does not declare
// getFaceInObject 005e76f0, getGridCorner, setGridCorner, getFirstRigidAt or the static insertEdge / removeEdge(Edge*);
// proposal filed with batch 42 (the header defines PRIMITIVE_HEADER_DECLARES_GRID_CORNER_EDGES with them).
// Measured against a scratch Primitive2008.h with the declarations: getFaceInWorld 005e81b0, getGridCorner 005e82e0
// and setGridCorner 005e8500 byte-exact; insertEdge / removeEdge byte-exact but each matches both 005e89f0 and
// 005e86a0 (placeholders; registry name proposal); getFirstRigidAt 93 B vs 97 B (target keeps the getNextJoint NULL
// arm `xor esi, esi` before the loop test, the build jump-threads it to the exit).
#ifdef PRIMITIVE_HEADER_DECLARES_GRID_CORNER_EDGES
namespace RBX
{
	// 005e7c10 (registry func_005e7c10; donor Primitive::getFirstRigidAt): RigidJoint::isRigidJoint inline (slot 3
	// getEdgeType == JOINT, slot 5 getJointType WELD 6 / SNAP 7), then the inline getNextJoint 005e7ba0 index walk.
	RigidJoint* Primitive::getFirstRigidAt(Edge* start)
	{
		while (start != NULL)
		{
			if (RigidJoint::isRigidJoint(start))
				return static_cast<RigidJoint*>(start);

			start = getNextJoint(static_cast<Joint*>(start));
		}

		return NULL;
	}

	// 005e81b0 (registry func_005e81b0): getFaceInObject 005e76f0, Face::toWorldSpace 00649970 of the body's
	// pv.position (Body::getPV: updatePV 00599360, pv +0x94).
	Face Primitive::getFaceInWorld(NormalId objectFace)
	{
		return getFaceInObject(objectFace).toWorldSpace(body->getPV().position);
	}

	// 005e82e0 (registry func_005e82e0): -(gridSize * 0.5f) ([00819bac]) to world space of pv.position, then the
	// CoordinateFrame(rotation, translation) ctor 00513220.
	G3D::CoordinateFrame Primitive::getGridCorner() const
	{
		const G3D::CoordinateFrame& pos = body->getPV().position;
		G3D::Vector3 hVec = -(geometry->getGridSize() * 0.5f);

		return G3D::CoordinateFrame(pos.rotation, pos.pointToWorldSpace(hVec));
	}

	// 005e8500 (registry func_005e8500; caller PartInstance 00599730): gridSize * 0.5 to world space of gridCorner,
	// CoordinateFrame ctor 00513220, setCoordinateFrame 005e8200.
	void Primitive::setGridCorner(const G3D::CoordinateFrame& gridCorner)
	{
		G3D::Vector3 hVec = geometry->getGridSize() * 0.5f;
		setCoordinateFrame(G3D::CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(hVec)));
	}

	// 005e86a0 (registry func_005e86a0; callers TreeStage::onEdgeRemoving 00669c70): EdgeList::removeEdge 005e8610
	// on the joints list (+0x34) of both primitives (prim1 may be NULL) or on the contacts lists (+0x18).
	void Primitive::removeEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (e->getEdgeType() == Edge::JOINT)
		{
			p0->joints.removeEdge(e);
			if (p1)
				p1->joints.removeEdge(e);
		}
		else
		{
			p0->contacts.removeEdge(e);
			p1->contacts.removeEdge(e);
		}
	}

	// 005e89f0 (registry func_005e89f0; TreeStage onEdgeAdded caller): as removeEdge with EdgeList::insertEdge 005e8990.
	void Primitive::insertEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (e->getEdgeType() == Edge::JOINT)
		{
			p0->joints.insertEdge(e);
			if (p1)
				p1->joints.insertEdge(e);
		}
		else
		{
			p0->contacts.insertEdge(e);
			p1->contacts.insertEdge(e);
		}
	}
}
#endif
