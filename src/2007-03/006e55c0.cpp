// from server: 100% by auto
// roc 2007-03 006e55c0  unit: seg_006e0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e55c0
//
// 006e55c0  8b442404             mov eax, dword ptr [esp + 4]
// 006e55c4  394134               cmp dword ptr [ecx + 0x34], eax
// 006e55c7  7408                 je 0x6e55d1
// 006e55c9  894134               mov dword ptr [ecx + 0x34], eax
// 006e55cc  e86fffffff           call 0x6e5540
// 006e55d1  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetVisible@CXTPTabManagerItem@@UAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
