// from server: 100% by auto
// roc 2009-12 0057c230  unit: std::Vlength_error::?$error_info_injector  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c230
//
// 0057c230  64a100000000         mov eax, dword ptr fs:[0]
// 0057c236  6aff                 push -1
// 0057c238  6812699500           push 0x956912
// 0057c23d  50                   push eax
// 0057c23e  64892500000000       mov dword ptr fs:[0], esp
// 0057c245  83ec44               sub esp, 0x44
// 0057c248  57                   push edi
// 0057c249  8bf9                 mov edi, ecx
// 0057c24b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 0057c252  7259                 jb 0x57c2ad
// 0057c254  6800f59900           push 0x99f500
// 0057c259  8d4c2408             lea ecx, [esp + 8]
// 0057c25d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0057c263  8d4c2420             lea ecx, [esp + 0x20]
// 0057c267  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0057c26f  ff1554b79800         call dword ptr [0x98b754]
// 0057c275  8d442404             lea eax, [esp + 4]
// 0057c279  50                   push eax
// 0057c27a  8d4c2430             lea ecx, [esp + 0x30]
// 0057c27e  c644245401           mov byte ptr [esp + 0x54], 1
// 0057c283  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0057c28b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0057c291  68e4efa800           push 0xa8efe4
// 0057c296  8d4c2424             lea ecx, [esp + 0x24]
// 0057c29a  51                   push ecx
// 0057c29b  c644245800           mov byte ptr [esp + 0x58], 0
// 0057c2a0  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0057c2a8  e8cb852700           call 0x7f4878
// 0057c2ad  8b542464             mov edx, dword ptr [esp + 0x64]
// 0057c2b1  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c2b4  53                   push ebx
// 0057c2b5  55                   push ebp
// 0057c2b6  56                   push esi
// 0057c2b7  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0057c2bb  6a00                 push 0
// 0057c2bd  52                   push edx
// 0057c2be  50                   push eax
// 0057c2bf  56                   push esi
// 0057c2c0  50                   push eax
// 0057c2c1  e8fa0e1300           call 0x6ad1c0
// 0057c2c6  8be8                 mov ebp, eax
// 0057c2c8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c2cb  bb01000000           mov ebx, 1
// 0057c2d0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0057c2d3  3bf0                 cmp esi, eax
// 0057c2d5  7510                 jne 0x57c2e7
// 0057c2d7  896804               mov dword ptr [eax + 4], ebp
// 0057c2da  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c2dd  8928                 mov dword ptr [eax], ebp
// 0057c2df  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0057c2e2  896908               mov dword ptr [ecx + 8], ebp
// 0057c2e5  eb22                 jmp 0x57c309
// 0057c2e7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0057c2ec  740d                 je 0x57c2fb
// 0057c2ee  892e                 mov dword ptr [esi], ebp
// 0057c2f0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c2f3  3b30                 cmp esi, dword ptr [eax]
// 0057c2f5  7512                 jne 0x57c309
// 0057c2f7  8928                 mov dword ptr [eax], ebp
// 0057c2f9  eb0e                 jmp 0x57c309
// 0057c2fb  896e08               mov dword ptr [esi + 8], ebp
// 0057c2fe  8b4718               mov eax, dword ptr [edi + 0x18]
// 0057c301  3b7008               cmp esi, dword ptr [eax + 8]
// 0057c304  7503                 jne 0x57c309
// 0057c306  896808               mov dword ptr [eax + 8], ebp
// 0057c309  8b5504               mov edx, dword ptr [ebp + 4]
// 0057c30c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0057c310  8d4504               lea eax, [ebp + 4]
// 0057c313  8bf5                 mov esi, ebp
// 0057c315  0f85ea000000         jne 0x57c405
// 0057c31b  eb03                 jmp 0x57c320
// 0057c31d  8d4900               lea ecx, [ecx]
// 0057c320  8b08                 mov ecx, dword ptr [eax]
// 0057c322  8b5104               mov edx, dword ptr [ecx + 4]
// 0057c325  3b0a                 cmp ecx, dword ptr [edx]
// 0057c327  7551                 jne 0x57c37a
// 0057c329  8b5208               mov edx, dword ptr [edx + 8]
// 0057c32c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0057c330  7519                 jne 0x57c34b
// 0057c332  88592c               mov byte ptr [ecx + 0x2c], bl
// 0057c335  885a2c               mov byte ptr [edx + 0x2c], bl
// 0057c338  8b10                 mov edx, dword ptr [eax]
// 0057c33a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0057c33d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0057c341  8b10                 mov edx, dword ptr [eax]
// 0057c343  8b7204               mov esi, dword ptr [edx + 4]
// 0057c346  e9aa000000           jmp 0x57c3f5
// 0057c34b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0057c34e  750a                 jne 0x57c35a
// 0057c350  8bf1                 mov esi, ecx
// 0057c352  56                   push esi
// 0057c353  8bcf                 mov ecx, edi
// 0057c355  e826e6efff           call 0x47a980
// 0057c35a  8b4604               mov eax, dword ptr [esi + 4]
// 0057c35d  88582c               mov byte ptr [eax + 0x2c], bl
// 0057c360  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057c363  8b5104               mov edx, dword ptr [ecx + 4]
// 0057c366  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0057c36a  8b4604               mov eax, dword ptr [esi + 4]
// 0057c36d  8b4804               mov ecx, dword ptr [eax + 4]
// 0057c370  51                   push ecx
// 0057c371  8bcf                 mov ecx, edi
// 0057c373  e8180d1300           call 0x6ad090
// 0057c378  eb7b                 jmp 0x57c3f5
// 0057c37a  8b12                 mov edx, dword ptr [edx]
// 0057c37c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0057c380  7516                 jne 0x57c398
// 0057c382  88592c               mov byte ptr [ecx + 0x2c], bl
// 0057c385  885a2c               mov byte ptr [edx + 0x2c], bl
// 0057c388  8b10                 mov edx, dword ptr [eax]
// 0057c38a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0057c38d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0057c391  8b10                 mov edx, dword ptr [eax]
// 0057c393  8b7204               mov esi, dword ptr [edx + 4]
// 0057c396  eb5d                 jmp 0x57c3f5
// 0057c398  3b31                 cmp esi, dword ptr [ecx]
// 0057c39a  750a                 jne 0x57c3a6
// 0057c39c  8bf1                 mov esi, ecx
// 0057c39e  56                   push esi
// 0057c39f  8bcf                 mov ecx, edi
// 0057c3a1  e8ea0c1300           call 0x6ad090
// 0057c3a6  8b4604               mov eax, dword ptr [esi + 4]
// 0057c3a9  88582c               mov byte ptr [eax + 0x2c], bl
// 0057c3ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057c3af  8b5104               mov edx, dword ptr [ecx + 4]
// 0057c3b2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0057c3b6  8b4604               mov eax, dword ptr [esi + 4]
// 0057c3b9  8b4004               mov eax, dword ptr [eax + 4]
// 0057c3bc  8b4808               mov ecx, dword ptr [eax + 8]
// 0057c3bf  8b11                 mov edx, dword ptr [ecx]
// 0057c3c1  895008               mov dword ptr [eax + 8], edx
// 0057c3c4  8b11                 mov edx, dword ptr [ecx]
// 0057c3c6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0057c3ca  7503                 jne 0x57c3cf
// 0057c3cc  894204               mov dword ptr [edx + 4], eax
// 0057c3cf  8b5004               mov edx, dword ptr [eax + 4]
// 0057c3d2  895104               mov dword ptr [ecx + 4], edx
// 0057c3d5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0057c3d8  3b4204               cmp eax, dword ptr [edx + 4]
// 0057c3db  7505                 jne 0x57c3e2
// 0057c3dd  894a04               mov dword ptr [edx + 4], ecx
// 0057c3e0  eb0e                 jmp 0x57c3f0
// 0057c3e2  8b5004               mov edx, dword ptr [eax + 4]
// 0057c3e5  3b02                 cmp eax, dword ptr [edx]
// 0057c3e7  7504                 jne 0x57c3ed
// 0057c3e9  890a                 mov dword ptr [edx], ecx
// 0057c3eb  eb03                 jmp 0x57c3f0
// 0057c3ed  894a08               mov dword ptr [edx + 8], ecx
// 0057c3f0  8901                 mov dword ptr [ecx], eax
// 0057c3f2  894804               mov dword ptr [eax + 4], ecx
// 0057c3f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057c3f8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0057c3fc  8d4604               lea eax, [esi + 4]
// 0057c3ff  0f841bffffff         je 0x57c320
// 0057c405  8b5718               mov edx, dword ptr [edi + 0x18]
// 0057c408  8b4204               mov eax, dword ptr [edx + 4]
// 0057c40b  88582c               mov byte ptr [eax + 0x2c], bl
// 0057c40e  8b442464             mov eax, dword ptr [esp + 0x64]
// 0057c412  8b0f                 mov ecx, dword ptr [edi]
// 0057c414  5e                   pop esi
// 0057c415  896804               mov dword ptr [eax + 4], ebp
// 0057c418  5d                   pop ebp
// 0057c419  8908                 mov dword ptr [eax], ecx
// 0057c41b  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0057c41f  5b                   pop ebx
// 0057c420  5f                   pop edi
// 0057c421  64890d00000000       mov dword ptr fs:[0], ecx
// 0057c428  83c450               add esp, 0x50
// 0057c42b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
