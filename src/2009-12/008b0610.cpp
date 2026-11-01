// from server: 100% by auto
// roc 2009-12 008b0610  unit: CXTPDockingPaneMiniWnd  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0610
//
// 008b0610  837c240402           cmp dword ptr [esp + 4], 2
// 008b0615  7535                 jne 0x8b064c
// 008b0617  83b94801000000       cmp dword ptr [ecx + 0x148], 0
// 008b061e  7408                 je 0x8b0628
// 008b0620  e82bfdffff           call 0x8b0350
// 008b0625  c20c00               ret 0xc
// 008b0628  8b8130010000         mov eax, dword ptr [ecx + 0x130]
// 008b062e  85c0                 test eax, eax
// 008b0630  7405                 je 0x8b0637
// 008b0632  83c020               add eax, 0x20
// 008b0635  eb02                 jmp 0x8b0639
// 008b0637  33c0                 xor eax, eax
// 008b0639  50                   push eax
// 008b063a  81c1f8000000         add ecx, 0xf8
// 008b0640  e8fb010000           call 0x8b0840
// 008b0645  8bc8                 mov ecx, eax
// 008b0647  e814a2f8ff           call 0x83a860
// 008b064c  c20c00               ret 0xc
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneMiniWnd.cpp (function ?OnNcLButtonDblClk@CXTPDockingPaneMiniWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneMiniWnd.cpp
