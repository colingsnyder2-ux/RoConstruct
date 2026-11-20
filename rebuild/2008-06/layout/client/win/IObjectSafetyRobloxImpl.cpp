#include <afx.h>
#include "CApp2008.h"

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::GetInterfaceSafetyOptions(
    REFIID iid, DWORD* supported, DWORD* enabled)
{
    CApp* owner = static_cast<CApp*>(this);
    if (!supported || !enabled) return E_POINTER;
    IUnknown* object;
    HRESULT result = owner->GetUnknown()->QueryInterface(iid, reinterpret_cast<void**>(&object));
    if (SUCCEEDED(result)) {
        object->Release();
        if (checkSite()) {
            *supported = 1;
            *enabled = 0;
        } else {
            *supported = 1;
            *enabled = currentSafety;
        }
    } else {
        *supported = 0;
        *enabled = 0;
    }
    return result;
}

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::SetInterfaceSafetyOptions(
    REFIID iid, DWORD mask, DWORD enabled)
{
    CApp* owner = static_cast<CApp*>(this);
    IUnknown* object;
    if (FAILED(owner->GetUnknown()->QueryInterface(iid, reinterpret_cast<void**>(&object))))
        return E_NOINTERFACE;
    object->Release();
    if (mask & ~1) return E_FAIL;
    HRESULT result = checkSite();
    if (result != S_OK) return result;
    currentSafety = (currentSafety & ~mask) | (mask & enabled);
    return S_OK;
}
