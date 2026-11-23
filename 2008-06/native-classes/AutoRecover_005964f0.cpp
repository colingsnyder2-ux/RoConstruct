// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

struct Fn0Vtable {
    void (__cdecl *manager)(const void* src, void* dst, int op);
};

struct Fn0 {
    Fn0Vtable* vtable;
    int pad;
    char buf[24];
    Fn0() : vtable(0) {}
    Fn0(const Fn0& o) : vtable(0) {
        if (o.vtable) {
            vtable = o.vtable;
            o.vtable->manager(o.buf, buf, 0);
        }
    }
    ~Fn0() {
        if (vtable) {
            if (vtable->manager)
                vtable->manager(buf, buf, 1);
            vtable = 0;
        }
    }
};

struct BoundTask {
    char base[0x40];
    int field40;
};

extern "C" void __fastcall fn_00596340(BoundTask* self, int unusedEdx, Fn0 f, std::string s);

extern "C" BoundTask* __fastcall fn_005964f0(BoundTask* self, int unusedEdx,
                                             Fn0 f, std::string s, int a16)
{
    fn_00596340(self, 0, f, s);
    // INFERRED: the store at +0x40 reads stack arg 8 (E+0x58), the first dword of the string slot, not arg 16.
    self->field40 = *(int*)&s;
    return self;
}
