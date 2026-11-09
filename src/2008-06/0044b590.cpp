// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0-dll-rtm roc_espeon_nativeatldirabi3272e783e3521ab9.cpp

// Candidate translation unit (score above; library headers required).
#include <atlbase.h>
HRESULT (__stdcall *nativeRegisterTypeLib)(HINSTANCE, LPCOLESTR) = &ATL::AtlRegisterTypeLib;
UINT (WINAPI *nativeDirLength)(LPCOLESTR) = &ATL::AtlGetDirLen;
