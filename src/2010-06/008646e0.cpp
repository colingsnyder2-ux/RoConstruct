// from server: 100% by auto
// roc 2010-06 008646e0  unit: CXTPDockingPaneMiniWnd  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008646e0
//
// 008646e0  837c240402           cmp dword ptr [esp + 4], 2
// 008646e5  7535                 jne 0x86471c
// 008646e7  83b94801000000       cmp dword ptr [ecx + 0x148], 0
// 008646ee  7408                 je 0x8646f8
// 008646f0  e82bfdffff           call 0x864420
// 008646f5  c20c00               ret 0xc
// 008646f8  8b8130010000         mov eax, dword ptr [ecx + 0x130]
// 008646fe  85c0                 test eax, eax
// 00864700  7405                 je 0x864707
// 00864702  83c020               add eax, 0x20
// 00864705  eb02                 jmp 0x864709
// 00864707  33c0                 xor eax, eax
// 00864709  50                   push eax
// 0086470a  81c1f8000000         add ecx, 0xf8
// 00864710  e8fb010000           call 0x864910
// 00864715  8bc8                 mov ecx, eax
// 00864717  e8a4a2f8ff           call 0x7ee9c0
// 0086471c  c20c00               ret 0xc
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnNcLButtonDblClk@CXTPDockingPaneMiniWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
