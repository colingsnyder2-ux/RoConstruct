// from server: 100% by auto
// roc 2009-06 007f3490  unit: CXTPTabManagerItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f3490
//
// 007f3490  8b442404             mov eax, dword ptr [esp + 4]
// 007f3494  394130               cmp dword ptr [ecx + 0x30], eax
// 007f3497  7408                 je 0x7f34a1
// 007f3499  894130               mov dword ptr [ecx + 0x30], eax
// 007f349c  e85fffffff           call 0x7f3400
// 007f34a1  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetEnabled@CXTPTabManagerItem@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
