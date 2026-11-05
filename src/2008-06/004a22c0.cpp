// from server: 100% by auto
// roc 2008-06 004a22c0  unit: RBX::Network::VServer::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a22c0
//
// 004a22c0  64a100000000         mov eax, dword ptr fs:[0]
// 004a22c6  6aff                 push -1
// 004a22c8  6842e87d00           push 0x7de842
// 004a22cd  50                   push eax
// 004a22ce  64892500000000       mov dword ptr fs:[0], esp
// 004a22d5  83ec44               sub esp, 0x44
// 004a22d8  57                   push edi
// 004a22d9  8bf9                 mov edi, ecx
// 004a22db  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 004a22e2  7259                 jb 0x4a233d
// 004a22e4  688cb28000           push 0x80b28c
// 004a22e9  8d4c2408             lea ecx, [esp + 8]
// 004a22ed  ff1558248000         call dword ptr [0x802458]
// 004a22f3  8d4c2420             lea ecx, [esp + 0x20]
// 004a22f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004a22ff  ff1598288000         call dword ptr [0x802898]
// 004a2305  8d442404             lea eax, [esp + 4]
// 004a2309  50                   push eax
// 004a230a  8d4c2430             lea ecx, [esp + 0x30]
// 004a230e  c644245401           mov byte ptr [esp + 0x54], 1
// 004a2313  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004a231b  ff155c248000         call dword ptr [0x80245c]
// 004a2321  68c00c8d00           push 0x8d0cc0
// 004a2326  8d4c2424             lea ecx, [esp + 0x24]
// 004a232a  51                   push ecx
// 004a232b  c644245800           mov byte ptr [esp + 0x58], 0
// 004a2330  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004a2338  e84ff21f00           call 0x6a158c
// 004a233d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004a2341  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a2344  53                   push ebx
// 004a2345  55                   push ebp
// 004a2346  56                   push esi
// 004a2347  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004a234b  6a00                 push 0
// 004a234d  52                   push edx
// 004a234e  50                   push eax
// 004a234f  56                   push esi
// 004a2350  50                   push eax
// 004a2351  e83afcffff           call 0x4a1f90
// 004a2356  8be8                 mov ebp, eax
// 004a2358  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a235b  bb01000000           mov ebx, 1
// 004a2360  015f1c               add dword ptr [edi + 0x1c], ebx
// 004a2363  3bf0                 cmp esi, eax
// 004a2365  7510                 jne 0x4a2377
// 004a2367  896804               mov dword ptr [eax + 4], ebp
// 004a236a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a236d  8928                 mov dword ptr [eax], ebp
// 004a236f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004a2372  896908               mov dword ptr [ecx + 8], ebp
// 004a2375  eb22                 jmp 0x4a2399
// 004a2377  807c246800           cmp byte ptr [esp + 0x68], 0
// 004a237c  740d                 je 0x4a238b
// 004a237e  892e                 mov dword ptr [esi], ebp
// 004a2380  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a2383  3b30                 cmp esi, dword ptr [eax]
// 004a2385  7512                 jne 0x4a2399
// 004a2387  8928                 mov dword ptr [eax], ebp
// 004a2389  eb0e                 jmp 0x4a2399
// 004a238b  896e08               mov dword ptr [esi + 8], ebp
// 004a238e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004a2391  3b7008               cmp esi, dword ptr [eax + 8]
// 004a2394  7503                 jne 0x4a2399
// 004a2396  896808               mov dword ptr [eax + 8], ebp
// 004a2399  8b5504               mov edx, dword ptr [ebp + 4]
// 004a239c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004a23a0  8d4504               lea eax, [ebp + 4]
// 004a23a3  8bf5                 mov esi, ebp
// 004a23a5  0f85ea000000         jne 0x4a2495
// 004a23ab  eb03                 jmp 0x4a23b0
// 004a23ad  8d4900               lea ecx, [ecx]
// 004a23b0  8b08                 mov ecx, dword ptr [eax]
// 004a23b2  8b5104               mov edx, dword ptr [ecx + 4]
// 004a23b5  3b0a                 cmp ecx, dword ptr [edx]
// 004a23b7  7551                 jne 0x4a240a
// 004a23b9  8b5208               mov edx, dword ptr [edx + 8]
// 004a23bc  807a2800             cmp byte ptr [edx + 0x28], 0
// 004a23c0  7519                 jne 0x4a23db
// 004a23c2  885928               mov byte ptr [ecx + 0x28], bl
// 004a23c5  885a28               mov byte ptr [edx + 0x28], bl
// 004a23c8  8b10                 mov edx, dword ptr [eax]
// 004a23ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a23cd  c6412800             mov byte ptr [ecx + 0x28], 0
// 004a23d1  8b10                 mov edx, dword ptr [eax]
// 004a23d3  8b7204               mov esi, dword ptr [edx + 4]
// 004a23d6  e9aa000000           jmp 0x4a2485
// 004a23db  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a23de  750a                 jne 0x4a23ea
// 004a23e0  8bf1                 mov esi, ecx
// 004a23e2  56                   push esi
// 004a23e3  8bcf                 mov ecx, edi
// 004a23e5  e8b6510300           call 0x4d75a0
// 004a23ea  8b4604               mov eax, dword ptr [esi + 4]
// 004a23ed  885828               mov byte ptr [eax + 0x28], bl
// 004a23f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a23f3  8b5104               mov edx, dword ptr [ecx + 4]
// 004a23f6  c6422800             mov byte ptr [edx + 0x28], 0
// 004a23fa  8b4604               mov eax, dword ptr [esi + 4]
// 004a23fd  8b4804               mov ecx, dword ptr [eax + 4]
// 004a2400  51                   push ecx
// 004a2401  8bcf                 mov ecx, edi
// 004a2403  e888f6ffff           call 0x4a1a90
// 004a2408  eb7b                 jmp 0x4a2485
// 004a240a  8b12                 mov edx, dword ptr [edx]
// 004a240c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004a2410  7516                 jne 0x4a2428
// 004a2412  885928               mov byte ptr [ecx + 0x28], bl
// 004a2415  885a28               mov byte ptr [edx + 0x28], bl
// 004a2418  8b10                 mov edx, dword ptr [eax]
// 004a241a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a241d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004a2421  8b10                 mov edx, dword ptr [eax]
// 004a2423  8b7204               mov esi, dword ptr [edx + 4]
// 004a2426  eb5d                 jmp 0x4a2485
// 004a2428  3b31                 cmp esi, dword ptr [ecx]
// 004a242a  750a                 jne 0x4a2436
// 004a242c  8bf1                 mov esi, ecx
// 004a242e  56                   push esi
// 004a242f  8bcf                 mov ecx, edi
// 004a2431  e85af6ffff           call 0x4a1a90
// 004a2436  8b4604               mov eax, dword ptr [esi + 4]
// 004a2439  885828               mov byte ptr [eax + 0x28], bl
// 004a243c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a243f  8b5104               mov edx, dword ptr [ecx + 4]
// 004a2442  c6422800             mov byte ptr [edx + 0x28], 0
// 004a2446  8b4604               mov eax, dword ptr [esi + 4]
// 004a2449  8b4004               mov eax, dword ptr [eax + 4]
// 004a244c  8b4808               mov ecx, dword ptr [eax + 8]
// 004a244f  8b11                 mov edx, dword ptr [ecx]
// 004a2451  895008               mov dword ptr [eax + 8], edx
// 004a2454  8b11                 mov edx, dword ptr [ecx]
// 004a2456  807a2900             cmp byte ptr [edx + 0x29], 0
// 004a245a  7503                 jne 0x4a245f
// 004a245c  894204               mov dword ptr [edx + 4], eax
// 004a245f  8b5004               mov edx, dword ptr [eax + 4]
// 004a2462  895104               mov dword ptr [ecx + 4], edx
// 004a2465  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a2468  3b4204               cmp eax, dword ptr [edx + 4]
// 004a246b  7505                 jne 0x4a2472
// 004a246d  894a04               mov dword ptr [edx + 4], ecx
// 004a2470  eb0e                 jmp 0x4a2480
// 004a2472  8b5004               mov edx, dword ptr [eax + 4]
// 004a2475  3b02                 cmp eax, dword ptr [edx]
// 004a2477  7504                 jne 0x4a247d
// 004a2479  890a                 mov dword ptr [edx], ecx
// 004a247b  eb03                 jmp 0x4a2480
// 004a247d  894a08               mov dword ptr [edx + 8], ecx
// 004a2480  8901                 mov dword ptr [ecx], eax
// 004a2482  894804               mov dword ptr [eax + 4], ecx
// 004a2485  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2488  80792800             cmp byte ptr [ecx + 0x28], 0
// 004a248c  8d4604               lea eax, [esi + 4]
// 004a248f  0f841bffffff         je 0x4a23b0
// 004a2495  8b5718               mov edx, dword ptr [edi + 0x18]
// 004a2498  8b4204               mov eax, dword ptr [edx + 4]
// 004a249b  885828               mov byte ptr [eax + 0x28], bl
// 004a249e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004a24a2  8b0f                 mov ecx, dword ptr [edi]
// 004a24a4  5e                   pop esi
// 004a24a5  896804               mov dword ptr [eax + 4], ebp
// 004a24a8  5d                   pop ebp
// 004a24a9  8908                 mov dword ptr [eax], ecx
// 004a24ab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a24af  5b                   pop ebx
// 004a24b0  5f                   pop edi
// 004a24b1  64890d00000000       mov dword ptr fs:[0], ecx
// 004a24b8  83c450               add esp, 0x50
// 004a24bb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
