// from server: 100% by auto
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_daa9467bfe875fbf.cpp

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

struct RocRegObject : ATL::CRegObject {
    static HRESULT (ATL::CRegObject::*get())(LPCOLESTR, LPCTSTR, LPCTSTR, BOOL) { return &RocRegObject::RegisterFromResource; }
};
HRESULT (ATL::CRegObject::*roc_rfr)(LPCOLESTR, LPCTSTR, LPCTSTR, BOOL) = RocRegObject::get();
