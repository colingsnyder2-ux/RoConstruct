// from server: 100% by auto
// roc 2008-06 0055e8d0  unit: RBX::MD5HasherImpl  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e8d0
//
// 0055e8d0  64a100000000         mov eax, dword ptr fs:[0]
// 0055e8d6  6aff                 push -1
// 0055e8d8  6842e87d00           push 0x7de842
// 0055e8dd  50                   push eax
// 0055e8de  64892500000000       mov dword ptr fs:[0], esp
// 0055e8e5  83ec44               sub esp, 0x44
// 0055e8e8  57                   push edi
// 0055e8e9  8bf9                 mov edi, ecx
// 0055e8eb  817f1c54555505       cmp dword ptr [edi + 0x1c], 0x5555554
// 0055e8f2  7259                 jb 0x55e94d
// 0055e8f4  688cb28000           push 0x80b28c
// 0055e8f9  8d4c2408             lea ecx, [esp + 8]
// 0055e8fd  ff1558248000         call dword ptr [0x802458]
// 0055e903  8d4c2420             lea ecx, [esp + 0x20]
// 0055e907  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0055e90f  ff1598288000         call dword ptr [0x802898]
// 0055e915  8d442404             lea eax, [esp + 4]
// 0055e919  50                   push eax
// 0055e91a  8d4c2430             lea ecx, [esp + 0x30]
// 0055e91e  c644245401           mov byte ptr [esp + 0x54], 1
// 0055e923  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0055e92b  ff155c248000         call dword ptr [0x80245c]
// 0055e931  68c00c8d00           push 0x8d0cc0
// 0055e936  8d4c2424             lea ecx, [esp + 0x24]
// 0055e93a  51                   push ecx
// 0055e93b  c644245800           mov byte ptr [esp + 0x58], 0
// 0055e940  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 0055e948  e83f2c1400           call 0x6a158c
// 0055e94d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0055e951  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055e954  53                   push ebx
// 0055e955  55                   push ebp
// 0055e956  56                   push esi
// 0055e957  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0055e95b  6a00                 push 0
// 0055e95d  52                   push edx
// 0055e95e  50                   push eax
// 0055e95f  56                   push esi
// 0055e960  50                   push eax
// 0055e961  e8aaf6ffff           call 0x55e010
// 0055e966  8be8                 mov ebp, eax
// 0055e968  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055e96b  bb01000000           mov ebx, 1
// 0055e970  015f1c               add dword ptr [edi + 0x1c], ebx
// 0055e973  3bf0                 cmp esi, eax
// 0055e975  7510                 jne 0x55e987
// 0055e977  896804               mov dword ptr [eax + 4], ebp
// 0055e97a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055e97d  8928                 mov dword ptr [eax], ebp
// 0055e97f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0055e982  896908               mov dword ptr [ecx + 8], ebp
// 0055e985  eb22                 jmp 0x55e9a9
// 0055e987  807c246800           cmp byte ptr [esp + 0x68], 0
// 0055e98c  740d                 je 0x55e99b
// 0055e98e  892e                 mov dword ptr [esi], ebp
// 0055e990  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055e993  3b30                 cmp esi, dword ptr [eax]
// 0055e995  7512                 jne 0x55e9a9
// 0055e997  8928                 mov dword ptr [eax], ebp
// 0055e999  eb0e                 jmp 0x55e9a9
// 0055e99b  896e08               mov dword ptr [esi + 8], ebp
// 0055e99e  8b4718               mov eax, dword ptr [edi + 0x18]
// 0055e9a1  3b7008               cmp esi, dword ptr [eax + 8]
// 0055e9a4  7503                 jne 0x55e9a9
// 0055e9a6  896808               mov dword ptr [eax + 8], ebp
// 0055e9a9  8b5504               mov edx, dword ptr [ebp + 4]
// 0055e9ac  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 0055e9b0  8d4504               lea eax, [ebp + 4]
// 0055e9b3  8bf5                 mov esi, ebp
// 0055e9b5  0f85ea000000         jne 0x55eaa5
// 0055e9bb  eb03                 jmp 0x55e9c0
// 0055e9bd  8d4900               lea ecx, [ecx]
// 0055e9c0  8b08                 mov ecx, dword ptr [eax]
// 0055e9c2  8b5104               mov edx, dword ptr [ecx + 4]
// 0055e9c5  3b0a                 cmp ecx, dword ptr [edx]
// 0055e9c7  7551                 jne 0x55ea1a
// 0055e9c9  8b5208               mov edx, dword ptr [edx + 8]
// 0055e9cc  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 0055e9d0  7519                 jne 0x55e9eb
// 0055e9d2  88593c               mov byte ptr [ecx + 0x3c], bl
// 0055e9d5  885a3c               mov byte ptr [edx + 0x3c], bl
// 0055e9d8  8b10                 mov edx, dword ptr [eax]
// 0055e9da  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055e9dd  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 0055e9e1  8b10                 mov edx, dword ptr [eax]
// 0055e9e3  8b7204               mov esi, dword ptr [edx + 4]
// 0055e9e6  e9aa000000           jmp 0x55ea95
// 0055e9eb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0055e9ee  750a                 jne 0x55e9fa
// 0055e9f0  8bf1                 mov esi, ecx
// 0055e9f2  56                   push esi
// 0055e9f3  8bcf                 mov ecx, edi
// 0055e9f5  e8a6d3f4ff           call 0x4abda0
// 0055e9fa  8b4604               mov eax, dword ptr [esi + 4]
// 0055e9fd  88583c               mov byte ptr [eax + 0x3c], bl
// 0055ea00  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055ea03  8b5104               mov edx, dword ptr [ecx + 4]
// 0055ea06  c6423c00             mov byte ptr [edx + 0x3c], 0
// 0055ea0a  8b4604               mov eax, dword ptr [esi + 4]
// 0055ea0d  8b4804               mov ecx, dword ptr [eax + 4]
// 0055ea10  51                   push ecx
// 0055ea11  8bcf                 mov ecx, edi
// 0055ea13  e8f8c5f4ff           call 0x4ab010
// 0055ea18  eb7b                 jmp 0x55ea95
// 0055ea1a  8b12                 mov edx, dword ptr [edx]
// 0055ea1c  807a3c00             cmp byte ptr [edx + 0x3c], 0
// 0055ea20  7516                 jne 0x55ea38
// 0055ea22  88593c               mov byte ptr [ecx + 0x3c], bl
// 0055ea25  885a3c               mov byte ptr [edx + 0x3c], bl
// 0055ea28  8b10                 mov edx, dword ptr [eax]
// 0055ea2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0055ea2d  c6413c00             mov byte ptr [ecx + 0x3c], 0
// 0055ea31  8b10                 mov edx, dword ptr [eax]
// 0055ea33  8b7204               mov esi, dword ptr [edx + 4]
// 0055ea36  eb5d                 jmp 0x55ea95
// 0055ea38  3b31                 cmp esi, dword ptr [ecx]
// 0055ea3a  750a                 jne 0x55ea46
// 0055ea3c  8bf1                 mov esi, ecx
// 0055ea3e  56                   push esi
// 0055ea3f  8bcf                 mov ecx, edi
// 0055ea41  e8cac5f4ff           call 0x4ab010
// 0055ea46  8b4604               mov eax, dword ptr [esi + 4]
// 0055ea49  88583c               mov byte ptr [eax + 0x3c], bl
// 0055ea4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055ea4f  8b5104               mov edx, dword ptr [ecx + 4]
// 0055ea52  c6423c00             mov byte ptr [edx + 0x3c], 0
// 0055ea56  8b4604               mov eax, dword ptr [esi + 4]
// 0055ea59  8b4004               mov eax, dword ptr [eax + 4]
// 0055ea5c  8b4808               mov ecx, dword ptr [eax + 8]
// 0055ea5f  8b11                 mov edx, dword ptr [ecx]
// 0055ea61  895008               mov dword ptr [eax + 8], edx
// 0055ea64  8b11                 mov edx, dword ptr [ecx]
// 0055ea66  807a3d00             cmp byte ptr [edx + 0x3d], 0
// 0055ea6a  7503                 jne 0x55ea6f
// 0055ea6c  894204               mov dword ptr [edx + 4], eax
// 0055ea6f  8b5004               mov edx, dword ptr [eax + 4]
// 0055ea72  895104               mov dword ptr [ecx + 4], edx
// 0055ea75  8b5718               mov edx, dword ptr [edi + 0x18]
// 0055ea78  3b4204               cmp eax, dword ptr [edx + 4]
// 0055ea7b  7505                 jne 0x55ea82
// 0055ea7d  894a04               mov dword ptr [edx + 4], ecx
// 0055ea80  eb0e                 jmp 0x55ea90
// 0055ea82  8b5004               mov edx, dword ptr [eax + 4]
// 0055ea85  3b02                 cmp eax, dword ptr [edx]
// 0055ea87  7504                 jne 0x55ea8d
// 0055ea89  890a                 mov dword ptr [edx], ecx
// 0055ea8b  eb03                 jmp 0x55ea90
// 0055ea8d  894a08               mov dword ptr [edx + 8], ecx
// 0055ea90  8901                 mov dword ptr [ecx], eax
// 0055ea92  894804               mov dword ptr [eax + 4], ecx
// 0055ea95  8b4e04               mov ecx, dword ptr [esi + 4]
// 0055ea98  80793c00             cmp byte ptr [ecx + 0x3c], 0
// 0055ea9c  8d4604               lea eax, [esi + 4]
// 0055ea9f  0f841bffffff         je 0x55e9c0
// 0055eaa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0055eaa8  8b4204               mov eax, dword ptr [edx + 4]
// 0055eaab  88583c               mov byte ptr [eax + 0x3c], bl
// 0055eaae  8b442464             mov eax, dword ptr [esp + 0x64]
// 0055eab2  8b0f                 mov ecx, dword ptr [edi]
// 0055eab4  5e                   pop esi
// 0055eab5  896804               mov dword ptr [eax + 4], ebp
// 0055eab8  5d                   pop ebp
// 0055eab9  8908                 mov dword ptr [eax], ecx
// 0055eabb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0055eabf  5b                   pop ebx
// 0055eac0  5f                   pop edi
// 0055eac1  64890d00000000       mov dword ptr fs:[0], ecx
// 0055eac8  83c450               add esp, 0x50
// 0055eacb  c21000               ret 0x10
// standard library map_str<pod20> (function ?_Insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
