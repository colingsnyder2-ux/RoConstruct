// roc 2012-06 005bb1c0  unit: RakNet::RakPeer  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb1c0
//
// 005bb1c0  56                   push esi
// 005bb1c1  8bf1                 mov esi, ecx
// 005bb1c3  68f815d900           push 0xd915f8
// 005bb1c8  8d4c240c             lea ecx, [esp + 0xc]
// 005bb1cc  e83f6bfaff           call 0x561d10
// 005bb1d1  84c0                 test al, al
// 005bb1d3  7407                 je 0x5bb1dc
// 005bb1d5  83c8ff               or eax, 0xffffffff
// 005bb1d8  5e                   pop esi
// 005bb1d9  c21000               ret 0x10
// 005bb1dc  668b442410           mov ax, word ptr [esp + 0x10]
// 005bb1e1  b9ffff0000           mov ecx, 0xffff
// 005bb1e6  663bc1               cmp ax, cx
// 005bb1e9  7447                 je 0x5bb232
// 005bb1eb  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bb1ef  7341                 jae 0x5bb232
// 005bb1f1  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bb1f7  0fb7c0               movzx eax, ax
// 005bb1fa  69c008120000         imul eax, eax, 0x1208
// 005bb200  8d542408             lea edx, [esp + 8]
// 005bb204  52                   push edx
// 005bb205  8d8c08e0110000       lea ecx, [eax + ecx + 0x11e0]
// 005bb20c  e8ff6afaff           call 0x561d10
// 005bb211  84c0                 test al, al
// 005bb213  741d                 je 0x5bb232
// 005bb215  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 005bb21a  8b8e2c020000         mov ecx, dword ptr [esi + 0x22c]
// 005bb220  8bd0                 mov edx, eax
// 005bb222  69d208120000         imul edx, edx, 0x1208
// 005bb228  803c0a00             cmp byte ptr [edx + ecx], 0
// 005bb22c  0f857d000000         jne 0x5bb2af
// 005bb232  53                   push ebx
// 005bb233  57                   push edi
// 005bb234  33d2                 xor edx, edx
// 005bb236  33ff                 xor edi, edi
// 005bb238  663b560e             cmp dx, word ptr [esi + 0xe]
// 005bb23c  7332                 jae 0x5bb270
// 005bb23e  33db                 xor ebx, ebx
// 005bb240  8b862c020000         mov eax, dword ptr [esi + 0x22c]
// 005bb246  03c3                 add eax, ebx
// 005bb248  803800               cmp byte ptr [eax], 0
// 005bb24b  7414                 je 0x5bb261
// 005bb24d  8d4c2410             lea ecx, [esp + 0x10]
// 005bb251  51                   push ecx
// 005bb252  8d88e0110000         lea ecx, [eax + 0x11e0]
// 005bb258  e8b36afaff           call 0x561d10
// 005bb25d  84c0                 test al, al
// 005bb25f  7552                 jne 0x5bb2b3
// 005bb261  0fb7560e             movzx edx, word ptr [esi + 0xe]
// 005bb265  47                   inc edi
// 005bb266  81c308120000         add ebx, 0x1208
// 005bb26c  3bfa                 cmp edi, edx
// 005bb26e  72d0                 jb 0x5bb240
// 005bb270  33c0                 xor eax, eax
// 005bb272  33ff                 xor edi, edi
// 005bb274  663b460e             cmp ax, word ptr [esi + 0xe]
// 005bb278  7330                 jae 0x5bb2aa
// 005bb27a  33db                 xor ebx, ebx
// 005bb27c  8d642400             lea esp, [esp]
// 005bb280  8b962c020000         mov edx, dword ptr [esi + 0x22c]
// 005bb286  8d4c2410             lea ecx, [esp + 0x10]
// 005bb28a  51                   push ecx
// 005bb28b  8d8c13e0110000       lea ecx, [ebx + edx + 0x11e0]
// 005bb292  e8796afaff           call 0x561d10
// 005bb297  84c0                 test al, al
// 005bb299  7518                 jne 0x5bb2b3
// 005bb29b  0fb7460e             movzx eax, word ptr [esi + 0xe]
// 005bb29f  47                   inc edi
// 005bb2a0  81c308120000         add ebx, 0x1208
// 005bb2a6  3bf8                 cmp edi, eax
// 005bb2a8  72d6                 jb 0x5bb280
// 005bb2aa  5f                   pop edi
// 005bb2ab  83c8ff               or eax, 0xffffffff
// 005bb2ae  5b                   pop ebx
// 005bb2af  5e                   pop esi
// 005bb2b0  c21000               ret 0x10
// 005bb2b3  8bc7                 mov eax, edi
// 005bb2b5  5f                   pop edi
// 005bb2b6  5b                   pop ebx
// 005bb2b7  5e                   pop esi
// 005bb2b8  c21000               ret 0x10
// copied from an identical function in another client (function ?GetIndexFromGuid@RakPeer@RakNet@@IAEHURakNetGUID@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp