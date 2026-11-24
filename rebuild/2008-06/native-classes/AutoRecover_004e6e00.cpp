// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" void __fastcall fn_004f0810(void* self);
extern "C" void __fastcall fn_00502a70(void* self);
extern "C" int __fastcall fn_004e60f0(void* self, int unusedEdx, void* a1);

// INFERRED: local placement new, avoids <new>
inline void* operator new(unsigned int, void* p) { return p; }
inline void operator delete(void*, void*) {}

// INFERRED: element type of the 1-element array at +0x10; ctor/dtor are the vector-ctor/dtor callbacks
struct Elem4 {
    int v;
    Elem4() { fn_004f0810(this); }
    ~Elem4() { fn_00502a70(this); }
};

// INFERRED: class name/layout from the disassembly
struct Obj004e6e00 {
    int a0;
    float x, y, z;
    Elem4 arr[1];
    int a14;
    Obj004e6e00() : x(0.0f), y(0.0f), z(0.0f) {}
};

// INFERRED: a4 is a by-value Elem4 parameter (callee destroys it via vector dtor, passed by address)
extern "C" Obj004e6e00* __fastcall fn_004e6e00(Obj004e6e00* self, int unusedEdx,
                                                float x, float y, float z,
                                                Elem4 a4, int a5, int a6)
{
    new (self) Obj004e6e00();
    self->x = x;
    self->y = y;
    self->z = z;
    fn_004e60f0(self->arr, 0, &a4);
    self->a0 = a5;
    self->a14 = a6;
    return self;
}
