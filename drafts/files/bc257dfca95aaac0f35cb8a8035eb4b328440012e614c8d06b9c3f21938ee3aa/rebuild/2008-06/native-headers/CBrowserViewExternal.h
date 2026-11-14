#pragma once
// >>> native-status (generated) -- do not edit >>>
// CBrowserViewExternal | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d0dbfffc | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>

// Declarations only (bodies live in the original's CBrowserViewExternal unit).
// Bases and offsets from the RTTI of ATL::CComObjectNoLock<CBrowserViewExternal> (vtable 0080d778):
// ISupportErrorInfoImpl +0, IConnectionPointContainerImpl +4, CProxy_IBrowserViewExternalEvents +8
// (CComDynamicUnkArray +0xc/+0x10), IDispatchImpl<IBrowserViewExternal> +0x14, CComObjectRootEx +0x18,
// CComCoClass +0x1c (empty). The creator 0040fbf0 allocates 0x20 bytes and clears the VARIANT_BOOL at +0x1c.
extern "C" const IID IID_IBrowserViewExternal;
extern "C" const CLSID CLSID_BrowserViewExternal;
extern const IID LIBID_RobloxLib;
struct __declspec(uuid("dd754d30-321a-45a2-a40c-75783afabfab")) _IBrowserViewExternalEvents;

// IDispatchImpl vtable 0080d714 slots 7 and 8.
// IID from the first entry of the COM map table 0080d64c.
struct __declspec(novtable) __declspec(uuid("e2ece10d-9997-414b-b40b-0928b8f3cadb")) IBrowserViewExternal : IDispatch {
    STDMETHOD(get_IsIDE)(VARIANT_BOOL* result) = 0;   // 00410f90: copies the VARIANT_BOOL at +0x1c
    STDMETHOD(GetApp)(IDispatch** result) = 0;        // 00410fe0: "IBrowserViewExternal::GetApp-0x%X"; CoCreateInstance of
                                                      // CLSID eec6b245-01be-4a51-92ba-2afdaf97581b / IID 54f58168-734e-4379-b198-64b0826a002e
};

template <class T>
class CProxy_IBrowserViewExternalEvents
    : public ATL::IConnectionPointImpl<T, &__uuidof(_IBrowserViewExternalEvents), ATL::CComDynamicUnkArray> {
};

class ATL_NO_VTABLE CBrowserViewExternal
    : public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
      public ATL::CComCoClass<CBrowserViewExternal, &CLSID_BrowserViewExternal>,
      public ATL::ISupportErrorInfoImpl<&IID_IBrowserViewExternal>,
      public ATL::IConnectionPointContainerImpl<CBrowserViewExternal>,
      public CProxy_IBrowserViewExternalEvents<CBrowserViewExternal>,
      public ATL::IDispatchImpl<IBrowserViewExternal, &IID_IBrowserViewExternal, &LIBID_RobloxLib, 1, 0> {
public:
    DECLARE_REGISTRY_RESOURCEID(119)
    CBrowserViewExternal() : isIDE(VARIANT_FALSE) {}
    STDMETHOD(get_IsIDE)(VARIANT_BOOL* result);
    STDMETHOD(GetApp)(IDispatch** result);

    // _ATL_INTMAP_ENTRY table 0080d64c: IBrowserViewExternal +0x14, IDispatch +0x14, ISupportErrorInfo +0,
    // IConnectionPointContainer +4 (all simple entries).
    BEGIN_COM_MAP(CBrowserViewExternal)
        COM_INTERFACE_ENTRY(IBrowserViewExternal)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IConnectionPointContainer)
    END_COM_MAP()

    BEGIN_CONNECTION_POINT_MAP(CBrowserViewExternal)
        CONNECTION_POINT_ENTRY(__uuidof(_IBrowserViewExternalEvents))
    END_CONNECTION_POINT_MAP()

    VARIANT_BOOL isIDE;     // +0x1c: set by CBrowserView::OnGetExternal (dynamic_cast to CIDEBrowserView)
};

// Original 0040fbf0: new ATL::CComObjectNoLock<CBrowserViewExternal> (0x20 bytes) with the ATL construct
// protocol; cdecl, second argument unused by the body (CBrowserView::OnGetExternal passes 0).
HRESULT __cdecl createBrowserViewExternal(ATL::CComObjectNoLock<CBrowserViewExternal>** result, int unused);
