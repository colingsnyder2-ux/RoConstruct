// from server: 100% by auto
// roc 2009-12 005363e0  unit: RBX::Network::IdSerializer  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005363e0
//
// 005363e0  64a100000000         mov eax, dword ptr fs:[0]
// 005363e6  6aff                 push -1
// 005363e8  6812699500           push 0x956912
// 005363ed  50                   push eax
// 005363ee  64892500000000       mov dword ptr fs:[0], esp
// 005363f5  83ec44               sub esp, 0x44
// 005363f8  57                   push edi
// 005363f9  8bf9                 mov edi, ecx
// 005363fb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 00536402  7259                 jb 0x53645d
// 00536404  6800f59900           push 0x99f500
// 00536409  8d4c2408             lea ecx, [esp + 8]
// 0053640d  ff15f4b69800         call dword ptr [0x98b6f4]
// 00536413  8d4c2420             lea ecx, [esp + 0x20]
// 00536417  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0053641f  ff1554b79800         call dword ptr [0x98b754]
// 00536425  8d442404             lea eax, [esp + 4]
// 00536429  50                   push eax
// 0053642a  8d4c2430             lea ecx, [esp + 0x30]
// 0053642e  c644245401           mov byte ptr [esp + 0x54], 1
// 00536433  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0053643b  ff15f0b69800         call dword ptr [0x98b6f0]
// 00536441  68e4efa800           push 0xa8efe4
// 00536446  8d4c2424             lea ecx, [esp + 0x24]
// 0053644a  51                   push ecx
// 0053644b  c644245800           mov byte ptr [esp + 0x58], 0
// 00536450  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 00536458  e81be42b00           call 0x7f4878
// 0053645d  8b542464             mov edx, dword ptr [esp + 0x64]
// 00536461  8b4718               mov eax, dword ptr [edi + 0x18]
// 00536464  53                   push ebx
// 00536465  55                   push ebp
// 00536466  56                   push esi
// 00536467  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0053646b  6a00                 push 0
// 0053646d  52                   push edx
// 0053646e  50                   push eax
// 0053646f  56                   push esi
// 00536470  50                   push eax
// 00536471  e8aafdffff           call 0x536220
// 00536476  8be8                 mov ebp, eax
// 00536478  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053647b  bb01000000           mov ebx, 1
// 00536480  015f1c               add dword ptr [edi + 0x1c], ebx
// 00536483  3bf0                 cmp esi, eax
// 00536485  7510                 jne 0x536497
// 00536487  896804               mov dword ptr [eax + 4], ebp
// 0053648a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0053648d  8928                 mov dword ptr [eax], ebp
// 0053648f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00536492  896908               mov dword ptr [ecx + 8], ebp
// 00536495  eb22                 jmp 0x5364b9
// 00536497  807c246800           cmp byte ptr [esp + 0x68], 0
// 0053649c  740d                 je 0x5364ab
// 0053649e  892e                 mov dword ptr [esi], ebp
// 005364a0  8b4718               mov eax, dword ptr [edi + 0x18]
// 005364a3  3b30                 cmp esi, dword ptr [eax]
// 005364a5  7512                 jne 0x5364b9
// 005364a7  8928                 mov dword ptr [eax], ebp
// 005364a9  eb0e                 jmp 0x5364b9
// 005364ab  896e08               mov dword ptr [esi + 8], ebp
// 005364ae  8b4718               mov eax, dword ptr [edi + 0x18]
// 005364b1  3b7008               cmp esi, dword ptr [eax + 8]
// 005364b4  7503                 jne 0x5364b9
// 005364b6  896808               mov dword ptr [eax + 8], ebp
// 005364b9  8b5504               mov edx, dword ptr [ebp + 4]
// 005364bc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005364c0  8d4504               lea eax, [ebp + 4]
// 005364c3  8bf5                 mov esi, ebp
// 005364c5  0f85ea000000         jne 0x5365b5
// 005364cb  eb03                 jmp 0x5364d0
// 005364cd  8d4900               lea ecx, [ecx]
// 005364d0  8b08                 mov ecx, dword ptr [eax]
// 005364d2  8b5104               mov edx, dword ptr [ecx + 4]
// 005364d5  3b0a                 cmp ecx, dword ptr [edx]
// 005364d7  7551                 jne 0x53652a
// 005364d9  8b5208               mov edx, dword ptr [edx + 8]
// 005364dc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 005364e0  7519                 jne 0x5364fb
// 005364e2  88592c               mov byte ptr [ecx + 0x2c], bl
// 005364e5  885a2c               mov byte ptr [edx + 0x2c], bl
// 005364e8  8b10                 mov edx, dword ptr [eax]
// 005364ea  8b4a04               mov ecx, dword ptr [edx + 4]
// 005364ed  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 005364f1  8b10                 mov edx, dword ptr [eax]
// 005364f3  8b7204               mov esi, dword ptr [edx + 4]
// 005364f6  e9aa000000           jmp 0x5365a5
// 005364fb  3b7108               cmp esi, dword ptr [ecx + 8]
// 005364fe  750a                 jne 0x53650a
// 00536500  8bf1                 mov esi, ecx
// 00536502  56                   push esi
// 00536503  8bcf                 mov ecx, edi
// 00536505  e87644f4ff           call 0x47a980
// 0053650a  8b4604               mov eax, dword ptr [esi + 4]
// 0053650d  88582c               mov byte ptr [eax + 0x2c], bl
// 00536510  8b4e04               mov ecx, dword ptr [esi + 4]
// 00536513  8b5104               mov edx, dword ptr [ecx + 4]
// 00536516  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0053651a  8b4604               mov eax, dword ptr [esi + 4]
// 0053651d  8b4804               mov ecx, dword ptr [eax + 4]
// 00536520  51                   push ecx
// 00536521  8bcf                 mov ecx, edi
// 00536523  e8686b1700           call 0x6ad090
// 00536528  eb7b                 jmp 0x5365a5
// 0053652a  8b12                 mov edx, dword ptr [edx]
// 0053652c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 00536530  7516                 jne 0x536548
// 00536532  88592c               mov byte ptr [ecx + 0x2c], bl
// 00536535  885a2c               mov byte ptr [edx + 0x2c], bl
// 00536538  8b10                 mov edx, dword ptr [eax]
// 0053653a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0053653d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 00536541  8b10                 mov edx, dword ptr [eax]
// 00536543  8b7204               mov esi, dword ptr [edx + 4]
// 00536546  eb5d                 jmp 0x5365a5
// 00536548  3b31                 cmp esi, dword ptr [ecx]
// 0053654a  750a                 jne 0x536556
// 0053654c  8bf1                 mov esi, ecx
// 0053654e  56                   push esi
// 0053654f  8bcf                 mov ecx, edi
// 00536551  e83a6b1700           call 0x6ad090
// 00536556  8b4604               mov eax, dword ptr [esi + 4]
// 00536559  88582c               mov byte ptr [eax + 0x2c], bl
// 0053655c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0053655f  8b5104               mov edx, dword ptr [ecx + 4]
// 00536562  c6422c00             mov byte ptr [edx + 0x2c], 0
// 00536566  8b4604               mov eax, dword ptr [esi + 4]
// 00536569  8b4004               mov eax, dword ptr [eax + 4]
// 0053656c  8b4808               mov ecx, dword ptr [eax + 8]
// 0053656f  8b11                 mov edx, dword ptr [ecx]
// 00536571  895008               mov dword ptr [eax + 8], edx
// 00536574  8b11                 mov edx, dword ptr [ecx]
// 00536576  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0053657a  7503                 jne 0x53657f
// 0053657c  894204               mov dword ptr [edx + 4], eax
// 0053657f  8b5004               mov edx, dword ptr [eax + 4]
// 00536582  895104               mov dword ptr [ecx + 4], edx
// 00536585  8b5718               mov edx, dword ptr [edi + 0x18]
// 00536588  3b4204               cmp eax, dword ptr [edx + 4]
// 0053658b  7505                 jne 0x536592
// 0053658d  894a04               mov dword ptr [edx + 4], ecx
// 00536590  eb0e                 jmp 0x5365a0
// 00536592  8b5004               mov edx, dword ptr [eax + 4]
// 00536595  3b02                 cmp eax, dword ptr [edx]
// 00536597  7504                 jne 0x53659d
// 00536599  890a                 mov dword ptr [edx], ecx
// 0053659b  eb03                 jmp 0x5365a0
// 0053659d  894a08               mov dword ptr [edx + 8], ecx
// 005365a0  8901                 mov dword ptr [ecx], eax
// 005365a2  894804               mov dword ptr [eax + 4], ecx
// 005365a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 005365a8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 005365ac  8d4604               lea eax, [esi + 4]
// 005365af  0f841bffffff         je 0x5364d0
// 005365b5  8b5718               mov edx, dword ptr [edi + 0x18]
// 005365b8  8b4204               mov eax, dword ptr [edx + 4]
// 005365bb  88582c               mov byte ptr [eax + 0x2c], bl
// 005365be  8b442464             mov eax, dword ptr [esp + 0x64]
// 005365c2  8b0f                 mov ecx, dword ptr [edi]
// 005365c4  5e                   pop esi
// 005365c5  896804               mov dword ptr [eax + 4], ebp
// 005365c8  5d                   pop ebp
// 005365c9  8908                 mov dword ptr [eax], ecx
// 005365cb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005365cf  5b                   pop ebx
// 005365d0  5f                   pop edi
// 005365d1  64890d00000000       mov dword ptr fs:[0], ecx
// 005365d8  83c450               add esp, 0x50
// 005365db  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
