// from server: 100% by auto
// roc 2008-06 006922f0  unit: Ogre::RbxSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006922f0
//
// 006922f0  64a100000000         mov eax, dword ptr fs:[0]
// 006922f6  6aff                 push -1
// 006922f8  6842e87d00           push 0x7de842
// 006922fd  50                   push eax
// 006922fe  64892500000000       mov dword ptr fs:[0], esp
// 00692305  83ec44               sub esp, 0x44
// 00692308  57                   push edi
// 00692309  8bf9                 mov edi, ecx
// 0069230b  817f1c5c74d105       cmp dword ptr [edi + 0x1c], 0x5d1745c
// 00692312  7259                 jb 0x69236d
// 00692314  688cb28000           push 0x80b28c
// 00692319  8d4c2408             lea ecx, [esp + 8]
// 0069231d  ff1558248000         call dword ptr [0x802458]
// 00692323  8d4c2420             lea ecx, [esp + 0x20]
// 00692327  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0069232f  ff1598288000         call dword ptr [0x802898]
// 00692335  8d442404             lea eax, [esp + 4]
// 00692339  50                   push eax
// 0069233a  8d4c2430             lea ecx, [esp + 0x30]
// 0069233e  c644245401           mov byte ptr [esp + 0x54], 1
// 00692343  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 0069234b  ff155c248000         call dword ptr [0x80245c]
// 00692351  68c00c8d00           push 0x8d0cc0
// 00692356  8d4c2424             lea ecx, [esp + 0x24]
// 0069235a  51                   push ecx
// 0069235b  c644245800           mov byte ptr [esp + 0x58], 0
// 00692360  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 00692368  e81ff20000           call 0x6a158c
// 0069236d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00692371  8b4718               mov eax, dword ptr [edi + 0x18]
// 00692374  53                   push ebx
// 00692375  55                   push ebp
// 00692376  56                   push esi
// 00692377  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0069237b  6a00                 push 0
// 0069237d  52                   push edx
// 0069237e  50                   push eax
// 0069237f  56                   push esi
// 00692380  50                   push eax
// 00692381  e89addffff           call 0x690120
// 00692386  8be8                 mov ebp, eax
// 00692388  8b4718               mov eax, dword ptr [edi + 0x18]
// 0069238b  bb01000000           mov ebx, 1
// 00692390  015f1c               add dword ptr [edi + 0x1c], ebx
// 00692393  3bf0                 cmp esi, eax
// 00692395  7510                 jne 0x6923a7
// 00692397  896804               mov dword ptr [eax + 4], ebp
// 0069239a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0069239d  8928                 mov dword ptr [eax], ebp
// 0069239f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006923a2  896908               mov dword ptr [ecx + 8], ebp
// 006923a5  eb22                 jmp 0x6923c9
// 006923a7  807c246800           cmp byte ptr [esp + 0x68], 0
// 006923ac  740d                 je 0x6923bb
// 006923ae  892e                 mov dword ptr [esi], ebp
// 006923b0  8b4718               mov eax, dword ptr [edi + 0x18]
// 006923b3  3b30                 cmp esi, dword ptr [eax]
// 006923b5  7512                 jne 0x6923c9
// 006923b7  8928                 mov dword ptr [eax], ebp
// 006923b9  eb0e                 jmp 0x6923c9
// 006923bb  896e08               mov dword ptr [esi + 8], ebp
// 006923be  8b4718               mov eax, dword ptr [edi + 0x18]
// 006923c1  3b7008               cmp esi, dword ptr [eax + 8]
// 006923c4  7503                 jne 0x6923c9
// 006923c6  896808               mov dword ptr [eax + 8], ebp
// 006923c9  8b5504               mov edx, dword ptr [ebp + 4]
// 006923cc  807a3800             cmp byte ptr [edx + 0x38], 0
// 006923d0  8d4504               lea eax, [ebp + 4]
// 006923d3  8bf5                 mov esi, ebp
// 006923d5  0f85ea000000         jne 0x6924c5
// 006923db  eb03                 jmp 0x6923e0
// 006923dd  8d4900               lea ecx, [ecx]
// 006923e0  8b08                 mov ecx, dword ptr [eax]
// 006923e2  8b5104               mov edx, dword ptr [ecx + 4]
// 006923e5  3b0a                 cmp ecx, dword ptr [edx]
// 006923e7  7551                 jne 0x69243a
// 006923e9  8b5208               mov edx, dword ptr [edx + 8]
// 006923ec  807a3800             cmp byte ptr [edx + 0x38], 0
// 006923f0  7519                 jne 0x69240b
// 006923f2  885938               mov byte ptr [ecx + 0x38], bl
// 006923f5  885a38               mov byte ptr [edx + 0x38], bl
// 006923f8  8b10                 mov edx, dword ptr [eax]
// 006923fa  8b4a04               mov ecx, dword ptr [edx + 4]
// 006923fd  c6413800             mov byte ptr [ecx + 0x38], 0
// 00692401  8b10                 mov edx, dword ptr [eax]
// 00692403  8b7204               mov esi, dword ptr [edx + 4]
// 00692406  e9aa000000           jmp 0x6924b5
// 0069240b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0069240e  750a                 jne 0x69241a
// 00692410  8bf1                 mov esi, ecx
// 00692412  56                   push esi
// 00692413  8bcf                 mov ecx, edi
// 00692415  e836bbffff           call 0x68df50
// 0069241a  8b4604               mov eax, dword ptr [esi + 4]
// 0069241d  885838               mov byte ptr [eax + 0x38], bl
// 00692420  8b4e04               mov ecx, dword ptr [esi + 4]
// 00692423  8b5104               mov edx, dword ptr [ecx + 4]
// 00692426  c6423800             mov byte ptr [edx + 0x38], 0
// 0069242a  8b4604               mov eax, dword ptr [esi + 4]
// 0069242d  8b4804               mov ecx, dword ptr [eax + 4]
// 00692430  51                   push ecx
// 00692431  8bcf                 mov ecx, edi
// 00692433  e808adffff           call 0x68d140
// 00692438  eb7b                 jmp 0x6924b5
// 0069243a  8b12                 mov edx, dword ptr [edx]
// 0069243c  807a3800             cmp byte ptr [edx + 0x38], 0
// 00692440  7516                 jne 0x692458
// 00692442  885938               mov byte ptr [ecx + 0x38], bl
// 00692445  885a38               mov byte ptr [edx + 0x38], bl
// 00692448  8b10                 mov edx, dword ptr [eax]
// 0069244a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0069244d  c6413800             mov byte ptr [ecx + 0x38], 0
// 00692451  8b10                 mov edx, dword ptr [eax]
// 00692453  8b7204               mov esi, dword ptr [edx + 4]
// 00692456  eb5d                 jmp 0x6924b5
// 00692458  3b31                 cmp esi, dword ptr [ecx]
// 0069245a  750a                 jne 0x692466
// 0069245c  8bf1                 mov esi, ecx
// 0069245e  56                   push esi
// 0069245f  8bcf                 mov ecx, edi
// 00692461  e8daacffff           call 0x68d140
// 00692466  8b4604               mov eax, dword ptr [esi + 4]
// 00692469  885838               mov byte ptr [eax + 0x38], bl
// 0069246c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0069246f  8b5104               mov edx, dword ptr [ecx + 4]
// 00692472  c6423800             mov byte ptr [edx + 0x38], 0
// 00692476  8b4604               mov eax, dword ptr [esi + 4]
// 00692479  8b4004               mov eax, dword ptr [eax + 4]
// 0069247c  8b4808               mov ecx, dword ptr [eax + 8]
// 0069247f  8b11                 mov edx, dword ptr [ecx]
// 00692481  895008               mov dword ptr [eax + 8], edx
// 00692484  8b11                 mov edx, dword ptr [ecx]
// 00692486  807a3900             cmp byte ptr [edx + 0x39], 0
// 0069248a  7503                 jne 0x69248f
// 0069248c  894204               mov dword ptr [edx + 4], eax
// 0069248f  8b5004               mov edx, dword ptr [eax + 4]
// 00692492  895104               mov dword ptr [ecx + 4], edx
// 00692495  8b5718               mov edx, dword ptr [edi + 0x18]
// 00692498  3b4204               cmp eax, dword ptr [edx + 4]
// 0069249b  7505                 jne 0x6924a2
// 0069249d  894a04               mov dword ptr [edx + 4], ecx
// 006924a0  eb0e                 jmp 0x6924b0
// 006924a2  8b5004               mov edx, dword ptr [eax + 4]
// 006924a5  3b02                 cmp eax, dword ptr [edx]
// 006924a7  7504                 jne 0x6924ad
// 006924a9  890a                 mov dword ptr [edx], ecx
// 006924ab  eb03                 jmp 0x6924b0
// 006924ad  894a08               mov dword ptr [edx + 8], ecx
// 006924b0  8901                 mov dword ptr [ecx], eax
// 006924b2  894804               mov dword ptr [eax + 4], ecx
// 006924b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 006924b8  80793800             cmp byte ptr [ecx + 0x38], 0
// 006924bc  8d4604               lea eax, [esi + 4]
// 006924bf  0f841bffffff         je 0x6923e0
// 006924c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 006924c8  8b4204               mov eax, dword ptr [edx + 4]
// 006924cb  885838               mov byte ptr [eax + 0x38], bl
// 006924ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 006924d2  8b0f                 mov ecx, dword ptr [edi]
// 006924d4  5e                   pop esi
// 006924d5  896804               mov dword ptr [eax + 4], ebp
// 006924d8  5d                   pop ebp
// 006924d9  8908                 mov dword ptr [eax], ecx
// 006924db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 006924df  5b                   pop ebx
// 006924e0  5f                   pop edi
// 006924e1  64890d00000000       mov dword ptr fs:[0], ecx
// 006924e8  83c450               add esp, 0x50
// 006924eb  c21000               ret 0x10
// standard library map_int<pod40> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod40>
struct E { int v[10]; };
#include <map>
template class std::map<int, E>;
