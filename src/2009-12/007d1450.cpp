// from server: 100% by auto
// roc 2009-12 007d1450  unit: seg_007d0000  size: 326 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1450
//
// 007d1450  51                   push ecx
// 007d1451  53                   push ebx
// 007d1452  55                   push ebp
// 007d1453  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 007d1457  56                   push esi
// 007d1458  8bf0                 mov esi, eax
// 007d145a  837e0c00             cmp dword ptr [esi + 0xc], 0
// 007d145e  57                   push edi
// 007d145f  7404                 je 0x7d1465
// 007d1461  33ff                 xor edi, edi
// 007d1463  eb03                 jmp 0x7d1468
// 007d1465  8b7d30               mov edi, dword ptr [ebp + 0x30]
// 007d1468  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d146c  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 007d146f  897c2418             mov dword ptr [esp + 0x18], edi
// 007d1473  7538                 jne 0x7d14ad
// 007d1475  8b4608               mov eax, dword ptr [esi + 8]
// 007d1478  8b16                 mov edx, dword ptr [esi]
// 007d147a  50                   push eax
// 007d147b  8b4604               mov eax, dword ptr [esi + 4]
// 007d147e  6a04                 push 4
// 007d1480  8d4c2420             lea ecx, [esp + 0x20]
// 007d1484  51                   push ecx
// 007d1485  52                   push edx
// 007d1486  ffd0                 call eax
// 007d1488  83c410               add esp, 0x10
// 007d148b  894610               mov dword ptr [esi + 0x10], eax
// 007d148e  85c0                 test eax, eax
// 007d1490  751b                 jne 0x7d14ad
// 007d1492  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d1495  8b06                 mov eax, dword ptr [esi]
// 007d1497  51                   push ecx
// 007d1498  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d149b  8d14bd00000000       lea edx, [edi*4]
// 007d14a2  52                   push edx
// 007d14a3  53                   push ebx
// 007d14a4  50                   push eax
// 007d14a5  ffd1                 call ecx
// 007d14a7  83c410               add esp, 0x10
// 007d14aa  894610               mov dword ptr [esi + 0x10], eax
// 007d14ad  837e0c00             cmp dword ptr [esi + 0xc], 0
// 007d14b1  7404                 je 0x7d14b7
// 007d14b3  33db                 xor ebx, ebx
// 007d14b5  eb03                 jmp 0x7d14ba
// 007d14b7  8b5d38               mov ebx, dword ptr [ebp + 0x38]
// 007d14ba  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d14be  895c2418             mov dword ptr [esp + 0x18], ebx
// 007d14c2  7519                 jne 0x7d14dd
// 007d14c4  8b5608               mov edx, dword ptr [esi + 8]
// 007d14c7  8b0e                 mov ecx, dword ptr [esi]
// 007d14c9  52                   push edx
// 007d14ca  8b5604               mov edx, dword ptr [esi + 4]
// 007d14cd  6a04                 push 4
// 007d14cf  8d442420             lea eax, [esp + 0x20]
// 007d14d3  50                   push eax
// 007d14d4  51                   push ecx
// 007d14d5  ffd2                 call edx
// 007d14d7  83c410               add esp, 0x10
// 007d14da  894610               mov dword ptr [esi + 0x10], eax
// 007d14dd  85db                 test ebx, ebx
// 007d14df  7e69                 jle 0x7d154a
// 007d14e1  33ff                 xor edi, edi
// 007d14e3  8b4518               mov eax, dword ptr [ebp + 0x18]
// 007d14e6  8b0407               mov eax, dword ptr [edi + eax]
// 007d14e9  e8a2fdffff           call 0x7d1290
// 007d14ee  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d14f2  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007d14f5  8b540f04             mov edx, dword ptr [edi + ecx + 4]
// 007d14f9  89542418             mov dword ptr [esp + 0x18], edx
// 007d14fd  7519                 jne 0x7d1518
// 007d14ff  8b4608               mov eax, dword ptr [esi + 8]
// 007d1502  8b16                 mov edx, dword ptr [esi]
// 007d1504  50                   push eax
// 007d1505  8b4604               mov eax, dword ptr [esi + 4]
// 007d1508  6a04                 push 4
// 007d150a  8d4c2420             lea ecx, [esp + 0x20]
// 007d150e  51                   push ecx
// 007d150f  52                   push edx
// 007d1510  ffd0                 call eax
// 007d1512  83c410               add esp, 0x10
// 007d1515  894610               mov dword ptr [esi + 0x10], eax
// 007d1518  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d151c  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007d151f  8b540f08             mov edx, dword ptr [edi + ecx + 8]
// 007d1523  89542410             mov dword ptr [esp + 0x10], edx
// 007d1527  7519                 jne 0x7d1542
// 007d1529  8b4608               mov eax, dword ptr [esi + 8]
// 007d152c  8b16                 mov edx, dword ptr [esi]
// 007d152e  50                   push eax
// 007d152f  8b4604               mov eax, dword ptr [esi + 4]
// 007d1532  6a04                 push 4
// 007d1534  8d4c2418             lea ecx, [esp + 0x18]
// 007d1538  51                   push ecx
// 007d1539  52                   push edx
// 007d153a  ffd0                 call eax
// 007d153c  83c410               add esp, 0x10
// 007d153f  894610               mov dword ptr [esi + 0x10], eax
// 007d1542  83c70c               add edi, 0xc
// 007d1545  83eb01               sub ebx, 1
// 007d1548  7599                 jne 0x7d14e3
// 007d154a  837e0c00             cmp dword ptr [esi + 0xc], 0
// 007d154e  7404                 je 0x7d1554
// 007d1550  33db                 xor ebx, ebx
// 007d1552  eb03                 jmp 0x7d1557
// 007d1554  8b5d24               mov ebx, dword ptr [ebp + 0x24]
// 007d1557  837e1000             cmp dword ptr [esi + 0x10], 0
// 007d155b  895c2418             mov dword ptr [esp + 0x18], ebx
// 007d155f  7519                 jne 0x7d157a
// 007d1561  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d1564  8b06                 mov eax, dword ptr [esi]
// 007d1566  51                   push ecx
// 007d1567  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d156a  6a04                 push 4
// 007d156c  8d542420             lea edx, [esp + 0x20]
// 007d1570  52                   push edx
// 007d1571  50                   push eax
// 007d1572  ffd1                 call ecx
// 007d1574  83c410               add esp, 0x10
// 007d1577  894610               mov dword ptr [esi + 0x10], eax
// 007d157a  33ff                 xor edi, edi
// 007d157c  85db                 test ebx, ebx
// 007d157e  7e10                 jle 0x7d1590
// 007d1580  8b551c               mov edx, dword ptr [ebp + 0x1c]
// 007d1583  8b04ba               mov eax, dword ptr [edx + edi*4]
// 007d1586  e805fdffff           call 0x7d1290
// 007d158b  47                   inc edi
// 007d158c  3bfb                 cmp edi, ebx
// 007d158e  7cf0                 jl 0x7d1580
// 007d1590  5f                   pop edi
// 007d1591  5e                   pop esi
// 007d1592  5d                   pop ebp
// 007d1593  5b                   pop ebx
// 007d1594  59                   pop ecx
// 007d1595  c3                   ret 
// library lua-5.1/ldump.c (function _DumpDebug)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldump.c
