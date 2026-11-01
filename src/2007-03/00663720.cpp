// from server: 100% by auto
// roc 2007-03 00663720  unit: seg_00660000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00663720
//
// 00663720  56                   push esi
// 00663721  8bf1                 mov esi, ecx
// 00663723  8b4610               mov eax, dword ptr [esi + 0x10]
// 00663726  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00663729  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0066372c  50                   push eax
// 0066372d  52                   push edx
// 0066372e  ff155cee7700         call dword ptr [0x77ee5c]
// 00663734  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0066373b  5e                   pop esi
// 0066373c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?KillTimer@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
