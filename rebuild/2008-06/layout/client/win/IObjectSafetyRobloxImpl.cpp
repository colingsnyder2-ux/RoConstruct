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
