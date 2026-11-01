// from server: 100% by auto
// roc 2007-03 006d33b0  unit: seg_006d0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d33b0
//
// 006d33b0  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 006d33b3  51                   push ecx
// 006d33b4  e897fbffff           call 0x6d2f50
// 006d33b9  83c404               add esp, 4
// 006d33bc  85c0                 test eax, eax
// 006d33be  740e                 je 0x6d33ce
// 006d33c0  8bc8                 mov ecx, eax
// 006d33c2  e80959faff           call 0x678cd0
// 006d33c7  a802                 test al, 2
// 006d33c9  7503                 jne 0x6d33ce
// 006d33cb  33c0                 xor eax, eax
// 006d33cd  c3                   ret 
// 006d33ce  b801000000           mov eax, 1
// 006d33d3  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsEnabled@CXTPDockingPaneCaptionButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
