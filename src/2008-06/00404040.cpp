// from server: 100% by auto
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_04fd8290f2921435.cpp

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

struct RocRegParser : ATL::CRegParser
{
    RocRegParser() : ATL::CRegParser(0) {}
    HRESULT roc_add(ATL::CRegKey& k, LPCTSTR n, LPTSTR t) { return AddValue(k, n, t); }
};

HRESULT roc_regparser_addvalue(RocRegParser* p, ATL::CRegKey& k, LPCTSTR n, LPTSTR t)
{
    return p->roc_add(k, n, t);
}
