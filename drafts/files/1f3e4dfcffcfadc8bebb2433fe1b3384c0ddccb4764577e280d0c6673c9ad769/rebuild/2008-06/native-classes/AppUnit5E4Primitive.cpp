// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 v8world/Primitive.cpp rows of the application range 005e4000..005e8000 (inactive native unit) that the native
// v8world/Primitive2008.h declares (read-only; the Body/Primitive owner's 0xfc layout). Built next to v8world/Contact2008.h on the
// native 2008 Edge / IPipelined2008.h (no donor-IPipelined switch since batch 13), and /fp:fast.
// Verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Constants.h"
#include "v8world/IMoving.h"
#include "v8world/World2008.h"
#include "v8world/AssemblyLayout.h"
#include "v8kernel/Body2008.h"   // Body::getParent / sub_005e7370 (Body +0x14 parent) for getBodyDepth 005e7470

namespace RBX
{
	// INFERRED: file-local helper (no code of its own). The 2008 awake test of the assembly reached through the clump
	// (+0x24) and its SleepInfo (+0x18): NULL -> not awake, then state AWAKE 3, RECURSIVE_WAKE_PENDING 1 or WAKE_PENDING 2
	// in that order (005e74e3..005e74fc, the same order as the SleepStage isMoving inline of 0064bc60).
	static inline bool clumpIsMoving(Clump* clump)
	{
		int state = AssemblyLayout::getSleepStatus(reinterpret_cast<AssemblyLayout::ClumpFields*>(clump)->assembly);
		return state == 3 || state == 1 || state == 2;
	}

	// 005e74c0 (registry func_005e74c0; Primitive.cpp file-level function, openrbx / rbxgs newTouch; onNewTouch calls it
	// twice): both clumps (+0x5c) read first, myOwner (+0xa4) IMoving slot 1 reportTouches, then the awake test of
	// either clump's assembly and World::onPrimitiveTouched 005e98c0 through world (+0x58).
	void newTouch(Primitive* touch, Primitive* touchOther)
	{
		Clump* clumpTouch = touch->getClump();
		Clump* clumpOTouch = touchOther->getClump();

		if (touch->getOwner()->reportTouches() && (clumpIsMoving(clumpTouch) || clumpIsMoving(clumpOTouch)))
		{
			touch->getWorld()->onPrimitiveTouched(touch, touchOther);
		}
	}

	// 005e7420: writes +0x14 only while world (+0x58) is NULL.
	void Primitive::setUnknown0x14(int value)
	{
		if (value != unknown0x14 && world == NULL)
			unknown0x14 = value;
	}

	// 005e7470 (registry placeholder func_005e7470; declared INFERRED in Primitive2008.h, callers TreeStage 00669b83 /
	// 00669b9a): the depth of the primitive's body (+0xa0) in its body tree. The first level is inline (body parent
	// +0x14); the parent's depth comes from the recursive Body body 005e7370 (Body2008.h sub_005e7370, plus one).
	// NEAR MISS (same 26 bytes, register choice only: the target keeps the body in ecx). A scratch build with the
	// Body2008.h proposal (sub_005e7370 defined inline in the class, `parent ? parent->sub_005e7370() + 1 : 1`) and
	// this body as `return body->sub_005e7370();` is byte-identical: the 2008 Body getDepth is a header inline whose
	// out-of-line COMDAT copy is 005e7370. Rejected here: explicit parent test (eax/ecx swap), double getParent(),
	// local reassignment (all the same swap).
	int Primitive::getBodyDepth() const
	{
		const Body* parent = body->getParent();
		return parent ? parent->sub_005e7370() + 1 : 1;
	}

	// 005e7530: newTouch(p0, p1) then newTouch(p1, p0) (005e74c0).
	void Primitive::onNewTouch(Primitive* p0, Primitive* p1)
	{
		newTouch(p0, p1);
		newTouch(p1, p0);
	}

	// 005e7580: geometry (+0x9c) slot 2 (getGeometryType) == GEOMETRY_BALL, Constants::getJointK 00649730 with the
	// grid size at geometry +0x4.
	float Primitive::computeJointK() const
	{
		Geometry::GeometryType type = geometry->getGeometryType();
		return Constants::getJointK(geometry->getGridSize(), type == Geometry::GEOMETRY_BALL);
	}

	// 005e7850: surfaceType[id] at +0xb8 + 4 * id.
	void Primitive::setSurfaceType(NormalId id, SurfaceType newSurfaceType)
	{
		if (surfaceType[id] != newSurfaceType)
			surfaceType[id] = newSurfaceType;
	}

	// 005e7910: out-of-line ~EdgeList: the two G3D::Array destructors (otherPrimitives +0x10, then edges +0x4;
	// G3D::System::alignedFree 00507d20), with an EH frame.
	EdgeList::~EdgeList()
	{
	}

	// 005e7bd0: contacts.edges (+0x18 + 0x4: data +0x1c, size +0x20), first element or NULL.
	Contact* Primitive::getFirstContact()
	{
		return contacts.edges.size() > 0 ? static_cast<Contact*>(contacts.edges[0]) : NULL;
	}

#ifdef PRIMITIVE_HEADER_DECLARES_GETFIRSTRIGID
	// 005e7c80 (registry placeholder func_005e7c80; donor Primitive::getFirstRigid, caller FlagStand::GetFlag 0062b90c):
	// the inline getFirstJoint (joints.edges size +0x3c > 0 ? data +0x38 [0] : NULL), then getFirstRigidAt 005e7c10
	// (call + ret, not a tail jump). GUARDED: v8world/Primitive2008.h declares getFirstRigidAt / getNextRigid but not
	// getFirstRigid (header proposal `RigidJoint* getFirstRigid();` beside them). A scratch build with that one line is
	// byte-identical (27 bytes, relocs masked).
	RigidJoint* Primitive::getFirstRigid()
	{
		return getFirstRigidAt(joints.edges.size() > 0 ? joints.edges[0] : NULL);
	}
#endif

	// 005e7d30: search the smaller contact list's parallel primitive/edge arrays (donor Primitive::getContact).
	Contact* Primitive::getContact(Primitive* p0, Primitive* p1)
	{
		Primitive* least = p0->contacts.edges.size() < p1->contacts.edges.size() ? p0 : p1;
		Primitive* other = least == p0 ? p1 : p0;
		for (int i = 0; i < least->contacts.edges.size(); ++i)
		{
			if (least->contacts.otherPrimitives[i] == other)
				return static_cast<Contact*>(least->contacts.edges[i]);
		}
		return NULL;
	}

	// 005e7f10: vtable slot 3, geometry->getRadius() (Geometry slot 4) as a tail jump.
	float Primitive::getRadius() const
	{
		return geometry->getRadius();
	}
}
