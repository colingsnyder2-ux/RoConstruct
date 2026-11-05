// from server: 100% by auto
// roc 2009-12 007d3240  unit: seg_007d0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d3240
//
// 007d3240  56                   push esi
// 007d3241  8b7130               mov esi, dword ptr [ecx + 0x30]
// 007d3244  8b5624               mov edx, dword ptr [esi + 0x24]
// 007d3247  33c9                 xor ecx, ecx
// 007d3249  85c0                 test eax, eax
// 007d324b  7450                 je 0x7d329d
// 007d324d  55                   push ebp
// 007d324e  8bff                 mov edi, edi
// 007d3250  83780809             cmp dword ptr [eax + 8], 9
// 007d3254  7520                 jne 0x7d3276
// 007d3256  8b6810               mov ebp, dword ptr [eax + 0x10]
// 007d3259  3b6f08               cmp ebp, dword ptr [edi + 8]
// 007d325c  7508                 jne 0x7d3266
// 007d325e  b901000000           mov ecx, 1
// 007d3263  895010               mov dword ptr [eax + 0x10], edx
// 007d3266  8b6814               mov ebp, dword ptr [eax + 0x14]
// 007d3269  3b6f08               cmp ebp, dword ptr [edi + 8]
// 007d326c  7508                 jne 0x7d3276
// 007d326e  b901000000           mov ecx, 1
// 007d3273  895014               mov dword ptr [eax + 0x14], edx
// 007d3276  8b00                 mov eax, dword ptr [eax]
// 007d3278  85c0                 test eax, eax
// 007d327a  75d4                 jne 0x7d3250
// 007d327c  5d                   pop ebp
// 007d327d  85c9                 test ecx, ecx
// 007d327f  741c                 je 0x7d329d
// 007d3281  8b5708               mov edx, dword ptr [edi + 8]
// 007d3284  50                   push eax
// 007d3285  8b4624               mov eax, dword ptr [esi + 0x24]
// 007d3288  52                   push edx
// 007d3289  50                   push eax
// 007d328a  6a00                 push 0
// 007d328c  56                   push esi
// 007d328d  e86e930000           call 0x7dc600
// 007d3292  6a01                 push 1
// 007d3294  56                   push esi
// 007d3295  e8c68e0000           call 0x7dc160
// 007d329a  83c41c               add esp, 0x1c
// 007d329d  5e                   pop esi
// 007d329e  c3                   ret 
// library lua-5.1/lparser.c (function _check_conflict)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
