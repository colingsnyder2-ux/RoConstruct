// from server: 100% by auto
// roc 2010-06 00564930  unit: seg_00560000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00564930
//
// 00564930  55                   push ebp
// 00564931  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00564935  85ed                 test ebp, ebp
// 00564937  0f84da000000         je 0x564a17
// 0056493d  56                   push esi
// 0056493e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564942  85f6                 test esi, esi
// 00564944  0f84cc000000         je 0x564a16
// 0056494a  53                   push ebx
// 0056494b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0056494f  57                   push edi
// 00564950  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00564954  85ff                 test edi, edi
// 00564956  743d                 je 0x564995
// 00564958  6a00                 push 0
// 0056495a  6800200000           push 0x2000
// 0056495f  56                   push esi
// 00564960  55                   push ebp
// 00564961  e8ca060000           call 0x565030
// 00564966  6800010000           push 0x100
// 0056496b  55                   push ebp
// 0056496c  e82fdc0000           call 0x5725a0
// 00564971  89464c               mov dword ptr [esi + 0x4c], eax
// 00564974  898588010000         mov dword ptr [ebp + 0x188], eax
// 0056497a  8d43ff               lea eax, [ebx - 1]
// 0056497d  83c418               add esp, 0x18
// 00564980  3dff000000           cmp eax, 0xff
// 00564985  770e                 ja 0x564995
// 00564987  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0056498a  53                   push ebx
// 0056498b  57                   push edi
// 0056498c  51                   push ecx
// 0056498d  e894442400           call 0x7a8e26
// 00564992  83c40c               add esp, 0xc
// 00564995  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00564999  85ff                 test edi, edi
// 0056499b  7461                 je 0x5649fe
// 0056499d  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 005649a1  b801000000           mov eax, 1
// 005649a6  d3e0                 shl eax, cl
// 005649a8  8a4e19               mov cl, byte ptr [esi + 0x19]
// 005649ab  84c9                 test cl, cl
// 005649ad  7508                 jne 0x5649b7
// 005649af  0fb75708             movzx edx, word ptr [edi + 8]
// 005649b3  3bd0                 cmp edx, eax
// 005649b5  7f1d                 jg 0x5649d4
// 005649b7  80f902               cmp cl, 2
// 005649ba  7526                 jne 0x5649e2
// 005649bc  0fb74f02             movzx ecx, word ptr [edi + 2]
// 005649c0  3bc8                 cmp ecx, eax
// 005649c2  7f10                 jg 0x5649d4
// 005649c4  0fb75704             movzx edx, word ptr [edi + 4]
// 005649c8  3bd0                 cmp edx, eax
// 005649ca  7f08                 jg 0x5649d4
// 005649cc  0fb74f06             movzx ecx, word ptr [edi + 6]
// 005649d0  3bc8                 cmp ecx, eax
// 005649d2  7e0e                 jle 0x5649e2
// 005649d4  686814a200           push 0xa21468
// 005649d9  55                   push ebp
// 005649da  e881d10000           call 0x571b60
// 005649df  83c408               add esp, 8
// 005649e2  8b17                 mov edx, dword ptr [edi]
// 005649e4  895650               mov dword ptr [esi + 0x50], edx
// 005649e7  8b4704               mov eax, dword ptr [edi + 4]
// 005649ea  894654               mov dword ptr [esi + 0x54], eax
// 005649ed  668b4f08             mov cx, word ptr [edi + 8]
// 005649f1  66894e58             mov word ptr [esi + 0x58], cx
// 005649f5  85db                 test ebx, ebx
// 005649f7  7505                 jne 0x5649fe
// 005649f9  bb01000000           mov ebx, 1
// 005649fe  5f                   pop edi
// 005649ff  66895e16             mov word ptr [esi + 0x16], bx
// 00564a03  85db                 test ebx, ebx
// 00564a05  5b                   pop ebx
// 00564a06  740e                 je 0x564a16
// 00564a08  834e0810             or dword ptr [esi + 8], 0x10
// 00564a0c  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 00564a16  5e                   pop esi
// 00564a17  5d                   pop ebp
// 00564a18  c3                   ret 
// library libpng-1.2.32/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngset.c
