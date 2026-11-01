// from server: 100% by auto
// roc 2007-03 005fee60  unit: seg_005f0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fee60
//
// 005fee60  56                   push esi
// 005fee61  8b7130               mov esi, dword ptr [ecx + 0x30]
// 005fee64  8b5624               mov edx, dword ptr [esi + 0x24]
// 005fee67  33c9                 xor ecx, ecx
// 005fee69  85c0                 test eax, eax
// 005fee6b  7450                 je 0x5feebd
// 005fee6d  55                   push ebp
// 005fee6e  8bff                 mov edi, edi
// 005fee70  83780809             cmp dword ptr [eax + 8], 9
// 005fee74  7520                 jne 0x5fee96
// 005fee76  8b6810               mov ebp, dword ptr [eax + 0x10]
// 005fee79  3b6f08               cmp ebp, dword ptr [edi + 8]
// 005fee7c  7508                 jne 0x5fee86
// 005fee7e  b901000000           mov ecx, 1
// 005fee83  895010               mov dword ptr [eax + 0x10], edx
// 005fee86  8b6814               mov ebp, dword ptr [eax + 0x14]
// 005fee89  3b6f08               cmp ebp, dword ptr [edi + 8]
// 005fee8c  7508                 jne 0x5fee96
// 005fee8e  b901000000           mov ecx, 1
// 005fee93  895014               mov dword ptr [eax + 0x14], edx
// 005fee96  8b00                 mov eax, dword ptr [eax]
// 005fee98  85c0                 test eax, eax
// 005fee9a  75d4                 jne 0x5fee70
// 005fee9c  85c9                 test ecx, ecx
// 005fee9e  5d                   pop ebp
// 005fee9f  741c                 je 0x5feebd
// 005feea1  8b5708               mov edx, dword ptr [edi + 8]
// 005feea4  50                   push eax
// 005feea5  8b4624               mov eax, dword ptr [esi + 0x24]
// 005feea8  52                   push edx
// 005feea9  50                   push eax
// 005feeaa  6a00                 push 0
// 005feeac  56                   push esi
// 005feead  e8fe5c0100           call 0x614bb0
// 005feeb2  6a01                 push 1
// 005feeb4  56                   push esi
// 005feeb5  e826580100           call 0x6146e0
// 005feeba  83c41c               add esp, 0x1c
// 005feebd  5e                   pop esi
// 005feebe  c3                   ret 
// library lua-5.1.1/lparser.c (function _check_conflict)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
