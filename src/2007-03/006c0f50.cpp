// from server: 100% by auto
// roc 2007-03 006c0f50  unit: seg_006c0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0f50
//
// 006c0f50  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 006c0f53  85c9                 test ecx, ecx
// 006c0f55  7418                 je 0x6c0f6f
// 006c0f57  8b542404             mov edx, dword ptr [esp + 4]
// 006c0f5b  eb03                 jmp 0x6c0f60
// 006c0f5d  8d4900               lea ecx, [ecx]
// 006c0f60  8bc1                 mov eax, ecx
// 006c0f62  8b09                 mov ecx, dword ptr [ecx]
// 006c0f64  83c008               add eax, 8
// 006c0f67  3910                 cmp dword ptr [eax], edx
// 006c0f69  7406                 je 0x6c0f71
// 006c0f6b  85c9                 test ecx, ecx
// 006c0f6d  75f1                 jne 0x6c0f60
// 006c0f6f  33c0                 xor eax, eax
// 006c0f71  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneLayout.cpp (function ?FindPaneInfo@CXTPDockingPaneLayout@@AAEPAUXTP_DOCKINGPANE_INFO@@PAVCXTPDockingPane@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneLayout.cpp
