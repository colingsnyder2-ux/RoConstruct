// from server: 100% by auto
// roc 2010-06 00540980  unit: RBX::AggregatingSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00540980
//
// 00540980  64a100000000         mov eax, dword ptr fs:[0]
// 00540986  6aff                 push -1
// 00540988  68e22f9a00           push 0x9a2fe2
// 0054098d  50                   push eax
// 0054098e  64892500000000       mov dword ptr fs:[0], esp
// 00540995  83ec44               sub esp, 0x44
// 00540998  57                   push edi
// 00540999  8bf9                 mov edi, ecx
// 0054099b  817f1cfeffff0f       cmp dword ptr [edi + 0x1c], 0xffffffe
// 005409a2  7259                 jb 0x5409fd
// 005409a4  68a800a000           push 0xa000a8
// 005409a9  8d4c2408             lea ecx, [esp + 8]
// 005409ad  ff1510a49e00         call dword ptr [0x9ea410]
// 005409b3  8d4c2420             lea ecx, [esp + 0x20]
// 005409b7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005409bf  ff1518a99e00         call dword ptr [0x9ea918]
// 005409c5  8d442404             lea eax, [esp + 4]
// 005409c9  50                   push eax
// 005409ca  8d4c2430             lea ecx, [esp + 0x30]
// 005409ce  c644245401           mov byte ptr [esp + 0x54], 1
// 005409d3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005409db  ff150ca49e00         call dword ptr [0x9ea40c]
// 005409e1  68601bb000           push 0xb01b60
// 005409e6  8d4c2424             lea ecx, [esp + 0x24]
// 005409ea  51                   push ecx
// 005409eb  c644245800           mov byte ptr [esp + 0x58], 0
// 005409f0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005409f8  e8b57f2600           call 0x7a89b2
// 005409fd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00540a01  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540a04  53                   push ebx
// 00540a05  55                   push ebp
// 00540a06  56                   push esi
// 00540a07  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00540a0b  6a00                 push 0
// 00540a0d  52                   push edx
// 00540a0e  50                   push eax
// 00540a0f  56                   push esi
// 00540a10  50                   push eax
// 00540a11  e86afbffff           call 0x540580
// 00540a16  8be8                 mov ebp, eax
// 00540a18  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540a1b  bb01000000           mov ebx, 1
// 00540a20  015f1c               add dword ptr [edi + 0x1c], ebx
// 00540a23  3bf0                 cmp esi, eax
// 00540a25  7510                 jne 0x540a37
// 00540a27  896804               mov dword ptr [eax + 4], ebp
// 00540a2a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540a2d  8928                 mov dword ptr [eax], ebp
// 00540a2f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00540a32  896908               mov dword ptr [ecx + 8], ebp
// 00540a35  eb22                 jmp 0x540a59
// 00540a37  807c246800           cmp byte ptr [esp + 0x68], 0
// 00540a3c  740d                 je 0x540a4b
// 00540a3e  892e                 mov dword ptr [esi], ebp
// 00540a40  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540a43  3b30                 cmp esi, dword ptr [eax]
// 00540a45  7512                 jne 0x540a59
// 00540a47  8928                 mov dword ptr [eax], ebp
// 00540a49  eb0e                 jmp 0x540a59
// 00540a4b  896e08               mov dword ptr [esi + 8], ebp
// 00540a4e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540a51  3b7008               cmp esi, dword ptr [eax + 8]
// 00540a54  7503                 jne 0x540a59
// 00540a56  896808               mov dword ptr [eax + 8], ebp
// 00540a59  8b5504               mov edx, dword ptr [ebp + 4]
// 00540a5c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 00540a60  8d4504               lea eax, [ebp + 4]
// 00540a63  8bf5                 mov esi, ebp
// 00540a65  0f85ea000000         jne 0x540b55
// 00540a6b  eb03                 jmp 0x540a70
// 00540a6d  8d4900               lea ecx, [ecx]
// 00540a70  8b08                 mov ecx, dword ptr [eax]
// 00540a72  8b5104               mov edx, dword ptr [ecx + 4]
// 00540a75  3b0a                 cmp ecx, dword ptr [edx]
// 00540a77  7551                 jne 0x540aca
// 00540a79  8b5208               mov edx, dword ptr [edx + 8]
// 00540a7c  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 00540a80  7519                 jne 0x540a9b
// 00540a82  88591c               mov byte ptr [ecx + 0x1c], bl
// 00540a85  885a1c               mov byte ptr [edx + 0x1c], bl
// 00540a88  8b10                 mov edx, dword ptr [eax]
// 00540a8a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00540a8d  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 00540a91  8b10                 mov edx, dword ptr [eax]
// 00540a93  8b7204               mov esi, dword ptr [edx + 4]
// 00540a96  e9aa000000           jmp 0x540b45
// 00540a9b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00540a9e  750a                 jne 0x540aaa
// 00540aa0  8bf1                 mov esi, ecx
// 00540aa2  56                   push esi
// 00540aa3  8bcf                 mov ecx, edi
// 00540aa5  e866aa2100           call 0x75b510
// 00540aaa  8b4604               mov eax, dword ptr [esi + 4]
// 00540aad  88581c               mov byte ptr [eax + 0x1c], bl
// 00540ab0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00540ab3  8b5104               mov edx, dword ptr [ecx + 4]
// 00540ab6  c6421c00             mov byte ptr [edx + 0x1c], 0
// 00540aba  8b4604               mov eax, dword ptr [esi + 4]
// 00540abd  8b4804               mov ecx, dword ptr [eax + 4]
// 00540ac0  51                   push ecx
// 00540ac1  8bcf                 mov ecx, edi
// 00540ac3  e8484c2100           call 0x755710
// 00540ac8  eb7b                 jmp 0x540b45
// 00540aca  8b12                 mov edx, dword ptr [edx]
// 00540acc  807a1c00             cmp byte ptr [edx + 0x1c], 0
// 00540ad0  7516                 jne 0x540ae8
// 00540ad2  88591c               mov byte ptr [ecx + 0x1c], bl
// 00540ad5  885a1c               mov byte ptr [edx + 0x1c], bl
// 00540ad8  8b10                 mov edx, dword ptr [eax]
// 00540ada  8b4a04               mov ecx, dword ptr [edx + 4]
// 00540add  c6411c00             mov byte ptr [ecx + 0x1c], 0
// 00540ae1  8b10                 mov edx, dword ptr [eax]
// 00540ae3  8b7204               mov esi, dword ptr [edx + 4]
// 00540ae6  eb5d                 jmp 0x540b45
// 00540ae8  3b31                 cmp esi, dword ptr [ecx]
// 00540aea  750a                 jne 0x540af6
// 00540aec  8bf1                 mov esi, ecx
// 00540aee  56                   push esi
// 00540aef  8bcf                 mov ecx, edi
// 00540af1  e81a4c2100           call 0x755710
// 00540af6  8b4604               mov eax, dword ptr [esi + 4]
// 00540af9  88581c               mov byte ptr [eax + 0x1c], bl
// 00540afc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00540aff  8b5104               mov edx, dword ptr [ecx + 4]
// 00540b02  c6421c00             mov byte ptr [edx + 0x1c], 0
// 00540b06  8b4604               mov eax, dword ptr [esi + 4]
// 00540b09  8b4004               mov eax, dword ptr [eax + 4]
// 00540b0c  8b4808               mov ecx, dword ptr [eax + 8]
// 00540b0f  8b11                 mov edx, dword ptr [ecx]
// 00540b11  895008               mov dword ptr [eax + 8], edx
// 00540b14  8b11                 mov edx, dword ptr [ecx]
// 00540b16  807a1d00             cmp byte ptr [edx + 0x1d], 0
// 00540b1a  7503                 jne 0x540b1f
// 00540b1c  894204               mov dword ptr [edx + 4], eax
// 00540b1f  8b5004               mov edx, dword ptr [eax + 4]
// 00540b22  895104               mov dword ptr [ecx + 4], edx
// 00540b25  8b5718               mov edx, dword ptr [edi + 0x18]
// 00540b28  3b4204               cmp eax, dword ptr [edx + 4]
// 00540b2b  7505                 jne 0x540b32
// 00540b2d  894a04               mov dword ptr [edx + 4], ecx
// 00540b30  eb0e                 jmp 0x540b40
// 00540b32  8b5004               mov edx, dword ptr [eax + 4]
// 00540b35  3b02                 cmp eax, dword ptr [edx]
// 00540b37  7504                 jne 0x540b3d
// 00540b39  890a                 mov dword ptr [edx], ecx
// 00540b3b  eb03                 jmp 0x540b40
// 00540b3d  894a08               mov dword ptr [edx + 8], ecx
// 00540b40  8901                 mov dword ptr [ecx], eax
// 00540b42  894804               mov dword ptr [eax + 4], ecx
// 00540b45  8b4e04               mov ecx, dword ptr [esi + 4]
// 00540b48  80791c00             cmp byte ptr [ecx + 0x1c], 0
// 00540b4c  8d4604               lea eax, [esi + 4]
// 00540b4f  0f841bffffff         je 0x540a70
// 00540b55  8b5718               mov edx, dword ptr [edi + 0x18]
// 00540b58  8b4204               mov eax, dword ptr [edx + 4]
// 00540b5b  88581c               mov byte ptr [eax + 0x1c], bl
// 00540b5e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00540b62  8b0f                 mov ecx, dword ptr [edi]
// 00540b64  5e                   pop esi
// 00540b65  896804               mov dword ptr [eax + 4], ebp
// 00540b68  5d                   pop ebp
// 00540b69  8908                 mov dword ptr [eax], ecx
// 00540b6b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00540b6f  5b                   pop ebx
// 00540b70  5f                   pop edi
// 00540b71  64890d00000000       mov dword ptr fs:[0], ecx
// 00540b78  83c450               add esp, 0x50
// 00540b7b  c21000               ret 0x10
// standard library map_int<pod12> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
