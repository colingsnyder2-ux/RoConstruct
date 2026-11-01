// from server: 100% by auto
// roc 2009-06 007f36a0  unit: CXTPTabManager::CNavigateButtonArrowLeft  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f36a0
//
// 007f36a0  8b442404             mov eax, dword ptr [esp + 4]
// 007f36a4  39411c               cmp dword ptr [ecx + 0x1c], eax
// 007f36a7  740a                 je 0x7f36b3
// 007f36a9  89411c               mov dword ptr [ecx + 0x1c], eax
// 007f36ac  8b01                 mov eax, dword ptr [ecx]
// 007f36ae  8b5004               mov edx, dword ptr [eax + 4]
// 007f36b1  ffd2                 call edx
// 007f36b3  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetActive@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
