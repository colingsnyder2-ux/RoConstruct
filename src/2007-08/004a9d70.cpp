// from server: 100% by auto
// roc 2007-08 004a9d70  unit: RBX::VInstance::?$NonFactoryProduct  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a9d70
//
// 004a9d70  6aff                 push -1
// 004a9d72  68293a7400           push 0x743a29
// 004a9d77  64a100000000         mov eax, dword ptr fs:[0]
// 004a9d7d  50                   push eax
// 004a9d7e  83ec44               sub esp, 0x44
// 004a9d81  53                   push ebx
// 004a9d82  55                   push ebp
// 004a9d83  56                   push esi
// 004a9d84  57                   push edi
// 004a9d85  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a9d8a  33c4                 xor eax, esp
// 004a9d8c  50                   push eax
// 004a9d8d  8d442458             lea eax, [esp + 0x58]
// 004a9d91  64a300000000         mov dword ptr fs:[0], eax
// 004a9d97  8bf9                 mov edi, ecx
// 004a9d99  817f08a9aaaa0a       cmp dword ptr [edi + 8], 0xaaaaaa9
// 004a9da0  723c                 jb 0x4a9dde
// 004a9da2  68904f7800           push 0x784f90
// 004a9da7  8d4c2418             lea ecx, [esp + 0x18]
// 004a9dab  ff1598e67700         call dword ptr [0x77e698]
// 004a9db1  8d442414             lea eax, [esp + 0x14]
// 004a9db5  50                   push eax
// 004a9db6  8d4c2434             lea ecx, [esp + 0x34]
// 004a9dba  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a9dc2  e8f986f5ff           call 0x4024c0
// 004a9dc7  6878f78300           push 0x83f778
// 004a9dcc  8d4c2434             lea ecx, [esp + 0x34]
// 004a9dd0  51                   push ecx
// 004a9dd1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a9dd9  e8c06d1800           call 0x630b9e
// 004a9dde  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a9de2  8b4704               mov eax, dword ptr [edi + 4]
// 004a9de5  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a9de9  6a00                 push 0
// 004a9deb  52                   push edx
// 004a9dec  50                   push eax
// 004a9ded  56                   push esi
// 004a9dee  50                   push eax
// 004a9def  e89cedffff           call 0x4a8b90
// 004a9df4  8be8                 mov ebp, eax
// 004a9df6  8b4704               mov eax, dword ptr [edi + 4]
// 004a9df9  bb01000000           mov ebx, 1
// 004a9dfe  015f08               add dword ptr [edi + 8], ebx
// 004a9e01  3bf0                 cmp esi, eax
// 004a9e03  7510                 jne 0x4a9e15
// 004a9e05  896804               mov dword ptr [eax + 4], ebp
// 004a9e08  8b4704               mov eax, dword ptr [edi + 4]
// 004a9e0b  8928                 mov dword ptr [eax], ebp
// 004a9e0d  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a9e10  896908               mov dword ptr [ecx + 8], ebp
// 004a9e13  eb22                 jmp 0x4a9e37
// 004a9e15  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a9e1a  740d                 je 0x4a9e29
// 004a9e1c  892e                 mov dword ptr [esi], ebp
// 004a9e1e  8b4704               mov eax, dword ptr [edi + 4]
// 004a9e21  3b30                 cmp esi, dword ptr [eax]
// 004a9e23  7512                 jne 0x4a9e37
// 004a9e25  8928                 mov dword ptr [eax], ebp
// 004a9e27  eb0e                 jmp 0x4a9e37
// 004a9e29  896e08               mov dword ptr [esi + 8], ebp
// 004a9e2c  8b4704               mov eax, dword ptr [edi + 4]
// 004a9e2f  3b7008               cmp esi, dword ptr [eax + 8]
// 004a9e32  7503                 jne 0x4a9e37
// 004a9e34  896808               mov dword ptr [eax + 8], ebp
// 004a9e37  8b5504               mov edx, dword ptr [ebp + 4]
// 004a9e3a  807a2400             cmp byte ptr [edx + 0x24], 0
// 004a9e3e  8d4504               lea eax, [ebp + 4]
// 004a9e41  8bf5                 mov esi, ebp
// 004a9e43  0f85ec000000         jne 0x4a9f35
// 004a9e49  8da42400000000       lea esp, [esp]
// 004a9e50  8b08                 mov ecx, dword ptr [eax]
// 004a9e52  8b5104               mov edx, dword ptr [ecx + 4]
// 004a9e55  3b0a                 cmp ecx, dword ptr [edx]
// 004a9e57  7551                 jne 0x4a9eaa
// 004a9e59  8b5208               mov edx, dword ptr [edx + 8]
// 004a9e5c  807a2400             cmp byte ptr [edx + 0x24], 0
// 004a9e60  7519                 jne 0x4a9e7b
// 004a9e62  885924               mov byte ptr [ecx + 0x24], bl
// 004a9e65  885a24               mov byte ptr [edx + 0x24], bl
// 004a9e68  8b10                 mov edx, dword ptr [eax]
// 004a9e6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a9e6d  c6412400             mov byte ptr [ecx + 0x24], 0
// 004a9e71  8b10                 mov edx, dword ptr [eax]
// 004a9e73  8b7204               mov esi, dword ptr [edx + 4]
// 004a9e76  e9aa000000           jmp 0x4a9f25
// 004a9e7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a9e7e  750a                 jne 0x4a9e8a
// 004a9e80  8bf1                 mov esi, ecx
// 004a9e82  56                   push esi
// 004a9e83  8bcf                 mov ecx, edi
// 004a9e85  e8a6ccffff           call 0x4a6b30
// 004a9e8a  8b4604               mov eax, dword ptr [esi + 4]
// 004a9e8d  885824               mov byte ptr [eax + 0x24], bl
// 004a9e90  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a9e93  8b5104               mov edx, dword ptr [ecx + 4]
// 004a9e96  c6422400             mov byte ptr [edx + 0x24], 0
// 004a9e9a  8b4604               mov eax, dword ptr [esi + 4]
// 004a9e9d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a9ea0  51                   push ecx
// 004a9ea1  8bcf                 mov ecx, edi
// 004a9ea3  e8d8b1ffff           call 0x4a5080
// 004a9ea8  eb7b                 jmp 0x4a9f25
// 004a9eaa  8b12                 mov edx, dword ptr [edx]
// 004a9eac  807a2400             cmp byte ptr [edx + 0x24], 0
// 004a9eb0  7516                 jne 0x4a9ec8
// 004a9eb2  885924               mov byte ptr [ecx + 0x24], bl
// 004a9eb5  885a24               mov byte ptr [edx + 0x24], bl
// 004a9eb8  8b10                 mov edx, dword ptr [eax]
// 004a9eba  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a9ebd  c6412400             mov byte ptr [ecx + 0x24], 0
// 004a9ec1  8b10                 mov edx, dword ptr [eax]
// 004a9ec3  8b7204               mov esi, dword ptr [edx + 4]
// 004a9ec6  eb5d                 jmp 0x4a9f25
// 004a9ec8  3b31                 cmp esi, dword ptr [ecx]
// 004a9eca  750a                 jne 0x4a9ed6
// 004a9ecc  8bf1                 mov esi, ecx
// 004a9ece  56                   push esi
// 004a9ecf  8bcf                 mov ecx, edi
// 004a9ed1  e8aab1ffff           call 0x4a5080
// 004a9ed6  8b4604               mov eax, dword ptr [esi + 4]
// 004a9ed9  885824               mov byte ptr [eax + 0x24], bl
// 004a9edc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a9edf  8b5104               mov edx, dword ptr [ecx + 4]
// 004a9ee2  c6422400             mov byte ptr [edx + 0x24], 0
// 004a9ee6  8b4604               mov eax, dword ptr [esi + 4]
// 004a9ee9  8b4004               mov eax, dword ptr [eax + 4]
// 004a9eec  8b4808               mov ecx, dword ptr [eax + 8]
// 004a9eef  8b11                 mov edx, dword ptr [ecx]
// 004a9ef1  895008               mov dword ptr [eax + 8], edx
// 004a9ef4  8b11                 mov edx, dword ptr [ecx]
// 004a9ef6  807a2500             cmp byte ptr [edx + 0x25], 0
// 004a9efa  7503                 jne 0x4a9eff
// 004a9efc  894204               mov dword ptr [edx + 4], eax
// 004a9eff  8b5004               mov edx, dword ptr [eax + 4]
// 004a9f02  895104               mov dword ptr [ecx + 4], edx
// 004a9f05  8b5704               mov edx, dword ptr [edi + 4]
// 004a9f08  3b4204               cmp eax, dword ptr [edx + 4]
// 004a9f0b  7505                 jne 0x4a9f12
// 004a9f0d  894a04               mov dword ptr [edx + 4], ecx
// 004a9f10  eb0e                 jmp 0x4a9f20
// 004a9f12  8b5004               mov edx, dword ptr [eax + 4]
// 004a9f15  3b02                 cmp eax, dword ptr [edx]
// 004a9f17  7504                 jne 0x4a9f1d
// 004a9f19  890a                 mov dword ptr [edx], ecx
// 004a9f1b  eb03                 jmp 0x4a9f20
// 004a9f1d  894a08               mov dword ptr [edx + 8], ecx
// 004a9f20  8901                 mov dword ptr [ecx], eax
// 004a9f22  894804               mov dword ptr [eax + 4], ecx
// 004a9f25  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a9f28  80792400             cmp byte ptr [ecx + 0x24], 0
// 004a9f2c  8d4604               lea eax, [esi + 4]
// 004a9f2f  0f841bffffff         je 0x4a9e50
// 004a9f35  8b5704               mov edx, dword ptr [edi + 4]
// 004a9f38  8b4204               mov eax, dword ptr [edx + 4]
// 004a9f3b  885824               mov byte ptr [eax + 0x24], bl
// 004a9f3e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a9f42  896804               mov dword ptr [eax + 4], ebp
// 004a9f45  8938                 mov dword ptr [eax], edi
// 004a9f47  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a9f4b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a9f52  59                   pop ecx
// 004a9f53  5f                   pop edi
// 004a9f54  5e                   pop esi
// 004a9f55  5d                   pop ebp
// 004a9f56  5b                   pop ebx
// 004a9f57  83c450               add esp, 0x50
// 004a9f5a  c21000               ret 0x10
// standard library map_int<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod20>
struct E { int v[5]; };
#include <map>
template class std::map<int, E>;
