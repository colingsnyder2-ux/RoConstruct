// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdio.h>

// INFERRED: 0x082450c is the FilePacketLogger vftable stored by the original
// deleting destructor; the byte check masks relocation operands.
extern "C" char g_082450c[];

// INFERRED: base destructor func_004baa40, thiscall with no stack arguments.
extern "C" void __fastcall fn_004baa40(void* self);

// INFERRED: compiler-generated vector deleting destructor, written out by hand
// so its body/flags match the original.
extern "C" void* __fastcall fn_004ab7f0(void* self, int unusedEdx, unsigned int flags)
{
    void* stream = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x20c);
    *reinterpret_cast<void**>(self) = g_082450c;
    if (stream)
        fclose((FILE*)stream);
    fn_004baa40(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
