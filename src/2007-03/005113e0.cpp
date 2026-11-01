// from server: 100% by auto
// roc 2007-03 005113e0  unit: seg_00510000  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005113e0
//
// 005113e0  51                   push ecx
// 005113e1  8b542408             mov edx, dword ptr [esp + 8]
// 005113e5  8a4208               mov al, byte ptr [edx + 8]
// 005113e8  3c02                 cmp al, 2
// 005113ea  53                   push ebx
// 005113eb  8b1a                 mov ebx, dword ptr [edx]
// 005113ed  55                   push ebp
// 005113ee  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005113f2  56                   push esi
// 005113f3  57                   push edi
// 005113f4  895c2410             mov dword ptr [esp + 0x10], ebx
// 005113f8  0f8581000000         jne 0x51147f
// 005113fe  85ed                 test ebp, ebp
// 00511400  747d                 je 0x51147f
// 00511402  807a0908             cmp byte ptr [edx + 9], 8
// 00511406  7577                 jne 0x51147f
// 00511408  85db                 test ebx, ebx
// 0051140a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0051140e  8bf9                 mov edi, ecx
// 00511410  7645                 jbe 0x511457
// 00511412  0fb601               movzx eax, byte ptr [ecx]
// 00511415  0fb67101             movzx esi, byte ptr [ecx + 1]
// 00511419  83c101               add ecx, 1
// 0051141c  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00511420  25f8000000           and eax, 0xf8
// 00511425  c1e005               shl eax, 5
// 00511428  83c101               add ecx, 1
// 0051142b  81e6f8000000         and esi, 0xf8
// 00511431  0bc6                 or eax, esi
// 00511433  03c0                 add eax, eax
// 00511435  c1fa03               sar edx, 3
// 00511438  03c0                 add eax, eax
// 0051143a  83e21f               and edx, 0x1f
// 0051143d  0bc2                 or eax, edx
// 0051143f  8a0428               mov al, byte ptr [eax + ebp]
// 00511442  8807                 mov byte ptr [edi], al
// 00511444  83c101               add ecx, 1
// 00511447  83c701               add edi, 1
// 0051144a  83eb01               sub ebx, 1
// 0051144d  75c3                 jne 0x511412
// 0051144f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00511453  8b542418             mov edx, dword ptr [esp + 0x18]
// 00511457  8a4209               mov al, byte ptr [edx + 9]
// 0051145a  88420b               mov byte ptr [edx + 0xb], al
// 0051145d  3c08                 cmp al, 8
// 0051145f  c6420803             mov byte ptr [edx + 8], 3
// 00511463  c6420a01             mov byte ptr [edx + 0xa], 1
// 00511467  0fb6c0               movzx eax, al
// 0051146a  0f829c000000         jb 0x51150c
// 00511470  c1e803               shr eax, 3
// 00511473  0fafc3               imul eax, ebx
// 00511476  5f                   pop edi
// 00511477  5e                   pop esi
// 00511478  5d                   pop ebp
// 00511479  894204               mov dword ptr [edx + 4], eax
// 0051147c  5b                   pop ebx
// 0051147d  59                   pop ecx
// 0051147e  c3                   ret 
// 0051147f  3c06                 cmp al, 6
// 00511481  0f8597000000         jne 0x51151e
// 00511487  85ed                 test ebp, ebp
// 00511489  0f848f000000         je 0x51151e
// 0051148f  807a0908             cmp byte ptr [edx + 9], 8
// 00511493  0f8585000000         jne 0x51151e
// 00511499  85db                 test ebx, ebx
// 0051149b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0051149f  8bf9                 mov edi, ecx
// 005114a1  7645                 jbe 0x5114e8
// 005114a3  0fb601               movzx eax, byte ptr [ecx]
// 005114a6  0fb67101             movzx esi, byte ptr [ecx + 1]
// 005114aa  83c101               add ecx, 1
// 005114ad  0fb65101             movzx edx, byte ptr [ecx + 1]
// 005114b1  25f8000000           and eax, 0xf8
// 005114b6  83c101               add ecx, 1
// 005114b9  c1e005               shl eax, 5
// 005114bc  81e6f8000000         and esi, 0xf8
// 005114c2  0bc6                 or eax, esi
// 005114c4  03c0                 add eax, eax
// 005114c6  c1fa03               sar edx, 3
// 005114c9  83e21f               and edx, 0x1f
// 005114cc  03c0                 add eax, eax
// 005114ce  0bc2                 or eax, edx
// 005114d0  8a1428               mov dl, byte ptr [eax + ebp]
// 005114d3  8817                 mov byte ptr [edi], dl
// 005114d5  83c102               add ecx, 2
// 005114d8  83c701               add edi, 1
// 005114db  83eb01               sub ebx, 1
// 005114de  75c3                 jne 0x5114a3
// 005114e0  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005114e4  8b542418             mov edx, dword ptr [esp + 0x18]
// 005114e8  8a4209               mov al, byte ptr [edx + 9]
// 005114eb  88420b               mov byte ptr [edx + 0xb], al
// 005114ee  3c08                 cmp al, 8
// 005114f0  c6420803             mov byte ptr [edx + 8], 3
// 005114f4  c6420a01             mov byte ptr [edx + 0xa], 1
// 005114f8  0fb6c0               movzx eax, al
// 005114fb  720f                 jb 0x51150c
// 005114fd  c1e803               shr eax, 3
// 00511500  0fafc3               imul eax, ebx
// 00511503  5f                   pop edi
// 00511504  5e                   pop esi
// 00511505  5d                   pop ebp
// 00511506  894204               mov dword ptr [edx + 4], eax
// 00511509  5b                   pop ebx
// 0051150a  59                   pop ecx
// 0051150b  c3                   ret 
// 0051150c  0fafc3               imul eax, ebx
// 0051150f  5f                   pop edi
// 00511510  5e                   pop esi
// 00511511  83c007               add eax, 7
// 00511514  c1e803               shr eax, 3
// 00511517  5d                   pop ebp
// 00511518  894204               mov dword ptr [edx + 4], eax
// 0051151b  5b                   pop ebx
// 0051151c  59                   pop ecx
// 0051151d  c3                   ret 
// 0051151e  3c03                 cmp al, 3
// 00511520  7526                 jne 0x511548
// 00511522  8b742424             mov esi, dword ptr [esp + 0x24]
// 00511526  85f6                 test esi, esi
// 00511528  741e                 je 0x511548
// 0051152a  807a0908             cmp byte ptr [edx + 9], 8
// 0051152e  7518                 jne 0x511548
// 00511530  85db                 test ebx, ebx
// 00511532  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00511536  7610                 jbe 0x511548
// 00511538  0fb608               movzx ecx, byte ptr [eax]
// 0051153b  8a1431               mov dl, byte ptr [ecx + esi]
// 0051153e  8810                 mov byte ptr [eax], dl
// 00511540  83c001               add eax, 1
// 00511543  83eb01               sub ebx, 1
// 00511546  75f0                 jne 0x511538
// 00511548  5f                   pop edi
// 00511549  5e                   pop esi
// 0051154a  5d                   pop ebp
// 0051154b  5b                   pop ebx
// 0051154c  59                   pop ecx
// 0051154d  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_dither)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
