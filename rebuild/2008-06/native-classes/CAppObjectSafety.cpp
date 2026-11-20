// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// IObjectSafetyRobloxImpl<CApp, 1> IObjectSafety slots (2008-06 native, inactive). CApp2008.h declares both members as
// explicit specializations, so they are defined here as such. Identity: vftable owner unit VCApp (native-asm), the
// same shape as the CWorkspace instance 00404d20 / 00404db0 (CWorkspaceObjectSafety.cpp) with the CApp layout:
// IObjectSafety at CApp+4 (`lea eax, [ebx - 4]`), QueryInterface through GetUnknown() (the first COM map entry,
// IApp at CApp+0x14, folded to a constant offset without a null test, as in ATL's IObjectSafetyImpl; a plain
// owner->QueryInterface goes through +0 and static_cast<IApp*> adds a null test: both rejected), and checkSite for CApp at 00407500 (registry placeholder func_00407500, the CApp instance of 00403b60).
// Replaces IObjectSafetyRobloxImplRecovery_00407690.cpp, whose bodies use nullptr (C2065 under VC9) and an invented
// FinalConstruct call.
#include <afx.h>
#include "CApp2008.h"

// 00407690 (137 B): GetInterfaceSafetyOptions.
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

// 00407720 (119 B): SetInterfaceSafetyOptions.
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
