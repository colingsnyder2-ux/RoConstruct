// from server: 100% by auto
// roc 2009-06 007f36f0  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f36f0
//
// 007f36f0  8b442404             mov eax, dword ptr [esp + 4]
// 007f36f4  85c0                 test eax, eax
// 007f36f6  7e02                 jle 0x7f36fa
// 007f36f8  33c0                 xor eax, eax
// 007f36fa  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 007f36fd  740a                 je 0x7f3709
// 007f36ff  894114               mov dword ptr [ecx + 0x14], eax
// 007f3702  8b01                 mov eax, dword ptr [ecx]
// 007f3704  8b5004               mov edx, dword ptr [eax + 4]
// 007f3707  ffd2                 call edx
// 007f3709  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetHeaderOffset@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
