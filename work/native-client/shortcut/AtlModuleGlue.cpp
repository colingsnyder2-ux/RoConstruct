// Shortcut glue (owner-authorized): the exe's global ATL module (0096dbb4, openrbx `CRobloxModule _AtlModule`) was a zeroed data stub, so
// CAtlModule::CAtlModule never ran and ATL::_pAtlModule stayed null; the first CComObject<> construction then crashed
// (CComObject<CWorkspace>::CComObject calls _pAtlModule->Lock()).  This gives the global a real CAtlModule base.
#include <atlbase.h>
#include <atlcom.h>

class NativeAtlModule : public ATL::CAtlModule
{
public:
    HRESULT RegisterServer(BOOL, const CLSID*);
    virtual HRESULT AddCommonRGSReplacements(IRegistrarBase*) throw() { return S_OK; }
};

HRESULT NativeAtlModule::RegisterServer(BOOL, const CLSID*) { return S_OK; }  // exe 0044bea0 (registration path only)

NativeAtlModule nativeAtlModule;
