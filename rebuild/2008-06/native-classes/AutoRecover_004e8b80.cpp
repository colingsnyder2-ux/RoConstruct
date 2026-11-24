// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object = {int a; int b; Table t (vptr,count,data,cap); int c}; ctor takes a Table by value (4 dwords) + 3 ints.
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);

namespace G3D { struct System { static void* alignedMalloc(unsigned size, unsigned align); static void memset(void* p, unsigned char v, unsigned n); }; }

struct Table {
    virtual ~Table() {}
    int count;
    void* data;
    int cap;
};

struct Obj {
    int a;
    int b;
    Table t;
    int c;
    Obj(Table src, int x, int y, int z, int w);
};

Obj::Obj(Table src, int x, int y, int z, int w)
{
    b = 0;
    t.count = 0;
    t.cap = 10;
    t.data = G3D::System::alignedMalloc(0x28, 0x10);
    G3D::System::memset(t.data, 0, t.cap * 4);
    b = src.count;
    if (&t != &src) {
        fn_004d7e30(&t, 0);
        fn_004e7880(&t, 0, (int)&src);
    }
    a = z;
    c = w;
}
