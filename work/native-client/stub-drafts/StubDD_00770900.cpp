// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Scalar deleting destructor at 0x00770900: calls the class destructor body fn_0076f9c0, then operator delete when flags&1.
// INFERRED: byte pattern in Roblox.exe (push esi; mov esi,ecx; call dtor; test [esp+8],1; je; push esi; call delete; ret 4);
// the class itself is unknown here, so the destructor body is declared as a bare thiscall (fastcall w/o edx use).
#include <new>
extern "C" void __fastcall fn_0076f9c0(void* self);
extern "C" void* __fastcall fn_00770900(void* self, int unusedEdx, unsigned int flags)
{
    fn_0076f9c0(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
