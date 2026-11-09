// from server: 100% by auto
// roc 2008-06 00497900  unit: RBX::Network::Players  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00497900
//
// 00497900  64a100000000         mov eax, dword ptr fs:[0]
// 00497906  6aff                 push -1
// 00497908  6842e87d00           push 0x7de842
// 0049790d  50                   push eax
// 0049790e  64892500000000       mov dword ptr fs:[0], esp
// 00497915  83ec44               sub esp, 0x44
// 00497918  57                   push edi
// 00497919  8bf9                 mov edi, ecx
// 0049791b  817f1c54555515       cmp dword ptr [edi + 0x1c], 0x15555554
// 00497922  7259                 jb 0x49797d
// 00497924  688cb28000           push 0x80b28c
// 00497929  8d4c2408             lea ecx, [esp + 8]
// 0049792d  ff1558248000         call dword ptr [0x802458]
// 00497933  8d4c2420             lea ecx, [esp + 0x20]
// 00497937  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0049793f  ff1598288000         call dword ptr [0x802898]
// 00497945  8d442404             lea eax, [esp + 4]
// 00497949  50                   push eax
// 0049794a  8d4c2430             lea ecx, [esp + 0x30]
// 0049794e  c644245401           mov byte ptr [esp + 0x54], 1
// 00497953  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0049795b  ff155c248000         call dword ptr [0x80245c]
// 00497961  68c00c8d00           push 0x8d0cc0
// 00497966  8d4c2424             lea ecx, [esp + 0x24]
// 0049796a  51                   push ecx
// 0049796b  c644245800           mov byte ptr [esp + 0x58], 0
// 00497970  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00497978  e80f9c2000           call 0x6a158c
// 0049797d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00497981  8b4718               mov eax, dword ptr [edi + 0x18]
// 00497984  53                   push ebx
// 00497985  55                   push ebp
// 00497986  56                   push esi
// 00497987  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0049798b  6a00                 push 0
// 0049798d  52                   push edx
// 0049798e  50                   push eax
// 0049798f  56                   push esi
// 00497990  50                   push eax
// 00497991  e8faf6ffff           call 0x497090
// 00497996  8be8                 mov ebp, eax
// 00497998  8b4718               mov eax, dword ptr [edi + 0x18]
// 0049799b  bb01000000           mov ebx, 1
// 004979a0  015f1c               add dword ptr [edi + 0x1c], ebx
// 004979a3  3bf0                 cmp esi, eax
// 004979a5  7510                 jne 0x4979b7
// 004979a7  896804               mov dword ptr [eax + 4], ebp
// 004979aa  8b4718               mov eax, dword ptr [edi + 0x18]
// 004979ad  8928                 mov dword ptr [eax], ebp
// 004979af  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004979b2  896908               mov dword ptr [ecx + 8], ebp
// 004979b5  eb22                 jmp 0x4979d9
// 004979b7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004979bc  740d                 je 0x4979cb
// 004979be  892e                 mov dword ptr [esi], ebp
// 004979c0  8b4718               mov eax, dword ptr [edi + 0x18]
// 004979c3  3b30                 cmp esi, dword ptr [eax]
// 004979c5  7512                 jne 0x4979d9
// 004979c7  8928                 mov dword ptr [eax], ebp
// 004979c9  eb0e                 jmp 0x4979d9
// 004979cb  896e08               mov dword ptr [esi + 8], ebp
// 004979ce  8b4718               mov eax, dword ptr [edi + 0x18]
// 004979d1  3b7008               cmp esi, dword ptr [eax + 8]
// 004979d4  7503                 jne 0x4979d9
// 004979d6  896808               mov dword ptr [eax + 8], ebp
// 004979d9  8b5504               mov edx, dword ptr [ebp + 4]
// 004979dc  807a1800             cmp byte ptr [edx + 0x18], 0
// 004979e0  8d4504               lea eax, [ebp + 4]
// 004979e3  8bf5                 mov esi, ebp
// 004979e5  0f85ea000000         jne 0x497ad5
// 004979eb  eb03                 jmp 0x4979f0
// 004979ed  8d4900               lea ecx, [ecx]
// 004979f0  8b08                 mov ecx, dword ptr [eax]
// 004979f2  8b5104               mov edx, dword ptr [ecx + 4]
// 004979f5  3b0a                 cmp ecx, dword ptr [edx]
// 004979f7  7551                 jne 0x497a4a
// 004979f9  8b5208               mov edx, dword ptr [edx + 8]
// 004979fc  807a1800             cmp byte ptr [edx + 0x18], 0
// 00497a00  7519                 jne 0x497a1b
// 00497a02  885918               mov byte ptr [ecx + 0x18], bl
// 00497a05  885a18               mov byte ptr [edx + 0x18], bl
// 00497a08  8b10                 mov edx, dword ptr [eax]
// 00497a0a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00497a0d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00497a11  8b10                 mov edx, dword ptr [eax]
// 00497a13  8b7204               mov esi, dword ptr [edx + 4]
// 00497a16  e9aa000000           jmp 0x497ac5
// 00497a1b  3b7108               cmp esi, dword ptr [ecx + 8]
// 00497a1e  750a                 jne 0x497a2a
// 00497a20  8bf1                 mov esi, ecx
// 00497a22  56                   push esi
// 00497a23  8bcf                 mov ecx, edi
// 00497a25  e8c6430100           call 0x4abdf0
// 00497a2a  8b4604               mov eax, dword ptr [esi + 4]
// 00497a2d  885818               mov byte ptr [eax + 0x18], bl
// 00497a30  8b4e04               mov ecx, dword ptr [esi + 4]
// 00497a33  8b5104               mov edx, dword ptr [ecx + 4]
// 00497a36  c6421800             mov byte ptr [edx + 0x18], 0
// 00497a3a  8b4604               mov eax, dword ptr [esi + 4]
// 00497a3d  8b4804               mov ecx, dword ptr [eax + 4]
// 00497a40  51                   push ecx
// 00497a41  8bcf                 mov ecx, edi
// 00497a43  e818f90e00           call 0x587360
// 00497a48  eb7b                 jmp 0x497ac5
// 00497a4a  8b12                 mov edx, dword ptr [edx]
// 00497a4c  807a1800             cmp byte ptr [edx + 0x18], 0
// 00497a50  7516                 jne 0x497a68
// 00497a52  885918               mov byte ptr [ecx + 0x18], bl
// 00497a55  885a18               mov byte ptr [edx + 0x18], bl
// 00497a58  8b10                 mov edx, dword ptr [eax]
// 00497a5a  8b4a04               mov ecx, dword ptr [edx + 4]
// 00497a5d  c6411800             mov byte ptr [ecx + 0x18], 0
// 00497a61  8b10                 mov edx, dword ptr [eax]
// 00497a63  8b7204               mov esi, dword ptr [edx + 4]
// 00497a66  eb5d                 jmp 0x497ac5
// 00497a68  3b31                 cmp esi, dword ptr [ecx]
// 00497a6a  750a                 jne 0x497a76
// 00497a6c  8bf1                 mov esi, ecx
// 00497a6e  56                   push esi
// 00497a6f  8bcf                 mov ecx, edi
// 00497a71  e8eaf80e00           call 0x587360
// 00497a76  8b4604               mov eax, dword ptr [esi + 4]
// 00497a79  885818               mov byte ptr [eax + 0x18], bl
// 00497a7c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00497a7f  8b5104               mov edx, dword ptr [ecx + 4]
// 00497a82  c6421800             mov byte ptr [edx + 0x18], 0
// 00497a86  8b4604               mov eax, dword ptr [esi + 4]
// 00497a89  8b4004               mov eax, dword ptr [eax + 4]
// 00497a8c  8b4808               mov ecx, dword ptr [eax + 8]
// 00497a8f  8b11                 mov edx, dword ptr [ecx]
// 00497a91  895008               mov dword ptr [eax + 8], edx
// 00497a94  8b11                 mov edx, dword ptr [ecx]
// 00497a96  807a1900             cmp byte ptr [edx + 0x19], 0
// 00497a9a  7503                 jne 0x497a9f
// 00497a9c  894204               mov dword ptr [edx + 4], eax
// 00497a9f  8b5004               mov edx, dword ptr [eax + 4]
// 00497aa2  895104               mov dword ptr [ecx + 4], edx
// 00497aa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00497aa8  3b4204               cmp eax, dword ptr [edx + 4]
// 00497aab  7505                 jne 0x497ab2
// 00497aad  894a04               mov dword ptr [edx + 4], ecx
// 00497ab0  eb0e                 jmp 0x497ac0
// 00497ab2  8b5004               mov edx, dword ptr [eax + 4]
// 00497ab5  3b02                 cmp eax, dword ptr [edx]
// 00497ab7  7504                 jne 0x497abd
// 00497ab9  890a                 mov dword ptr [edx], ecx
// 00497abb  eb03                 jmp 0x497ac0
// 00497abd  894a08               mov dword ptr [edx + 8], ecx
// 00497ac0  8901                 mov dword ptr [ecx], eax
// 00497ac2  894804               mov dword ptr [eax + 4], ecx
// 00497ac5  8b4e04               mov ecx, dword ptr [esi + 4]
// 00497ac8  80791800             cmp byte ptr [ecx + 0x18], 0
// 00497acc  8d4604               lea eax, [esi + 4]
// 00497acf  0f841bffffff         je 0x4979f0
// 00497ad5  8b5718               mov edx, dword ptr [edi + 0x18]
// 00497ad8  8b4204               mov eax, dword ptr [edx + 4]
// 00497adb  885818               mov byte ptr [eax + 0x18], bl
// 00497ade  8b442464             mov eax, dword ptr [esp + 0x64]
// 00497ae2  8b0f                 mov ecx, dword ptr [edi]
// 00497ae4  5e                   pop esi
// 00497ae5  896804               mov dword ptr [eax + 4], ebp
// 00497ae8  5d                   pop ebp
// 00497ae9  8908                 mov dword ptr [eax], ecx
// 00497aeb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00497aef  5b                   pop ebx
// 00497af0  5f                   pop edi
// 00497af1  64890d00000000       mov dword ptr fs:[0], ecx
// 00497af8  83c450               add esp, 0x50
// 00497afb  c21000               ret 0x10
// standard library map_int<pod8> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod8>
struct E { int v[2]; };
#include <map>
template class std::map<int, E>;
