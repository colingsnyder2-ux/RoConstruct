// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Scalar deleting destructor at 0x0060b190: calls the class destructor body fn_0060ae50, then operator delete when flags&1.
// INFERRED: byte pattern in Roblox.exe (push esi; mov esi,ecx; call dtor; test [esp+8],1; je; push esi; call delete; ret 4);
// the class itself is unknown here, so the destructor body is declared as a bare thiscall (fastcall w/o edx use).
#include <new>
extern "C" void __fastcall fn_0060ae50(void* self);
extern "C" void* __fastcall fn_0060b190(void* self, int unusedEdx, unsigned int flags)
{
    fn_0060ae50(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
