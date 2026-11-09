// from server: 100% by auto
// roc 2010-06 007ec810  unit: CXTPControls  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec810
//
// 007ec810  8b442404             mov eax, dword ptr [esp + 4]
// 007ec814  85c0                 test eax, eax
// 007ec816  7416                 je 0x7ec82e
// 007ec818  8d4820               lea ecx, [eax + 0x20]
// 007ec81b  8b01                 mov eax, dword ptr [ecx]
// 007ec81d  8b501c               mov edx, dword ptr [eax + 0x1c]
// 007ec820  ffd2                 call edx
// 007ec822  85c0                 test eax, eax
// 007ec824  7408                 je 0x7ec82e
// 007ec826  b801000000           mov eax, 1
// 007ec82b  c20400               ret 4
// 007ec82e  33c0                 xor eax, eax
// 007ec830  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?IsPaneHidden@CXTPDockingPaneManager@@QBEHPAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
