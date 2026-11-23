// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: boost::function-style object; vtable-like struct whose first slot is the clone/manager call.
struct FnVtable {
    void (*manager)(const void* in, void* out, int op);
};

struct FnObj {
    int tag;
    int pad4;
    const FnVtable* vtable;
    int padC;
    char buf[16];

    FnObj(const FnObj& o) {
        tag = o.tag;
        vtable = 0;
        if (o.vtable) {
            vtable = o.vtable;
            o.vtable->manager(o.buf, buf, 0);
        }
    }
};

extern "C" void fn_0055f6a0(void* dest, const FnObj* src)
{
    // INFERRED: placement-new copy construct (SEH state saves dest for unwinding)
    ::new (dest) FnObj(*src);
}
