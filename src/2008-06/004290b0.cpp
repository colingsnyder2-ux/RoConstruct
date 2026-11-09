// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll roc_espeon_atlreporterrorunwind59eab001a8c0d0a3.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <atlbase.h>
#include <atlcom.h>
typedef HRESULT (WINAPI *Report)(const CLSID&,LPCSTR,DWORD,LPCSTR,const IID&,HRESULT);
Report reportFunction=static_cast<Report>(&ATL::AtlReportError);
