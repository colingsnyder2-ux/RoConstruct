// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

extern "C" void __stdcall sub_48D750();
extern "C" void __stdcall sub_494E80();
extern "C" void __stdcall sub_4991B0();
extern "C" void __stdcall sub_499230();
extern "C" void __stdcall sub_498F60();

// std::string::operator=(const char*) is imported from MSVCP80 (call through IAT).
extern std::string g_8BE4B0;

void __cdecl sub_4992B0(const char* name)
{
    g_8BE4B0 = name;
    sub_4991B0();
    sub_499230();
    sub_48D750();
    sub_494E80();
    sub_498F60();
}
