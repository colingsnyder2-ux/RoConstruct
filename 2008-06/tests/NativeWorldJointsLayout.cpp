// Layout and instantiation probe for the inactive native joint header (native-headers/v8world/Joints2008.h).
// tests/record_native_world_joints.py checks each size function is `mov eax, imm32; ret` with the size the binary
// news (RotateJoint::surfaceTypeToJoint 00645e40: RotateJoint 0xc4, RotateP/V 0xc8; GlueJoint::canBuildJoint
// 00646f60: 0x120; VelocityMotor creator 0060bbb0: MotorJoint 0x98) or that the constructors fill (Joint 0x88,
// MultiJoint 0xc0). Constructing the classes with inline constructors here emits their vtables and the header-inline
// COMDATs the original keeps in the JointInstance unit (RigidJoint ??_G 005e2760, RotatePJoint ??_G 005e28e0,
// Joint::align 005e28c0). Field offsets are compile-time asserts (NativeWorldJointsLayout is a friend).
#include <stddef.h>
#include "v8world/Joints2008.h"

struct NativeWorldJointsLayout
{
	typedef char JointOwner[offsetof(RBX::Joint, jointOwner) == 0x20 ? 1 : -1];
	typedef char JointActive[offsetof(RBX::Joint, active) == 0x24 ? 1 : -1];
	typedef char JointCoord0[offsetof(RBX::Joint, jointCoord0) == 0x28 ? 1 : -1];
	typedef char JointCoord1[offsetof(RBX::Joint, jointCoord1) == 0x58 ? 1 : -1];
	typedef char MultiNumConnector[offsetof(RBX::MultiJoint, numConnector) == 0x88 ? 1 : -1];
	typedef char MultiPoint[offsetof(RBX::MultiJoint, point) == 0x8c ? 1 : -1];
	typedef char MultiConnector[offsetof(RBX::MultiJoint, connector) == 0xac ? 1 : -1];
	typedef char MultiNumBreaking[offsetof(RBX::MultiJoint, numBreakingConnectors) == 0xbc ? 1 : -1];
	typedef char RotateConnector[offsetof(RBX::RotateJoint, rotateConnector) == 0xc0 ? 1 : -1];
	typedef char DynamicRotateValue[offsetof(RBX::DynamicRotateJoint, channelValue) == 0xc4 ? 1 : -1];
	typedef char GlueOverlap0[offsetof(RBX::GlueJoint, overlapInP0) == 0xc0 ? 1 : -1];
	typedef char GlueOverlap1[offsetof(RBX::GlueJoint, overlapInP1) == 0xf0 ? 1 : -1];
	typedef char MotorLink[offsetof(RBX::MotorJoint, link) == 0x88 ? 1 : -1];
	typedef char MotorCurrentAngle[offsetof(RBX::MotorJoint, currentAngle) == 0x8c ? 1 : -1];
	typedef char MotorMaxVelocity[offsetof(RBX::MotorJoint, maxVelocity) == 0x90 ? 1 : -1];
	typedef char MotorDesiredAngle[offsetof(RBX::MotorJoint, desiredAngle) == 0x94 ? 1 : -1];
};

size_t nativeJointSize() { return sizeof(RBX::Joint); }
size_t nativeRigidJointSize() { return sizeof(RBX::RigidJoint); }
size_t nativeWeldJointSize() { return sizeof(RBX::WeldJoint); }
size_t nativeSnapJointSize() { return sizeof(RBX::SnapJoint); }
size_t nativeMultiJointSize() { return sizeof(RBX::MultiJoint); }
size_t nativeRotateJointSize() { return sizeof(RBX::RotateJoint); }
size_t nativeRotatePJointSize() { return sizeof(RBX::RotatePJoint); }
size_t nativeRotateVJointSize() { return sizeof(RBX::RotateVJoint); }
size_t nativeGlueJointSize() { return sizeof(RBX::GlueJoint); }
size_t nativeMotorJointSize() { return sizeof(RBX::MotorJoint); }
size_t nativeRevoluteLinkSize() { return sizeof(RBX::RevoluteLink); }

// The JointInstance subclasses (Weld 005e4810, Snap 005e4600, RotateP 005e4c60, RotateV 005e4dd0) new these with the
// inline default constructors; these analogs only instantiate them (not compared).
RBX::Joint* nativeWorldJointsNewRigid() { return new RBX::RigidJoint(); }
RBX::Joint* nativeWorldJointsNewWeld() { return new RBX::WeldJoint(); }
RBX::Joint* nativeWorldJointsNewSnap() { return new RBX::SnapJoint(); }
RBX::Joint* nativeWorldJointsNewRotateP() { return new RBX::RotatePJoint(); }
RBX::Joint* nativeWorldJointsNewRotateV() { return new RBX::RotateVJoint(); }
