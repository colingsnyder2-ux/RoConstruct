// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>
#include <new>

// INFERRED: fn_006a0920 is the CRT allocator (operator new); the disassembly pushes one
// argument (0x28) and pops 4 bytes afterwards, so it is declared with a single parameter.
extern "C" void* fn_006a0920(size_t size);

// INFERRED: layout stand-in for any::holder<boost::function<void(shared_ptr<Instance>)>>,
// size 0x28. Its copy constructor is the real __thiscall helper at 0x004b1dc0
// (sets the vptr and copies the function). It is declared as a constructor so the
// compiler emits a true __thiscall call (no edx setup).
// NOTE: the constructor's symbol is not fn_004b1dc0; it is declared here only so the
// call is a real __thiscall.
struct HolderFn
{
    char data[0x28];
    static void* operator new(size_t) { return fn_006a0920(0x28); }
    // INFERRED: the unwind path of the new-expression frees through the normal operator delete.
    static void operator delete(void* p) { ::operator delete(p); }
    HolderFn(const void* value);
};

// any::holder<function<...>>::clone() const  { return new holder(held); }
extern "C" HolderFn* __fastcall fn_004b1e30(HolderFn* self, int unusedEdx)
{
    return new HolderFn((const char*)self + 8);
}
