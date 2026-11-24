// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

extern "C" int __fastcall fn_004e6050(void* self, int unusedEdx, int a1);

// INFERRED: element type with non-trivial ctor/dtor (0x4f0810 / 0x502a70 in the original)
struct Elem4 {
    float v;
    __declspec(noinline) Elem4() {}
    __declspec(noinline) ~Elem4() {}
};

// INFERRED: 4-element array passed by value as args 4..7 (destroyed at function end)
struct Quad4 {
    Elem4 e[4];
};

// INFERRED: object layout from the member accesses in the disassembly
struct Fn004e6d50Obj {
    int   field0;
    float x, y, z;
    Quad4 quad;      // +0x10
    int   field20;
};

extern "C" Fn004e6d50Obj* __fastcall fn_004e6d50(Fn004e6d50Obj* self, int unusedEdx,
                                                 float x, float y, float z,
                                                 Quad4 q,
                                                 int a8, int a9)
{
    self->x = 0.0f;
    self->y = 0.0f;
    self->z = 0.0f;
    new (&self->quad) Quad4();
    self->x = x;
    self->y = y;
    self->z = z;
    fn_004e6050(&self->quad, 0, (int)&q);
    self->field0  = a8;
    self->field20 = a9;
    return self;
}
