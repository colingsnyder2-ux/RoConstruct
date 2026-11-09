// from server: 100% by auto
// roc 2009-12 00534ef0  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00534ef0
//
// 00534ef0  64a100000000         mov eax, dword ptr fs:[0]
// 00534ef6  6aff                 push -1
// 00534ef8  6812699500           push 0x956912
// 00534efd  50                   push eax
// 00534efe  64892500000000       mov dword ptr fs:[0], esp
// 00534f05  83ec44               sub esp, 0x44
// 00534f08  57                   push edi
// 00534f09  8bf9                 mov edi, ecx
// 00534f0b  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00534f12  7259                 jb 0x534f6d
// 00534f14  6800f59900           push 0x99f500
// 00534f19  8d4c2408             lea ecx, [esp + 8]
// 00534f1d  ff15f4b69800         call dword ptr [0x98b6f4]
// 00534f23  8d4c2420             lea ecx, [esp + 0x20]
// 00534f27  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00534f2f  ff1554b79800         call dword ptr [0x98b754]
// 00534f35  8d442404             lea eax, [esp + 4]
// 00534f39  50                   push eax
// 00534f3a  8d4c2430             lea ecx, [esp + 0x30]
// 00534f3e  c644245401           mov byte ptr [esp + 0x54], 1
// 00534f43  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 00534f4b  ff15f0b69800         call dword ptr [0x98b6f0]
// 00534f51  68e4efa800           push 0xa8efe4
// 00534f56  8d4c2424             lea ecx, [esp + 0x24]
// 00534f5a  51                   push ecx
// 00534f5b  c644245800           mov byte ptr [esp + 0x58], 0
// 00534f60  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00534f68  e80bf92b00           call 0x7f4878
// 00534f6d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00534f71  8b4718               mov eax, dword ptr [edi + 0x18]
// 00534f74  53                   push ebx
// 00534f75  55                   push ebp
// 00534f76  56                   push esi
// 00534f77  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00534f7b  6a00                 push 0
// 00534f7d  52                   push edx
// 00534f7e  50                   push eax
// 00534f7f  56                   push esi
// 00534f80  50                   push eax
// 00534f81  e86af2ffff           call 0x5341f0
// 00534f86  8be8                 mov ebp, eax
// 00534f88  8b4718               mov eax, dword ptr [edi + 0x18]
// 00534f8b  bb01000000           mov ebx, 1
// 00534f90  015f1c               add dword ptr [edi + 0x1c], ebx
// 00534f93  3bf0                 cmp esi, eax
// 00534f95  7510                 jne 0x534fa7
// 00534f97  896804               mov dword ptr [eax + 4], ebp
// 00534f9a  8b4718               mov eax, dword ptr [edi + 0x18]
// 00534f9d  8928                 mov dword ptr [eax], ebp
// 00534f9f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00534fa2  896908               mov dword ptr [ecx + 8], ebp
// 00534fa5  eb22                 jmp 0x534fc9
// 00534fa7  807c246800           cmp byte ptr [esp + 0x68], 0
// 00534fac  740d                 je 0x534fbb
// 00534fae  892e                 mov dword ptr [esi], ebp
// 00534fb0  8b4718               mov eax, dword ptr [edi + 0x18]
// 00534fb3  3b30                 cmp esi, dword ptr [eax]
// 00534fb5  7512                 jne 0x534fc9
// 00534fb7  8928                 mov dword ptr [eax], ebp
// 00534fb9  eb0e                 jmp 0x534fc9
// 00534fbb  896e08               mov dword ptr [esi + 8], ebp
// 00534fbe  8b4718               mov eax, dword ptr [edi + 0x18]
// 00534fc1  3b7008               cmp esi, dword ptr [eax + 8]
// 00534fc4  7503                 jne 0x534fc9
// 00534fc6  896808               mov dword ptr [eax + 8], ebp
// 00534fc9  8b5504               mov edx, dword ptr [ebp + 4]
// 00534fcc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00534fd0  8d4504               lea eax, [ebp + 4]
// 00534fd3  8bf5                 mov esi, ebp
// 00534fd5  0f85ea000000         jne 0x5350c5
// 00534fdb  eb03                 jmp 0x534fe0
// 00534fdd  8d4900               lea ecx, [ecx]
// 00534fe0  8b08                 mov ecx, dword ptr [eax]
// 00534fe2  8b5104               mov edx, dword ptr [ecx + 4]
// 00534fe5  3b0a                 cmp ecx, dword ptr [edx]
// 00534fe7  7551                 jne 0x53503a
// 00534fe9  8b5208               mov edx, dword ptr [edx + 8]
// 00534fec  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00534ff0  7519                 jne 0x53500b
// 00534ff2  88592c               mov byte ptr [ecx + 0x2c], bl
// 00534ff5  885a2c               mov byte ptr [edx + 0x2c], bl
// 00534ff8  8b10                 mov edx, dword ptr [eax]
// 00534ffa  8b4a04               mov ecx, dword ptr [edx + 4]
// 00534ffd  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00535001  8b10                 mov edx, dword ptr [eax]
// 00535003  8b7204               mov esi, dword ptr [edx + 4]
// 00535006  e9aa000000           jmp 0x5350b5
// 0053500b  3b7108               cmp esi, dword ptr [ecx + 8]
// 0053500e  750a                 jne 0x53501a
// 00535010  8bf1                 mov esi, ecx
// 00535012  56                   push esi
// 00535013  8bcf                 mov ecx, edi
// 00535015  e86659f4ff           call 0x47a980
// 0053501a  8b4604               mov eax, dword ptr [esi + 4]
// 0053501d  88582c               mov byte ptr [eax + 0x2c], bl
// 00535020  8b4e04               mov ecx, dword ptr [esi + 4]
// 00535023  8b5104               mov edx, dword ptr [ecx + 4]
// 00535026  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0053502a  8b4604               mov eax, dword ptr [esi + 4]
// 0053502d  8b4804               mov ecx, dword ptr [eax + 4]
// 00535030  51                   push ecx
// 00535031  8bcf                 mov ecx, edi
// 00535033  e858801700           call 0x6ad090
// 00535038  eb7b                 jmp 0x5350b5
// 0053503a  8b12                 mov edx, dword ptr [edx]
// 0053503c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00535040  7516                 jne 0x535058
// 00535042  88592c               mov byte ptr [ecx + 0x2c], bl
// 00535045  885a2c               mov byte ptr [edx + 0x2c], bl
// 00535048  8b10                 mov edx, dword ptr [eax]
// 0053504a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053504d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00535051  8b10                 mov edx, dword ptr [eax]
// 00535053  8b7204               mov esi, dword ptr [edx + 4]
// 00535056  eb5d                 jmp 0x5350b5
// 00535058  3b31                 cmp esi, dword ptr [ecx]
// 0053505a  750a                 jne 0x535066
// 0053505c  8bf1                 mov esi, ecx
// 0053505e  56                   push esi
// 0053505f  8bcf                 mov ecx, edi
// 00535061  e82a801700           call 0x6ad090
// 00535066  8b4604               mov eax, dword ptr [esi + 4]
// 00535069  88582c               mov byte ptr [eax + 0x2c], bl
// 0053506c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053506f  8b5104               mov edx, dword ptr [ecx + 4]
// 00535072  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00535076  8b4604               mov eax, dword ptr [esi + 4]
// 00535079  8b4004               mov eax, dword ptr [eax + 4]
// 0053507c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053507f  8b11                 mov edx, dword ptr [ecx]
// 00535081  895008               mov dword ptr [eax + 8], edx
// 00535084  8b11                 mov edx, dword ptr [ecx]
// 00535086  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0053508a  7503                 jne 0x53508f
// 0053508c  894204               mov dword ptr [edx + 4], eax
// 0053508f  8b5004               mov edx, dword ptr [eax + 4]
// 00535092  895104               mov dword ptr [ecx + 4], edx
// 00535095  8b5718               mov edx, dword ptr [edi + 0x18]
// 00535098  3b4204               cmp eax, dword ptr [edx + 4]
// 0053509b  7505                 jne 0x5350a2
// 0053509d  894a04               mov dword ptr [edx + 4], ecx
// 005350a0  eb0e                 jmp 0x5350b0
// 005350a2  8b5004               mov edx, dword ptr [eax + 4]
// 005350a5  3b02                 cmp eax, dword ptr [edx]
// 005350a7  7504                 jne 0x5350ad
// 005350a9  890a                 mov dword ptr [edx], ecx
// 005350ab  eb03                 jmp 0x5350b0
// 005350ad  894a08               mov dword ptr [edx + 8], ecx
// 005350b0  8901                 mov dword ptr [ecx], eax
// 005350b2  894804               mov dword ptr [eax + 4], ecx
// 005350b5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005350b8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005350bc  8d4604               lea eax, [esi + 4]
// 005350bf  0f841bffffff         je 0x534fe0
// 005350c5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005350c8  8b4204               mov eax, dword ptr [edx + 4]
// 005350cb  88582c               mov byte ptr [eax + 0x2c], bl
// 005350ce  8b442464             mov eax, dword ptr [esp + 0x64]
// 005350d2  8b0f                 mov ecx, dword ptr [edi]
// 005350d4  5e                   pop esi
// 005350d5  896804               mov dword ptr [eax + 4], ebp
// 005350d8  5d                   pop ebp
// 005350d9  8908                 mov dword ptr [eax], ecx
// 005350db  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005350df  5b                   pop ebx
// 005350e0  5f                   pop edi
// 005350e1  64890d00000000       mov dword ptr fs:[0], ecx
// 005350e8  83c450               add esp, 0x50
// 005350eb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
