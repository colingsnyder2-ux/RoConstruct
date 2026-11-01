// from server: 100% by auto
// roc 2009-06 0075d880  unit: CXTPControls  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075d880
//
// 0075d880  8b442404             mov eax, dword ptr [esp + 4]
// 0075d884  85c0                 test eax, eax
// 0075d886  7416                 je 0x75d89e
// 0075d888  8d4820               lea ecx, [eax + 0x20]
// 0075d88b  8b01                 mov eax, dword ptr [ecx]
// 0075d88d  8b501c               mov edx, dword ptr [eax + 0x1c]
// 0075d890  ffd2                 call edx
// 0075d892  85c0                 test eax, eax
// 0075d894  7408                 je 0x75d89e
// 0075d896  b801000000           mov eax, 1
// 0075d89b  c20400               ret 4
// 0075d89e  33c0                 xor eax, eax
// 0075d8a0  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneHidden@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
