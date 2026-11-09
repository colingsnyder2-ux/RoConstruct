// from server: 100% by auto
// roc 2010-06 00882430  unit: CXTPTabManager::CNavigateButtonArrowLeft  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882430
//
// 00882430  8b442404             mov eax, dword ptr [esp + 4]
// 00882434  39411c               cmp dword ptr [ecx + 0x1c], eax
// 00882437  740a                 je 0x882443
// 00882439  89411c               mov dword ptr [ecx + 0x1c], eax
// 0088243c  8b01                 mov eax, dword ptr [ecx]
// 0088243e  8b5004               mov edx, dword ptr [eax + 4]
// 00882441  ffd2                 call edx
// 00882443  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetActive@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
