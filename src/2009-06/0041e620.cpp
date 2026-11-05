// from server: 100% by auto
// roc 2009-06 0041e620  unit: CSelectionTreeCtrl  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041e620
//
// 0041e620  64a100000000         mov eax, dword ptr fs:[0]
// 0041e626  6aff                 push -1
// 0041e628  68b2db8500           push 0x85dbb2
// 0041e62d  50                   push eax
// 0041e62e  64892500000000       mov dword ptr fs:[0], esp
// 0041e635  83ec44               sub esp, 0x44
// 0041e638  57                   push edi
// 0041e639  8bf9                 mov edi, ecx
// 0041e63b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 0041e642  7259                 jb 0x41e69d
// 0041e644  68c0c98a00           push 0x8ac9c0
// 0041e649  8d4c2408             lea ecx, [esp + 8]
// 0041e64d  ff15b4e48900         call dword ptr [0x89e4b4]
// 0041e653  8d4c2420             lea ecx, [esp + 0x20]
// 0041e657  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0041e65f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0041e665  8d442404             lea eax, [esp + 4]
// 0041e669  50                   push eax
// 0041e66a  8d4c2430             lea ecx, [esp + 0x30]
// 0041e66e  c644245401           mov byte ptr [esp + 0x54], 1
// 0041e673  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0041e67b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0041e681  6834929700           push 0x979234
// 0041e686  8d4c2424             lea ecx, [esp + 0x24]
// 0041e68a  51                   push ecx
// 0041e68b  c644245800           mov byte ptr [esp + 0x58], 0
// 0041e690  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0041e698  e8adb32f00           call 0x719a4a
// 0041e69d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0041e6a1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041e6a4  53                   push ebx
// 0041e6a5  55                   push ebp
// 0041e6a6  56                   push esi
// 0041e6a7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0041e6ab  6a00                 push 0
// 0041e6ad  52                   push edx
// 0041e6ae  50                   push eax
// 0041e6af  56                   push esi
// 0041e6b0  50                   push eax
// 0041e6b1  e8eac42e00           call 0x70aba0
// 0041e6b6  8be8                 mov ebp, eax
// 0041e6b8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041e6bb  bb01000000           mov ebx, 1
// 0041e6c0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0041e6c3  3bf0                 cmp esi, eax
// 0041e6c5  7510                 jne 0x41e6d7
// 0041e6c7  896804               mov dword ptr [eax + 4], ebp
// 0041e6ca  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041e6cd  8928                 mov dword ptr [eax], ebp
// 0041e6cf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0041e6d2  896908               mov dword ptr [ecx + 8], ebp
// 0041e6d5  eb22                 jmp 0x41e6f9
// 0041e6d7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0041e6dc  740d                 je 0x41e6eb
// 0041e6de  892e                 mov dword ptr [esi], ebp
// 0041e6e0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041e6e3  3b30                 cmp esi, dword ptr [eax]
// 0041e6e5  7512                 jne 0x41e6f9
// 0041e6e7  8928                 mov dword ptr [eax], ebp
// 0041e6e9  eb0e                 jmp 0x41e6f9
// 0041e6eb  896e08               mov dword ptr [esi + 8], ebp
// 0041e6ee  8b4718               mov eax, dword ptr [edi + 0x18]
// 0041e6f1  3b7008               cmp esi, dword ptr [eax + 8]
// 0041e6f4  7503                 jne 0x41e6f9
// 0041e6f6  896808               mov dword ptr [eax + 8], ebp
// 0041e6f9  8b5504               mov edx, dword ptr [ebp + 4]
// 0041e6fc  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041e700  8d4504               lea eax, [ebp + 4]
// 0041e703  8bf5                 mov esi, ebp
// 0041e705  0f85ea000000         jne 0x41e7f5
// 0041e70b  eb03                 jmp 0x41e710
// 0041e70d  8d4900               lea ecx, [ecx]
// 0041e710  8b08                 mov ecx, dword ptr [eax]
// 0041e712  8b5104               mov edx, dword ptr [ecx + 4]
// 0041e715  3b0a                 cmp ecx, dword ptr [edx]
// 0041e717  7551                 jne 0x41e76a
// 0041e719  8b5208               mov edx, dword ptr [edx + 8]
// 0041e71c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041e720  7519                 jne 0x41e73b
// 0041e722  885914               mov byte ptr [ecx + 0x14], bl
// 0041e725  885a14               mov byte ptr [edx + 0x14], bl
// 0041e728  8b10                 mov edx, dword ptr [eax]
// 0041e72a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0041e72d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0041e731  8b10                 mov edx, dword ptr [eax]
// 0041e733  8b7204               mov esi, dword ptr [edx + 4]
// 0041e736  e9aa000000           jmp 0x41e7e5
// 0041e73b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0041e73e  750a                 jne 0x41e74a
// 0041e740  8bf1                 mov esi, ecx
// 0041e742  56                   push esi
// 0041e743  8bcf                 mov ecx, edi
// 0041e745  e846e12d00           call 0x6fc890
// 0041e74a  8b4604               mov eax, dword ptr [esi + 4]
// 0041e74d  885814               mov byte ptr [eax + 0x14], bl
// 0041e750  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041e753  8b5104               mov edx, dword ptr [ecx + 4]
// 0041e756  c6421400             mov byte ptr [edx + 0x14], 0
// 0041e75a  8b4604               mov eax, dword ptr [esi + 4]
// 0041e75d  8b4804               mov ecx, dword ptr [eax + 4]
// 0041e760  51                   push ecx
// 0041e761  8bcf                 mov ecx, edi
// 0041e763  e8a8a91c00           call 0x5e9110
// 0041e768  eb7b                 jmp 0x41e7e5
// 0041e76a  8b12                 mov edx, dword ptr [edx]
// 0041e76c  807a1400             cmp byte ptr [edx + 0x14], 0
// 0041e770  7516                 jne 0x41e788
// 0041e772  885914               mov byte ptr [ecx + 0x14], bl
// 0041e775  885a14               mov byte ptr [edx + 0x14], bl
// 0041e778  8b10                 mov edx, dword ptr [eax]
// 0041e77a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0041e77d  c6411400             mov byte ptr [ecx + 0x14], 0
// 0041e781  8b10                 mov edx, dword ptr [eax]
// 0041e783  8b7204               mov esi, dword ptr [edx + 4]
// 0041e786  eb5d                 jmp 0x41e7e5
// 0041e788  3b31                 cmp esi, dword ptr [ecx]
// 0041e78a  750a                 jne 0x41e796
// 0041e78c  8bf1                 mov esi, ecx
// 0041e78e  56                   push esi
// 0041e78f  8bcf                 mov ecx, edi
// 0041e791  e87aa91c00           call 0x5e9110
// 0041e796  8b4604               mov eax, dword ptr [esi + 4]
// 0041e799  885814               mov byte ptr [eax + 0x14], bl
// 0041e79c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041e79f  8b5104               mov edx, dword ptr [ecx + 4]
// 0041e7a2  c6421400             mov byte ptr [edx + 0x14], 0
// 0041e7a6  8b4604               mov eax, dword ptr [esi + 4]
// 0041e7a9  8b4004               mov eax, dword ptr [eax + 4]
// 0041e7ac  8b4808               mov ecx, dword ptr [eax + 8]
// 0041e7af  8b11                 mov edx, dword ptr [ecx]
// 0041e7b1  895008               mov dword ptr [eax + 8], edx
// 0041e7b4  8b11                 mov edx, dword ptr [ecx]
// 0041e7b6  807a1500             cmp byte ptr [edx + 0x15], 0
// 0041e7ba  7503                 jne 0x41e7bf
// 0041e7bc  894204               mov dword ptr [edx + 4], eax
// 0041e7bf  8b5004               mov edx, dword ptr [eax + 4]
// 0041e7c2  895104               mov dword ptr [ecx + 4], edx
// 0041e7c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0041e7c8  3b4204               cmp eax, dword ptr [edx + 4]
// 0041e7cb  7505                 jne 0x41e7d2
// 0041e7cd  894a04               mov dword ptr [edx + 4], ecx
// 0041e7d0  eb0e                 jmp 0x41e7e0
// 0041e7d2  8b5004               mov edx, dword ptr [eax + 4]
// 0041e7d5  3b02                 cmp eax, dword ptr [edx]
// 0041e7d7  7504                 jne 0x41e7dd
// 0041e7d9  890a                 mov dword ptr [edx], ecx
// 0041e7db  eb03                 jmp 0x41e7e0
// 0041e7dd  894a08               mov dword ptr [edx + 8], ecx
// 0041e7e0  8901                 mov dword ptr [ecx], eax
// 0041e7e2  894804               mov dword ptr [eax + 4], ecx
// 0041e7e5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0041e7e8  80791400             cmp byte ptr [ecx + 0x14], 0
// 0041e7ec  8d4604               lea eax, [esi + 4]
// 0041e7ef  0f841bffffff         je 0x41e710
// 0041e7f5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0041e7f8  8b4204               mov eax, dword ptr [edx + 4]
// 0041e7fb  885814               mov byte ptr [eax + 0x14], bl
// 0041e7fe  8b442464             mov eax, dword ptr [esp + 0x64]
// 0041e802  8b0f                 mov ecx, dword ptr [edi]
// 0041e804  5e                   pop esi
// 0041e805  896804               mov dword ptr [eax + 4], ebp
// 0041e808  5d                   pop ebp
// 0041e809  8908                 mov dword ptr [eax], ecx
// 0041e80b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0041e80f  5b                   pop ebx
// 0041e810  5f                   pop edi
// 0041e811  64890d00000000       mov dword ptr fs:[0], ecx
// 0041e818  83c450               add esp, 0x50
// 0041e81b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
