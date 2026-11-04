// Layout probe for the inactive native RBX::SpecialShape header; tests/record_native_special_shape.py checks
// each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(SpecialShape)   0x18c  Creatable<Instance>::create<SpecialShape> 0041ec30 allocates 0x18c
// Field offsets are compile-time asserts (NativeSpecialShapeLayout is a friend of SpecialShape):
//   meshType +0x130, scale +0x134, textureId +0x140, meshId +0x160, vertColor +0x180 (constructor 0059fbb0,
//   destructor 0059fd70, getters 00565e30/0068e8b0/004e5f50/004e5f20/004e5ba0, setters 0059fee0..005a0030)
#include <stddef.h>
#include "v8datamodel/SpecialShape.h"

struct NativeSpecialShapeLayout
{
	typedef char MeshType[offsetof(RBX::SpecialShape, meshType) == 0x130 ? 1 : -1];
	typedef char Scale[offsetof(RBX::SpecialShape, scale) == 0x134 ? 1 : -1];
	typedef char TextureId[offsetof(RBX::SpecialShape, textureId) == 0x140 ? 1 : -1];
	typedef char MeshId[offsetof(RBX::SpecialShape, meshId) == 0x160 ? 1 : -1];
	typedef char VertColor[offsetof(RBX::SpecialShape, vertColor) == 0x180 ? 1 : -1];
	typedef char ContentIdSize[sizeof(RBX::MeshId) == 0x20 && sizeof(RBX::TextureId) == 0x20 ? 1 : -1];
};

size_t nativeSpecialShapeSize() { return sizeof(RBX::SpecialShape); }
