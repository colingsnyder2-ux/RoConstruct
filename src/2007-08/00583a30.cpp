// from server: 100% by auto
// roc 2007-08 00583a30  unit: RBX::VHat::?$FactoryProduct  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583a30
//
// 00583a30  64a100000000         mov eax, dword ptr fs:[0]
// 00583a36  6aff                 push -1
// 00583a38  68b2417500           push 0x7541b2
// 00583a3d  50                   push eax
// 00583a3e  64892500000000       mov dword ptr fs:[0], esp
// 00583a45  83ec44               sub esp, 0x44
// 00583a48  57                   push edi
// 00583a49  8bf9                 mov edi, ecx
// 00583a4b  817f08feffff1f       cmp dword ptr [edi + 8], 0x1ffffffe
// 00583a52  7259                 jb 0x583aad
// 00583a54  68904f7800           push 0x784f90
// 00583a59  8d4c2408             lea ecx, [esp + 8]
// 00583a5d  ff1598e67700         call dword ptr [0x77e698]
// 00583a63  8d4c2420             lea ecx, [esp + 0x20]
// 00583a67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00583a6f  ff15f8e67700         call dword ptr [0x77e6f8]
// 00583a75  8d442404             lea eax, [esp + 4]
// 00583a79  50                   push eax
// 00583a7a  8d4c2430             lea ecx, [esp + 0x30]
// 00583a7e  c644245401           mov byte ptr [esp + 0x54], 1
// 00583a83  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 00583a8b  ff159ce67700         call dword ptr [0x77e69c]
// 00583a91  6878f78300           push 0x83f778
// 00583a96  8d4c2424             lea ecx, [esp + 0x24]
// 00583a9a  51                   push ecx
// 00583a9b  c644245800           mov byte ptr [esp + 0x58], 0
// 00583aa0  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 00583aa8  e8f1d00a00           call 0x630b9e
// 00583aad  8b542464             mov edx, dword ptr [esp + 0x64]
// 00583ab1  8b4704               mov eax, dword ptr [edi + 4]
// 00583ab4  53                   push ebx
// 00583ab5  55                   push ebp
// 00583ab6  56                   push esi
// 00583ab7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00583abb  6a00                 push 0
// 00583abd  52                   push edx
// 00583abe  50                   push eax
// 00583abf  56                   push esi
// 00583ac0  50                   push eax
// 00583ac1  e86a700500           call 0x5dab30
// 00583ac6  8be8                 mov ebp, eax
// 00583ac8  8b4704               mov eax, dword ptr [edi + 4]
// 00583acb  bb01000000           mov ebx, 1
// 00583ad0  015f08               add dword ptr [edi + 8], ebx
// 00583ad3  3bf0                 cmp esi, eax
// 00583ad5  7510                 jne 0x583ae7
// 00583ad7  896804               mov dword ptr [eax + 4], ebp
// 00583ada  8b4704               mov eax, dword ptr [edi + 4]
// 00583add  8928                 mov dword ptr [eax], ebp
// 00583adf  8b4f04               mov ecx, dword ptr [edi + 4]
// 00583ae2  896908               mov dword ptr [ecx + 8], ebp
// 00583ae5  eb22                 jmp 0x583b09
// 00583ae7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00583aec  740d                 je 0x583afb
// 00583aee  892e                 mov dword ptr [esi], ebp
// 00583af0  8b4704               mov eax, dword ptr [edi + 4]
// 00583af3  3b30                 cmp esi, dword ptr [eax]
// 00583af5  7512                 jne 0x583b09
// 00583af7  8928                 mov dword ptr [eax], ebp
// 00583af9  eb0e                 jmp 0x583b09
// 00583afb  896e08               mov dword ptr [esi + 8], ebp
// 00583afe  8b4704               mov eax, dword ptr [edi + 4]
// 00583b01  3b7008               cmp esi, dword ptr [eax + 8]
// 00583b04  7503                 jne 0x583b09
// 00583b06  896808               mov dword ptr [eax + 8], ebp
// 00583b09  8b5504               mov edx, dword ptr [ebp + 4]
// 00583b0c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00583b10  8d4504               lea eax, [ebp + 4]
// 00583b13  8bf5                 mov esi, ebp
// 00583b15  0f85ea000000         jne 0x583c05
// 00583b1b  eb03                 jmp 0x583b20
// 00583b1d  8d4900               lea ecx, [ecx]
// 00583b20  8b08                 mov ecx, dword ptr [eax]
// 00583b22  8b5104               mov edx, dword ptr [ecx + 4]
// 00583b25  3b0a                 cmp ecx, dword ptr [edx]
// 00583b27  7551                 jne 0x583b7a
// 00583b29  8b5208               mov edx, dword ptr [edx + 8]
// 00583b2c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00583b30  7519                 jne 0x583b4b
// 00583b32  885914               mov byte ptr [ecx + 0x14], bl
// 00583b35  885a14               mov byte ptr [edx + 0x14], bl
// 00583b38  8b10                 mov edx, dword ptr [eax]
// 00583b3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00583b3d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00583b41  8b10                 mov edx, dword ptr [eax]
// 00583b43  8b7204               mov esi, dword ptr [edx + 4]
// 00583b46  e9aa000000           jmp 0x583bf5
// 00583b4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00583b4e  750a                 jne 0x583b5a
// 00583b50  8bf1                 mov esi, ecx
// 00583b52  56                   push esi
// 00583b53  8bcf                 mov ecx, edi
// 00583b55  e88699feff           call 0x56d4e0
// 00583b5a  8b4604               mov eax, dword ptr [esi + 4]
// 00583b5d  885814               mov byte ptr [eax + 0x14], bl
// 00583b60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583b63  8b5104               mov edx, dword ptr [ecx + 4]
// 00583b66  c6421400             mov byte ptr [edx + 0x14], 0
// 00583b6a  8b4604               mov eax, dword ptr [esi + 4]
// 00583b6d  8b4804               mov ecx, dword ptr [eax + 4]
// 00583b70  51                   push ecx
// 00583b71  8bcf                 mov ecx, edi
// 00583b73  e8a80f0800           call 0x604b20
// 00583b78  eb7b                 jmp 0x583bf5
// 00583b7a  8b12                 mov edx, dword ptr [edx]
// 00583b7c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00583b80  7516                 jne 0x583b98
// 00583b82  885914               mov byte ptr [ecx + 0x14], bl
// 00583b85  885a14               mov byte ptr [edx + 0x14], bl
// 00583b88  8b10                 mov edx, dword ptr [eax]
// 00583b8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00583b8d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00583b91  8b10                 mov edx, dword ptr [eax]
// 00583b93  8b7204               mov esi, dword ptr [edx + 4]
// 00583b96  eb5d                 jmp 0x583bf5
// 00583b98  3b31                 cmp esi, dword ptr [ecx]
// 00583b9a  750a                 jne 0x583ba6
// 00583b9c  8bf1                 mov esi, ecx
// 00583b9e  56                   push esi
// 00583b9f  8bcf                 mov ecx, edi
// 00583ba1  e87a0f0800           call 0x604b20
// 00583ba6  8b4604               mov eax, dword ptr [esi + 4]
// 00583ba9  885814               mov byte ptr [eax + 0x14], bl
// 00583bac  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583baf  8b5104               mov edx, dword ptr [ecx + 4]
// 00583bb2  c6421400             mov byte ptr [edx + 0x14], 0
// 00583bb6  8b4604               mov eax, dword ptr [esi + 4]
// 00583bb9  8b4004               mov eax, dword ptr [eax + 4]
// 00583bbc  8b4808               mov ecx, dword ptr [eax + 8]
// 00583bbf  8b11                 mov edx, dword ptr [ecx]
// 00583bc1  895008               mov dword ptr [eax + 8], edx
// 00583bc4  8b11                 mov edx, dword ptr [ecx]
// 00583bc6  807a1500             cmp byte ptr [edx + 0x15], 0
// 00583bca  7503                 jne 0x583bcf
// 00583bcc  894204               mov dword ptr [edx + 4], eax
// 00583bcf  8b5004               mov edx, dword ptr [eax + 4]
// 00583bd2  895104               mov dword ptr [ecx + 4], edx
// 00583bd5  8b5704               mov edx, dword ptr [edi + 4]
// 00583bd8  3b4204               cmp eax, dword ptr [edx + 4]
// 00583bdb  7505                 jne 0x583be2
// 00583bdd  894a04               mov dword ptr [edx + 4], ecx
// 00583be0  eb0e                 jmp 0x583bf0
// 00583be2  8b5004               mov edx, dword ptr [eax + 4]
// 00583be5  3b02                 cmp eax, dword ptr [edx]
// 00583be7  7504                 jne 0x583bed
// 00583be9  890a                 mov dword ptr [edx], ecx
// 00583beb  eb03                 jmp 0x583bf0
// 00583bed  894a08               mov dword ptr [edx + 8], ecx
// 00583bf0  8901                 mov dword ptr [ecx], eax
// 00583bf2  894804               mov dword ptr [eax + 4], ecx
// 00583bf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00583bf8  80791400             cmp byte ptr [ecx + 0x14], 0
// 00583bfc  8d4604               lea eax, [esi + 4]
// 00583bff  0f841bffffff         je 0x583b20
// 00583c05  8b5704               mov edx, dword ptr [edi + 4]
// 00583c08  8b4204               mov eax, dword ptr [edx + 4]
// 00583c0b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00583c0f  885814               mov byte ptr [eax + 0x14], bl
// 00583c12  8b442464             mov eax, dword ptr [esp + 0x64]
// 00583c16  5e                   pop esi
// 00583c17  896804               mov dword ptr [eax + 4], ebp
// 00583c1a  5d                   pop ebp
// 00583c1b  8938                 mov dword ptr [eax], edi
// 00583c1d  5b                   pop ebx
// 00583c1e  5f                   pop edi
// 00583c1f  64890d00000000       mov dword ptr fs:[0], ecx
// 00583c26  83c450               add esp, 0x50
// 00583c29  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
