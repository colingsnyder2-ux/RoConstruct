// from server: 100% by colin
// from server: 0% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espeon_contentinterface6da1be04c6837004.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<atlcom.h>, <roc_espeon_atlobjectinlineheader81dc549e9ad7a653.cpp>)
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
#include <sstream>

extern const GUID IID_IContent;
extern const GUID CLSID_Content;
extern const GUID LIBID_RobloxLib;

struct ATL_NO_VTABLE IContent : public IDispatch
{
    virtual HRESULT STDMETHODCALLTYPE Load(BSTR url) = 0;
};

class ATL_NO_VTABLE CContent :
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CContent, &CLSID_Content>,
    public ATL::ISupportErrorInfoImpl<&IID_IContent>,
    public ATL::IDispatchImpl<IContent, &IID_IContent, &LIBID_RobloxLib, 1, 0>
{
public:
    std::stringstream stream;

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CContent)
    COM_INTERFACE_ENTRY_IID(IID_IContent, IContent)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

    STDMETHOD(Load)(BSTR url);
};

template class ATL::CComObject<CContent>;
ATL::_ATL_CREATORFUNC* roc_creator = &ATL::CComCreator<ATL::CComObject<CContent> >::CreateInstance;
