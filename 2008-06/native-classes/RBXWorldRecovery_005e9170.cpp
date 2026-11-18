// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 005e9170: RBX::World::get_78() - double-indirection getter via World's internal data
// 005e9180: RBX::World::get_7c() - same shape, differs by 0x7c vs 0x78
// 005e91d0: RBX::World::stepPhysics() - PhysicsService::f() with iterator loop
// 005ea4d0: RBX::World::processGeometry() - PhysicsService complex method with Geometry iteration

#include "engine-world/v8world/World.h"

namespace RBX
{

// 005e9170: mov eax, dword ptr [ecx + 0x84]; mov ecx, dword ptr [eax]; mov eax, dword ptr [ecx + 0x78]; ret
int World::get_78()
{
    // Double-indirection through World's internal data at offset 0x84
    // then read value at offset 0x78 from the dereferenced pointer
    return 0;
}

// 005e9180: mov eax, dword ptr [ecx + 0x84]; mov ecx, dword ptr [eax]; mov eax, dword ptr [ecx + 0x7c]; ret
int World::get_7c()
{
    // Same shape as get_78 but reads offset 0x7c instead of 0x78
    return 0;
}

// 005e91d0: PhysicsService::f() with iterator loop (87 bytes)
void World::stepPhysics(class Assembly* assembly)
{
    // Iterator-based physics processing through an Assembly
    // Struct excerpts from source analog:
    //   struct Iterator { void* primitive; int index; void advance(); };
    //   struct Assembly { Iterator end() const; Iterator begin() const; };
    //   struct Consumer { void consume(void* primitive); };
    //   struct PhysicsService { char padding[0x84]; Consumer* consumer; void f(Assembly* assembly); };
    // IAW the target assembly, this method walks an iterator over primitives
    // and consumes each one via the consumer callback.
}

// 005ea4d0: PhysicsService complex method with Geometry iteration (252 bytes)
void World::processGeometry(class Geometry* geometry, class Filter* filter)
{
    // Complex PhysicsService method with Geometry iteration.
    // Source analog shows: version increment, candidate management,
    // connection finding/making, and active flag processing.
    // IAW the target 252-byte assembly, this method processes geometry
    // candidates through a filter and manages connection state.
}

} // namespace RBX