// from server: 100% by auto
// roc 2010-06 005cea10  unit: RBX::SimpleThrottlingArbiter  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005cea10
//
// 005cea10  64a100000000         mov eax, dword ptr fs:[0]
// 005cea16  6aff                 push -1
// 005cea18  68e22f9a00           push 0x9a2fe2
// 005cea1d  50                   push eax
// 005cea1e  64892500000000       mov dword ptr fs:[0], esp
// 005cea25  83ec44               sub esp, 0x44
// 005cea28  57                   push edi
// 005cea29  8bf9                 mov edi, ecx
// 005cea2b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 005cea32  7259                 jb 0x5cea8d
// 005cea34  68a800a000           push 0xa000a8
// 005cea39  8d4c2408             lea ecx, [esp + 8]
// 005cea3d  ff1510a49e00         call dword ptr [0x9ea410]
// 005cea43  8d4c2420             lea ecx, [esp + 0x20]
// 005cea47  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005cea4f  ff1518a99e00         call dword ptr [0x9ea918]
// 005cea55  8d442404             lea eax, [esp + 4]
// 005cea59  50                   push eax
// 005cea5a  8d4c2430             lea ecx, [esp + 0x30]
// 005cea5e  c644245401           mov byte ptr [esp + 0x54], 1
// 005cea63  c74424242c00a000     mov dword ptr [esp + 0x24], 0xa0002c
// 005cea6b  ff150ca49e00         call dword ptr [0x9ea40c]
// 005cea71  68601bb000           push 0xb01b60
// 005cea76  8d4c2424             lea ecx, [esp + 0x24]
// 005cea7a  51                   push ecx
// 005cea7b  c644245800           mov byte ptr [esp + 0x58], 0
// 005cea80  c74424283800a000     mov dword ptr [esp + 0x28], 0xa00038
// 005cea88  e8259f1d00           call 0x7a89b2
// 005cea8d  8b542464             mov edx, dword ptr [esp + 0x64]
// 005cea91  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cea94  53                   push ebx
// 005cea95  55                   push ebp
// 005cea96  56                   push esi
// 005cea97  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 005cea9b  6a00                 push 0
// 005cea9d  52                   push edx
// 005cea9e  50                   push eax
// 005cea9f  56                   push esi
// 005ceaa0  50                   push eax
// 005ceaa1  e80aae1600           call 0x7398b0
// 005ceaa6  8be8                 mov ebp, eax
// 005ceaa8  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ceaab  bb01000000           mov ebx, 1
// 005ceab0  015f1c               add dword ptr [edi + 0x1c], ebx
// 005ceab3  3bf0                 cmp esi, eax
// 005ceab5  7510                 jne 0x5ceac7
// 005ceab7  896804               mov dword ptr [eax + 4], ebp
// 005ceaba  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ceabd  8928                 mov dword ptr [eax], ebp
// 005ceabf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005ceac2  896908               mov dword ptr [ecx + 8], ebp
// 005ceac5  eb22                 jmp 0x5ceae9
// 005ceac7  807c246800           cmp byte ptr [esp + 0x68], 0
// 005ceacc  740d                 je 0x5ceadb
// 005ceace  892e                 mov dword ptr [esi], ebp
// 005cead0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005cead3  3b30                 cmp esi, dword ptr [eax]
// 005cead5  7512                 jne 0x5ceae9
// 005cead7  8928                 mov dword ptr [eax], ebp
// 005cead9  eb0e                 jmp 0x5ceae9
// 005ceadb  896e08               mov dword ptr [esi + 8], ebp
// 005ceade  8b4718               mov eax, dword ptr [edi + 0x18]
// 005ceae1  3b7008               cmp esi, dword ptr [eax + 8]
// 005ceae4  7503                 jne 0x5ceae9
// 005ceae6  896808               mov dword ptr [eax + 8], ebp
// 005ceae9  8b5504               mov edx, dword ptr [ebp + 4]
// 005ceaec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005ceaf0  8d4504               lea eax, [ebp + 4]
// 005ceaf3  8bf5                 mov esi, ebp
// 005ceaf5  0f85ea000000         jne 0x5cebe5
// 005ceafb  eb03                 jmp 0x5ceb00
// 005ceafd  8d4900               lea ecx, [ecx]
// 005ceb00  8b08                 mov ecx, dword ptr [eax]
// 005ceb02  8b5104               mov edx, dword ptr [ecx + 4]
// 005ceb05  3b0a                 cmp ecx, dword ptr [edx]
// 005ceb07  7551                 jne 0x5ceb5a
// 005ceb09  8b5208               mov edx, dword ptr [edx + 8]
// 005ceb0c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005ceb10  7519                 jne 0x5ceb2b
// 005ceb12  88592c               mov byte ptr [ecx + 0x2c], bl
// 005ceb15  885a2c               mov byte ptr [edx + 0x2c], bl
// 005ceb18  8b10                 mov edx, dword ptr [eax]
// 005ceb1a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ceb1d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005ceb21  8b10                 mov edx, dword ptr [eax]
// 005ceb23  8b7204               mov esi, dword ptr [edx + 4]
// 005ceb26  e9aa000000           jmp 0x5cebd5
// 005ceb2b  3b7108               cmp esi, dword ptr [ecx + 8]
// 005ceb2e  750a                 jne 0x5ceb3a
// 005ceb30  8bf1                 mov esi, ecx
// 005ceb32  56                   push esi
// 005ceb33  8bcf                 mov ecx, edi
// 005ceb35  e8f616edff           call 0x4a0230
// 005ceb3a  8b4604               mov eax, dword ptr [esi + 4]
// 005ceb3d  88582c               mov byte ptr [eax + 0x2c], bl
// 005ceb40  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ceb43  8b5104               mov edx, dword ptr [ecx + 4]
// 005ceb46  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005ceb4a  8b4604               mov eax, dword ptr [esi + 4]
// 005ceb4d  8b4804               mov ecx, dword ptr [eax + 4]
// 005ceb50  51                   push ecx
// 005ceb51  8bcf                 mov ecx, edi
// 005ceb53  e88817edff           call 0x4a02e0
// 005ceb58  eb7b                 jmp 0x5cebd5
// 005ceb5a  8b12                 mov edx, dword ptr [edx]
// 005ceb5c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005ceb60  7516                 jne 0x5ceb78
// 005ceb62  88592c               mov byte ptr [ecx + 0x2c], bl
// 005ceb65  885a2c               mov byte ptr [edx + 0x2c], bl
// 005ceb68  8b10                 mov edx, dword ptr [eax]
// 005ceb6a  8b4a04               mov ecx, dword ptr [edx + 4]
// 005ceb6d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005ceb71  8b10                 mov edx, dword ptr [eax]
// 005ceb73  8b7204               mov esi, dword ptr [edx + 4]
// 005ceb76  eb5d                 jmp 0x5cebd5
// 005ceb78  3b31                 cmp esi, dword ptr [ecx]
// 005ceb7a  750a                 jne 0x5ceb86
// 005ceb7c  8bf1                 mov esi, ecx
// 005ceb7e  56                   push esi
// 005ceb7f  8bcf                 mov ecx, edi
// 005ceb81  e85a17edff           call 0x4a02e0
// 005ceb86  8b4604               mov eax, dword ptr [esi + 4]
// 005ceb89  88582c               mov byte ptr [eax + 0x2c], bl
// 005ceb8c  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ceb8f  8b5104               mov edx, dword ptr [ecx + 4]
// 005ceb92  c6422c00             mov byte ptr [edx + 0x2c], 0
// 005ceb96  8b4604               mov eax, dword ptr [esi + 4]
// 005ceb99  8b4004               mov eax, dword ptr [eax + 4]
// 005ceb9c  8b4808               mov ecx, dword ptr [eax + 8]
// 005ceb9f  8b11                 mov edx, dword ptr [ecx]
// 005ceba1  895008               mov dword ptr [eax + 8], edx
// 005ceba4  8b11                 mov edx, dword ptr [ecx]
// 005ceba6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 005cebaa  7503                 jne 0x5cebaf
// 005cebac  894204               mov dword ptr [edx + 4], eax
// 005cebaf  8b5004               mov edx, dword ptr [eax + 4]
// 005cebb2  895104               mov dword ptr [ecx + 4], edx
// 005cebb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cebb8  3b4204               cmp eax, dword ptr [edx + 4]
// 005cebbb  7505                 jne 0x5cebc2
// 005cebbd  894a04               mov dword ptr [edx + 4], ecx
// 005cebc0  eb0e                 jmp 0x5cebd0
// 005cebc2  8b5004               mov edx, dword ptr [eax + 4]
// 005cebc5  3b02                 cmp eax, dword ptr [edx]
// 005cebc7  7504                 jne 0x5cebcd
// 005cebc9  890a                 mov dword ptr [edx], ecx
// 005cebcb  eb03                 jmp 0x5cebd0
// 005cebcd  894a08               mov dword ptr [edx + 8], ecx
// 005cebd0  8901                 mov dword ptr [ecx], eax
// 005cebd2  894804               mov dword ptr [eax + 4], ecx
// 005cebd5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005cebd8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005cebdc  8d4604               lea eax, [esi + 4]
// 005cebdf  0f841bffffff         je 0x5ceb00
// 005cebe5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005cebe8  8b4204               mov eax, dword ptr [edx + 4]
// 005cebeb  88582c               mov byte ptr [eax + 0x2c], bl
// 005cebee  8b442464             mov eax, dword ptr [esp + 0x64]
// 005cebf2  8b0f                 mov ecx, dword ptr [edi]
// 005cebf4  5e                   pop esi
// 005cebf5  896804               mov dword ptr [eax + 4], ebp
// 005cebf8  5d                   pop ebp
// 005cebf9  8908                 mov dword ptr [eax], ecx
// 005cebfb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005cebff  5b                   pop ebx
// 005cec00  5f                   pop edi
// 005cec01  64890d00000000       mov dword ptr fs:[0], ecx
// 005cec08  83c450               add esp, 0x50
// 005cec0b  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
