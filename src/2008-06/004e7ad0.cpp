// from server: 100% by auto
// roc 2008-06 004e7ad0  unit: RBX::RenderBase::VAggregateChunk::?$WeakReferenceCountedPointer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e7ad0
//
// 004e7ad0  64a100000000         mov eax, dword ptr fs:[0]
// 004e7ad6  6aff                 push -1
// 004e7ad8  6842e87d00           push 0x7de842
// 004e7add  50                   push eax
// 004e7ade  64892500000000       mov dword ptr fs:[0], esp
// 004e7ae5  83ec44               sub esp, 0x44
// 004e7ae8  57                   push edi
// 004e7ae9  8bf9                 mov edi, ecx
// 004e7aeb  817f1ccbcccc0c       cmp dword ptr [edi + 0x1c], 0xccccccb
// 004e7af2  7259                 jb 0x4e7b4d
// 004e7af4  688cb28000           push 0x80b28c
// 004e7af9  8d4c2408             lea ecx, [esp + 8]
// 004e7afd  ff1558248000         call dword ptr [0x802458]
// 004e7b03  8d4c2420             lea ecx, [esp + 0x20]
// 004e7b07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004e7b0f  ff1598288000         call dword ptr [0x802898]
// 004e7b15  8d442404             lea eax, [esp + 4]
// 004e7b19  50                   push eax
// 004e7b1a  8d4c2430             lea ecx, [esp + 0x30]
// 004e7b1e  c644245401           mov byte ptr [esp + 0x54], 1
// 004e7b23  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004e7b2b  ff155c248000         call dword ptr [0x80245c]
// 004e7b31  68c00c8d00           push 0x8d0cc0
// 004e7b36  8d4c2424             lea ecx, [esp + 0x24]
// 004e7b3a  51                   push ecx
// 004e7b3b  c644245800           mov byte ptr [esp + 0x58], 0
// 004e7b40  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004e7b48  e83f9a1b00           call 0x6a158c
// 004e7b4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004e7b51  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7b54  53                   push ebx
// 004e7b55  55                   push ebp
// 004e7b56  56                   push esi
// 004e7b57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004e7b5b  6a00                 push 0
// 004e7b5d  52                   push edx
// 004e7b5e  50                   push eax
// 004e7b5f  56                   push esi
// 004e7b60  50                   push eax
// 004e7b61  e88afdffff           call 0x4e78f0
// 004e7b66  8be8                 mov ebp, eax
// 004e7b68  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7b6b  bb01000000           mov ebx, 1
// 004e7b70  015f1c               add dword ptr [edi + 0x1c], ebx
// 004e7b73  3bf0                 cmp esi, eax
// 004e7b75  7510                 jne 0x4e7b87
// 004e7b77  896804               mov dword ptr [eax + 4], ebp
// 004e7b7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7b7d  8928                 mov dword ptr [eax], ebp
// 004e7b7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004e7b82  896908               mov dword ptr [ecx + 8], ebp
// 004e7b85  eb22                 jmp 0x4e7ba9
// 004e7b87  807c246800           cmp byte ptr [esp + 0x68], 0
// 004e7b8c  740d                 je 0x4e7b9b
// 004e7b8e  892e                 mov dword ptr [esi], ebp
// 004e7b90  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7b93  3b30                 cmp esi, dword ptr [eax]
// 004e7b95  7512                 jne 0x4e7ba9
// 004e7b97  8928                 mov dword ptr [eax], ebp
// 004e7b99  eb0e                 jmp 0x4e7ba9
// 004e7b9b  896e08               mov dword ptr [esi + 8], ebp
// 004e7b9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7ba1  3b7008               cmp esi, dword ptr [eax + 8]
// 004e7ba4  7503                 jne 0x4e7ba9
// 004e7ba6  896808               mov dword ptr [eax + 8], ebp
// 004e7ba9  8b5504               mov edx, dword ptr [ebp + 4]
// 004e7bac  807a2000             cmp byte ptr [edx + 0x20], 0
// 004e7bb0  8d4504               lea eax, [ebp + 4]
// 004e7bb3  8bf5                 mov esi, ebp
// 004e7bb5  0f85ea000000         jne 0x4e7ca5
// 004e7bbb  eb03                 jmp 0x4e7bc0
// 004e7bbd  8d4900               lea ecx, [ecx]
// 004e7bc0  8b08                 mov ecx, dword ptr [eax]
// 004e7bc2  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7bc5  3b0a                 cmp ecx, dword ptr [edx]
// 004e7bc7  7551                 jne 0x4e7c1a
// 004e7bc9  8b5208               mov edx, dword ptr [edx + 8]
// 004e7bcc  807a2000             cmp byte ptr [edx + 0x20], 0
// 004e7bd0  7519                 jne 0x4e7beb
// 004e7bd2  885920               mov byte ptr [ecx + 0x20], bl
// 004e7bd5  885a20               mov byte ptr [edx + 0x20], bl
// 004e7bd8  8b10                 mov edx, dword ptr [eax]
// 004e7bda  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e7bdd  c6412000             mov byte ptr [ecx + 0x20], 0
// 004e7be1  8b10                 mov edx, dword ptr [eax]
// 004e7be3  8b7204               mov esi, dword ptr [edx + 4]
// 004e7be6  e9aa000000           jmp 0x4e7c95
// 004e7beb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004e7bee  750a                 jne 0x4e7bfa
// 004e7bf0  8bf1                 mov esi, ecx
// 004e7bf2  56                   push esi
// 004e7bf3  8bcf                 mov ecx, edi
// 004e7bf5  e8f6f9feff           call 0x4d75f0
// 004e7bfa  8b4604               mov eax, dword ptr [esi + 4]
// 004e7bfd  885820               mov byte ptr [eax + 0x20], bl
// 004e7c00  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7c03  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7c06  c6422000             mov byte ptr [edx + 0x20], 0
// 004e7c0a  8b4604               mov eax, dword ptr [esi + 4]
// 004e7c0d  8b4804               mov ecx, dword ptr [eax + 4]
// 004e7c10  51                   push ecx
// 004e7c11  8bcf                 mov ecx, edi
// 004e7c13  e8a8b20c00           call 0x5b2ec0
// 004e7c18  eb7b                 jmp 0x4e7c95
// 004e7c1a  8b12                 mov edx, dword ptr [edx]
// 004e7c1c  807a2000             cmp byte ptr [edx + 0x20], 0
// 004e7c20  7516                 jne 0x4e7c38
// 004e7c22  885920               mov byte ptr [ecx + 0x20], bl
// 004e7c25  885a20               mov byte ptr [edx + 0x20], bl
// 004e7c28  8b10                 mov edx, dword ptr [eax]
// 004e7c2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e7c2d  c6412000             mov byte ptr [ecx + 0x20], 0
// 004e7c31  8b10                 mov edx, dword ptr [eax]
// 004e7c33  8b7204               mov esi, dword ptr [edx + 4]
// 004e7c36  eb5d                 jmp 0x4e7c95
// 004e7c38  3b31                 cmp esi, dword ptr [ecx]
// 004e7c3a  750a                 jne 0x4e7c46
// 004e7c3c  8bf1                 mov esi, ecx
// 004e7c3e  56                   push esi
// 004e7c3f  8bcf                 mov ecx, edi
// 004e7c41  e87ab20c00           call 0x5b2ec0
// 004e7c46  8b4604               mov eax, dword ptr [esi + 4]
// 004e7c49  885820               mov byte ptr [eax + 0x20], bl
// 004e7c4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7c4f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7c52  c6422000             mov byte ptr [edx + 0x20], 0
// 004e7c56  8b4604               mov eax, dword ptr [esi + 4]
// 004e7c59  8b4004               mov eax, dword ptr [eax + 4]
// 004e7c5c  8b4808               mov ecx, dword ptr [eax + 8]
// 004e7c5f  8b11                 mov edx, dword ptr [ecx]
// 004e7c61  895008               mov dword ptr [eax + 8], edx
// 004e7c64  8b11                 mov edx, dword ptr [ecx]
// 004e7c66  807a2100             cmp byte ptr [edx + 0x21], 0
// 004e7c6a  7503                 jne 0x4e7c6f
// 004e7c6c  894204               mov dword ptr [edx + 4], eax
// 004e7c6f  8b5004               mov edx, dword ptr [eax + 4]
// 004e7c72  895104               mov dword ptr [ecx + 4], edx
// 004e7c75  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e7c78  3b4204               cmp eax, dword ptr [edx + 4]
// 004e7c7b  7505                 jne 0x4e7c82
// 004e7c7d  894a04               mov dword ptr [edx + 4], ecx
// 004e7c80  eb0e                 jmp 0x4e7c90
// 004e7c82  8b5004               mov edx, dword ptr [eax + 4]
// 004e7c85  3b02                 cmp eax, dword ptr [edx]
// 004e7c87  7504                 jne 0x4e7c8d
// 004e7c89  890a                 mov dword ptr [edx], ecx
// 004e7c8b  eb03                 jmp 0x4e7c90
// 004e7c8d  894a08               mov dword ptr [edx + 8], ecx
// 004e7c90  8901                 mov dword ptr [ecx], eax
// 004e7c92  894804               mov dword ptr [eax + 4], ecx
// 004e7c95  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7c98  80792000             cmp byte ptr [ecx + 0x20], 0
// 004e7c9c  8d4604               lea eax, [esi + 4]
// 004e7c9f  0f841bffffff         je 0x4e7bc0
// 004e7ca5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e7ca8  8b4204               mov eax, dword ptr [edx + 4]
// 004e7cab  885820               mov byte ptr [eax + 0x20], bl
// 004e7cae  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e7cb2  8b0f                 mov ecx, dword ptr [edi]
// 004e7cb4  5e                   pop esi
// 004e7cb5  896804               mov dword ptr [eax + 4], ebp
// 004e7cb8  5d                   pop ebp
// 004e7cb9  8908                 mov dword ptr [eax], ecx
// 004e7cbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e7cbf  5b                   pop ebx
// 004e7cc0  5f                   pop edi
// 004e7cc1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e7cc8  83c450               add esp, 0x50
// 004e7ccb  c21000               ret 0x10
// standard library map_int<pod16> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod16>
struct E { int v[4]; };
#include <map>
template class std::map<int, E>;
