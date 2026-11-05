// from server: 100% by auto
// roc 2010-06 007f5fb0  unit: CXTPPopupToolBar  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f5fb0
//
// 007f5fb0  8b442408             mov eax, dword ptr [esp + 8]
// 007f5fb4  56                   push esi
// 007f5fb5  8bf1                 mov esi, ecx
// 007f5fb7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007f5fbb  50                   push eax
// 007f5fbc  51                   push ecx
// 007f5fbd  56                   push esi
// 007f5fbe  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 007f5fc4  85c0                 test eax, eax
// 007f5fc6  7427                 je 0x7f5fef
// 007f5fc8  837e1000             cmp dword ptr [esi + 0x10], 0
// 007f5fcc  7518                 jne 0x7f5fe6
// 007f5fce  8b4618               mov eax, dword ptr [esi + 0x18]
// 007f5fd1  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007f5fd4  8b5120               mov edx, dword ptr [ecx + 0x20]
// 007f5fd7  6a00                 push 0
// 007f5fd9  6a50                 push 0x50
// 007f5fdb  50                   push eax
// 007f5fdc  52                   push edx
// 007f5fdd  ff1554bc9e00         call dword ptr [0x9ebc54]
// 007f5fe3  894610               mov dword ptr [esi + 0x10], eax
// 007f5fe6  b801000000           mov eax, 1
// 007f5feb  5e                   pop esi
// 007f5fec  c20800               ret 8
// 007f5fef  8b4610               mov eax, dword ptr [esi + 0x10]
// 007f5ff2  85c0                 test eax, eax
// 007f5ff4  7415                 je 0x7f600b
// 007f5ff6  50                   push eax
// 007f5ff7  8b4614               mov eax, dword ptr [esi + 0x14]
// 007f5ffa  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007f5ffd  51                   push ecx
// 007f5ffe  ff1560ba9e00         call dword ptr [0x9eba60]
// 007f6004  c7461000000000       mov dword ptr [esi + 0x10], 0
// 007f600b  33c0                 xor eax, eax
// 007f600d  5e                   pop esi
// 007f600e  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnMouseMove@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPopupBar.cpp
