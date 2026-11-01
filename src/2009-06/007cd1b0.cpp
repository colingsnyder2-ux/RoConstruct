// from server: 100% by auto
// roc 2009-06 007cd1b0  unit: CXTPDockingPaneBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd1b0
//
// 007cd1b0  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 007cd1b3  85c9                 test ecx, ecx
// 007cd1b5  7418                 je 0x7cd1cf
// 007cd1b7  8b542404             mov edx, dword ptr [esp + 4]
// 007cd1bb  eb03                 jmp 0x7cd1c0
// 007cd1bd  8d4900               lea ecx, [ecx]
// 007cd1c0  8bc1                 mov eax, ecx
// 007cd1c2  8b09                 mov ecx, dword ptr [ecx]
// 007cd1c4  83c008               add eax, 8
// 007cd1c7  3910                 cmp dword ptr [eax], edx
// 007cd1c9  7406                 je 0x7cd1d1
// 007cd1cb  85c9                 test ecx, ecx
// 007cd1cd  75f1                 jne 0x7cd1c0
// 007cd1cf  33c0                 xor eax, eax
// 007cd1d1  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?FindPaneInfo@CXTPDockingPaneLayout@@AAEPAUXTP_DOCKINGPANE_INFO@@PAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
