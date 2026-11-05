// from server: 100% by auto
// roc 2012-06 006472f0  unit: seg_00640000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006472f0
//
// 006472f0  55                   push ebp
// 006472f1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 006472f5  85ed                 test ebp, ebp
// 006472f7  0f84da000000         je 0x6473d7
// 006472fd  56                   push esi
// 006472fe  8b742410             mov esi, dword ptr [esp + 0x10]
// 00647302  85f6                 test esi, esi
// 00647304  0f84cc000000         je 0x6473d6
// 0064730a  53                   push ebx
// 0064730b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0064730f  57                   push edi
// 00647310  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00647314  85ff                 test edi, edi
// 00647316  743d                 je 0x647355
// 00647318  6a00                 push 0
// 0064731a  6800200000           push 0x2000
// 0064731f  56                   push esi
// 00647320  55                   push ebp
// 00647321  e8ba6bffff           call 0x63dee0
// 00647326  6800010000           push 0x100
// 0064732b  55                   push ebp
// 0064732c  e88f710000           call 0x64e4c0
// 00647331  89464c               mov dword ptr [esi + 0x4c], eax
// 00647334  898588010000         mov dword ptr [ebp + 0x188], eax
// 0064733a  8d43ff               lea eax, [ebx - 1]
// 0064733d  83c418               add esp, 0x18
// 00647340  3dff000000           cmp eax, 0xff
// 00647345  770e                 ja 0x647355
// 00647347  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0064734a  53                   push ebx
// 0064734b  57                   push edi
// 0064734c  51                   push ecx
// 0064734d  e80ac33300           call 0x98365c
// 00647352  83c40c               add esp, 0xc
// 00647355  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00647359  85ff                 test edi, edi
// 0064735b  7461                 je 0x6473be
// 0064735d  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00647361  b801000000           mov eax, 1
// 00647366  d3e0                 shl eax, cl
// 00647368  8a4e19               mov cl, byte ptr [esi + 0x19]
// 0064736b  84c9                 test cl, cl
// 0064736d  7508                 jne 0x647377
// 0064736f  0fb75708             movzx edx, word ptr [edi + 8]
// 00647373  3bd0                 cmp edx, eax
// 00647375  7f1d                 jg 0x647394
// 00647377  80f902               cmp cl, 2
// 0064737a  7526                 jne 0x6473a2
// 0064737c  0fb74f02             movzx ecx, word ptr [edi + 2]
// 00647380  3bc8                 cmp ecx, eax
// 00647382  7f10                 jg 0x647394
// 00647384  0fb75704             movzx edx, word ptr [edi + 4]
// 00647388  3bd0                 cmp edx, eax
// 0064738a  7f08                 jg 0x647394
// 0064738c  0fb74f06             movzx ecx, word ptr [edi + 6]
// 00647390  3bc8                 cmp ecx, eax
// 00647392  7e0e                 jle 0x6473a2
// 00647394  689063b800           push 0xb86390
// 00647399  55                   push ebp
// 0064739a  e8c16e0000           call 0x64e260
// 0064739f  83c408               add esp, 8
// 006473a2  8b17                 mov edx, dword ptr [edi]
// 006473a4  895650               mov dword ptr [esi + 0x50], edx
// 006473a7  8b4704               mov eax, dword ptr [edi + 4]
// 006473aa  894654               mov dword ptr [esi + 0x54], eax
// 006473ad  668b4f08             mov cx, word ptr [edi + 8]
// 006473b1  66894e58             mov word ptr [esi + 0x58], cx
// 006473b5  85db                 test ebx, ebx
// 006473b7  7505                 jne 0x6473be
// 006473b9  bb01000000           mov ebx, 1
// 006473be  5f                   pop edi
// 006473bf  66895e16             mov word ptr [esi + 0x16], bx
// 006473c3  85db                 test ebx, ebx
// 006473c5  5b                   pop ebx
// 006473c6  740e                 je 0x6473d6
// 006473c8  834e0810             or dword ptr [esi + 8], 0x10
// 006473cc  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 006473d6  5e                   pop esi
// 006473d7  5d                   pop ebp
// 006473d8  c3                   ret 
// library libpng-1.2.32/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngset.c
