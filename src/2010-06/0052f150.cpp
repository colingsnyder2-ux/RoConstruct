// from server: 100% by auto
// roc 2010-06 0052f150  unit: RBX::VAggregateChunk::?$WeakReferenceCountedPointer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052f150
//
// 0052f150  64a100000000         mov eax, dword ptr fs:[0]
// 0052f156  6aff                 push -1
// 0052f158  68e22f9a00           push 0x9a2fe2
// 0052f15d  50                   push eax
// 0052f15e  64892500000000       mov dword ptr fs:[0], esp
// 0052f165  83ec44               sub esp, 0x44
// 0052f168  57                   push edi
// 0052f169  8bf9                 mov edi, ecx
// 0052f16b  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 0052f172  7259                 jb 0x52f1cd
// 0052f174  68a800a000           push 0xa000a8
// 0052f179  8d4c2408             lea ecx, [esp + 8]
// 0052f17d  ff1510a49e00         call dword ptr [0x9ea410]
// 0052f183  8d4c2420             lea ecx, [esp + 0x20]
// 0052f187  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0052f18f  ff1518a99e00         call dword ptr [0x9ea918]
// 0052f195  8d442404             lea eax, [esp + 4]
// 0052f199  50                   push eax
// 0052f19a  8d4c2430             lea ecx, [esp + 0x30]
// 0052f19e  c644245401           mov byte ptr [esp + 0x54], 1
// 0052f1a3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0052f1ab  ff150ca49e00         call dword ptr [0x9ea40c]
// 0052f1b1  68601bb000           push 0xb01b60
// 0052f1b6  8d4c2424             lea ecx, [esp + 0x24]
// 0052f1ba  51                   push ecx
// 0052f1bb  c644245800           mov byte ptr [esp + 0x58], 0
// 0052f1c0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0052f1c8  e8e5972700           call 0x7a89b2
// 0052f1cd  8b542464             mov edx, dword ptr [esp + 0x64]
// 0052f1d1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f1d4  53                   push ebx
// 0052f1d5  55                   push ebp
// 0052f1d6  56                   push esi
// 0052f1d7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0052f1db  6a00                 push 0
// 0052f1dd  52                   push edx
// 0052f1de  50                   push eax
// 0052f1df  56                   push esi
// 0052f1e0  50                   push eax
// 0052f1e1  e8eaf8ffff           call 0x52ead0
// 0052f1e6  8be8                 mov ebp, eax
// 0052f1e8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f1eb  bb01000000           mov ebx, 1
// 0052f1f0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0052f1f3  3bf0                 cmp esi, eax
// 0052f1f5  7510                 jne 0x52f207
// 0052f1f7  896804               mov dword ptr [eax + 4], ebp
// 0052f1fa  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f1fd  8928                 mov dword ptr [eax], ebp
// 0052f1ff  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0052f202  896908               mov dword ptr [ecx + 8], ebp
// 0052f205  eb22                 jmp 0x52f229
// 0052f207  807c246800           cmp byte ptr [esp + 0x68], 0
// 0052f20c  740d                 je 0x52f21b
// 0052f20e  892e                 mov dword ptr [esi], ebp
// 0052f210  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f213  3b30                 cmp esi, dword ptr [eax]
// 0052f215  7512                 jne 0x52f229
// 0052f217  8928                 mov dword ptr [eax], ebp
// 0052f219  eb0e                 jmp 0x52f229
// 0052f21b  896e08               mov dword ptr [esi + 8], ebp
// 0052f21e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0052f221  3b7008               cmp esi, dword ptr [eax + 8]
// 0052f224  7503                 jne 0x52f229
// 0052f226  896808               mov dword ptr [eax + 8], ebp
// 0052f229  8b5504               mov edx, dword ptr [ebp + 4]
// 0052f22c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0052f230  8d4504               lea eax, [ebp + 4]
// 0052f233  8bf5                 mov esi, ebp
// 0052f235  0f85ea000000         jne 0x52f325
// 0052f23b  eb03                 jmp 0x52f240
// 0052f23d  8d4900               lea ecx, [ecx]
// 0052f240  8b08                 mov ecx, dword ptr [eax]
// 0052f242  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f245  3b0a                 cmp ecx, dword ptr [edx]
// 0052f247  7551                 jne 0x52f29a
// 0052f249  8b5208               mov edx, dword ptr [edx + 8]
// 0052f24c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0052f250  7519                 jne 0x52f26b
// 0052f252  885928               mov byte ptr [ecx + 0x28], bl
// 0052f255  885a28               mov byte ptr [edx + 0x28], bl
// 0052f258  8b10                 mov edx, dword ptr [eax]
// 0052f25a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0052f25d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0052f261  8b10                 mov edx, dword ptr [eax]
// 0052f263  8b7204               mov esi, dword ptr [edx + 4]
// 0052f266  e9aa000000           jmp 0x52f315
// 0052f26b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0052f26e  750a                 jne 0x52f27a
// 0052f270  8bf1                 mov esi, ecx
// 0052f272  56                   push esi
// 0052f273  8bcf                 mov ecx, edi
// 0052f275  e8567dffff           call 0x526fd0
// 0052f27a  8b4604               mov eax, dword ptr [esi + 4]
// 0052f27d  885828               mov byte ptr [eax + 0x28], bl
// 0052f280  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f283  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f286  c6422800             mov byte ptr [edx + 0x28], 0
// 0052f28a  8b4604               mov eax, dword ptr [esi + 4]
// 0052f28d  8b4804               mov ecx, dword ptr [eax + 4]
// 0052f290  51                   push ecx
// 0052f291  8bcf                 mov ecx, edi
// 0052f293  e8d87cffff           call 0x526f70
// 0052f298  eb7b                 jmp 0x52f315
// 0052f29a  8b12                 mov edx, dword ptr [edx]
// 0052f29c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0052f2a0  7516                 jne 0x52f2b8
// 0052f2a2  885928               mov byte ptr [ecx + 0x28], bl
// 0052f2a5  885a28               mov byte ptr [edx + 0x28], bl
// 0052f2a8  8b10                 mov edx, dword ptr [eax]
// 0052f2aa  8b4a04               mov ecx, dword ptr [edx + 4]
// 0052f2ad  c6412800             mov byte ptr [ecx + 0x28], 0
// 0052f2b1  8b10                 mov edx, dword ptr [eax]
// 0052f2b3  8b7204               mov esi, dword ptr [edx + 4]
// 0052f2b6  eb5d                 jmp 0x52f315
// 0052f2b8  3b31                 cmp esi, dword ptr [ecx]
// 0052f2ba  750a                 jne 0x52f2c6
// 0052f2bc  8bf1                 mov esi, ecx
// 0052f2be  56                   push esi
// 0052f2bf  8bcf                 mov ecx, edi
// 0052f2c1  e8aa7cffff           call 0x526f70
// 0052f2c6  8b4604               mov eax, dword ptr [esi + 4]
// 0052f2c9  885828               mov byte ptr [eax + 0x28], bl
// 0052f2cc  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f2cf  8b5104               mov edx, dword ptr [ecx + 4]
// 0052f2d2  c6422800             mov byte ptr [edx + 0x28], 0
// 0052f2d6  8b4604               mov eax, dword ptr [esi + 4]
// 0052f2d9  8b4004               mov eax, dword ptr [eax + 4]
// 0052f2dc  8b4808               mov ecx, dword ptr [eax + 8]
// 0052f2df  8b11                 mov edx, dword ptr [ecx]
// 0052f2e1  895008               mov dword ptr [eax + 8], edx
// 0052f2e4  8b11                 mov edx, dword ptr [ecx]
// 0052f2e6  807a2900             cmp byte ptr [edx + 0x29], 0
// 0052f2ea  7503                 jne 0x52f2ef
// 0052f2ec  894204               mov dword ptr [edx + 4], eax
// 0052f2ef  8b5004               mov edx, dword ptr [eax + 4]
// 0052f2f2  895104               mov dword ptr [ecx + 4], edx
// 0052f2f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0052f2f8  3b4204               cmp eax, dword ptr [edx + 4]
// 0052f2fb  7505                 jne 0x52f302
// 0052f2fd  894a04               mov dword ptr [edx + 4], ecx
// 0052f300  eb0e                 jmp 0x52f310
// 0052f302  8b5004               mov edx, dword ptr [eax + 4]
// 0052f305  3b02                 cmp eax, dword ptr [edx]
// 0052f307  7504                 jne 0x52f30d
// 0052f309  890a                 mov dword ptr [edx], ecx
// 0052f30b  eb03                 jmp 0x52f310
// 0052f30d  894a08               mov dword ptr [edx + 8], ecx
// 0052f310  8901                 mov dword ptr [ecx], eax
// 0052f312  894804               mov dword ptr [eax + 4], ecx
// 0052f315  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f318  80792800             cmp byte ptr [ecx + 0x28], 0
// 0052f31c  8d4604               lea eax, [esi + 4]
// 0052f31f  0f841bffffff         je 0x52f240
// 0052f325  8b5718               mov edx, dword ptr [edi + 0x18]
// 0052f328  8b4204               mov eax, dword ptr [edx + 4]
// 0052f32b  885828               mov byte ptr [eax + 0x28], bl
// 0052f32e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0052f332  8b0f                 mov ecx, dword ptr [edi]
// 0052f334  5e                   pop esi
// 0052f335  896804               mov dword ptr [eax + 4], ebp
// 0052f338  5d                   pop ebp
// 0052f339  8908                 mov dword ptr [eax], ecx
// 0052f33b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0052f33f  5b                   pop ebx
// 0052f340  5f                   pop edi
// 0052f341  64890d00000000       mov dword ptr fs:[0], ecx
// 0052f348  83c450               add esp, 0x50
// 0052f34b  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
