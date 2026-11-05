// from server: 100% by auto
// roc 2007-03 00618bc0  unit: seg_00610000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00618bc0
//
// 00618bc0  64a100000000         mov eax, dword ptr fs:[0]
// 00618bc6  6aff                 push -1
// 00618bc8  68926f7500           push 0x756f92
// 00618bcd  50                   push eax
// 00618bce  64892500000000       mov dword ptr fs:[0], esp
// 00618bd5  83ec44               sub esp, 0x44
// 00618bd8  57                   push edi
// 00618bd9  8bf9                 mov edi, ecx
// 00618bdb  817f0848922409       cmp dword ptr [edi + 8], 0x9249248
// 00618be2  7259                 jb 0x618c3d
// 00618be4  68903f7800           push 0x783f90
// 00618be9  8d4c2408             lea ecx, [esp + 8]
// 00618bed  ff1578e77700         call dword ptr [0x77e778]
// 00618bf3  8d4c2420             lea ecx, [esp + 0x20]
// 00618bf7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00618bff  ff1560e97700         call dword ptr [0x77e960]
// 00618c05  8d442404             lea eax, [esp + 4]
// 00618c09  50                   push eax
// 00618c0a  8d4c2430             lea ecx, [esp + 0x30]
// 00618c0e  c644245401           mov byte ptr [esp + 0x54], 1
// 00618c13  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 00618c1b  ff157ce77700         call dword ptr [0x77e77c]
// 00618c21  6870f78300           push 0x83f770
// 00618c26  8d4c2424             lea ecx, [esp + 0x24]
// 00618c2a  51                   push ecx
// 00618c2b  c644245800           mov byte ptr [esp + 0x58], 0
// 00618c30  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 00618c38  e8f1630000           call 0x61f02e
// 00618c3d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00618c41  8b4704               mov eax, dword ptr [edi + 4]
// 00618c44  53                   push ebx
// 00618c45  55                   push ebp
// 00618c46  56                   push esi
// 00618c47  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00618c4b  6a00                 push 0
// 00618c4d  52                   push edx
// 00618c4e  50                   push eax
// 00618c4f  56                   push esi
// 00618c50  50                   push eax
// 00618c51  e87afbffff           call 0x6187d0
// 00618c56  8be8                 mov ebp, eax
// 00618c58  8b4704               mov eax, dword ptr [edi + 4]
// 00618c5b  bb01000000           mov ebx, 1
// 00618c60  015f08               add dword ptr [edi + 8], ebx
// 00618c63  3bf0                 cmp esi, eax
// 00618c65  7510                 jne 0x618c77
// 00618c67  896804               mov dword ptr [eax + 4], ebp
// 00618c6a  8b4704               mov eax, dword ptr [edi + 4]
// 00618c6d  8928                 mov dword ptr [eax], ebp
// 00618c6f  8b4f04               mov ecx, dword ptr [edi + 4]
// 00618c72  896908               mov dword ptr [ecx + 8], ebp
// 00618c75  eb22                 jmp 0x618c99
// 00618c77  807c246800           cmp byte ptr [esp + 0x68], 0
// 00618c7c  740d                 je 0x618c8b
// 00618c7e  892e                 mov dword ptr [esi], ebp
// 00618c80  8b4704               mov eax, dword ptr [edi + 4]
// 00618c83  3b30                 cmp esi, dword ptr [eax]
// 00618c85  7512                 jne 0x618c99
// 00618c87  8928                 mov dword ptr [eax], ebp
// 00618c89  eb0e                 jmp 0x618c99
// 00618c8b  896e08               mov dword ptr [esi + 8], ebp
// 00618c8e  8b4704               mov eax, dword ptr [edi + 4]
// 00618c91  3b7008               cmp esi, dword ptr [eax + 8]
// 00618c94  7503                 jne 0x618c99
// 00618c96  896808               mov dword ptr [eax + 8], ebp
// 00618c99  8b5504               mov edx, dword ptr [ebp + 4]
// 00618c9c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00618ca0  8d4504               lea eax, [ebp + 4]
// 00618ca3  8bf5                 mov esi, ebp
// 00618ca5  0f85ea000000         jne 0x618d95
// 00618cab  eb03                 jmp 0x618cb0
// 00618cad  8d4900               lea ecx, [ecx]
// 00618cb0  8b08                 mov ecx, dword ptr [eax]
// 00618cb2  8b5104               mov edx, dword ptr [ecx + 4]
// 00618cb5  3b0a                 cmp ecx, dword ptr [edx]
// 00618cb7  7551                 jne 0x618d0a
// 00618cb9  8b5208               mov edx, dword ptr [edx + 8]
// 00618cbc  807a2800             cmp byte ptr [edx + 0x28], 0
// 00618cc0  7519                 jne 0x618cdb
// 00618cc2  885928               mov byte ptr [ecx + 0x28], bl
// 00618cc5  885a28               mov byte ptr [edx + 0x28], bl
// 00618cc8  8b10                 mov edx, dword ptr [eax]
// 00618cca  8b4a04               mov ecx, dword ptr [edx + 4]
// 00618ccd  c6412800             mov byte ptr [ecx + 0x28], 0
// 00618cd1  8b10                 mov edx, dword ptr [eax]
// 00618cd3  8b7204               mov esi, dword ptr [edx + 4]
// 00618cd6  e9aa000000           jmp 0x618d85
// 00618cdb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00618cde  750a                 jne 0x618cea
// 00618ce0  8bf1                 mov esi, ecx
// 00618ce2  56                   push esi
// 00618ce3  8bcf                 mov ecx, edi
// 00618ce5  e806bfeaff           call 0x4c4bf0
// 00618cea  8b4604               mov eax, dword ptr [esi + 4]
// 00618ced  885828               mov byte ptr [eax + 0x28], bl
// 00618cf0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618cf3  8b5104               mov edx, dword ptr [ecx + 4]
// 00618cf6  c6422800             mov byte ptr [edx + 0x28], 0
// 00618cfa  8b4604               mov eax, dword ptr [esi + 4]
// 00618cfd  8b4804               mov ecx, dword ptr [eax + 4]
// 00618d00  51                   push ecx
// 00618d01  8bcf                 mov ecx, edi
// 00618d03  e878b9eaff           call 0x4c4680
// 00618d08  eb7b                 jmp 0x618d85
// 00618d0a  8b12                 mov edx, dword ptr [edx]
// 00618d0c  807a2800             cmp byte ptr [edx + 0x28], 0
// 00618d10  7516                 jne 0x618d28
// 00618d12  885928               mov byte ptr [ecx + 0x28], bl
// 00618d15  885a28               mov byte ptr [edx + 0x28], bl
// 00618d18  8b10                 mov edx, dword ptr [eax]
// 00618d1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00618d1d  c6412800             mov byte ptr [ecx + 0x28], 0
// 00618d21  8b10                 mov edx, dword ptr [eax]
// 00618d23  8b7204               mov esi, dword ptr [edx + 4]
// 00618d26  eb5d                 jmp 0x618d85
// 00618d28  3b31                 cmp esi, dword ptr [ecx]
// 00618d2a  750a                 jne 0x618d36
// 00618d2c  8bf1                 mov esi, ecx
// 00618d2e  56                   push esi
// 00618d2f  8bcf                 mov ecx, edi
// 00618d31  e84ab9eaff           call 0x4c4680
// 00618d36  8b4604               mov eax, dword ptr [esi + 4]
// 00618d39  885828               mov byte ptr [eax + 0x28], bl
// 00618d3c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618d3f  8b5104               mov edx, dword ptr [ecx + 4]
// 00618d42  c6422800             mov byte ptr [edx + 0x28], 0
// 00618d46  8b4604               mov eax, dword ptr [esi + 4]
// 00618d49  8b4004               mov eax, dword ptr [eax + 4]
// 00618d4c  8b4808               mov ecx, dword ptr [eax + 8]
// 00618d4f  8b11                 mov edx, dword ptr [ecx]
// 00618d51  895008               mov dword ptr [eax + 8], edx
// 00618d54  8b11                 mov edx, dword ptr [ecx]
// 00618d56  807a2900             cmp byte ptr [edx + 0x29], 0
// 00618d5a  7503                 jne 0x618d5f
// 00618d5c  894204               mov dword ptr [edx + 4], eax
// 00618d5f  8b5004               mov edx, dword ptr [eax + 4]
// 00618d62  895104               mov dword ptr [ecx + 4], edx
// 00618d65  8b5704               mov edx, dword ptr [edi + 4]
// 00618d68  3b4204               cmp eax, dword ptr [edx + 4]
// 00618d6b  7505                 jne 0x618d72
// 00618d6d  894a04               mov dword ptr [edx + 4], ecx
// 00618d70  eb0e                 jmp 0x618d80
// 00618d72  8b5004               mov edx, dword ptr [eax + 4]
// 00618d75  3b02                 cmp eax, dword ptr [edx]
// 00618d77  7504                 jne 0x618d7d
// 00618d79  890a                 mov dword ptr [edx], ecx
// 00618d7b  eb03                 jmp 0x618d80
// 00618d7d  894a08               mov dword ptr [edx + 8], ecx
// 00618d80  8901                 mov dword ptr [ecx], eax
// 00618d82  894804               mov dword ptr [eax + 4], ecx
// 00618d85  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618d88  80792800             cmp byte ptr [ecx + 0x28], 0
// 00618d8c  8d4604               lea eax, [esi + 4]
// 00618d8f  0f841bffffff         je 0x618cb0
// 00618d95  8b5704               mov edx, dword ptr [edi + 4]
// 00618d98  8b4204               mov eax, dword ptr [edx + 4]
// 00618d9b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00618d9f  885828               mov byte ptr [eax + 0x28], bl
// 00618da2  8b442464             mov eax, dword ptr [esp + 0x64]
// 00618da6  5e                   pop esi
// 00618da7  896804               mov dword ptr [eax + 4], ebp
// 00618daa  5d                   pop ebp
// 00618dab  8938                 mov dword ptr [eax], edi
// 00618dad  5b                   pop ebx
// 00618dae  5f                   pop edi
// 00618daf  64890d00000000       mov dword ptr fs:[0], ecx
// 00618db6  83c450               add esp, 0x50
// 00618db9  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
