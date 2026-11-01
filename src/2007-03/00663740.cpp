// from server: 100% by auto
// roc 2007-03 00663740  unit: seg_00660000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00663740
//
// 00663740  8b442408             mov eax, dword ptr [esp + 8]
// 00663744  56                   push esi
// 00663745  8bf1                 mov esi, ecx
// 00663747  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066374b  50                   push eax
// 0066374c  51                   push ecx
// 0066374d  56                   push esi
// 0066374e  ff1598ed7700         call dword ptr [0x77ed98]
// 00663754  85c0                 test eax, eax
// 00663756  7427                 je 0x66377f
// 00663758  837e1000             cmp dword ptr [esi + 0x10], 0
// 0066375c  7518                 jne 0x663776
// 0066375e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00663761  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00663764  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00663767  6a00                 push 0
// 00663769  6a50                 push 0x50
// 0066376b  50                   push eax
// 0066376c  52                   push edx
// 0066376d  ff1544ed7700         call dword ptr [0x77ed44]
// 00663773  894610               mov dword ptr [esi + 0x10], eax
// 00663776  b801000000           mov eax, 1
// 0066377b  5e                   pop esi
// 0066377c  c20800               ret 8
// 0066377f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00663782  85c0                 test eax, eax
// 00663784  7415                 je 0x66379b
// 00663786  50                   push eax
// 00663787  8b4614               mov eax, dword ptr [esi + 0x14]
// 0066378a  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0066378d  51                   push ecx
// 0066378e  ff155cee7700         call dword ptr [0x77ee5c]
// 00663794  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0066379b  33c0                 xor eax, eax
// 0066379d  5e                   pop esi
// 0066379e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnMouseMove@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
