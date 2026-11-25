// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: the original takes its object pointer in ecx and tail-calls the destructor of
// a std::string member at offset 8. The ABI checker classifies it as __cdecl, so the
// pointer is declared as a plain cdecl parameter here.
extern "C" void __fastcall fn_00485420(void* self, int)
{
    std::string* s = reinterpret_cast<std::string*>(static_cast<char*>(self) + 8);
    s->~basic_string();
}
