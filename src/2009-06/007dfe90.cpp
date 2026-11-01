// from server: 100% by auto
// roc 2009-06 007dfe90  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOffice2003Theme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dfe90
//
// 007dfe90  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 007dfe93  51                   push ecx
// 007dfe94  e887fbffff           call 0x7dfa20
// 007dfe99  83c404               add esp, 4
// 007dfe9c  85c0                 test eax, eax
// 007dfe9e  740e                 je 0x7dfeae
// 007dfea0  8bc8                 mov ecx, eax
// 007dfea2  e85918faff           call 0x781700
// 007dfea7  a802                 test al, 2
// 007dfea9  7503                 jne 0x7dfeae
// 007dfeab  33c0                 xor eax, eax
// 007dfead  c3                   ret 
// 007dfeae  b801000000           mov eax, 1
// 007dfeb3  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsEnabled@CXTPDockingPaneCaptionButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
