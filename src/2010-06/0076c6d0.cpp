// from server: 100% by auto
// roc 2010-06 0076c6d0  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076c6d0
//
// 0076c6d0  64a100000000         mov eax, dword ptr fs:[0]
// 0076c6d6  6aff                 push -1
// 0076c6d8  68e22f9a00           push 0x9a2fe2
// 0076c6dd  50                   push eax
// 0076c6de  64892500000000       mov dword ptr fs:[0], esp
// 0076c6e5  83ec44               sub esp, 0x44
// 0076c6e8  57                   push edi
// 0076c6e9  8bf9                 mov edi, ecx
// 0076c6eb  817f1cfeffff03       cmp dword ptr [edi + 0x1c], 0x3fffffe
// 0076c6f2  7259                 jb 0x76c74d
// 0076c6f4  68a800a000           push 0xa000a8
// 0076c6f9  8d4c2408             lea ecx, [esp + 8]
// 0076c6fd  ff1510a49e00         call dword ptr [0x9ea410]
// 0076c703  8d4c2420             lea ecx, [esp + 0x20]
// 0076c707  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0076c70f  ff1518a99e00         call dword ptr [0x9ea918]
// 0076c715  8d442404             lea eax, [esp + 4]
// 0076c719  50                   push eax
// 0076c71a  8d4c2430             lea ecx, [esp + 0x30]
// 0076c71e  c644245401           mov byte ptr [esp + 0x54], 1
// 0076c723  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0076c72b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0076c731  68601bb000           push 0xb01b60
// 0076c736  8d4c2424             lea ecx, [esp + 0x24]
// 0076c73a  51                   push ecx
// 0076c73b  c644245800           mov byte ptr [esp + 0x58], 0
// 0076c740  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0076c748  e865c20300           call 0x7a89b2
// 0076c74d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0076c751  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076c754  53                   push ebx
// 0076c755  55                   push ebp
// 0076c756  56                   push esi
// 0076c757  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0076c75b  6a00                 push 0
// 0076c75d  52                   push edx
// 0076c75e  50                   push eax
// 0076c75f  56                   push esi
// 0076c760  50                   push eax
// 0076c761  e85afeffff           call 0x76c5c0
// 0076c766  8be8                 mov ebp, eax
// 0076c768  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076c76b  bb01000000           mov ebx, 1
// 0076c770  015f1c               add dword ptr [edi + 0x1c], ebx
// 0076c773  3bf0                 cmp esi, eax
// 0076c775  7510                 jne 0x76c787
// 0076c777  896804               mov dword ptr [eax + 4], ebp
// 0076c77a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076c77d  8928                 mov dword ptr [eax], ebp
// 0076c77f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0076c782  896908               mov dword ptr [ecx + 8], ebp
// 0076c785  eb22                 jmp 0x76c7a9
// 0076c787  807c246800           cmp byte ptr [esp + 0x68], 0
// 0076c78c  740d                 je 0x76c79b
// 0076c78e  892e                 mov dword ptr [esi], ebp
// 0076c790  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076c793  3b30                 cmp esi, dword ptr [eax]
// 0076c795  7512                 jne 0x76c7a9
// 0076c797  8928                 mov dword ptr [eax], ebp
// 0076c799  eb0e                 jmp 0x76c7a9
// 0076c79b  896e08               mov dword ptr [esi + 8], ebp
// 0076c79e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0076c7a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0076c7a4  7503                 jne 0x76c7a9
// 0076c7a6  896808               mov dword ptr [eax + 8], ebp
// 0076c7a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0076c7ac  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 0076c7b0  8d4504               lea eax, [ebp + 4]
// 0076c7b3  8bf5                 mov esi, ebp
// 0076c7b5  0f85ea000000         jne 0x76c8a5
// 0076c7bb  eb03                 jmp 0x76c7c0
// 0076c7bd  8d4900               lea ecx, [ecx]
// 0076c7c0  8b08                 mov ecx, dword ptr [eax]
// 0076c7c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0076c7c5  3b0a                 cmp ecx, dword ptr [edx]
// 0076c7c7  7551                 jne 0x76c81a
// 0076c7c9  8b5208               mov edx, dword ptr [edx + 8]
// 0076c7cc  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 0076c7d0  7519                 jne 0x76c7eb
// 0076c7d2  88594c               mov byte ptr [ecx + 0x4c], bl
// 0076c7d5  885a4c               mov byte ptr [edx + 0x4c], bl
// 0076c7d8  8b10                 mov edx, dword ptr [eax]
// 0076c7da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076c7dd  c6414c00             mov byte ptr [ecx + 0x4c], 0
// 0076c7e1  8b10                 mov edx, dword ptr [eax]
// 0076c7e3  8b7204               mov esi, dword ptr [edx + 4]
// 0076c7e6  e9aa000000           jmp 0x76c895
// 0076c7eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0076c7ee  750a                 jne 0x76c7fa
// 0076c7f0  8bf1                 mov esi, ecx
// 0076c7f2  56                   push esi
// 0076c7f3  8bcf                 mov ecx, edi
// 0076c7f5  e836eaffff           call 0x76b230
// 0076c7fa  8b4604               mov eax, dword ptr [esi + 4]
// 0076c7fd  88584c               mov byte ptr [eax + 0x4c], bl
// 0076c800  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076c803  8b5104               mov edx, dword ptr [ecx + 4]
// 0076c806  c6424c00             mov byte ptr [edx + 0x4c], 0
// 0076c80a  8b4604               mov eax, dword ptr [esi + 4]
// 0076c80d  8b4804               mov ecx, dword ptr [eax + 4]
// 0076c810  51                   push ecx
// 0076c811  8bcf                 mov ecx, edi
// 0076c813  e868e7ffff           call 0x76af80
// 0076c818  eb7b                 jmp 0x76c895
// 0076c81a  8b12                 mov edx, dword ptr [edx]
// 0076c81c  807a4c00             cmp byte ptr [edx + 0x4c], 0
// 0076c820  7516                 jne 0x76c838
// 0076c822  88594c               mov byte ptr [ecx + 0x4c], bl
// 0076c825  885a4c               mov byte ptr [edx + 0x4c], bl
// 0076c828  8b10                 mov edx, dword ptr [eax]
// 0076c82a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0076c82d  c6414c00             mov byte ptr [ecx + 0x4c], 0
// 0076c831  8b10                 mov edx, dword ptr [eax]
// 0076c833  8b7204               mov esi, dword ptr [edx + 4]
// 0076c836  eb5d                 jmp 0x76c895
// 0076c838  3b31                 cmp esi, dword ptr [ecx]
// 0076c83a  750a                 jne 0x76c846
// 0076c83c  8bf1                 mov esi, ecx
// 0076c83e  56                   push esi
// 0076c83f  8bcf                 mov ecx, edi
// 0076c841  e83ae7ffff           call 0x76af80
// 0076c846  8b4604               mov eax, dword ptr [esi + 4]
// 0076c849  88584c               mov byte ptr [eax + 0x4c], bl
// 0076c84c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076c84f  8b5104               mov edx, dword ptr [ecx + 4]
// 0076c852  c6424c00             mov byte ptr [edx + 0x4c], 0
// 0076c856  8b4604               mov eax, dword ptr [esi + 4]
// 0076c859  8b4004               mov eax, dword ptr [eax + 4]
// 0076c85c  8b4808               mov ecx, dword ptr [eax + 8]
// 0076c85f  8b11                 mov edx, dword ptr [ecx]
// 0076c861  895008               mov dword ptr [eax + 8], edx
// 0076c864  8b11                 mov edx, dword ptr [ecx]
// 0076c866  807a4d00             cmp byte ptr [edx + 0x4d], 0
// 0076c86a  7503                 jne 0x76c86f
// 0076c86c  894204               mov dword ptr [edx + 4], eax
// 0076c86f  8b5004               mov edx, dword ptr [eax + 4]
// 0076c872  895104               mov dword ptr [ecx + 4], edx
// 0076c875  8b5718               mov edx, dword ptr [edi + 0x18]
// 0076c878  3b4204               cmp eax, dword ptr [edx + 4]
// 0076c87b  7505                 jne 0x76c882
// 0076c87d  894a04               mov dword ptr [edx + 4], ecx
// 0076c880  eb0e                 jmp 0x76c890
// 0076c882  8b5004               mov edx, dword ptr [eax + 4]
// 0076c885  3b02                 cmp eax, dword ptr [edx]
// 0076c887  7504                 jne 0x76c88d
// 0076c889  890a                 mov dword ptr [edx], ecx
// 0076c88b  eb03                 jmp 0x76c890
// 0076c88d  894a08               mov dword ptr [edx + 8], ecx
// 0076c890  8901                 mov dword ptr [ecx], eax
// 0076c892  894804               mov dword ptr [eax + 4], ecx
// 0076c895  8b4e04               mov ecx, dword ptr [esi + 4]
// 0076c898  80794c00             cmp byte ptr [ecx + 0x4c], 0
// 0076c89c  8d4604               lea eax, [esi + 4]
// 0076c89f  0f841bffffff         je 0x76c7c0
// 0076c8a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0076c8a8  8b4204               mov eax, dword ptr [edx + 4]
// 0076c8ab  88584c               mov byte ptr [eax + 0x4c], bl
// 0076c8ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0076c8b2  8b0f                 mov ecx, dword ptr [edi]
// 0076c8b4  5e                   pop esi
// 0076c8b5  896804               mov dword ptr [eax + 4], ebp
// 0076c8b8  5d                   pop ebp
// 0076c8b9  8908                 mov dword ptr [eax], ecx
// 0076c8bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0076c8bf  5b                   pop ebx
// 0076c8c0  5f                   pop edi
// 0076c8c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0076c8c8  83c450               add esp, 0x50
// 0076c8cb  c21000               ret 0x10
// standard library map_str<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
