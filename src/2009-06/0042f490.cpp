// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0-rtm roc_escapexml_dll_efe68300ee96d383.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <atlenc.h>
int recoveredEscapeXML(const wchar_t* in, int sourceLength, wchar_t* out, int destinationLength, DWORD flags) {
    return ATL::EscapeXML(in, sourceLength, out, destinationLength, flags);
}
