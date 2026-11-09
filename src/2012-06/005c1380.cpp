// roc 2012-06 005c1380  unit: RakNet::RakPeer  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c1380
//
// 005c1380  6aff                 push -1
// 005c1382  68982bab00           push 0xab2b98
// 005c1387  64a100000000         mov eax, dword ptr fs:[0]
// 005c138d  50                   push eax
// 005c138e  64892500000000       mov dword ptr fs:[0], esp
// 005c1395  83ec0c               sub esp, 0xc
// 005c1398  56                   push esi
// 005c1399  57                   push edi
// 005c139a  33ff                 xor edi, edi
// 005c139c  897c2410             mov dword ptr [esp + 0x10], edi
// 005c13a0  897c2408             mov dword ptr [esp + 8], edi
// 005c13a4  897c240c             mov dword ptr [esp + 0xc], edi
// 005c13a8  8b01                 mov eax, dword ptr [ecx]
// 005c13aa  8b801c010000         mov eax, dword ptr [eax + 0x11c]
// 005c13b0  8d542408             lea edx, [esp + 8]
// 005c13b4  52                   push edx
// 005c13b5  897c2420             mov dword ptr [esp + 0x20], edi
// 005c13b9  ffd0                 call eax
// 005c13bb  8b742424             mov esi, dword ptr [esp + 0x24]
// 005c13bf  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005c13c7  397c240c             cmp dword ptr [esp + 0xc], edi
// 005c13cb  7643                 jbe 0x5c1410
// 005c13cd  8b542428             mov edx, dword ptr [esp + 0x28]
// 005c13d1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c13d5  8b04d1               mov eax, dword ptr [ecx + edx*8]
// 005c13d8  8b5008               mov edx, dword ptr [eax + 8]
// 005c13db  8916                 mov dword ptr [esi], edx
// 005c13dd  8b500c               mov edx, dword ptr [eax + 0xc]
// 005c13e0  895604               mov dword ptr [esi + 4], edx
// 005c13e3  8b5010               mov edx, dword ptr [eax + 0x10]
// 005c13e6  895608               mov dword ptr [esi + 8], edx
// 005c13e9  8b5014               mov edx, dword ptr [eax + 0x14]
// 005c13ec  8b4018               mov eax, dword ptr [eax + 0x18]
// 005c13ef  89560c               mov dword ptr [esi + 0xc], edx
// 005c13f2  894610               mov dword ptr [esi + 0x10], eax
// 005c13f5  397c2410             cmp dword ptr [esp + 0x10], edi
// 005c13f9  766a                 jbe 0x5c1465
// 005c13fb  3bcf                 cmp ecx, edi
// 005c13fd  7466                 je 0x5c1465
// 005c13ff  8b51fc               mov edx, dword ptr [ecx - 4]
// 005c1402  8d79fc               lea edi, [ecx - 4]
// 005c1405  68e0ed5b00           push 0x5bede0
// 005c140a  52                   push edx
// 005c140b  6a08                 push 8
// 005c140d  51                   push ecx
// 005c140e  eb47                 jmp 0x5c1457
// 005c1410  a14c69e200           mov eax, dword ptr [0xe2694c]
// 005c1415  8b0d5069e200         mov ecx, dword ptr [0xe26950]
// 005c141b  8b155469e200         mov edx, dword ptr [0xe26954]
// 005c1421  8906                 mov dword ptr [esi], eax
// 005c1423  a15869e200           mov eax, dword ptr [0xe26958]
// 005c1428  894e04               mov dword ptr [esi + 4], ecx
// 005c142b  8b0d5c69e200         mov ecx, dword ptr [0xe2695c]
// 005c1431  895608               mov dword ptr [esi + 8], edx
// 005c1434  89460c               mov dword ptr [esi + 0xc], eax
// 005c1437  894e10               mov dword ptr [esi + 0x10], ecx
// 005c143a  397c2410             cmp dword ptr [esp + 0x10], edi
// 005c143e  7625                 jbe 0x5c1465
// 005c1440  8b442408             mov eax, dword ptr [esp + 8]
// 005c1444  3bc7                 cmp eax, edi
// 005c1446  741d                 je 0x5c1465
// 005c1448  8b50fc               mov edx, dword ptr [eax - 4]
// 005c144b  8d78fc               lea edi, [eax - 4]
// 005c144e  68e0ed5b00           push 0x5bede0
// 005c1453  52                   push edx
// 005c1454  6a08                 push 8
// 005c1456  50                   push eax
// 005c1457  e8141e3c00           call 0x983270
// 005c145c  57                   push edi
// 005c145d  e8580f3c00           call 0x9823ba
// 005c1462  83c404               add esp, 4
// 005c1465  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c1469  5f                   pop edi
// 005c146a  8bc6                 mov eax, esi
// 005c146c  5e                   pop esi
// 005c146d  64890d00000000       mov dword ptr fs:[0], ecx
// 005c1474  83c418               add esp, 0x18
// 005c1477  c20800               ret 8
// copied from an identical function in another client (function ?GetMyBoundAddress@RakPeer@RakNet@@UAE?AUSystemAddress@2@H@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp