// from server: 100% by auto
// roc 2010-06 006634e0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006634e0
//
// 006634e0  64a100000000         mov eax, dword ptr fs:[0]
// 006634e6  6aff                 push -1
// 006634e8  68e22f9a00           push 0x9a2fe2
// 006634ed  50                   push eax
// 006634ee  64892500000000       mov dword ptr fs:[0], esp
// 006634f5  83ec44               sub esp, 0x44
// 006634f8  57                   push edi
// 006634f9  8bf9                 mov edi, ecx
// 006634fb  817f1cc6711c07       cmp dword ptr [edi + 0x1c], 0x71c71c6
// 00663502  7259                 jb 0x66355d
// 00663504  68a800a000           push 0xa000a8
// 00663509  8d4c2408             lea ecx, [esp + 8]
// 0066350d  ff1510a49e00         call dword ptr [0x9ea410]
// 00663513  8d4c2420             lea ecx, [esp + 0x20]
// 00663517  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0066351f  ff1518a99e00         call dword ptr [0x9ea918]
// 00663525  8d442404             lea eax, [esp + 4]
// 00663529  50                   push eax
// 0066352a  8d4c2430             lea ecx, [esp + 0x30]
// 0066352e  c644245401           mov byte ptr [esp + 0x54], 1
// 00663533  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0066353b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00663541  68601bb000           push 0xb01b60
// 00663546  8d4c2424             lea ecx, [esp + 0x24]
// 0066354a  51                   push ecx
// 0066354b  c644245800           mov byte ptr [esp + 0x58], 0
// 00663550  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00663558  e855541400           call 0x7a89b2
// 0066355d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00663561  8b4718               mov eax, dword ptr [edi + 0x18]
// 00663564  53                   push ebx
// 00663565  55                   push ebp
// 00663566  56                   push esi
// 00663567  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0066356b  6a00                 push 0
// 0066356d  52                   push edx
// 0066356e  50                   push eax
// 0066356f  56                   push esi
// 00663570  50                   push eax
// 00663571  e8aaf6ffff           call 0x662c20
// 00663576  8be8                 mov ebp, eax
// 00663578  8b4718               mov eax, dword ptr [edi + 0x18]
// 0066357b  bb01000000           mov ebx, 1
// 00663580  015f1c               add dword ptr [edi + 0x1c], ebx
// 00663583  3bf0                 cmp esi, eax
// 00663585  7510                 jne 0x663597
// 00663587  896804               mov dword ptr [eax + 4], ebp
// 0066358a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0066358d  8928                 mov dword ptr [eax], ebp
// 0066358f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00663592  896908               mov dword ptr [ecx + 8], ebp
// 00663595  eb22                 jmp 0x6635b9
// 00663597  807c246800           cmp byte ptr [esp + 0x68], 0
// 0066359c  740d                 je 0x6635ab
// 0066359e  892e                 mov dword ptr [esi], ebp
// 006635a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006635a3  3b30                 cmp esi, dword ptr [eax]
// 006635a5  7512                 jne 0x6635b9
// 006635a7  8928                 mov dword ptr [eax], ebp
// 006635a9  eb0e                 jmp 0x6635b9
// 006635ab  896e08               mov dword ptr [esi + 8], ebp
// 006635ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 006635b1  3b7008               cmp esi, dword ptr [eax + 8]
// 006635b4  7503                 jne 0x6635b9
// 006635b6  896808               mov dword ptr [eax + 8], ebp
// 006635b9  8b5504               mov edx, dword ptr [ebp + 4]
// 006635bc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006635c0  8d4504               lea eax, [ebp + 4]
// 006635c3  8bf5                 mov esi, ebp
// 006635c5  0f85ea000000         jne 0x6636b5
// 006635cb  eb03                 jmp 0x6635d0
// 006635cd  8d4900               lea ecx, [ecx]
// 006635d0  8b08                 mov ecx, dword ptr [eax]
// 006635d2  8b5104               mov edx, dword ptr [ecx + 4]
// 006635d5  3b0a                 cmp ecx, dword ptr [edx]
// 006635d7  7551                 jne 0x66362a
// 006635d9  8b5208               mov edx, dword ptr [edx + 8]
// 006635dc  807a3000             cmp byte ptr [edx + 0x30], 0
// 006635e0  7519                 jne 0x6635fb
// 006635e2  885930               mov byte ptr [ecx + 0x30], bl
// 006635e5  885a30               mov byte ptr [edx + 0x30], bl
// 006635e8  8b10                 mov edx, dword ptr [eax]
// 006635ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 006635ed  c6413000             mov byte ptr [ecx + 0x30], 0
// 006635f1  8b10                 mov edx, dword ptr [eax]
// 006635f3  8b7204               mov esi, dword ptr [edx + 4]
// 006635f6  e9aa000000           jmp 0x6636a5
// 006635fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 006635fe  750a                 jne 0x66360a
// 00663600  8bf1                 mov esi, ecx
// 00663602  56                   push esi
// 00663603  8bcf                 mov ecx, edi
// 00663605  e816bfffff           call 0x65f520
// 0066360a  8b4604               mov eax, dword ptr [esi + 4]
// 0066360d  885830               mov byte ptr [eax + 0x30], bl
// 00663610  8b4e04               mov ecx, dword ptr [esi + 4]
// 00663613  8b5104               mov edx, dword ptr [ecx + 4]
// 00663616  c6423000             mov byte ptr [edx + 0x30], 0
// 0066361a  8b4604               mov eax, dword ptr [esi + 4]
// 0066361d  8b4804               mov ecx, dword ptr [eax + 4]
// 00663620  51                   push ecx
// 00663621  8bcf                 mov ecx, edi
// 00663623  e828c8e5ff           call 0x4bfe50
// 00663628  eb7b                 jmp 0x6636a5
// 0066362a  8b12                 mov edx, dword ptr [edx]
// 0066362c  807a3000             cmp byte ptr [edx + 0x30], 0
// 00663630  7516                 jne 0x663648
// 00663632  885930               mov byte ptr [ecx + 0x30], bl
// 00663635  885a30               mov byte ptr [edx + 0x30], bl
// 00663638  8b10                 mov edx, dword ptr [eax]
// 0066363a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066363d  c6413000             mov byte ptr [ecx + 0x30], 0
// 00663641  8b10                 mov edx, dword ptr [eax]
// 00663643  8b7204               mov esi, dword ptr [edx + 4]
// 00663646  eb5d                 jmp 0x6636a5
// 00663648  3b31                 cmp esi, dword ptr [ecx]
// 0066364a  750a                 jne 0x663656
// 0066364c  8bf1                 mov esi, ecx
// 0066364e  56                   push esi
// 0066364f  8bcf                 mov ecx, edi
// 00663651  e8fac7e5ff           call 0x4bfe50
// 00663656  8b4604               mov eax, dword ptr [esi + 4]
// 00663659  885830               mov byte ptr [eax + 0x30], bl
// 0066365c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0066365f  8b5104               mov edx, dword ptr [ecx + 4]
// 00663662  c6423000             mov byte ptr [edx + 0x30], 0
// 00663666  8b4604               mov eax, dword ptr [esi + 4]
// 00663669  8b4004               mov eax, dword ptr [eax + 4]
// 0066366c  8b4808               mov ecx, dword ptr [eax + 8]
// 0066366f  8b11                 mov edx, dword ptr [ecx]
// 00663671  895008               mov dword ptr [eax + 8], edx
// 00663674  8b11                 mov edx, dword ptr [ecx]
// 00663676  807a3100             cmp byte ptr [edx + 0x31], 0
// 0066367a  7503                 jne 0x66367f
// 0066367c  894204               mov dword ptr [edx + 4], eax
// 0066367f  8b5004               mov edx, dword ptr [eax + 4]
// 00663682  895104               mov dword ptr [ecx + 4], edx
// 00663685  8b5718               mov edx, dword ptr [edi + 0x18]
// 00663688  3b4204               cmp eax, dword ptr [edx + 4]
// 0066368b  7505                 jne 0x663692
// 0066368d  894a04               mov dword ptr [edx + 4], ecx
// 00663690  eb0e                 jmp 0x6636a0
// 00663692  8b5004               mov edx, dword ptr [eax + 4]
// 00663695  3b02                 cmp eax, dword ptr [edx]
// 00663697  7504                 jne 0x66369d
// 00663699  890a                 mov dword ptr [edx], ecx
// 0066369b  eb03                 jmp 0x6636a0
// 0066369d  894a08               mov dword ptr [edx + 8], ecx
// 006636a0  8901                 mov dword ptr [ecx], eax
// 006636a2  894804               mov dword ptr [eax + 4], ecx
// 006636a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006636a8  80793000             cmp byte ptr [ecx + 0x30], 0
// 006636ac  8d4604               lea eax, [esi + 4]
// 006636af  0f841bffffff         je 0x6635d0
// 006636b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006636b8  8b4204               mov eax, dword ptr [edx + 4]
// 006636bb  885830               mov byte ptr [eax + 0x30], bl
// 006636be  8b442464             mov eax, dword ptr [esp + 0x64]
// 006636c2  8b0f                 mov ecx, dword ptr [edi]
// 006636c4  5e                   pop esi
// 006636c5  896804               mov dword ptr [eax + 4], ebp
// 006636c8  5d                   pop ebp
// 006636c9  8908                 mov dword ptr [eax], ecx
// 006636cb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006636cf  5b                   pop ebx
// 006636d0  5f                   pop edi
// 006636d1  64890d00000000       mov dword ptr fs:[0], ecx
// 006636d8  83c450               add esp, 0x50
// 006636db  c21000               ret 0x10
// standard library map_int<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod32>
struct E { int v[8]; };
#include <map>
template class std::map<int, E>;
