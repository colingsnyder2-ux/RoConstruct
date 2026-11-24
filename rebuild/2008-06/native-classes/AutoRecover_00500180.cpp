// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: no class headers were provided, so the types below are
// file-local stand-ins and this is only an approximate reconstruction.
// The Level reference count lives at +4, and the Level array is a G3D
// Array at this+0xc (data pointer at +0, size at +4).

extern "C" void __fastcall fn_00548570(void* self);                 // Mesh::Mesh()
extern "C" int  __fastcall fn_006a0920(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_004dd2e0(void* self, int unusedEdx, int primitive); // Level::Level(Primitive)
extern "C" void __fastcall fn_004dcbb0(void* arr, int unusedEdx, void* ref);      // Array<RCP<Level>>::append
extern "C" void __fastcall fn_0045ad90(void* self);                 // zeroWeakPointers
extern "C" int  __fastcall fn_004fdaf0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" void __fastcall fn_00500d30(void* self, int unusedEdx, int purpose);   // LevelBuilder::build

extern "C" void* g_008271b8[];   // INFERRED: vtable of this mesh class
extern "C" float g_0083a3e4;     // INFERRED: float scale constant

struct RCObj {
    void** vtbl;
    volatile LONG refs;
};

static void releaseRef(RCObj* p)
{
    if (p) {
        if (InterlockedDecrement(&p->refs) == 0) {
            fn_0045ad90(p);
            typedef void (__thiscall *Dtor)(RCObj*, int);
            ((Dtor)p->vtbl[0])(p, 1);
        }
    }
}

struct MeshObj {
    void** vtbl;
    int    pad;
    int    pad2;
    RCObj** levelData; // +0x0c
    int    levelSize;  // +0x10
};

extern "C" MeshObj* __fastcall fn_00500180(MeshObj* self, int unusedEdx, float* extents, int arg2)
{
    fn_00548570(self);
    self->vtbl = g_008271b8;

    float* hi = &extents[2];
    float* pick = (extents[0] <= extents[2]) ? hi : extents;
    float scaled = *pick * g_0083a3e4;

    RCObj* lvl = (RCObj*)fn_006a0920(0, 0, 0x28);
    if (lvl) {
        fn_004dd2e0(lvl, 0, 5);
    }

    RCObj* ref = 0;
    if (lvl) {
        ref = lvl;
        InterlockedIncrement(&lvl->refs);
    }
    fn_004dcbb0((char*)self + 0xc, 0, &ref);
    releaseRef(ref);

    RCObj** data = self->levelData;
    RCObj* last = data[self->levelSize - 1];
    RCObj* held = 0;
    if (last) {
        held = last;
        InterlockedIncrement(&last->refs);
    }

    char builder[0x30];
    union { float f; int i; } sc;
    sc.f = scaled;
    fn_004fdaf0(builder, 0, sc.i, arg2, 9, (int)&extents[0], (int)&extents[1], (int)hi, (int)held);
    fn_00500d30(builder, 0, 0);

    releaseRef(held);
    return self;
}
