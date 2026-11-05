// from server: 100% by auto
// roc 2009-06 005db7e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db7e0
//
// 005db7e0  64a100000000         mov eax, dword ptr fs:[0]
// 005db7e6  6aff                 push -1
// 005db7e8  68b2db8500           push 0x85dbb2
// 005db7ed  50                   push eax
// 005db7ee  64892500000000       mov dword ptr fs:[0], esp
// 005db7f5  83ec44               sub esp, 0x44
// 005db7f8  57                   push edi
// 005db7f9  8bf9                 mov edi, ecx
// 005db7fb  817f1c54555505       cmp dword ptr [edi + 0x1c], 0x5555554
// 005db802  7259                 jb 0x5db85d
// 005db804  68c0c98a00           push 0x8ac9c0
// 005db809  8d4c2408             lea ecx, [esp + 8]
// 005db80d  ff15b4e48900         call dword ptr [0x89e4b4]
// 005db813  8d4c2420             lea ecx, [esp + 0x20]
// 005db817  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005db81f  ff15b8e98900         call dword ptr [0x89e9b8]
// 005db825  8d442404             lea eax, [esp + 4]
// 005db829  50                   push eax
// 005db82a  8d4c2430             lea ecx, [esp + 0x30]
// 005db82e  c644245401           mov byte ptr [esp + 0x54], 1
// 005db833  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 005db83b  ff15b8e48900         call dword ptr [0x89e4b8]
// 005db841  6834929700           push 0x979234
// 005db846  8d4c2424             lea ecx, [esp + 0x24]
// 005db84a  51                   push ecx
// 005db84b  c644245800           mov byte ptr [esp + 0x58], 0
// 005db850  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 005db858  e8ede11300           call 0x719a4a
// 005db85d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005db861  8b4718               mov eax, dword ptr [edi + 0x18]
// 005db864  53                   push ebx
// 005db865  55                   push ebp
// 005db866  56                   push esi
// 005db867  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005db86b  6a00                 push 0
// 005db86d  52                   push edx
// 005db86e  50                   push eax
// 005db86f  56                   push esi
// 005db870  50                   push eax
// 005db871  e88af7ffff           call 0x5db000
// 005db876  8be8                 mov ebp, eax
// 005db878  8b4718               mov eax, dword ptr [edi + 0x18]
// 005db87b  bb01000000           mov ebx, 1
// 005db880  015f1c               add dword ptr [edi + 0x1c], ebx
// 005db883  3bf0                 cmp esi, eax
// 005db885  7510                 jne 0x5db897
// 005db887  896804               mov dword ptr [eax + 4], ebp
// 005db88a  8b4718               mov eax, dword ptr [edi + 0x18]
// 005db88d  8928                 mov dword ptr [eax], ebp
// 005db88f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005db892  896908               mov dword ptr [ecx + 8], ebp
// 005db895  eb22                 jmp 0x5db8b9
// 005db897  807c246800           cmp byte ptr [esp + 0x68], 0
// 005db89c  740d                 je 0x5db8ab
// 005db89e  892e                 mov dword ptr [esi], ebp
// 005db8a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005db8a3  3b30                 cmp esi, dword ptr [eax]
// 005db8a5  7512                 jne 0x5db8b9
// 005db8a7  8928                 mov dword ptr [eax], ebp
// 005db8a9  eb0e                 jmp 0x5db8b9
// 005db8ab  896e08               mov dword ptr [esi + 8], ebp
// 005db8ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 005db8b1  3b7008               cmp esi, dword ptr [eax + 8]
// 005db8b4  7503                 jne 0x5db8b9
// 005db8b6  896808               mov dword ptr [eax + 8], ebp
// 005db8b9  8b5504               mov edx, dword ptr [ebp + 4]
// 005db8bc  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 005db8c0  8d4504               lea eax, [ebp + 4]
// 005db8c3  8bf5                 mov esi, ebp
// 005db8c5  0f85ea000000         jne 0x5db9b5
// 005db8cb  eb03                 jmp 0x5db8d0
// 005db8cd  8d4900               lea ecx, [ecx]
// 005db8d0  8b08                 mov ecx, dword ptr [eax]
// 005db8d2  8b5104               mov edx, dword ptr [ecx + 4]
// 005db8d5  3b0a                 cmp ecx, dword ptr [edx]
// 005db8d7  7551                 jne 0x5db92a
// 005db8d9  8b5208               mov edx, dword ptr [edx + 8]
// 005db8dc  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 005db8e0  7519                 jne 0x5db8fb
// 005db8e2  88593c               mov byte ptr [ecx + 0x3c], bl
// 005db8e5  885a3c               mov byte ptr [edx + 0x3c], bl
// 005db8e8  8b10                 mov edx, dword ptr [eax]
// 005db8ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 005db8ed  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 005db8f1  8b10                 mov edx, dword ptr [eax]
// 005db8f3  8b7204               mov esi, dword ptr [edx + 4]
// 005db8f6  e9aa000000           jmp 0x5db9a5
// 005db8fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005db8fe  750a                 jne 0x5db90a
// 005db900  8bf1                 mov esi, ecx
// 005db902  56                   push esi
// 005db903  8bcf                 mov ecx, edi
// 005db905  e806e1ffff           call 0x5d9a10
// 005db90a  8b4604               mov eax, dword ptr [esi + 4]
// 005db90d  88583c               mov byte ptr [eax + 0x3c], bl
// 005db910  8b4e04               mov ecx, dword ptr [esi + 4]
// 005db913  8b5104               mov edx, dword ptr [ecx + 4]
// 005db916  c6423c00             mov byte ptr [edx + 0x3c], 0
// 005db91a  8b4604               mov eax, dword ptr [esi + 4]
// 005db91d  8b4804               mov ecx, dword ptr [eax + 4]
// 005db920  51                   push ecx
// 005db921  8bcf                 mov ecx, edi
// 005db923  e888d6ffff           call 0x5d8fb0
// 005db928  eb7b                 jmp 0x5db9a5
// 005db92a  8b12                 mov edx, dword ptr [edx]
// 005db92c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 005db930  7516                 jne 0x5db948
// 005db932  88593c               mov byte ptr [ecx + 0x3c], bl
// 005db935  885a3c               mov byte ptr [edx + 0x3c], bl
// 005db938  8b10                 mov edx, dword ptr [eax]
// 005db93a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005db93d  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 005db941  8b10                 mov edx, dword ptr [eax]
// 005db943  8b7204               mov esi, dword ptr [edx + 4]
// 005db946  eb5d                 jmp 0x5db9a5
// 005db948  3b31                 cmp esi, dword ptr [ecx]
// 005db94a  750a                 jne 0x5db956
// 005db94c  8bf1                 mov esi, ecx
// 005db94e  56                   push esi
// 005db94f  8bcf                 mov ecx, edi
// 005db951  e85ad6ffff           call 0x5d8fb0
// 005db956  8b4604               mov eax, dword ptr [esi + 4]
// 005db959  88583c               mov byte ptr [eax + 0x3c], bl
// 005db95c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005db95f  8b5104               mov edx, dword ptr [ecx + 4]
// 005db962  c6423c00             mov byte ptr [edx + 0x3c], 0
// 005db966  8b4604               mov eax, dword ptr [esi + 4]
// 005db969  8b4004               mov eax, dword ptr [eax + 4]
// 005db96c  8b4808               mov ecx, dword ptr [eax + 8]
// 005db96f  8b11                 mov edx, dword ptr [ecx]
// 005db971  895008               mov dword ptr [eax + 8], edx
// 005db974  8b11                 mov edx, dword ptr [ecx]
// 005db976  807a3d00             cmp byte ptr [edx + 0x3d], 0
// 005db97a  7503                 jne 0x5db97f
// 005db97c  894204               mov dword ptr [edx + 4], eax
// 005db97f  8b5004               mov edx, dword ptr [eax + 4]
// 005db982  895104               mov dword ptr [ecx + 4], edx
// 005db985  8b5718               mov edx, dword ptr [edi + 0x18]
// 005db988  3b4204               cmp eax, dword ptr [edx + 4]
// 005db98b  7505                 jne 0x5db992
// 005db98d  894a04               mov dword ptr [edx + 4], ecx
// 005db990  eb0e                 jmp 0x5db9a0
// 005db992  8b5004               mov edx, dword ptr [eax + 4]
// 005db995  3b02                 cmp eax, dword ptr [edx]
// 005db997  7504                 jne 0x5db99d
// 005db999  890a                 mov dword ptr [edx], ecx
// 005db99b  eb03                 jmp 0x5db9a0
// 005db99d  894a08               mov dword ptr [edx + 8], ecx
// 005db9a0  8901                 mov dword ptr [ecx], eax
// 005db9a2  894804               mov dword ptr [eax + 4], ecx
// 005db9a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005db9a8  80793c00             cmp byte ptr [ecx + 0x3c], 0
// 005db9ac  8d4604               lea eax, [esi + 4]
// 005db9af  0f841bffffff         je 0x5db8d0
// 005db9b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005db9b8  8b4204               mov eax, dword ptr [edx + 4]
// 005db9bb  88583c               mov byte ptr [eax + 0x3c], bl
// 005db9be  8b442464             mov eax, dword ptr [esp + 0x64]
// 005db9c2  8b0f                 mov ecx, dword ptr [edi]
// 005db9c4  5e                   pop esi
// 005db9c5  896804               mov dword ptr [eax + 4], ebp
// 005db9c8  5d                   pop ebp
// 005db9c9  8908                 mov dword ptr [eax], ecx
// 005db9cb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005db9cf  5b                   pop ebx
// 005db9d0  5f                   pop edi
// 005db9d1  64890d00000000       mov dword ptr fs:[0], ecx
// 005db9d8  83c450               add esp, 0x50
// 005db9db  c21000               ret 0x10
// standard library map_str<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
