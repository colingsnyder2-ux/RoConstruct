// Layout probe for the inactive native Feature/Hole/MotorFeature/VelocityMotor header; tests/record_native_feature.py
// checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Hole), sizeof(MotorFeature)  0x150  Creatable<Instance>::create<Hole> 00580230 and
//                                              create<MotorFeature> 0057ffc0 allocate 0x150
//   sizeof(Feature)                     0x150  (Hole/MotorFeature add no fields: constructors 0060c840/0060c910
//                                              only store vtables and call setName)
//   IRenderable base                    +0x130 (RTTI base class descriptor, constructor 0060be60 stores its vtable)
//   Feature fields   faceId +0x140, topBottom +0x144, leftRight +0x148, inOut +0x14c (constructor 0060be60,
//                    getters 00609a30/004a1560/00609a40/00609a50, setters 0060c340..0060c3d0)
//   VelocityMotor    0x170 (create<VelocityMotor> 005804a0); hole +0x154, holeAncestorChanged +0x15c (constructor
//                    0060bbb0, destructor 0060a650); JointInstance part 0x154 with joint +0x150 and IJointOwner
//                    +0x140 (constructor 005e3870, RTTI). With the current shared JointInstance.h the recorder checks
//                    the relative layout (fields start at sizeof(JointInstance)); the NATIVE_FEATURE_PENDING build
//                    (generated JointInstance.h copy) checks the absolute offsets.
// Field offsets of Feature are compile-time asserts (NativeFeatureLayout is a friend of Feature and VelocityMotor).
#include <stddef.h>
#include "v8datamodel/Feature.h"

struct NativeFeatureLayout
{
	typedef char FaceId[offsetof(RBX::Feature, faceId) == 0x140 ? 1 : -1];
	typedef char TopBottom[offsetof(RBX::Feature, topBottom) == 0x144 ? 1 : -1];
	typedef char LeftRight[offsetof(RBX::Feature, leftRight) == 0x148 ? 1 : -1];
	typedef char InOut[offsetof(RBX::Feature, inOut) == 0x14c ? 1 : -1];

	static size_t velocityMotorHole() { return offsetof(RBX::VelocityMotor, hole); }
	static size_t velocityMotorHoleAncestorChanged() { return offsetof(RBX::VelocityMotor, holeAncestorChanged); }
	static size_t velocityMotorJoint() { return offsetof(RBX::VelocityMotor, joint); }
};

size_t nativeFeatureSize() { return sizeof(RBX::Feature); }
size_t nativeHoleSize() { return sizeof(RBX::Hole); }
size_t nativeMotorFeatureSize() { return sizeof(RBX::MotorFeature); }
size_t nativeFeatureRenderableOffset()
{
	RBX::Feature* feature = reinterpret_cast<RBX::Feature*>(0x1000);
	return reinterpret_cast<char*>(static_cast<RBX::IRenderable*>(feature)) - reinterpret_cast<char*>(feature);
}

size_t nativeVelocityMotorSize() { return sizeof(RBX::VelocityMotor); }
size_t nativeJointInstanceSize() { return sizeof(RBX::JointInstance); }
size_t nativeVelocityMotorHoleOffset() { return NativeFeatureLayout::velocityMotorHole(); }
size_t nativeVelocityMotorConnectionOffset() { return NativeFeatureLayout::velocityMotorHoleAncestorChanged(); }
size_t nativeVelocityMotorJointOffset() { return NativeFeatureLayout::velocityMotorJoint(); }
size_t nativeVelocityMotorRenderableOffset()
{
	RBX::VelocityMotor* motor = reinterpret_cast<RBX::VelocityMotor*>(0x1000);
	return reinterpret_cast<char*>(static_cast<RBX::IRenderable*>(motor)) - reinterpret_cast<char*>(motor);
}
size_t nativeVelocityMotorJointOwnerOffset()
{
	RBX::VelocityMotor* motor = reinterpret_cast<RBX::VelocityMotor*>(0x1000);
	return reinterpret_cast<char*>(static_cast<RBX::IJointOwner*>(motor)) - reinterpret_cast<char*>(motor);
}
