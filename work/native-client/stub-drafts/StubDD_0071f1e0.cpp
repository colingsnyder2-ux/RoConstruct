// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Scalar deleting destructor at 0x0071f1e0: calls the class destructor body fn_0071f140, then operator delete when flags&1.
// INFERRED: byte pattern in Roblox.exe (push esi; mov esi,ecx; call dtor; test [esp+8],1; je; push esi; call delete; ret 4);
// the class itself is unknown here, so the destructor body is declared as a bare thiscall (fastcall w/o edx use).
#include <new>
extern "C" void __fastcall fn_0071f140(void* self);
extern "C" void* __fastcall fn_0071f1e0(void* self, int unusedEdx, unsigned int flags)
{
    fn_0071f140(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
