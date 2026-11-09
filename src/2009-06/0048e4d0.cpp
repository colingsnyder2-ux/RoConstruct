// from server: 100% by auto
// roc 2009-06 0048e4d0  unit: Ogre::RbxTextureCompositorSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048e4d0
//
// 0048e4d0  64a100000000         mov eax, dword ptr fs:[0]
// 0048e4d6  6aff                 push -1
// 0048e4d8  68b2db8500           push 0x85dbb2
// 0048e4dd  50                   push eax
// 0048e4de  64892500000000       mov dword ptr fs:[0], esp
// 0048e4e5  83ec44               sub esp, 0x44
// 0048e4e8  57                   push edi
// 0048e4e9  8bf9                 mov edi, ecx
// 0048e4eb  817f1c0a59c802       cmp dword ptr [edi + 0x1c], 0x2c8590a
// 0048e4f2  7259                 jb 0x48e54d
// 0048e4f4  68c0c98a00           push 0x8ac9c0
// 0048e4f9  8d4c2408             lea ecx, [esp + 8]
// 0048e4fd  ff15b4e48900         call dword ptr [0x89e4b4]
// 0048e503  8d4c2420             lea ecx, [esp + 0x20]
// 0048e507  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0048e50f  ff15b8e98900         call dword ptr [0x89e9b8]
// 0048e515  8d442404             lea eax, [esp + 4]
// 0048e519  50                   push eax
// 0048e51a  8d4c2430             lea ecx, [esp + 0x30]
// 0048e51e  c644245401           mov byte ptr [esp + 0x54], 1
// 0048e523  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 0048e52b  ff15b8e48900         call dword ptr [0x89e4b8]
// 0048e531  6834929700           push 0x979234
// 0048e536  8d4c2424             lea ecx, [esp + 0x24]
// 0048e53a  51                   push ecx
// 0048e53b  c644245800           mov byte ptr [esp + 0x58], 0
// 0048e540  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 0048e548  e8fdb42800           call 0x719a4a
// 0048e54d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0048e551  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048e554  53                   push ebx
// 0048e555  55                   push ebp
// 0048e556  56                   push esi
// 0048e557  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0048e55b  6a00                 push 0
// 0048e55d  52                   push edx
// 0048e55e  50                   push eax
// 0048e55f  56                   push esi
// 0048e560  50                   push eax
// 0048e561  e85afdffff           call 0x48e2c0
// 0048e566  8be8                 mov ebp, eax
// 0048e568  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048e56b  bb01000000           mov ebx, 1
// 0048e570  015f1c               add dword ptr [edi + 0x1c], ebx
// 0048e573  3bf0                 cmp esi, eax
// 0048e575  7510                 jne 0x48e587
// 0048e577  896804               mov dword ptr [eax + 4], ebp
// 0048e57a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048e57d  8928                 mov dword ptr [eax], ebp
// 0048e57f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0048e582  896908               mov dword ptr [ecx + 8], ebp
// 0048e585  eb22                 jmp 0x48e5a9
// 0048e587  807c246800           cmp byte ptr [esp + 0x68], 0
// 0048e58c  740d                 je 0x48e59b
// 0048e58e  892e                 mov dword ptr [esi], ebp
// 0048e590  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048e593  3b30                 cmp esi, dword ptr [eax]
// 0048e595  7512                 jne 0x48e5a9
// 0048e597  8928                 mov dword ptr [eax], ebp
// 0048e599  eb0e                 jmp 0x48e5a9
// 0048e59b  896e08               mov dword ptr [esi + 8], ebp
// 0048e59e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0048e5a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0048e5a4  7503                 jne 0x48e5a9
// 0048e5a6  896808               mov dword ptr [eax + 8], ebp
// 0048e5a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0048e5ac  807a6800             cmp byte ptr [edx + 0x68], 0
// 0048e5b0  8d4504               lea eax, [ebp + 4]
// 0048e5b3  8bf5                 mov esi, ebp
// 0048e5b5  0f85ea000000         jne 0x48e6a5
// 0048e5bb  eb03                 jmp 0x48e5c0
// 0048e5bd  8d4900               lea ecx, [ecx]
// 0048e5c0  8b08                 mov ecx, dword ptr [eax]
// 0048e5c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0048e5c5  3b0a                 cmp ecx, dword ptr [edx]
// 0048e5c7  7551                 jne 0x48e61a
// 0048e5c9  8b5208               mov edx, dword ptr [edx + 8]
// 0048e5cc  807a6800             cmp byte ptr [edx + 0x68], 0
// 0048e5d0  7519                 jne 0x48e5eb
// 0048e5d2  885968               mov byte ptr [ecx + 0x68], bl
// 0048e5d5  885a68               mov byte ptr [edx + 0x68], bl
// 0048e5d8  8b10                 mov edx, dword ptr [eax]
// 0048e5da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048e5dd  c6416800             mov byte ptr [ecx + 0x68], 0
// 0048e5e1  8b10                 mov edx, dword ptr [eax]
// 0048e5e3  8b7204               mov esi, dword ptr [edx + 4]
// 0048e5e6  e9aa000000           jmp 0x48e695
// 0048e5eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0048e5ee  750a                 jne 0x48e5fa
// 0048e5f0  8bf1                 mov esi, ecx
// 0048e5f2  56                   push esi
// 0048e5f3  8bcf                 mov ecx, edi
// 0048e5f5  e8c6d5ffff           call 0x48bbc0
// 0048e5fa  8b4604               mov eax, dword ptr [esi + 4]
// 0048e5fd  885868               mov byte ptr [eax + 0x68], bl
// 0048e600  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048e603  8b5104               mov edx, dword ptr [ecx + 4]
// 0048e606  c6426800             mov byte ptr [edx + 0x68], 0
// 0048e60a  8b4604               mov eax, dword ptr [esi + 4]
// 0048e60d  8b4804               mov ecx, dword ptr [eax + 4]
// 0048e610  51                   push ecx
// 0048e611  8bcf                 mov ecx, edi
// 0048e613  e828d1ffff           call 0x48b740
// 0048e618  eb7b                 jmp 0x48e695
// 0048e61a  8b12                 mov edx, dword ptr [edx]
// 0048e61c  807a6800             cmp byte ptr [edx + 0x68], 0
// 0048e620  7516                 jne 0x48e638
// 0048e622  885968               mov byte ptr [ecx + 0x68], bl
// 0048e625  885a68               mov byte ptr [edx + 0x68], bl
// 0048e628  8b10                 mov edx, dword ptr [eax]
// 0048e62a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0048e62d  c6416800             mov byte ptr [ecx + 0x68], 0
// 0048e631  8b10                 mov edx, dword ptr [eax]
// 0048e633  8b7204               mov esi, dword ptr [edx + 4]
// 0048e636  eb5d                 jmp 0x48e695
// 0048e638  3b31                 cmp esi, dword ptr [ecx]
// 0048e63a  750a                 jne 0x48e646
// 0048e63c  8bf1                 mov esi, ecx
// 0048e63e  56                   push esi
// 0048e63f  8bcf                 mov ecx, edi
// 0048e641  e8fad0ffff           call 0x48b740
// 0048e646  8b4604               mov eax, dword ptr [esi + 4]
// 0048e649  885868               mov byte ptr [eax + 0x68], bl
// 0048e64c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048e64f  8b5104               mov edx, dword ptr [ecx + 4]
// 0048e652  c6426800             mov byte ptr [edx + 0x68], 0
// 0048e656  8b4604               mov eax, dword ptr [esi + 4]
// 0048e659  8b4004               mov eax, dword ptr [eax + 4]
// 0048e65c  8b4808               mov ecx, dword ptr [eax + 8]
// 0048e65f  8b11                 mov edx, dword ptr [ecx]
// 0048e661  895008               mov dword ptr [eax + 8], edx
// 0048e664  8b11                 mov edx, dword ptr [ecx]
// 0048e666  807a6900             cmp byte ptr [edx + 0x69], 0
// 0048e66a  7503                 jne 0x48e66f
// 0048e66c  894204               mov dword ptr [edx + 4], eax
// 0048e66f  8b5004               mov edx, dword ptr [eax + 4]
// 0048e672  895104               mov dword ptr [ecx + 4], edx
// 0048e675  8b5718               mov edx, dword ptr [edi + 0x18]
// 0048e678  3b4204               cmp eax, dword ptr [edx + 4]
// 0048e67b  7505                 jne 0x48e682
// 0048e67d  894a04               mov dword ptr [edx + 4], ecx
// 0048e680  eb0e                 jmp 0x48e690
// 0048e682  8b5004               mov edx, dword ptr [eax + 4]
// 0048e685  3b02                 cmp eax, dword ptr [edx]
// 0048e687  7504                 jne 0x48e68d
// 0048e689  890a                 mov dword ptr [edx], ecx
// 0048e68b  eb03                 jmp 0x48e690
// 0048e68d  894a08               mov dword ptr [edx + 8], ecx
// 0048e690  8901                 mov dword ptr [ecx], eax
// 0048e692  894804               mov dword ptr [eax + 4], ecx
// 0048e695  8b4e04               mov ecx, dword ptr [esi + 4]
// 0048e698  80796800             cmp byte ptr [ecx + 0x68], 0
// 0048e69c  8d4604               lea eax, [esi + 4]
// 0048e69f  0f841bffffff         je 0x48e5c0
// 0048e6a5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0048e6a8  8b4204               mov eax, dword ptr [edx + 4]
// 0048e6ab  885868               mov byte ptr [eax + 0x68], bl
// 0048e6ae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0048e6b2  8b0f                 mov ecx, dword ptr [edi]
// 0048e6b4  5e                   pop esi
// 0048e6b5  896804               mov dword ptr [eax + 4], ebp
// 0048e6b8  5d                   pop ebp
// 0048e6b9  8908                 mov dword ptr [eax], ecx
// 0048e6bb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0048e6bf  5b                   pop ebx
// 0048e6c0  5f                   pop edi
// 0048e6c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0048e6c8  83c450               add esp, 0x50
// 0048e6cb  c21000               ret 0x10
// standard library map_str<pod64> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
