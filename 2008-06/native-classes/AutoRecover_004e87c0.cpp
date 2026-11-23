// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_004d7dc0(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7810(void* self, int unusedEdx, int a1);
namespace G3D { namespace System {
void* alignedMalloc(unsigned size, unsigned align);
void memset(void* p, unsigned char v, unsigned n);
} }

// placement new declared locally (no <new> include)
inline void* operator new(unsigned, void* p) { return p; }
inline void operator delete(void*, void*) {}

// INFERRED: 16-byte array-like helper (vptr, size, data, capacity) passed by value
struct Arr {
    virtual ~Arr() { fn_004d7dc0(this, 0); }
    int size;
    void* data;
    int cap;
    Arr() : size(0), cap(10) {
        data = G3D::System::alignedMalloc(0x28, 0x10);
        G3D::System::memset(data, 0, cap * 4);
    }
    Arr& operator=(const Arr& o) {
        if (this != &o) {
            fn_004d7dc0(this, 0);
            fn_004e7810(this, 0, (int)&o);
        }
        return *this;
    }
};

struct Obj {
    int a0;
    int a4;
    Arr arr;
    int a18;
    Obj(int arg1, Arr src, int arg6, int arg7) {
        a4 = 0;
        arr = src;
        a4 = arg1;
        a0 = arg6;
        a18 = arg7;
    }
};

extern "C" Obj* __fastcall fn_004e87c0(Obj* self, int unusedEdx, int arg1, Arr arr, int arg6, int arg7)
{
    return new (self) Obj(arg1, arr, arg6, arg7);
}
