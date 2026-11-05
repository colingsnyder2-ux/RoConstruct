// from server: 100% by auto
// roc 2010-06 006e99e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e99e0
//
// 006e99e0  64a100000000         mov eax, dword ptr fs:[0]
// 006e99e6  6aff                 push -1
// 006e99e8  68e22f9a00           push 0x9a2fe2
// 006e99ed  50                   push eax
// 006e99ee  64892500000000       mov dword ptr fs:[0], esp
// 006e99f5  83ec44               sub esp, 0x44
// 006e99f8  57                   push edi
// 006e99f9  8bf9                 mov edi, ecx
// 006e99fb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 006e9a02  7259                 jb 0x6e9a5d
// 006e9a04  68a800a000           push 0xa000a8
// 006e9a09  8d4c2408             lea ecx, [esp + 8]
// 006e9a0d  ff1510a49e00         call dword ptr [0x9ea410]
// 006e9a13  8d4c2420             lea ecx, [esp + 0x20]
// 006e9a17  c744245000000000     mov dword ptr [esp + 0x50], 0
// 006e9a1f  ff1518a99e00         call dword ptr [0x9ea918]
// 006e9a25  8d442404             lea eax, [esp + 4]
// 006e9a29  50                   push eax
// 006e9a2a  8d4c2430             lea ecx, [esp + 0x30]
// 006e9a2e  c644245401           mov byte ptr [esp + 0x54], 1
// 006e9a33  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 006e9a3b  ff150ca49e00         call dword ptr [0x9ea40c]
// 006e9a41  68601bb000           push 0xb01b60
// 006e9a46  8d4c2424             lea ecx, [esp + 0x24]
// 006e9a4a  51                   push ecx
// 006e9a4b  c644245800           mov byte ptr [esp + 0x58], 0
// 006e9a50  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 006e9a58  e855ef0b00           call 0x7a89b2
// 006e9a5d  8b542464             mov edx, dword ptr [esp + 0x64]
// 006e9a61  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e9a64  53                   push ebx
// 006e9a65  55                   push ebp
// 006e9a66  56                   push esi
// 006e9a67  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 006e9a6b  6a00                 push 0
// 006e9a6d  52                   push edx
// 006e9a6e  50                   push eax
// 006e9a6f  56                   push esi
// 006e9a70  50                   push eax
// 006e9a71  e84afaffff           call 0x6e94c0
// 006e9a76  8be8                 mov ebp, eax
// 006e9a78  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e9a7b  bb01000000           mov ebx, 1
// 006e9a80  015f1c               add dword ptr [edi + 0x1c], ebx
// 006e9a83  3bf0                 cmp esi, eax
// 006e9a85  7510                 jne 0x6e9a97
// 006e9a87  896804               mov dword ptr [eax + 4], ebp
// 006e9a8a  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e9a8d  8928                 mov dword ptr [eax], ebp
// 006e9a8f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006e9a92  896908               mov dword ptr [ecx + 8], ebp
// 006e9a95  eb22                 jmp 0x6e9ab9
// 006e9a97  807c246800           cmp byte ptr [esp + 0x68], 0
// 006e9a9c  740d                 je 0x6e9aab
// 006e9a9e  892e                 mov dword ptr [esi], ebp
// 006e9aa0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e9aa3  3b30                 cmp esi, dword ptr [eax]
// 006e9aa5  7512                 jne 0x6e9ab9
// 006e9aa7  8928                 mov dword ptr [eax], ebp
// 006e9aa9  eb0e                 jmp 0x6e9ab9
// 006e9aab  896e08               mov dword ptr [esi + 8], ebp
// 006e9aae  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e9ab1  3b7008               cmp esi, dword ptr [eax + 8]
// 006e9ab4  7503                 jne 0x6e9ab9
// 006e9ab6  896808               mov dword ptr [eax + 8], ebp
// 006e9ab9  8b5504               mov edx, dword ptr [ebp + 4]
// 006e9abc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e9ac0  8d4504               lea eax, [ebp + 4]
// 006e9ac3  8bf5                 mov esi, ebp
// 006e9ac5  0f85ea000000         jne 0x6e9bb5
// 006e9acb  eb03                 jmp 0x6e9ad0
// 006e9acd  8d4900               lea ecx, [ecx]
// 006e9ad0  8b08                 mov ecx, dword ptr [eax]
// 006e9ad2  8b5104               mov edx, dword ptr [ecx + 4]
// 006e9ad5  3b0a                 cmp ecx, dword ptr [edx]
// 006e9ad7  7551                 jne 0x6e9b2a
// 006e9ad9  8b5208               mov edx, dword ptr [edx + 8]
// 006e9adc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e9ae0  7519                 jne 0x6e9afb
// 006e9ae2  885930               mov byte ptr [ecx + 0x30], bl
// 006e9ae5  885a30               mov byte ptr [edx + 0x30], bl
// 006e9ae8  8b10                 mov edx, dword ptr [eax]
// 006e9aea  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e9aed  c6413000             mov byte ptr [ecx + 0x30], 0
// 006e9af1  8b10                 mov edx, dword ptr [eax]
// 006e9af3  8b7204               mov esi, dword ptr [edx + 4]
// 006e9af6  e9aa000000           jmp 0x6e9ba5
// 006e9afb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006e9afe  750a                 jne 0x6e9b0a
// 006e9b00  8bf1                 mov esi, ecx
// 006e9b02  56                   push esi
// 006e9b03  8bcf                 mov ecx, edi
// 006e9b05  e8165af7ff           call 0x65f520
// 006e9b0a  8b4604               mov eax, dword ptr [esi + 4]
// 006e9b0d  885830               mov byte ptr [eax + 0x30], bl
// 006e9b10  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e9b13  8b5104               mov edx, dword ptr [ecx + 4]
// 006e9b16  c6423000             mov byte ptr [edx + 0x30], 0
// 006e9b1a  8b4604               mov eax, dword ptr [esi + 4]
// 006e9b1d  8b4804               mov ecx, dword ptr [eax + 4]
// 006e9b20  51                   push ecx
// 006e9b21  8bcf                 mov ecx, edi
// 006e9b23  e82863ddff           call 0x4bfe50
// 006e9b28  eb7b                 jmp 0x6e9ba5
// 006e9b2a  8b12                 mov edx, dword ptr [edx]
// 006e9b2c  807a3000             cmp byte ptr [edx + 0x30], 0
// 006e9b30  7516                 jne 0x6e9b48
// 006e9b32  885930               mov byte ptr [ecx + 0x30], bl
// 006e9b35  885a30               mov byte ptr [edx + 0x30], bl
// 006e9b38  8b10                 mov edx, dword ptr [eax]
// 006e9b3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 006e9b3d  c6413000             mov byte ptr [ecx + 0x30], 0
// 006e9b41  8b10                 mov edx, dword ptr [eax]
// 006e9b43  8b7204               mov esi, dword ptr [edx + 4]
// 006e9b46  eb5d                 jmp 0x6e9ba5
// 006e9b48  3b31                 cmp esi, dword ptr [ecx]
// 006e9b4a  750a                 jne 0x6e9b56
// 006e9b4c  8bf1                 mov esi, ecx
// 006e9b4e  56                   push esi
// 006e9b4f  8bcf                 mov ecx, edi
// 006e9b51  e8fa62ddff           call 0x4bfe50
// 006e9b56  8b4604               mov eax, dword ptr [esi + 4]
// 006e9b59  885830               mov byte ptr [eax + 0x30], bl
// 006e9b5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e9b5f  8b5104               mov edx, dword ptr [ecx + 4]
// 006e9b62  c6423000             mov byte ptr [edx + 0x30], 0
// 006e9b66  8b4604               mov eax, dword ptr [esi + 4]
// 006e9b69  8b4004               mov eax, dword ptr [eax + 4]
// 006e9b6c  8b4808               mov ecx, dword ptr [eax + 8]
// 006e9b6f  8b11                 mov edx, dword ptr [ecx]
// 006e9b71  895008               mov dword ptr [eax + 8], edx
// 006e9b74  8b11                 mov edx, dword ptr [ecx]
// 006e9b76  807a3100             cmp byte ptr [edx + 0x31], 0
// 006e9b7a  7503                 jne 0x6e9b7f
// 006e9b7c  894204               mov dword ptr [edx + 4], eax
// 006e9b7f  8b5004               mov edx, dword ptr [eax + 4]
// 006e9b82  895104               mov dword ptr [ecx + 4], edx
// 006e9b85  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e9b88  3b4204               cmp eax, dword ptr [edx + 4]
// 006e9b8b  7505                 jne 0x6e9b92
// 006e9b8d  894a04               mov dword ptr [edx + 4], ecx
// 006e9b90  eb0e                 jmp 0x6e9ba0
// 006e9b92  8b5004               mov edx, dword ptr [eax + 4]
// 006e9b95  3b02                 cmp eax, dword ptr [edx]
// 006e9b97  7504                 jne 0x6e9b9d
// 006e9b99  890a                 mov dword ptr [edx], ecx
// 006e9b9b  eb03                 jmp 0x6e9ba0
// 006e9b9d  894a08               mov dword ptr [edx + 8], ecx
// 006e9ba0  8901                 mov dword ptr [ecx], eax
// 006e9ba2  894804               mov dword ptr [eax + 4], ecx
// 006e9ba5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006e9ba8  80793000             cmp byte ptr [ecx + 0x30], 0
// 006e9bac  8d4604               lea eax, [esi + 4]
// 006e9baf  0f841bffffff         je 0x6e9ad0
// 006e9bb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006e9bb8  8b4204               mov eax, dword ptr [edx + 4]
// 006e9bbb  885830               mov byte ptr [eax + 0x30], bl
// 006e9bbe  8b442464             mov eax, dword ptr [esp + 0x64]
// 006e9bc2  8b0f                 mov ecx, dword ptr [edi]
// 006e9bc4  5e                   pop esi
// 006e9bc5  896804               mov dword ptr [eax + 4], ebp
// 006e9bc8  5d                   pop ebp
// 006e9bc9  8908                 mov dword ptr [eax], ecx
// 006e9bcb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006e9bcf  5b                   pop ebx
// 006e9bd0  5f                   pop edi
// 006e9bd1  64890d00000000       mov dword ptr fs:[0], ecx
// 006e9bd8  83c450               add esp, 0x50
// 006e9bdb  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
