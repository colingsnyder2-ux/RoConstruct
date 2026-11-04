// Layout and instantiation probe for the inactive native connector header (native-headers/v8kernel/Connector2008.h).
// tests/record_native_world_joints.py checks each size function is `mov eax, imm32; ret` with the size the binary
// news (RotateJoint::putInKernel 00646550: PointToPointBreakConnector 0x1c, RotateConnector 0x34;
// GlueJoint::putInKernel 00647190: NormalBreakConnector 0x20) or that the constructor fills (ContactConnector 0x50,
// 00606d40). Constructing the connectors here emits their vtables and the header-inline COMDATs the original keeps
// out of line: ContactConnector(k, kNeg, kFriction) 00606d40, the shared scalar deleting destructor 006062c0 and
// PointToPointBreakConnector::getBroken 00645a60. Field offsets are compile-time asserts (friend struct).
#include <stddef.h>
#include "v8kernel/Connector2008.h"

struct NativeWorldJointsConnectorLayout
{
	typedef char ContactGeoPair[offsetof(RBX::ContactConnector, geoPair) == 0x8 ? 1 : -1];
	typedef char ContactK[offsetof(RBX::ContactConnector, k) == 0x2c ? 1 : -1];
	typedef char ContactKFriction[offsetof(RBX::ContactConnector, kFriction) == 0x30 ? 1 : -1];
	typedef char ContactKNeg[offsetof(RBX::ContactConnector, kNeg) == 0x34 ? 1 : -1];
	typedef char ContactFirstApproach[offsetof(RBX::ContactConnector, firstApproach) == 0x38 ? 1 : -1];
	typedef char ContactThreshold[offsetof(RBX::ContactConnector, threshold) == 0x3c ? 1 : -1];
	typedef char ContactForceMagLast[offsetof(RBX::ContactConnector, forceMagLast) == 0x40 ? 1 : -1];
	typedef char ContactFrictionOffset[offsetof(RBX::ContactConnector, frictionOffset) == 0x44 ? 1 : -1];
	typedef char P2PPoint0[offsetof(RBX::PointToPointBreakConnector, point0) == 0x8 ? 1 : -1];
	typedef char P2PPoint1[offsetof(RBX::PointToPointBreakConnector, point1) == 0xc ? 1 : -1];
	typedef char P2PK[offsetof(RBX::PointToPointBreakConnector, k) == 0x10 ? 1 : -1];
	typedef char P2PBreakForce[offsetof(RBX::PointToPointBreakConnector, breakForce) == 0x14 ? 1 : -1];
	typedef char P2PBroken[offsetof(RBX::PointToPointBreakConnector, broken) == 0x18 ? 1 : -1];
	typedef char NormalBreakNormalId[offsetof(RBX::NormalBreakConnector, normalIdBody0) == 0x1c ? 1 : -1];
	typedef char RotateK[offsetof(RBX::RotateConnector, k) == 0x8 ? 1 : -1];
	typedef char RotateBase0[offsetof(RBX::RotateConnector, base0) == 0xc ? 1 : -1];
	typedef char RotateRay0[offsetof(RBX::RotateConnector, ray0) == 0x10 ? 1 : -1];
	typedef char RotateRef0[offsetof(RBX::RotateConnector, ref0) == 0x14 ? 1 : -1];
	typedef char RotateRef1[offsetof(RBX::RotateConnector, ref1) == 0x18 ? 1 : -1];
	typedef char RotateLastRotation[offsetof(RBX::RotateConnector, lastRotation) == 0x1c ? 1 : -1];
	typedef char RotateWindings[offsetof(RBX::RotateConnector, windings) == 0x20 ? 1 : -1];
	typedef char RotateKernelInput[offsetof(RBX::RotateConnector, kernelInput) == 0x24 ? 1 : -1];
};

size_t nativeConnectorSize() { return sizeof(RBX::Connector); }
size_t nativeContactConnectorSize() { return sizeof(RBX::ContactConnector); }
size_t nativePointToPointBreakConnectorSize() { return sizeof(RBX::PointToPointBreakConnector); }
size_t nativeNormalBreakConnectorSize() { return sizeof(RBX::NormalBreakConnector); }
size_t nativeRotateConnectorSize() { return sizeof(RBX::RotateConnector); }

// Analogs of the creators (Contact::createConnector, RotateJoint::putInKernel, GlueJoint::putInKernel): they only
// instantiate the inline constructors and vtables here (not compared).
RBX::Connector* nativeWorldJointsNewContactConnector(float k, float kNeg, float kFriction)
{
	return new RBX::ContactConnector(k, kNeg, kFriction);
}

RBX::Connector* nativeWorldJointsNewPointToPoint(RBX::Point* p0, RBX::Point* p1, float k, float breakForce)
{
	return new RBX::PointToPointBreakConnector(p0, p1, k, breakForce);
}

RBX::Connector* nativeWorldJointsNewNormalBreak(RBX::Point* p0, RBX::Point* p1, float k, float breakForce, RBX::NormalId n)
{
	return new RBX::NormalBreakConnector(p0, p1, k, breakForce, n);
}

RBX::Connector* nativeWorldJointsNewRotate(RBX::Point* b, RBX::Point* r, RBX::Point* f0, RBX::Point* f1, float k, float arm)
{
	return new RBX::RotateConnector(b, r, f0, f1, k, arm);
}
