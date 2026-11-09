// from server: 100% by auto
// roc 2008-06 00592aa0  unit: ArchiveBinder  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592aa0
//
// 00592aa0  64a100000000         mov eax, dword ptr fs:[0]
// 00592aa6  6aff                 push -1
// 00592aa8  6842e87d00           push 0x7de842
// 00592aad  50                   push eax
// 00592aae  64892500000000       mov dword ptr fs:[0], esp
// 00592ab5  83ec44               sub esp, 0x44
// 00592ab8  57                   push edi
// 00592ab9  8bf9                 mov edi, ecx
// 00592abb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00592ac2  7259                 jb 0x592b1d
// 00592ac4  688cb28000           push 0x80b28c
// 00592ac9  8d4c2408             lea ecx, [esp + 8]
// 00592acd  ff1558248000         call dword ptr [0x802458]
// 00592ad3  8d4c2420             lea ecx, [esp + 0x20]
// 00592ad7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00592adf  ff1598288000         call dword ptr [0x802898]
// 00592ae5  8d442404             lea eax, [esp + 4]
// 00592ae9  50                   push eax
// 00592aea  8d4c2430             lea ecx, [esp + 0x30]
// 00592aee  c644245401           mov byte ptr [esp + 0x54], 1
// 00592af3  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 00592afb  ff155c248000         call dword ptr [0x80245c]
// 00592b01  68c00c8d00           push 0x8d0cc0
// 00592b06  8d4c2424             lea ecx, [esp + 0x24]
// 00592b0a  51                   push ecx
// 00592b0b  c644245800           mov byte ptr [esp + 0x58], 0
// 00592b10  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00592b18  e86fea1000           call 0x6a158c
// 00592b1d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00592b21  8b4718               mov eax, dword ptr [edi + 0x18]
// 00592b24  53                   push ebx
// 00592b25  55                   push ebp
// 00592b26  56                   push esi
// 00592b27  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00592b2b  6a00                 push 0
// 00592b2d  52                   push edx
// 00592b2e  50                   push eax
// 00592b2f  56                   push esi
// 00592b30  50                   push eax
// 00592b31  e8dafeffff           call 0x592a10
// 00592b36  8be8                 mov ebp, eax
// 00592b38  8b4718               mov eax, dword ptr [edi + 0x18]
// 00592b3b  bb01000000           mov ebx, 1
// 00592b40  015f1c               add dword ptr [edi + 0x1c], ebx
// 00592b43  3bf0                 cmp esi, eax
// 00592b45  7510                 jne 0x592b57
// 00592b47  896804               mov dword ptr [eax + 4], ebp
// 00592b4a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00592b4d  8928                 mov dword ptr [eax], ebp
// 00592b4f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00592b52  896908               mov dword ptr [ecx + 8], ebp
// 00592b55  eb22                 jmp 0x592b79
// 00592b57  807c246800           cmp byte ptr [esp + 0x68], 0
// 00592b5c  740d                 je 0x592b6b
// 00592b5e  892e                 mov dword ptr [esi], ebp
// 00592b60  8b4718               mov eax, dword ptr [edi + 0x18]
// 00592b63  3b30                 cmp esi, dword ptr [eax]
// 00592b65  7512                 jne 0x592b79
// 00592b67  8928                 mov dword ptr [eax], ebp
// 00592b69  eb0e                 jmp 0x592b79
// 00592b6b  896e08               mov dword ptr [esi + 8], ebp
// 00592b6e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00592b71  3b7008               cmp esi, dword ptr [eax + 8]
// 00592b74  7503                 jne 0x592b79
// 00592b76  896808               mov dword ptr [eax + 8], ebp
// 00592b79  8b5504               mov edx, dword ptr [ebp + 4]
// 00592b7c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00592b80  8d4504               lea eax, [ebp + 4]
// 00592b83  8bf5                 mov esi, ebp
// 00592b85  0f85ea000000         jne 0x592c75
// 00592b8b  eb03                 jmp 0x592b90
// 00592b8d  8d4900               lea ecx, [ecx]
// 00592b90  8b08                 mov ecx, dword ptr [eax]
// 00592b92  8b5104               mov edx, dword ptr [ecx + 4]
// 00592b95  3b0a                 cmp ecx, dword ptr [edx]
// 00592b97  7551                 jne 0x592bea
// 00592b99  8b5208               mov edx, dword ptr [edx + 8]
// 00592b9c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00592ba0  7519                 jne 0x592bbb
// 00592ba2  885930               mov byte ptr [ecx + 0x30], bl
// 00592ba5  885a30               mov byte ptr [edx + 0x30], bl
// 00592ba8  8b10                 mov edx, dword ptr [eax]
// 00592baa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00592bad  c6413000             mov byte ptr [ecx + 0x30], 0
// 00592bb1  8b10                 mov edx, dword ptr [eax]
// 00592bb3  8b7204               mov esi, dword ptr [edx + 4]
// 00592bb6  e9aa000000           jmp 0x592c65
// 00592bbb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00592bbe  750a                 jne 0x592bca
// 00592bc0  8bf1                 mov esi, ecx
// 00592bc2  56                   push esi
// 00592bc3  8bcf                 mov ecx, edi
// 00592bc5  e866ecffff           call 0x591830
// 00592bca  8b4604               mov eax, dword ptr [esi + 4]
// 00592bcd  885830               mov byte ptr [eax + 0x30], bl
// 00592bd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00592bd3  8b5104               mov edx, dword ptr [ecx + 4]
// 00592bd6  c6423000             mov byte ptr [edx + 0x30], 0
// 00592bda  8b4604               mov eax, dword ptr [esi + 4]
// 00592bdd  8b4804               mov ecx, dword ptr [eax + 4]
// 00592be0  51                   push ecx
// 00592be1  8bcf                 mov ecx, edi
// 00592be3  e828e20b00           call 0x650e10
// 00592be8  eb7b                 jmp 0x592c65
// 00592bea  8b12                 mov edx, dword ptr [edx]
// 00592bec  807a3000             cmp byte ptr [edx + 0x30], 0
// 00592bf0  7516                 jne 0x592c08
// 00592bf2  885930               mov byte ptr [ecx + 0x30], bl
// 00592bf5  885a30               mov byte ptr [edx + 0x30], bl
// 00592bf8  8b10                 mov edx, dword ptr [eax]
// 00592bfa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00592bfd  c6413000             mov byte ptr [ecx + 0x30], 0
// 00592c01  8b10                 mov edx, dword ptr [eax]
// 00592c03  8b7204               mov esi, dword ptr [edx + 4]
// 00592c06  eb5d                 jmp 0x592c65
// 00592c08  3b31                 cmp esi, dword ptr [ecx]
// 00592c0a  750a                 jne 0x592c16
// 00592c0c  8bf1                 mov esi, ecx
// 00592c0e  56                   push esi
// 00592c0f  8bcf                 mov ecx, edi
// 00592c11  e8fae10b00           call 0x650e10
// 00592c16  8b4604               mov eax, dword ptr [esi + 4]
// 00592c19  885830               mov byte ptr [eax + 0x30], bl
// 00592c1c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00592c1f  8b5104               mov edx, dword ptr [ecx + 4]
// 00592c22  c6423000             mov byte ptr [edx + 0x30], 0
// 00592c26  8b4604               mov eax, dword ptr [esi + 4]
// 00592c29  8b4004               mov eax, dword ptr [eax + 4]
// 00592c2c  8b4808               mov ecx, dword ptr [eax + 8]
// 00592c2f  8b11                 mov edx, dword ptr [ecx]
// 00592c31  895008               mov dword ptr [eax + 8], edx
// 00592c34  8b11                 mov edx, dword ptr [ecx]
// 00592c36  807a3100             cmp byte ptr [edx + 0x31], 0
// 00592c3a  7503                 jne 0x592c3f
// 00592c3c  894204               mov dword ptr [edx + 4], eax
// 00592c3f  8b5004               mov edx, dword ptr [eax + 4]
// 00592c42  895104               mov dword ptr [ecx + 4], edx
// 00592c45  8b5718               mov edx, dword ptr [edi + 0x18]
// 00592c48  3b4204               cmp eax, dword ptr [edx + 4]
// 00592c4b  7505                 jne 0x592c52
// 00592c4d  894a04               mov dword ptr [edx + 4], ecx
// 00592c50  eb0e                 jmp 0x592c60
// 00592c52  8b5004               mov edx, dword ptr [eax + 4]
// 00592c55  3b02                 cmp eax, dword ptr [edx]
// 00592c57  7504                 jne 0x592c5d
// 00592c59  890a                 mov dword ptr [edx], ecx
// 00592c5b  eb03                 jmp 0x592c60
// 00592c5d  894a08               mov dword ptr [edx + 8], ecx
// 00592c60  8901                 mov dword ptr [ecx], eax
// 00592c62  894804               mov dword ptr [eax + 4], ecx
// 00592c65  8b4e04               mov ecx, dword ptr [esi + 4]
// 00592c68  80793000             cmp byte ptr [ecx + 0x30], 0
// 00592c6c  8d4604               lea eax, [esi + 4]
// 00592c6f  0f841bffffff         je 0x592b90
// 00592c75  8b5718               mov edx, dword ptr [edi + 0x18]
// 00592c78  8b4204               mov eax, dword ptr [edx + 4]
// 00592c7b  885830               mov byte ptr [eax + 0x30], bl
// 00592c7e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00592c82  8b0f                 mov ecx, dword ptr [edi]
// 00592c84  5e                   pop esi
// 00592c85  896804               mov dword ptr [eax + 4], ebp
// 00592c88  5d                   pop ebp
// 00592c89  8908                 mov dword ptr [eax], ecx
// 00592c8b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00592c8f  5b                   pop ebx
// 00592c90  5f                   pop edi
// 00592c91  64890d00000000       mov dword ptr fs:[0], ecx
// 00592c98  83c450               add esp, 0x50
// 00592c9b  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
