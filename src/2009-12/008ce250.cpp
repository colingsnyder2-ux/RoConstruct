// from server: 100% by auto
// roc 2009-12 008ce250  unit: CXTPTabManager::CNavigateButtonArrowLeft  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce250
//
// 008ce250  8b442404             mov eax, dword ptr [esp + 4]
// 008ce254  39411c               cmp dword ptr [ecx + 0x1c], eax
// 008ce257  740a                 je 0x8ce263
// 008ce259  89411c               mov dword ptr [ecx + 0x1c], eax
// 008ce25c  8b01                 mov eax, dword ptr [ecx]
// 008ce25e  8b5004               mov edx, dword ptr [eax + 4]
// 008ce261  ffd2                 call edx
// 008ce263  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetActive@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
