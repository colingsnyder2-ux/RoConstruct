// from server: 100% by auto
// roc 2009-06 004fc150  unit: RBX::Network::ServerReplicator  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004fc150
//
// 004fc150  64a100000000         mov eax, dword ptr fs:[0]
// 004fc156  6aff                 push -1
// 004fc158  68b2db8500           push 0x85dbb2
// 004fc15d  50                   push eax
// 004fc15e  64892500000000       mov dword ptr fs:[0], esp
// 004fc165  83ec44               sub esp, 0x44
// 004fc168  57                   push edi
// 004fc169  8bf9                 mov edi, ecx
// 004fc16b  817f1c5c74d105       cmp dword ptr [edi + 0x1c], 0x5d1745c
// 004fc172  7259                 jb 0x4fc1cd
// 004fc174  68c0c98a00           push 0x8ac9c0
// 004fc179  8d4c2408             lea ecx, [esp + 8]
// 004fc17d  ff15b4e48900         call dword ptr [0x89e4b4]
// 004fc183  8d4c2420             lea ecx, [esp + 0x20]
// 004fc187  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004fc18f  ff15b8e98900         call dword ptr [0x89e9b8]
// 004fc195  8d442404             lea eax, [esp + 4]
// 004fc199  50                   push eax
// 004fc19a  8d4c2430             lea ecx, [esp + 0x30]
// 004fc19e  c644245401           mov byte ptr [esp + 0x54], 1
// 004fc1a3  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004fc1ab  ff15b8e48900         call dword ptr [0x89e4b8]
// 004fc1b1  6834929700           push 0x979234
// 004fc1b6  8d4c2424             lea ecx, [esp + 0x24]
// 004fc1ba  51                   push ecx
// 004fc1bb  c644245800           mov byte ptr [esp + 0x58], 0
// 004fc1c0  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004fc1c8  e87dd82100           call 0x719a4a
// 004fc1cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 004fc1d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 004fc1d4  53                   push ebx
// 004fc1d5  55                   push ebp
// 004fc1d6  56                   push esi
// 004fc1d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004fc1db  6a00                 push 0
// 004fc1dd  52                   push edx
// 004fc1de  50                   push eax
// 004fc1df  56                   push esi
// 004fc1e0  50                   push eax
// 004fc1e1  e8baf9ffff           call 0x4fbba0
// 004fc1e6  8be8                 mov ebp, eax
// 004fc1e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 004fc1eb  bb01000000           mov ebx, 1
// 004fc1f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004fc1f3  3bf0                 cmp esi, eax
// 004fc1f5  7510                 jne 0x4fc207
// 004fc1f7  896804               mov dword ptr [eax + 4], ebp
// 004fc1fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004fc1fd  8928                 mov dword ptr [eax], ebp
// 004fc1ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004fc202  896908               mov dword ptr [ecx + 8], ebp
// 004fc205  eb22                 jmp 0x4fc229
// 004fc207  807c246800           cmp byte ptr [esp + 0x68], 0
// 004fc20c  740d                 je 0x4fc21b
// 004fc20e  892e                 mov dword ptr [esi], ebp
// 004fc210  8b4718               mov eax, dword ptr [edi + 0x18]
// 004fc213  3b30                 cmp esi, dword ptr [eax]
// 004fc215  7512                 jne 0x4fc229
// 004fc217  8928                 mov dword ptr [eax], ebp
// 004fc219  eb0e                 jmp 0x4fc229
// 004fc21b  896e08               mov dword ptr [esi + 8], ebp
// 004fc21e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004fc221  3b7008               cmp esi, dword ptr [eax + 8]
// 004fc224  7503                 jne 0x4fc229
// 004fc226  896808               mov dword ptr [eax + 8], ebp
// 004fc229  8b5504               mov edx, dword ptr [ebp + 4]
// 004fc22c  807a3800             cmp byte ptr [edx + 0x38], 0
// 004fc230  8d4504               lea eax, [ebp + 4]
// 004fc233  8bf5                 mov esi, ebp
// 004fc235  0f85ea000000         jne 0x4fc325
// 004fc23b  eb03                 jmp 0x4fc240
// 004fc23d  8d4900               lea ecx, [ecx]
// 004fc240  8b08                 mov ecx, dword ptr [eax]
// 004fc242  8b5104               mov edx, dword ptr [ecx + 4]
// 004fc245  3b0a                 cmp ecx, dword ptr [edx]
// 004fc247  7551                 jne 0x4fc29a
// 004fc249  8b5208               mov edx, dword ptr [edx + 8]
// 004fc24c  807a3800             cmp byte ptr [edx + 0x38], 0
// 004fc250  7519                 jne 0x4fc26b
// 004fc252  885938               mov byte ptr [ecx + 0x38], bl
// 004fc255  885a38               mov byte ptr [edx + 0x38], bl
// 004fc258  8b10                 mov edx, dword ptr [eax]
// 004fc25a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004fc25d  c6413800             mov byte ptr [ecx + 0x38], 0
// 004fc261  8b10                 mov edx, dword ptr [eax]
// 004fc263  8b7204               mov esi, dword ptr [edx + 4]
// 004fc266  e9aa000000           jmp 0x4fc315
// 004fc26b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004fc26e  750a                 jne 0x4fc27a
// 004fc270  8bf1                 mov esi, ecx
// 004fc272  56                   push esi
// 004fc273  8bcf                 mov ecx, edi
// 004fc275  e886f7ffff           call 0x4fba00
// 004fc27a  8b4604               mov eax, dword ptr [esi + 4]
// 004fc27d  885838               mov byte ptr [eax + 0x38], bl
// 004fc280  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fc283  8b5104               mov edx, dword ptr [ecx + 4]
// 004fc286  c6423800             mov byte ptr [edx + 0x38], 0
// 004fc28a  8b4604               mov eax, dword ptr [esi + 4]
// 004fc28d  8b4804               mov ecx, dword ptr [eax + 4]
// 004fc290  51                   push ecx
// 004fc291  8bcf                 mov ecx, edi
// 004fc293  e8b8f7ffff           call 0x4fba50
// 004fc298  eb7b                 jmp 0x4fc315
// 004fc29a  8b12                 mov edx, dword ptr [edx]
// 004fc29c  807a3800             cmp byte ptr [edx + 0x38], 0
// 004fc2a0  7516                 jne 0x4fc2b8
// 004fc2a2  885938               mov byte ptr [ecx + 0x38], bl
// 004fc2a5  885a38               mov byte ptr [edx + 0x38], bl
// 004fc2a8  8b10                 mov edx, dword ptr [eax]
// 004fc2aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004fc2ad  c6413800             mov byte ptr [ecx + 0x38], 0
// 004fc2b1  8b10                 mov edx, dword ptr [eax]
// 004fc2b3  8b7204               mov esi, dword ptr [edx + 4]
// 004fc2b6  eb5d                 jmp 0x4fc315
// 004fc2b8  3b31                 cmp esi, dword ptr [ecx]
// 004fc2ba  750a                 jne 0x4fc2c6
// 004fc2bc  8bf1                 mov esi, ecx
// 004fc2be  56                   push esi
// 004fc2bf  8bcf                 mov ecx, edi
// 004fc2c1  e88af7ffff           call 0x4fba50
// 004fc2c6  8b4604               mov eax, dword ptr [esi + 4]
// 004fc2c9  885838               mov byte ptr [eax + 0x38], bl
// 004fc2cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fc2cf  8b5104               mov edx, dword ptr [ecx + 4]
// 004fc2d2  c6423800             mov byte ptr [edx + 0x38], 0
// 004fc2d6  8b4604               mov eax, dword ptr [esi + 4]
// 004fc2d9  8b4004               mov eax, dword ptr [eax + 4]
// 004fc2dc  8b4808               mov ecx, dword ptr [eax + 8]
// 004fc2df  8b11                 mov edx, dword ptr [ecx]
// 004fc2e1  895008               mov dword ptr [eax + 8], edx
// 004fc2e4  8b11                 mov edx, dword ptr [ecx]
// 004fc2e6  807a3900             cmp byte ptr [edx + 0x39], 0
// 004fc2ea  7503                 jne 0x4fc2ef
// 004fc2ec  894204               mov dword ptr [edx + 4], eax
// 004fc2ef  8b5004               mov edx, dword ptr [eax + 4]
// 004fc2f2  895104               mov dword ptr [ecx + 4], edx
// 004fc2f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004fc2f8  3b4204               cmp eax, dword ptr [edx + 4]
// 004fc2fb  7505                 jne 0x4fc302
// 004fc2fd  894a04               mov dword ptr [edx + 4], ecx
// 004fc300  eb0e                 jmp 0x4fc310
// 004fc302  8b5004               mov edx, dword ptr [eax + 4]
// 004fc305  3b02                 cmp eax, dword ptr [edx]
// 004fc307  7504                 jne 0x4fc30d
// 004fc309  890a                 mov dword ptr [edx], ecx
// 004fc30b  eb03                 jmp 0x4fc310
// 004fc30d  894a08               mov dword ptr [edx + 8], ecx
// 004fc310  8901                 mov dword ptr [ecx], eax
// 004fc312  894804               mov dword ptr [eax + 4], ecx
// 004fc315  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fc318  80793800             cmp byte ptr [ecx + 0x38], 0
// 004fc31c  8d4604               lea eax, [esi + 4]
// 004fc31f  0f841bffffff         je 0x4fc240
// 004fc325  8b5718               mov edx, dword ptr [edi + 0x18]
// 004fc328  8b4204               mov eax, dword ptr [edx + 4]
// 004fc32b  885838               mov byte ptr [eax + 0x38], bl
// 004fc32e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004fc332  8b0f                 mov ecx, dword ptr [edi]
// 004fc334  5e                   pop esi
// 004fc335  896804               mov dword ptr [eax + 4], ebp
// 004fc338  5d                   pop ebp
// 004fc339  8908                 mov dword ptr [eax], ecx
// 004fc33b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004fc33f  5b                   pop ebx
// 004fc340  5f                   pop edi
// 004fc341  64890d00000000       mov dword ptr fs:[0], ecx
// 004fc348  83c450               add esp, 0x50
// 004fc34b  c21000               ret 0x10
// standard library map_int<pod40> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
