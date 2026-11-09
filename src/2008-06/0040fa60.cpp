// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_2e752666f44a81f5.cpp

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

extern "C" const IID IID_IBrowserViewExternal;
extern "C" const CLSID CLSID_BrowserViewExternal;
extern "C" const GUID LIBID_RobloxLib;

MIDL_INTERFACE("00000000-0000-0000-0000-000000000002")
IBrowserViewExternal : public IDispatch
{
public:
};

struct __declspec(uuid("dd754d30-321a-45a2-a40c-75783afabfab")) _IBrowserViewExternalEvents;

template<class T>
class CProxy_IBrowserViewExternalEvents :
    public IConnectionPointImpl<T, &__uuidof(_IBrowserViewExternalEvents)>
{
};

class ATL_NO_VTABLE CBrowserViewExternal :
    public CComObjectRootEx<CComSingleThreadModel>,
    public CComCoClass<CBrowserViewExternal, &CLSID_BrowserViewExternal>,
    public ISupportErrorInfoImpl<&IID_IBrowserViewExternal>,
    public IConnectionPointContainerImpl<CBrowserViewExternal>,
    public CProxy_IBrowserViewExternalEvents<CBrowserViewExternal>,
    public IDispatchImpl<IBrowserViewExternal, &IID_IBrowserViewExternal, &LIBID_RobloxLib, 1, 0>
{
public:
    CBrowserViewExternal() : m_flag(0) {}

    BEGIN_COM_MAP(CBrowserViewExternal)
        COM_INTERFACE_ENTRY(IBrowserViewExternal)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CBrowserViewExternal)
        CONNECTION_POINT_ENTRY(__uuidof(_IBrowserViewExternalEvents))
    END_CONNECTION_POINT_MAP()

    short m_flag;
};

template ATL::CComAggObject<CBrowserViewExternal>::CComAggObject(void*);
