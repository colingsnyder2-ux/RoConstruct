// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_geometryvalues880e996718eba644.cpp

// Candidate translation unit (score above; library headers required).
// from server: 87% by king_originala
// roc 2008-06 00615940  unit: RBX::ArrowTool  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00615940
//
// 00615940  6aff                 push -1
// 00615942  6828ae7d00           push 0x7dae28
// 00615947  64a100000000         mov eax, dword ptr fs:[0]
// 0061594d  50                   push eax
// 0061594e  64892500000000       mov dword ptr fs:[0], esp
// 00615955  83ec28               sub esp, 0x28
// 00615958  8b442438             mov eax, dword ptr [esp + 0x38]
// 0061595c  d94010               fld dword ptr [eax + 0x10]
// 0061595f  8d0c24               lea ecx, [esp]
// 00615962  d905d8398400         fld dword ptr [0x8439d8]
// 00615968  51                   push ecx
// 00615969  dcc9                 fmul st(1), st(0)
// 0061596b  83c004               add eax, 4
// 0061596e  d94010               fld dword ptr [eax + 0x10]
// 00615971  50                   push eax
// 00615972  8d542414             lea edx, [esp + 0x14]
// 00615976  d8c9                 fmul st(1)
// 00615978  52                   push edx
// 00615979  d94014               fld dword ptr [eax + 0x14]
// 0061597c  deca                 fmulp st(2)
// 0061597e  d9ca                 fxch st(2)
// 00615980  d95c240c             fstp dword ptr [esp + 0xc]
// 00615984  d9c9                 fxch st(1)
// 00615986  d95c2410             fstp dword ptr [esp + 0x10]
// 0061598a  d95c2414             fstp dword ptr [esp + 0x14]
// 0061598e  e89d2ef0ff           call 0x518830
// 00615993  83c40c               add esp, 0xc
// 00615996  8b442448             mov eax, dword ptr [esp + 0x48]
// 0061599a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0061599e  8b542440             mov edx, dword ptr [esp + 0x40]
// 006159a2  68b8be9700           push 0x97beb8
// 006159a7  50                   push eax
// 006159a8  51                   push ecx
// 006159a9  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 006159ad  52                   push edx
// 006159ae  8d44241c             lea eax, [esp + 0x1c]
// 006159b2  50                   push eax
// 006159b3  c744244400000000     mov dword ptr [esp + 0x44], 0
// 006159bb  e85081ffff           call 0x60db10
// 006159c0  85c0                 test eax, eax
// 006159c2  7418                 je 0x6159dc
// 006159c4  50                   push eax
// 006159c5  e8b645f8ff           call 0x599f80
// 006159ca  83c404               add esp, 4
// 006159cd  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006159d1  64890d00000000       mov dword ptr fs:[0], ecx
// 006159d8  83c434               add esp, 0x34
// 006159db  c3                   ret 
// 006159dc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006159e0  33c0                 xor eax, eax
// 006159e2  64890d00000000       mov dword ptr fs:[0], ecx
// 006159e9  83c434               add esp, 0x34
// 006159ec  c3                   ret 

#include <G3D/Ray.h>
typedef G3D::Vector3 Vector3;
typedef G3D::Ray Ray;
struct PartInstance;

struct GetSetImpl {
    static PartInstance* get(PartInstance*);
};

struct Filter;
extern Filter filter;
extern const float scale;

struct World {
    PartInstance* intersect(const Ray&, void*, void*, void*, Filter*);
};

struct ArrowTool {
    static PartInstance* findPart(const Ray*, World*, void*, void*, void*);
};

PartInstance* ArrowTool::findPart(
    const Ray* input, World* world, void* a, void* b, void* c)
{
    Vector3 direction = input->direction * scale;

    Ray ray = Ray::fromOriginAndDirection(input->origin, direction);
    PartInstance* part = world->intersect(ray, a, b, c, &filter);
    if (part)
        return GetSetImpl::get(part);
    return 0;
}
