// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <cstddef>

// INFERRED: the callee at 0x6a0920 is the CRT operator new, called with a single size argument.
extern "C" void* fn_006a0920(unsigned size);

// INFERRED: holder<boost::function<...>> is a 0x28-byte object. Its out-of-line copy
// constructor lives at 0x49f5b0 and is called thiscall (ecx only, no edx) and returns this.
// It is declared as a real constructor and left undefined here, so the call site compiles to
// a plain thiscall that returns this. The linker alias below binds it to fn_0049f5b0.
struct FuncHolder
{
    char data[0x28];

    FuncHolder(const void* srcHeld);

    static void* operator new(size_t n)
    {
        return fn_006a0920((unsigned)n);
    }
    static void operator delete(void* p)
    {
        ::operator delete(p);
    }
};

// INFERRED: alias the undefined constructor symbol to the shared fn_0049f5b0 symbol (fastcall decoration).
#pragma comment(linker, "/alternatename:??0FuncHolder@@QAE@PBX@Z=@fn_0049f5b0@12")

extern "C" FuncHolder* __fastcall fn_0049f620(FuncHolder* self, int unusedEdx)
{
    // clone(): return new holder(held);  held lives at this+8
    return new FuncHolder((const char*)self + 8);
}
