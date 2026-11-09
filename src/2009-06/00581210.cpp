// from server: 100% by auto
// roc 2009-06 00581210  unit: seg_00580000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581210
//
// 00581210  55                   push ebp
// 00581211  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00581215  85ed                 test ebp, ebp
// 00581217  0f84da000000         je 0x5812f7
// 0058121d  56                   push esi
// 0058121e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00581222  85f6                 test esi, esi
// 00581224  0f84cc000000         je 0x5812f6
// 0058122a  53                   push ebx
// 0058122b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0058122f  57                   push edi
// 00581230  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00581234  85ff                 test edi, edi
// 00581236  743d                 je 0x581275
// 00581238  6a00                 push 0
// 0058123a  6800200000           push 0x2000
// 0058123f  56                   push esi
// 00581240  55                   push ebp
// 00581241  e8ca060000           call 0x581910
// 00581246  6800010000           push 0x100
// 0058124b  55                   push ebp
// 0058124c  e8ffd90000           call 0x58ec50
// 00581251  89464c               mov dword ptr [esi + 0x4c], eax
// 00581254  898588010000         mov dword ptr [ebp + 0x188], eax
// 0058125a  8d43ff               lea eax, [ebx - 1]
// 0058125d  83c418               add esp, 0x18
// 00581260  3dff000000           cmp eax, 0xff
// 00581265  770e                 ja 0x581275
// 00581267  8b4e4c               mov ecx, dword ptr [esi + 0x4c]
// 0058126a  53                   push ebx
// 0058126b  57                   push edi
// 0058126c  51                   push ecx
// 0058126d  e8448c1900           call 0x719eb6
// 00581272  83c40c               add esp, 0xc
// 00581275  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00581279  85ff                 test edi, edi
// 0058127b  7461                 je 0x5812de
// 0058127d  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00581281  b801000000           mov eax, 1
// 00581286  d3e0                 shl eax, cl
// 00581288  8a4e19               mov cl, byte ptr [esi + 0x19]
// 0058128b  84c9                 test cl, cl
// 0058128d  7508                 jne 0x581297
// 0058128f  0fb75708             movzx edx, word ptr [edi + 8]
// 00581293  3bd0                 cmp edx, eax
// 00581295  7f1d                 jg 0x5812b4
// 00581297  80f902               cmp cl, 2
// 0058129a  7526                 jne 0x5812c2
// 0058129c  0fb74f02             movzx ecx, word ptr [edi + 2]
// 005812a0  3bc8                 cmp ecx, eax
// 005812a2  7f10                 jg 0x5812b4
// 005812a4  0fb75704             movzx edx, word ptr [edi + 4]
// 005812a8  3bd0                 cmp edx, eax
// 005812aa  7f08                 jg 0x5812b4
// 005812ac  0fb74f06             movzx ecx, word ptr [edi + 6]
// 005812b0  3bc8                 cmp ecx, eax
// 005812b2  7e0e                 jle 0x5812c2
// 005812b4  6868c88c00           push 0x8cc868
// 005812b9  55                   push ebp
// 005812ba  e851cf0000           call 0x58e210
// 005812bf  83c408               add esp, 8
// 005812c2  8b17                 mov edx, dword ptr [edi]
// 005812c4  895650               mov dword ptr [esi + 0x50], edx
// 005812c7  8b4704               mov eax, dword ptr [edi + 4]
// 005812ca  894654               mov dword ptr [esi + 0x54], eax
// 005812cd  668b4f08             mov cx, word ptr [edi + 8]
// 005812d1  66894e58             mov word ptr [esi + 0x58], cx
// 005812d5  85db                 test ebx, ebx
// 005812d7  7505                 jne 0x5812de
// 005812d9  bb01000000           mov ebx, 1
// 005812de  5f                   pop edi
// 005812df  66895e16             mov word ptr [esi + 0x16], bx
// 005812e3  85db                 test ebx, ebx
// 005812e5  5b                   pop ebx
// 005812e6  740e                 je 0x5812f6
// 005812e8  834e0810             or dword ptr [esi + 8], 0x10
// 005812ec  818eb800000000200000 or dword ptr [esi + 0xb8], 0x2000
// 005812f6  5e                   pop esi
// 005812f7  5d                   pop ebp
// 005812f8  c3                   ret 
// library libpng-1.2.32/pngset.c (function _png_set_tRNS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngset.c
