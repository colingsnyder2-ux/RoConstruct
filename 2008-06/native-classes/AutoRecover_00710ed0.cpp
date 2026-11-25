// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CBrowserDoc.h"

// INFERRED: The target destroys a CString at offset 4.
// A cdecl parameter is stack-passed, so this cannot reproduce the ECX-based thunk.
extern "C" void __fastcall fn_00710ed0(void* self, int)
{
    reinterpret_cast<CString*>(static_cast<char*>(self) + 4)->~CString();
}
