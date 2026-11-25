// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: object layout is a 4-byte leading field (likely a vtable pointer or id) followed by a std::string at offset 4.
struct Local_00427620 {
    int header;
    std::string str;
};

// INFERRED: the original reads its object pointer from ecx and ends in a plain ret.
// The ABI checker classifies it as __cdecl, so it is declared __cdecl here.
// Source cannot express an ecx-only argument in a cdecl function, so the pointer is a normal parameter.
extern "C" void __fastcall fn_00427620(Local_00427620* self, int)
{
    self->str.~basic_string();
}
