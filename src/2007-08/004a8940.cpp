// from server: 100% by auto
// roc 2007-08 004a8940  unit: RBX::Network::VClient::?$FactoryProduct  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a8940
//
// 004a8940  6aff                 push -1
// 004a8942  68293a7400           push 0x743a29
// 004a8947  64a100000000         mov eax, dword ptr fs:[0]
// 004a894d  50                   push eax
// 004a894e  83ec44               sub esp, 0x44
// 004a8951  53                   push ebx
// 004a8952  55                   push ebp
// 004a8953  56                   push esi
// 004a8954  57                   push edi
// 004a8955  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a895a  33c4                 xor eax, esp
// 004a895c  50                   push eax
// 004a895d  8d442458             lea eax, [esp + 0x58]
// 004a8961  64a300000000         mov dword ptr fs:[0], eax
// 004a8967  8bf9                 mov edi, ecx
// 004a8969  817f08feffff1f       cmp dword ptr [edi + 8], 0x1ffffffe
// 004a8970  723c                 jb 0x4a89ae
// 004a8972  68904f7800           push 0x784f90
// 004a8977  8d4c2418             lea ecx, [esp + 0x18]
// 004a897b  ff1598e67700         call dword ptr [0x77e698]
// 004a8981  8d442414             lea eax, [esp + 0x14]
// 004a8985  50                   push eax
// 004a8986  8d4c2434             lea ecx, [esp + 0x34]
// 004a898a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a8992  e8299bf5ff           call 0x4024c0
// 004a8997  6878f78300           push 0x83f778
// 004a899c  8d4c2434             lea ecx, [esp + 0x34]
// 004a89a0  51                   push ecx
// 004a89a1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a89a9  e8f0811800           call 0x630b9e
// 004a89ae  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a89b2  8b4704               mov eax, dword ptr [edi + 4]
// 004a89b5  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a89b9  6a00                 push 0
// 004a89bb  52                   push edx
// 004a89bc  50                   push eax
// 004a89bd  56                   push esi
// 004a89be  50                   push eax
// 004a89bf  e84cf1ffff           call 0x4a7b10
// 004a89c4  8be8                 mov ebp, eax
// 004a89c6  8b4704               mov eax, dword ptr [edi + 4]
// 004a89c9  bb01000000           mov ebx, 1
// 004a89ce  015f08               add dword ptr [edi + 8], ebx
// 004a89d1  3bf0                 cmp esi, eax
// 004a89d3  7510                 jne 0x4a89e5
// 004a89d5  896804               mov dword ptr [eax + 4], ebp
// 004a89d8  8b4704               mov eax, dword ptr [edi + 4]
// 004a89db  8928                 mov dword ptr [eax], ebp
// 004a89dd  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a89e0  896908               mov dword ptr [ecx + 8], ebp
// 004a89e3  eb22                 jmp 0x4a8a07
// 004a89e5  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a89ea  740d                 je 0x4a89f9
// 004a89ec  892e                 mov dword ptr [esi], ebp
// 004a89ee  8b4704               mov eax, dword ptr [edi + 4]
// 004a89f1  3b30                 cmp esi, dword ptr [eax]
// 004a89f3  7512                 jne 0x4a8a07
// 004a89f5  8928                 mov dword ptr [eax], ebp
// 004a89f7  eb0e                 jmp 0x4a8a07
// 004a89f9  896e08               mov dword ptr [esi + 8], ebp
// 004a89fc  8b4704               mov eax, dword ptr [edi + 4]
// 004a89ff  3b7008               cmp esi, dword ptr [eax + 8]
// 004a8a02  7503                 jne 0x4a8a07
// 004a8a04  896808               mov dword ptr [eax + 8], ebp
// 004a8a07  8b5504               mov edx, dword ptr [ebp + 4]
// 004a8a0a  807a1400             cmp byte ptr [edx + 0x14], 0
// 004a8a0e  8d4504               lea eax, [ebp + 4]
// 004a8a11  8bf5                 mov esi, ebp
// 004a8a13  0f85ec000000         jne 0x4a8b05
// 004a8a19  8da42400000000       lea esp, [esp]
// 004a8a20  8b08                 mov ecx, dword ptr [eax]
// 004a8a22  8b5104               mov edx, dword ptr [ecx + 4]
// 004a8a25  3b0a                 cmp ecx, dword ptr [edx]
// 004a8a27  7551                 jne 0x4a8a7a
// 004a8a29  8b5208               mov edx, dword ptr [edx + 8]
// 004a8a2c  807a1400             cmp byte ptr [edx + 0x14], 0
// 004a8a30  7519                 jne 0x4a8a4b
// 004a8a32  885914               mov byte ptr [ecx + 0x14], bl
// 004a8a35  885a14               mov byte ptr [edx + 0x14], bl
// 004a8a38  8b10                 mov edx, dword ptr [eax]
// 004a8a3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a8a3d  c6411400             mov byte ptr [ecx + 0x14], 0
// 004a8a41  8b10                 mov edx, dword ptr [eax]
// 004a8a43  8b7204               mov esi, dword ptr [edx + 4]
// 004a8a46  e9aa000000           jmp 0x4a8af5
// 004a8a4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a8a4e  750a                 jne 0x4a8a5a
// 004a8a50  8bf1                 mov esi, ecx
// 004a8a52  56                   push esi
// 004a8a53  8bcf                 mov ecx, edi
// 004a8a55  e8864a0c00           call 0x56d4e0
// 004a8a5a  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a5d  885814               mov byte ptr [eax + 0x14], bl
// 004a8a60  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8a63  8b5104               mov edx, dword ptr [ecx + 4]
// 004a8a66  c6421400             mov byte ptr [edx + 0x14], 0
// 004a8a6a  8b4604               mov eax, dword ptr [esi + 4]
// 004a8a6d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a8a70  51                   push ecx
// 004a8a71  8bcf                 mov ecx, edi
// 004a8a73  e8a8c01500           call 0x604b20
// 004a8a78  eb7b                 jmp 0x4a8af5
// 004a8a7a  8b12                 mov edx, dword ptr [edx]
// 004a8a7c  807a1400             cmp byte ptr [edx + 0x14], 0
// 004a8a80  7516                 jne 0x4a8a98
// 004a8a82  885914               mov byte ptr [ecx + 0x14], bl
// 004a8a85  885a14               mov byte ptr [edx + 0x14], bl
// 004a8a88  8b10                 mov edx, dword ptr [eax]
// 004a8a8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a8a8d  c6411400             mov byte ptr [ecx + 0x14], 0
// 004a8a91  8b10                 mov edx, dword ptr [eax]
// 004a8a93  8b7204               mov esi, dword ptr [edx + 4]
// 004a8a96  eb5d                 jmp 0x4a8af5
// 004a8a98  3b31                 cmp esi, dword ptr [ecx]
// 004a8a9a  750a                 jne 0x4a8aa6
// 004a8a9c  8bf1                 mov esi, ecx
// 004a8a9e  56                   push esi
// 004a8a9f  8bcf                 mov ecx, edi
// 004a8aa1  e87ac01500           call 0x604b20
// 004a8aa6  8b4604               mov eax, dword ptr [esi + 4]
// 004a8aa9  885814               mov byte ptr [eax + 0x14], bl
// 004a8aac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8aaf  8b5104               mov edx, dword ptr [ecx + 4]
// 004a8ab2  c6421400             mov byte ptr [edx + 0x14], 0
// 004a8ab6  8b4604               mov eax, dword ptr [esi + 4]
// 004a8ab9  8b4004               mov eax, dword ptr [eax + 4]
// 004a8abc  8b4808               mov ecx, dword ptr [eax + 8]
// 004a8abf  8b11                 mov edx, dword ptr [ecx]
// 004a8ac1  895008               mov dword ptr [eax + 8], edx
// 004a8ac4  8b11                 mov edx, dword ptr [ecx]
// 004a8ac6  807a1500             cmp byte ptr [edx + 0x15], 0
// 004a8aca  7503                 jne 0x4a8acf
// 004a8acc  894204               mov dword ptr [edx + 4], eax
// 004a8acf  8b5004               mov edx, dword ptr [eax + 4]
// 004a8ad2  895104               mov dword ptr [ecx + 4], edx
// 004a8ad5  8b5704               mov edx, dword ptr [edi + 4]
// 004a8ad8  3b4204               cmp eax, dword ptr [edx + 4]
// 004a8adb  7505                 jne 0x4a8ae2
// 004a8add  894a04               mov dword ptr [edx + 4], ecx
// 004a8ae0  eb0e                 jmp 0x4a8af0
// 004a8ae2  8b5004               mov edx, dword ptr [eax + 4]
// 004a8ae5  3b02                 cmp eax, dword ptr [edx]
// 004a8ae7  7504                 jne 0x4a8aed
// 004a8ae9  890a                 mov dword ptr [edx], ecx
// 004a8aeb  eb03                 jmp 0x4a8af0
// 004a8aed  894a08               mov dword ptr [edx + 8], ecx
// 004a8af0  8901                 mov dword ptr [ecx], eax
// 004a8af2  894804               mov dword ptr [eax + 4], ecx
// 004a8af5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a8af8  80791400             cmp byte ptr [ecx + 0x14], 0
// 004a8afc  8d4604               lea eax, [esi + 4]
// 004a8aff  0f841bffffff         je 0x4a8a20
// 004a8b05  8b5704               mov edx, dword ptr [edi + 4]
// 004a8b08  8b4204               mov eax, dword ptr [edx + 4]
// 004a8b0b  885814               mov byte ptr [eax + 0x14], bl
// 004a8b0e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a8b12  896804               mov dword ptr [eax + 4], ebp
// 004a8b15  8938                 mov dword ptr [eax], edi
// 004a8b17  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a8b1b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a8b22  59                   pop ecx
// 004a8b23  5f                   pop edi
// 004a8b24  5e                   pop esi
// 004a8b25  5d                   pop ebp
// 004a8b26  5b                   pop ebx
// 004a8b27  83c450               add esp, 0x50
// 004a8b2a  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
