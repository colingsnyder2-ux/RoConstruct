// from server: 100% by auto
// roc 2009-06 007f3470  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3470
//
// 007f3470  8b442404             mov eax, dword ptr [esp + 4]
// 007f3474  394134               cmp dword ptr [ecx + 0x34], eax
// 007f3477  7408                 je 0x7f3481
// 007f3479  894134               mov dword ptr [ecx + 0x34], eax
// 007f347c  e87fffffff           call 0x7f3400
// 007f3481  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetVisible@CXTPTabManagerItem@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
