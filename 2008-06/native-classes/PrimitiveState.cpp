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
