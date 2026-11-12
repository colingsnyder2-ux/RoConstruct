// from server: 100% by auto
// roc 2008-06 004be1a0  unit: ProfiledRakPeer  size: 823 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be1a0
//
// 004be1a0  55                   push ebp
// 004be1a1  8bec                 mov ebp, esp
// 004be1a3  83ec24               sub esp, 0x24
// 004be1a6  53                   push ebx
// 004be1a7  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004be1aa  56                   push esi
// 004be1ab  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004be1ae  57                   push edi
// 004be1af  b908000000           mov ecx, 8
// 004be1b4  8d7ddc               lea edi, [ebp - 0x24]
// 004be1b7  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be1b9  8b7508               mov esi, dword ptr [ebp + 8]
// 004be1bc  b908000000           mov ecx, 8
// 004be1c1  8bfb                 mov edi, ebx
// 004be1c3  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be1c5  bf00000080           mov edi, 0x80000000
// 004be1ca  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004be1d1  857df8               test dword ptr [ebp - 8], edi
// 004be1d4  0f85c5010000         jne 0x4be39f
// 004be1da  8d45dc               lea eax, [ebp - 0x24]
// 004be1dd  50                   push eax
// 004be1de  53                   push ebx
// 004be1df  e8dce6ffff           call 0x4bc8c0
// 004be1e4  83c408               add esp, 8
// 004be1e7  84c0                 test al, al
// 004be1e9  0f84b0010000         je 0x4be39f
// 004be1ef  b807000000           mov eax, 7
// 004be1f4  833c8300             cmp dword ptr [ebx + eax*4], 0
// 004be1f8  7505                 jne 0x4be1ff
// 004be1fa  83e801               sub eax, 1
// 004be1fd  79f5                 jns 0x4be1f4
// 004be1ff  8bc8                 mov ecx, eax
// 004be201  85c0                 test eax, eax
// 004be203  7c28                 jl 0x4be22d
// 004be205  837c8ddc00           cmp dword ptr [ebp + ecx*4 - 0x24], 0
// 004be20a  7505                 jne 0x4be211
// 004be20c  83e901               sub ecx, 1
// 004be20f  79f4                 jns 0x4be205
// 004be211  3bc1                 cmp eax, ecx
// 004be213  7418                 je 0x4be22d
// 004be215  2bc1                 sub eax, ecx
// 004be217  c1e005               shl eax, 5
// 004be21a  8bf0                 mov esi, eax
// 004be21c  8d4ddc               lea ecx, [ebp - 0x24]
// 004be21f  56                   push esi
// 004be220  51                   push ecx
// 004be221  e8bae5ffff           call 0x4bc7e0
// 004be226  83c408               add esp, 8
// 004be229  46                   inc esi
// 004be22a  8975fc               mov dword ptr [ebp - 4], esi
// 004be22d  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004be230  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004be233  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004be236  8b75e8               mov esi, dword ptr [ebp - 0x18]
// 004be239  857df8               test dword ptr [ebp - 8], edi
// 004be23c  0f85ae000000         jne 0x4be2f0
// 004be242  bb07000000           mov ebx, 7
// 004be247  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be24a  8d9b00000000         lea ebx, [ebx]
// 004be250  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004be253  8b3c9f               mov edi, dword ptr [edi + ebx*4]
// 004be256  8b5c9ddc             mov ebx, dword ptr [ebp + ebx*4 - 0x24]
// 004be25a  3bfb                 cmp edi, ebx
// 004be25c  7716                 ja 0x4be274
// 004be25e  0f828c000000         jb 0x4be2f0
// 004be264  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 004be267  83eb01               sub ebx, 1
// 004be26a  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be26d  79e1                 jns 0x4be250
// 004be26f  e97c000000           jmp 0x4be2f0
// 004be274  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004be277  8bfb                 mov edi, ebx
// 004be279  03db                 add ebx, ebx
// 004be27b  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004be27e  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004be281  c1ef1f               shr edi, 0x1f
// 004be284  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be287  03db                 add ebx, ebx
// 004be289  0bdf                 or ebx, edi
// 004be28b  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be28e  895de0               mov dword ptr [ebp - 0x20], ebx
// 004be291  8b5de4               mov ebx, dword ptr [ebp - 0x1c]
// 004be294  c1ef1f               shr edi, 0x1f
// 004be297  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be29a  03db                 add ebx, ebx
// 004be29c  0bdf                 or ebx, edi
// 004be29e  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be2a1  c1ef1f               shr edi, 0x1f
// 004be2a4  ff45fc               inc dword ptr [ebp - 4]
// 004be2a7  895de4               mov dword ptr [ebp - 0x1c], ebx
// 004be2aa  8bdf                 mov ebx, edi
// 004be2ac  8bfe                 mov edi, esi
// 004be2ae  c1ef1f               shr edi, 0x1f
// 004be2b1  03f6                 add esi, esi
// 004be2b3  0bf3                 or esi, ebx
// 004be2b5  8bda                 mov ebx, edx
// 004be2b7  03d2                 add edx, edx
// 004be2b9  0bd7                 or edx, edi
// 004be2bb  c1eb1f               shr ebx, 0x1f
// 004be2be  8bf9                 mov edi, ecx
// 004be2c0  03c9                 add ecx, ecx
// 004be2c2  0bcb                 or ecx, ebx
// 004be2c4  c1ef1f               shr edi, 0x1f
// 004be2c7  8bd8                 mov ebx, eax
// 004be2c9  03c0                 add eax, eax
// 004be2cb  0bc7                 or eax, edi
// 004be2cd  8b7df8               mov edi, dword ptr [ebp - 8]
// 004be2d0  c1eb1f               shr ebx, 0x1f
// 004be2d3  03ff                 add edi, edi
// 004be2d5  0bfb                 or edi, ebx
// 004be2d7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004be2da  8955ec               mov dword ptr [ebp - 0x14], edx
// 004be2dd  894df0               mov dword ptr [ebp - 0x10], ecx
// 004be2e0  8945f4               mov dword ptr [ebp - 0xc], eax
// 004be2e3  897df8               mov dword ptr [ebp - 8], edi
// 004be2e6  85ff                 test edi, edi
// 004be2e8  0f8954ffffff         jns 0x4be242
// 004be2ee  8bff                 mov edi, edi
// 004be2f0  bf07000000           mov edi, 7
// 004be2f5  897d0c               mov dword ptr [ebp + 0xc], edi
// 004be2f8  eb06                 jmp 0x4be300
// 004be2fa  8d9b00000000         lea ebx, [ebx]
// 004be300  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004be303  8b1cbb               mov ebx, dword ptr [ebx + edi*4]
// 004be306  8b7cbddc             mov edi, dword ptr [ebp + edi*4 - 0x24]
// 004be30a  3bfb                 cmp edi, ebx
// 004be30c  771c                 ja 0x4be32a
// 004be30e  720b                 jb 0x4be31b
// 004be310  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be313  83ef01               sub edi, 1
// 004be316  897d0c               mov dword ptr [ebp + 0xc], edi
// 004be319  79e5                 jns 0x4be300
// 004be31b  837dfc00             cmp dword ptr [ebp - 4], 0
// 004be31f  0f84ab010000         je 0x4be4d0
// 004be325  e9a6000000           jmp 0x4be3d0
// 004be32a  8b5df8               mov ebx, dword ptr [ebp - 8]
// 004be32d  8bfb                 mov edi, ebx
// 004be32f  d1eb                 shr ebx, 1
// 004be331  895df8               mov dword ptr [ebp - 8], ebx
// 004be334  c1e71f               shl edi, 0x1f
// 004be337  8bd8                 mov ebx, eax
// 004be339  c1e31f               shl ebx, 0x1f
// 004be33c  d1e8                 shr eax, 1
// 004be33e  0bc7                 or eax, edi
// 004be340  8bf9                 mov edi, ecx
// 004be342  c1e71f               shl edi, 0x1f
// 004be345  d1e9                 shr ecx, 1
// 004be347  0bcb                 or ecx, ebx
// 004be349  8bda                 mov ebx, edx
// 004be34b  c1e31f               shl ebx, 0x1f
// 004be34e  d1ea                 shr edx, 1
// 004be350  0bd7                 or edx, edi
// 004be352  8bfe                 mov edi, esi
// 004be354  d1ee                 shr esi, 1
// 004be356  0bf3                 or esi, ebx
// 004be358  8b5de4               mov ebx, dword ptr [ebp - 0x1c]
// 004be35b  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be35e  d1eb                 shr ebx, 1
// 004be360  c1e71f               shl edi, 0x1f
// 004be363  0bdf                 or ebx, edi
// 004be365  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be368  895de4               mov dword ptr [ebp - 0x1c], ebx
// 004be36b  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004be36e  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be371  d1eb                 shr ebx, 1
// 004be373  c1e71f               shl edi, 0x1f
// 004be376  0bdf                 or ebx, edi
// 004be378  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be37b  895de0               mov dword ptr [ebp - 0x20], ebx
// 004be37e  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004be381  c1e71f               shl edi, 0x1f
// 004be384  d1eb                 shr ebx, 1
// 004be386  0bdf                 or ebx, edi
// 004be388  ff4dfc               dec dword ptr [ebp - 4]
// 004be38b  8945f4               mov dword ptr [ebp - 0xc], eax
// 004be38e  894df0               mov dword ptr [ebp - 0x10], ecx
// 004be391  8955ec               mov dword ptr [ebp - 0x14], edx
// 004be394  8975e8               mov dword ptr [ebp - 0x18], esi
// 004be397  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004be39a  e951ffffff           jmp 0x4be2f0
// 004be39f  b807000000           mov eax, 7
// 004be3a4  8b0c83               mov ecx, dword ptr [ebx + eax*4]
// 004be3a7  8b5485dc             mov edx, dword ptr [ebp + eax*4 - 0x24]
// 004be3ab  3bd1                 cmp edx, ecx
// 004be3ad  0f871d010000         ja 0x4be4d0
// 004be3b3  7205                 jb 0x4be3ba
// 004be3b5  83e801               sub eax, 1
// 004be3b8  79ea                 jns 0x4be3a4
// 004be3ba  8b75e8               mov esi, dword ptr [ebp - 0x18]
// 004be3bd  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004be3c0  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004be3c3  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004be3c6  eb08                 jmp 0x4be3d0
// 004be3c8  8da42400000000       lea esp, [esp]
// 004be3cf  90                   nop 
// 004be3d0  ff4dfc               dec dword ptr [ebp - 4]
// 004be3d3  bf07000000           mov edi, 7
// 004be3d8  897d0c               mov dword ptr [ebp + 0xc], edi
// 004be3db  eb03                 jmp 0x4be3e0
// 004be3dd  8d4900               lea ecx, [ecx]
// 004be3e0  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 004be3e3  8b1cbb               mov ebx, dword ptr [ebx + edi*4]
// 004be3e6  8b7cbddc             mov edi, dword ptr [ebp + edi*4 - 0x24]
// 004be3ea  3bfb                 cmp edi, ebx
// 004be3ec  776b                 ja 0x4be459
// 004be3ee  720b                 jb 0x4be3fb
// 004be3f0  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be3f3  83ef01               sub edi, 1
// 004be3f6  897d0c               mov dword ptr [ebp + 0xc], edi
// 004be3f9  79e5                 jns 0x4be3e0
// 004be3fb  8d55dc               lea edx, [ebp - 0x24]
// 004be3fe  895508               mov dword ptr [ebp + 8], edx
// 004be401  c7450c01000000       mov dword ptr [ebp + 0xc], 1
// 004be408  8b7508               mov esi, dword ptr [ebp + 8]
// 004be40b  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004be40e  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004be411  8b06                 mov eax, dword ptr [esi]
// 004be413  33d2                 xor edx, edx
// 004be415  2907                 sub dword ptr [edi], eax
// 004be417  8b4604               mov eax, dword ptr [esi + 4]
// 004be41a  194704               sbb dword ptr [edi + 4], eax
// 004be41d  8b4608               mov eax, dword ptr [esi + 8]
// 004be420  194708               sbb dword ptr [edi + 8], eax
// 004be423  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be426  19470c               sbb dword ptr [edi + 0xc], eax
// 004be429  e322                 jecxz 0x4be44d
// 004be42b  42                   inc edx
// 004be42c  42                   inc edx
// 004be42d  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004be430  1904d7               sbb dword ptr [edi + edx*8], eax
// 004be433  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004be437  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004be43b  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004be43f  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004be443  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004be447  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004be44b  e2de                 loop 0x4be42b
// 004be44d  8b45f4               mov eax, dword ptr [ebp - 0xc]
// 004be450  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004be453  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004be456  8b75e8               mov esi, dword ptr [ebp - 0x18]
// 004be459  8b5df8               mov ebx, dword ptr [ebp - 8]
// 004be45c  8bfb                 mov edi, ebx
// 004be45e  d1eb                 shr ebx, 1
// 004be460  895df8               mov dword ptr [ebp - 8], ebx
// 004be463  c1e71f               shl edi, 0x1f
// 004be466  8bd8                 mov ebx, eax
// 004be468  c1e31f               shl ebx, 0x1f
// 004be46b  d1e8                 shr eax, 1
// 004be46d  0bc7                 or eax, edi
// 004be46f  8bf9                 mov edi, ecx
// 004be471  c1e71f               shl edi, 0x1f
// 004be474  d1e9                 shr ecx, 1
// 004be476  0bcb                 or ecx, ebx
// 004be478  8bda                 mov ebx, edx
// 004be47a  c1e31f               shl ebx, 0x1f
// 004be47d  d1ea                 shr edx, 1
// 004be47f  0bd7                 or edx, edi
// 004be481  8bfe                 mov edi, esi
// 004be483  d1ee                 shr esi, 1
// 004be485  0bf3                 or esi, ebx
// 004be487  8b5de4               mov ebx, dword ptr [ebp - 0x1c]
// 004be48a  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be48d  d1eb                 shr ebx, 1
// 004be48f  c1e71f               shl edi, 0x1f
// 004be492  0bdf                 or ebx, edi
// 004be494  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be497  895de4               mov dword ptr [ebp - 0x1c], ebx
// 004be49a  8b5de0               mov ebx, dword ptr [ebp - 0x20]
// 004be49d  895d0c               mov dword ptr [ebp + 0xc], ebx
// 004be4a0  d1eb                 shr ebx, 1
// 004be4a2  c1e71f               shl edi, 0x1f
// 004be4a5  0bdf                 or ebx, edi
// 004be4a7  8b7d0c               mov edi, dword ptr [ebp + 0xc]
// 004be4aa  895de0               mov dword ptr [ebp - 0x20], ebx
// 004be4ad  8b5ddc               mov ebx, dword ptr [ebp - 0x24]
// 004be4b0  c1e71f               shl edi, 0x1f
// 004be4b3  d1eb                 shr ebx, 1
// 004be4b5  0bdf                 or ebx, edi
// 004be4b7  837dfc00             cmp dword ptr [ebp - 4], 0
// 004be4bb  8945f4               mov dword ptr [ebp - 0xc], eax
// 004be4be  894df0               mov dword ptr [ebp - 0x10], ecx
// 004be4c1  8955ec               mov dword ptr [ebp - 0x14], edx
// 004be4c4  8975e8               mov dword ptr [ebp - 0x18], esi
// 004be4c7  895ddc               mov dword ptr [ebp - 0x24], ebx
// 004be4ca  0f8500ffffff         jne 0x4be3d0
// 004be4d0  5f                   pop edi
// 004be4d1  5e                   pop esi
// 004be4d2  5b                   pop ebx
// 004be4d3  8be5                 mov esp, ebp
// 004be4d5  5d                   pop ebp
// 004be4d6  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umodulo@$$BY07I@big@@YAXAAY07I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
