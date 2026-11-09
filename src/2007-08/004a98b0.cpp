// from server: 100% by auto
// roc 2007-08 004a98b0  unit: RBX::VInstance::?$NonFactoryProduct  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a98b0
//
// 004a98b0  6aff                 push -1
// 004a98b2  68293a7400           push 0x743a29
// 004a98b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a98bd  50                   push eax
// 004a98be  83ec44               sub esp, 0x44
// 004a98c1  53                   push ebx
// 004a98c2  55                   push ebp
// 004a98c3  56                   push esi
// 004a98c4  57                   push edi
// 004a98c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a98ca  33c4                 xor eax, esp
// 004a98cc  50                   push eax
// 004a98cd  8d442458             lea eax, [esp + 0x58]
// 004a98d1  64a300000000         mov dword ptr fs:[0], eax
// 004a98d7  8bf9                 mov edi, ecx
// 004a98d9  817f0854555515       cmp dword ptr [edi + 8], 0x15555554
// 004a98e0  723c                 jb 0x4a991e
// 004a98e2  68904f7800           push 0x784f90
// 004a98e7  8d4c2418             lea ecx, [esp + 0x18]
// 004a98eb  ff1598e67700         call dword ptr [0x77e698]
// 004a98f1  8d442414             lea eax, [esp + 0x14]
// 004a98f5  50                   push eax
// 004a98f6  8d4c2434             lea ecx, [esp + 0x34]
// 004a98fa  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a9902  e8b98bf5ff           call 0x4024c0
// 004a9907  6878f78300           push 0x83f778
// 004a990c  8d4c2434             lea ecx, [esp + 0x34]
// 004a9910  51                   push ecx
// 004a9911  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a9919  e880721800           call 0x630b9e
// 004a991e  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a9922  8b4704               mov eax, dword ptr [edi + 4]
// 004a9925  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a9929  6a00                 push 0
// 004a992b  52                   push edx
// 004a992c  50                   push eax
// 004a992d  56                   push esi
// 004a992e  50                   push eax
// 004a992f  e8fcf1ffff           call 0x4a8b30
// 004a9934  8be8                 mov ebp, eax
// 004a9936  8b4704               mov eax, dword ptr [edi + 4]
// 004a9939  bb01000000           mov ebx, 1
// 004a993e  015f08               add dword ptr [edi + 8], ebx
// 004a9941  3bf0                 cmp esi, eax
// 004a9943  7510                 jne 0x4a9955
// 004a9945  896804               mov dword ptr [eax + 4], ebp
// 004a9948  8b4704               mov eax, dword ptr [edi + 4]
// 004a994b  8928                 mov dword ptr [eax], ebp
// 004a994d  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a9950  896908               mov dword ptr [ecx + 8], ebp
// 004a9953  eb22                 jmp 0x4a9977
// 004a9955  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a995a  740d                 je 0x4a9969
// 004a995c  892e                 mov dword ptr [esi], ebp
// 004a995e  8b4704               mov eax, dword ptr [edi + 4]
// 004a9961  3b30                 cmp esi, dword ptr [eax]
// 004a9963  7512                 jne 0x4a9977
// 004a9965  8928                 mov dword ptr [eax], ebp
// 004a9967  eb0e                 jmp 0x4a9977
// 004a9969  896e08               mov dword ptr [esi + 8], ebp
// 004a996c  8b4704               mov eax, dword ptr [edi + 4]
// 004a996f  3b7008               cmp esi, dword ptr [eax + 8]
// 004a9972  7503                 jne 0x4a9977
// 004a9974  896808               mov dword ptr [eax + 8], ebp
// 004a9977  8b5504               mov edx, dword ptr [ebp + 4]
// 004a997a  807a1800             cmp byte ptr [edx + 0x18], 0
// 004a997e  8d4504               lea eax, [ebp + 4]
// 004a9981  8bf5                 mov esi, ebp
// 004a9983  0f85ec000000         jne 0x4a9a75
// 004a9989  8da42400000000       lea esp, [esp]
// 004a9990  8b08                 mov ecx, dword ptr [eax]
// 004a9992  8b5104               mov edx, dword ptr [ecx + 4]
// 004a9995  3b0a                 cmp ecx, dword ptr [edx]
// 004a9997  7551                 jne 0x4a99ea
// 004a9999  8b5208               mov edx, dword ptr [edx + 8]
// 004a999c  807a1800             cmp byte ptr [edx + 0x18], 0
// 004a99a0  7519                 jne 0x4a99bb
// 004a99a2  885918               mov byte ptr [ecx + 0x18], bl
// 004a99a5  885a18               mov byte ptr [edx + 0x18], bl
// 004a99a8  8b10                 mov edx, dword ptr [eax]
// 004a99aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a99ad  c6411800             mov byte ptr [ecx + 0x18], 0
// 004a99b1  8b10                 mov edx, dword ptr [eax]
// 004a99b3  8b7204               mov esi, dword ptr [edx + 4]
// 004a99b6  e9aa000000           jmp 0x4a9a65
// 004a99bb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a99be  750a                 jne 0x4a99ca
// 004a99c0  8bf1                 mov esi, ecx
// 004a99c2  56                   push esi
// 004a99c3  8bcf                 mov ecx, edi
// 004a99c5  e8f64a1300           call 0x5de4c0
// 004a99ca  8b4604               mov eax, dword ptr [esi + 4]
// 004a99cd  885818               mov byte ptr [eax + 0x18], bl
// 004a99d0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a99d3  8b5104               mov edx, dword ptr [ecx + 4]
// 004a99d6  c6421800             mov byte ptr [edx + 0x18], 0
// 004a99da  8b4604               mov eax, dword ptr [esi + 4]
// 004a99dd  8b4804               mov ecx, dword ptr [eax + 4]
// 004a99e0  51                   push ecx
// 004a99e1  8bcf                 mov ecx, edi
// 004a99e3  e8a85af6ff           call 0x40f490
// 004a99e8  eb7b                 jmp 0x4a9a65
// 004a99ea  8b12                 mov edx, dword ptr [edx]
// 004a99ec  807a1800             cmp byte ptr [edx + 0x18], 0
// 004a99f0  7516                 jne 0x4a9a08
// 004a99f2  885918               mov byte ptr [ecx + 0x18], bl
// 004a99f5  885a18               mov byte ptr [edx + 0x18], bl
// 004a99f8  8b10                 mov edx, dword ptr [eax]
// 004a99fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a99fd  c6411800             mov byte ptr [ecx + 0x18], 0
// 004a9a01  8b10                 mov edx, dword ptr [eax]
// 004a9a03  8b7204               mov esi, dword ptr [edx + 4]
// 004a9a06  eb5d                 jmp 0x4a9a65
// 004a9a08  3b31                 cmp esi, dword ptr [ecx]
// 004a9a0a  750a                 jne 0x4a9a16
// 004a9a0c  8bf1                 mov esi, ecx
// 004a9a0e  56                   push esi
// 004a9a0f  8bcf                 mov ecx, edi
// 004a9a11  e87a5af6ff           call 0x40f490
// 004a9a16  8b4604               mov eax, dword ptr [esi + 4]
// 004a9a19  885818               mov byte ptr [eax + 0x18], bl
// 004a9a1c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a9a1f  8b5104               mov edx, dword ptr [ecx + 4]
// 004a9a22  c6421800             mov byte ptr [edx + 0x18], 0
// 004a9a26  8b4604               mov eax, dword ptr [esi + 4]
// 004a9a29  8b4004               mov eax, dword ptr [eax + 4]
// 004a9a2c  8b4808               mov ecx, dword ptr [eax + 8]
// 004a9a2f  8b11                 mov edx, dword ptr [ecx]
// 004a9a31  895008               mov dword ptr [eax + 8], edx
// 004a9a34  8b11                 mov edx, dword ptr [ecx]
// 004a9a36  807a1900             cmp byte ptr [edx + 0x19], 0
// 004a9a3a  7503                 jne 0x4a9a3f
// 004a9a3c  894204               mov dword ptr [edx + 4], eax
// 004a9a3f  8b5004               mov edx, dword ptr [eax + 4]
// 004a9a42  895104               mov dword ptr [ecx + 4], edx
// 004a9a45  8b5704               mov edx, dword ptr [edi + 4]
// 004a9a48  3b4204               cmp eax, dword ptr [edx + 4]
// 004a9a4b  7505                 jne 0x4a9a52
// 004a9a4d  894a04               mov dword ptr [edx + 4], ecx
// 004a9a50  eb0e                 jmp 0x4a9a60
// 004a9a52  8b5004               mov edx, dword ptr [eax + 4]
// 004a9a55  3b02                 cmp eax, dword ptr [edx]
// 004a9a57  7504                 jne 0x4a9a5d
// 004a9a59  890a                 mov dword ptr [edx], ecx
// 004a9a5b  eb03                 jmp 0x4a9a60
// 004a9a5d  894a08               mov dword ptr [edx + 8], ecx
// 004a9a60  8901                 mov dword ptr [ecx], eax
// 004a9a62  894804               mov dword ptr [eax + 4], ecx
// 004a9a65  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a9a68  80791800             cmp byte ptr [ecx + 0x18], 0
// 004a9a6c  8d4604               lea eax, [esi + 4]
// 004a9a6f  0f841bffffff         je 0x4a9990
// 004a9a75  8b5704               mov edx, dword ptr [edi + 4]
// 004a9a78  8b4204               mov eax, dword ptr [edx + 4]
// 004a9a7b  885818               mov byte ptr [eax + 0x18], bl
// 004a9a7e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a9a82  896804               mov dword ptr [eax + 4], ebp
// 004a9a85  8938                 mov dword ptr [eax], edi
// 004a9a87  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a9a8b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a9a92  59                   pop ecx
// 004a9a93  5f                   pop edi
// 004a9a94  5e                   pop esi
// 004a9a95  5d                   pop ebp
// 004a9a96  5b                   pop ebx
// 004a9a97  83c450               add esp, 0x50
// 004a9a9a  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
