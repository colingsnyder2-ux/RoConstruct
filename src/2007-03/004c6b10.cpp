// from server: 100% by auto
// roc 2007-03 004c6b10  unit: seg_004c0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004c6b10
//
// 004c6b10  64a100000000         mov eax, dword ptr fs:[0]
// 004c6b16  6aff                 push -1
// 004c6b18  68926f7500           push 0x756f92
// 004c6b1d  50                   push eax
// 004c6b1e  64892500000000       mov dword ptr fs:[0], esp
// 004c6b25  83ec44               sub esp, 0x44
// 004c6b28  57                   push edi
// 004c6b29  8bf9                 mov edi, ecx
// 004c6b2b  817f08cbcccc0c       cmp dword ptr [edi + 8], 0xccccccb
// 004c6b32  7259                 jb 0x4c6b8d
// 004c6b34  68903f7800           push 0x783f90
// 004c6b39  8d4c2408             lea ecx, [esp + 8]
// 004c6b3d  ff1578e77700         call dword ptr [0x77e778]
// 004c6b43  8d4c2420             lea ecx, [esp + 0x20]
// 004c6b47  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004c6b4f  ff1560e97700         call dword ptr [0x77e960]
// 004c6b55  8d442404             lea eax, [esp + 4]
// 004c6b59  50                   push eax
// 004c6b5a  8d4c2430             lea ecx, [esp + 0x30]
// 004c6b5e  c644245401           mov byte ptr [esp + 0x54], 1
// 004c6b63  c7442424383e7800     mov dword ptr [esp + 0x24], 0x783e38
// 004c6b6b  ff157ce77700         call dword ptr [0x77e77c]
// 004c6b71  6870f78300           push 0x83f770
// 004c6b76  8d4c2424             lea ecx, [esp + 0x24]
// 004c6b7a  51                   push ecx
// 004c6b7b  c644245800           mov byte ptr [esp + 0x58], 0
// 004c6b80  c7442428443e7800     mov dword ptr [esp + 0x28], 0x783e44
// 004c6b88  e8a1841500           call 0x61f02e
// 004c6b8d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004c6b91  8b4704               mov eax, dword ptr [edi + 4]
// 004c6b94  53                   push ebx
// 004c6b95  55                   push ebp
// 004c6b96  56                   push esi
// 004c6b97  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004c6b9b  6a00                 push 0
// 004c6b9d  52                   push edx
// 004c6b9e  50                   push eax
// 004c6b9f  56                   push esi
// 004c6ba0  50                   push eax
// 004c6ba1  e80afaffff           call 0x4c65b0
// 004c6ba6  8be8                 mov ebp, eax
// 004c6ba8  8b4704               mov eax, dword ptr [edi + 4]
// 004c6bab  bb01000000           mov ebx, 1
// 004c6bb0  015f08               add dword ptr [edi + 8], ebx
// 004c6bb3  3bf0                 cmp esi, eax
// 004c6bb5  7510                 jne 0x4c6bc7
// 004c6bb7  896804               mov dword ptr [eax + 4], ebp
// 004c6bba  8b4704               mov eax, dword ptr [edi + 4]
// 004c6bbd  8928                 mov dword ptr [eax], ebp
// 004c6bbf  8b4f04               mov ecx, dword ptr [edi + 4]
// 004c6bc2  896908               mov dword ptr [ecx + 8], ebp
// 004c6bc5  eb22                 jmp 0x4c6be9
// 004c6bc7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004c6bcc  740d                 je 0x4c6bdb
// 004c6bce  892e                 mov dword ptr [esi], ebp
// 004c6bd0  8b4704               mov eax, dword ptr [edi + 4]
// 004c6bd3  3b30                 cmp esi, dword ptr [eax]
// 004c6bd5  7512                 jne 0x4c6be9
// 004c6bd7  8928                 mov dword ptr [eax], ebp
// 004c6bd9  eb0e                 jmp 0x4c6be9
// 004c6bdb  896e08               mov dword ptr [esi + 8], ebp
// 004c6bde  8b4704               mov eax, dword ptr [edi + 4]
// 004c6be1  3b7008               cmp esi, dword ptr [eax + 8]
// 004c6be4  7503                 jne 0x4c6be9
// 004c6be6  896808               mov dword ptr [eax + 8], ebp
// 004c6be9  8b5504               mov edx, dword ptr [ebp + 4]
// 004c6bec  807a2000             cmp byte ptr [edx + 0x20], 0
// 004c6bf0  8d4504               lea eax, [ebp + 4]
// 004c6bf3  8bf5                 mov esi, ebp
// 004c6bf5  0f85ea000000         jne 0x4c6ce5
// 004c6bfb  eb03                 jmp 0x4c6c00
// 004c6bfd  8d4900               lea ecx, [ecx]
// 004c6c00  8b08                 mov ecx, dword ptr [eax]
// 004c6c02  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6c05  3b0a                 cmp ecx, dword ptr [edx]
// 004c6c07  7551                 jne 0x4c6c5a
// 004c6c09  8b5208               mov edx, dword ptr [edx + 8]
// 004c6c0c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004c6c10  7519                 jne 0x4c6c2b
// 004c6c12  885920               mov byte ptr [ecx + 0x20], bl
// 004c6c15  885a20               mov byte ptr [edx + 0x20], bl
// 004c6c18  8b10                 mov edx, dword ptr [eax]
// 004c6c1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6c1d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004c6c21  8b10                 mov edx, dword ptr [eax]
// 004c6c23  8b7204               mov esi, dword ptr [edx + 4]
// 004c6c26  e9aa000000           jmp 0x4c6cd5
// 004c6c2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004c6c2e  750a                 jne 0x4c6c3a
// 004c6c30  8bf1                 mov esi, ecx
// 004c6c32  56                   push esi
// 004c6c33  8bcf                 mov ecx, edi
// 004c6c35  e8a6b7ffff           call 0x4c23e0
// 004c6c3a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c3d  885820               mov byte ptr [eax + 0x20], bl
// 004c6c40  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6c43  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6c46  c6422000             mov byte ptr [edx + 0x20], 0
// 004c6c4a  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c4d  8b4804               mov ecx, dword ptr [eax + 4]
// 004c6c50  51                   push ecx
// 004c6c51  8bcf                 mov ecx, edi
// 004c6c53  e8282af7ff           call 0x439680
// 004c6c58  eb7b                 jmp 0x4c6cd5
// 004c6c5a  8b12                 mov edx, dword ptr [edx]
// 004c6c5c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004c6c60  7516                 jne 0x4c6c78
// 004c6c62  885920               mov byte ptr [ecx + 0x20], bl
// 004c6c65  885a20               mov byte ptr [edx + 0x20], bl
// 004c6c68  8b10                 mov edx, dword ptr [eax]
// 004c6c6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004c6c6d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004c6c71  8b10                 mov edx, dword ptr [eax]
// 004c6c73  8b7204               mov esi, dword ptr [edx + 4]
// 004c6c76  eb5d                 jmp 0x4c6cd5
// 004c6c78  3b31                 cmp esi, dword ptr [ecx]
// 004c6c7a  750a                 jne 0x4c6c86
// 004c6c7c  8bf1                 mov esi, ecx
// 004c6c7e  56                   push esi
// 004c6c7f  8bcf                 mov ecx, edi
// 004c6c81  e8fa29f7ff           call 0x439680
// 004c6c86  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c89  885820               mov byte ptr [eax + 0x20], bl
// 004c6c8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6c8f  8b5104               mov edx, dword ptr [ecx + 4]
// 004c6c92  c6422000             mov byte ptr [edx + 0x20], 0
// 004c6c96  8b4604               mov eax, dword ptr [esi + 4]
// 004c6c99  8b4004               mov eax, dword ptr [eax + 4]
// 004c6c9c  8b4808               mov ecx, dword ptr [eax + 8]
// 004c6c9f  8b11                 mov edx, dword ptr [ecx]
// 004c6ca1  895008               mov dword ptr [eax + 8], edx
// 004c6ca4  8b11                 mov edx, dword ptr [ecx]
// 004c6ca6  807a2100             cmp byte ptr [edx + 0x21], 0
// 004c6caa  7503                 jne 0x4c6caf
// 004c6cac  894204               mov dword ptr [edx + 4], eax
// 004c6caf  8b5004               mov edx, dword ptr [eax + 4]
// 004c6cb2  895104               mov dword ptr [ecx + 4], edx
// 004c6cb5  8b5704               mov edx, dword ptr [edi + 4]
// 004c6cb8  3b4204               cmp eax, dword ptr [edx + 4]
// 004c6cbb  7505                 jne 0x4c6cc2
// 004c6cbd  894a04               mov dword ptr [edx + 4], ecx
// 004c6cc0  eb0e                 jmp 0x4c6cd0
// 004c6cc2  8b5004               mov edx, dword ptr [eax + 4]
// 004c6cc5  3b02                 cmp eax, dword ptr [edx]
// 004c6cc7  7504                 jne 0x4c6ccd
// 004c6cc9  890a                 mov dword ptr [edx], ecx
// 004c6ccb  eb03                 jmp 0x4c6cd0
// 004c6ccd  894a08               mov dword ptr [edx + 8], ecx
// 004c6cd0  8901                 mov dword ptr [ecx], eax
// 004c6cd2  894804               mov dword ptr [eax + 4], ecx
// 004c6cd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c6cd8  80792000             cmp byte ptr [ecx + 0x20], 0
// 004c6cdc  8d4604               lea eax, [esi + 4]
// 004c6cdf  0f841bffffff         je 0x4c6c00
// 004c6ce5  8b5704               mov edx, dword ptr [edi + 4]
// 004c6ce8  8b4204               mov eax, dword ptr [edx + 4]
// 004c6ceb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004c6cef  885820               mov byte ptr [eax + 0x20], bl
// 004c6cf2  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c6cf6  5e                   pop esi
// 004c6cf7  896804               mov dword ptr [eax + 4], ebp
// 004c6cfa  5d                   pop ebp
// 004c6cfb  8938                 mov dword ptr [eax], edi
// 004c6cfd  5b                   pop ebx
// 004c6cfe  5f                   pop edi
// 004c6cff  64890d00000000       mov dword ptr fs:[0], ecx
// 004c6d06  83c450               add esp, 0x50
// 004c6d09  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
