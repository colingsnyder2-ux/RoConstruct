// >>> native-status (generated) -- do not edit >>>
// CWorkspaceObjectSafety | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0bc50e71 | roc native-status --write
#include "CWorkspace.h"

template<class T, DWORD Supported>
HRESULT __stdcall IObjectSafetyRobloxImpl<T, Supported>::GetInterfaceSafetyOptions(
    REFIID iid, DWORD* supported, DWORD* enabled)
{
    T* owner = static_cast<T*>(this);
    if (!supported || !enabled) return E_POINTER;
    IUnknown* object;
    HRESULT result = static_cast<IWorkspace*>(owner)->QueryInterface(iid, reinterpret_cast<void**>(&object));
    if (SUCCEEDED(result)) {
        object->Release();
        if (checkSite()) {
            *supported = Supported;
            *enabled = 0;
        } else {
            *supported = Supported;
            *enabled = currentSafety;
        }
    } else {
        *supported = 0;
        *enabled = 0;
    }
    return result;
}

template<class T, DWORD Supported>
HRESULT __stdcall IObjectSafetyRobloxImpl<T, Supported>::SetInterfaceSafetyOptions(
    REFIID iid, DWORD mask, DWORD enabled)
{
    T* owner = static_cast<T*>(this);
    IUnknown* object;
    if (FAILED(static_cast<IWorkspace*>(owner)->QueryInterface(iid, reinterpret_cast<void**>(&object))))
        return E_NOINTERFACE;
    object->Release();
    if (mask & ~Supported) return E_FAIL;
    HRESULT result = checkSite();
    if (result != S_OK) return result;
    currentSafety = (currentSafety & ~mask) | (mask & enabled);
    return S_OK;
}

template class IObjectSafetyRobloxImpl<CWorkspace, 1>;
