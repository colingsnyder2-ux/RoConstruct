// from server: 100% by auto
// roc 2010-06 00640a30  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00640a30
//
// 00640a30  64a100000000         mov eax, dword ptr fs:[0]
// 00640a36  6aff                 push -1
// 00640a38  68e22f9a00           push 0x9a2fe2
// 00640a3d  50                   push eax
// 00640a3e  64892500000000       mov dword ptr fs:[0], esp
// 00640a45  83ec44               sub esp, 0x44
// 00640a48  57                   push edi
// 00640a49  8bf9                 mov edi, ecx
// 00640a4b  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 00640a52  7259                 jb 0x640aad
// 00640a54  68a800a000           push 0xa000a8
// 00640a59  8d4c2408             lea ecx, [esp + 8]
// 00640a5d  ff1510a49e00         call dword ptr [0x9ea410]
// 00640a63  8d4c2420             lea ecx, [esp + 0x20]
// 00640a67  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00640a6f  ff1518a99e00         call dword ptr [0x9ea918]
// 00640a75  8d442404             lea eax, [esp + 4]
// 00640a79  50                   push eax
// 00640a7a  8d4c2430             lea ecx, [esp + 0x30]
// 00640a7e  c644245401           mov byte ptr [esp + 0x54], 1
// 00640a83  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00640a8b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00640a91  68601bb000           push 0xb01b60
// 00640a96  8d4c2424             lea ecx, [esp + 0x24]
// 00640a9a  51                   push ecx
// 00640a9b  c644245800           mov byte ptr [esp + 0x58], 0
// 00640aa0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00640aa8  e8057f1600           call 0x7a89b2
// 00640aad  8b542464             mov edx, dword ptr [esp + 0x64]
// 00640ab1  8b4718               mov eax, dword ptr [edi + 0x18]
// 00640ab4  53                   push ebx
// 00640ab5  55                   push ebp
// 00640ab6  56                   push esi
// 00640ab7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00640abb  6a00                 push 0
// 00640abd  52                   push edx
// 00640abe  50                   push eax
// 00640abf  56                   push esi
// 00640ac0  50                   push eax
// 00640ac1  e80af6ffff           call 0x6400d0
// 00640ac6  8be8                 mov ebp, eax
// 00640ac8  8b4718               mov eax, dword ptr [edi + 0x18]
// 00640acb  bb01000000           mov ebx, 1
// 00640ad0  015f1c               add dword ptr [edi + 0x1c], ebx
// 00640ad3  3bf0                 cmp esi, eax
// 00640ad5  7510                 jne 0x640ae7
// 00640ad7  896804               mov dword ptr [eax + 4], ebp
// 00640ada  8b4718               mov eax, dword ptr [edi + 0x18]
// 00640add  8928                 mov dword ptr [eax], ebp
// 00640adf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00640ae2  896908               mov dword ptr [ecx + 8], ebp
// 00640ae5  eb22                 jmp 0x640b09
// 00640ae7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00640aec  740d                 je 0x640afb
// 00640aee  892e                 mov dword ptr [esi], ebp
// 00640af0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00640af3  3b30                 cmp esi, dword ptr [eax]
// 00640af5  7512                 jne 0x640b09
// 00640af7  8928                 mov dword ptr [eax], ebp
// 00640af9  eb0e                 jmp 0x640b09
// 00640afb  896e08               mov dword ptr [esi + 8], ebp
// 00640afe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00640b01  3b7008               cmp esi, dword ptr [eax + 8]
// 00640b04  7503                 jne 0x640b09
// 00640b06  896808               mov dword ptr [eax + 8], ebp
// 00640b09  8b5504               mov edx, dword ptr [ebp + 4]
// 00640b0c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00640b10  8d4504               lea eax, [ebp + 4]
// 00640b13  8bf5                 mov esi, ebp
// 00640b15  0f85ea000000         jne 0x640c05
// 00640b1b  eb03                 jmp 0x640b20
// 00640b1d  8d4900               lea ecx, [ecx]
// 00640b20  8b08                 mov ecx, dword ptr [eax]
// 00640b22  8b5104               mov edx, dword ptr [ecx + 4]
// 00640b25  3b0a                 cmp ecx, dword ptr [edx]
// 00640b27  7551                 jne 0x640b7a
// 00640b29  8b5208               mov edx, dword ptr [edx + 8]
// 00640b2c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00640b30  7519                 jne 0x640b4b
// 00640b32  885934               mov byte ptr [ecx + 0x34], bl
// 00640b35  885a34               mov byte ptr [edx + 0x34], bl
// 00640b38  8b10                 mov edx, dword ptr [eax]
// 00640b3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00640b3d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00640b41  8b10                 mov edx, dword ptr [eax]
// 00640b43  8b7204               mov esi, dword ptr [edx + 4]
// 00640b46  e9aa000000           jmp 0x640bf5
// 00640b4b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00640b4e  750a                 jne 0x640b5a
// 00640b50  8bf1                 mov esi, ecx
// 00640b52  56                   push esi
// 00640b53  8bcf                 mov ecx, edi
// 00640b55  e856f1ffff           call 0x63fcb0
// 00640b5a  8b4604               mov eax, dword ptr [esi + 4]
// 00640b5d  885834               mov byte ptr [eax + 0x34], bl
// 00640b60  8b4e04               mov ecx, dword ptr [esi + 4]
// 00640b63  8b5104               mov edx, dword ptr [ecx + 4]
// 00640b66  c6423400             mov byte ptr [edx + 0x34], 0
// 00640b6a  8b4604               mov eax, dword ptr [esi + 4]
// 00640b6d  8b4804               mov ecx, dword ptr [eax + 4]
// 00640b70  51                   push ecx
// 00640b71  8bcf                 mov ecx, edi
// 00640b73  e888f1ffff           call 0x63fd00
// 00640b78  eb7b                 jmp 0x640bf5
// 00640b7a  8b12                 mov edx, dword ptr [edx]
// 00640b7c  807a3400             cmp byte ptr [edx + 0x34], 0
// 00640b80  7516                 jne 0x640b98
// 00640b82  885934               mov byte ptr [ecx + 0x34], bl
// 00640b85  885a34               mov byte ptr [edx + 0x34], bl
// 00640b88  8b10                 mov edx, dword ptr [eax]
// 00640b8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00640b8d  c6413400             mov byte ptr [ecx + 0x34], 0
// 00640b91  8b10                 mov edx, dword ptr [eax]
// 00640b93  8b7204               mov esi, dword ptr [edx + 4]
// 00640b96  eb5d                 jmp 0x640bf5
// 00640b98  3b31                 cmp esi, dword ptr [ecx]
// 00640b9a  750a                 jne 0x640ba6
// 00640b9c  8bf1                 mov esi, ecx
// 00640b9e  56                   push esi
// 00640b9f  8bcf                 mov ecx, edi
// 00640ba1  e85af1ffff           call 0x63fd00
// 00640ba6  8b4604               mov eax, dword ptr [esi + 4]
// 00640ba9  885834               mov byte ptr [eax + 0x34], bl
// 00640bac  8b4e04               mov ecx, dword ptr [esi + 4]
// 00640baf  8b5104               mov edx, dword ptr [ecx + 4]
// 00640bb2  c6423400             mov byte ptr [edx + 0x34], 0
// 00640bb6  8b4604               mov eax, dword ptr [esi + 4]
// 00640bb9  8b4004               mov eax, dword ptr [eax + 4]
// 00640bbc  8b4808               mov ecx, dword ptr [eax + 8]
// 00640bbf  8b11                 mov edx, dword ptr [ecx]
// 00640bc1  895008               mov dword ptr [eax + 8], edx
// 00640bc4  8b11                 mov edx, dword ptr [ecx]
// 00640bc6  807a3500             cmp byte ptr [edx + 0x35], 0
// 00640bca  7503                 jne 0x640bcf
// 00640bcc  894204               mov dword ptr [edx + 4], eax
// 00640bcf  8b5004               mov edx, dword ptr [eax + 4]
// 00640bd2  895104               mov dword ptr [ecx + 4], edx
// 00640bd5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00640bd8  3b4204               cmp eax, dword ptr [edx + 4]
// 00640bdb  7505                 jne 0x640be2
// 00640bdd  894a04               mov dword ptr [edx + 4], ecx
// 00640be0  eb0e                 jmp 0x640bf0
// 00640be2  8b5004               mov edx, dword ptr [eax + 4]
// 00640be5  3b02                 cmp eax, dword ptr [edx]
// 00640be7  7504                 jne 0x640bed
// 00640be9  890a                 mov dword ptr [edx], ecx
// 00640beb  eb03                 jmp 0x640bf0
// 00640bed  894a08               mov dword ptr [edx + 8], ecx
// 00640bf0  8901                 mov dword ptr [ecx], eax
// 00640bf2  894804               mov dword ptr [eax + 4], ecx
// 00640bf5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00640bf8  80793400             cmp byte ptr [ecx + 0x34], 0
// 00640bfc  8d4604               lea eax, [esi + 4]
// 00640bff  0f841bffffff         je 0x640b20
// 00640c05  8b5718               mov edx, dword ptr [edi + 0x18]
// 00640c08  8b4204               mov eax, dword ptr [edx + 4]
// 00640c0b  885834               mov byte ptr [eax + 0x34], bl
// 00640c0e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00640c12  8b0f                 mov ecx, dword ptr [edi]
// 00640c14  5e                   pop esi
// 00640c15  896804               mov dword ptr [eax + 4], ebp
// 00640c18  5d                   pop ebp
// 00640c19  8908                 mov dword ptr [eax], ecx
// 00640c1b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00640c1f  5b                   pop ebx
// 00640c20  5f                   pop edi
// 00640c21  64890d00000000       mov dword ptr fs:[0], ecx
// 00640c28  83c450               add esp, 0x50
// 00640c2b  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
