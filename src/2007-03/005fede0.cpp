// from server: 100% by auto
// roc 2007-03 005fede0  unit: seg_005f0000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fede0
//
// 005fede0  83ec0c               sub esp, 0xc
// 005fede3  56                   push esi
// 005fede4  8b7030               mov esi, dword ptr [eax + 0x30]
// 005fede7  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 005fedef  c644240e00           mov byte ptr [esp + 0xe], 0
// 005fedf4  8a4e32               mov cl, byte ptr [esi + 0x32]
// 005fedf7  884c240c             mov byte ptr [esp + 0xc], cl
// 005fedfb  c644240d00           mov byte ptr [esp + 0xd], 0
// 005fee00  8b5614               mov edx, dword ptr [esi + 0x14]
// 005fee03  57                   push edi
// 005fee04  8d4c2408             lea ecx, [esp + 8]
// 005fee08  89542408             mov dword ptr [esp + 8], edx
// 005fee0c  50                   push eax
// 005fee0d  894e14               mov dword ptr [esi + 0x14], ecx
// 005fee10  e88b130000           call 0x6001a0
// 005fee15  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005fee18  8b17                 mov edx, dword ptr [edi]
// 005fee1a  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fee1d  895614               mov dword ptr [esi + 0x14], edx
// 005fee20  0fb65708             movzx edx, byte ptr [edi + 8]
// 005fee24  83c404               add esp, 4
// 005fee27  e884e8ffff           call 0x5fd6b0
// 005fee2c  807f0900             cmp byte ptr [edi + 9], 0
// 005fee30  7414                 je 0x5fee46
// 005fee32  0fb64708             movzx eax, byte ptr [edi + 8]
// 005fee36  6a00                 push 0
// 005fee38  6a00                 push 0
// 005fee3a  50                   push eax
// 005fee3b  6a23                 push 0x23
// 005fee3d  56                   push esi
// 005fee3e  e86d5d0100           call 0x614bb0
// 005fee43  83c414               add esp, 0x14
// 005fee46  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 005fee4a  894e24               mov dword ptr [esi + 0x24], ecx
// 005fee4d  8b5704               mov edx, dword ptr [edi + 4]
// 005fee50  52                   push edx
// 005fee51  56                   push esi
// 005fee52  e8b95f0100           call 0x614e10
// 005fee57  83c408               add esp, 8
// 005fee5a  5f                   pop edi
// 005fee5b  5e                   pop esi
// 005fee5c  83c40c               add esp, 0xc
// 005fee5f  c3                   ret 
// library lua-5.1.1/lparser.c (function _block)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
