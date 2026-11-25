// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: fn_006a0920 is operator new(size_t); the disassembly pushes only the size.
// INFERRED: fn_0062a360 is the out-of-line holder(const ValueType&) constructor (thiscall).
// The constructor is declared as a real thiscall member and aliased to fn_0062a360 at link
// time so no edx dummy load is emitted (original only sets ecx).
#include <new>

extern "C" void* fn_006a0920(unsigned size);
extern "C" int __fastcall fn_0062a360(void* self, int unusedEdx, int a1);

struct FuncHolder
{
    // INFERRED: opaque layout; vptr at 0, boost::function (0x20 bytes) at 8, total 0x28
    char raw[0x28];

    static void* operator new(unsigned size) { return fn_006a0920(size); }
    static void operator delete(void* p) { ::operator delete(p); }

    FuncHolder(const void* value); // INFERRED: == fn_0062a360 (thiscall, 1 stack arg)
};

#pragma comment(linker, "/alternatename:??0FuncHolder@@QAE@PBX@Z=@fn_0062a360@12")

extern "C" FuncHolder* __fastcall fn_0062a3d0(FuncHolder* self, int unusedEdx)
{
    return new FuncHolder(self->raw + 8);
}
