// from server: 100% by auto
// roc 2009-12 008ce040  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce040
//
// 008ce040  8b442404             mov eax, dword ptr [esp + 4]
// 008ce044  394130               cmp dword ptr [ecx + 0x30], eax
// 008ce047  7408                 je 0x8ce051
// 008ce049  894130               mov dword ptr [ecx + 0x30], eax
// 008ce04c  e85fffffff           call 0x8cdfb0
// 008ce051  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetEnabled@CXTPTabManagerItem@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
