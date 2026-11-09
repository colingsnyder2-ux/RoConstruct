// from server: 100% by auto
// roc 2009-06 0057f0c0  unit: G3D::_internal::DialogTemplate  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057f0c0
//
// 0057f0c0  55                   push ebp
// 0057f0c1  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0057f0c5  85ed                 test ebp, ebp
// 0057f0c7  0f84da010000         je 0x57f2a7
// 0057f0cd  56                   push esi
// 0057f0ce  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057f0d2  85f6                 test esi, esi
// 0057f0d4  0f84cc010000         je 0x57f2a6
// 0057f0da  f7456800040000       test dword ptr [ebp + 0x68], 0x400
// 0057f0e1  0f85bf010000         jne 0x57f2a6
// 0057f0e7  57                   push edi
// 0057f0e8  55                   push ebp
// 0057f0e9  e862b70000           call 0x58a850
// 0057f0ee  bf00100000           mov edi, 0x1000
// 0057f0f3  83c404               add esp, 4
// 0057f0f6  857d68               test dword ptr [ebp + 0x68], edi
// 0057f0f9  7421                 je 0x57f11c
// 0057f0fb  83bd3002000000       cmp dword ptr [ebp + 0x230], 0
// 0057f102  7418                 je 0x57f11c
// 0057f104  683cc28c00           push 0x8cc23c
// 0057f109  55                   push ebp
// 0057f10a  e801f10000           call 0x58e210
// 0057f10f  83c408               add esp, 8
// 0057f112  c7853002000000000000 mov dword ptr [ebp + 0x230], 0
// 0057f11c  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 0057f120  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 0057f124  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 0057f128  50                   push eax
// 0057f129  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0057f12d  51                   push ecx
// 0057f12e  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 0057f132  52                   push edx
// 0057f133  8b5604               mov edx, dword ptr [esi + 4]
// 0057f136  50                   push eax
// 0057f137  8b06                 mov eax, dword ptr [esi]
// 0057f139  51                   push ecx
// 0057f13a  52                   push edx
// 0057f13b  50                   push eax
// 0057f13c  55                   push ebp
// 0057f13d  e85ec90000           call 0x58baa0
// 0057f142  83c420               add esp, 0x20
// 0057f145  f6460801             test byte ptr [esi + 8], 1
// 0057f149  7412                 je 0x57f15d
// 0057f14b  d94628               fld dword ptr [esi + 0x28]
// 0057f14e  83ec08               sub esp, 8
// 0057f151  dd1c24               fstp qword ptr [esp]
// 0057f154  55                   push ebp
// 0057f155  e836cf0000           call 0x58c090
// 0057f15a  83c40c               add esp, 0xc
// 0057f15d  f7460800080000       test dword ptr [esi + 8], 0x800
// 0057f164  740e                 je 0x57f174
// 0057f166  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 0057f16a  51                   push ecx
// 0057f16b  55                   push ebp
// 0057f16c  e8ffcf0000           call 0x58c170
// 0057f171  83c408               add esp, 8
// 0057f174  857e08               test dword ptr [esi + 8], edi
// 0057f177  7420                 je 0x57f199
// 0057f179  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0057f17f  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 0057f185  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0057f18b  52                   push edx
// 0057f18c  50                   push eax
// 0057f18d  6a00                 push 0
// 0057f18f  51                   push ecx
// 0057f190  55                   push ebp
// 0057f191  e88ad00000           call 0x58c220
// 0057f196  83c414               add esp, 0x14
// 0057f199  f6460802             test byte ptr [esi + 8], 2
// 0057f19d  7412                 je 0x57f1b1
// 0057f19f  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 0057f1a3  52                   push edx
// 0057f1a4  8d4644               lea eax, [esi + 0x44]
// 0057f1a7  50                   push eax
// 0057f1a8  55                   push ebp
// 0057f1a9  e8c2d30000           call 0x58c570
// 0057f1ae  83c40c               add esp, 0xc
// 0057f1b1  f6460804             test byte ptr [esi + 8], 4
// 0057f1b5  745b                 je 0x57f212
// 0057f1b7  d9869c000000         fld dword ptr [esi + 0x9c]
// 0057f1bd  83ec40               sub esp, 0x40
// 0057f1c0  dd5c2438             fstp qword ptr [esp + 0x38]
// 0057f1c4  d98698000000         fld dword ptr [esi + 0x98]
// 0057f1ca  dd5c2430             fstp qword ptr [esp + 0x30]
// 0057f1ce  d98694000000         fld dword ptr [esi + 0x94]
// 0057f1d4  dd5c2428             fstp qword ptr [esp + 0x28]
// 0057f1d8  d98690000000         fld dword ptr [esi + 0x90]
// 0057f1de  dd5c2420             fstp qword ptr [esp + 0x20]
// 0057f1e2  d9868c000000         fld dword ptr [esi + 0x8c]
// 0057f1e8  dd5c2418             fstp qword ptr [esp + 0x18]
// 0057f1ec  d98688000000         fld dword ptr [esi + 0x88]
// 0057f1f2  dd5c2410             fstp qword ptr [esp + 0x10]
// 0057f1f6  d98684000000         fld dword ptr [esi + 0x84]
// 0057f1fc  dd5c2408             fstp qword ptr [esp + 8]
// 0057f200  d98680000000         fld dword ptr [esi + 0x80]
// 0057f206  dd1c24               fstp qword ptr [esp]
// 0057f209  55                   push ebp
// 0057f20a  e841d40000           call 0x58c650
// 0057f20f  83c444               add esp, 0x44
// 0057f212  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f218  85c0                 test eax, eax
// 0057f21a  0f847e000000         je 0x57f29e
// 0057f220  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 0057f226  8d0c80               lea ecx, [eax + eax*4]
// 0057f229  8d148f               lea edx, [edi + ecx*4]
// 0057f22c  3bfa                 cmp edi, edx
// 0057f22e  736e                 jae 0x57f29e
// 0057f230  57                   push edi
// 0057f231  55                   push ebp
// 0057f232  e8f92a0000           call 0x581d30
// 0057f237  83c408               add esp, 8
// 0057f23a  83f801               cmp eax, 1
// 0057f23d  7446                 je 0x57f285
// 0057f23f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 0057f242  84c9                 test cl, cl
// 0057f244  743f                 je 0x57f285
// 0057f246  f6c106               test cl, 6
// 0057f249  753a                 jne 0x57f285
// 0057f24b  f6470320             test byte ptr [edi + 3], 0x20
// 0057f24f  750e                 jne 0x57f25f
// 0057f251  83f803               cmp eax, 3
// 0057f254  7409                 je 0x57f25f
// 0057f256  f7456c00000100       test dword ptr [ebp + 0x6c], 0x10000
// 0057f25d  7426                 je 0x57f285
// 0057f25f  837f0c00             cmp dword ptr [edi + 0xc], 0
// 0057f263  750e                 jne 0x57f273
// 0057f265  6818c28c00           push 0x8cc218
// 0057f26a  55                   push ebp
// 0057f26b  e8a0ef0000           call 0x58e210
// 0057f270  83c408               add esp, 8
// 0057f273  8b470c               mov eax, dword ptr [edi + 0xc]
// 0057f276  8b4f08               mov ecx, dword ptr [edi + 8]
// 0057f279  50                   push eax
// 0057f27a  51                   push ecx
// 0057f27b  57                   push edi
// 0057f27c  55                   push ebp
// 0057f27d  e89ec70000           call 0x58ba20
// 0057f282  83c410               add esp, 0x10
// 0057f285  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 0057f28b  8d1480               lea edx, [eax + eax*4]
// 0057f28e  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 0057f294  83c714               add edi, 0x14
// 0057f297  8d0c90               lea ecx, [eax + edx*4]
// 0057f29a  3bf9                 cmp edi, ecx
// 0057f29c  7292                 jb 0x57f230
// 0057f29e  814d6800040000       or dword ptr [ebp + 0x68], 0x400
// 0057f2a5  5f                   pop edi
// 0057f2a6  5e                   pop esi
// 0057f2a7  5d                   pop ebp
// 0057f2a8  c3                   ret 
// library libpng-1.2.29/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngwrite.c
