// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: atl-8.0 roc_espclaude_c6206da9d4aa0c3f.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 00411530: ATL 8.0 CComVariant(const SAFEARRAY*) emitted out of line
#define _CPPUNWIND 1
#define _DLL
#include <atlbase.h>
#pragma inline_depth(0)
void RocMakeVariant(const SAFEARRAY* psa, VARIANT* out)
{
    CComVariant v(psa);
    v.Detach(out);
}
