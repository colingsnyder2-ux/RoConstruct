// from server: 100% by auto
// roc 2010-06 0085c140  unit: CXTPDockingPaneBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c140
//
// 0085c140  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 0085c143  85c9                 test ecx, ecx
// 0085c145  7418                 je 0x85c15f
// 0085c147  8b542404             mov edx, dword ptr [esp + 4]
// 0085c14b  eb03                 jmp 0x85c150
// 0085c14d  8d4900               lea ecx, [ecx]
// 0085c150  8bc1                 mov eax, ecx
// 0085c152  8b09                 mov ecx, dword ptr [ecx]
// 0085c154  83c008               add eax, 8
// 0085c157  3910                 cmp dword ptr [eax], edx
// 0085c159  7406                 je 0x85c161
// 0085c15b  85c9                 test ecx, ecx
// 0085c15d  75f1                 jne 0x85c150
// 0085c15f  33c0                 xor eax, eax
// 0085c161  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?FindPane@CXTPDockingPaneLayout@@AAEPAUXTP_DOCKINGPANE_INFO@@PAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
