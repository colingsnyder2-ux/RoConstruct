// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Scalar deleting destructor at 0x006fda70: calls the class destructor body fn_006fc880, then operator delete when flags&1.
// INFERRED: byte pattern in Roblox.exe (push esi; mov esi,ecx; call dtor; test [esp+8],1; je; push esi; call delete; ret 4);
// the class itself is unknown here, so the destructor body is declared as a bare thiscall (fastcall w/o edx use).
#include <new>
extern "C" void __fastcall fn_006fc880(void* self);
extern "C" void* __fastcall fn_006fda70(void* self, int unusedEdx, unsigned int flags)
{
    fn_006fc880(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
