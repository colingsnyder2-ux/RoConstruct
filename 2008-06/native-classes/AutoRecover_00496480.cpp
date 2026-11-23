// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <intrin.h>

// INFERRED: two shared_ptr-like (ptr, control block) pairs; control block has an int count at +4
struct FnCtrl_00496480 {
    int vtbl;
    volatile long count;
};

struct Fn_00496480 {
    std::string a;
    std::string b;
    void* p0;
    FnCtrl_00496480* c0;
    void* p1;
    FnCtrl_00496480* c1;
};

extern "C" Fn_00496480* __fastcall fn_00496480(Fn_00496480* self, int unusedEdx, const Fn_00496480* src)
{
    new (&self->a) std::string(src->a);
    new (&self->b) std::string(src->b);
    self->p0 = src->p0;
    self->c0 = src->c0;
    if (self->c0)
        _InterlockedIncrement(&self->c0->count);
    self->p1 = src->p1;
    self->c1 = src->c1;
    if (self->c1)
        _InterlockedIncrement(&self->c1->count);
    return self;
}
