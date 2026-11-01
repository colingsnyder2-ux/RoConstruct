// from server: 100% by auto
// roc 2007-08 004212b0  unit: CSelectionTreeCtrl  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004212b0
//
// 004212b0  6aff                 push -1
// 004212b2  68293a7400           push 0x743a29
// 004212b7  64a100000000         mov eax, dword ptr fs:[0]
// 004212bd  50                   push eax
// 004212be  83ec44               sub esp, 0x44
// 004212c1  53                   push ebx
// 004212c2  55                   push ebp
// 004212c3  56                   push esi
// 004212c4  57                   push edi
// 004212c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004212ca  33c4                 xor eax, esp
// 004212cc  50                   push eax
// 004212cd  8d442458             lea eax, [esp + 0x58]
// 004212d1  64a300000000         mov dword ptr fs:[0], eax
// 004212d7  8bf9                 mov edi, ecx
// 004212d9  817f08feffff1f       cmp dword ptr [edi + 8], 0x1ffffffe
// 004212e0  723c                 jb 0x42131e
// 004212e2  68904f7800           push 0x784f90
// 004212e7  8d4c2418             lea ecx, [esp + 0x18]
// 004212eb  ff1598e67700         call dword ptr [0x77e698]
// 004212f1  8d442414             lea eax, [esp + 0x14]
// 004212f5  50                   push eax
// 004212f6  8d4c2434             lea ecx, [esp + 0x34]
// 004212fa  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00421302  e8b911feff           call 0x4024c0
// 00421307  6878f78300           push 0x83f778
// 0042130c  8d4c2434             lea ecx, [esp + 0x34]
// 00421310  51                   push ecx
// 00421311  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 00421319  e880f82000           call 0x630b9e
// 0042131e  8b542474             mov edx, dword ptr [esp + 0x74]
// 00421322  8b4704               mov eax, dword ptr [edi + 4]
// 00421325  8b742470             mov esi, dword ptr [esp + 0x70]
// 00421329  6a00                 push 0
// 0042132b  52                   push edx
// 0042132c  50                   push eax
// 0042132d  56                   push esi
// 0042132e  50                   push eax
// 0042132f  e85cfdffff           call 0x421090
// 00421334  8be8                 mov ebp, eax
// 00421336  8b4704               mov eax, dword ptr [edi + 4]
// 00421339  bb01000000           mov ebx, 1
// 0042133e  015f08               add dword ptr [edi + 8], ebx
// 00421341  3bf0                 cmp esi, eax
// 00421343  7510                 jne 0x421355
// 00421345  896804               mov dword ptr [eax + 4], ebp
// 00421348  8b4704               mov eax, dword ptr [edi + 4]
// 0042134b  8928                 mov dword ptr [eax], ebp
// 0042134d  8b4f04               mov ecx, dword ptr [edi + 4]
// 00421350  896908               mov dword ptr [ecx + 8], ebp
// 00421353  eb22                 jmp 0x421377
// 00421355  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 0042135a  740d                 je 0x421369
// 0042135c  892e                 mov dword ptr [esi], ebp
// 0042135e  8b4704               mov eax, dword ptr [edi + 4]
// 00421361  3b30                 cmp esi, dword ptr [eax]
// 00421363  7512                 jne 0x421377
// 00421365  8928                 mov dword ptr [eax], ebp
// 00421367  eb0e                 jmp 0x421377
// 00421369  896e08               mov dword ptr [esi + 8], ebp
// 0042136c  8b4704               mov eax, dword ptr [edi + 4]
// 0042136f  3b7008               cmp esi, dword ptr [eax + 8]
// 00421372  7503                 jne 0x421377
// 00421374  896808               mov dword ptr [eax + 8], ebp
// 00421377  8b5504               mov edx, dword ptr [ebp + 4]
// 0042137a  807a1400             cmp byte ptr [edx + 0x14], 0
// 0042137e  8d4504               lea eax, [ebp + 4]
// 00421381  8bf5                 mov esi, ebp
// 00421383  0f85ec000000         jne 0x421475
// 00421389  8da42400000000       lea esp, [esp]
// 00421390  8b08                 mov ecx, dword ptr [eax]
// 00421392  8b5104               mov edx, dword ptr [ecx + 4]
// 00421395  3b0a                 cmp ecx, dword ptr [edx]
// 00421397  7551                 jne 0x4213ea
// 00421399  8b5208               mov edx, dword ptr [edx + 8]
// 0042139c  807a1400             cmp byte ptr [edx + 0x14], 0
// 004213a0  7519                 jne 0x4213bb
// 004213a2  885914               mov byte ptr [ecx + 0x14], bl
// 004213a5  885a14               mov byte ptr [edx + 0x14], bl
// 004213a8  8b10                 mov edx, dword ptr [eax]
// 004213aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004213ad  c6411400             mov byte ptr [ecx + 0x14], 0
// 004213b1  8b10                 mov edx, dword ptr [eax]
// 004213b3  8b7204               mov esi, dword ptr [edx + 4]
// 004213b6  e9aa000000           jmp 0x421465
// 004213bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004213be  750a                 jne 0x4213ca
// 004213c0  8bf1                 mov esi, ecx
// 004213c2  56                   push esi
// 004213c3  8bcf                 mov ecx, edi
// 004213c5  e816c11400           call 0x56d4e0
// 004213ca  8b4604               mov eax, dword ptr [esi + 4]
// 004213cd  885814               mov byte ptr [eax + 0x14], bl
// 004213d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004213d3  8b5104               mov edx, dword ptr [ecx + 4]
// 004213d6  c6421400             mov byte ptr [edx + 0x14], 0
// 004213da  8b4604               mov eax, dword ptr [esi + 4]
// 004213dd  8b4804               mov ecx, dword ptr [eax + 4]
// 004213e0  51                   push ecx
// 004213e1  8bcf                 mov ecx, edi
// 004213e3  e838371e00           call 0x604b20
// 004213e8  eb7b                 jmp 0x421465
// 004213ea  8b12                 mov edx, dword ptr [edx]
// 004213ec  807a1400             cmp byte ptr [edx + 0x14], 0
// 004213f0  7516                 jne 0x421408
// 004213f2  885914               mov byte ptr [ecx + 0x14], bl
// 004213f5  885a14               mov byte ptr [edx + 0x14], bl
// 004213f8  8b10                 mov edx, dword ptr [eax]
// 004213fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004213fd  c6411400             mov byte ptr [ecx + 0x14], 0
// 00421401  8b10                 mov edx, dword ptr [eax]
// 00421403  8b7204               mov esi, dword ptr [edx + 4]
// 00421406  eb5d                 jmp 0x421465
// 00421408  3b31                 cmp esi, dword ptr [ecx]
// 0042140a  750a                 jne 0x421416
// 0042140c  8bf1                 mov esi, ecx
// 0042140e  56                   push esi
// 0042140f  8bcf                 mov ecx, edi
// 00421411  e80a371e00           call 0x604b20
// 00421416  8b4604               mov eax, dword ptr [esi + 4]
// 00421419  885814               mov byte ptr [eax + 0x14], bl
// 0042141c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0042141f  8b5104               mov edx, dword ptr [ecx + 4]
// 00421422  c6421400             mov byte ptr [edx + 0x14], 0
// 00421426  8b4604               mov eax, dword ptr [esi + 4]
// 00421429  8b4004               mov eax, dword ptr [eax + 4]
// 0042142c  8b4808               mov ecx, dword ptr [eax + 8]
// 0042142f  8b11                 mov edx, dword ptr [ecx]
// 00421431  895008               mov dword ptr [eax + 8], edx
// 00421434  8b11                 mov edx, dword ptr [ecx]
// 00421436  807a1500             cmp byte ptr [edx + 0x15], 0
// 0042143a  7503                 jne 0x42143f
// 0042143c  894204               mov dword ptr [edx + 4], eax
// 0042143f  8b5004               mov edx, dword ptr [eax + 4]
// 00421442  895104               mov dword ptr [ecx + 4], edx
// 00421445  8b5704               mov edx, dword ptr [edi + 4]
// 00421448  3b4204               cmp eax, dword ptr [edx + 4]
// 0042144b  7505                 jne 0x421452
// 0042144d  894a04               mov dword ptr [edx + 4], ecx
// 00421450  eb0e                 jmp 0x421460
// 00421452  8b5004               mov edx, dword ptr [eax + 4]
// 00421455  3b02                 cmp eax, dword ptr [edx]
// 00421457  7504                 jne 0x42145d
// 00421459  890a                 mov dword ptr [edx], ecx
// 0042145b  eb03                 jmp 0x421460
// 0042145d  894a08               mov dword ptr [edx + 8], ecx
// 00421460  8901                 mov dword ptr [ecx], eax
// 00421462  894804               mov dword ptr [eax + 4], ecx
// 00421465  8b4e04               mov ecx, dword ptr [esi + 4]
// 00421468  80791400             cmp byte ptr [ecx + 0x14], 0
// 0042146c  8d4604               lea eax, [esi + 4]
// 0042146f  0f841bffffff         je 0x421390
// 00421475  8b5704               mov edx, dword ptr [edi + 4]
// 00421478  8b4204               mov eax, dword ptr [edx + 4]
// 0042147b  885814               mov byte ptr [eax + 0x14], bl
// 0042147e  8b442468             mov eax, dword ptr [esp + 0x68]
// 00421482  896804               mov dword ptr [eax + 4], ebp
// 00421485  8938                 mov dword ptr [eax], edi
// 00421487  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0042148b  64890d00000000       mov dword ptr fs:[0], ecx
// 00421492  59                   pop ecx
// 00421493  5f                   pop edi
// 00421494  5e                   pop esi
// 00421495  5d                   pop ebp
// 00421496  5b                   pop ebx
// 00421497  83c450               add esp, 0x50
// 0042149a  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
