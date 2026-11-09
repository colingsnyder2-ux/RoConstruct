// from server: 100% by auto
// roc 2010-06 007e1300  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e1300
//
// 007e1300  55                   push ebp
// 007e1301  56                   push esi
// 007e1302  57                   push edi
// 007e1303  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e1307  33ed                 xor ebp, ebp
// 007e1309  3bfd                 cmp edi, ebp
// 007e130b  8bf1                 mov esi, ecx
// 007e130d  7d05                 jge 0x7e1314
// 007e130f  e83869fcff           call 0x7a7c4c
// 007e1314  8b442414             mov eax, dword ptr [esp + 0x14]
// 007e1318  3bc5                 cmp eax, ebp
// 007e131a  7c03                 jl 0x7e131f
// 007e131c  894610               mov dword ptr [esi + 0x10], eax
// 007e131f  3bfd                 cmp edi, ebp
// 007e1321  751f                 jne 0x7e1342
// 007e1323  8b4604               mov eax, dword ptr [esi + 4]
// 007e1326  3bc5                 cmp eax, ebp
// 007e1328  740c                 je 0x7e1336
// 007e132a  50                   push eax
// 007e132b  e81669fcff           call 0x7a7c46
// 007e1330  83c404               add esp, 4
// 007e1333  896e04               mov dword ptr [esi + 4], ebp
// 007e1336  5f                   pop edi
// 007e1337  896e0c               mov dword ptr [esi + 0xc], ebp
// 007e133a  896e08               mov dword ptr [esi + 8], ebp
// 007e133d  5e                   pop esi
// 007e133e  5d                   pop ebp
// 007e133f  c20800               ret 8
// 007e1342  8b4e04               mov ecx, dword ptr [esi + 4]
// 007e1345  53                   push ebx
// 007e1346  3bcd                 cmp ecx, ebp
// 007e1348  7532                 jne 0x7e137c
// 007e134a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007e134d  3bfd                 cmp edi, ebp
// 007e134f  7e02                 jle 0x7e1353
// 007e1351  8bef                 mov ebp, edi
// 007e1353  8d1cad00000000       lea ebx, [ebp*4]
// 007e135a  53                   push ebx
// 007e135b  e82269fcff           call 0x7a7c82
// 007e1360  53                   push ebx
// 007e1361  6a00                 push 0
// 007e1363  50                   push eax
// 007e1364  894604               mov dword ptr [esi + 4], eax
// 007e1367  e87878fcff           call 0x7a8be4
// 007e136c  83c410               add esp, 0x10
// 007e136f  5b                   pop ebx
// 007e1370  897e08               mov dword ptr [esi + 8], edi
// 007e1373  5f                   pop edi
// 007e1374  896e0c               mov dword ptr [esi + 0xc], ebp
// 007e1377  5e                   pop esi
// 007e1378  5d                   pop ebp
// 007e1379  c20800               ret 8
// 007e137c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007e137f  3bfb                 cmp edi, ebx
// 007e1381  7f2b                 jg 0x7e13ae
// 007e1383  8b4608               mov eax, dword ptr [esi + 8]
// 007e1386  3bf8                 cmp edi, eax
// 007e1388  0f8eb5000000         jle 0x7e1443
// 007e138e  8bd7                 mov edx, edi
// 007e1390  2bd0                 sub edx, eax
// 007e1392  03d2                 add edx, edx
// 007e1394  03d2                 add edx, edx
// 007e1396  52                   push edx
// 007e1397  8d0481               lea eax, [ecx + eax*4]
// 007e139a  55                   push ebp
// 007e139b  50                   push eax
// 007e139c  e84378fcff           call 0x7a8be4
// 007e13a1  83c40c               add esp, 0xc
// 007e13a4  5b                   pop ebx
// 007e13a5  897e08               mov dword ptr [esi + 8], edi
// 007e13a8  5f                   pop edi
// 007e13a9  5e                   pop esi
// 007e13aa  5d                   pop ebp
// 007e13ab  c20800               ret 8
// 007e13ae  8b4610               mov eax, dword ptr [esi + 0x10]
// 007e13b1  3bc5                 cmp eax, ebp
// 007e13b3  7524                 jne 0x7e13d9
// 007e13b5  8b4608               mov eax, dword ptr [esi + 8]
// 007e13b8  99                   cdq 
// 007e13b9  83e207               and edx, 7
// 007e13bc  03c2                 add eax, edx
// 007e13be  c1f803               sar eax, 3
// 007e13c1  83f804               cmp eax, 4
// 007e13c4  7d07                 jge 0x7e13cd
// 007e13c6  b804000000           mov eax, 4
// 007e13cb  eb0c                 jmp 0x7e13d9
// 007e13cd  3d00040000           cmp eax, 0x400
// 007e13d2  7e05                 jle 0x7e13d9
// 007e13d4  b800040000           mov eax, 0x400
// 007e13d9  03c3                 add eax, ebx
// 007e13db  3bf8                 cmp edi, eax
// 007e13dd  7d06                 jge 0x7e13e5
// 007e13df  89442414             mov dword ptr [esp + 0x14], eax
// 007e13e3  eb06                 jmp 0x7e13eb
// 007e13e5  897c2414             mov dword ptr [esp + 0x14], edi
// 007e13e9  8bc7                 mov eax, edi
// 007e13eb  3bc3                 cmp eax, ebx
// 007e13ed  7d05                 jge 0x7e13f4
// 007e13ef  e85868fcff           call 0x7a7c4c
// 007e13f4  8d2c8500000000       lea ebp, [eax*4]
// 007e13fb  55                   push ebp
// 007e13fc  e88168fcff           call 0x7a7c82
// 007e1401  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e1404  8b5604               mov edx, dword ptr [esi + 4]
// 007e1407  03c9                 add ecx, ecx
// 007e1409  03c9                 add ecx, ecx
// 007e140b  51                   push ecx
// 007e140c  52                   push edx
// 007e140d  8bd8                 mov ebx, eax
// 007e140f  55                   push ebp
// 007e1410  53                   push ebx
// 007e1411  e8da17c2ff           call 0x402bf0
// 007e1416  8b4608               mov eax, dword ptr [esi + 8]
// 007e1419  8bcf                 mov ecx, edi
// 007e141b  2bc8                 sub ecx, eax
// 007e141d  03c9                 add ecx, ecx
// 007e141f  03c9                 add ecx, ecx
// 007e1421  51                   push ecx
// 007e1422  8d1483               lea edx, [ebx + eax*4]
// 007e1425  6a00                 push 0
// 007e1427  52                   push edx
// 007e1428  e8b777fcff           call 0x7a8be4
// 007e142d  8b4604               mov eax, dword ptr [esi + 4]
// 007e1430  50                   push eax
// 007e1431  e81068fcff           call 0x7a7c46
// 007e1436  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007e143a  83c424               add esp, 0x24
// 007e143d  895e04               mov dword ptr [esi + 4], ebx
// 007e1440  894e0c               mov dword ptr [esi + 0xc], ecx
// 007e1443  5b                   pop ebx
// 007e1444  897e08               mov dword ptr [esi + 8], edi
// 007e1447  5f                   pop edi
// 007e1448  5e                   pop esi
// 007e1449  5d                   pop ebp
// 007e144a  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetSize@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
