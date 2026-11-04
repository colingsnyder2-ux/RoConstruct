// Layout and instantiation probe for the inactive native GeometryService header.
// tests/record_native_geometry_service.py checks the size function is `mov eax, imm32; ret` with the allocation size
// the binary passes to malloc, and compares the instantiated creator with the original:
//   sizeof(GeometryService) 0x140  Creatable<Instance>::create<GeometryService> 005c1790
// Field offsets are compile-time asserts (NativeGeometryServiceLayout is a friend of the class).
#include <stddef.h>
#include "v8datamodel/GeometryService.h"

struct NativeGeometryServiceLayout
{
	typedef char GeometryWorkspace[offsetof(RBX::GeometryService, workspace) == 0x130 ? 1 : -1];
	typedef char GeometryPrimitives[offsetof(RBX::GeometryService, primitives) == 0x134 ? 1 : -1];
};

size_t nativeGeometryServiceSize() { return sizeof(RBX::GeometryService); }

// The original emits this creator in the unit that first creates the class.
template boost::shared_ptr<RBX::GeometryService> RBX::Creatable<RBX::Instance>::create<RBX::GeometryService>();

// G3D::Array<PartInstance*> members the original keeps in the GeometryService unit (used by getPartsTouchingExtents
// 0062db60): resize 0062d9e0 (bytes 00..100 of that function-list row) and append 0062daf0.
template void G3D::Array<RBX::PartInstance*>::resize(int, bool);
template void G3D::Array<RBX::PartInstance*>::append(RBX::PartInstance* const&);
