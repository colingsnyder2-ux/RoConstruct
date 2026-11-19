// >>> native-flags: /O2 /GS- /EHsc /MD >>>
// IObjectSafetyRobloxImpl<CApp,1> | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 00000000 | roc native-status --write
#include "CApp2008.h"
#include <objsafe.h>

// Explicit specialization for CApp, Supported=1
template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::GetInterfaceSafetyOptions(
    REFIID riid, DWORD* pdwSupportedOptions, DWORD* pdwEnabledOptions)
{
    // Assembly prologue: push ebx; mov ebx, this; push esi; push edi
    IObjectSafetyRobloxImpl<CApp, 1>* pThis = this;
    
    // Assembly: test ebx, ebx; je null_this_path
    if (!pThis) {
        return E_POINTER;
    }
    
    // Assembly: lea eax, [ebx - 0x14] (adjust IObjectSafetyRobloxImpl* to CApp*)
    CApp* owner = reinterpret_cast<CApp*>(reinterpret_cast<char*>(pThis) - 0x14);
    
    // Assembly: test pdwSupportedOptions (edi); je null_supported_path
    if (!pdwSupportedOptions) {
        return E_POINTER;
    }
    
    // Assembly: test pdwEnabledOptions (esi); je null_enabled_path
    if (!pdwEnabledOptions) {
        *pdwSupportedOptions = 0;
        return E_POINTER;
    }
    
    // Assembly: mov ecx, [eax]; push riid; push owner; call [ecx] (QueryInterface on CApp*)
    IUnknown* object = nullptr;
    HRESULT hr = owner->QueryInterface(riid, reinterpret_cast<void**>(&object));
    
    // Assembly: mov ebp, eax (save QueryInterface result)
    HRESULT qresult = hr;
    
    // Assembly: test ebp, ebp; jl query_failed
    if (FAILED(qresult)) {
        *pdwSupportedOptions = 0;
        *pdwEnabledOptions = 0;
        return qresult;
    }
    
    // Assembly: mov ecx, [eax]; mov edx, [ecx+8]; push eax; call edx (Release)
    if (object) {
        object->Release();
    }
    
    // Assembly: mov ecx, ebx; call 0x407500 (FinalConstruct on original this? But FinalConstruct is on CApp*)
    // The assembly uses ebx (original this) but FinalConstruct is a CApp method.
    // Since owner = pThis - 0x14, and pThis is in ebx, owner is in eax.
    // The shape says "mov ecx, ebx ; call N" - this might be a thiscall to FinalConstruct
    // but with the IObjectSafetyRobloxImpl* this pointer. However, FinalConstruct expects CApp*.
    // Given the offset, the compiler might adjust. Let's call on owner.
    hr = owner->FinalConstruct();
    
    // Assembly: mov dword ptr [edi], 1 (*pdwSupportedOptions = 1)
    *pdwSupportedOptions = 1;
    
    // Assembly: test eax, eax; jne finalconstruct_failed
    if (FAILED(hr)) {
        *pdwEnabledOptions = 0;
        return qresult; // Assembly returns QueryInterface result (ebp)
    }
    
    // Assembly: mov eax, [ebx+4]; mov [esi], eax (*pdwEnabledOptions = currentSafety)
    *pdwEnabledOptions = pThis->currentSafety;
    
    // Assembly: mov eax, ebp; return qresult
    return qresult;
}

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::SetInterfaceSafetyOptions(
    REFIID riid, DWORD dwOptionSetMask, DWORD dwEnabledOptions)
{
    // Assembly prologue similar to GetInterfaceSafetyOptions
    IObjectSafetyRobloxImpl<CApp, 1>* pThis = this;
    
    if (!pThis) {
        return E_POINTER;
    }
    
    CApp* owner = reinterpret_cast<CApp*>(reinterpret_cast<char*>(pThis) - 0x14);
    
    // Assembly validates mask: test mask & ~1; jnz invalid_mask
    if (dwOptionSetMask & ~1u) {
        return E_FAIL;
    }
    
    // Assembly: QueryInterface on CApp*
    IUnknown* object = nullptr;
    HRESULT hr = owner->QueryInterface(riid, reinterpret_cast<void**>(&object));
    
    HRESULT qresult = hr;
    
    if (FAILED(qresult)) {
        return qresult;
    }
    
    // Assembly: Release
    if (object) {
        object->Release();
    }
    
    // Assembly: call FinalConstruct (0x407500)
    hr = owner->FinalConstruct();
    
    if (FAILED(hr)) {
        return hr;
    }
    
    // Assembly: currentSafety = (currentSafety & ~mask) | (mask & enabled)
    pThis->currentSafety = (pThis->currentSafety & ~dwOptionSetMask) | (dwOptionSetMask & dwEnabledOptions);
    
    return S_OK;
}

// Explicit instantiation for CApp
template class IObjectSafetyRobloxImpl<CApp, 1>;