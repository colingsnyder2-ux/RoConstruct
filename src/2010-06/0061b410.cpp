// from server: 100% by auto
// roc 2010-06 0061b410  unit: RBX::Accoutrement  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b410
//
// 0061b410  64a100000000         mov eax, dword ptr fs:[0]
// 0061b416  6aff                 push -1
// 0061b418  68e22f9a00           push 0x9a2fe2
// 0061b41d  50                   push eax
// 0061b41e  64892500000000       mov dword ptr fs:[0], esp
// 0061b425  83ec44               sub esp, 0x44
// 0061b428  57                   push edi
// 0061b429  8bf9                 mov edi, ecx
// 0061b42b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 0061b432  7259                 jb 0x61b48d
// 0061b434  68a800a000           push 0xa000a8
// 0061b439  8d4c2408             lea ecx, [esp + 8]
// 0061b43d  ff1510a49e00         call dword ptr [0x9ea410]
// 0061b443  8d4c2420             lea ecx, [esp + 0x20]
// 0061b447  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0061b44f  ff1518a99e00         call dword ptr [0x9ea918]
// 0061b455  8d442404             lea eax, [esp + 4]
// 0061b459  50                   push eax
// 0061b45a  8d4c2430             lea ecx, [esp + 0x30]
// 0061b45e  c644245401           mov byte ptr [esp + 0x54], 1
// 0061b463  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 0061b46b  ff150ca49e00         call dword ptr [0x9ea40c]
// 0061b471  68601bb000           push 0xb01b60
// 0061b476  8d4c2424             lea ecx, [esp + 0x24]
// 0061b47a  51                   push ecx
// 0061b47b  c644245800           mov byte ptr [esp + 0x58], 0
// 0061b480  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 0061b488  e825d51800           call 0x7a89b2
// 0061b48d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061b491  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b494  53                   push ebx
// 0061b495  55                   push ebp
// 0061b496  56                   push esi
// 0061b497  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0061b49b  6a00                 push 0
// 0061b49d  52                   push edx
// 0061b49e  50                   push eax
// 0061b49f  56                   push esi
// 0061b4a0  50                   push eax
// 0061b4a1  e80a5b3400           call 0x960fb0
// 0061b4a6  8be8                 mov ebp, eax
// 0061b4a8  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b4ab  bb01000000           mov ebx, 1
// 0061b4b0  015f1c               add dword ptr [edi + 0x1c], ebx
// 0061b4b3  3bf0                 cmp esi, eax
// 0061b4b5  7510                 jne 0x61b4c7
// 0061b4b7  896804               mov dword ptr [eax + 4], ebp
// 0061b4ba  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b4bd  8928                 mov dword ptr [eax], ebp
// 0061b4bf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0061b4c2  896908               mov dword ptr [ecx + 8], ebp
// 0061b4c5  eb22                 jmp 0x61b4e9
// 0061b4c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 0061b4cc  740d                 je 0x61b4db
// 0061b4ce  892e                 mov dword ptr [esi], ebp
// 0061b4d0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b4d3  3b30                 cmp esi, dword ptr [eax]
// 0061b4d5  7512                 jne 0x61b4e9
// 0061b4d7  8928                 mov dword ptr [eax], ebp
// 0061b4d9  eb0e                 jmp 0x61b4e9
// 0061b4db  896e08               mov dword ptr [esi + 8], ebp
// 0061b4de  8b4718               mov eax, dword ptr [edi + 0x18]
// 0061b4e1  3b7008               cmp esi, dword ptr [eax + 8]
// 0061b4e4  7503                 jne 0x61b4e9
// 0061b4e6  896808               mov dword ptr [eax + 8], ebp
// 0061b4e9  8b5504               mov edx, dword ptr [ebp + 4]
// 0061b4ec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0061b4f0  8d4504               lea eax, [ebp + 4]
// 0061b4f3  8bf5                 mov esi, ebp
// 0061b4f5  0f85ea000000         jne 0x61b5e5
// 0061b4fb  eb03                 jmp 0x61b500
// 0061b4fd  8d4900               lea ecx, [ecx]
// 0061b500  8b08                 mov ecx, dword ptr [eax]
// 0061b502  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b505  3b0a                 cmp ecx, dword ptr [edx]
// 0061b507  7551                 jne 0x61b55a
// 0061b509  8b5208               mov edx, dword ptr [edx + 8]
// 0061b50c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0061b510  7519                 jne 0x61b52b
// 0061b512  88592c               mov byte ptr [ecx + 0x2c], bl
// 0061b515  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b518  8b10                 mov edx, dword ptr [eax]
// 0061b51a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061b51d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0061b521  8b10                 mov edx, dword ptr [eax]
// 0061b523  8b7204               mov esi, dword ptr [edx + 4]
// 0061b526  e9aa000000           jmp 0x61b5d5
// 0061b52b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0061b52e  750a                 jne 0x61b53a
// 0061b530  8bf1                 mov esi, ecx
// 0061b532  56                   push esi
// 0061b533  8bcf                 mov ecx, edi
// 0061b535  e896e21100           call 0x7397d0
// 0061b53a  8b4604               mov eax, dword ptr [esi + 4]
// 0061b53d  88582c               mov byte ptr [eax + 0x2c], bl
// 0061b540  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b543  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b546  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0061b54a  8b4604               mov eax, dword ptr [esi + 4]
// 0061b54d  8b4804               mov ecx, dword ptr [eax + 4]
// 0061b550  51                   push ecx
// 0061b551  8bcf                 mov ecx, edi
// 0061b553  e868553400           call 0x960ac0
// 0061b558  eb7b                 jmp 0x61b5d5
// 0061b55a  8b12                 mov edx, dword ptr [edx]
// 0061b55c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0061b560  7516                 jne 0x61b578
// 0061b562  88592c               mov byte ptr [ecx + 0x2c], bl
// 0061b565  885a2c               mov byte ptr [edx + 0x2c], bl
// 0061b568  8b10                 mov edx, dword ptr [eax]
// 0061b56a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0061b56d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0061b571  8b10                 mov edx, dword ptr [eax]
// 0061b573  8b7204               mov esi, dword ptr [edx + 4]
// 0061b576  eb5d                 jmp 0x61b5d5
// 0061b578  3b31                 cmp esi, dword ptr [ecx]
// 0061b57a  750a                 jne 0x61b586
// 0061b57c  8bf1                 mov esi, ecx
// 0061b57e  56                   push esi
// 0061b57f  8bcf                 mov ecx, edi
// 0061b581  e83a553400           call 0x960ac0
// 0061b586  8b4604               mov eax, dword ptr [esi + 4]
// 0061b589  88582c               mov byte ptr [eax + 0x2c], bl
// 0061b58c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b58f  8b5104               mov edx, dword ptr [ecx + 4]
// 0061b592  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0061b596  8b4604               mov eax, dword ptr [esi + 4]
// 0061b599  8b4004               mov eax, dword ptr [eax + 4]
// 0061b59c  8b4808               mov ecx, dword ptr [eax + 8]
// 0061b59f  8b11                 mov edx, dword ptr [ecx]
// 0061b5a1  895008               mov dword ptr [eax + 8], edx
// 0061b5a4  8b11                 mov edx, dword ptr [ecx]
// 0061b5a6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0061b5aa  7503                 jne 0x61b5af
// 0061b5ac  894204               mov dword ptr [edx + 4], eax
// 0061b5af  8b5004               mov edx, dword ptr [eax + 4]
// 0061b5b2  895104               mov dword ptr [ecx + 4], edx
// 0061b5b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061b5b8  3b4204               cmp eax, dword ptr [edx + 4]
// 0061b5bb  7505                 jne 0x61b5c2
// 0061b5bd  894a04               mov dword ptr [edx + 4], ecx
// 0061b5c0  eb0e                 jmp 0x61b5d0
// 0061b5c2  8b5004               mov edx, dword ptr [eax + 4]
// 0061b5c5  3b02                 cmp eax, dword ptr [edx]
// 0061b5c7  7504                 jne 0x61b5cd
// 0061b5c9  890a                 mov dword ptr [edx], ecx
// 0061b5cb  eb03                 jmp 0x61b5d0
// 0061b5cd  894a08               mov dword ptr [edx + 8], ecx
// 0061b5d0  8901                 mov dword ptr [ecx], eax
// 0061b5d2  894804               mov dword ptr [eax + 4], ecx
// 0061b5d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0061b5d8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0061b5dc  8d4604               lea eax, [esi + 4]
// 0061b5df  0f841bffffff         je 0x61b500
// 0061b5e5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0061b5e8  8b4204               mov eax, dword ptr [edx + 4]
// 0061b5eb  88582c               mov byte ptr [eax + 0x2c], bl
// 0061b5ee  8b442464             mov eax, dword ptr [esp + 0x64]
// 0061b5f2  8b0f                 mov ecx, dword ptr [edi]
// 0061b5f4  5e                   pop esi
// 0061b5f5  896804               mov dword ptr [eax + 4], ebp
// 0061b5f8  5d                   pop ebp
// 0061b5f9  8908                 mov dword ptr [eax], ecx
// 0061b5fb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0061b5ff  5b                   pop ebx
// 0061b600  5f                   pop edi
// 0061b601  64890d00000000       mov dword ptr fs:[0], ecx
// 0061b608  83c450               add esp, 0x50
// 0061b60b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
