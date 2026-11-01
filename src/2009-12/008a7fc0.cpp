// from server: 100% by auto
// roc 2009-12 008a7fc0  unit: CXTPDockingPaneBase  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a7fc0
//
// 008a7fc0  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 008a7fc3  85c9                 test ecx, ecx
// 008a7fc5  7418                 je 0x8a7fdf
// 008a7fc7  8b542404             mov edx, dword ptr [esp + 4]
// 008a7fcb  eb03                 jmp 0x8a7fd0
// 008a7fcd  8d4900               lea ecx, [ecx]
// 008a7fd0  8bc1                 mov eax, ecx
// 008a7fd2  8b09                 mov ecx, dword ptr [ecx]
// 008a7fd4  83c008               add eax, 8
// 008a7fd7  3910                 cmp dword ptr [eax], edx
// 008a7fd9  7406                 je 0x8a7fe1
// 008a7fdb  85c9                 test ecx, ecx
// 008a7fdd  75f1                 jne 0x8a7fd0
// 008a7fdf  33c0                 xor eax, eax
// 008a7fe1  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?FindPaneInfo@CXTPDockingPaneLayout@@AAEPAUXTP_DOCKINGPANE_INFO@@PAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
