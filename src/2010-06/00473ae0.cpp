// from server: 100% by auto
// roc 2010-06 00473ae0  unit: CRobloxScriptReviewPaneView  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00473ae0
//
// 00473ae0  64a100000000         mov eax, dword ptr fs:[0]
// 00473ae6  6aff                 push -1
// 00473ae8  68e22f9a00           push 0x9a2fe2
// 00473aed  50                   push eax
// 00473aee  64892500000000       mov dword ptr fs:[0], esp
// 00473af5  83ec44               sub esp, 0x44
// 00473af8  57                   push edi
// 00473af9  8bf9                 mov edi, ecx
// 00473afb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00473b02  7259                 jb 0x473b5d
// 00473b04  68a800a000           push 0xa000a8
// 00473b09  8d4c2408             lea ecx, [esp + 8]
// 00473b0d  ff1510a49e00         call dword ptr [0x9ea410]
// 00473b13  8d4c2420             lea ecx, [esp + 0x20]
// 00473b17  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00473b1f  ff1518a99e00         call dword ptr [0x9ea918]
// 00473b25  8d442404             lea eax, [esp + 4]
// 00473b29  50                   push eax
// 00473b2a  8d4c2430             lea ecx, [esp + 0x30]
// 00473b2e  c644245401           mov byte ptr [esp + 0x54], 1
// 00473b33  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00473b3b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00473b41  68601bb000           push 0xb01b60
// 00473b46  8d4c2424             lea ecx, [esp + 0x24]
// 00473b4a  51                   push ecx
// 00473b4b  c644245800           mov byte ptr [esp + 0x58], 0
// 00473b50  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00473b58  e8554e3300           call 0x7a89b2
// 00473b5d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00473b61  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473b64  53                   push ebx
// 00473b65  55                   push ebp
// 00473b66  56                   push esi
// 00473b67  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00473b6b  6a00                 push 0
// 00473b6d  52                   push edx
// 00473b6e  50                   push eax
// 00473b6f  56                   push esi
// 00473b70  50                   push eax
// 00473b71  e81a7b1e00           call 0x65b690
// 00473b76  8be8                 mov ebp, eax
// 00473b78  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473b7b  bb01000000           mov ebx, 1
// 00473b80  015f1c               add dword ptr [edi + 0x1c], ebx
// 00473b83  3bf0                 cmp esi, eax
// 00473b85  7510                 jne 0x473b97
// 00473b87  896804               mov dword ptr [eax + 4], ebp
// 00473b8a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473b8d  8928                 mov dword ptr [eax], ebp
// 00473b8f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00473b92  896908               mov dword ptr [ecx + 8], ebp
// 00473b95  eb22                 jmp 0x473bb9
// 00473b97  807c246800           cmp byte ptr [esp + 0x68], 0
// 00473b9c  740d                 je 0x473bab
// 00473b9e  892e                 mov dword ptr [esi], ebp
// 00473ba0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473ba3  3b30                 cmp esi, dword ptr [eax]
// 00473ba5  7512                 jne 0x473bb9
// 00473ba7  8928                 mov dword ptr [eax], ebp
// 00473ba9  eb0e                 jmp 0x473bb9
// 00473bab  896e08               mov dword ptr [esi + 8], ebp
// 00473bae  8b4718               mov eax, dword ptr [edi + 0x18]
// 00473bb1  3b7008               cmp esi, dword ptr [eax + 8]
// 00473bb4  7503                 jne 0x473bb9
// 00473bb6  896808               mov dword ptr [eax + 8], ebp
// 00473bb9  8b5504               mov edx, dword ptr [ebp + 4]
// 00473bbc  807a3000             cmp byte ptr [edx + 0x30], 0
// 00473bc0  8d4504               lea eax, [ebp + 4]
// 00473bc3  8bf5                 mov esi, ebp
// 00473bc5  0f85ea000000         jne 0x473cb5
// 00473bcb  eb03                 jmp 0x473bd0
// 00473bcd  8d4900               lea ecx, [ecx]
// 00473bd0  8b08                 mov ecx, dword ptr [eax]
// 00473bd2  8b5104               mov edx, dword ptr [ecx + 4]
// 00473bd5  3b0a                 cmp ecx, dword ptr [edx]
// 00473bd7  7551                 jne 0x473c2a
// 00473bd9  8b5208               mov edx, dword ptr [edx + 8]
// 00473bdc  807a3000             cmp byte ptr [edx + 0x30], 0
// 00473be0  7519                 jne 0x473bfb
// 00473be2  885930               mov byte ptr [ecx + 0x30], bl
// 00473be5  885a30               mov byte ptr [edx + 0x30], bl
// 00473be8  8b10                 mov edx, dword ptr [eax]
// 00473bea  8b4a04               mov ecx, dword ptr [edx + 4]
// 00473bed  c6413000             mov byte ptr [ecx + 0x30], 0
// 00473bf1  8b10                 mov edx, dword ptr [eax]
// 00473bf3  8b7204               mov esi, dword ptr [edx + 4]
// 00473bf6  e9aa000000           jmp 0x473ca5
// 00473bfb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00473bfe  750a                 jne 0x473c0a
// 00473c00  8bf1                 mov esi, ecx
// 00473c02  56                   push esi
// 00473c03  8bcf                 mov ecx, edi
// 00473c05  e816b91e00           call 0x65f520
// 00473c0a  8b4604               mov eax, dword ptr [esi + 4]
// 00473c0d  885830               mov byte ptr [eax + 0x30], bl
// 00473c10  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473c13  8b5104               mov edx, dword ptr [ecx + 4]
// 00473c16  c6423000             mov byte ptr [edx + 0x30], 0
// 00473c1a  8b4604               mov eax, dword ptr [esi + 4]
// 00473c1d  8b4804               mov ecx, dword ptr [eax + 4]
// 00473c20  51                   push ecx
// 00473c21  8bcf                 mov ecx, edi
// 00473c23  e828c20400           call 0x4bfe50
// 00473c28  eb7b                 jmp 0x473ca5
// 00473c2a  8b12                 mov edx, dword ptr [edx]
// 00473c2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00473c30  7516                 jne 0x473c48
// 00473c32  885930               mov byte ptr [ecx + 0x30], bl
// 00473c35  885a30               mov byte ptr [edx + 0x30], bl
// 00473c38  8b10                 mov edx, dword ptr [eax]
// 00473c3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00473c3d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00473c41  8b10                 mov edx, dword ptr [eax]
// 00473c43  8b7204               mov esi, dword ptr [edx + 4]
// 00473c46  eb5d                 jmp 0x473ca5
// 00473c48  3b31                 cmp esi, dword ptr [ecx]
// 00473c4a  750a                 jne 0x473c56
// 00473c4c  8bf1                 mov esi, ecx
// 00473c4e  56                   push esi
// 00473c4f  8bcf                 mov ecx, edi
// 00473c51  e8fac10400           call 0x4bfe50
// 00473c56  8b4604               mov eax, dword ptr [esi + 4]
// 00473c59  885830               mov byte ptr [eax + 0x30], bl
// 00473c5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473c5f  8b5104               mov edx, dword ptr [ecx + 4]
// 00473c62  c6423000             mov byte ptr [edx + 0x30], 0
// 00473c66  8b4604               mov eax, dword ptr [esi + 4]
// 00473c69  8b4004               mov eax, dword ptr [eax + 4]
// 00473c6c  8b4808               mov ecx, dword ptr [eax + 8]
// 00473c6f  8b11                 mov edx, dword ptr [ecx]
// 00473c71  895008               mov dword ptr [eax + 8], edx
// 00473c74  8b11                 mov edx, dword ptr [ecx]
// 00473c76  807a3100             cmp byte ptr [edx + 0x31], 0
// 00473c7a  7503                 jne 0x473c7f
// 00473c7c  894204               mov dword ptr [edx + 4], eax
// 00473c7f  8b5004               mov edx, dword ptr [eax + 4]
// 00473c82  895104               mov dword ptr [ecx + 4], edx
// 00473c85  8b5718               mov edx, dword ptr [edi + 0x18]
// 00473c88  3b4204               cmp eax, dword ptr [edx + 4]
// 00473c8b  7505                 jne 0x473c92
// 00473c8d  894a04               mov dword ptr [edx + 4], ecx
// 00473c90  eb0e                 jmp 0x473ca0
// 00473c92  8b5004               mov edx, dword ptr [eax + 4]
// 00473c95  3b02                 cmp eax, dword ptr [edx]
// 00473c97  7504                 jne 0x473c9d
// 00473c99  890a                 mov dword ptr [edx], ecx
// 00473c9b  eb03                 jmp 0x473ca0
// 00473c9d  894a08               mov dword ptr [edx + 8], ecx
// 00473ca0  8901                 mov dword ptr [ecx], eax
// 00473ca2  894804               mov dword ptr [eax + 4], ecx
// 00473ca5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00473ca8  80793000             cmp byte ptr [ecx + 0x30], 0
// 00473cac  8d4604               lea eax, [esi + 4]
// 00473caf  0f841bffffff         je 0x473bd0
// 00473cb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00473cb8  8b4204               mov eax, dword ptr [edx + 4]
// 00473cbb  885830               mov byte ptr [eax + 0x30], bl
// 00473cbe  8b442464             mov eax, dword ptr [esp + 0x64]
// 00473cc2  8b0f                 mov ecx, dword ptr [edi]
// 00473cc4  5e                   pop esi
// 00473cc5  896804               mov dword ptr [eax + 4], ebp
// 00473cc8  5d                   pop ebp
// 00473cc9  8908                 mov dword ptr [eax], ecx
// 00473ccb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00473ccf  5b                   pop ebx
// 00473cd0  5f                   pop edi
// 00473cd1  64890d00000000       mov dword ptr fs:[0], ecx
// 00473cd8  83c450               add esp, 0x50
// 00473cdb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
