// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>

// INFERRED: no native headers were provided, so the types below are minimal local stand-ins.
// The shared_ptr is modelled as a plain {px, pn} pair.
struct SharedPtrStats {
    void* px;
    void* pn;
};

// INFERRED: Creatable<Instance>::Deleter is passed by value as one 4-byte stack argument, initialised to 0.
struct CreatableDeleter {
    int flag;
};

// RBX::Stats::StatsService::StatsService() at 0x00458520 (thiscall)
extern "C" void __fastcall fn_00458520(void* self, int unusedEdx);

// boost::shared_ptr<...>::shared_ptr<..., Creatable<Instance>::Deleter>(T*, Deleter) at 0x00456f10
// (thiscall, callee pops the 8 bytes of stack args)
extern "C" void __fastcall fn_00456f10(SharedPtrStats* self, int unusedEdx, void* p, CreatableDeleter d);

// INFERRED: the target is unnamed, so it uses the fn_ convention. It returns the shared_ptr
// through a hidden return pointer, which matches the disassembly (esi = arg, eax = esi).
extern "C" SharedPtrStats fn_00458590()
{
    SharedPtrStats result;
    CreatableDeleter deleter;
    deleter.flag = 0;

    void* mem = malloc(0x130);
    void* obj = 0;
    if (mem) {
        fn_00458520(mem, 0);
        obj = mem;
    }
    fn_00456f10(&result, 0, obj, deleter);
    return result;
}
