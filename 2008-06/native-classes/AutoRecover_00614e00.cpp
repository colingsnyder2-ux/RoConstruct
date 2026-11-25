// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: object is RBX::Reflection::EnumDesc<RBX::PartType>; laid out raw here.
// Base EnumDescriptor occupies [0x00,0x30), two std::map at 0x30/0x50,
// five vector-like containers (proxy + first/last/end) at 0x70..0xd0 (0x18 each).
struct EnumDescPartType;

namespace RBX { enum PartType { BALL = 0, BLOCK = 1, CYLINDER = 2 }; }

// INFERRED: EnumDescriptor ctor (protected member, called via thiscall)
extern "C" void* __fastcall fn_0056c590(EnumDescPartType* self, int unusedEdx,
                                        const char* name, const std::type_info* type);
// INFERRED: std::_Tree ctor (identical-code-folded instantiation)
extern "C" void* __fastcall fn_00446110(void* self, int unusedEdx,
                                        const void* comp, const void* alloc);
// operator new style allocator
extern "C" int fn_006a0920(int a1);
// INFERRED: EnumDesc::addPair (folded instantiation)
extern "C" void __fastcall fn_0064d530(EnumDescPartType* self, int unusedEdx,
                                       int value, const char* name);

extern "C" char g_00832dc4;   // INFERRED: vftable of EnumDesc<PartType>

struct VecLike
{
    void** proxy;
    int    pad[2];
    void*  first;
    void*  last;
    void*  end;
};

struct EnumDescPartType
{
    void*   vfptr;
    char    base[0x2c];
    char    mapA[0x20];
    char    mapB[0x20];
    VecLike v0;
    VecLike v1;
    VecLike v2;
    VecLike v3;
    VecLike v4;
};

static inline void initVec(VecLike* v)
{
    void** p = (void**)fn_006a0920(4);
    if (p != 0)
        *p = v;
    else
        p = 0;
    v->proxy = p;
    v->first = 0;
    v->last = 0;
    v->end = 0;
}

extern "C" EnumDescPartType* __fastcall fn_00614e00(EnumDescPartType* self, int unusedEdx)
{
    char comp;
    char alloc;

    fn_0056c590(self, 0, "PartType", &typeid(RBX::PartType));
    self->vfptr = &g_00832dc4;
    fn_00446110(self->mapA, 0, &comp, &alloc);
    fn_00446110(self->mapB, 0, &comp, &alloc);
    initVec(&self->v0);
    initVec(&self->v1);
    initVec(&self->v2);
    initVec(&self->v3);
    initVec(&self->v4);

    fn_0064d530(self, 0, RBX::BALL, "Ball");
    fn_0064d530(self, 0, RBX::BLOCK, "Block");
    fn_0064d530(self, 0, RBX::CYLINDER, "Cylinder");
    return self;
}
