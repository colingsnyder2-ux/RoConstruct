// from server: 100% by auto
// roc 2009-12 008ce020  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce020
//
// 008ce020  8b442404             mov eax, dword ptr [esp + 4]
// 008ce024  394134               cmp dword ptr [ecx + 0x34], eax
// 008ce027  7408                 je 0x8ce031
// 008ce029  894134               mov dword ptr [ecx + 0x34], eax
// 008ce02c  e87fffffff           call 0x8cdfb0
// 008ce031  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetVisible@CXTPTabManagerItem@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
