// from server: 100% by auto
// roc 2010-06 007f5f90  unit: CXTPPopupToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f5f90
//
// 007f5f90  56                   push esi
// 007f5f91  8bf1                 mov esi, ecx
// 007f5f93  8b4610               mov eax, dword ptr [esi + 0x10]
// 007f5f96  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007f5f99  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007f5f9c  50                   push eax
// 007f5f9d  52                   push edx
// 007f5f9e  ff1560ba9e00         call dword ptr [0x9eba60]
// 007f5fa4  c7461000000000       mov dword ptr [esi + 0x10], 0
// 007f5fab  5e                   pop esi
// 007f5fac  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?KillTimer@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
