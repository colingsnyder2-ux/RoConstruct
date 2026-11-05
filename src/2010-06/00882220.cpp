// from server: 100% by auto
// roc 2010-06 00882220  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882220
//
// 00882220  8b442404             mov eax, dword ptr [esp + 4]
// 00882224  394130               cmp dword ptr [ecx + 0x30], eax
// 00882227  7408                 je 0x882231
// 00882229  894130               mov dword ptr [ecx + 0x30], eax
// 0088222c  e84fffffff           call 0x882180
// 00882231  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetEnabled@CXTPTabManagerItem@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
