// from server: 100% by auto
// roc 2009-06 004e62c0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e62c0
//
// 004e62c0  64a100000000         mov eax, dword ptr fs:[0]
// 004e62c6  6aff                 push -1
// 004e62c8  68b2db8500           push 0x85dbb2
// 004e62cd  50                   push eax
// 004e62ce  64892500000000       mov dword ptr fs:[0], esp
// 004e62d5  83ec44               sub esp, 0x44
// 004e62d8  57                   push edi
// 004e62d9  8bf9                 mov edi, ecx
// 004e62db  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 004e62e2  7259                 jb 0x4e633d
// 004e62e4  68c0c98a00           push 0x8ac9c0
// 004e62e9  8d4c2408             lea ecx, [esp + 8]
// 004e62ed  ff15b4e48900         call dword ptr [0x89e4b4]
// 004e62f3  8d4c2420             lea ecx, [esp + 0x20]
// 004e62f7  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004e62ff  ff15b8e98900         call dword ptr [0x89e9b8]
// 004e6305  8d442404             lea eax, [esp + 4]
// 004e6309  50                   push eax
// 004e630a  8d4c2430             lea ecx, [esp + 0x30]
// 004e630e  c644245401           mov byte ptr [esp + 0x54], 1
// 004e6313  c744242444c98a00     mov dword ptr [esp + 0x24], 0x8ac944
// 004e631b  ff15b8e48900         call dword ptr [0x89e4b8]
// 004e6321  6834929700           push 0x979234
// 004e6326  8d4c2424             lea ecx, [esp + 0x24]
// 004e632a  51                   push ecx
// 004e632b  c644245800           mov byte ptr [esp + 0x58], 0
// 004e6330  c744242850c98a00     mov dword ptr [esp + 0x28], 0x8ac950
// 004e6338  e80d372300           call 0x719a4a
// 004e633d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004e6341  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e6344  53                   push ebx
// 004e6345  55                   push ebp
// 004e6346  56                   push esi
// 004e6347  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004e634b  6a00                 push 0
// 004e634d  52                   push edx
// 004e634e  50                   push eax
// 004e634f  56                   push esi
// 004e6350  50                   push eax
// 004e6351  e82af4ffff           call 0x4e5780
// 004e6356  8be8                 mov ebp, eax
// 004e6358  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e635b  bb01000000           mov ebx, 1
// 004e6360  015f1c               add dword ptr [edi + 0x1c], ebx
// 004e6363  3bf0                 cmp esi, eax
// 004e6365  7510                 jne 0x4e6377
// 004e6367  896804               mov dword ptr [eax + 4], ebp
// 004e636a  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e636d  8928                 mov dword ptr [eax], ebp
// 004e636f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 004e6372  896908               mov dword ptr [ecx + 8], ebp
// 004e6375  eb22                 jmp 0x4e6399
// 004e6377  807c246800           cmp byte ptr [esp + 0x68], 0
// 004e637c  740d                 je 0x4e638b
// 004e637e  892e                 mov dword ptr [esi], ebp
// 004e6380  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e6383  3b30                 cmp esi, dword ptr [eax]
// 004e6385  7512                 jne 0x4e6399
// 004e6387  8928                 mov dword ptr [eax], ebp
// 004e6389  eb0e                 jmp 0x4e6399
// 004e638b  896e08               mov dword ptr [esi + 8], ebp
// 004e638e  8b4718               mov eax, dword ptr [edi + 0x18]
// 004e6391  3b7008               cmp esi, dword ptr [eax + 8]
// 004e6394  7503                 jne 0x4e6399
// 004e6396  896808               mov dword ptr [eax + 8], ebp
// 004e6399  8b5504               mov edx, dword ptr [ebp + 4]
// 004e639c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e63a0  8d4504               lea eax, [ebp + 4]
// 004e63a3  8bf5                 mov esi, ebp
// 004e63a5  0f85ea000000         jne 0x4e6495
// 004e63ab  eb03                 jmp 0x4e63b0
// 004e63ad  8d4900               lea ecx, [ecx]
// 004e63b0  8b08                 mov ecx, dword ptr [eax]
// 004e63b2  8b5104               mov edx, dword ptr [ecx + 4]
// 004e63b5  3b0a                 cmp ecx, dword ptr [edx]
// 004e63b7  7551                 jne 0x4e640a
// 004e63b9  8b5208               mov edx, dword ptr [edx + 8]
// 004e63bc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e63c0  7519                 jne 0x4e63db
// 004e63c2  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e63c5  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e63c8  8b10                 mov edx, dword ptr [eax]
// 004e63ca  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e63cd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e63d1  8b10                 mov edx, dword ptr [eax]
// 004e63d3  8b7204               mov esi, dword ptr [edx + 4]
// 004e63d6  e9aa000000           jmp 0x4e6485
// 004e63db  3b7108               cmp esi, dword ptr [ecx + 8]
// 004e63de  750a                 jne 0x4e63ea
// 004e63e0  8bf1                 mov esi, ecx
// 004e63e2  56                   push esi
// 004e63e3  8bcf                 mov ecx, edi
// 004e63e5  e896861500           call 0x63ea80
// 004e63ea  8b4604               mov eax, dword ptr [esi + 4]
// 004e63ed  88582c               mov byte ptr [eax + 0x2c], bl
// 004e63f0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e63f3  8b5104               mov edx, dword ptr [ecx + 4]
// 004e63f6  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e63fa  8b4604               mov eax, dword ptr [esi + 4]
// 004e63fd  8b4804               mov ecx, dword ptr [eax + 4]
// 004e6400  51                   push ecx
// 004e6401  8bcf                 mov ecx, edi
// 004e6403  e8f865ffff           call 0x4dca00
// 004e6408  eb7b                 jmp 0x4e6485
// 004e640a  8b12                 mov edx, dword ptr [edx]
// 004e640c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004e6410  7516                 jne 0x4e6428
// 004e6412  88592c               mov byte ptr [ecx + 0x2c], bl
// 004e6415  885a2c               mov byte ptr [edx + 0x2c], bl
// 004e6418  8b10                 mov edx, dword ptr [eax]
// 004e641a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004e641d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004e6421  8b10                 mov edx, dword ptr [eax]
// 004e6423  8b7204               mov esi, dword ptr [edx + 4]
// 004e6426  eb5d                 jmp 0x4e6485
// 004e6428  3b31                 cmp esi, dword ptr [ecx]
// 004e642a  750a                 jne 0x4e6436
// 004e642c  8bf1                 mov esi, ecx
// 004e642e  56                   push esi
// 004e642f  8bcf                 mov ecx, edi
// 004e6431  e8ca65ffff           call 0x4dca00
// 004e6436  8b4604               mov eax, dword ptr [esi + 4]
// 004e6439  88582c               mov byte ptr [eax + 0x2c], bl
// 004e643c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e643f  8b5104               mov edx, dword ptr [ecx + 4]
// 004e6442  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004e6446  8b4604               mov eax, dword ptr [esi + 4]
// 004e6449  8b4004               mov eax, dword ptr [eax + 4]
// 004e644c  8b4808               mov ecx, dword ptr [eax + 8]
// 004e644f  8b11                 mov edx, dword ptr [ecx]
// 004e6451  895008               mov dword ptr [eax + 8], edx
// 004e6454  8b11                 mov edx, dword ptr [ecx]
// 004e6456  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004e645a  7503                 jne 0x4e645f
// 004e645c  894204               mov dword ptr [edx + 4], eax
// 004e645f  8b5004               mov edx, dword ptr [eax + 4]
// 004e6462  895104               mov dword ptr [ecx + 4], edx
// 004e6465  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e6468  3b4204               cmp eax, dword ptr [edx + 4]
// 004e646b  7505                 jne 0x4e6472
// 004e646d  894a04               mov dword ptr [edx + 4], ecx
// 004e6470  eb0e                 jmp 0x4e6480
// 004e6472  8b5004               mov edx, dword ptr [eax + 4]
// 004e6475  3b02                 cmp eax, dword ptr [edx]
// 004e6477  7504                 jne 0x4e647d
// 004e6479  890a                 mov dword ptr [edx], ecx
// 004e647b  eb03                 jmp 0x4e6480
// 004e647d  894a08               mov dword ptr [edx + 8], ecx
// 004e6480  8901                 mov dword ptr [ecx], eax
// 004e6482  894804               mov dword ptr [eax + 4], ecx
// 004e6485  8b4e04               mov ecx, dword ptr [esi + 4]
// 004e6488  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004e648c  8d4604               lea eax, [esi + 4]
// 004e648f  0f841bffffff         je 0x4e63b0
// 004e6495  8b5718               mov edx, dword ptr [edi + 0x18]
// 004e6498  8b4204               mov eax, dword ptr [edx + 4]
// 004e649b  88582c               mov byte ptr [eax + 0x2c], bl
// 004e649e  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e64a2  8b0f                 mov ecx, dword ptr [edi]
// 004e64a4  5e                   pop esi
// 004e64a5  896804               mov dword ptr [eax + 4], ebp
// 004e64a8  5d                   pop ebp
// 004e64a9  8908                 mov dword ptr [eax], ecx
// 004e64ab  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e64af  5b                   pop ebx
// 004e64b0  5f                   pop edi
// 004e64b1  64890d00000000       mov dword ptr fs:[0], ecx
// 004e64b8  83c450               add esp, 0x50
// 004e64bb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
