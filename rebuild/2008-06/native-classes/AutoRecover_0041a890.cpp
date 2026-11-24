// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

extern "C" int __fastcall fn_0041a820(void* self, int unusedEdx, int a1);

// INFERRED: holder<boost::function<void(shared_ptr<Instance>)>> is 0x28 bytes:
// vtable at +0, 'held' (the boost::function) at +8. Its copy constructor is fn_0041a820,
// a real __thiscall constructor that returns 'this'. It is declared but not defined here,
// so the compiler emits a thiscall (no edx setup) and uses the returned this in eax.
struct HolderFn {
    char data[0x28];
    HolderFn(const void* value);
};

// Alias the member-constructor symbol to the fixed-convention fn_ name.
#pragma comment(linker, "/alternatename:??0HolderFn@@QAE@PBX@Z=@fn_0041a820@12")

// INFERRED: the allocator call at 0x6a0920 is operator new(size_t).
// virtual placeholder* clone() const { return new holder(held); }
extern "C" void* __fastcall fn_0041a890(void* self, int unusedEdx)
{
    return new HolderFn((const char*)self + 8);
}
