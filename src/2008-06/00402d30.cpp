// from server: 100% by auto
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_espeon_namecachemfcearly_8ee13228801bbb3a.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
typedef HRESULT(ATL::CComTypeInfoHolder::*Method)(ITypeInfo*);
Method forceNameCache=&ATL::CComTypeInfoHolder::LoadNameCache;
