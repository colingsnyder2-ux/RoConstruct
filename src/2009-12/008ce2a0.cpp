// from server: 100% by auto
// roc 2009-12 008ce2a0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ce2a0
//
// 008ce2a0  8b442404             mov eax, dword ptr [esp + 4]
// 008ce2a4  85c0                 test eax, eax
// 008ce2a6  7e02                 jle 0x8ce2aa
// 008ce2a8  33c0                 xor eax, eax
// 008ce2aa  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 008ce2ad  740a                 je 0x8ce2b9
// 008ce2af  894114               mov dword ptr [ecx + 0x14], eax
// 008ce2b2  8b01                 mov eax, dword ptr [ecx]
// 008ce2b4  8b5004               mov edx, dword ptr [eax + 4]
// 008ce2b7  ffd2                 call edx
// 008ce2b9  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetHeaderOffset@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
