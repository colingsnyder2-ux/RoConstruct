// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: Object contains a string at offset 0x14.
extern "C" void __fastcall fn_0043d0d0(void* self, int)
{
    reinterpret_cast<std::string*>(static_cast<char*>(self) + 0x14)->~basic_string();
}
