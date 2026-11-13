// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 v8world/Primitive.cpp rows of the application range 005e4000..005e8000 (inactive native unit) that the native
// v8world/Primitive2008.h declares (read-only; the Body/Primitive owner's 0xfc layout). Built with the donor-IPipelined
// switch (NATIVE_IPIPELINED2008_DONOR) next to v8world/Contact2008.h, as ContactUnit2008Contact.cpp does, and /fp:fast.
// Verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#define NATIVE_IPIPELINED2008_DONOR
#include "v8world/Contact2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/Constants.h"

namespace RBX
{
	// 005e74c0 (Primitive.cpp file-level function; onNewTouch calls it twice). Not built here: it reads the 2008 Clump
	// (+0x24 assembly) and Assembly sleep state, which no native header declares.
	void newTouch(Primitive* touch, Primitive* touchOther);

	// 005e7420: writes +0x14 only while world (+0x58) is NULL.
	void Primitive::setUnknown0x14(int value)
	{
		if (value != unknown0x14 && world == NULL)
			unknown0x14 = value;
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

	// 005e7f10: vtable slot 3, geometry->getRadius() (Geometry slot 4) as a tail jump.
	float Primitive::getRadius() const
	{
		return geometry->getRadius();
	}
}
