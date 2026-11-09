// from server: 100% by auto
// roc 2007-08 004a2980  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a2980
//
// 004a2980  6aff                 push -1
// 004a2982  68293a7400           push 0x743a29
// 004a2987  64a100000000         mov eax, dword ptr fs:[0]
// 004a298d  50                   push eax
// 004a298e  83ec44               sub esp, 0x44
// 004a2991  53                   push ebx
// 004a2992  55                   push ebp
// 004a2993  56                   push esi
// 004a2994  57                   push edi
// 004a2995  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a299a  33c4                 xor eax, esp
// 004a299c  50                   push eax
// 004a299d  8d442458             lea eax, [esp + 0x58]
// 004a29a1  64a300000000         mov dword ptr fs:[0], eax
// 004a29a7  8bf9                 mov edi, ecx
// 004a29a9  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 004a29b0  723c                 jb 0x4a29ee
// 004a29b2  68904f7800           push 0x784f90
// 004a29b7  8d4c2418             lea ecx, [esp + 0x18]
// 004a29bb  ff1598e67700         call dword ptr [0x77e698]
// 004a29c1  8d442414             lea eax, [esp + 0x14]
// 004a29c5  50                   push eax
// 004a29c6  8d4c2434             lea ecx, [esp + 0x34]
// 004a29ca  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a29d2  e8e9faf5ff           call 0x4024c0
// 004a29d7  6878f78300           push 0x83f778
// 004a29dc  8d4c2434             lea ecx, [esp + 0x34]
// 004a29e0  51                   push ecx
// 004a29e1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a29e9  e8b0e11800           call 0x630b9e
// 004a29ee  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a29f2  8b4704               mov eax, dword ptr [edi + 4]
// 004a29f5  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a29f9  6a00                 push 0
// 004a29fb  52                   push edx
// 004a29fc  50                   push eax
// 004a29fd  56                   push esi
// 004a29fe  50                   push eax
// 004a29ff  e8ccfeffff           call 0x4a28d0
// 004a2a04  8be8                 mov ebp, eax
// 004a2a06  8b4704               mov eax, dword ptr [edi + 4]
// 004a2a09  bb01000000           mov ebx, 1
// 004a2a0e  015f08               add dword ptr [edi + 8], ebx
// 004a2a11  3bf0                 cmp esi, eax
// 004a2a13  7510                 jne 0x4a2a25
// 004a2a15  896804               mov dword ptr [eax + 4], ebp
// 004a2a18  8b4704               mov eax, dword ptr [edi + 4]
// 004a2a1b  8928                 mov dword ptr [eax], ebp
// 004a2a1d  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a2a20  896908               mov dword ptr [ecx + 8], ebp
// 004a2a23  eb22                 jmp 0x4a2a47
// 004a2a25  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a2a2a  740d                 je 0x4a2a39
// 004a2a2c  892e                 mov dword ptr [esi], ebp
// 004a2a2e  8b4704               mov eax, dword ptr [edi + 4]
// 004a2a31  3b30                 cmp esi, dword ptr [eax]
// 004a2a33  7512                 jne 0x4a2a47
// 004a2a35  8928                 mov dword ptr [eax], ebp
// 004a2a37  eb0e                 jmp 0x4a2a47
// 004a2a39  896e08               mov dword ptr [esi + 8], ebp
// 004a2a3c  8b4704               mov eax, dword ptr [edi + 4]
// 004a2a3f  3b7008               cmp esi, dword ptr [eax + 8]
// 004a2a42  7503                 jne 0x4a2a47
// 004a2a44  896808               mov dword ptr [eax + 8], ebp
// 004a2a47  8b5504               mov edx, dword ptr [ebp + 4]
// 004a2a4a  807a2000             cmp byte ptr [edx + 0x20], 0
// 004a2a4e  8d4504               lea eax, [ebp + 4]
// 004a2a51  8bf5                 mov esi, ebp
// 004a2a53  0f85ec000000         jne 0x4a2b45
// 004a2a59  8da42400000000       lea esp, [esp]
// 004a2a60  8b08                 mov ecx, dword ptr [eax]
// 004a2a62  8b5104               mov edx, dword ptr [ecx + 4]
// 004a2a65  3b0a                 cmp ecx, dword ptr [edx]
// 004a2a67  7551                 jne 0x4a2aba
// 004a2a69  8b5208               mov edx, dword ptr [edx + 8]
// 004a2a6c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004a2a70  7519                 jne 0x4a2a8b
// 004a2a72  885920               mov byte ptr [ecx + 0x20], bl
// 004a2a75  885a20               mov byte ptr [edx + 0x20], bl
// 004a2a78  8b10                 mov edx, dword ptr [eax]
// 004a2a7a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a2a7d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004a2a81  8b10                 mov edx, dword ptr [eax]
// 004a2a83  8b7204               mov esi, dword ptr [edx + 4]
// 004a2a86  e9aa000000           jmp 0x4a2b35
// 004a2a8b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a2a8e  750a                 jne 0x4a2a9a
// 004a2a90  8bf1                 mov esi, ecx
// 004a2a92  56                   push esi
// 004a2a93  8bcf                 mov ecx, edi
// 004a2a95  e876ac0200           call 0x4cd710
// 004a2a9a  8b4604               mov eax, dword ptr [esi + 4]
// 004a2a9d  885820               mov byte ptr [eax + 0x20], bl
// 004a2aa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2aa3  8b5104               mov edx, dword ptr [ecx + 4]
// 004a2aa6  c6422000             mov byte ptr [edx + 0x20], 0
// 004a2aaa  8b4604               mov eax, dword ptr [esi + 4]
// 004a2aad  8b4804               mov ecx, dword ptr [eax + 4]
// 004a2ab0  51                   push ecx
// 004a2ab1  8bcf                 mov ecx, edi
// 004a2ab3  e838d80200           call 0x4d02f0
// 004a2ab8  eb7b                 jmp 0x4a2b35
// 004a2aba  8b12                 mov edx, dword ptr [edx]
// 004a2abc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004a2ac0  7516                 jne 0x4a2ad8
// 004a2ac2  885920               mov byte ptr [ecx + 0x20], bl
// 004a2ac5  885a20               mov byte ptr [edx + 0x20], bl
// 004a2ac8  8b10                 mov edx, dword ptr [eax]
// 004a2aca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a2acd  c6412000             mov byte ptr [ecx + 0x20], 0
// 004a2ad1  8b10                 mov edx, dword ptr [eax]
// 004a2ad3  8b7204               mov esi, dword ptr [edx + 4]
// 004a2ad6  eb5d                 jmp 0x4a2b35
// 004a2ad8  3b31                 cmp esi, dword ptr [ecx]
// 004a2ada  750a                 jne 0x4a2ae6
// 004a2adc  8bf1                 mov esi, ecx
// 004a2ade  56                   push esi
// 004a2adf  8bcf                 mov ecx, edi
// 004a2ae1  e80ad80200           call 0x4d02f0
// 004a2ae6  8b4604               mov eax, dword ptr [esi + 4]
// 004a2ae9  885820               mov byte ptr [eax + 0x20], bl
// 004a2aec  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2aef  8b5104               mov edx, dword ptr [ecx + 4]
// 004a2af2  c6422000             mov byte ptr [edx + 0x20], 0
// 004a2af6  8b4604               mov eax, dword ptr [esi + 4]
// 004a2af9  8b4004               mov eax, dword ptr [eax + 4]
// 004a2afc  8b4808               mov ecx, dword ptr [eax + 8]
// 004a2aff  8b11                 mov edx, dword ptr [ecx]
// 004a2b01  895008               mov dword ptr [eax + 8], edx
// 004a2b04  8b11                 mov edx, dword ptr [ecx]
// 004a2b06  807a2100             cmp byte ptr [edx + 0x21], 0
// 004a2b0a  7503                 jne 0x4a2b0f
// 004a2b0c  894204               mov dword ptr [edx + 4], eax
// 004a2b0f  8b5004               mov edx, dword ptr [eax + 4]
// 004a2b12  895104               mov dword ptr [ecx + 4], edx
// 004a2b15  8b5704               mov edx, dword ptr [edi + 4]
// 004a2b18  3b4204               cmp eax, dword ptr [edx + 4]
// 004a2b1b  7505                 jne 0x4a2b22
// 004a2b1d  894a04               mov dword ptr [edx + 4], ecx
// 004a2b20  eb0e                 jmp 0x4a2b30
// 004a2b22  8b5004               mov edx, dword ptr [eax + 4]
// 004a2b25  3b02                 cmp eax, dword ptr [edx]
// 004a2b27  7504                 jne 0x4a2b2d
// 004a2b29  890a                 mov dword ptr [edx], ecx
// 004a2b2b  eb03                 jmp 0x4a2b30
// 004a2b2d  894a08               mov dword ptr [edx + 8], ecx
// 004a2b30  8901                 mov dword ptr [ecx], eax
// 004a2b32  894804               mov dword ptr [eax + 4], ecx
// 004a2b35  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a2b38  80792000             cmp byte ptr [ecx + 0x20], 0
// 004a2b3c  8d4604               lea eax, [esi + 4]
// 004a2b3f  0f841bffffff         je 0x4a2a60
// 004a2b45  8b5704               mov edx, dword ptr [edi + 4]
// 004a2b48  8b4204               mov eax, dword ptr [edx + 4]
// 004a2b4b  885820               mov byte ptr [eax + 0x20], bl
// 004a2b4e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a2b52  896804               mov dword ptr [eax + 4], ebp
// 004a2b55  8938                 mov dword ptr [eax], edi
// 004a2b57  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a2b5b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2b62  59                   pop ecx
// 004a2b63  5f                   pop edi
// 004a2b64  5e                   pop esi
// 004a2b65  5d                   pop ebp
// 004a2b66  5b                   pop ebx
// 004a2b67  83c450               add esp, 0x50
// 004a2b6a  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
