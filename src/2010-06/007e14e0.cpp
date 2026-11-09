// from server: 100% by auto
// roc 2010-06 007e14e0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e14e0
//
// 007e14e0  55                   push ebp
// 007e14e1  56                   push esi
// 007e14e2  57                   push edi
// 007e14e3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e14e7  33ed                 xor ebp, ebp
// 007e14e9  3bfd                 cmp edi, ebp
// 007e14eb  8bf1                 mov esi, ecx
// 007e14ed  7d05                 jge 0x7e14f4
// 007e14ef  e85867fcff           call 0x7a7c4c
// 007e14f4  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e14f8  3bc5                 cmp eax, ebp
// 007e14fa  7c03                 jl 0x7e14ff
// 007e14fc  894610               mov dword ptr [esi + 0x10], eax
// 007e14ff  3bfd                 cmp edi, ebp
// 007e1501  751f                 jne 0x7e1522
// 007e1503  8b4604               mov eax, dword ptr [esi + 4]
// 007e1506  3bc5                 cmp eax, ebp
// 007e1508  740c                 je 0x7e1516
// 007e150a  50                   push eax
// 007e150b  e83667fcff           call 0x7a7c46
// 007e1510  83c404               add esp, 4
// 007e1513  896e04               mov dword ptr [esi + 4], ebp
// 007e1516  5f                   pop edi
// 007e1517  896e0c               mov dword ptr [esi + 0xc], ebp
// 007e151a  896e08               mov dword ptr [esi + 8], ebp
// 007e151d  5e                   pop esi
// 007e151e  5d                   pop ebp
// 007e151f  c20800               ret 8
// 007e1522  8b4e04               mov ecx, dword ptr [esi + 4]
// 007e1525  53                   push ebx
// 007e1526  3bcd                 cmp ecx, ebp
// 007e1528  7532                 jne 0x7e155c
// 007e152a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007e152d  3bfd                 cmp edi, ebp
// 007e152f  7e02                 jle 0x7e1533
// 007e1531  8bef                 mov ebp, edi
// 007e1533  8d1ced00000000       lea ebx, [ebp*8]
// 007e153a  53                   push ebx
// 007e153b  e84267fcff           call 0x7a7c82
// 007e1540  53                   push ebx
// 007e1541  6a00                 push 0
// 007e1543  50                   push eax
// 007e1544  894604               mov dword ptr [esi + 4], eax
// 007e1547  e89876fcff           call 0x7a8be4
// 007e154c  83c410               add esp, 0x10
// 007e154f  5b                   pop ebx
// 007e1550  897e08               mov dword ptr [esi + 8], edi
// 007e1553  5f                   pop edi
// 007e1554  896e0c               mov dword ptr [esi + 0xc], ebp
// 007e1557  5e                   pop esi
// 007e1558  5d                   pop ebp
// 007e1559  c20800               ret 8
// 007e155c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007e155f  3bfb                 cmp edi, ebx
// 007e1561  7f2d                 jg 0x7e1590
// 007e1563  8b4608               mov eax, dword ptr [esi + 8]
// 007e1566  3bf8                 cmp edi, eax
// 007e1568  0f8ebb000000         jle 0x7e1629
// 007e156e  8bd7                 mov edx, edi
// 007e1570  2bd0                 sub edx, eax
// 007e1572  03d2                 add edx, edx
// 007e1574  03d2                 add edx, edx
// 007e1576  03d2                 add edx, edx
// 007e1578  52                   push edx
// 007e1579  8d04c1               lea eax, [ecx + eax*8]
// 007e157c  55                   push ebp
// 007e157d  50                   push eax
// 007e157e  e86176fcff           call 0x7a8be4
// 007e1583  83c40c               add esp, 0xc
// 007e1586  5b                   pop ebx
// 007e1587  897e08               mov dword ptr [esi + 8], edi
// 007e158a  5f                   pop edi
// 007e158b  5e                   pop esi
// 007e158c  5d                   pop ebp
// 007e158d  c20800               ret 8
// 007e1590  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e1593  3bc5                 cmp eax, ebp
// 007e1595  7524                 jne 0x7e15bb
// 007e1597  8b4608               mov eax, dword ptr [esi + 8]
// 007e159a  99                   cdq 
// 007e159b  83e207               and edx, 7
// 007e159e  03c2                 add eax, edx
// 007e15a0  c1f803               sar eax, 3
// 007e15a3  83f804               cmp eax, 4
// 007e15a6  7d07                 jge 0x7e15af
// 007e15a8  b804000000           mov eax, 4
// 007e15ad  eb0c                 jmp 0x7e15bb
// 007e15af  3d00040000           cmp eax, 0x400
// 007e15b4  7e05                 jle 0x7e15bb
// 007e15b6  b800040000           mov eax, 0x400
// 007e15bb  03c3                 add eax, ebx
// 007e15bd  3bf8                 cmp edi, eax
// 007e15bf  7d06                 jge 0x7e15c7
// 007e15c1  89442414             mov dword ptr [esp + 0x14], eax
// 007e15c5  eb06                 jmp 0x7e15cd
// 007e15c7  897c2414             mov dword ptr [esp + 0x14], edi
// 007e15cb  8bc7                 mov eax, edi
// 007e15cd  3bc3                 cmp eax, ebx
// 007e15cf  7d05                 jge 0x7e15d6
// 007e15d1  e87666fcff           call 0x7a7c4c
// 007e15d6  8d2cc500000000       lea ebp, [eax*8]
// 007e15dd  55                   push ebp
// 007e15de  e89f66fcff           call 0x7a7c82
// 007e15e3  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e15e6  8b5604               mov edx, dword ptr [esi + 4]
// 007e15e9  03c9                 add ecx, ecx
// 007e15eb  03c9                 add ecx, ecx
// 007e15ed  03c9                 add ecx, ecx
// 007e15ef  51                   push ecx
// 007e15f0  52                   push edx
// 007e15f1  8bd8                 mov ebx, eax
// 007e15f3  55                   push ebp
// 007e15f4  53                   push ebx
// 007e15f5  e8f615c2ff           call 0x402bf0
// 007e15fa  8b4608               mov eax, dword ptr [esi + 8]
// 007e15fd  8bcf                 mov ecx, edi
// 007e15ff  2bc8                 sub ecx, eax
// 007e1601  03c9                 add ecx, ecx
// 007e1603  03c9                 add ecx, ecx
// 007e1605  03c9                 add ecx, ecx
// 007e1607  51                   push ecx
// 007e1608  8d14c3               lea edx, [ebx + eax*8]
// 007e160b  6a00                 push 0
// 007e160d  52                   push edx
// 007e160e  e8d175fcff           call 0x7a8be4
// 007e1613  8b4604               mov eax, dword ptr [esi + 4]
// 007e1616  50                   push eax
// 007e1617  e82a66fcff           call 0x7a7c46
// 007e161c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007e1620  83c424               add esp, 0x24
// 007e1623  895e04               mov dword ptr [esi + 4], ebx
// 007e1626  894e0c               mov dword ptr [esi + 0xc], ecx
// 007e1629  5b                   pop ebx
// 007e162a  897e08               mov dword ptr [esi + 8], edi
// 007e162d  5f                   pop edi
// 007e162e  5e                   pop esi
// 007e162f  5d                   pop ebp
// 007e1630  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ?SetSize@?$CArray@VCSize@@V1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
