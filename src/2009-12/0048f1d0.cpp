// from server: 100% by auto
// roc 2009-12 0048f1d0  unit: RBX::RbxTextureProxy  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048f1d0
//
// 0048f1d0  64a100000000         mov eax, dword ptr fs:[0]
// 0048f1d6  6aff                 push -1
// 0048f1d8  6812699500           push 0x956912
// 0048f1dd  50                   push eax
// 0048f1de  64892500000000       mov dword ptr fs:[0], esp
// 0048f1e5  83ec44               sub esp, 0x44
// 0048f1e8  57                   push edi
// 0048f1e9  8bf9                 mov edi, ecx
// 0048f1eb  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 0048f1f2  7259                 jb 0x48f24d
// 0048f1f4  6800f59900           push 0x99f500
// 0048f1f9  8d4c2408             lea ecx, [esp + 8]
// 0048f1fd  ff15f4b69800         call dword ptr [0x98b6f4]
// 0048f203  8d4c2420             lea ecx, [esp + 0x20]
// 0048f207  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0048f20f  ff1554b79800         call dword ptr [0x98b754]
// 0048f215  8d442404             lea eax, [esp + 4]
// 0048f219  50                   push eax
// 0048f21a  8d4c2430             lea ecx, [esp + 0x30]
// 0048f21e  c644245401           mov byte ptr [esp + 0x54], 1
// 0048f223  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0048f22b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0048f231  68e4efa800           push 0xa8efe4
// 0048f236  8d4c2424             lea ecx, [esp + 0x24]
// 0048f23a  51                   push ecx
// 0048f23b  c644245800           mov byte ptr [esp + 0x58], 0
// 0048f240  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0048f248  e82b563600           call 0x7f4878
// 0048f24d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0048f251  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f254  53                   push ebx
// 0048f255  55                   push ebp
// 0048f256  56                   push esi
// 0048f257  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0048f25b  6a00                 push 0
// 0048f25d  52                   push edx
// 0048f25e  50                   push eax
// 0048f25f  56                   push esi
// 0048f260  50                   push eax
// 0048f261  e80affffff           call 0x48f170
// 0048f266  8be8                 mov ebp, eax
// 0048f268  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f26b  bb01000000           mov ebx, 1
// 0048f270  015f1c               add dword ptr [edi + 0x1c], ebx
// 0048f273  3bf0                 cmp esi, eax
// 0048f275  7510                 jne 0x48f287
// 0048f277  896804               mov dword ptr [eax + 4], ebp
// 0048f27a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f27d  8928                 mov dword ptr [eax], ebp
// 0048f27f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0048f282  896908               mov dword ptr [ecx + 8], ebp
// 0048f285  eb22                 jmp 0x48f2a9
// 0048f287  807c246800           cmp byte ptr [esp + 0x68], 0
// 0048f28c  740d                 je 0x48f29b
// 0048f28e  892e                 mov dword ptr [esi], ebp
// 0048f290  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f293  3b30                 cmp esi, dword ptr [eax]
// 0048f295  7512                 jne 0x48f2a9
// 0048f297  8928                 mov dword ptr [eax], ebp
// 0048f299  eb0e                 jmp 0x48f2a9
// 0048f29b  896e08               mov dword ptr [esi + 8], ebp
// 0048f29e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048f2a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0048f2a4  7503                 jne 0x48f2a9
// 0048f2a6  896808               mov dword ptr [eax + 8], ebp
// 0048f2a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0048f2ac  807a2000             cmp byte ptr [edx + 0x20], 0
// 0048f2b0  8d4504               lea eax, [ebp + 4]
// 0048f2b3  8bf5                 mov esi, ebp
// 0048f2b5  0f85ea000000         jne 0x48f3a5
// 0048f2bb  eb03                 jmp 0x48f2c0
// 0048f2bd  8d4900               lea ecx, [ecx]
// 0048f2c0  8b08                 mov ecx, dword ptr [eax]
// 0048f2c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f2c5  3b0a                 cmp ecx, dword ptr [edx]
// 0048f2c7  7551                 jne 0x48f31a
// 0048f2c9  8b5208               mov edx, dword ptr [edx + 8]
// 0048f2cc  807a2000             cmp byte ptr [edx + 0x20], 0
// 0048f2d0  7519                 jne 0x48f2eb
// 0048f2d2  885920               mov byte ptr [ecx + 0x20], bl
// 0048f2d5  885a20               mov byte ptr [edx + 0x20], bl
// 0048f2d8  8b10                 mov edx, dword ptr [eax]
// 0048f2da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048f2dd  c6412000             mov byte ptr [ecx + 0x20], 0
// 0048f2e1  8b10                 mov edx, dword ptr [eax]
// 0048f2e3  8b7204               mov esi, dword ptr [edx + 4]
// 0048f2e6  e9aa000000           jmp 0x48f395
// 0048f2eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0048f2ee  750a                 jne 0x48f2fa
// 0048f2f0  8bf1                 mov esi, ecx
// 0048f2f2  56                   push esi
// 0048f2f3  8bcf                 mov ecx, edi
// 0048f2f5  e866e01300           call 0x5cd360
// 0048f2fa  8b4604               mov eax, dword ptr [esi + 4]
// 0048f2fd  885820               mov byte ptr [eax + 0x20], bl
// 0048f300  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048f303  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f306  c6422000             mov byte ptr [edx + 0x20], 0
// 0048f30a  8b4604               mov eax, dword ptr [esi + 4]
// 0048f30d  8b4804               mov ecx, dword ptr [eax + 4]
// 0048f310  51                   push ecx
// 0048f311  8bcf                 mov ecx, edi
// 0048f313  e868d21300           call 0x5cc580
// 0048f318  eb7b                 jmp 0x48f395
// 0048f31a  8b12                 mov edx, dword ptr [edx]
// 0048f31c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0048f320  7516                 jne 0x48f338
// 0048f322  885920               mov byte ptr [ecx + 0x20], bl
// 0048f325  885a20               mov byte ptr [edx + 0x20], bl
// 0048f328  8b10                 mov edx, dword ptr [eax]
// 0048f32a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048f32d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0048f331  8b10                 mov edx, dword ptr [eax]
// 0048f333  8b7204               mov esi, dword ptr [edx + 4]
// 0048f336  eb5d                 jmp 0x48f395
// 0048f338  3b31                 cmp esi, dword ptr [ecx]
// 0048f33a  750a                 jne 0x48f346
// 0048f33c  8bf1                 mov esi, ecx
// 0048f33e  56                   push esi
// 0048f33f  8bcf                 mov ecx, edi
// 0048f341  e83ad21300           call 0x5cc580
// 0048f346  8b4604               mov eax, dword ptr [esi + 4]
// 0048f349  885820               mov byte ptr [eax + 0x20], bl
// 0048f34c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048f34f  8b5104               mov edx, dword ptr [ecx + 4]
// 0048f352  c6422000             mov byte ptr [edx + 0x20], 0
// 0048f356  8b4604               mov eax, dword ptr [esi + 4]
// 0048f359  8b4004               mov eax, dword ptr [eax + 4]
// 0048f35c  8b4808               mov ecx, dword ptr [eax + 8]
// 0048f35f  8b11                 mov edx, dword ptr [ecx]
// 0048f361  895008               mov dword ptr [eax + 8], edx
// 0048f364  8b11                 mov edx, dword ptr [ecx]
// 0048f366  807a2100             cmp byte ptr [edx + 0x21], 0
// 0048f36a  7503                 jne 0x48f36f
// 0048f36c  894204               mov dword ptr [edx + 4], eax
// 0048f36f  8b5004               mov edx, dword ptr [eax + 4]
// 0048f372  895104               mov dword ptr [ecx + 4], edx
// 0048f375  8b5718               mov edx, dword ptr [edi + 0x18]
// 0048f378  3b4204               cmp eax, dword ptr [edx + 4]
// 0048f37b  7505                 jne 0x48f382
// 0048f37d  894a04               mov dword ptr [edx + 4], ecx
// 0048f380  eb0e                 jmp 0x48f390
// 0048f382  8b5004               mov edx, dword ptr [eax + 4]
// 0048f385  3b02                 cmp eax, dword ptr [edx]
// 0048f387  7504                 jne 0x48f38d
// 0048f389  890a                 mov dword ptr [edx], ecx
// 0048f38b  eb03                 jmp 0x48f390
// 0048f38d  894a08               mov dword ptr [edx + 8], ecx
// 0048f390  8901                 mov dword ptr [ecx], eax
// 0048f392  894804               mov dword ptr [eax + 4], ecx
// 0048f395  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048f398  80792000             cmp byte ptr [ecx + 0x20], 0
// 0048f39c  8d4604               lea eax, [esi + 4]
// 0048f39f  0f841bffffff         je 0x48f2c0
// 0048f3a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0048f3a8  8b4204               mov eax, dword ptr [edx + 4]
// 0048f3ab  885820               mov byte ptr [eax + 0x20], bl
// 0048f3ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0048f3b2  8b0f                 mov ecx, dword ptr [edi]
// 0048f3b4  5e                   pop esi
// 0048f3b5  896804               mov dword ptr [eax + 4], ebp
// 0048f3b8  5d                   pop ebp
// 0048f3b9  8908                 mov dword ptr [eax], ecx
// 0048f3bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0048f3bf  5b                   pop ebx
// 0048f3c0  5f                   pop edi
// 0048f3c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0048f3c8  83c450               add esp, 0x50
// 0048f3cb  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
