// from server: 100% by auto
// roc 2007-03 00516390  unit: seg_00510000  size: 270 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00516390
//
// 00516390  55                   push ebp
// 00516391  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00516395  57                   push edi
// 00516396  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0051639a  f6476804             test byte ptr [edi + 0x68], 4
// 0051639e  0f85df000000         jne 0x516483
// 005163a4  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 005163ab  0f85d2000000         jne 0x516483
// 005163b1  56                   push esi
// 005163b2  0fb67500             movzx esi, byte ptr [ebp]
// 005163b6  8bc6                 mov eax, esi
// 005163b8  240f                 and al, 0xf
// 005163ba  3c08                 cmp al, 8
// 005163bc  0f85b2000000         jne 0x516474
// 005163c2  8bce                 mov ecx, esi
// 005163c4  81e1f0000000         and ecx, 0xf0
// 005163ca  83f970               cmp ecx, 0x70
// 005163cd  0f87a1000000         ja 0x516474
// 005163d3  837c241802           cmp dword ptr [esp + 0x18], 2
// 005163d8  0f82a4000000         jb 0x516482
// 005163de  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 005163e4  81fa00400000         cmp edx, 0x4000
// 005163ea  0f8392000000         jae 0x516482
// 005163f0  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 005163f6  81f900400000         cmp ecx, 0x4000
// 005163fc  0f8380000000         jae 0x516482
// 00516402  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 00516409  53                   push ebx
// 0051640a  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 00516411  0fafc3               imul eax, ebx
// 00516414  0fafc1               imul eax, ecx
// 00516417  83c00f               add eax, 0xf
// 0051641a  c1e803               shr eax, 3
// 0051641d  0fafc2               imul eax, edx
// 00516420  c1ee04               shr esi, 4
// 00516423  8d4e07               lea ecx, [esi + 7]
// 00516426  ba01000000           mov edx, 1
// 0051642b  d3e2                 shl edx, cl
// 0051642d  5b                   pop ebx
// 0051642e  3bc2                 cmp eax, edx
// 00516430  7711                 ja 0x516443
// 00516432  81fa00010000         cmp edx, 0x100
// 00516438  7209                 jb 0x516443
// 0051643a  d1ea                 shr edx, 1
// 0051643c  83ee01               sub esi, 1
// 0051643f  3bc2                 cmp eax, edx
// 00516441  76ef                 jbe 0x516432
// 00516443  c1e604               shl esi, 4
// 00516446  83ce08               or esi, 8
// 00516449  8bc6                 mov eax, esi
// 0051644b  384500               cmp byte ptr [ebp], al
// 0051644e  7432                 je 0x516482
// 00516450  8a4d01               mov cl, byte ptr [ebp + 1]
// 00516453  80e1e0               and cl, 0xe0
// 00516456  0fb6d1               movzx edx, cl
// 00516459  884500               mov byte ptr [ebp], al
// 0051645c  c1e008               shl eax, 8
// 0051645f  03c2                 add eax, edx
// 00516461  33d2                 xor edx, edx
// 00516463  be1f000000           mov esi, 0x1f
// 00516468  f7f6                 div esi
// 0051646a  2aca                 sub cl, dl
// 0051646c  80c11f               add cl, 0x1f
// 0051646f  884d01               mov byte ptr [ebp + 1], cl
// 00516472  eb0e                 jmp 0x516482
// 00516474  6854317a00           push 0x7a3154
// 00516479  57                   push edi
// 0051647a  e8a11e0000           call 0x518320
// 0051647f  83c408               add esp, 8
// 00516482  5e                   pop esi
// 00516483  8b442414             mov eax, dword ptr [esp + 0x14]
// 00516487  50                   push eax
// 00516488  55                   push ebp
// 00516489  68a40e7a00           push 0x7a0ea4
// 0051648e  57                   push edi
// 0051648f  e84cfbffff           call 0x515fe0
// 00516494  834f6804             or dword ptr [edi + 0x68], 4
// 00516498  83c410               add esp, 0x10
// 0051649b  5f                   pop edi
// 0051649c  5d                   pop ebp
// 0051649d  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
