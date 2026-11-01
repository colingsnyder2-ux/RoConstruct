// from server: 100% by auto
// roc 2007-03 00678dc0  unit: seg_00670000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678dc0
//
// 00678dc0  85c9                 test ecx, ecx
// 00678dc2  7414                 je 0x678dd8
// 00678dc4  8d4120               lea eax, [ecx + 0x20]
// 00678dc7  50                   push eax
// 00678dc8  83c120               add ecx, 0x20
// 00678dcb  e850070500           call 0x6c9520
// 00678dd0  8bc8                 mov ecx, eax
// 00678dd2  e87928feff           call 0x65b650
// 00678dd7  c3                   ret 
// 00678dd8  33c0                 xor eax, eax
// 00678dda  50                   push eax
// 00678ddb  83c120               add ecx, 0x20
// 00678dde  e83d070500           call 0x6c9520
// 00678de3  8bc8                 mov ecx, eax
// 00678de5  e86628feff           call 0x65b650
// 00678dea  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Hide@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
