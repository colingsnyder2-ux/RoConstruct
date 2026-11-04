// Layout probe for the inactive native Feature/Hole/MotorFeature header; tests/record_native_feature.py checks
// each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Hole), sizeof(MotorFeature)  0x150  Creatable<Instance>::create<Hole> 00580230 and
//                                              create<MotorFeature> 0057ffc0 allocate 0x150
//   sizeof(Feature)                     0x150  (Hole/MotorFeature add no fields: constructors 0060c840/0060c910
//                                              only store vtables and call setName)
//   IRenderable base                    +0x130 (RTTI base class descriptor, constructor 0060be60 stores its vtable)
//   Feature fields   faceId +0x140, topBottom +0x144, leftRight +0x148, inOut +0x14c (constructor 0060be60,
//                    getters 00609a30/004a1560/00609a40/00609a50, setters 0060c340..0060c3d0)
// Field offsets are compile-time asserts (NativeFeatureLayout is a friend of Feature).
#include <stddef.h>
#include "v8datamodel/Feature.h"

struct NativeFeatureLayout
{
	typedef char FaceId[offsetof(RBX::Feature, faceId) == 0x140 ? 1 : -1];
	typedef char TopBottom[offsetof(RBX::Feature, topBottom) == 0x144 ? 1 : -1];
	typedef char LeftRight[offsetof(RBX::Feature, leftRight) == 0x148 ? 1 : -1];
	typedef char InOut[offsetof(RBX::Feature, inOut) == 0x14c ? 1 : -1];
};

size_t nativeFeatureSize() { return sizeof(RBX::Feature); }
size_t nativeHoleSize() { return sizeof(RBX::Hole); }
size_t nativeMotorFeatureSize() { return sizeof(RBX::MotorFeature); }
size_t nativeFeatureRenderableOffset()
{
	RBX::Feature* feature = reinterpret_cast<RBX::Feature*>(0x1000);
	return reinterpret_cast<char*>(static_cast<RBX::IRenderable*>(feature)) - reinterpret_cast<char*>(feature);
}
