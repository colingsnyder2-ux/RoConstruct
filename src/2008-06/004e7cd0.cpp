// from server: 100% by auto
// roc 2008-06 004e7cd0  unit: RBX::RenderBase::VAggregateChunk::?$WeakReferenceCountedPointer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e7cd0
//
// 004e7cd0  64a100000000         mov eax, dword ptr fs:[0]
// 004e7cd6  6aff                 push -1
// 004e7cd8  6842e87d00           push 0x7de842
// 004e7cdd  50                   push eax
// 004e7cde  64892500000000       mov dword ptr fs:[0], esp
// 004e7ce5  83ec44               sub esp, 0x44
// 004e7ce8  57                   push edi
// 004e7ce9  8bf9                 mov edi, ecx
// 004e7ceb  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 004e7cf2  7259                 jb 0x4e7d4d
// 004e7cf4  688cb28000           push 0x80b28c
// 004e7cf9  8d4c2408             lea ecx, [esp + 8]
// 004e7cfd  ff1558248000         call dword ptr [0x802458]
// 004e7d03  8d4c2420             lea ecx, [esp + 0x20]
// 004e7d07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004e7d0f  ff1598288000         call dword ptr [0x802898]
// 004e7d15  8d442404             lea eax, [esp + 4]
// 004e7d19  50                   push eax
// 004e7d1a  8d4c2430             lea ecx, [esp + 0x30]
// 004e7d1e  c644245401           mov byte ptr [esp + 0x54], 1
// 004e7d23  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004e7d2b  ff155c248000         call dword ptr [0x80245c]
// 004e7d31  68c00c8d00           push 0x8d0cc0
// 004e7d36  8d4c2424             lea ecx, [esp + 0x24]
// 004e7d3a  51                   push ecx
// 004e7d3b  c644245800           mov byte ptr [esp + 0x58], 0
// 004e7d40  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004e7d48  e83f981b00           call 0x6a158c
// 004e7d4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004e7d51  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7d54  53                   push ebx
// 004e7d55  55                   push ebp
// 004e7d56  56                   push esi
// 004e7d57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004e7d5b  6a00                 push 0
// 004e7d5d  52                   push edx
// 004e7d5e  50                   push eax
// 004e7d5f  56                   push esi
// 004e7d60  50                   push eax
// 004e7d61  e81afcffff           call 0x4e7980
// 004e7d66  8be8                 mov ebp, eax
// 004e7d68  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7d6b  bb01000000           mov ebx, 1
// 004e7d70  015f1c               add dword ptr [edi + 0x1c], ebx
// 004e7d73  3bf0                 cmp esi, eax
// 004e7d75  7510                 jne 0x4e7d87
// 004e7d77  896804               mov dword ptr [eax + 4], ebp
// 004e7d7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7d7d  8928                 mov dword ptr [eax], ebp
// 004e7d7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004e7d82  896908               mov dword ptr [ecx + 8], ebp
// 004e7d85  eb22                 jmp 0x4e7da9
// 004e7d87  807c246800           cmp byte ptr [esp + 0x68], 0
// 004e7d8c  740d                 je 0x4e7d9b
// 004e7d8e  892e                 mov dword ptr [esi], ebp
// 004e7d90  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7d93  3b30                 cmp esi, dword ptr [eax]
// 004e7d95  7512                 jne 0x4e7da9
// 004e7d97  8928                 mov dword ptr [eax], ebp
// 004e7d99  eb0e                 jmp 0x4e7da9
// 004e7d9b  896e08               mov dword ptr [esi + 8], ebp
// 004e7d9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e7da1  3b7008               cmp esi, dword ptr [eax + 8]
// 004e7da4  7503                 jne 0x4e7da9
// 004e7da6  896808               mov dword ptr [eax + 8], ebp
// 004e7da9  8b5504               mov edx, dword ptr [ebp + 4]
// 004e7dac  807a2800             cmp byte ptr [edx + 0x28], 0
// 004e7db0  8d4504               lea eax, [ebp + 4]
// 004e7db3  8bf5                 mov esi, ebp
// 004e7db5  0f85ea000000         jne 0x4e7ea5
// 004e7dbb  eb03                 jmp 0x4e7dc0
// 004e7dbd  8d4900               lea ecx, [ecx]
// 004e7dc0  8b08                 mov ecx, dword ptr [eax]
// 004e7dc2  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7dc5  3b0a                 cmp ecx, dword ptr [edx]
// 004e7dc7  7551                 jne 0x4e7e1a
// 004e7dc9  8b5208               mov edx, dword ptr [edx + 8]
// 004e7dcc  807a2800             cmp byte ptr [edx + 0x28], 0
// 004e7dd0  7519                 jne 0x4e7deb
// 004e7dd2  885928               mov byte ptr [ecx + 0x28], bl
// 004e7dd5  885a28               mov byte ptr [edx + 0x28], bl
// 004e7dd8  8b10                 mov edx, dword ptr [eax]
// 004e7dda  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e7ddd  c6412800             mov byte ptr [ecx + 0x28], 0
// 004e7de1  8b10                 mov edx, dword ptr [eax]
// 004e7de3  8b7204               mov esi, dword ptr [edx + 4]
// 004e7de6  e9aa000000           jmp 0x4e7e95
// 004e7deb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004e7dee  750a                 jne 0x4e7dfa
// 004e7df0  8bf1                 mov esi, ecx
// 004e7df2  56                   push esi
// 004e7df3  8bcf                 mov ecx, edi
// 004e7df5  e8a6f7feff           call 0x4d75a0
// 004e7dfa  8b4604               mov eax, dword ptr [esi + 4]
// 004e7dfd  885828               mov byte ptr [eax + 0x28], bl
// 004e7e00  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7e03  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7e06  c6422800             mov byte ptr [edx + 0x28], 0
// 004e7e0a  8b4604               mov eax, dword ptr [esi + 4]
// 004e7e0d  8b4804               mov ecx, dword ptr [eax + 4]
// 004e7e10  51                   push ecx
// 004e7e11  8bcf                 mov ecx, edi
// 004e7e13  e8789cfbff           call 0x4a1a90
// 004e7e18  eb7b                 jmp 0x4e7e95
// 004e7e1a  8b12                 mov edx, dword ptr [edx]
// 004e7e1c  807a2800             cmp byte ptr [edx + 0x28], 0
// 004e7e20  7516                 jne 0x4e7e38
// 004e7e22  885928               mov byte ptr [ecx + 0x28], bl
// 004e7e25  885a28               mov byte ptr [edx + 0x28], bl
// 004e7e28  8b10                 mov edx, dword ptr [eax]
// 004e7e2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e7e2d  c6412800             mov byte ptr [ecx + 0x28], 0
// 004e7e31  8b10                 mov edx, dword ptr [eax]
// 004e7e33  8b7204               mov esi, dword ptr [edx + 4]
// 004e7e36  eb5d                 jmp 0x4e7e95
// 004e7e38  3b31                 cmp esi, dword ptr [ecx]
// 004e7e3a  750a                 jne 0x4e7e46
// 004e7e3c  8bf1                 mov esi, ecx
// 004e7e3e  56                   push esi
// 004e7e3f  8bcf                 mov ecx, edi
// 004e7e41  e84a9cfbff           call 0x4a1a90
// 004e7e46  8b4604               mov eax, dword ptr [esi + 4]
// 004e7e49  885828               mov byte ptr [eax + 0x28], bl
// 004e7e4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7e4f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e7e52  c6422800             mov byte ptr [edx + 0x28], 0
// 004e7e56  8b4604               mov eax, dword ptr [esi + 4]
// 004e7e59  8b4004               mov eax, dword ptr [eax + 4]
// 004e7e5c  8b4808               mov ecx, dword ptr [eax + 8]
// 004e7e5f  8b11                 mov edx, dword ptr [ecx]
// 004e7e61  895008               mov dword ptr [eax + 8], edx
// 004e7e64  8b11                 mov edx, dword ptr [ecx]
// 004e7e66  807a2900             cmp byte ptr [edx + 0x29], 0
// 004e7e6a  7503                 jne 0x4e7e6f
// 004e7e6c  894204               mov dword ptr [edx + 4], eax
// 004e7e6f  8b5004               mov edx, dword ptr [eax + 4]
// 004e7e72  895104               mov dword ptr [ecx + 4], edx
// 004e7e75  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e7e78  3b4204               cmp eax, dword ptr [edx + 4]
// 004e7e7b  7505                 jne 0x4e7e82
// 004e7e7d  894a04               mov dword ptr [edx + 4], ecx
// 004e7e80  eb0e                 jmp 0x4e7e90
// 004e7e82  8b5004               mov edx, dword ptr [eax + 4]
// 004e7e85  3b02                 cmp eax, dword ptr [edx]
// 004e7e87  7504                 jne 0x4e7e8d
// 004e7e89  890a                 mov dword ptr [edx], ecx
// 004e7e8b  eb03                 jmp 0x4e7e90
// 004e7e8d  894a08               mov dword ptr [edx + 8], ecx
// 004e7e90  8901                 mov dword ptr [ecx], eax
// 004e7e92  894804               mov dword ptr [eax + 4], ecx
// 004e7e95  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e7e98  80792800             cmp byte ptr [ecx + 0x28], 0
// 004e7e9c  8d4604               lea eax, [esi + 4]
// 004e7e9f  0f841bffffff         je 0x4e7dc0
// 004e7ea5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e7ea8  8b4204               mov eax, dword ptr [edx + 4]
// 004e7eab  885828               mov byte ptr [eax + 0x28], bl
// 004e7eae  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e7eb2  8b0f                 mov ecx, dword ptr [edi]
// 004e7eb4  5e                   pop esi
// 004e7eb5  896804               mov dword ptr [eax + 4], ebp
// 004e7eb8  5d                   pop ebp
// 004e7eb9  8908                 mov dword ptr [eax], ecx
// 004e7ebb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e7ebf  5b                   pop ebx
// 004e7ec0  5f                   pop edi
// 004e7ec1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e7ec8  83c450               add esp, 0x50
// 004e7ecb  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
