// from server: 100% by auto
// roc 2010-06 0086eaf0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneOffice2003Theme  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0086eaf0
//
// 0086eaf0  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0086eaf3  51                   push ecx
// 0086eaf4  e897fbffff           call 0x86e690
// 0086eaf9  83c404               add esp, 4
// 0086eafc  85c0                 test eax, eax
// 0086eafe  740e                 je 0x86eb0e
// 0086eb00  8bc8                 mov ecx, eax
// 0086eb02  e8e9f7e6ff           call 0x6de2f0
// 0086eb07  a802                 test al, 2
// 0086eb09  7503                 jne 0x86eb0e
// 0086eb0b  33c0                 xor eax, eax
// 0086eb0d  c3                   ret 
// 0086eb0e  b801000000           mov eax, 1
// 0086eb13  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?IsEnabled@CXTPDockingPaneCaptionButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
