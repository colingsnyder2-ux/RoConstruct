// from server: 100% by auto
// roc 2007-08 004333b0  unit: RBX::CMarshalWindow  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004333b0
//
// 004333b0  6aff                 push -1
// 004333b2  68293a7400           push 0x743a29
// 004333b7  64a100000000         mov eax, dword ptr fs:[0]
// 004333bd  50                   push eax
// 004333be  83ec44               sub esp, 0x44
// 004333c1  53                   push ebx
// 004333c2  55                   push ebp
// 004333c3  56                   push esi
// 004333c4  57                   push edi
// 004333c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004333ca  33c4                 xor eax, esp
// 004333cc  50                   push eax
// 004333cd  8d442458             lea eax, [esp + 0x58]
// 004333d1  64a300000000         mov dword ptr fs:[0], eax
// 004333d7  8bf9                 mov edi, ecx
// 004333d9  817f08feffff1f       cmp dword ptr [edi + 8], 0x1ffffffe
// 004333e0  723c                 jb 0x43341e
// 004333e2  68904f7800           push 0x784f90
// 004333e7  8d4c2418             lea ecx, [esp + 0x18]
// 004333eb  ff1598e67700         call dword ptr [0x77e698]
// 004333f1  8d442414             lea eax, [esp + 0x14]
// 004333f5  50                   push eax
// 004333f6  8d4c2434             lea ecx, [esp + 0x34]
// 004333fa  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00433402  e8b9f0fcff           call 0x4024c0
// 00433407  6878f78300           push 0x83f778
// 0043340c  8d4c2434             lea ecx, [esp + 0x34]
// 00433410  51                   push ecx
// 00433411  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 00433419  e880d71f00           call 0x630b9e
// 0043341e  8b542474             mov edx, dword ptr [esp + 0x74]
// 00433422  8b4704               mov eax, dword ptr [edi + 4]
// 00433425  8b742470             mov esi, dword ptr [esp + 0x70]
// 00433429  6a00                 push 0
// 0043342b  52                   push edx
// 0043342c  50                   push eax
// 0043342d  56                   push esi
// 0043342e  50                   push eax
// 0043342f  e8fc761a00           call 0x5dab30
// 00433434  8be8                 mov ebp, eax
// 00433436  8b4704               mov eax, dword ptr [edi + 4]
// 00433439  bb01000000           mov ebx, 1
// 0043343e  015f08               add dword ptr [edi + 8], ebx
// 00433441  3bf0                 cmp esi, eax
// 00433443  7510                 jne 0x433455
// 00433445  896804               mov dword ptr [eax + 4], ebp
// 00433448  8b4704               mov eax, dword ptr [edi + 4]
// 0043344b  8928                 mov dword ptr [eax], ebp
// 0043344d  8b4f04               mov ecx, dword ptr [edi + 4]
// 00433450  896908               mov dword ptr [ecx + 8], ebp
// 00433453  eb22                 jmp 0x433477
// 00433455  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 0043345a  740d                 je 0x433469
// 0043345c  892e                 mov dword ptr [esi], ebp
// 0043345e  8b4704               mov eax, dword ptr [edi + 4]
// 00433461  3b30                 cmp esi, dword ptr [eax]
// 00433463  7512                 jne 0x433477
// 00433465  8928                 mov dword ptr [eax], ebp
// 00433467  eb0e                 jmp 0x433477
// 00433469  896e08               mov dword ptr [esi + 8], ebp
// 0043346c  8b4704               mov eax, dword ptr [edi + 4]
// 0043346f  3b7008               cmp esi, dword ptr [eax + 8]
// 00433472  7503                 jne 0x433477
// 00433474  896808               mov dword ptr [eax + 8], ebp
// 00433477  8b5504               mov edx, dword ptr [ebp + 4]
// 0043347a  807a1400             cmp byte ptr [edx + 0x14], 0
// 0043347e  8d4504               lea eax, [ebp + 4]
// 00433481  8bf5                 mov esi, ebp
// 00433483  0f85ec000000         jne 0x433575
// 00433489  8da42400000000       lea esp, [esp]
// 00433490  8b08                 mov ecx, dword ptr [eax]
// 00433492  8b5104               mov edx, dword ptr [ecx + 4]
// 00433495  3b0a                 cmp ecx, dword ptr [edx]
// 00433497  7551                 jne 0x4334ea
// 00433499  8b5208               mov edx, dword ptr [edx + 8]
// 0043349c  807a1400             cmp byte ptr [edx + 0x14], 0
// 004334a0  7519                 jne 0x4334bb
// 004334a2  885914               mov byte ptr [ecx + 0x14], bl
// 004334a5  885a14               mov byte ptr [edx + 0x14], bl
// 004334a8  8b10                 mov edx, dword ptr [eax]
// 004334aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004334ad  c6411400             mov byte ptr [ecx + 0x14], 0
// 004334b1  8b10                 mov edx, dword ptr [eax]
// 004334b3  8b7204               mov esi, dword ptr [edx + 4]
// 004334b6  e9aa000000           jmp 0x433565
// 004334bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004334be  750a                 jne 0x4334ca
// 004334c0  8bf1                 mov esi, ecx
// 004334c2  56                   push esi
// 004334c3  8bcf                 mov ecx, edi
// 004334c5  e816a01300           call 0x56d4e0
// 004334ca  8b4604               mov eax, dword ptr [esi + 4]
// 004334cd  885814               mov byte ptr [eax + 0x14], bl
// 004334d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004334d3  8b5104               mov edx, dword ptr [ecx + 4]
// 004334d6  c6421400             mov byte ptr [edx + 0x14], 0
// 004334da  8b4604               mov eax, dword ptr [esi + 4]
// 004334dd  8b4804               mov ecx, dword ptr [eax + 4]
// 004334e0  51                   push ecx
// 004334e1  8bcf                 mov ecx, edi
// 004334e3  e838161d00           call 0x604b20
// 004334e8  eb7b                 jmp 0x433565
// 004334ea  8b12                 mov edx, dword ptr [edx]
// 004334ec  807a1400             cmp byte ptr [edx + 0x14], 0
// 004334f0  7516                 jne 0x433508
// 004334f2  885914               mov byte ptr [ecx + 0x14], bl
// 004334f5  885a14               mov byte ptr [edx + 0x14], bl
// 004334f8  8b10                 mov edx, dword ptr [eax]
// 004334fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004334fd  c6411400             mov byte ptr [ecx + 0x14], 0
// 00433501  8b10                 mov edx, dword ptr [eax]
// 00433503  8b7204               mov esi, dword ptr [edx + 4]
// 00433506  eb5d                 jmp 0x433565
// 00433508  3b31                 cmp esi, dword ptr [ecx]
// 0043350a  750a                 jne 0x433516
// 0043350c  8bf1                 mov esi, ecx
// 0043350e  56                   push esi
// 0043350f  8bcf                 mov ecx, edi
// 00433511  e80a161d00           call 0x604b20
// 00433516  8b4604               mov eax, dword ptr [esi + 4]
// 00433519  885814               mov byte ptr [eax + 0x14], bl
// 0043351c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043351f  8b5104               mov edx, dword ptr [ecx + 4]
// 00433522  c6421400             mov byte ptr [edx + 0x14], 0
// 00433526  8b4604               mov eax, dword ptr [esi + 4]
// 00433529  8b4004               mov eax, dword ptr [eax + 4]
// 0043352c  8b4808               mov ecx, dword ptr [eax + 8]
// 0043352f  8b11                 mov edx, dword ptr [ecx]
// 00433531  895008               mov dword ptr [eax + 8], edx
// 00433534  8b11                 mov edx, dword ptr [ecx]
// 00433536  807a1500             cmp byte ptr [edx + 0x15], 0
// 0043353a  7503                 jne 0x43353f
// 0043353c  894204               mov dword ptr [edx + 4], eax
// 0043353f  8b5004               mov edx, dword ptr [eax + 4]
// 00433542  895104               mov dword ptr [ecx + 4], edx
// 00433545  8b5704               mov edx, dword ptr [edi + 4]
// 00433548  3b4204               cmp eax, dword ptr [edx + 4]
// 0043354b  7505                 jne 0x433552
// 0043354d  894a04               mov dword ptr [edx + 4], ecx
// 00433550  eb0e                 jmp 0x433560
// 00433552  8b5004               mov edx, dword ptr [eax + 4]
// 00433555  3b02                 cmp eax, dword ptr [edx]
// 00433557  7504                 jne 0x43355d
// 00433559  890a                 mov dword ptr [edx], ecx
// 0043355b  eb03                 jmp 0x433560
// 0043355d  894a08               mov dword ptr [edx + 8], ecx
// 00433560  8901                 mov dword ptr [ecx], eax
// 00433562  894804               mov dword ptr [eax + 4], ecx
// 00433565  8b4e04               mov ecx, dword ptr [esi + 4]
// 00433568  80791400             cmp byte ptr [ecx + 0x14], 0
// 0043356c  8d4604               lea eax, [esi + 4]
// 0043356f  0f841bffffff         je 0x433490
// 00433575  8b5704               mov edx, dword ptr [edi + 4]
// 00433578  8b4204               mov eax, dword ptr [edx + 4]
// 0043357b  885814               mov byte ptr [eax + 0x14], bl
// 0043357e  8b442468             mov eax, dword ptr [esp + 0x68]
// 00433582  896804               mov dword ptr [eax + 4], ebp
// 00433585  8938                 mov dword ptr [eax], edi
// 00433587  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0043358b  64890d00000000       mov dword ptr fs:[0], ecx
// 00433592  59                   pop ecx
// 00433593  5f                   pop edi
// 00433594  5e                   pop esi
// 00433595  5d                   pop ebp
// 00433596  5b                   pop ebx
// 00433597  83c450               add esp, 0x50
// 0043359a  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
