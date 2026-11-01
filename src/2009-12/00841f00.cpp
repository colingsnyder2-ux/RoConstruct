// from server: 100% by auto
// roc 2009-12 00841f00  unit: CXTPPopupToolBar  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00841f00
//
// 00841f00  8b442408             mov eax, dword ptr [esp + 8]
// 00841f04  56                   push esi
// 00841f05  8bf1                 mov esi, ecx
// 00841f07  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00841f0b  50                   push eax
// 00841f0c  51                   push ecx
// 00841f0d  56                   push esi
// 00841f0e  ff155cca9800         call dword ptr [0x98ca5c]
// 00841f14  85c0                 test eax, eax
// 00841f16  7427                 je 0x841f3f
// 00841f18  837e1000             cmp dword ptr [esi + 0x10], 0
// 00841f1c  7518                 jne 0x841f36
// 00841f1e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00841f21  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00841f24  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00841f27  6a00                 push 0
// 00841f29  6a50                 push 0x50
// 00841f2b  50                   push eax
// 00841f2c  52                   push edx
// 00841f2d  ff1558cc9800         call dword ptr [0x98cc58]
// 00841f33  894610               mov dword ptr [esi + 0x10], eax
// 00841f36  b801000000           mov eax, 1
// 00841f3b  5e                   pop esi
// 00841f3c  c20800               ret 8
// 00841f3f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00841f42  85c0                 test eax, eax
// 00841f44  7415                 je 0x841f5b
// 00841f46  50                   push eax
// 00841f47  8b4614               mov eax, dword ptr [esi + 0x14]
// 00841f4a  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00841f4d  51                   push ecx
// 00841f4e  ff15d0cb9800         call dword ptr [0x98cbd0]
// 00841f54  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00841f5b  33c0                 xor eax, eax
// 00841f5d  5e                   pop esi
// 00841f5e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnMouseMove@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
