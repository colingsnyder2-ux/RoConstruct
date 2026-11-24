// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: the function takes no real arguments. The one stack dword is a hidden
// return slot (sret) for a shared_ptr-like value that is copied from a global.
// The two words are px and pn, and the refcount sits at pn+4 after the vptr.
struct SpCountedBase {
    void* vptr;
    volatile long use_count;
    volatile long weak_count;
};

struct SharedPtrLike {
    void* px;
    SpCountedBase* pn;

    SharedPtrLike(const SharedPtrLike& o) : px(o.px), pn(o.pn) {
        if (pn)
            _InterlockedIncrement(&pn->use_count);
    }
};

// INFERRED: global shared pointer at 0x96c25c (px) / 0x96c260 (pn)
extern "C" SharedPtrLike g_global_0096c25c;

extern "C" SharedPtrLike fn_004306c0()
{
    return g_global_0096c25c;
}
