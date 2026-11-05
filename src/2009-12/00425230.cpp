// from server: 100% by auto
// roc 2009-12 00425230  unit: MainLogManager  size: 484 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425230
//
// 00425230  55                   push ebp
// 00425231  8bec                 mov ebp, esp
// 00425233  6aff                 push -1
// 00425235  6892919200           push 0x929192
// 0042523a  64a100000000         mov eax, dword ptr fs:[0]
// 00425240  50                   push eax
// 00425241  64892500000000       mov dword ptr fs:[0], esp
// 00425248  83ec50               sub esp, 0x50
// 0042524b  53                   push ebx
// 0042524c  56                   push esi
// 0042524d  8bf1                 mov esi, ecx
// 0042524f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425252  57                   push edi
// 00425253  8965f0               mov dword ptr [ebp - 0x10], esp
// 00425256  8975e0               mov dword ptr [ebp - 0x20], esi
// 00425259  85c0                 test eax, eax
// 0042525b  7505                 jne 0x425262
// 0042525d  8945ec               mov dword ptr [ebp - 0x14], eax
// 00425260  eb1b                 jmp 0x42527d
// 00425262  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00425265  2bc8                 sub ecx, eax
// 00425267  b893244992           mov eax, 0x92492493
// 0042526c  f7e9                 imul ecx
// 0042526e  03d1                 add edx, ecx
// 00425270  c1fa04               sar edx, 4
// 00425273  8bc2                 mov eax, edx
// 00425275  c1e81f               shr eax, 0x1f
// 00425278  03c2                 add eax, edx
// 0042527a  8945ec               mov dword ptr [ebp - 0x14], eax
// 0042527d  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00425280  85ff                 test edi, edi
// 00425282  0f842d030000         je 0x4255b5
// 00425288  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0042528b  8bcb                 mov ecx, ebx
// 0042528d  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00425290  b893244992           mov eax, 0x92492493
// 00425295  f7e9                 imul ecx
// 00425297  03d1                 add edx, ecx
// 00425299  c1fa04               sar edx, 4
// 0042529c  8bc2                 mov eax, edx
// 0042529e  c1e81f               shr eax, 0x1f
// 004252a1  03c2                 add eax, edx
// 004252a3  b949922409           mov ecx, 0x9249249
// 004252a8  2bc8                 sub ecx, eax
// 004252aa  3bcf                 cmp ecx, edi
// 004252ac  7305                 jae 0x4252b3
// 004252ae  e8adce0100           call 0x442160
// 004252b3  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004252b6  03c7                 add eax, edi
// 004252b8  3bc8                 cmp ecx, eax
// 004252ba  0f83b6010000         jae 0x425476
// 004252c0  8bd1                 mov edx, ecx
// 004252c2  d1ea                 shr edx, 1
// 004252c4  bb49922409           mov ebx, 0x9249249
// 004252c9  2bda                 sub ebx, edx
// 004252cb  3bd9                 cmp ebx, ecx
// 004252cd  730c                 jae 0x4252db
// 004252cf  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 004252d6  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004252d9  eb05                 jmp 0x4252e0
// 004252db  03ca                 add ecx, edx
// 004252dd  894dec               mov dword ptr [ebp - 0x14], ecx
// 004252e0  3bc8                 cmp ecx, eax
// 004252e2  7305                 jae 0x4252e9
// 004252e4  8945ec               mov dword ptr [ebp - 0x14], eax
// 004252e7  8bc8                 mov ecx, eax
// 004252e9  6a00                 push 0
// 004252eb  51                   push ecx
// 004252ec  e81f32ffff           call 0x418510
// 004252f1  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 004252f4  2b5e0c               sub ebx, dword ptr [esi + 0xc]
// 004252f7  8bc8                 mov ecx, eax
// 004252f9  b893244992           mov eax, 0x92492493
// 004252fe  f7eb                 imul ebx
// 00425300  03d3                 add edx, ebx
// 00425302  c1fa04               sar edx, 4
// 00425305  8bda                 mov ebx, edx
// 00425307  33c0                 xor eax, eax
// 00425309  c1eb1f               shr ebx, 0x1f
// 0042530c  03da                 add ebx, edx
// 0042530e  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00425311  83c408               add esp, 8
// 00425314  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00425317  8945fc               mov dword ptr [ebp - 4], eax
// 0042531a  52                   push edx
// 0042531b  8d04dd00000000       lea eax, [ebx*8]
// 00425322  894de8               mov dword ptr [ebp - 0x18], ecx
// 00425325  2bc3                 sub eax, ebx
// 00425327  8d0c81               lea ecx, [ecx + eax*4]
// 0042532a  57                   push edi
// 0042532b  51                   push ecx
// 0042532c  8bce                 mov ecx, esi
// 0042532e  895ddc               mov dword ptr [ebp - 0x24], ebx
// 00425331  e8bafeffff           call 0x4251f0
// 00425336  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425339  c6451400             mov byte ptr [ebp + 0x14], 0
// 0042533d  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00425340  52                   push edx
// 00425341  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00425344  52                   push edx
// 00425345  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00425348  8d4e08               lea ecx, [esi + 8]
// 0042534b  51                   push ecx
// 0042534c  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0042534f  51                   push ecx
// 00425350  52                   push edx
// 00425351  50                   push eax
// 00425352  c745e401000000       mov dword ptr [ebp - 0x1c], 1
// 00425359  e8f2f1ffff           call 0x424550
// 0042535e  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00425361  8b4610               mov eax, dword ptr [esi + 0x10]
// 00425364  03df                 add ebx, edi
// 00425366  83c418               add esp, 0x18
// 00425369  8d0cdd00000000       lea ecx, [ebx*8]
// 00425370  2bcb                 sub ecx, ebx
// 00425372  8d0c8a               lea ecx, [edx + ecx*4]
// 00425375  c6451400             mov byte ptr [ebp + 0x14], 0
// 00425379  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0042537c  52                   push edx
// 0042537d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00425380  52                   push edx
// 00425381  8d5608               lea edx, [esi + 8]
// 00425384  52                   push edx
// 00425385  51                   push ecx
// 00425386  50                   push eax
// 00425387  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0042538a  50                   push eax
// 0042538b  c745e402000000       mov dword ptr [ebp - 0x1c], 2
// 00425392  e8b9f1ffff           call 0x424550
// 00425397  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0042539a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042539d  2bcb                 sub ecx, ebx
// 0042539f  b893244992           mov eax, 0x92492493
// 004253a4  f7e9                 imul ecx
// 004253a6  03d1                 add edx, ecx
// 004253a8  c1fa04               sar edx, 4
// 004253ab  8bca                 mov ecx, edx
// 004253ad  c1e91f               shr ecx, 0x1f
// 004253b0  03ca                 add ecx, edx
// 004253b2  83c418               add esp, 0x18
// 004253b5  03f9                 add edi, ecx
// 004253b7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004253be  85db                 test ebx, ebx
// 004253c0  7418                 je 0x4253da
// 004253c2  8b5610               mov edx, dword ptr [esi + 0x10]
// 004253c5  52                   push edx
// 004253c6  53                   push ebx
// 004253c7  8bce                 mov ecx, esi
// 004253c9  e80232ffff           call 0x4185d0
// 004253ce  8b460c               mov eax, dword ptr [esi + 0xc]
// 004253d1  50                   push eax
// 004253d2  e883e43c00           call 0x7f385a
// 004253d7  83c404               add esp, 4
// 004253da  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004253dd  8d0cc500000000       lea ecx, [eax*8]
// 004253e4  2bc8                 sub ecx, eax
// 004253e6  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 004253e9  8d1488               lea edx, [eax + ecx*4]
// 004253ec  8d0cfd00000000       lea ecx, [edi*8]
// 004253f3  2bcf                 sub ecx, edi
// 004253f5  895614               mov dword ptr [esi + 0x14], edx
// 004253f8  8d1488               lea edx, [eax + ecx*4]
// 004253fb  895610               mov dword ptr [esi + 0x10], edx
// 004253fe  89460c               mov dword ptr [esi + 0xc], eax
// 00425401  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00425404  64890d00000000       mov dword ptr fs:[0], ecx
// 0042540b  5f                   pop edi
// 0042540c  5e                   pop esi
// 0042540d  5b                   pop ebx
// 0042540e  8be5                 mov esp, ebp
// 00425410  5d                   pop ebp
// 00425411  c21000               ret 0x10
// standard library vector<string> (function ?_Insert_n@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@IABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
