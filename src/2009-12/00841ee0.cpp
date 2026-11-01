// from server: 100% by auto
// roc 2009-12 00841ee0  unit: CXTPPopupToolBar  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00841ee0
//
// 00841ee0  56                   push esi
// 00841ee1  8bf1                 mov esi, ecx
// 00841ee3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00841ee6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00841ee9  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00841eec  50                   push eax
// 00841eed  52                   push edx
// 00841eee  ff15d0cb9800         call dword ptr [0x98cbd0]
// 00841ef4  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00841efb  5e                   pop esi
// 00841efc  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?KillTimer@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
