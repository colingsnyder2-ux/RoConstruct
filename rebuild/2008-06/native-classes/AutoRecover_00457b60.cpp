// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: headers not shown, so this file is self-contained with minimal stand-ins.
// Shape: a cached service lookup. Slot index = fn_00455ea0(), cache = vector<shared_ptr<Instance>> at this+0x190.
#include <vector>

namespace RBX { class Instance; }

struct SpCount { void* pi; };
struct SpInstance { RBX::Instance* px; SpCount pn; };

extern "C" int fn_00455ea0(void);
extern "C" void fn_00557330(void (*init)(void), long* flag); // boost::call_once, cdecl
extern "C" void fn_00455dc0_dummy(void);
extern "C" const void* fn_00455dc0(void);                     // Name::doDeclare<Stats::sStats>
extern "C" void __fastcall fn_00572a90(void* self, int unusedEdx, SpInstance* out, const void* name); // findServiceByClassName

struct ServiceCacheHolder {
    char pad[0x190];
    std::vector<SpInstance> cache; // INFERRED: begin/end at +0x19c/+0x1a0 (debug-iterator proxy at +0x190)
};

extern "C" RBX::Instance* __fastcall fn_00457b60(ServiceCacheHolder* self)
{
    static long once1, once2;
    extern void initA(void);
    extern void initB(void);
    fn_00557330(initA, &once1);
    unsigned idx = (unsigned)fn_00455ea0();
    if (self->cache.size() < idx + 1)
        self->cache.resize(idx + 1);
    else if (self->cache[idx].px)
        return self->cache[idx].px;

    fn_00557330(initB, &once2);
    SpInstance found = {0, {0}};
    fn_00572a90(self, 0, &found, fn_00455dc0());
    if (!found.px)
        return 0;
    self->cache[idx] = found;
    return found.px;
}
