// from server: 100% by auto
// roc 2009-06 00767120  unit: CXTPPopupToolBar  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00767120
//
// 00767120  8b442408             mov eax, dword ptr [esp + 8]
// 00767124  56                   push esi
// 00767125  8bf1                 mov esi, ecx
// 00767127  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076712b  50                   push eax
// 0076712c  51                   push ecx
// 0076712d  56                   push esi
// 0076712e  ff15c0ed8900         call dword ptr [0x89edc0]
// 00767134  85c0                 test eax, eax
// 00767136  7427                 je 0x76715f
// 00767138  837e1000             cmp dword ptr [esi + 0x10], 0
// 0076713c  7518                 jne 0x767156
// 0076713e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00767141  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00767144  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00767147  6a00                 push 0
// 00767149  6a50                 push 0x50
// 0076714b  50                   push eax
// 0076714c  52                   push edx
// 0076714d  ff150cee8900         call dword ptr [0x89ee0c]
// 00767153  894610               mov dword ptr [esi + 0x10], eax
// 00767156  b801000000           mov eax, 1
// 0076715b  5e                   pop esi
// 0076715c  c20800               ret 8
// 0076715f  8b4610               mov eax, dword ptr [esi + 0x10]
// 00767162  85c0                 test eax, eax
// 00767164  7415                 je 0x76717b
// 00767166  50                   push eax
// 00767167  8b4614               mov eax, dword ptr [esi + 0x14]
// 0076716a  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0076716d  51                   push ecx
// 0076716e  ff1584ee8900         call dword ptr [0x89ee84]
// 00767174  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0076717b  33c0                 xor eax, eax
// 0076717d  5e                   pop esi
// 0076717e  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?OnMouseMove@BTNSCROLL@SCROLLINFO@CXTPPopupBar@@QAEHVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
