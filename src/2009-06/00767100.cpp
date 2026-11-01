// from server: 100% by auto
// roc 2009-06 00767100  unit: CXTPPopupToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00767100
//
// 00767100  56                   push esi
// 00767101  8bf1                 mov esi, ecx
// 00767103  8b4610               mov eax, dword ptr [esi + 0x10]
// 00767106  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00767109  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0076710c  50                   push eax
// 0076710d  52                   push edx
// 0076710e  ff1584ee8900         call dword ptr [0x89ee84]
// 00767114  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0076711b  5e                   pop esi
// 0076711c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?KillTimer@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
