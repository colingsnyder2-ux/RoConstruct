// from server: 100% by king_originala
// from server: 24% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0-dll-rtm roc_unit_5fe21fa90d7ae9fe.cpp

// Candidate translation unit (score above; library headers required).
#define _ATL_APARTMENT_THREADED
#include <windows.h>
#include <atlutil.h>

__declspec(noinline) BOOL roc_atl_unescape_url(
    LPCSTR input,
    LPSTR output,
    LPDWORD outputLength,
    DWORD maximumLength)
{
    return AtlUnescapeUrl(input, output, outputLength, maximumLength);
}
