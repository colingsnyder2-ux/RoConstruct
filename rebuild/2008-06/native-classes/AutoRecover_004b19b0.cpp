// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

// INFERRED: fn_006a0920 is operator new (cdecl, one size argument), so it is declared
// with a single parameter. The 6-arg declaration in the prompt would not match the
// single push 0x28 in the disassembly.
extern "C" void* fn_006a0920(unsigned size);

// INFERRED: stand-in for boost::any::holder<boost::function<void(shared_ptr<Instance>)>>.
// The real constructor is fn_004b1940 (thiscall, returns this), which sets the vtable
// and copies `held` (at +8). It is bound to the real address via /alternatename.
struct HolderClone
{
    static void* operator new(size_t n) { return fn_006a0920((unsigned)n); }
    explicit HolderClone(const void* value); // out-of-line thiscall ctor = fn_004b1940
    char pad[0x28];
};

// INFERRED: map the out-of-line constructor symbol onto the extern "C" helper's symbol.
#pragma comment(linker, "/alternatename:??0HolderClone@@QAE@PBX@Z=@fn_004b1940@8")

extern "C" void* __fastcall fn_004b19b0(void* self, int unusedEdx)
{
    // virtual placeholder* clone() const { return new holder(held); }
    return new HolderClone((char*)self + 8);
}
