// from server: 100% by auto
// roc 2009-06 007d5ad0  unit: CXTPDockingPaneMiniWnd  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5ad0
//
// 007d5ad0  837c240402           cmp dword ptr [esp + 4], 2
// 007d5ad5  7535                 jne 0x7d5b0c
// 007d5ad7  83b94801000000       cmp dword ptr [ecx + 0x148], 0
// 007d5ade  7408                 je 0x7d5ae8
// 007d5ae0  e82bfdffff           call 0x7d5810
// 007d5ae5  c20c00               ret 0xc
// 007d5ae8  8b8130010000         mov eax, dword ptr [ecx + 0x130]
// 007d5aee  85c0                 test eax, eax
// 007d5af0  7405                 je 0x7d5af7
// 007d5af2  83c020               add eax, 0x20
// 007d5af5  eb02                 jmp 0x7d5af9
// 007d5af7  33c0                 xor eax, eax
// 007d5af9  50                   push eax
// 007d5afa  81c1f8000000         add ecx, 0xf8
// 007d5b00  e8fb010000           call 0x7d5d00
// 007d5b05  8bc8                 mov ecx, eax
// 007d5b07  e8949ff8ff           call 0x75faa0
// 007d5b0c  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnNcLButtonDblClk@CXTPDockingPaneMiniWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
