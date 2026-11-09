// from server: 100% by auto
// roc 2009-12 00602fc0  unit: seg_00600000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00602fc0
//
// 00602fc0  55                   push ebp
// 00602fc1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00602fc5  85ed                 test ebp, ebp
// 00602fc7  0f84da000000         je 0x6030a7
// 00602fcd  56                   push esi
// 00602fce  8b742410             mov esi, dword ptr [esp + 0x10]
// 00602fd2  85f6                 test esi, esi
// 00602fd4  0f84cc000000         je 0x6030a6
// 00602fda  53                   push ebx
// 00602fdb  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00602fdf  57                   push edi
// 00602fe0  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00602fe4  85ff                 test edi, edi
// 00602fe6  743d                 je 0x603025
// 00602fe8  6a00                 push 0
// 00602fea  6800200000           push 0x2000
// 00602fef  56                   push esi
// 00602ff0  55                   push ebp
// 00602ff1  e8ca060000           call 0x6036c0
// 00602ff6  6800010000           push 0x100
// 00602ffb  55                   push ebp
// 00602ffc  e87fdc0000           call 0x610c80
// 00603001  89464c               mov dword ptr [esi + 0x4c], eax
// 00603004  898588010000         mov dword ptr [ebp + 0x188], eax
// 0060300a  8d43ff               lea eax, [ebx - 1]
// 0060300d  83c418               add esp, 0x18
// 00603010  3dff000000           cmp eax, 0xff
// 00603015  770e                 ja 0x603025
// 00603017  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0060301a  53                   push ebx
// 0060301b  57                   push edi
// 0060301c  51                   push ecx
// 0060301d  e8c41c1f00           call 0x7f4ce6
// 00603022  83c40c               add esp, 0xc
// 00603025  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00603029  85ff                 test edi, edi
// 0060302b  7461                 je 0x60308e
// 0060302d  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00603031  b801000000           mov eax, 1
// 00603036  d3e0                 shl eax, cl
// 00603038  8a4e19               mov cl, byte ptr [esi + 0x19]
// 0060303b  84c9                 test cl, cl
// 0060303d  7508                 jne 0x603047
// 0060303f  0fb75708             movzx edx, word ptr [edi + 8]
// 00603043  3bd0                 cmp edx, eax
// 00603045  7f1d                 jg 0x603064
// 00603047  80f902               cmp cl, 2
// 0060304a  7526                 jne 0x603072
// 0060304c  0fb74f02             movzx ecx, word ptr [edi + 2]
// 00603050  3bc8                 cmp ecx, eax
// 00603052  7f10                 jg 0x603064
// 00603054  0fb75704             movzx edx, word ptr [edi + 4]
// 00603058  3bd0                 cmp edx, eax
// 0060305a  7f08                 jg 0x603064
// 0060305c  0fb74f06             movzx ecx, word ptr [edi + 6]
// 00603060  3bc8                 cmp ecx, eax
// 00603062  7e0e                 jle 0x603072
// 00603064  6808379c00           push 0x9c3708
// 00603069  55                   push ebp
// 0060306a  e8d1d10000           call 0x610240
// 0060306f  83c408               add esp, 8
// 00603072  8b17                 mov edx, dword ptr [edi]
// 00603074  895650               mov dword ptr [esi + 0x50], edx
// 00603077  8b4704               mov eax, dword ptr [edi + 4]
// 0060307a  894654               mov dword ptr [esi + 0x54], eax
// 0060307d  668b4f08             mov cx, word ptr [edi + 8]
// 00603081  66894e58             mov word ptr [esi + 0x58], cx
// 00603085  85db                 test ebx, ebx
// 00603087  7505                 jne 0x60308e
// 00603089  bb01000000           mov ebx, 1
// 0060308e  5f                   pop edi
// 0060308f  66895e16             mov word ptr [esi + 0x16], bx
// 00603093  85db                 test ebx, ebx
// 00603095  5b                   pop ebx
// 00603096  740e                 je 0x6030a6
// 00603098  834e0810             or dword ptr [esi + 8], 0x10
// 0060309c  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 006030a6  5e                   pop esi
// 006030a7  5d                   pop ebp
// 006030a8  c3                   ret 
// library libpng-1.2.32/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngset.c
