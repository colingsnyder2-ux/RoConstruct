#pragma once
// >>> native-status (generated) -- do not edit >>>
// CContent | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e5ca7b65 | roc native-status --write
#include <atlbase.h>
#include <atlcom.h>
#include <sstream>
#include "RobloxLib.h"

extern const IID IID_IContent;
extern const IID LIBID_RobloxLib;
extern const CLSID CLSID_Content;

class ATL_NO_VTABLE CContent :
    public ATL::ISupportErrorInfoImpl<&IID_IContent>,
    public ATL::IDispatchImpl<IContent, &IID_IContent, &LIBID_RobloxLib, 1, 0>,
    public ATL::CComObjectRootEx<ATL::CComSingleThreadModel>,
    public ATL::CComCoClass<CContent, &CLSID_Content> {
public:
    DECLARE_REGISTRY_RESOURCEID(116)
    std::stringstream stream;

    BEGIN_COM_MAP(CContent)
        COM_INTERFACE_ENTRY(IContent)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
    DECLARE_PROTECT_FINAL_CONSTRUCT()
    STDMETHOD(Upload)(BSTR);
};
