// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_king_originala_content_aggregate_ea2170ac4e02f923.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _AFXDLL
#define _AFXDLL
#endif
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#include <afxwin.h>
#include <afxdisp.h>
#include <atlbase.h>
#include <atlcom.h>
#include <sstream>
#include <memory>
#include <exception>
MIDL_INTERFACE("D63F927A-1170-4239-9C1D-06E8A658F300") IContent:IDispatch {
 STDMETHOD(Upload)(BSTR)=0;
};
extern const CLSID CLSID_Content;
extern const IID IID_IContent;
extern const GUID LIBID_RobloxLib;
class ATL_NO_VTABLE CContent:
 public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
 public ATL::CComCoClass<CContent,&CLSID_Content>,
 public ATL::ISupportErrorInfoImpl<&IID_IContent>,
 public ATL::IDispatchImpl<IContent,&IID_IContent,&LIBID_RobloxLib,1,0> {
public:
 std::stringstream stream;
 STDMETHOD(Upload)(BSTR);
 HRESULT _InternalQueryInterface(REFIID,void**)throw();
};

template class ATL::CComAggObject<CContent>;
