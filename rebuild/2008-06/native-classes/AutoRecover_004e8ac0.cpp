// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, void* a1);
namespace G3D { namespace System {
void* alignedMalloc(unsigned, unsigned);
void memset(void*, unsigned char, unsigned);
} }

// INFERRED: 4-dword array object (vtable, size, data, capacity), passed by value
struct Arr {
    void** vt; int size; void* data; int cap;
    ~Arr() { fn_004d7e30(this, 0); }
};
extern void* g_arrVt[]; // INFERRED: vtable at 0x826c04

struct Obj {
    int a; int b; Arr arr; int c;
};

extern "C" Obj* __fastcall fn_004e8ac0(Obj* self, int unusedEdx, int a1, Arr src, int a6, int a7)
{
    self->b = 0;
    self->arr.vt = g_arrVt;
    self->arr.cap = 10;
    self->arr.size = 0;
    self->arr.data = G3D::System::alignedMalloc(0x28, 0x10);
    G3D::System::memset(self->arr.data, 0, self->arr.cap * 4);
    self->b = a1;
    if (&self->arr != &src) {
        fn_004d7e30(&self->arr, 0);
        fn_004e7880(&self->arr, 0, &src);
    }
    self->a = a6;
    self->c = a7;
    return self;
}
