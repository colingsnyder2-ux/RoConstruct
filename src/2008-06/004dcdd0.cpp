// from server: 100% by auto
// roc 2008-06 004dcdd0  unit: RBX::ViewNew::ViewG3D  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dcdd0
//
// 004dcdd0  64a100000000         mov eax, dword ptr fs:[0]
// 004dcdd6  6aff                 push -1
// 004dcdd8  6842e87d00           push 0x7de842
// 004dcddd  50                   push eax
// 004dcdde  64892500000000       mov dword ptr fs:[0], esp
// 004dcde5  83ec44               sub esp, 0x44
// 004dcde8  57                   push edi
// 004dcde9  8bf9                 mov edi, ecx
// 004dcdeb  817f1c65666606       cmp dword ptr [edi + 0x1c], 0x6666665
// 004dcdf2  7259                 jb 0x4dce4d
// 004dcdf4  688cb28000           push 0x80b28c
// 004dcdf9  8d4c2408             lea ecx, [esp + 8]
// 004dcdfd  ff1558248000         call dword ptr [0x802458]
// 004dce03  8d4c2420             lea ecx, [esp + 0x20]
// 004dce07  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004dce0f  ff1598288000         call dword ptr [0x802898]
// 004dce15  8d442404             lea eax, [esp + 4]
// 004dce19  50                   push eax
// 004dce1a  8d4c2430             lea ecx, [esp + 0x30]
// 004dce1e  c644245401           mov byte ptr [esp + 0x54], 1
// 004dce23  c744242410b18000     mov dword ptr [esp + 0x24], 0x80b110
// 004dce2b  ff155c248000         call dword ptr [0x80245c]
// 004dce31  68c00c8d00           push 0x8d0cc0
// 004dce36  8d4c2424             lea ecx, [esp + 0x24]
// 004dce3a  51                   push ecx
// 004dce3b  c644245800           mov byte ptr [esp + 0x58], 0
// 004dce40  c74424281cb18000     mov dword ptr [esp + 0x28], 0x80b11c
// 004dce48  e83f471c00           call 0x6a158c
// 004dce4d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004dce51  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dce54  53                   push ebx
// 004dce55  55                   push ebp
// 004dce56  56                   push esi
// 004dce57  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004dce5b  6a00                 push 0
// 004dce5d  52                   push edx
// 004dce5e  50                   push eax
// 004dce5f  56                   push esi
// 004dce60  50                   push eax
// 004dce61  e86afeffff           call 0x4dccd0
// 004dce66  8be8                 mov ebp, eax
// 004dce68  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dce6b  bb01000000           mov ebx, 1
// 004dce70  015f1c               add dword ptr [edi + 0x1c], ebx
// 004dce73  3bf0                 cmp esi, eax
// 004dce75  7510                 jne 0x4dce87
// 004dce77  896804               mov dword ptr [eax + 4], ebp
// 004dce7a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dce7d  8928                 mov dword ptr [eax], ebp
// 004dce7f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004dce82  896908               mov dword ptr [ecx + 8], ebp
// 004dce85  eb22                 jmp 0x4dcea9
// 004dce87  807c246800           cmp byte ptr [esp + 0x68], 0
// 004dce8c  740d                 je 0x4dce9b
// 004dce8e  892e                 mov dword ptr [esi], ebp
// 004dce90  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dce93  3b30                 cmp esi, dword ptr [eax]
// 004dce95  7512                 jne 0x4dcea9
// 004dce97  8928                 mov dword ptr [eax], ebp
// 004dce99  eb0e                 jmp 0x4dcea9
// 004dce9b  896e08               mov dword ptr [esi + 8], ebp
// 004dce9e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004dcea1  3b7008               cmp esi, dword ptr [eax + 8]
// 004dcea4  7503                 jne 0x4dcea9
// 004dcea6  896808               mov dword ptr [eax + 8], ebp
// 004dcea9  8b5504               mov edx, dword ptr [ebp + 4]
// 004dceac  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dceb0  8d4504               lea eax, [ebp + 4]
// 004dceb3  8bf5                 mov esi, ebp
// 004dceb5  0f85ea000000         jne 0x4dcfa5
// 004dcebb  eb03                 jmp 0x4dcec0
// 004dcebd  8d4900               lea ecx, [ecx]
// 004dcec0  8b08                 mov ecx, dword ptr [eax]
// 004dcec2  8b5104               mov edx, dword ptr [ecx + 4]
// 004dcec5  3b0a                 cmp ecx, dword ptr [edx]
// 004dcec7  7551                 jne 0x4dcf1a
// 004dcec9  8b5208               mov edx, dword ptr [edx + 8]
// 004dcecc  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dced0  7519                 jne 0x4dceeb
// 004dced2  885934               mov byte ptr [ecx + 0x34], bl
// 004dced5  885a34               mov byte ptr [edx + 0x34], bl
// 004dced8  8b10                 mov edx, dword ptr [eax]
// 004dceda  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dcedd  c6413400             mov byte ptr [ecx + 0x34], 0
// 004dcee1  8b10                 mov edx, dword ptr [eax]
// 004dcee3  8b7204               mov esi, dword ptr [edx + 4]
// 004dcee6  e9aa000000           jmp 0x4dcf95
// 004dceeb  3b7108               cmp esi, dword ptr [ecx + 8]
// 004dceee  750a                 jne 0x4dcefa
// 004dcef0  8bf1                 mov esi, ecx
// 004dcef2  56                   push esi
// 004dcef3  8bcf                 mov ecx, edi
// 004dcef5  e826f7ffff           call 0x4dc620
// 004dcefa  8b4604               mov eax, dword ptr [esi + 4]
// 004dcefd  885834               mov byte ptr [eax + 0x34], bl
// 004dcf00  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dcf03  8b5104               mov edx, dword ptr [ecx + 4]
// 004dcf06  c6423400             mov byte ptr [edx + 0x34], 0
// 004dcf0a  8b4604               mov eax, dword ptr [esi + 4]
// 004dcf0d  8b4804               mov ecx, dword ptr [eax + 4]
// 004dcf10  51                   push ecx
// 004dcf11  8bcf                 mov ecx, edi
// 004dcf13  e8c89b0d00           call 0x5b6ae0
// 004dcf18  eb7b                 jmp 0x4dcf95
// 004dcf1a  8b12                 mov edx, dword ptr [edx]
// 004dcf1c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dcf20  7516                 jne 0x4dcf38
// 004dcf22  885934               mov byte ptr [ecx + 0x34], bl
// 004dcf25  885a34               mov byte ptr [edx + 0x34], bl
// 004dcf28  8b10                 mov edx, dword ptr [eax]
// 004dcf2a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dcf2d  c6413400             mov byte ptr [ecx + 0x34], 0
// 004dcf31  8b10                 mov edx, dword ptr [eax]
// 004dcf33  8b7204               mov esi, dword ptr [edx + 4]
// 004dcf36  eb5d                 jmp 0x4dcf95
// 004dcf38  3b31                 cmp esi, dword ptr [ecx]
// 004dcf3a  750a                 jne 0x4dcf46
// 004dcf3c  8bf1                 mov esi, ecx
// 004dcf3e  56                   push esi
// 004dcf3f  8bcf                 mov ecx, edi
// 004dcf41  e89a9b0d00           call 0x5b6ae0
// 004dcf46  8b4604               mov eax, dword ptr [esi + 4]
// 004dcf49  885834               mov byte ptr [eax + 0x34], bl
// 004dcf4c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dcf4f  8b5104               mov edx, dword ptr [ecx + 4]
// 004dcf52  c6423400             mov byte ptr [edx + 0x34], 0
// 004dcf56  8b4604               mov eax, dword ptr [esi + 4]
// 004dcf59  8b4004               mov eax, dword ptr [eax + 4]
// 004dcf5c  8b4808               mov ecx, dword ptr [eax + 8]
// 004dcf5f  8b11                 mov edx, dword ptr [ecx]
// 004dcf61  895008               mov dword ptr [eax + 8], edx
// 004dcf64  8b11                 mov edx, dword ptr [ecx]
// 004dcf66  807a3500             cmp byte ptr [edx + 0x35], 0
// 004dcf6a  7503                 jne 0x4dcf6f
// 004dcf6c  894204               mov dword ptr [edx + 4], eax
// 004dcf6f  8b5004               mov edx, dword ptr [eax + 4]
// 004dcf72  895104               mov dword ptr [ecx + 4], edx
// 004dcf75  8b5718               mov edx, dword ptr [edi + 0x18]
// 004dcf78  3b4204               cmp eax, dword ptr [edx + 4]
// 004dcf7b  7505                 jne 0x4dcf82
// 004dcf7d  894a04               mov dword ptr [edx + 4], ecx
// 004dcf80  eb0e                 jmp 0x4dcf90
// 004dcf82  8b5004               mov edx, dword ptr [eax + 4]
// 004dcf85  3b02                 cmp eax, dword ptr [edx]
// 004dcf87  7504                 jne 0x4dcf8d
// 004dcf89  890a                 mov dword ptr [edx], ecx
// 004dcf8b  eb03                 jmp 0x4dcf90
// 004dcf8d  894a08               mov dword ptr [edx + 8], ecx
// 004dcf90  8901                 mov dword ptr [ecx], eax
// 004dcf92  894804               mov dword ptr [eax + 4], ecx
// 004dcf95  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dcf98  80793400             cmp byte ptr [ecx + 0x34], 0
// 004dcf9c  8d4604               lea eax, [esi + 4]
// 004dcf9f  0f841bffffff         je 0x4dcec0
// 004dcfa5  8b5718               mov edx, dword ptr [edi + 0x18]
// 004dcfa8  8b4204               mov eax, dword ptr [edx + 4]
// 004dcfab  885834               mov byte ptr [eax + 0x34], bl
// 004dcfae  8b442464             mov eax, dword ptr [esp + 0x64]
// 004dcfb2  8b0f                 mov ecx, dword ptr [edi]
// 004dcfb4  5e                   pop esi
// 004dcfb5  896804               mov dword ptr [eax + 4], ebp
// 004dcfb8  5d                   pop ebp
// 004dcfb9  8908                 mov dword ptr [eax], ecx
// 004dcfbb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004dcfbf  5b                   pop ebx
// 004dcfc0  5f                   pop edi
// 004dcfc1  64890d00000000       mov dword ptr fs:[0], ecx
// 004dcfc8  83c450               add esp, 0x50
// 004dcfcb  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
