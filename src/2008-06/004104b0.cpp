// from server: 100% by auto
// from server: 100% by EspClaude
// from server: 69% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_b32a63565f36d548.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#define NDEBUG 1
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afx.h>
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
#include <atlcom.h>

class RocCpObj;
class RocCpObj : public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
                 public ATL::IConnectionPointImpl<RocCpObj, &IID_IDispatch, ATL::CComDynamicUnkArray>
{
public:
    HRESULT QueryInterface(REFIID, void**);
};
template HRESULT STDMETHODCALLTYPE ATL::IConnectionPointImpl<RocCpObj, &IID_IDispatch, ATL::CComDynamicUnkArray>::EnumConnections(IEnumConnections**);
