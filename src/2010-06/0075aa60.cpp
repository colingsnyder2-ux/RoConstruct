// from server: 100% by auto
// roc 2010-06 0075aa60  unit: RBX::PrismPoly  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075aa60
//
// 0075aa60  64a100000000         mov eax, dword ptr fs:[0]
// 0075aa66  6aff                 push -1
// 0075aa68  68e22f9a00           push 0x9a2fe2
// 0075aa6d  50                   push eax
// 0075aa6e  64892500000000       mov dword ptr fs:[0], esp
// 0075aa75  83ec44               sub esp, 0x44
// 0075aa78  57                   push edi
// 0075aa79  8bf9                 mov edi, ecx
// 0075aa7b  817f1cfeffff0f       cmp dword ptr [edi + 0x1c], 0xffffffe
// 0075aa82  7259                 jb 0x75aadd
// 0075aa84  68a800a000           push 0xa000a8
// 0075aa89  8d4c2408             lea ecx, [esp + 8]
// 0075aa8d  ff1510a49e00         call dword ptr [0x9ea410]
// 0075aa93  8d4c2420             lea ecx, [esp + 0x20]
// 0075aa97  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0075aa9f  ff1518a99e00         call dword ptr [0x9ea918]
// 0075aaa5  8d442404             lea eax, [esp + 4]
// 0075aaa9  50                   push eax
// 0075aaaa  8d4c2430             lea ecx, [esp + 0x30]
// 0075aaae  c644245401           mov byte ptr [esp + 0x54], 1
// 0075aab3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0075aabb  ff150ca49e00         call dword ptr [0x9ea40c]
// 0075aac1  68601bb000           push 0xb01b60
// 0075aac6  8d4c2424             lea ecx, [esp + 0x24]
// 0075aaca  51                   push ecx
// 0075aacb  c644245800           mov byte ptr [esp + 0x58], 0
// 0075aad0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0075aad8  e8d5de0400           call 0x7a89b2
// 0075aadd  8b542464             mov edx, dword ptr [esp + 0x64]
// 0075aae1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075aae4  53                   push ebx
// 0075aae5  55                   push ebp
// 0075aae6  56                   push esi
// 0075aae7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0075aaeb  6a00                 push 0
// 0075aaed  52                   push edx
// 0075aaee  50                   push eax
// 0075aaef  56                   push esi
// 0075aaf0  50                   push eax
// 0075aaf1  e86ab2ffff           call 0x755d60
// 0075aaf6  8be8                 mov ebp, eax
// 0075aaf8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075aafb  bb01000000           mov ebx, 1
// 0075ab00  015f1c               add dword ptr [edi + 0x1c], ebx
// 0075ab03  3bf0                 cmp esi, eax
// 0075ab05  7510                 jne 0x75ab17
// 0075ab07  896804               mov dword ptr [eax + 4], ebp
// 0075ab0a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075ab0d  8928                 mov dword ptr [eax], ebp
// 0075ab0f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0075ab12  896908               mov dword ptr [ecx + 8], ebp
// 0075ab15  eb22                 jmp 0x75ab39
// 0075ab17  807c246800           cmp byte ptr [esp + 0x68], 0
// 0075ab1c  740d                 je 0x75ab2b
// 0075ab1e  892e                 mov dword ptr [esi], ebp
// 0075ab20  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075ab23  3b30                 cmp esi, dword ptr [eax]
// 0075ab25  7512                 jne 0x75ab39
// 0075ab27  8928                 mov dword ptr [eax], ebp
// 0075ab29  eb0e                 jmp 0x75ab39
// 0075ab2b  896e08               mov dword ptr [esi + 8], ebp
// 0075ab2e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0075ab31  3b7008               cmp esi, dword ptr [eax + 8]
// 0075ab34  7503                 jne 0x75ab39
// 0075ab36  896808               mov dword ptr [eax + 8], ebp
// 0075ab39  8b5504               mov edx, dword ptr [ebp + 4]
// 0075ab3c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0075ab40  8d4504               lea eax, [ebp + 4]
// 0075ab43  8bf5                 mov esi, ebp
// 0075ab45  0f85ea000000         jne 0x75ac35
// 0075ab4b  eb03                 jmp 0x75ab50
// 0075ab4d  8d4900               lea ecx, [ecx]
// 0075ab50  8b08                 mov ecx, dword ptr [eax]
// 0075ab52  8b5104               mov edx, dword ptr [ecx + 4]
// 0075ab55  3b0a                 cmp ecx, dword ptr [edx]
// 0075ab57  7551                 jne 0x75abaa
// 0075ab59  8b5208               mov edx, dword ptr [edx + 8]
// 0075ab5c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0075ab60  7519                 jne 0x75ab7b
// 0075ab62  88591c               mov byte ptr [ecx + 0x1c], bl
// 0075ab65  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075ab68  8b10                 mov edx, dword ptr [eax]
// 0075ab6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0075ab6d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0075ab71  8b10                 mov edx, dword ptr [eax]
// 0075ab73  8b7204               mov esi, dword ptr [edx + 4]
// 0075ab76  e9aa000000           jmp 0x75ac25
// 0075ab7b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0075ab7e  750a                 jne 0x75ab8a
// 0075ab80  8bf1                 mov esi, ecx
// 0075ab82  56                   push esi
// 0075ab83  8bcf                 mov ecx, edi
// 0075ab85  e886090000           call 0x75b510
// 0075ab8a  8b4604               mov eax, dword ptr [esi + 4]
// 0075ab8d  88581c               mov byte ptr [eax + 0x1c], bl
// 0075ab90  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075ab93  8b5104               mov edx, dword ptr [ecx + 4]
// 0075ab96  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0075ab9a  8b4604               mov eax, dword ptr [esi + 4]
// 0075ab9d  8b4804               mov ecx, dword ptr [eax + 4]
// 0075aba0  51                   push ecx
// 0075aba1  8bcf                 mov ecx, edi
// 0075aba3  e868abffff           call 0x755710
// 0075aba8  eb7b                 jmp 0x75ac25
// 0075abaa  8b12                 mov edx, dword ptr [edx]
// 0075abac  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 0075abb0  7516                 jne 0x75abc8
// 0075abb2  88591c               mov byte ptr [ecx + 0x1c], bl
// 0075abb5  885a1c               mov byte ptr [edx + 0x1c], bl
// 0075abb8  8b10                 mov edx, dword ptr [eax]
// 0075abba  8b4a04               mov ecx, dword ptr [edx + 4]
// 0075abbd  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 0075abc1  8b10                 mov edx, dword ptr [eax]
// 0075abc3  8b7204               mov esi, dword ptr [edx + 4]
// 0075abc6  eb5d                 jmp 0x75ac25
// 0075abc8  3b31                 cmp esi, dword ptr [ecx]
// 0075abca  750a                 jne 0x75abd6
// 0075abcc  8bf1                 mov esi, ecx
// 0075abce  56                   push esi
// 0075abcf  8bcf                 mov ecx, edi
// 0075abd1  e83aabffff           call 0x755710
// 0075abd6  8b4604               mov eax, dword ptr [esi + 4]
// 0075abd9  88581c               mov byte ptr [eax + 0x1c], bl
// 0075abdc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075abdf  8b5104               mov edx, dword ptr [ecx + 4]
// 0075abe2  c6421c00             mov byte ptr [edx + 0x1c], 0
// 0075abe6  8b4604               mov eax, dword ptr [esi + 4]
// 0075abe9  8b4004               mov eax, dword ptr [eax + 4]
// 0075abec  8b4808               mov ecx, dword ptr [eax + 8]
// 0075abef  8b11                 mov edx, dword ptr [ecx]
// 0075abf1  895008               mov dword ptr [eax + 8], edx
// 0075abf4  8b11                 mov edx, dword ptr [ecx]
// 0075abf6  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 0075abfa  7503                 jne 0x75abff
// 0075abfc  894204               mov dword ptr [edx + 4], eax
// 0075abff  8b5004               mov edx, dword ptr [eax + 4]
// 0075ac02  895104               mov dword ptr [ecx + 4], edx
// 0075ac05  8b5718               mov edx, dword ptr [edi + 0x18]
// 0075ac08  3b4204               cmp eax, dword ptr [edx + 4]
// 0075ac0b  7505                 jne 0x75ac12
// 0075ac0d  894a04               mov dword ptr [edx + 4], ecx
// 0075ac10  eb0e                 jmp 0x75ac20
// 0075ac12  8b5004               mov edx, dword ptr [eax + 4]
// 0075ac15  3b02                 cmp eax, dword ptr [edx]
// 0075ac17  7504                 jne 0x75ac1d
// 0075ac19  890a                 mov dword ptr [edx], ecx
// 0075ac1b  eb03                 jmp 0x75ac20
// 0075ac1d  894a08               mov dword ptr [edx + 8], ecx
// 0075ac20  8901                 mov dword ptr [ecx], eax
// 0075ac22  894804               mov dword ptr [eax + 4], ecx
// 0075ac25  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075ac28  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 0075ac2c  8d4604               lea eax, [esi + 4]
// 0075ac2f  0f841bffffff         je 0x75ab50
// 0075ac35  8b5718               mov edx, dword ptr [edi + 0x18]
// 0075ac38  8b4204               mov eax, dword ptr [edx + 4]
// 0075ac3b  88581c               mov byte ptr [eax + 0x1c], bl
// 0075ac3e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0075ac42  8b0f                 mov ecx, dword ptr [edi]
// 0075ac44  5e                   pop esi
// 0075ac45  896804               mov dword ptr [eax + 4], ebp
// 0075ac48  5d                   pop ebp
// 0075ac49  8908                 mov dword ptr [eax], ecx
// 0075ac4b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0075ac4f  5b                   pop ebx
// 0075ac50  5f                   pop edi
// 0075ac51  64890d00000000       mov dword ptr fs:[0], ecx
// 0075ac58  83c450               add esp, 0x50
// 0075ac5b  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
