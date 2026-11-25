// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: RBX::VistaAPIs::~VistaAPIs (util/FileSystem.cpp); HMODULE handle at offset +4.
extern "C" void __fastcall fn_005a7770(void* self, int unusedEdx)
{
    HMODULE hModule = *reinterpret_cast<HMODULE*>(static_cast<char*>(self) + 4);
    if (hModule)
        FreeLibrary(hModule);
}
