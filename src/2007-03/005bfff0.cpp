// from server: 100% by auto
// roc 2007-03 005bfff0  unit: seg_005b0000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfff0
//
// 005bfff0  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bfff3  53                   push ebx
// 005bfff4  57                   push edi
// 005bfff5  8b38                 mov edi, dword ptr [eax]
// 005bfff7  8bc2                 mov eax, edx
// 005bfff9  897e08               mov dword ptr [esi + 8], edi
// 005bfffc  8d5801               lea ebx, [eax + 1]
// 005bffff  90                   nop 
// 005c0000  8a08                 mov cl, byte ptr [eax]
// 005c0002  83c001               add eax, 1
// 005c0005  84c9                 test cl, cl
// 005c0007  75f7                 jne 0x5c0000
// 005c0009  2bc3                 sub eax, ebx
// 005c000b  50                   push eax
// 005c000c  52                   push edx
// 005c000d  56                   push esi
// 005c000e  e80dc70300           call 0x5fc720
// 005c0013  8907                 mov dword ptr [edi], eax
// 005c0015  c7470804000000       mov dword ptr [edi + 8], 4
// 005c001c  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005c001f  2b4e08               sub ecx, dword ptr [esi + 8]
// 005c0022  bf10000000           mov edi, 0x10
// 005c0027  83c40c               add esp, 0xc
// 005c002a  3bcf                 cmp ecx, edi
// 005c002c  7f2d                 jg 0x5c005b
// 005c002e  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005c0031  83f801               cmp eax, 1
// 005c0034  7c18                 jl 0x5c004e
// 005c0036  8d1400               lea edx, [eax + eax]
// 005c0039  52                   push edx
// 005c003a  56                   push esi
// 005c003b  e8d0fbffff           call 0x5bfc10
// 005c0040  83c408               add esp, 8
// 005c0043  017e08               add dword ptr [esi + 8], edi
// 005c0046  5f                   pop edi
// 005c0047  b802000000           mov eax, 2
// 005c004c  5b                   pop ebx
// 005c004d  c3                   ret 
// 005c004e  83c001               add eax, 1
// 005c0051  50                   push eax
// 005c0052  56                   push esi
// 005c0053  e8b8fbffff           call 0x5bfc10
// 005c0058  83c408               add esp, 8
// 005c005b  017e08               add dword ptr [esi + 8], edi
// 005c005e  5f                   pop edi
// 005c005f  b802000000           mov eax, 2
// 005c0064  5b                   pop ebx
// 005c0065  c3                   ret 
// library lua-5.1.1/ldo.c (function _resume_error)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
