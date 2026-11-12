// from server: 100% by auto
// roc 2008-06 004c1380  unit: ProfiledRakPeer  size: 628 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1380
//
// 004c1380  55                   push ebp
// 004c1381  8d6c2494             lea ebp, [esp - 0x6c]
// 004c1385  81ecc8000000         sub esp, 0xc8
// 004c138b  33c0                 xor eax, eax
// 004c138d  53                   push ebx
// 004c138e  8b5d74               mov ebx, dword ptr [ebp + 0x74]
// 004c1391  56                   push esi
// 004c1392  8b7578               mov esi, dword ptr [ebp + 0x78]
// 004c1395  57                   push edi
// 004c1396  894550               mov dword ptr [ebp + 0x50], eax
// 004c1399  894554               mov dword ptr [ebp + 0x54], eax
// 004c139c  894558               mov dword ptr [ebp + 0x58], eax
// 004c139f  89455c               mov dword ptr [ebp + 0x5c], eax
// 004c13a2  894560               mov dword ptr [ebp + 0x60], eax
// 004c13a5  894564               mov dword ptr [ebp + 0x64], eax
// 004c13a8  894568               mov dword ptr [ebp + 0x68], eax
// 004c13ab  8d45e4               lea eax, [ebp - 0x1c]
// 004c13ae  50                   push eax
// 004c13af  8d4d2c               lea ecx, [ebp + 0x2c]
// 004c13b2  51                   push ecx
// 004c13b3  53                   push ebx
// 004c13b4  56                   push esi
// 004c13b5  c7454c01000000       mov dword ptr [ebp + 0x4c], 1
// 004c13bc  e8dfd8ffff           call 0x4beca0
// 004c13c1  b908000000           mov ecx, 8
// 004c13c6  8d7dc4               lea edi, [ebp - 0x3c]
// 004c13c9  8d552c               lea edx, [ebp + 0x2c]
// 004c13cc  8d45c4               lea eax, [ebp - 0x3c]
// 004c13cf  83c410               add esp, 0x10
// 004c13d2  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c13d4  895528               mov dword ptr [ebp + 0x28], edx
// 004c13d7  894524               mov dword ptr [ebp + 0x24], eax
// 004c13da  c7457401000000       mov dword ptr [ebp + 0x74], 1
// 004c13e1  8b7528               mov esi, dword ptr [ebp + 0x28]
// 004c13e4  8b7d24               mov edi, dword ptr [ebp + 0x24]
// 004c13e7  8b4d74               mov ecx, dword ptr [ebp + 0x74]
// 004c13ea  8b06                 mov eax, dword ptr [esi]
// 004c13ec  33d2                 xor edx, edx
// 004c13ee  2907                 sub dword ptr [edi], eax
// 004c13f0  8b4604               mov eax, dword ptr [esi + 4]
// 004c13f3  194704               sbb dword ptr [edi + 4], eax
// 004c13f6  8b4608               mov eax, dword ptr [esi + 8]
// 004c13f9  194708               sbb dword ptr [edi + 8], eax
// 004c13fc  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c13ff  19470c               sbb dword ptr [edi + 0xc], eax
// 004c1402  e322                 jecxz 0x4c1426
// 004c1404  42                   inc edx
// 004c1405  42                   inc edx
// 004c1406  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004c1409  1904d7               sbb dword ptr [edi + edx*8], eax
// 004c140c  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004c1410  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004c1414  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004c1418  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004c141c  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004c1420  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004c1424  e2de                 loop 0x4c1404
// 004c1426  b908000000           mov ecx, 8
// 004c142b  8bf3                 mov esi, ebx
// 004c142d  8d7d04               lea edi, [ebp + 4]
// 004c1430  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c1432  8d4d04               lea ecx, [ebp + 4]
// 004c1435  51                   push ecx
// 004c1436  8d552c               lea edx, [ebp + 0x2c]
// 004c1439  52                   push edx
// 004c143a  8d45e4               lea eax, [ebp - 0x1c]
// 004c143d  50                   push eax
// 004c143e  51                   push ecx
// 004c143f  e85cd8ffff           call 0x4beca0
// 004c1444  83c410               add esp, 0x10
// 004c1447  33c0                 xor eax, eax
// 004c1449  8da42400000000       lea esp, [esp]
// 004c1450  837c850400           cmp dword ptr [ebp + eax*4 + 4], 0
// 004c1455  751d                 jne 0x4c1474
// 004c1457  40                   inc eax
// 004c1458  83f808               cmp eax, 8
// 004c145b  72f3                 jb 0x4c1450
// 004c145d  8b7d7c               mov edi, dword ptr [ebp + 0x7c]
// 004c1460  8d75c4               lea esi, [ebp - 0x3c]
// 004c1463  b908000000           mov ecx, 8
// 004c1468  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c146a  5f                   pop edi
// 004c146b  5e                   pop esi
// 004c146c  5b                   pop ebx
// 004c146d  83c56c               add ebp, 0x6c
// 004c1470  8be5                 mov esp, ebp
// 004c1472  5d                   pop ebp
// 004c1473  c3                   ret 
// 004c1474  8b7578               mov esi, dword ptr [ebp + 0x78]
// 004c1477  8d55a4               lea edx, [ebp - 0x5c]
// 004c147a  52                   push edx
// 004c147b  56                   push esi
// 004c147c  8d454c               lea eax, [ebp + 0x4c]
// 004c147f  50                   push eax
// 004c1480  8d4d2c               lea ecx, [ebp + 0x2c]
// 004c1483  51                   push ecx
// 004c1484  8d55c4               lea edx, [ebp - 0x3c]
// 004c1487  52                   push edx
// 004c1488  e833deffff           call 0x4bf2c0
// 004c148d  8d45e4               lea eax, [ebp - 0x1c]
// 004c1490  50                   push eax
// 004c1491  8d4d2c               lea ecx, [ebp + 0x2c]
// 004c1494  51                   push ecx
// 004c1495  8d5504               lea edx, [ebp + 4]
// 004c1498  52                   push edx
// 004c1499  50                   push eax
// 004c149a  e801d8ffff           call 0x4beca0
// 004c149f  83c424               add esp, 0x24
// 004c14a2  33c0                 xor eax, eax
// 004c14a4  837c85e400           cmp dword ptr [ebp + eax*4 - 0x1c], 0
// 004c14a9  751d                 jne 0x4c14c8
// 004c14ab  40                   inc eax
// 004c14ac  83f808               cmp eax, 8
// 004c14af  72f3                 jb 0x4c14a4
// 004c14b1  8b7d7c               mov edi, dword ptr [ebp + 0x7c]
// 004c14b4  8d75a4               lea esi, [ebp - 0x5c]
// 004c14b7  b908000000           mov ecx, 8
// 004c14bc  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c14be  5f                   pop edi
// 004c14bf  5e                   pop esi
// 004c14c0  5b                   pop ebx
// 004c14c1  83c56c               add ebp, 0x6c
// 004c14c4  8be5                 mov esp, ebp
// 004c14c6  5d                   pop ebp
// 004c14c7  c3                   ret 
// 004c14c8  8d4d4c               lea ecx, [ebp + 0x4c]
// 004c14cb  51                   push ecx
// 004c14cc  56                   push esi
// 004c14cd  8d55c4               lea edx, [ebp - 0x3c]
// 004c14d0  52                   push edx
// 004c14d1  8d452c               lea eax, [ebp + 0x2c]
// 004c14d4  50                   push eax
// 004c14d5  8d4da4               lea ecx, [ebp - 0x5c]
// 004c14d8  51                   push ecx
// 004c14d9  e8e2ddffff           call 0x4bf2c0
// 004c14de  8d5504               lea edx, [ebp + 4]
// 004c14e1  52                   push edx
// 004c14e2  8d452c               lea eax, [ebp + 0x2c]
// 004c14e5  50                   push eax
// 004c14e6  8d4de4               lea ecx, [ebp - 0x1c]
// 004c14e9  51                   push ecx
// 004c14ea  52                   push edx
// 004c14eb  e8b0d7ffff           call 0x4beca0
// 004c14f0  83c424               add esp, 0x24
// 004c14f3  33c0                 xor eax, eax
// 004c14f5  837c850400           cmp dword ptr [ebp + eax*4 + 4], 0
// 004c14fa  751d                 jne 0x4c1519
// 004c14fc  40                   inc eax
// 004c14fd  83f808               cmp eax, 8
// 004c1500  72f3                 jb 0x4c14f5
// 004c1502  8b7d7c               mov edi, dword ptr [ebp + 0x7c]
// 004c1505  8d754c               lea esi, [ebp + 0x4c]
// 004c1508  b908000000           mov ecx, 8
// 004c150d  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c150f  5f                   pop edi
// 004c1510  5e                   pop esi
// 004c1511  5b                   pop ebx
// 004c1512  83c56c               add ebp, 0x6c
// 004c1515  8be5                 mov esp, ebp
// 004c1517  5d                   pop ebp
// 004c1518  c3                   ret 
// 004c1519  8d45c4               lea eax, [ebp - 0x3c]
// 004c151c  50                   push eax
// 004c151d  56                   push esi
// 004c151e  8d4da4               lea ecx, [ebp - 0x5c]
// 004c1521  51                   push ecx
// 004c1522  8d552c               lea edx, [ebp + 0x2c]
// 004c1525  52                   push edx
// 004c1526  8d454c               lea eax, [ebp + 0x4c]
// 004c1529  50                   push eax
// 004c152a  e891ddffff           call 0x4bf2c0
// 004c152f  8d4de4               lea ecx, [ebp - 0x1c]
// 004c1532  51                   push ecx
// 004c1533  8d552c               lea edx, [ebp + 0x2c]
// 004c1536  52                   push edx
// 004c1537  8d4504               lea eax, [ebp + 4]
// 004c153a  50                   push eax
// 004c153b  51                   push ecx
// 004c153c  e85fd7ffff           call 0x4beca0
// 004c1541  83c424               add esp, 0x24
// 004c1544  33c0                 xor eax, eax
// 004c1546  837c85e400           cmp dword ptr [ebp + eax*4 - 0x1c], 0
// 004c154b  750b                 jne 0x4c1558
// 004c154d  40                   inc eax
// 004c154e  83f808               cmp eax, 8
// 004c1551  72f3                 jb 0x4c1546
// 004c1553  e905ffffff           jmp 0x4c145d
// 004c1558  8d55a4               lea edx, [ebp - 0x5c]
// 004c155b  52                   push edx
// 004c155c  56                   push esi
// 004c155d  8d454c               lea eax, [ebp + 0x4c]
// 004c1560  50                   push eax
// 004c1561  8d4d2c               lea ecx, [ebp + 0x2c]
// 004c1564  51                   push ecx
// 004c1565  8d55c4               lea edx, [ebp - 0x3c]
// 004c1568  52                   push edx
// 004c1569  e852ddffff           call 0x4bf2c0
// 004c156e  8d4504               lea eax, [ebp + 4]
// 004c1571  50                   push eax
// 004c1572  8d4d2c               lea ecx, [ebp + 0x2c]
// 004c1575  51                   push ecx
// 004c1576  8d55e4               lea edx, [ebp - 0x1c]
// 004c1579  52                   push edx
// 004c157a  50                   push eax
// 004c157b  e820d7ffff           call 0x4beca0
// 004c1580  83c424               add esp, 0x24
// 004c1583  33c0                 xor eax, eax
// 004c1585  837c850400           cmp dword ptr [ebp + eax*4 + 4], 0
// 004c158a  750b                 jne 0x4c1597
// 004c158c  40                   inc eax
// 004c158d  83f808               cmp eax, 8
// 004c1590  72f3                 jb 0x4c1585
// 004c1592  e91affffff           jmp 0x4c14b1
// 004c1597  8d4d4c               lea ecx, [ebp + 0x4c]
// 004c159a  51                   push ecx
// 004c159b  56                   push esi
// 004c159c  8d55c4               lea edx, [ebp - 0x3c]
// 004c159f  52                   push edx
// 004c15a0  8d452c               lea eax, [ebp + 0x2c]
// 004c15a3  50                   push eax
// 004c15a4  8d4da4               lea ecx, [ebp - 0x5c]
// 004c15a7  51                   push ecx
// 004c15a8  e813ddffff           call 0x4bf2c0
// 004c15ad  8d55e4               lea edx, [ebp - 0x1c]
// 004c15b0  52                   push edx
// 004c15b1  8d452c               lea eax, [ebp + 0x2c]
// 004c15b4  50                   push eax
// 004c15b5  8d4d04               lea ecx, [ebp + 4]
// 004c15b8  51                   push ecx
// 004c15b9  52                   push edx
// 004c15ba  e8e1d6ffff           call 0x4beca0
// 004c15bf  83c424               add esp, 0x24
// 004c15c2  33c0                 xor eax, eax
// 004c15c4  837c85e400           cmp dword ptr [ebp + eax*4 - 0x1c], 0
// 004c15c9  750b                 jne 0x4c15d6
// 004c15cb  40                   inc eax
// 004c15cc  83f808               cmp eax, 8
// 004c15cf  72f3                 jb 0x4c15c4
// 004c15d1  e92cffffff           jmp 0x4c1502
// 004c15d6  8d45c4               lea eax, [ebp - 0x3c]
// 004c15d9  50                   push eax
// 004c15da  56                   push esi
// 004c15db  8d4da4               lea ecx, [ebp - 0x5c]
// 004c15de  51                   push ecx
// 004c15df  8d552c               lea edx, [ebp + 0x2c]
// 004c15e2  52                   push edx
// 004c15e3  8d454c               lea eax, [ebp + 0x4c]
// 004c15e6  50                   push eax
// 004c15e7  e8d4dcffff           call 0x4bf2c0
// 004c15ec  83c414               add esp, 0x14
// 004c15ef  e93efeffff           jmp 0x4c1432
// library openrbx-raknet/RakPeer.cpp (function ??$computeModularInverse@$$BY07I@big@@YAXAAY07I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
