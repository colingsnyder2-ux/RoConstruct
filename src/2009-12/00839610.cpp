// from server: 100% by auto
// roc 2009-12 00839610  unit: CXTPDockingPaneManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00839610
//
// 00839610  8d41ac               lea eax, [ecx - 0x54]
// 00839613  85c0                 test eax, eax
// 00839615  7422                 je 0x839639
// 00839617  83782000             cmp dword ptr [eax + 0x20], 0
// 0083961b  741c                 je 0x839639
// 0083961d  85c0                 test eax, eax
// 0083961f  7403                 je 0x839624
// 00839621  8b4020               mov eax, dword ptr [eax + 0x20]
// 00839624  8b542404             mov edx, dword ptr [esp + 4]
// 00839628  52                   push edx
// 00839629  68a04ba200           push 0xa24ba0
// 0083962e  6a00                 push 0
// 00839630  50                   push eax
// 00839631  e82a2e0000           call 0x83c460
// 00839636  c20400               ret 4
// 00839639  b805400080           mov eax, 0x80004005
// 0083963e  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneManager.cpp (function ?GetAccessibleParent@CXTPDockingPaneManager@@MAEJPAPAUIDispatch@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneManager.cpp
