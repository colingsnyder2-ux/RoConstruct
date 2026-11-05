// from server: 100% by auto
// roc 2008-06 004ae0f0  unit: RBX::Network::VClient::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ae0f0
//
// 004ae0f0  64a100000000         mov eax, dword ptr fs:[0]
// 004ae0f6  6aff                 push -1
// 004ae0f8  6842e87d00           push 0x7de842
// 004ae0fd  50                   push eax
// 004ae0fe  64892500000000       mov dword ptr fs:[0], esp
// 004ae105  83ec44               sub esp, 0x44
// 004ae108  57                   push edi
// 004ae109  8bf9                 mov edi, ecx
// 004ae10b  817f1c54555505       cmp dword ptr [edi + 0x1c], 0x5555554
// 004ae112  7259                 jb 0x4ae16d
// 004ae114  688cb28000           push 0x80b28c
// 004ae119  8d4c2408             lea ecx, [esp + 8]
// 004ae11d  ff1558248000         call dword ptr [0x802458]
// 004ae123  8d4c2420             lea ecx, [esp + 0x20]
// 004ae127  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004ae12f  ff1598288000         call dword ptr [0x802898]
// 004ae135  8d442404             lea eax, [esp + 4]
// 004ae139  50                   push eax
// 004ae13a  8d4c2430             lea ecx, [esp + 0x30]
// 004ae13e  c644245401           mov byte ptr [esp + 0x54], 1
// 004ae143  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004ae14b  ff155c248000         call dword ptr [0x80245c]
// 004ae151  68c00c8d00           push 0x8d0cc0
// 004ae156  8d4c2424             lea ecx, [esp + 0x24]
// 004ae15a  51                   push ecx
// 004ae15b  c644245800           mov byte ptr [esp + 0x58], 0
// 004ae160  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004ae168  e81f341f00           call 0x6a158c
// 004ae16d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004ae171  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae174  53                   push ebx
// 004ae175  55                   push ebp
// 004ae176  56                   push esi
// 004ae177  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004ae17b  6a00                 push 0
// 004ae17d  52                   push edx
// 004ae17e  50                   push eax
// 004ae17f  56                   push esi
// 004ae180  50                   push eax
// 004ae181  e83af6ffff           call 0x4ad7c0
// 004ae186  8be8                 mov ebp, eax
// 004ae188  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae18b  bb01000000           mov ebx, 1
// 004ae190  015f1c               add dword ptr [edi + 0x1c], ebx
// 004ae193  3bf0                 cmp esi, eax
// 004ae195  7510                 jne 0x4ae1a7
// 004ae197  896804               mov dword ptr [eax + 4], ebp
// 004ae19a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae19d  8928                 mov dword ptr [eax], ebp
// 004ae19f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004ae1a2  896908               mov dword ptr [ecx + 8], ebp
// 004ae1a5  eb22                 jmp 0x4ae1c9
// 004ae1a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004ae1ac  740d                 je 0x4ae1bb
// 004ae1ae  892e                 mov dword ptr [esi], ebp
// 004ae1b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae1b3  3b30                 cmp esi, dword ptr [eax]
// 004ae1b5  7512                 jne 0x4ae1c9
// 004ae1b7  8928                 mov dword ptr [eax], ebp
// 004ae1b9  eb0e                 jmp 0x4ae1c9
// 004ae1bb  896e08               mov dword ptr [esi + 8], ebp
// 004ae1be  8b4718               mov eax, dword ptr [edi + 0x18]
// 004ae1c1  3b7008               cmp esi, dword ptr [eax + 8]
// 004ae1c4  7503                 jne 0x4ae1c9
// 004ae1c6  896808               mov dword ptr [eax + 8], ebp
// 004ae1c9  8b5504               mov edx, dword ptr [ebp + 4]
// 004ae1cc  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 004ae1d0  8d4504               lea eax, [ebp + 4]
// 004ae1d3  8bf5                 mov esi, ebp
// 004ae1d5  0f85ea000000         jne 0x4ae2c5
// 004ae1db  eb03                 jmp 0x4ae1e0
// 004ae1dd  8d4900               lea ecx, [ecx]
// 004ae1e0  8b08                 mov ecx, dword ptr [eax]
// 004ae1e2  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae1e5  3b0a                 cmp ecx, dword ptr [edx]
// 004ae1e7  7551                 jne 0x4ae23a
// 004ae1e9  8b5208               mov edx, dword ptr [edx + 8]
// 004ae1ec  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 004ae1f0  7519                 jne 0x4ae20b
// 004ae1f2  88593c               mov byte ptr [ecx + 0x3c], bl
// 004ae1f5  885a3c               mov byte ptr [edx + 0x3c], bl
// 004ae1f8  8b10                 mov edx, dword ptr [eax]
// 004ae1fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae1fd  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 004ae201  8b10                 mov edx, dword ptr [eax]
// 004ae203  8b7204               mov esi, dword ptr [edx + 4]
// 004ae206  e9aa000000           jmp 0x4ae2b5
// 004ae20b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004ae20e  750a                 jne 0x4ae21a
// 004ae210  8bf1                 mov esi, ecx
// 004ae212  56                   push esi
// 004ae213  8bcf                 mov ecx, edi
// 004ae215  e886dbffff           call 0x4abda0
// 004ae21a  8b4604               mov eax, dword ptr [esi + 4]
// 004ae21d  88583c               mov byte ptr [eax + 0x3c], bl
// 004ae220  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae223  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae226  c6423c00             mov byte ptr [edx + 0x3c], 0
// 004ae22a  8b4604               mov eax, dword ptr [esi + 4]
// 004ae22d  8b4804               mov ecx, dword ptr [eax + 4]
// 004ae230  51                   push ecx
// 004ae231  8bcf                 mov ecx, edi
// 004ae233  e8d8cdffff           call 0x4ab010
// 004ae238  eb7b                 jmp 0x4ae2b5
// 004ae23a  8b12                 mov edx, dword ptr [edx]
// 004ae23c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 004ae240  7516                 jne 0x4ae258
// 004ae242  88593c               mov byte ptr [ecx + 0x3c], bl
// 004ae245  885a3c               mov byte ptr [edx + 0x3c], bl
// 004ae248  8b10                 mov edx, dword ptr [eax]
// 004ae24a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004ae24d  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 004ae251  8b10                 mov edx, dword ptr [eax]
// 004ae253  8b7204               mov esi, dword ptr [edx + 4]
// 004ae256  eb5d                 jmp 0x4ae2b5
// 004ae258  3b31                 cmp esi, dword ptr [ecx]
// 004ae25a  750a                 jne 0x4ae266
// 004ae25c  8bf1                 mov esi, ecx
// 004ae25e  56                   push esi
// 004ae25f  8bcf                 mov ecx, edi
// 004ae261  e8aacdffff           call 0x4ab010
// 004ae266  8b4604               mov eax, dword ptr [esi + 4]
// 004ae269  88583c               mov byte ptr [eax + 0x3c], bl
// 004ae26c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae26f  8b5104               mov edx, dword ptr [ecx + 4]
// 004ae272  c6423c00             mov byte ptr [edx + 0x3c], 0
// 004ae276  8b4604               mov eax, dword ptr [esi + 4]
// 004ae279  8b4004               mov eax, dword ptr [eax + 4]
// 004ae27c  8b4808               mov ecx, dword ptr [eax + 8]
// 004ae27f  8b11                 mov edx, dword ptr [ecx]
// 004ae281  895008               mov dword ptr [eax + 8], edx
// 004ae284  8b11                 mov edx, dword ptr [ecx]
// 004ae286  807a3d00             cmp byte ptr [edx + 0x3d], 0
// 004ae28a  7503                 jne 0x4ae28f
// 004ae28c  894204               mov dword ptr [edx + 4], eax
// 004ae28f  8b5004               mov edx, dword ptr [eax + 4]
// 004ae292  895104               mov dword ptr [ecx + 4], edx
// 004ae295  8b5718               mov edx, dword ptr [edi + 0x18]
// 004ae298  3b4204               cmp eax, dword ptr [edx + 4]
// 004ae29b  7505                 jne 0x4ae2a2
// 004ae29d  894a04               mov dword ptr [edx + 4], ecx
// 004ae2a0  eb0e                 jmp 0x4ae2b0
// 004ae2a2  8b5004               mov edx, dword ptr [eax + 4]
// 004ae2a5  3b02                 cmp eax, dword ptr [edx]
// 004ae2a7  7504                 jne 0x4ae2ad
// 004ae2a9  890a                 mov dword ptr [edx], ecx
// 004ae2ab  eb03                 jmp 0x4ae2b0
// 004ae2ad  894a08               mov dword ptr [edx + 8], ecx
// 004ae2b0  8901                 mov dword ptr [ecx], eax
// 004ae2b2  894804               mov dword ptr [eax + 4], ecx
// 004ae2b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ae2b8  80793c00             cmp byte ptr [ecx + 0x3c], 0
// 004ae2bc  8d4604               lea eax, [esi + 4]
// 004ae2bf  0f841bffffff         je 0x4ae1e0
// 004ae2c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004ae2c8  8b4204               mov eax, dword ptr [edx + 4]
// 004ae2cb  88583c               mov byte ptr [eax + 0x3c], bl
// 004ae2ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 004ae2d2  8b0f                 mov ecx, dword ptr [edi]
// 004ae2d4  5e                   pop esi
// 004ae2d5  896804               mov dword ptr [eax + 4], ebp
// 004ae2d8  5d                   pop ebp
// 004ae2d9  8908                 mov dword ptr [eax], ecx
// 004ae2db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004ae2df  5b                   pop ebx
// 004ae2e0  5f                   pop edi
// 004ae2e1  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae2e8  83c450               add esp, 0x50
// 004ae2eb  c21000               ret 0x10
// standard library map_str<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
