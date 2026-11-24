// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: the layout below is reconstructed from the disassembly only.
// The source object starts with a pointer to a manager whose first dword is a
// cdecl function pointer. The clone op is guessed to be 0.
struct FnManager {
    void (__cdecl *manage)(void* in, void* out, int op);
};

struct FnSource {
    FnManager* mgr;   // +0
    int pad;          // +4
    char buf[1];      // +8 (inline functor storage)
};

// INFERRED: a boost::function-like copy constructor with a vtable at +0.
struct FnHolder {
    virtual ~FnHolder() {}
    int unused;          // +4 (left uninitialised)
    FnManager* mgr;      // +8
    int pad;             // +0xc
    char buf[16];        // +0x10

    explicit FnHolder(FnSource* src) {
        mgr = 0;
        if (src->mgr != 0) {
            mgr = src->mgr;
            src->mgr->manage(src->buf, buf, 0);
        }
    }
};

extern "C" FnHolder* __fastcall fn_004b1940(FnHolder* self, int unusedEdx, FnSource* src)
{
    return new (self) FnHolder(src);
}
