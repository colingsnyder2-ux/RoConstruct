// from server: 100% by auto
// roc 2009-12 00618320  unit: seg_00610000  size: 374 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00618320
//
// 00618320  81ec04020000         sub esp, 0x204
// 00618326  55                   push ebp
// 00618327  8bac2410020000       mov ebp, dword ptr [esp + 0x210]
// 0061832e  56                   push esi
// 0061832f  8bb42410020000       mov esi, dword ptr [esp + 0x210]
// 00618336  8b4668               mov eax, dword ptr [esi + 0x68]
// 00618339  a801                 test al, 1
// 0061833b  0f85ac000000         jne 0x6183ed
// 00618341  68ec979c00           push 0x9c97ec
// 00618346  56                   push esi
// 00618347  e8447effff           call 0x610190
// 0061834c  83c408               add esp, 8
// 0061834f  0fb78618010000       movzx eax, word ptr [esi + 0x118]
// 00618356  53                   push ebx
// 00618357  57                   push edi
// 00618358  8bbc2420020000       mov edi, dword ptr [esp + 0x220]
// 0061835f  8bdf                 mov ebx, edi
// 00618361  d1eb                 shr ebx, 1
// 00618363  3bd8                 cmp ebx, eax
// 00618365  0f850b010000         jne 0x618476
// 0061836b  81fb00010000         cmp ebx, 0x100
// 00618371  0f87ff000000         ja 0x618476
// 00618377  33ff                 xor edi, edi
// 00618379  85db                 test ebx, ebx
// 0061837b  7643                 jbe 0x6183c0
// 0061837d  8d4900               lea ecx, [ecx]
// 00618380  6a02                 push 2
// 00618382  8d4c2414             lea ecx, [esp + 0x14]
// 00618386  51                   push ecx
// 00618387  56                   push esi
// 00618388  e80327ffff           call 0x60aa90
// 0061838d  6a02                 push 2
// 0061838f  8d542420             lea edx, [esp + 0x20]
// 00618393  52                   push edx
// 00618394  56                   push esi
// 00618395  e8d6b2feff           call 0x603670
// 0061839a  668b442428           mov ax, word ptr [esp + 0x28]
// 0061839f  660fb6c8             movzx cx, al
// 006183a3  ba00010000           mov edx, 0x100
// 006183a8  660fafca             imul cx, dx
// 006183ac  660fb6c4             movzx ax, ah
// 006183b0  6603c8               add cx, ax
// 006183b3  66894c7c2c           mov word ptr [esp + edi*2 + 0x2c], cx
// 006183b8  47                   inc edi
// 006183b9  83c418               add esp, 0x18
// 006183bc  3bfb                 cmp edi, ebx
// 006183be  72c0                 jb 0x618380
// 006183c0  6a00                 push 0
// 006183c2  56                   push esi
// 006183c3  e828e8ffff           call 0x616bf0
// 006183c8  83c408               add esp, 8
// 006183cb  85c0                 test eax, eax
// 006183cd  0f85b8000000         jne 0x61848b
// 006183d3  8d4c2414             lea ecx, [esp + 0x14]
// 006183d7  51                   push ecx
// 006183d8  55                   push ebp
// 006183d9  56                   push esi
// 006183da  e8f1a1feff           call 0x6025d0
// 006183df  83c40c               add esp, 0xc
// 006183e2  5f                   pop edi
// 006183e3  5b                   pop ebx
// 006183e4  5e                   pop esi
// 006183e5  5d                   pop ebp
// 006183e6  81c404020000         add esp, 0x204
// 006183ec  c3                   ret 
// 006183ed  a804                 test al, 4
// 006183ef  7425                 je 0x618416
// 006183f1  68d4979c00           push 0x9c97d4
// 006183f6  56                   push esi
// 006183f7  e8447effff           call 0x610240
// 006183fc  8b842420020000       mov eax, dword ptr [esp + 0x220]
// 00618403  50                   push eax
// 00618404  56                   push esi
// 00618405  e8e6e7ffff           call 0x616bf0
// 0061840a  83c410               add esp, 0x10
// 0061840d  5e                   pop esi
// 0061840e  5d                   pop ebp
// 0061840f  81c404020000         add esp, 0x204
// 00618415  c3                   ret 
// 00618416  a802                 test al, 2
// 00618418  7525                 jne 0x61843f
// 0061841a  68b8979c00           push 0x9c97b8
// 0061841f  56                   push esi
// 00618420  e81b7effff           call 0x610240
// 00618425  8b8c2420020000       mov ecx, dword ptr [esp + 0x220]
// 0061842c  51                   push ecx
// 0061842d  56                   push esi
// 0061842e  e8bde7ffff           call 0x616bf0
// 00618433  83c410               add esp, 0x10
// 00618436  5e                   pop esi
// 00618437  5d                   pop ebp
// 00618438  81c404020000         add esp, 0x204
// 0061843e  c3                   ret 
// 0061843f  85ed                 test ebp, ebp
// 00618441  0f8408ffffff         je 0x61834f
// 00618447  f6450840             test byte ptr [ebp + 8], 0x40
// 0061844b  0f84fefeffff         je 0x61834f
// 00618451  68a0979c00           push 0x9c97a0
// 00618456  56                   push esi
// 00618457  e8e47dffff           call 0x610240
// 0061845c  8b942420020000       mov edx, dword ptr [esp + 0x220]
// 00618463  52                   push edx
// 00618464  56                   push esi
// 00618465  e886e7ffff           call 0x616bf0
// 0061846a  83c410               add esp, 0x10
// 0061846d  5e                   pop esi
// 0061846e  5d                   pop ebp
// 0061846f  81c404020000         add esp, 0x204
// 00618475  c3                   ret 
// 00618476  6884979c00           push 0x9c9784
// 0061847b  56                   push esi
// 0061847c  e8bf7dffff           call 0x610240
// 00618481  57                   push edi
// 00618482  56                   push esi
// 00618483  e868e7ffff           call 0x616bf0
// 00618488  83c410               add esp, 0x10
// 0061848b  5f                   pop edi
// 0061848c  5b                   pop ebx
// 0061848d  5e                   pop esi
// 0061848e  5d                   pop ebp
// 0061848f  81c404020000         add esp, 0x204
// 00618495  c3                   ret 
// library libpng-1.2.6/pngrutil.c (function _png_handle_hIST)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrutil.c
