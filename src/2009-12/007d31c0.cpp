// from server: 100% by auto
// roc 2009-12 007d31c0  unit: seg_007d0000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d31c0
//
// 007d31c0  83ec0c               sub esp, 0xc
// 007d31c3  56                   push esi
// 007d31c4  8b7030               mov esi, dword ptr [eax + 0x30]
// 007d31c7  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 007d31cf  c644240e00           mov byte ptr [esp + 0xe], 0
// 007d31d4  8a4e32               mov cl, byte ptr [esi + 0x32]
// 007d31d7  884c240c             mov byte ptr [esp + 0xc], cl
// 007d31db  c644240d00           mov byte ptr [esp + 0xd], 0
// 007d31e0  8b5614               mov edx, dword ptr [esi + 0x14]
// 007d31e3  57                   push edi
// 007d31e4  8d4c2408             lea ecx, [esp + 8]
// 007d31e8  89542408             mov dword ptr [esp + 8], edx
// 007d31ec  50                   push eax
// 007d31ed  894e14               mov dword ptr [esi + 0x14], ecx
// 007d31f0  e8ab130000           call 0x7d45a0
// 007d31f5  8b7e14               mov edi, dword ptr [esi + 0x14]
// 007d31f8  8b17                 mov edx, dword ptr [edi]
// 007d31fa  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d31fd  895614               mov dword ptr [esi + 0x14], edx
// 007d3200  0fb65708             movzx edx, byte ptr [edi + 8]
// 007d3204  83c404               add esp, 4
// 007d3207  e8a4e8ffff           call 0x7d1ab0
// 007d320c  807f0900             cmp byte ptr [edi + 9], 0
// 007d3210  7414                 je 0x7d3226
// 007d3212  0fb64708             movzx eax, byte ptr [edi + 8]
// 007d3216  6a00                 push 0
// 007d3218  6a00                 push 0
// 007d321a  50                   push eax
// 007d321b  6a23                 push 0x23
// 007d321d  56                   push esi
// 007d321e  e8dd930000           call 0x7dc600
// 007d3223  83c414               add esp, 0x14
// 007d3226  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d322a  894e24               mov dword ptr [esi + 0x24], ecx
// 007d322d  8b5704               mov edx, dword ptr [edi + 4]
// 007d3230  52                   push edx
// 007d3231  56                   push esi
// 007d3232  e829960000           call 0x7dc860
// 007d3237  83c408               add esp, 8
// 007d323a  5f                   pop edi
// 007d323b  5e                   pop esi
// 007d323c  83c40c               add esp, 0xc
// 007d323f  c3                   ret 
// library lua-5.1/lparser.c (function _block)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
