// Layout probe for the inactive native ClickDetector header; tests/record_native_click_detector.py checks each
// function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(ClickDetector)   0x14c  Creatable<Instance>::create<ClickDetector> 005c0b60 allocates 0x14c
//   IRenderable base        0x130  constructor 006297e0 stores the IRenderable vtable 00845a68 at +0x130
//   sizeof(Instance)        0x130
// Field offsets are compile-time asserts (NativeClickDetectorLayout is a friend of ClickDetector):
//   zeroInitialized +0x140 (constructor), maxActivationDistance +0x144 (constructor 32.0f, BoundProp member pushed by
//   initializer 007f7d90, click 00629ac0, isClickable 00629b20), frontendMouseClick +0x148 (getter 0068e8c0, click).
#include <stddef.h>
#include "v8datamodel/ClickDetector.h"

struct NativeClickDetectorLayout
{
	typedef char ZeroInitialized[offsetof(RBX::ClickDetector, zeroInitialized) == 0x140 ? 1 : -1];
	typedef char MaxActivationDistance[offsetof(RBX::ClickDetector, maxActivationDistance) == 0x144 ? 1 : -1];
	typedef char FrontendMouseClick[offsetof(RBX::ClickDetector, frontendMouseClick) == 0x148 ? 1 : -1];
};

size_t nativeClickDetectorSize() { return sizeof(RBX::ClickDetector); }
size_t nativeClickDetectorRenderable()
{
	return (size_t)static_cast<RBX::IRenderable*>((RBX::ClickDetector*)0x1000) - 0x1000;
}
size_t nativeInstanceSize() { return sizeof(RBX::Instance); }
