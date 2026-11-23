// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" void* __cdecl fn_00508580(unsigned size, unsigned align);
extern "C" void __cdecl fn_00508a30(void* p, unsigned char v, unsigned n);
// INFERRED: vtable of the G3D-style array type
extern "C" char g_00826c1c[];

// INFERRED: G3D-style array member (vtable, size, data, capacity) passed by value
struct Arr {
    void* vt;
    int a;
    void* data;
    int cap;
    ~Arr() { vt = g_00826c1c; fn_004d7e30(this, 0); }
};

struct Obj {
    int first;
    int f4;
    Arr arr;
    int f18;
    Obj(int a1, Arr src, int a6, int a7);
};

Obj::Obj(int a1, Arr src, int a6, int a7)
{
    f4 = 0;
    arr.vt = g_00826c1c;
    arr.a = 0;
    arr.cap = 10;
    arr.data = fn_00508580(0x28, 0x10);
    fn_00508a30(arr.data, 0, arr.cap * 4);
    f4 = a1;
    if (&arr != &src) {
        fn_004d7e30(&arr, 0);
        fn_004e7880(&arr, 0, (int)&src);
    }
    first = a6;
    f18 = a7;
}
