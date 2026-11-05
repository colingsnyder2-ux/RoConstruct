// from server: 100% by auto
// roc 2010-06 00882200  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882200
//
// 00882200  8b442404             mov eax, dword ptr [esp + 4]
// 00882204  394134               cmp dword ptr [ecx + 0x34], eax
// 00882207  7408                 je 0x882211
// 00882209  894134               mov dword ptr [ecx + 0x34], eax
// 0088220c  e86fffffff           call 0x882180
// 00882211  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetVisible@CXTPTabManagerItem@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
