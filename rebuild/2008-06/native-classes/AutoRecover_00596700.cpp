// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: boost::function-style 32-byte callable (vtable-like manager ptr + 8 + 24 byte buffer), shape from copy/destroy code.
struct FnObj {
    struct VT { void (__cdecl *manage)(void* src, void* dst, int op); };
    VT* vt;
    int pad;
    char buf[24];
    FnObj() : vt(0) {}
    FnObj(const FnObj& o) {
        vt = 0;
        if (o.vt) {
            vt = o.vt;
            o.vt->manage((void*)o.buf, buf, 0);
        }
    }
    ~FnObj() {
        if (vt) {
            if (vt->manage) vt->manage(buf, buf, 1);
            vt = 0;
        }
    }
};

struct Target;

extern "C" Target* __fastcall fn_005964f0(Target* self, int unusedEdx, FnObj f, std::string s, int a16);

extern "C" Target* __fastcall fn_00596700(Target* self, int unusedEdx, FnObj f, std::string s, int a16)
{
    fn_005964f0(self, 0, f, s, a16);
    return self;
}
