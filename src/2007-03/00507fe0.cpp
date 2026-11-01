// from server: 100% by auto
// roc 2007-03 00507fe0  unit: seg_00500000  size: 453 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00507fe0
//
// 00507fe0  53                   push ebx
// 00507fe1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00507fe5  f7436800040000       test dword ptr [ebx + 0x68], 0x400
// 00507fec  0f85b1010000         jne 0x5081a3
// 00507ff2  56                   push esi
// 00507ff3  57                   push edi
// 00507ff4  53                   push ebx
// 00507ff5  e876d00000           call 0x515070
// 00507ffa  bf00100000           mov edi, 0x1000
// 00507fff  83c404               add esp, 4
// 00508002  857b68               test dword ptr [ebx + 0x68], edi
// 00508005  7421                 je 0x508028
// 00508007  83bb3002000000       cmp dword ptr [ebx + 0x230], 0
// 0050800e  7418                 je 0x508028
// 00508010  68a4077a00           push 0x7a07a4
// 00508015  53                   push ebx
// 00508016  e8b5030100           call 0x5183d0
// 0050801b  83c408               add esp, 8
// 0050801e  c7833002000000000000 mov dword ptr [ebx + 0x230], 0
// 00508028  8b742414             mov esi, dword ptr [esp + 0x14]
// 0050802c  0fb6461c             movzx eax, byte ptr [esi + 0x1c]
// 00508030  0fb64e1b             movzx ecx, byte ptr [esi + 0x1b]
// 00508034  0fb6561a             movzx edx, byte ptr [esi + 0x1a]
// 00508038  50                   push eax
// 00508039  0fb64619             movzx eax, byte ptr [esi + 0x19]
// 0050803d  51                   push ecx
// 0050803e  0fb64e18             movzx ecx, byte ptr [esi + 0x18]
// 00508042  52                   push edx
// 00508043  8b5604               mov edx, dword ptr [esi + 4]
// 00508046  50                   push eax
// 00508047  8b06                 mov eax, dword ptr [esi]
// 00508049  51                   push ecx
// 0050804a  52                   push edx
// 0050804b  50                   push eax
// 0050804c  53                   push ebx
// 0050804d  e8bedf0000           call 0x516010
// 00508052  83c420               add esp, 0x20
// 00508055  f6460801             test byte ptr [esi + 8], 1
// 00508059  7412                 je 0x50806d
// 0050805b  d94628               fld dword ptr [esi + 0x28]
// 0050805e  83ec08               sub esp, 8
// 00508061  dd1c24               fstp qword ptr [esp]
// 00508064  53                   push ebx
// 00508065  e856e40000           call 0x5164c0
// 0050806a  83c40c               add esp, 0xc
// 0050806d  f7460800080000       test dword ptr [esi + 8], 0x800
// 00508074  740e                 je 0x508084
// 00508076  0fb64e2c             movzx ecx, byte ptr [esi + 0x2c]
// 0050807a  51                   push ecx
// 0050807b  53                   push ebx
// 0050807c  e89fe40000           call 0x516520
// 00508081  83c408               add esp, 8
// 00508084  857e08               test dword ptr [esi + 8], edi
// 00508087  7420                 je 0x5080a9
// 00508089  8b96cc000000         mov edx, dword ptr [esi + 0xcc]
// 0050808f  8b86c8000000         mov eax, dword ptr [esi + 0xc8]
// 00508095  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0050809b  52                   push edx
// 0050809c  50                   push eax
// 0050809d  6a00                 push 0
// 0050809f  51                   push ecx
// 005080a0  53                   push ebx
// 005080a1  e8bae40000           call 0x516560
// 005080a6  83c414               add esp, 0x14
// 005080a9  f6460802             test byte ptr [esi + 8], 2
// 005080ad  7412                 je 0x5080c1
// 005080af  0fb65619             movzx edx, byte ptr [esi + 0x19]
// 005080b3  52                   push edx
// 005080b4  8d4644               lea eax, [esi + 0x44]
// 005080b7  50                   push eax
// 005080b8  53                   push ebx
// 005080b9  e812e70000           call 0x5167d0
// 005080be  83c40c               add esp, 0xc
// 005080c1  f6460804             test byte ptr [esi + 8], 4
// 005080c5  745b                 je 0x508122
// 005080c7  d9869c000000         fld dword ptr [esi + 0x9c]
// 005080cd  83ec40               sub esp, 0x40
// 005080d0  dd5c2438             fstp qword ptr [esp + 0x38]
// 005080d4  d98698000000         fld dword ptr [esi + 0x98]
// 005080da  dd5c2430             fstp qword ptr [esp + 0x30]
// 005080de  d98694000000         fld dword ptr [esi + 0x94]
// 005080e4  dd5c2428             fstp qword ptr [esp + 0x28]
// 005080e8  d98690000000         fld dword ptr [esi + 0x90]
// 005080ee  dd5c2420             fstp qword ptr [esp + 0x20]
// 005080f2  d9868c000000         fld dword ptr [esi + 0x8c]
// 005080f8  dd5c2418             fstp qword ptr [esp + 0x18]
// 005080fc  d98688000000         fld dword ptr [esi + 0x88]
// 00508102  dd5c2410             fstp qword ptr [esp + 0x10]
// 00508106  d98684000000         fld dword ptr [esi + 0x84]
// 0050810c  dd5c2408             fstp qword ptr [esp + 8]
// 00508110  d98680000000         fld dword ptr [esi + 0x80]
// 00508116  dd1c24               fstp qword ptr [esp]
// 00508119  53                   push ebx
// 0050811a  e871e70000           call 0x516890
// 0050811f  83c444               add esp, 0x44
// 00508122  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00508128  85c0                 test eax, eax
// 0050812a  746e                 je 0x50819a
// 0050812c  8bbebc000000         mov edi, dword ptr [esi + 0xbc]
// 00508132  8d0c80               lea ecx, [eax + eax*4]
// 00508135  8d148f               lea edx, [edi + ecx*4]
// 00508138  3bfa                 cmp edi, edx
// 0050813a  735e                 jae 0x50819a
// 0050813c  8d642400             lea esp, [esp]
// 00508140  57                   push edi
// 00508141  53                   push ebx
// 00508142  e8492a0000           call 0x50ab90
// 00508147  83c408               add esp, 8
// 0050814a  83f801               cmp eax, 1
// 0050814d  7432                 je 0x508181
// 0050814f  8a4f10               mov cl, byte ptr [edi + 0x10]
// 00508152  84c9                 test cl, cl
// 00508154  742b                 je 0x508181
// 00508156  f6c106               test cl, 6
// 00508159  7526                 jne 0x508181
// 0050815b  f6470320             test byte ptr [edi + 3], 0x20
// 0050815f  750e                 jne 0x50816f
// 00508161  83f803               cmp eax, 3
// 00508164  7409                 je 0x50816f
// 00508166  f7436c00000100       test dword ptr [ebx + 0x6c], 0x10000
// 0050816d  7412                 je 0x508181
// 0050816f  8b470c               mov eax, dword ptr [edi + 0xc]
// 00508172  8b4f08               mov ecx, dword ptr [edi + 8]
// 00508175  50                   push eax
// 00508176  51                   push ecx
// 00508177  57                   push edi
// 00508178  53                   push ebx
// 00508179  e862de0000           call 0x515fe0
// 0050817e  83c410               add esp, 0x10
// 00508181  8b86c0000000         mov eax, dword ptr [esi + 0xc0]
// 00508187  8d1480               lea edx, [eax + eax*4]
// 0050818a  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 00508190  83c714               add edi, 0x14
// 00508193  8d0c90               lea ecx, [eax + edx*4]
// 00508196  3bf9                 cmp edi, ecx
// 00508198  72a6                 jb 0x508140
// 0050819a  814b6800040000       or dword ptr [ebx + 0x68], 0x400
// 005081a1  5f                   pop edi
// 005081a2  5e                   pop esi
// 005081a3  5b                   pop ebx
// 005081a4  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_write_info_before_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
