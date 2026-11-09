// from server: 100% by auto
// roc 2010-06 00540780  unit: RBX::AggregatingSceneManager  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00540780
//
// 00540780  64a100000000         mov eax, dword ptr fs:[0]
// 00540786  6aff                 push -1
// 00540788  68e22f9a00           push 0x9a2fe2
// 0054078d  50                   push eax
// 0054078e  64892500000000       mov dword ptr fs:[0], esp
// 00540795  83ec44               sub esp, 0x44
// 00540798  57                   push edi
// 00540799  8bf9                 mov edi, ecx
// 0054079b  817f1cfeffff1f       cmp dword ptr [edi + 0x1c], 0x1ffffffe
// 005407a2  7259                 jb 0x5407fd
// 005407a4  68a800a000           push 0xa000a8
// 005407a9  8d4c2408             lea ecx, [esp + 8]
// 005407ad  ff1510a49e00         call dword ptr [0x9ea410]
// 005407b3  8d4c2420             lea ecx, [esp + 0x20]
// 005407b7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005407bf  ff1518a99e00         call dword ptr [0x9ea918]
// 005407c5  8d442404             lea eax, [esp + 4]
// 005407c9  50                   push eax
// 005407ca  8d4c2430             lea ecx, [esp + 0x30]
// 005407ce  c644245401           mov byte ptr [esp + 0x54], 1
// 005407d3  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005407db  ff150ca49e00         call dword ptr [0x9ea40c]
// 005407e1  68601bb000           push 0xb01b60
// 005407e6  8d4c2424             lea ecx, [esp + 0x24]
// 005407ea  51                   push ecx
// 005407eb  c644245800           mov byte ptr [esp + 0x58], 0
// 005407f0  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005407f8  e8b5812600           call 0x7a89b2
// 005407fd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00540801  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540804  53                   push ebx
// 00540805  55                   push ebp
// 00540806  56                   push esi
// 00540807  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0054080b  6a00                 push 0
// 0054080d  52                   push edx
// 0054080e  50                   push eax
// 0054080f  56                   push esi
// 00540810  50                   push eax
// 00540811  e8cafcffff           call 0x5404e0
// 00540816  8be8                 mov ebp, eax
// 00540818  8b4718               mov eax, dword ptr [edi + 0x18]
// 0054081b  bb01000000           mov ebx, 1
// 00540820  015f1c               add dword ptr [edi + 0x1c], ebx
// 00540823  3bf0                 cmp esi, eax
// 00540825  7510                 jne 0x540837
// 00540827  896804               mov dword ptr [eax + 4], ebp
// 0054082a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0054082d  8928                 mov dword ptr [eax], ebp
// 0054082f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00540832  896908               mov dword ptr [ecx + 8], ebp
// 00540835  eb22                 jmp 0x540859
// 00540837  807c246800           cmp byte ptr [esp + 0x68], 0
// 0054083c  740d                 je 0x54084b
// 0054083e  892e                 mov dword ptr [esi], ebp
// 00540840  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540843  3b30                 cmp esi, dword ptr [eax]
// 00540845  7512                 jne 0x540859
// 00540847  8928                 mov dword ptr [eax], ebp
// 00540849  eb0e                 jmp 0x540859
// 0054084b  896e08               mov dword ptr [esi + 8], ebp
// 0054084e  8b4718               mov eax, dword ptr [edi + 0x18]
// 00540851  3b7008               cmp esi, dword ptr [eax + 8]
// 00540854  7503                 jne 0x540859
// 00540856  896808               mov dword ptr [eax + 8], ebp
// 00540859  8b5504               mov edx, dword ptr [ebp + 4]
// 0054085c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00540860  8d4504               lea eax, [ebp + 4]
// 00540863  8bf5                 mov esi, ebp
// 00540865  0f85ea000000         jne 0x540955
// 0054086b  eb03                 jmp 0x540870
// 0054086d  8d4900               lea ecx, [ecx]
// 00540870  8b08                 mov ecx, dword ptr [eax]
// 00540872  8b5104               mov edx, dword ptr [ecx + 4]
// 00540875  3b0a                 cmp ecx, dword ptr [edx]
// 00540877  7551                 jne 0x5408ca
// 00540879  8b5208               mov edx, dword ptr [edx + 8]
// 0054087c  807a1400             cmp byte ptr [edx + 0x14], 0
// 00540880  7519                 jne 0x54089b
// 00540882  885914               mov byte ptr [ecx + 0x14], bl
// 00540885  885a14               mov byte ptr [edx + 0x14], bl
// 00540888  8b10                 mov edx, dword ptr [eax]
// 0054088a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0054088d  c6411400             mov byte ptr [ecx + 0x14], 0
// 00540891  8b10                 mov edx, dword ptr [eax]
// 00540893  8b7204               mov esi, dword ptr [edx + 4]
// 00540896  e9aa000000           jmp 0x540945
// 0054089b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0054089e  750a                 jne 0x5408aa
// 005408a0  8bf1                 mov esi, ecx
// 005408a2  56                   push esi
// 005408a3  8bcf                 mov ecx, edi
// 005408a5  e876ba0600           call 0x5ac320
// 005408aa  8b4604               mov eax, dword ptr [esi + 4]
// 005408ad  885814               mov byte ptr [eax + 0x14], bl
// 005408b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 005408b3  8b5104               mov edx, dword ptr [ecx + 4]
// 005408b6  c6421400             mov byte ptr [edx + 0x14], 0
// 005408ba  8b4604               mov eax, dword ptr [esi + 4]
// 005408bd  8b4804               mov ecx, dword ptr [eax + 4]
// 005408c0  51                   push ecx
// 005408c1  8bcf                 mov ecx, edi
// 005408c3  e838830800           call 0x5c8c00
// 005408c8  eb7b                 jmp 0x540945
// 005408ca  8b12                 mov edx, dword ptr [edx]
// 005408cc  807a1400             cmp byte ptr [edx + 0x14], 0
// 005408d0  7516                 jne 0x5408e8
// 005408d2  885914               mov byte ptr [ecx + 0x14], bl
// 005408d5  885a14               mov byte ptr [edx + 0x14], bl
// 005408d8  8b10                 mov edx, dword ptr [eax]
// 005408da  8b4a04               mov ecx, dword ptr [edx + 4]
// 005408dd  c6411400             mov byte ptr [ecx + 0x14], 0
// 005408e1  8b10                 mov edx, dword ptr [eax]
// 005408e3  8b7204               mov esi, dword ptr [edx + 4]
// 005408e6  eb5d                 jmp 0x540945
// 005408e8  3b31                 cmp esi, dword ptr [ecx]
// 005408ea  750a                 jne 0x5408f6
// 005408ec  8bf1                 mov esi, ecx
// 005408ee  56                   push esi
// 005408ef  8bcf                 mov ecx, edi
// 005408f1  e80a830800           call 0x5c8c00
// 005408f6  8b4604               mov eax, dword ptr [esi + 4]
// 005408f9  885814               mov byte ptr [eax + 0x14], bl
// 005408fc  8b4e04               mov ecx, dword ptr [esi + 4]
// 005408ff  8b5104               mov edx, dword ptr [ecx + 4]
// 00540902  c6421400             mov byte ptr [edx + 0x14], 0
// 00540906  8b4604               mov eax, dword ptr [esi + 4]
// 00540909  8b4004               mov eax, dword ptr [eax + 4]
// 0054090c  8b4808               mov ecx, dword ptr [eax + 8]
// 0054090f  8b11                 mov edx, dword ptr [ecx]
// 00540911  895008               mov dword ptr [eax + 8], edx
// 00540914  8b11                 mov edx, dword ptr [ecx]
// 00540916  807a1500             cmp byte ptr [edx + 0x15], 0
// 0054091a  7503                 jne 0x54091f
// 0054091c  894204               mov dword ptr [edx + 4], eax
// 0054091f  8b5004               mov edx, dword ptr [eax + 4]
// 00540922  895104               mov dword ptr [ecx + 4], edx
// 00540925  8b5718               mov edx, dword ptr [edi + 0x18]
// 00540928  3b4204               cmp eax, dword ptr [edx + 4]
// 0054092b  7505                 jne 0x540932
// 0054092d  894a04               mov dword ptr [edx + 4], ecx
// 00540930  eb0e                 jmp 0x540940
// 00540932  8b5004               mov edx, dword ptr [eax + 4]
// 00540935  3b02                 cmp eax, dword ptr [edx]
// 00540937  7504                 jne 0x54093d
// 00540939  890a                 mov dword ptr [edx], ecx
// 0054093b  eb03                 jmp 0x540940
// 0054093d  894a08               mov dword ptr [edx + 8], ecx
// 00540940  8901                 mov dword ptr [ecx], eax
// 00540942  894804               mov dword ptr [eax + 4], ecx
// 00540945  8b4e04               mov ecx, dword ptr [esi + 4]
// 00540948  80791400             cmp byte ptr [ecx + 0x14], 0
// 0054094c  8d4604               lea eax, [esi + 4]
// 0054094f  0f841bffffff         je 0x540870
// 00540955  8b5718               mov edx, dword ptr [edi + 0x18]
// 00540958  8b4204               mov eax, dword ptr [edx + 4]
// 0054095b  885814               mov byte ptr [eax + 0x14], bl
// 0054095e  8b442464             mov eax, dword ptr [esp + 0x64]
// 00540962  8b0f                 mov ecx, dword ptr [edi]
// 00540964  5e                   pop esi
// 00540965  896804               mov dword ptr [eax + 4], ebp
// 00540968  5d                   pop ebp
// 00540969  8908                 mov dword ptr [eax], ecx
// 0054096b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0054096f  5b                   pop ebx
// 00540970  5f                   pop edi
// 00540971  64890d00000000       mov dword ptr fs:[0], ecx
// 00540978  83c450               add esp, 0x50
// 0054097b  c21000               ret 0x10
// standard library map_int<ptr> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
