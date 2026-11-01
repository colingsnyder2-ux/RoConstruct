// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_13551b6034a59a28.cpp

// Candidate translation unit (score above; library headers required).
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
#include <atlctl.h>

extern "C" const IID IID_IApp;
extern "C" const CLSID CLSID_App;
extern "C" const GUID LIBID_RobloxLib;

MIDL_INTERFACE("00000000-0000-0000-0000-000000000001")
IApp : public IDispatch
{
public:
};

template <class T, DWORD dwSupportedSafety>
class IObjectSafetyRobloxImpl : public IObjectSafety
{
public:
    IObjectSafetyRobloxImpl() : m_dwCurrentSafety(0) {}
    STDMETHOD(GetInterfaceSafetyOptions)(REFIID riid, DWORD* pdwSupportedOptions, DWORD* pdwEnabledOptions);
    STDMETHOD(SetInterfaceSafetyOptions)(REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions);
    DWORD m_dwCurrentSafety;
};

class ATL_NO_VTABLE CApp :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CApp, &CLSID_App>,
    public ISupportErrorInfoImpl<&IID_IApp>,
    public IObjectSafetyRobloxImpl<CApp, 1>,
    public IObjectWithSiteImpl<CApp>,
    public IDispatchImpl<IApp, &IID_IApp, &LIBID_RobloxLib, 1, 2>
{
public:
    BEGIN_COM_MAP(CApp)
        COM_INTERFACE_ENTRY(IApp)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IObjectSafety)
        COM_INTERFACE_ENTRY(IObjectWithSite)
    END_COM_MAP()
};

template ATL::CComAggObject<CApp>::CComAggObject(void*);
