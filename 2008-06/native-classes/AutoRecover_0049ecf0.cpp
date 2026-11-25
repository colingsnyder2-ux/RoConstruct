// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

extern std::string g_00970b88; // INFERRED: global version string at 0x970b88 (std::string, assigned via MSVCP90 operator=(const char*))

extern "C" void fn_0049eb30();
extern "C" void fn_0049eba0();
extern "C" void fn_00491360();
extern "C" void fn_0049a8a0();
extern "C" void fn_0049ec10();
extern "C" void fn_0049ec80();
extern "C" void fn_0049e890();

void __cdecl nativeSetVersion(const char* version)
{
    g_00970b88 = version;
    fn_0049eb30();
    fn_0049eba0();
    fn_00491360();
    fn_0049a8a0();
    fn_0049ec10();
    fn_0049ec80();
    fn_0049e890();
}
