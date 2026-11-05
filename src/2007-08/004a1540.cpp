// from server: 100% by auto
// roc 2007-08 004a1540  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 493 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1540
//
// 004a1540  6aff                 push -1
// 004a1542  68293a7400           push 0x743a29
// 004a1547  64a100000000         mov eax, dword ptr fs:[0]
// 004a154d  50                   push eax
// 004a154e  83ec44               sub esp, 0x44
// 004a1551  53                   push ebx
// 004a1552  55                   push ebp
// 004a1553  56                   push esi
// 004a1554  57                   push edi
// 004a1555  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a155a  33c4                 xor eax, esp
// 004a155c  50                   push eax
// 004a155d  8d442458             lea eax, [esp + 0x58]
// 004a1561  64a300000000         mov dword ptr fs:[0], eax
// 004a1567  8bf9                 mov edi, ecx
// 004a1569  817f08feffff07       cmp dword ptr [edi + 8], 0x7fffffe
// 004a1570  723c                 jb 0x4a15ae
// 004a1572  68904f7800           push 0x784f90
// 004a1577  8d4c2418             lea ecx, [esp + 0x18]
// 004a157b  ff1598e67700         call dword ptr [0x77e698]
// 004a1581  8d442414             lea eax, [esp + 0x14]
// 004a1585  50                   push eax
// 004a1586  8d4c2434             lea ecx, [esp + 0x34]
// 004a158a  c744246400000000     mov dword ptr [esp + 0x64], 0
// 004a1592  e8290ff6ff           call 0x4024c0
// 004a1597  6878f78300           push 0x83f778
// 004a159c  8d4c2434             lea ecx, [esp + 0x34]
// 004a15a0  51                   push ecx
// 004a15a1  c74424386c4e7800     mov dword ptr [esp + 0x38], 0x784e6c
// 004a15a9  e8f0f51800           call 0x630b9e
// 004a15ae  8b542474             mov edx, dword ptr [esp + 0x74]
// 004a15b2  8b4704               mov eax, dword ptr [edi + 4]
// 004a15b5  8b742470             mov esi, dword ptr [esp + 0x70]
// 004a15b9  6a00                 push 0
// 004a15bb  52                   push edx
// 004a15bc  50                   push eax
// 004a15bd  56                   push esi
// 004a15be  50                   push eax
// 004a15bf  e8bcfbffff           call 0x4a1180
// 004a15c4  8be8                 mov ebp, eax
// 004a15c6  8b4704               mov eax, dword ptr [edi + 4]
// 004a15c9  bb01000000           mov ebx, 1
// 004a15ce  015f08               add dword ptr [edi + 8], ebx
// 004a15d1  3bf0                 cmp esi, eax
// 004a15d3  7510                 jne 0x4a15e5
// 004a15d5  896804               mov dword ptr [eax + 4], ebp
// 004a15d8  8b4704               mov eax, dword ptr [edi + 4]
// 004a15db  8928                 mov dword ptr [eax], ebp
// 004a15dd  8b4f04               mov ecx, dword ptr [edi + 4]
// 004a15e0  896908               mov dword ptr [ecx + 8], ebp
// 004a15e3  eb22                 jmp 0x4a1607
// 004a15e5  807c246c00           cmp byte ptr [esp + 0x6c], 0
// 004a15ea  740d                 je 0x4a15f9
// 004a15ec  892e                 mov dword ptr [esi], ebp
// 004a15ee  8b4704               mov eax, dword ptr [edi + 4]
// 004a15f1  3b30                 cmp esi, dword ptr [eax]
// 004a15f3  7512                 jne 0x4a1607
// 004a15f5  8928                 mov dword ptr [eax], ebp
// 004a15f7  eb0e                 jmp 0x4a1607
// 004a15f9  896e08               mov dword ptr [esi + 8], ebp
// 004a15fc  8b4704               mov eax, dword ptr [edi + 4]
// 004a15ff  3b7008               cmp esi, dword ptr [eax + 8]
// 004a1602  7503                 jne 0x4a1607
// 004a1604  896808               mov dword ptr [eax + 8], ebp
// 004a1607  8b5504               mov edx, dword ptr [ebp + 4]
// 004a160a  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a160e  8d4504               lea eax, [ebp + 4]
// 004a1611  8bf5                 mov esi, ebp
// 004a1613  0f85ec000000         jne 0x4a1705
// 004a1619  8da42400000000       lea esp, [esp]
// 004a1620  8b08                 mov ecx, dword ptr [eax]
// 004a1622  8b5104               mov edx, dword ptr [ecx + 4]
// 004a1625  3b0a                 cmp ecx, dword ptr [edx]
// 004a1627  7551                 jne 0x4a167a
// 004a1629  8b5208               mov edx, dword ptr [edx + 8]
// 004a162c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a1630  7519                 jne 0x4a164b
// 004a1632  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a1635  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a1638  8b10                 mov edx, dword ptr [eax]
// 004a163a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a163d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a1641  8b10                 mov edx, dword ptr [eax]
// 004a1643  8b7204               mov esi, dword ptr [edx + 4]
// 004a1646  e9aa000000           jmp 0x4a16f5
// 004a164b  3b7108               cmp esi, dword ptr [ecx + 8]
// 004a164e  750a                 jne 0x4a165a
// 004a1650  8bf1                 mov esi, ecx
// 004a1652  56                   push esi
// 004a1653  8bcf                 mov ecx, edi
// 004a1655  e836f9ffff           call 0x4a0f90
// 004a165a  8b4604               mov eax, dword ptr [esi + 4]
// 004a165d  88582c               mov byte ptr [eax + 0x2c], bl
// 004a1660  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a1663  8b5104               mov edx, dword ptr [ecx + 4]
// 004a1666  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a166a  8b4604               mov eax, dword ptr [esi + 4]
// 004a166d  8b4804               mov ecx, dword ptr [eax + 4]
// 004a1670  51                   push ecx
// 004a1671  8bcf                 mov ecx, edi
// 004a1673  e868f8ffff           call 0x4a0ee0
// 004a1678  eb7b                 jmp 0x4a16f5
// 004a167a  8b12                 mov edx, dword ptr [edx]
// 004a167c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 004a1680  7516                 jne 0x4a1698
// 004a1682  88592c               mov byte ptr [ecx + 0x2c], bl
// 004a1685  885a2c               mov byte ptr [edx + 0x2c], bl
// 004a1688  8b10                 mov edx, dword ptr [eax]
// 004a168a  8b4a04               mov ecx, dword ptr [edx + 4]
// 004a168d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 004a1691  8b10                 mov edx, dword ptr [eax]
// 004a1693  8b7204               mov esi, dword ptr [edx + 4]
// 004a1696  eb5d                 jmp 0x4a16f5
// 004a1698  3b31                 cmp esi, dword ptr [ecx]
// 004a169a  750a                 jne 0x4a16a6
// 004a169c  8bf1                 mov esi, ecx
// 004a169e  56                   push esi
// 004a169f  8bcf                 mov ecx, edi
// 004a16a1  e83af8ffff           call 0x4a0ee0
// 004a16a6  8b4604               mov eax, dword ptr [esi + 4]
// 004a16a9  88582c               mov byte ptr [eax + 0x2c], bl
// 004a16ac  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a16af  8b5104               mov edx, dword ptr [ecx + 4]
// 004a16b2  c6422c00             mov byte ptr [edx + 0x2c], 0
// 004a16b6  8b4604               mov eax, dword ptr [esi + 4]
// 004a16b9  8b4004               mov eax, dword ptr [eax + 4]
// 004a16bc  8b4808               mov ecx, dword ptr [eax + 8]
// 004a16bf  8b11                 mov edx, dword ptr [ecx]
// 004a16c1  895008               mov dword ptr [eax + 8], edx
// 004a16c4  8b11                 mov edx, dword ptr [ecx]
// 004a16c6  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 004a16ca  7503                 jne 0x4a16cf
// 004a16cc  894204               mov dword ptr [edx + 4], eax
// 004a16cf  8b5004               mov edx, dword ptr [eax + 4]
// 004a16d2  895104               mov dword ptr [ecx + 4], edx
// 004a16d5  8b5704               mov edx, dword ptr [edi + 4]
// 004a16d8  3b4204               cmp eax, dword ptr [edx + 4]
// 004a16db  7505                 jne 0x4a16e2
// 004a16dd  894a04               mov dword ptr [edx + 4], ecx
// 004a16e0  eb0e                 jmp 0x4a16f0
// 004a16e2  8b5004               mov edx, dword ptr [eax + 4]
// 004a16e5  3b02                 cmp eax, dword ptr [edx]
// 004a16e7  7504                 jne 0x4a16ed
// 004a16e9  890a                 mov dword ptr [edx], ecx
// 004a16eb  eb03                 jmp 0x4a16f0
// 004a16ed  894a08               mov dword ptr [edx + 8], ecx
// 004a16f0  8901                 mov dword ptr [ecx], eax
// 004a16f2  894804               mov dword ptr [eax + 4], ecx
// 004a16f5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004a16f8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 004a16fc  8d4604               lea eax, [esi + 4]
// 004a16ff  0f841bffffff         je 0x4a1620
// 004a1705  8b5704               mov edx, dword ptr [edi + 4]
// 004a1708  8b4204               mov eax, dword ptr [edx + 4]
// 004a170b  88582c               mov byte ptr [eax + 0x2c], bl
// 004a170e  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a1712  896804               mov dword ptr [eax + 4], ebp
// 004a1715  8938                 mov dword ptr [eax], edi
// 004a1717  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 004a171b  64890d00000000       mov dword ptr fs:[0], ecx
// 004a1722  59                   pop ecx
// 004a1723  5f                   pop edi
// 004a1724  5e                   pop esi
// 004a1725  5d                   pop ebp
// 004a1726  5b                   pop ebx
// 004a1727  83c450               add esp, 0x50
// 004a172a  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
