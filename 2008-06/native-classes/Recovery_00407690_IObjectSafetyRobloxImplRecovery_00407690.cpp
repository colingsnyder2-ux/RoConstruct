// native-flags: /O2 /GS- /EHsc /MD
// IObjectSafetyRobloxImpl<CApp,1> | 2008-06 | draft (lane)
// Targets: 00407720 SetInterfaceSafetyOptions (119 bytes), 00407690 GetInterfaceSafetyOptions (137 bytes)
// Assembly evidence (roc native-asm):
//   00407720: QI called on this+0x10; FinalConstruct called on this (unadjusted);
//             currentSafety read/written at [this+4]; mask validated (mask & ~1 -> E_FAIL);
//             QI failure -> E_NOINTERFACE (0x80004002).
//   00407690: *pdwSupportedOptions = 1; *pdwEnabledOptions = currentSafety; return QI hr;
//             null output pointers -> E_POINTER (0x80004003).
#include "CApp2008.h"
#include <objsafe.h>

// Explicit specialization for CApp, Supported=1
template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::SetInterfaceSafetyOptions(
    REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions)
{
    // this is the IObjectSafetyRobloxImpl subobject; currentSafety lives at [this+4].
    // INFERRED: the binary performs QueryInterface on this+0x10 and FinalConstruct on
    // this itself (no CApp this-adjustment), so owner is expressed as raw byte offset.
    IObjectSafetyRobloxImpl<CApp, 1>* pThis = this;
    CApp* owner = reinterpret_cast<CApp*>(reinterpret_cast<char*>(pThis) + 0x10);

    IUnknown* object = 0;
    HRESULT hr = owner->QueryInterface(riid, reinterpret_cast<void**>(&object));
    HRESULT qresult = hr;
    if (FAILED(hr)) {
        return 0x80004002; // E_NOINTERFACE
    }
    if (object) {
        object->Release();
    }
    // The option mask may only be 0 or 1 (IObjectSafetyInterfacy::INTERFACE_USES... single bit).
    if (dwOptionSetMask & ~1u) {
        return 0x80004005; // E_FAIL
    }
    // FinalConstruct is invoked on the original this pointer, unadjusted.
    hr = reinterpret_cast<CApp*>(pThis)->FinalConstruct();
    if (FAILED(hr)) {
        return hr;
    }
    pThis->currentSafety = (pThis->currentSafety & ~dwOptionSetMask) | (dwOptionSetMask & dwEnabledOptions);
    return S_OK;
}

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::GetInterfaceSafetyOptions(
    REFIID riid, DWORD* pdwSupportedOptions, DWORD* pdwEnabledOptions)
{
    IObjectSafetyRobloxImpl<CApp, 1>* pThis = this;
    CApp* owner = reinterpret_cast<CApp*>(reinterpret_cast<char*>(pThis) + 0x10);

    if (!pdwSupportedOptions || !pdwEnabledOptions) {
        return 0x80004003; // E_POINTER
    }

    IUnknown* object = 0;
    HRESULT hr = owner->QueryInterface(riid, reinterpret_cast<void**>(&object));
    HRESULT qresult = hr;
    if (FAILED(hr)) {
        *pdwSupportedOptions = 0;
        *pdwEnabledOptions = 0;
        return qresult;
    }
    if (object) {
        object->Release();
    }
    hr = reinterpret_cast<CApp*>(pThis)->FinalConstruct();
    *pdwSupportedOptions = 1;
    if (FAILED(hr)) {
        *pdwEnabledOptions = 0;
        return qresult;
    }
    *pdwEnabledOptions = pThis->currentSafety;
    return qresult;
}
