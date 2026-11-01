// from server: 100% by auto
// roc 2007-08 004a1350  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1350
//
// 004a1350  6aff                 push -1
// 004a1352  68293a7400           push 0x743a29
// 004a1357  64a100000000         mov eax, dword ptr fs:[0]
// 004a135d  50                   push eax
// 004a135e  83ec44               sub esp, 0x44
// 004a1361  53                   push ebx
// 004a1362  55                   push ebp
// 004a1363  56                   push esi
// 004a1364  57                   push edi
// 004a1365  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a136a  33c4                 xor eax, esp
// 004a136c  50                   push eax
// 004a136d  8d442458             lea eax, [esp + 0x58]
// 004a1371  64a300000000         mov dword ptr fs:[0], eax
// 004a1377  8bf9                 mov edi, ecx
// 004a1379  817f08feffff07       cmp dword ptr [edi + 8], 0x7fffffe
// 004a1380  723c                 jb 0x4a13be
// 004a1382  68904f7800           push 0x784f90
// 004a1387  8d4c2418             lea ecx, [esp + 0x18]
// 004a138b  ff1598e67700         call dword ptr [0x77e698]
// 004a1391  8d442414             lea eax, [esp + 0x14]
// 004a1395  50                   push eax
// 004a1396  8d4c2434             lea ecx, [esp + 0x34]
// 004a139a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a13a2  e81911f6ff           call 0x4024c0
// 004a13a7  6878f78300           push 0x83f778
// 004a13ac  8d4c2434             lea ecx, [esp + 0x34]
// 004a13b0  51                   push ecx
// 004a13b1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a13b9  e8e0f71800           call 0x630b9e
// 004a13be  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a13c2  8b4704               mov eax, dword ptr [edi + 4]
// 004a13c5  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a13c9  6a00                 push 0
// 004a13cb  52                   push edx
// 004a13cc  50                   push eax
// 004a13cd  56                   push esi
// 004a13ce  50                   push eax
// 004a13cf  e8fcfcffff           call 0x4a10d0
// 004a13d4  8be8                 mov ebp, eax
// 004a13d6  8b4704               mov eax, dword ptr [edi + 4]
// 004a13d9  bb01000000           mov ebx, 1
// 004a13de  015f08               add dword ptr [edi + 8], ebx
// 004a13e1  3bf0                 cmp esi, eax
// 004a13e3  7510                 jne 0x4a13f5
// 004a13e5  896804               mov dword ptr [eax + 4], ebp
// 004a13e8  8b4704               mov eax, dword ptr [edi + 4]
// 004a13eb  8928                 mov dword ptr [eax], ebp
// 004a13ed  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a13f0  896908               mov dword ptr [ecx + 8], ebp
// 004a13f3  eb22                 jmp 0x4a1417
// 004a13f5  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a13fa  740d                 je 0x4a1409
// 004a13fc  892e                 mov dword ptr [esi], ebp
// 004a13fe  8b4704               mov eax, dword ptr [edi + 4]
// 004a1401  3b30                 cmp esi, dword ptr [eax]
// 004a1403  7512                 jne 0x4a1417
// 004a1405  8928                 mov dword ptr [eax], ebp
// 004a1407  eb0e                 jmp 0x4a1417
// 004a1409  896e08               mov dword ptr [esi + 8], ebp
// 004a140c  8b4704               mov eax, dword ptr [edi + 4]
// 004a140f  3b7008               cmp esi, dword ptr [eax + 8]
// 004a1412  7503                 jne 0x4a1417
// 004a1414  896808               mov dword ptr [eax + 8], ebp
// 004a1417  8b5504               mov edx, dword ptr [ebp + 4]
// 004a141a  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a141e  8d4504               lea eax, [ebp + 4]
// 004a1421  8bf5                 mov esi, ebp
// 004a1423  0f85ec000000         jne 0x4a1515
// 004a1429  8da42400000000       lea esp, [esp]
// 004a1430  8b08                 mov ecx, dword ptr [eax]
// 004a1432  8b5104               mov edx, dword ptr [ecx + 4]
// 004a1435  3b0a                 cmp ecx, dword ptr [edx]
// 004a1437  7551                 jne 0x4a148a
// 004a1439  8b5208               mov edx, dword ptr [edx + 8]
// 004a143c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a1440  7519                 jne 0x4a145b
// 004a1442  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a1445  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a1448  8b10                 mov edx, dword ptr [eax]
// 004a144a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a144d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a1451  8b10                 mov edx, dword ptr [eax]
// 004a1453  8b7204               mov esi, dword ptr [edx + 4]
// 004a1456  e9aa000000           jmp 0x4a1505
// 004a145b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a145e  750a                 jne 0x4a146a
// 004a1460  8bf1                 mov esi, ecx
// 004a1462  56                   push esi
// 004a1463  8bcf                 mov ecx, edi
// 004a1465  e826fbffff           call 0x4a0f90
// 004a146a  8b4604               mov eax, dword ptr [esi + 4]
// 004a146d  88582c               mov byte ptr [eax + 0x2c], bl
// 004a1470  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a1473  8b5104               mov edx, dword ptr [ecx + 4]
// 004a1476  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a147a  8b4604               mov eax, dword ptr [esi + 4]
// 004a147d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a1480  51                   push ecx
// 004a1481  8bcf                 mov ecx, edi
// 004a1483  e858faffff           call 0x4a0ee0
// 004a1488  eb7b                 jmp 0x4a1505
// 004a148a  8b12                 mov edx, dword ptr [edx]
// 004a148c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a1490  7516                 jne 0x4a14a8
// 004a1492  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a1495  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a1498  8b10                 mov edx, dword ptr [eax]
// 004a149a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a149d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a14a1  8b10                 mov edx, dword ptr [eax]
// 004a14a3  8b7204               mov esi, dword ptr [edx + 4]
// 004a14a6  eb5d                 jmp 0x4a1505
// 004a14a8  3b31                 cmp esi, dword ptr [ecx]
// 004a14aa  750a                 jne 0x4a14b6
// 004a14ac  8bf1                 mov esi, ecx
// 004a14ae  56                   push esi
// 004a14af  8bcf                 mov ecx, edi
// 004a14b1  e82afaffff           call 0x4a0ee0
// 004a14b6  8b4604               mov eax, dword ptr [esi + 4]
// 004a14b9  88582c               mov byte ptr [eax + 0x2c], bl
// 004a14bc  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a14bf  8b5104               mov edx, dword ptr [ecx + 4]
// 004a14c2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a14c6  8b4604               mov eax, dword ptr [esi + 4]
// 004a14c9  8b4004               mov eax, dword ptr [eax + 4]
// 004a14cc  8b4808               mov ecx, dword ptr [eax + 8]
// 004a14cf  8b11                 mov edx, dword ptr [ecx]
// 004a14d1  895008               mov dword ptr [eax + 8], edx
// 004a14d4  8b11                 mov edx, dword ptr [ecx]
// 004a14d6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004a14da  7503                 jne 0x4a14df
// 004a14dc  894204               mov dword ptr [edx + 4], eax
// 004a14df  8b5004               mov edx, dword ptr [eax + 4]
// 004a14e2  895104               mov dword ptr [ecx + 4], edx
// 004a14e5  8b5704               mov edx, dword ptr [edi + 4]
// 004a14e8  3b4204               cmp eax, dword ptr [edx + 4]
// 004a14eb  7505                 jne 0x4a14f2
// 004a14ed  894a04               mov dword ptr [edx + 4], ecx
// 004a14f0  eb0e                 jmp 0x4a1500
// 004a14f2  8b5004               mov edx, dword ptr [eax + 4]
// 004a14f5  3b02                 cmp eax, dword ptr [edx]
// 004a14f7  7504                 jne 0x4a14fd
// 004a14f9  890a                 mov dword ptr [edx], ecx
// 004a14fb  eb03                 jmp 0x4a1500
// 004a14fd  894a08               mov dword ptr [edx + 8], ecx
// 004a1500  8901                 mov dword ptr [ecx], eax
// 004a1502  894804               mov dword ptr [eax + 4], ecx
// 004a1505  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a1508  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004a150c  8d4604               lea eax, [esi + 4]
// 004a150f  0f841bffffff         je 0x4a1430
// 004a1515  8b5704               mov edx, dword ptr [edi + 4]
// 004a1518  8b4204               mov eax, dword ptr [edx + 4]
// 004a151b  88582c               mov byte ptr [eax + 0x2c], bl
// 004a151e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a1522  896804               mov dword ptr [eax + 4], ebp
// 004a1525  8938                 mov dword ptr [eax], edi
// 004a1527  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a152b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a1532  59                   pop ecx
// 004a1533  5f                   pop edi
// 004a1534  5e                   pop esi
// 004a1535  5d                   pop ebp
// 004a1536  5b                   pop ebx
// 004a1537  83c450               add esp, 0x50
// 004a153a  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
