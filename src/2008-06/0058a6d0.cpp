// from server: 100% by auto
// roc 2008-06 0058a6d0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058a6d0
//
// 0058a6d0  64a100000000         mov eax, dword ptr fs:[0]
// 0058a6d6  6aff                 push -1
// 0058a6d8  6842e87d00           push 0x7de842
// 0058a6dd  50                   push eax
// 0058a6de  64892500000000       mov dword ptr fs:[0], esp
// 0058a6e5  83ec44               sub esp, 0x44
// 0058a6e8  57                   push edi
// 0058a6e9  8bf9                 mov edi, ecx
// 0058a6eb  817f1c43444404       cmp dword ptr [edi + 0x1c], 0x4444443
// 0058a6f2  7259                 jb 0x58a74d
// 0058a6f4  688cb28000           push 0x80b28c
// 0058a6f9  8d4c2408             lea ecx, [esp + 8]
// 0058a6fd  ff1558248000         call dword ptr [0x802458]
// 0058a703  8d4c2420             lea ecx, [esp + 0x20]
// 0058a707  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0058a70f  ff1598288000         call dword ptr [0x802898]
// 0058a715  8d442404             lea eax, [esp + 4]
// 0058a719  50                   push eax
// 0058a71a  8d4c2430             lea ecx, [esp + 0x30]
// 0058a71e  c644245401           mov byte ptr [esp + 0x54], 1
// 0058a723  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0058a72b  ff155c248000         call dword ptr [0x80245c]
// 0058a731  68c00c8d00           push 0x8d0cc0
// 0058a736  8d4c2424             lea ecx, [esp + 0x24]
// 0058a73a  51                   push ecx
// 0058a73b  c644245800           mov byte ptr [esp + 0x58], 0
// 0058a740  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 0058a748  e83f6e1100           call 0x6a158c
// 0058a74d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0058a751  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058a754  53                   push ebx
// 0058a755  55                   push ebp
// 0058a756  56                   push esi
// 0058a757  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0058a75b  6a00                 push 0
// 0058a75d  52                   push edx
// 0058a75e  50                   push eax
// 0058a75f  56                   push esi
// 0058a760  50                   push eax
// 0058a761  e8aafbffff           call 0x58a310
// 0058a766  8be8                 mov ebp, eax
// 0058a768  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058a76b  bb01000000           mov ebx, 1
// 0058a770  015f1c               add dword ptr [edi + 0x1c], ebx
// 0058a773  3bf0                 cmp esi, eax
// 0058a775  7510                 jne 0x58a787
// 0058a777  896804               mov dword ptr [eax + 4], ebp
// 0058a77a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058a77d  8928                 mov dword ptr [eax], ebp
// 0058a77f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0058a782  896908               mov dword ptr [ecx + 8], ebp
// 0058a785  eb22                 jmp 0x58a7a9
// 0058a787  807c246800           cmp byte ptr [esp + 0x68], 0
// 0058a78c  740d                 je 0x58a79b
// 0058a78e  892e                 mov dword ptr [esi], ebp
// 0058a790  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058a793  3b30                 cmp esi, dword ptr [eax]
// 0058a795  7512                 jne 0x58a7a9
// 0058a797  8928                 mov dword ptr [eax], ebp
// 0058a799  eb0e                 jmp 0x58a7a9
// 0058a79b  896e08               mov dword ptr [esi + 8], ebp
// 0058a79e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058a7a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0058a7a4  7503                 jne 0x58a7a9
// 0058a7a6  896808               mov dword ptr [eax + 8], ebp
// 0058a7a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0058a7ac  807a4800             cmp byte ptr [edx + 0x48], 0
// 0058a7b0  8d4504               lea eax, [ebp + 4]
// 0058a7b3  8bf5                 mov esi, ebp
// 0058a7b5  0f85ea000000         jne 0x58a8a5
// 0058a7bb  eb03                 jmp 0x58a7c0
// 0058a7bd  8d4900               lea ecx, [ecx]
// 0058a7c0  8b08                 mov ecx, dword ptr [eax]
// 0058a7c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0058a7c5  3b0a                 cmp ecx, dword ptr [edx]
// 0058a7c7  7551                 jne 0x58a81a
// 0058a7c9  8b5208               mov edx, dword ptr [edx + 8]
// 0058a7cc  807a4800             cmp byte ptr [edx + 0x48], 0
// 0058a7d0  7519                 jne 0x58a7eb
// 0058a7d2  885948               mov byte ptr [ecx + 0x48], bl
// 0058a7d5  885a48               mov byte ptr [edx + 0x48], bl
// 0058a7d8  8b10                 mov edx, dword ptr [eax]
// 0058a7da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058a7dd  c6414800             mov byte ptr [ecx + 0x48], 0
// 0058a7e1  8b10                 mov edx, dword ptr [eax]
// 0058a7e3  8b7204               mov esi, dword ptr [edx + 4]
// 0058a7e6  e9aa000000           jmp 0x58a895
// 0058a7eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0058a7ee  750a                 jne 0x58a7fa
// 0058a7f0  8bf1                 mov esi, ecx
// 0058a7f2  56                   push esi
// 0058a7f3  8bcf                 mov ecx, edi
// 0058a7f5  e816cbffff           call 0x587310
// 0058a7fa  8b4604               mov eax, dword ptr [esi + 4]
// 0058a7fd  885848               mov byte ptr [eax + 0x48], bl
// 0058a800  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058a803  8b5104               mov edx, dword ptr [ecx + 4]
// 0058a806  c6424800             mov byte ptr [edx + 0x48], 0
// 0058a80a  8b4604               mov eax, dword ptr [esi + 4]
// 0058a80d  8b4804               mov ecx, dword ptr [eax + 4]
// 0058a810  51                   push ecx
// 0058a811  8bcf                 mov ecx, edi
// 0058a813  e8c8c8ffff           call 0x5870e0
// 0058a818  eb7b                 jmp 0x58a895
// 0058a81a  8b12                 mov edx, dword ptr [edx]
// 0058a81c  807a4800             cmp byte ptr [edx + 0x48], 0
// 0058a820  7516                 jne 0x58a838
// 0058a822  885948               mov byte ptr [ecx + 0x48], bl
// 0058a825  885a48               mov byte ptr [edx + 0x48], bl
// 0058a828  8b10                 mov edx, dword ptr [eax]
// 0058a82a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0058a82d  c6414800             mov byte ptr [ecx + 0x48], 0
// 0058a831  8b10                 mov edx, dword ptr [eax]
// 0058a833  8b7204               mov esi, dword ptr [edx + 4]
// 0058a836  eb5d                 jmp 0x58a895
// 0058a838  3b31                 cmp esi, dword ptr [ecx]
// 0058a83a  750a                 jne 0x58a846
// 0058a83c  8bf1                 mov esi, ecx
// 0058a83e  56                   push esi
// 0058a83f  8bcf                 mov ecx, edi
// 0058a841  e89ac8ffff           call 0x5870e0
// 0058a846  8b4604               mov eax, dword ptr [esi + 4]
// 0058a849  885848               mov byte ptr [eax + 0x48], bl
// 0058a84c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058a84f  8b5104               mov edx, dword ptr [ecx + 4]
// 0058a852  c6424800             mov byte ptr [edx + 0x48], 0
// 0058a856  8b4604               mov eax, dword ptr [esi + 4]
// 0058a859  8b4004               mov eax, dword ptr [eax + 4]
// 0058a85c  8b4808               mov ecx, dword ptr [eax + 8]
// 0058a85f  8b11                 mov edx, dword ptr [ecx]
// 0058a861  895008               mov dword ptr [eax + 8], edx
// 0058a864  8b11                 mov edx, dword ptr [ecx]
// 0058a866  807a4900             cmp byte ptr [edx + 0x49], 0
// 0058a86a  7503                 jne 0x58a86f
// 0058a86c  894204               mov dword ptr [edx + 4], eax
// 0058a86f  8b5004               mov edx, dword ptr [eax + 4]
// 0058a872  895104               mov dword ptr [ecx + 4], edx
// 0058a875  8b5718               mov edx, dword ptr [edi + 0x18]
// 0058a878  3b4204               cmp eax, dword ptr [edx + 4]
// 0058a87b  7505                 jne 0x58a882
// 0058a87d  894a04               mov dword ptr [edx + 4], ecx
// 0058a880  eb0e                 jmp 0x58a890
// 0058a882  8b5004               mov edx, dword ptr [eax + 4]
// 0058a885  3b02                 cmp eax, dword ptr [edx]
// 0058a887  7504                 jne 0x58a88d
// 0058a889  890a                 mov dword ptr [edx], ecx
// 0058a88b  eb03                 jmp 0x58a890
// 0058a88d  894a08               mov dword ptr [edx + 8], ecx
// 0058a890  8901                 mov dword ptr [ecx], eax
// 0058a892  894804               mov dword ptr [eax + 4], ecx
// 0058a895  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058a898  80794800             cmp byte ptr [ecx + 0x48], 0
// 0058a89c  8d4604               lea eax, [esi + 4]
// 0058a89f  0f841bffffff         je 0x58a7c0
// 0058a8a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0058a8a8  8b4204               mov eax, dword ptr [edx + 4]
// 0058a8ab  885848               mov byte ptr [eax + 0x48], bl
// 0058a8ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0058a8b2  8b0f                 mov ecx, dword ptr [edi]
// 0058a8b4  5e                   pop esi
// 0058a8b5  896804               mov dword ptr [eax + 4], ebp
// 0058a8b8  5d                   pop ebp
// 0058a8b9  8908                 mov dword ptr [eax], ecx
// 0058a8bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0058a8bf  5b                   pop ebx
// 0058a8c0  5f                   pop edi
// 0058a8c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0058a8c8  83c450               add esp, 0x50
// 0058a8cb  c21000               ret 0x10
// standard library map_str<pod32> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
