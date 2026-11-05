// from server: 100% by auto
// roc 2007-08 004dd410  unit: seg_004d0000  size: 508 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004dd410
//
// 004dd410  64a100000000         mov eax, dword ptr fs:[0]
// 004dd416  6aff                 push -1
// 004dd418  68b2417500           push 0x7541b2
// 004dd41d  50                   push eax
// 004dd41e  64892500000000       mov dword ptr fs:[0], esp
// 004dd425  83ec44               sub esp, 0x44
// 004dd428  57                   push edi
// 004dd429  8bf9                 mov edi, ecx
// 004dd42b  817f0865666606       cmp dword ptr [edi + 8], 0x6666665
// 004dd432  7259                 jb 0x4dd48d
// 004dd434  68904f7800           push 0x784f90
// 004dd439  8d4c2408             lea ecx, [esp + 8]
// 004dd43d  ff1598e67700         call dword ptr [0x77e698]
// 004dd443  8d4c2420             lea ecx, [esp + 0x20]
// 004dd447  c744245000000000     mov dword ptr [esp + 0x50], 0
// 004dd44f  ff15f8e67700         call dword ptr [0x77e6f8]
// 004dd455  8d442404             lea eax, [esp + 4]
// 004dd459  50                   push eax
// 004dd45a  8d4c2430             lea ecx, [esp + 0x30]
// 004dd45e  c644245401           mov byte ptr [esp + 0x54], 1
// 004dd463  c7442424604e7800     mov dword ptr [esp + 0x24], 0x784e60
// 004dd46b  ff159ce67700         call dword ptr [0x77e69c]
// 004dd471  6878f78300           push 0x83f778
// 004dd476  8d4c2424             lea ecx, [esp + 0x24]
// 004dd47a  51                   push ecx
// 004dd47b  c644245800           mov byte ptr [esp + 0x58], 0
// 004dd480  c74424286c4e7800     mov dword ptr [esp + 0x28], 0x784e6c
// 004dd488  e811371500           call 0x630b9e
// 004dd48d  8b542464             mov edx, dword ptr [esp + 0x64]
// 004dd491  8b4704               mov eax, dword ptr [edi + 4]
// 004dd494  53                   push ebx
// 004dd495  55                   push ebp
// 004dd496  56                   push esi
// 004dd497  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 004dd49b  6a00                 push 0
// 004dd49d  52                   push edx
// 004dd49e  50                   push eax
// 004dd49f  56                   push esi
// 004dd4a0  50                   push eax
// 004dd4a1  e8dafeffff           call 0x4dd380
// 004dd4a6  8be8                 mov ebp, eax
// 004dd4a8  8b4704               mov eax, dword ptr [edi + 4]
// 004dd4ab  bb01000000           mov ebx, 1
// 004dd4b0  015f08               add dword ptr [edi + 8], ebx
// 004dd4b3  3bf0                 cmp esi, eax
// 004dd4b5  7510                 jne 0x4dd4c7
// 004dd4b7  896804               mov dword ptr [eax + 4], ebp
// 004dd4ba  8b4704               mov eax, dword ptr [edi + 4]
// 004dd4bd  8928                 mov dword ptr [eax], ebp
// 004dd4bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 004dd4c2  896908               mov dword ptr [ecx + 8], ebp
// 004dd4c5  eb22                 jmp 0x4dd4e9
// 004dd4c7  807c246800           cmp byte ptr [esp + 0x68], 0
// 004dd4cc  740d                 je 0x4dd4db
// 004dd4ce  892e                 mov dword ptr [esi], ebp
// 004dd4d0  8b4704               mov eax, dword ptr [edi + 4]
// 004dd4d3  3b30                 cmp esi, dword ptr [eax]
// 004dd4d5  7512                 jne 0x4dd4e9
// 004dd4d7  8928                 mov dword ptr [eax], ebp
// 004dd4d9  eb0e                 jmp 0x4dd4e9
// 004dd4db  896e08               mov dword ptr [esi + 8], ebp
// 004dd4de  8b4704               mov eax, dword ptr [edi + 4]
// 004dd4e1  3b7008               cmp esi, dword ptr [eax + 8]
// 004dd4e4  7503                 jne 0x4dd4e9
// 004dd4e6  896808               mov dword ptr [eax + 8], ebp
// 004dd4e9  8b5504               mov edx, dword ptr [ebp + 4]
// 004dd4ec  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dd4f0  8d4504               lea eax, [ebp + 4]
// 004dd4f3  8bf5                 mov esi, ebp
// 004dd4f5  0f85ea000000         jne 0x4dd5e5
// 004dd4fb  eb03                 jmp 0x4dd500
// 004dd4fd  8d4900               lea ecx, [ecx]
// 004dd500  8b08                 mov ecx, dword ptr [eax]
// 004dd502  8b5104               mov edx, dword ptr [ecx + 4]
// 004dd505  3b0a                 cmp ecx, dword ptr [edx]
// 004dd507  7551                 jne 0x4dd55a
// 004dd509  8b5208               mov edx, dword ptr [edx + 8]
// 004dd50c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dd510  7519                 jne 0x4dd52b
// 004dd512  885934               mov byte ptr [ecx + 0x34], bl
// 004dd515  885a34               mov byte ptr [edx + 0x34], bl
// 004dd518  8b10                 mov edx, dword ptr [eax]
// 004dd51a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dd51d  c6413400             mov byte ptr [ecx + 0x34], 0
// 004dd521  8b10                 mov edx, dword ptr [eax]
// 004dd523  8b7204               mov esi, dword ptr [edx + 4]
// 004dd526  e9aa000000           jmp 0x4dd5d5
// 004dd52b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004dd52e  750a                 jne 0x4dd53a
// 004dd530  8bf1                 mov esi, ecx
// 004dd532  56                   push esi
// 004dd533  8bcf                 mov ecx, edi
// 004dd535  e826aa0a00           call 0x587f60
// 004dd53a  8b4604               mov eax, dword ptr [esi + 4]
// 004dd53d  885834               mov byte ptr [eax + 0x34], bl
// 004dd540  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dd543  8b5104               mov edx, dword ptr [ecx + 4]
// 004dd546  c6423400             mov byte ptr [edx + 0x34], 0
// 004dd54a  8b4604               mov eax, dword ptr [esi + 4]
// 004dd54d  8b4804               mov ecx, dword ptr [eax + 4]
// 004dd550  51                   push ecx
// 004dd551  8bcf                 mov ecx, edi
// 004dd553  e808a50a00           call 0x587a60
// 004dd558  eb7b                 jmp 0x4dd5d5
// 004dd55a  8b12                 mov edx, dword ptr [edx]
// 004dd55c  807a3400             cmp byte ptr [edx + 0x34], 0
// 004dd560  7516                 jne 0x4dd578
// 004dd562  885934               mov byte ptr [ecx + 0x34], bl
// 004dd565  885a34               mov byte ptr [edx + 0x34], bl
// 004dd568  8b10                 mov edx, dword ptr [eax]
// 004dd56a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004dd56d  c6413400             mov byte ptr [ecx + 0x34], 0
// 004dd571  8b10                 mov edx, dword ptr [eax]
// 004dd573  8b7204               mov esi, dword ptr [edx + 4]
// 004dd576  eb5d                 jmp 0x4dd5d5
// 004dd578  3b31                 cmp esi, dword ptr [ecx]
// 004dd57a  750a                 jne 0x4dd586
// 004dd57c  8bf1                 mov esi, ecx
// 004dd57e  56                   push esi
// 004dd57f  8bcf                 mov ecx, edi
// 004dd581  e8daa40a00           call 0x587a60
// 004dd586  8b4604               mov eax, dword ptr [esi + 4]
// 004dd589  885834               mov byte ptr [eax + 0x34], bl
// 004dd58c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dd58f  8b5104               mov edx, dword ptr [ecx + 4]
// 004dd592  c6423400             mov byte ptr [edx + 0x34], 0
// 004dd596  8b4604               mov eax, dword ptr [esi + 4]
// 004dd599  8b4004               mov eax, dword ptr [eax + 4]
// 004dd59c  8b4808               mov ecx, dword ptr [eax + 8]
// 004dd59f  8b11                 mov edx, dword ptr [ecx]
// 004dd5a1  895008               mov dword ptr [eax + 8], edx
// 004dd5a4  8b11                 mov edx, dword ptr [ecx]
// 004dd5a6  807a3500             cmp byte ptr [edx + 0x35], 0
// 004dd5aa  7503                 jne 0x4dd5af
// 004dd5ac  894204               mov dword ptr [edx + 4], eax
// 004dd5af  8b5004               mov edx, dword ptr [eax + 4]
// 004dd5b2  895104               mov dword ptr [ecx + 4], edx
// 004dd5b5  8b5704               mov edx, dword ptr [edi + 4]
// 004dd5b8  3b4204               cmp eax, dword ptr [edx + 4]
// 004dd5bb  7505                 jne 0x4dd5c2
// 004dd5bd  894a04               mov dword ptr [edx + 4], ecx
// 004dd5c0  eb0e                 jmp 0x4dd5d0
// 004dd5c2  8b5004               mov edx, dword ptr [eax + 4]
// 004dd5c5  3b02                 cmp eax, dword ptr [edx]
// 004dd5c7  7504                 jne 0x4dd5cd
// 004dd5c9  890a                 mov dword ptr [edx], ecx
// 004dd5cb  eb03                 jmp 0x4dd5d0
// 004dd5cd  894a08               mov dword ptr [edx + 8], ecx
// 004dd5d0  8901                 mov dword ptr [ecx], eax
// 004dd5d2  894804               mov dword ptr [eax + 4], ecx
// 004dd5d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004dd5d8  80793400             cmp byte ptr [ecx + 0x34], 0
// 004dd5dc  8d4604               lea eax, [esi + 4]
// 004dd5df  0f841bffffff         je 0x4dd500
// 004dd5e5  8b5704               mov edx, dword ptr [edi + 4]
// 004dd5e8  8b4204               mov eax, dword ptr [edx + 4]
// 004dd5eb  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004dd5ef  885834               mov byte ptr [eax + 0x34], bl
// 004dd5f2  8b442464             mov eax, dword ptr [esp + 0x64]
// 004dd5f6  5e                   pop esi
// 004dd5f7  896804               mov dword ptr [eax + 4], ebp
// 004dd5fa  5d                   pop ebp
// 004dd5fb  8938                 mov dword ptr [eax], edi
// 004dd5fd  5b                   pop ebx
// 004dd5fe  5f                   pop edi
// 004dd5ff  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd606  83c450               add esp, 0x50
// 004dd609  c21000               ret 0x10
// standard library map_int<pod36> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@2@ABU?$pair@$$CBHUE@@@2@@Z)

// stl: map_int<pod36>
struct E { int v[9]; };
#include <map>
template class std::map<int, E>;
