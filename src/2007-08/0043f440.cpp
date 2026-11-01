// from server: 100% by auto
// roc 2007-08 0043f440  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043f440
//
// 0043f440  6aff                 push -1
// 0043f442  68293a7400           push 0x743a29
// 0043f447  64a100000000         mov eax, dword ptr fs:[0]
// 0043f44d  50                   push eax
// 0043f44e  83ec44               sub esp, 0x44
// 0043f451  53                   push ebx
// 0043f452  55                   push ebp
// 0043f453  56                   push esi
// 0043f454  57                   push edi
// 0043f455  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043f45a  33c4                 xor eax, esp
// 0043f45c  50                   push eax
// 0043f45d  8d442458             lea eax, [esp + 0x58]
// 0043f461  64a300000000         mov dword ptr fs:[0], eax
// 0043f467  8bf9                 mov edi, ecx
// 0043f469  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 0043f470  723c                 jb 0x43f4ae
// 0043f472  68904f7800           push 0x784f90
// 0043f477  8d4c2418             lea ecx, [esp + 0x18]
// 0043f47b  ff1598e67700         call dword ptr [0x77e698]
// 0043f481  8d442414             lea eax, [esp + 0x14]
// 0043f485  50                   push eax
// 0043f486  8d4c2434             lea ecx, [esp + 0x34]
// 0043f48a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0043f492  e82930fcff           call 0x4024c0
// 0043f497  6878f78300           push 0x83f778
// 0043f49c  8d4c2434             lea ecx, [esp + 0x34]
// 0043f4a0  51                   push ecx
// 0043f4a1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 0043f4a9  e8f0161f00           call 0x630b9e
// 0043f4ae  8b542474             mov edx, dword ptr [esp + 0x74]
// 0043f4b2  8b4704               mov eax, dword ptr [edi + 4]
// 0043f4b5  8b742470             mov esi, dword ptr [esp + 0x70]
// 0043f4b9  6a00                 push 0
// 0043f4bb  52                   push edx
// 0043f4bc  50                   push eax
// 0043f4bd  56                   push esi
// 0043f4be  50                   push eax
// 0043f4bf  e89ce7ffff           call 0x43dc60
// 0043f4c4  8be8                 mov ebp, eax
// 0043f4c6  8b4704               mov eax, dword ptr [edi + 4]
// 0043f4c9  bb01000000           mov ebx, 1
// 0043f4ce  015f08               add dword ptr [edi + 8], ebx
// 0043f4d1  3bf0                 cmp esi, eax
// 0043f4d3  7510                 jne 0x43f4e5
// 0043f4d5  896804               mov dword ptr [eax + 4], ebp
// 0043f4d8  8b4704               mov eax, dword ptr [edi + 4]
// 0043f4db  8928                 mov dword ptr [eax], ebp
// 0043f4dd  8b4f04               mov ecx, dword ptr [edi + 4]
// 0043f4e0  896908               mov dword ptr [ecx + 8], ebp
// 0043f4e3  eb22                 jmp 0x43f507
// 0043f4e5  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 0043f4ea  740d                 je 0x43f4f9
// 0043f4ec  892e                 mov dword ptr [esi], ebp
// 0043f4ee  8b4704               mov eax, dword ptr [edi + 4]
// 0043f4f1  3b30                 cmp esi, dword ptr [eax]
// 0043f4f3  7512                 jne 0x43f507
// 0043f4f5  8928                 mov dword ptr [eax], ebp
// 0043f4f7  eb0e                 jmp 0x43f507
// 0043f4f9  896e08               mov dword ptr [esi + 8], ebp
// 0043f4fc  8b4704               mov eax, dword ptr [edi + 4]
// 0043f4ff  3b7008               cmp esi, dword ptr [eax + 8]
// 0043f502  7503                 jne 0x43f507
// 0043f504  896808               mov dword ptr [eax + 8], ebp
// 0043f507  8b5504               mov edx, dword ptr [ebp + 4]
// 0043f50a  807a2000             cmp byte ptr [edx + 0x20], 0
// 0043f50e  8d4504               lea eax, [ebp + 4]
// 0043f511  8bf5                 mov esi, ebp
// 0043f513  0f85ec000000         jne 0x43f605
// 0043f519  8da42400000000       lea esp, [esp]
// 0043f520  8b08                 mov ecx, dword ptr [eax]
// 0043f522  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f525  3b0a                 cmp ecx, dword ptr [edx]
// 0043f527  7551                 jne 0x43f57a
// 0043f529  8b5208               mov edx, dword ptr [edx + 8]
// 0043f52c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0043f530  7519                 jne 0x43f54b
// 0043f532  885920               mov byte ptr [ecx + 0x20], bl
// 0043f535  885a20               mov byte ptr [edx + 0x20], bl
// 0043f538  8b10                 mov edx, dword ptr [eax]
// 0043f53a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043f53d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0043f541  8b10                 mov edx, dword ptr [eax]
// 0043f543  8b7204               mov esi, dword ptr [edx + 4]
// 0043f546  e9aa000000           jmp 0x43f5f5
// 0043f54b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0043f54e  750a                 jne 0x43f55a
// 0043f550  8bf1                 mov esi, ecx
// 0043f552  56                   push esi
// 0043f553  8bcf                 mov ecx, edi
// 0043f555  e8b6e10800           call 0x4cd710
// 0043f55a  8b4604               mov eax, dword ptr [esi + 4]
// 0043f55d  885820               mov byte ptr [eax + 0x20], bl
// 0043f560  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f563  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f566  c6422000             mov byte ptr [edx + 0x20], 0
// 0043f56a  8b4604               mov eax, dword ptr [esi + 4]
// 0043f56d  8b4804               mov ecx, dword ptr [eax + 4]
// 0043f570  51                   push ecx
// 0043f571  8bcf                 mov ecx, edi
// 0043f573  e8780d0900           call 0x4d02f0
// 0043f578  eb7b                 jmp 0x43f5f5
// 0043f57a  8b12                 mov edx, dword ptr [edx]
// 0043f57c  807a2000             cmp byte ptr [edx + 0x20], 0
// 0043f580  7516                 jne 0x43f598
// 0043f582  885920               mov byte ptr [ecx + 0x20], bl
// 0043f585  885a20               mov byte ptr [edx + 0x20], bl
// 0043f588  8b10                 mov edx, dword ptr [eax]
// 0043f58a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0043f58d  c6412000             mov byte ptr [ecx + 0x20], 0
// 0043f591  8b10                 mov edx, dword ptr [eax]
// 0043f593  8b7204               mov esi, dword ptr [edx + 4]
// 0043f596  eb5d                 jmp 0x43f5f5
// 0043f598  3b31                 cmp esi, dword ptr [ecx]
// 0043f59a  750a                 jne 0x43f5a6
// 0043f59c  8bf1                 mov esi, ecx
// 0043f59e  56                   push esi
// 0043f59f  8bcf                 mov ecx, edi
// 0043f5a1  e84a0d0900           call 0x4d02f0
// 0043f5a6  8b4604               mov eax, dword ptr [esi + 4]
// 0043f5a9  885820               mov byte ptr [eax + 0x20], bl
// 0043f5ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f5af  8b5104               mov edx, dword ptr [ecx + 4]
// 0043f5b2  c6422000             mov byte ptr [edx + 0x20], 0
// 0043f5b6  8b4604               mov eax, dword ptr [esi + 4]
// 0043f5b9  8b4004               mov eax, dword ptr [eax + 4]
// 0043f5bc  8b4808               mov ecx, dword ptr [eax + 8]
// 0043f5bf  8b11                 mov edx, dword ptr [ecx]
// 0043f5c1  895008               mov dword ptr [eax + 8], edx
// 0043f5c4  8b11                 mov edx, dword ptr [ecx]
// 0043f5c6  807a2100             cmp byte ptr [edx + 0x21], 0
// 0043f5ca  7503                 jne 0x43f5cf
// 0043f5cc  894204               mov dword ptr [edx + 4], eax
// 0043f5cf  8b5004               mov edx, dword ptr [eax + 4]
// 0043f5d2  895104               mov dword ptr [ecx + 4], edx
// 0043f5d5  8b5704               mov edx, dword ptr [edi + 4]
// 0043f5d8  3b4204               cmp eax, dword ptr [edx + 4]
// 0043f5db  7505                 jne 0x43f5e2
// 0043f5dd  894a04               mov dword ptr [edx + 4], ecx
// 0043f5e0  eb0e                 jmp 0x43f5f0
// 0043f5e2  8b5004               mov edx, dword ptr [eax + 4]
// 0043f5e5  3b02                 cmp eax, dword ptr [edx]
// 0043f5e7  7504                 jne 0x43f5ed
// 0043f5e9  890a                 mov dword ptr [edx], ecx
// 0043f5eb  eb03                 jmp 0x43f5f0
// 0043f5ed  894a08               mov dword ptr [edx + 8], ecx
// 0043f5f0  8901                 mov dword ptr [ecx], eax
// 0043f5f2  894804               mov dword ptr [eax + 4], ecx
// 0043f5f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f5f8  80792000             cmp byte ptr [ecx + 0x20], 0
// 0043f5fc  8d4604               lea eax, [esi + 4]
// 0043f5ff  0f841bffffff         je 0x43f520
// 0043f605  8b5704               mov edx, dword ptr [edi + 4]
// 0043f608  8b4204               mov eax, dword ptr [edx + 4]
// 0043f60b  885820               mov byte ptr [eax + 0x20], bl
// 0043f60e  8b442468             mov eax, dword ptr [esp + 0x68]
// 0043f612  896804               mov dword ptr [eax + 4], ebp
// 0043f615  8938                 mov dword ptr [eax], edi
// 0043f617  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0043f61b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f622  59                   pop ecx
// 0043f623  5f                   pop edi
// 0043f624  5e                   pop esi
// 0043f625  5d                   pop ebp
// 0043f626  5b                   pop ebx
// 0043f627  83c450               add esp, 0x50
// 0043f62a  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
