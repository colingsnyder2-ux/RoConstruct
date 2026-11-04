// Layout and instantiation probe for the inactive native Geometry / Block / Ball / Contact headers.
// tests/record_native_world_shapes.py checks each size function is `mov eax, imm32; ret` with the size the binary
// news (Primitive::newGeometry 005e7d80: Block 0x18, Ball 0x14) or keeps for the nullGeometry static (0x10), and
// compares the creator probe below (an analog of the Primitive::newGeometry static; Primitive is not declared here)
// with 005e7d80 for the inline constructors. Constructing the three classes here also emits their vtables and the
// header-inline virtuals the original keeps as COMDATs (Geometry slots, Block/Ball getRadius, getCenterToCorner,
// getMoment, ??_G 005e73b0, nullGeometry 005e7870).
// Field offsets are compile-time asserts (NativeWorldShapesLayout is a friend of the classes).
#include <stddef.h>
#include "v8world/Block2008.h"
#include "v8world/Ball2008.h"
#include "v8world/Contact2008.h"

struct NativeWorldShapesLayout
{
	typedef char GeometryGridSize[offsetof(RBX::Geometry, gridSize) == 0x4 ? 1 : -1];
	typedef char BlockVertices[offsetof(RBX::Block, vertices) == 0x10 ? 1 : -1];
	typedef char BlockCornerRadius[offsetof(RBX::Block, cornerRadius) == 0x14 ? 1 : -1];
	typedef char BallRealRadius[offsetof(RBX::Ball, realRadius) == 0x10 ? 1 : -1];
	typedef char ContactLastContactStep[offsetof(RBX::Contact, lastContactStep) == 0x20 ? 1 : -1];
	typedef char ContactSteppingIndex[offsetof(RBX::Contact, steppingIndex) == 0x24 ? 1 : -1];
	typedef char ContactJointK[offsetof(RBX::Contact, jointK) == 0x28 ? 1 : -1];
	typedef char ContactElasticJointK[offsetof(RBX::Contact, elasticJointK) == 0x2c ? 1 : -1];
	typedef char ContactKFriction[offsetof(RBX::Contact, kFriction) == 0x30 ? 1 : -1];
	typedef char BallBallConnector[offsetof(RBX::BallBallContact, ballBallConnector) == 0x34 ? 1 : -1];
	typedef char BallBlockConnector[offsetof(RBX::BallBlockContact, ballBlockConnector) == 0x34 ? 1 : -1];
};

size_t nativeGeometrySize() { return sizeof(RBX::Geometry); }
size_t nativeBlockSize() { return sizeof(RBX::Block); }
size_t nativeBallSize() { return sizeof(RBX::Ball); }
size_t nativeContactSize() { return sizeof(RBX::Contact); }
size_t nativeBallBallContactSize() { return sizeof(RBX::BallBallContact); }
size_t nativeBallBlockContactSize() { return sizeof(RBX::BallBlockContact); }

// Same body as Primitive::newGeometry 005e7d80 (switch on the type, nullGeometry for anything else).
RBX::Geometry* nativeWorldShapesNewGeometry(RBX::Geometry::GeometryType geometryType)
{
	switch (geometryType)
	{
	case RBX::Geometry::GEOMETRY_BALL:
		return new RBX::Ball();
	case RBX::Geometry::GEOMETRY_BLOCK:
		return new RBX::Block();
	default:
		return RBX::Geometry::nullGeometry();
	}
}

// Constructing the two ball contacts emits their inline constructors (0060cae0, 0060cb90), vtables and the
// header-inline slots the original keeps as COMDATs in the ContactManager unit (0060cb10 .. 0060cbd0). The callers
// are analogs of the two ball branches of ContactManager::createContact 0060d770 (which news 0x38 for both).
RBX::Contact* nativeWorldShapesNewBallBallContact(RBX::Primitive* p0, RBX::Primitive* p1)
{
	return new RBX::BallBallContact(p0, p1);
}

RBX::Contact* nativeWorldShapesNewBallBlockContact(RBX::Primitive* p0, RBX::Primitive* p1)
{
	return new RBX::BallBlockContact(p0, p1);
}
