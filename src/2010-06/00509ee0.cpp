// from server: 100% by auto
// roc 2010-06 00509ee0  unit: RBX::Network::ServerReplicator  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00509ee0
//
// 00509ee0  64a100000000         mov eax, dword ptr fs:[0]
// 00509ee6  6aff                 push -1
// 00509ee8  68e22f9a00           push 0x9a2fe2
// 00509eed  50                   push eax
// 00509eee  64892500000000       mov dword ptr fs:[0], esp
// 00509ef5  83ec44               sub esp, 0x44
// 00509ef8  57                   push edi
// 00509ef9  8bf9                 mov edi, ecx
// 00509efb  817f1c48922409       cmp dword ptr [edi + 0x1c], 0x9249248
// 00509f02  7259                 jb 0x509f5d
// 00509f04  68a800a000           push 0xa000a8
// 00509f09  8d4c2408             lea ecx, [esp + 8]
// 00509f0d  ff1510a49e00         call dword ptr [0x9ea410]
// 00509f13  8d4c2420             lea ecx, [esp + 0x20]
// 00509f17  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00509f1f  ff1518a99e00         call dword ptr [0x9ea918]
// 00509f25  8d442404             lea eax, [esp + 4]
// 00509f29  50                   push eax
// 00509f2a  8d4c2430             lea ecx, [esp + 0x30]
// 00509f2e  c644245401           mov byte ptr [esp + 0x54], 1
// 00509f33  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 00509f3b  ff150ca49e00         call dword ptr [0x9ea40c]
// 00509f41  68601bb000           push 0xb01b60
// 00509f46  8d4c2424             lea ecx, [esp + 0x24]
// 00509f4a  51                   push ecx
// 00509f4b  c644245800           mov byte ptr [esp + 0x58], 0
// 00509f50  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 00509f58  e855ea2900           call 0x7a89b2
// 00509f5d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00509f61  8b4718               mov eax, dword ptr [edi + 0x18]
// 00509f64  53                   push ebx
// 00509f65  55                   push ebp
// 00509f66  56                   push esi
// 00509f67  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00509f6b  6a00                 push 0
// 00509f6d  52                   push edx
// 00509f6e  50                   push eax
// 00509f6f  56                   push esi
// 00509f70  50                   push eax
// 00509f71  e86afaffff           call 0x5099e0
// 00509f76  8be8                 mov ebp, eax
// 00509f78  8b4718               mov eax, dword ptr [edi + 0x18]
// 00509f7b  bb01000000           mov ebx, 1
// 00509f80  015f1c               add dword ptr [edi + 0x1c], ebx
// 00509f83  3bf0                 cmp esi, eax
// 00509f85  7510                 jne 0x509f97
// 00509f87  896804               mov dword ptr [eax + 4], ebp
// 00509f8a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00509f8d  8928                 mov dword ptr [eax], ebp
// 00509f8f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00509f92  896908               mov dword ptr [ecx + 8], ebp
// 00509f95  eb22                 jmp 0x509fb9
// 00509f97  807c246800           cmp byte ptr [esp + 0x68], 0
// 00509f9c  740d                 je 0x509fab
// 00509f9e  892e                 mov dword ptr [esi], ebp
// 00509fa0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00509fa3  3b30                 cmp esi, dword ptr [eax]
// 00509fa5  7512                 jne 0x509fb9
// 00509fa7  8928                 mov dword ptr [eax], ebp
// 00509fa9  eb0e                 jmp 0x509fb9
// 00509fab  896e08               mov dword ptr [esi + 8], ebp
// 00509fae  8b4718               mov eax, dword ptr [edi + 0x18]
// 00509fb1  3b7008               cmp esi, dword ptr [eax + 8]
// 00509fb4  7503                 jne 0x509fb9
// 00509fb6  896808               mov dword ptr [eax + 8], ebp
// 00509fb9  8b5504               mov edx, dword ptr [ebp + 4]
// 00509fbc  807a2800             cmp byte ptr [edx + 0x28], 0
// 00509fc0  8d4504               lea eax, [ebp + 4]
// 00509fc3  8bf5                 mov esi, ebp
// 00509fc5  0f85ea000000         jne 0x50a0b5
// 00509fcb  eb03                 jmp 0x509fd0
// 00509fcd  8d4900               lea ecx, [ecx]
// 00509fd0  8b08                 mov ecx, dword ptr [eax]
// 00509fd2  8b5104               mov edx, dword ptr [ecx + 4]
// 00509fd5  3b0a                 cmp ecx, dword ptr [edx]
// 00509fd7  7551                 jne 0x50a02a
// 00509fd9  8b5208               mov edx, dword ptr [edx + 8]
// 00509fdc  807a2800             cmp byte ptr [edx + 0x28], 0
// 00509fe0  7519                 jne 0x509ffb
// 00509fe2  885928               mov byte ptr [ecx + 0x28], bl
// 00509fe5  885a28               mov byte ptr [edx + 0x28], bl
// 00509fe8  8b10                 mov edx, dword ptr [eax]
// 00509fea  8b4a04               mov ecx, dword ptr [edx + 4]
// 00509fed  c6412800             mov byte ptr [ecx + 0x28], 0
// 00509ff1  8b10                 mov edx, dword ptr [eax]
// 00509ff3  8b7204               mov esi, dword ptr [edx + 4]
// 00509ff6  e9aa000000           jmp 0x50a0a5
// 00509ffb  3b7108               cmp esi, dword ptr [ecx + 8]
// 00509ffe  750a                 jne 0x50a00a
// 0050a000  8bf1                 mov esi, ecx
// 0050a002  56                   push esi
// 0050a003  8bcf                 mov ecx, edi
// 0050a005  e8c6cf0100           call 0x526fd0
// 0050a00a  8b4604               mov eax, dword ptr [esi + 4]
// 0050a00d  885828               mov byte ptr [eax + 0x28], bl
// 0050a010  8b4e04               mov ecx, dword ptr [esi + 4]
// 0050a013  8b5104               mov edx, dword ptr [ecx + 4]
// 0050a016  c6422800             mov byte ptr [edx + 0x28], 0
// 0050a01a  8b4604               mov eax, dword ptr [esi + 4]
// 0050a01d  8b4804               mov ecx, dword ptr [eax + 4]
// 0050a020  51                   push ecx
// 0050a021  8bcf                 mov ecx, edi
// 0050a023  e848cf0100           call 0x526f70
// 0050a028  eb7b                 jmp 0x50a0a5
// 0050a02a  8b12                 mov edx, dword ptr [edx]
// 0050a02c  807a2800             cmp byte ptr [edx + 0x28], 0
// 0050a030  7516                 jne 0x50a048
// 0050a032  885928               mov byte ptr [ecx + 0x28], bl
// 0050a035  885a28               mov byte ptr [edx + 0x28], bl
// 0050a038  8b10                 mov edx, dword ptr [eax]
// 0050a03a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0050a03d  c6412800             mov byte ptr [ecx + 0x28], 0
// 0050a041  8b10                 mov edx, dword ptr [eax]
// 0050a043  8b7204               mov esi, dword ptr [edx + 4]
// 0050a046  eb5d                 jmp 0x50a0a5
// 0050a048  3b31                 cmp esi, dword ptr [ecx]
// 0050a04a  750a                 jne 0x50a056
// 0050a04c  8bf1                 mov esi, ecx
// 0050a04e  56                   push esi
// 0050a04f  8bcf                 mov ecx, edi
// 0050a051  e81acf0100           call 0x526f70
// 0050a056  8b4604               mov eax, dword ptr [esi + 4]
// 0050a059  885828               mov byte ptr [eax + 0x28], bl
// 0050a05c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0050a05f  8b5104               mov edx, dword ptr [ecx + 4]
// 0050a062  c6422800             mov byte ptr [edx + 0x28], 0
// 0050a066  8b4604               mov eax, dword ptr [esi + 4]
// 0050a069  8b4004               mov eax, dword ptr [eax + 4]
// 0050a06c  8b4808               mov ecx, dword ptr [eax + 8]
// 0050a06f  8b11                 mov edx, dword ptr [ecx]
// 0050a071  895008               mov dword ptr [eax + 8], edx
// 0050a074  8b11                 mov edx, dword ptr [ecx]
// 0050a076  807a2900             cmp byte ptr [edx + 0x29], 0
// 0050a07a  7503                 jne 0x50a07f
// 0050a07c  894204               mov dword ptr [edx + 4], eax
// 0050a07f  8b5004               mov edx, dword ptr [eax + 4]
// 0050a082  895104               mov dword ptr [ecx + 4], edx
// 0050a085  8b5718               mov edx, dword ptr [edi + 0x18]
// 0050a088  3b4204               cmp eax, dword ptr [edx + 4]
// 0050a08b  7505                 jne 0x50a092
// 0050a08d  894a04               mov dword ptr [edx + 4], ecx
// 0050a090  eb0e                 jmp 0x50a0a0
// 0050a092  8b5004               mov edx, dword ptr [eax + 4]
// 0050a095  3b02                 cmp eax, dword ptr [edx]
// 0050a097  7504                 jne 0x50a09d
// 0050a099  890a                 mov dword ptr [edx], ecx
// 0050a09b  eb03                 jmp 0x50a0a0
// 0050a09d  894a08               mov dword ptr [edx + 8], ecx
// 0050a0a0  8901                 mov dword ptr [ecx], eax
// 0050a0a2  894804               mov dword ptr [eax + 4], ecx
// 0050a0a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0050a0a8  80792800             cmp byte ptr [ecx + 0x28], 0
// 0050a0ac  8d4604               lea eax, [esi + 4]
// 0050a0af  0f841bffffff         je 0x509fd0
// 0050a0b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0050a0b8  8b4204               mov eax, dword ptr [edx + 4]
// 0050a0bb  885828               mov byte ptr [eax + 0x28], bl
// 0050a0be  8b442464             mov eax, dword ptr [esp + 0x64]
// 0050a0c2  8b0f                 mov ecx, dword ptr [edi]
// 0050a0c4  5e                   pop esi
// 0050a0c5  896804               mov dword ptr [eax + 4], ebp
// 0050a0c8  5d                   pop ebp
// 0050a0c9  8908                 mov dword ptr [eax], ecx
// 0050a0cb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0050a0cf  5b                   pop ebx
// 0050a0d0  5f                   pop edi
// 0050a0d1  64890d00000000       mov dword ptr fs:[0], ecx
// 0050a0d8  83c450               add esp, 0x50
// 0050a0db  c21000               ret 0x10
// standard library map_int<pod24> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod24>
struct E { int v[6]; };
#include <map>
template class std::map<int, E>;
