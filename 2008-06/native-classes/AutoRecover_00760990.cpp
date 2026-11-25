// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: The object type is unknown.
class Local_00760990;

extern "C" int fn_00760650(int a1);

extern "C" Local_00760990* __fastcall fn_00760990(
    Local_00760990* self, int unusedEdx, unsigned int flags)
{
    // INFERRED: The call passes self in ECX despite the supplied cdecl declaration.
    reinterpret_cast<void (__fastcall *)(Local_00760990*)>(fn_00760650)(self);
    if (flags & 1)
        ::operator delete(self);
    return self;
}
