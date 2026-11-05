// from server: 100% by auto
// from server: 100% by EspClaude
// from server: 75% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_acf6ced398afe108.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afx.h>
#include <atlbase.h>
#include <statreg.h>

BOOL roc_expansion_add(ATL::CExpansionVector* v, LPCTSTR key, LPCOLESTR value)
{
    return v->Add(key, value);
}
