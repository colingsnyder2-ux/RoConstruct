// from server: 100% by auto
// roc 2010-06 00882480  unit: CXTPDockingPaneAutoHidePanel::CAutoHidePanelTabManager  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882480
//
// 00882480  8b442404             mov eax, dword ptr [esp + 4]
// 00882484  85c0                 test eax, eax
// 00882486  7e02                 jle 0x88248a
// 00882488  33c0                 xor eax, eax
// 0088248a  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 0088248d  740a                 je 0x882499
// 0088248f  894114               mov dword ptr [ecx + 0x14], eax
// 00882492  8b01                 mov eax, dword ptr [ecx]
// 00882494  8b5004               mov edx, dword ptr [eax + 4]
// 00882497  ffd2                 call edx
// 00882499  c20400               ret 4
// library xtp-13.2.1/Source\TabManager\XTPTabManager.cpp (function ?SetHeaderOffset@CXTPTabManager@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabManager.cpp
