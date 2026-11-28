// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Scalar deleting destructor at 0x00476130: calls the class destructor body fn_00475d60, then operator delete when flags&1.
// INFERRED: byte pattern in Roblox.exe (push esi; mov esi,ecx; call dtor; test [esp+8],1; je; push esi; call delete; ret 4);
// the class itself is unknown here, so the destructor body is declared as a bare thiscall (fastcall w/o edx use).
#include <new>
extern "C" void __fastcall fn_00475d60(void* self);
extern "C" void* __fastcall fn_00476130(void* self, int unusedEdx, unsigned int flags)
{
    fn_00475d60(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
