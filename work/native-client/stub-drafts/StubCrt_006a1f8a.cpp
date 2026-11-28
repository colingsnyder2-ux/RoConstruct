// native-flags: /O1 /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0x006a1f8a: CRT operator new(size_t, const nothrow_t&) (tools/msvc800sp1/VC/crt/src/newopnt.cpp, statically linked from msvcrt.lib).
#define _USE_ANSI_CPP
#include <new>
void * __cdecl operator new(size_t count, const std::nothrow_t&) throw()
{
    void *p;
    try
    {
        p = operator new(count);
    }
    catch (...)
    {
        p = 0;
    }
    return (p);
}
