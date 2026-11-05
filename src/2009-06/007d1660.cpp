// from server: 100% by auto
// roc 2009-06 007d1660  unit: CXTPDockingPaneWindowSelect  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d1660
//
// 007d1660  55                   push ebp
// 007d1661  56                   push esi
// 007d1662  57                   push edi
// 007d1663  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d1667  33ed                 xor ebp, ebp
// 007d1669  3bfd                 cmp edi, ebp
// 007d166b  8bf1                 mov esi, ecx
// 007d166d  7d05                 jge 0x7d1674
// 007d166f  e87076f4ff           call 0x718ce4
// 007d1674  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d1678  3bc5                 cmp eax, ebp
// 007d167a  7c03                 jl 0x7d167f
// 007d167c  894610               mov dword ptr [esi + 0x10], eax
// 007d167f  3bfd                 cmp edi, ebp
// 007d1681  751f                 jne 0x7d16a2
// 007d1683  8b4604               mov eax, dword ptr [esi + 4]
// 007d1686  3bc5                 cmp eax, ebp
// 007d1688  740c                 je 0x7d1696
// 007d168a  50                   push eax
// 007d168b  e84e76f4ff           call 0x718cde
// 007d1690  83c404               add esp, 4
// 007d1693  896e04               mov dword ptr [esi + 4], ebp
// 007d1696  5f                   pop edi
// 007d1697  896e0c               mov dword ptr [esi + 0xc], ebp
// 007d169a  896e08               mov dword ptr [esi + 8], ebp
// 007d169d  5e                   pop esi
// 007d169e  5d                   pop ebp
// 007d169f  c20800               ret 8
// 007d16a2  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d16a5  53                   push ebx
// 007d16a6  3bcd                 cmp ecx, ebp
// 007d16a8  7532                 jne 0x7d16dc
// 007d16aa  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007d16ad  3bfd                 cmp edi, ebp
// 007d16af  7e02                 jle 0x7d16b3
// 007d16b1  8bef                 mov ebp, edi
// 007d16b3  8d1ced00000000       lea ebx, [ebp*8]
// 007d16ba  53                   push ebx
// 007d16bb  e85a76f4ff           call 0x718d1a
// 007d16c0  53                   push ebx
// 007d16c1  6a00                 push 0
// 007d16c3  50                   push eax
// 007d16c4  894604               mov dword ptr [esi + 4], eax
// 007d16c7  e8a885f4ff           call 0x719c74
// 007d16cc  83c410               add esp, 0x10
// 007d16cf  5b                   pop ebx
// 007d16d0  897e08               mov dword ptr [esi + 8], edi
// 007d16d3  5f                   pop edi
// 007d16d4  896e0c               mov dword ptr [esi + 0xc], ebp
// 007d16d7  5e                   pop esi
// 007d16d8  5d                   pop ebp
// 007d16d9  c20800               ret 8
// 007d16dc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007d16df  3bfb                 cmp edi, ebx
// 007d16e1  7f2d                 jg 0x7d1710
// 007d16e3  8b4608               mov eax, dword ptr [esi + 8]
// 007d16e6  3bf8                 cmp edi, eax
// 007d16e8  0f8ebb000000         jle 0x7d17a9
// 007d16ee  8bd7                 mov edx, edi
// 007d16f0  2bd0                 sub edx, eax
// 007d16f2  03d2                 add edx, edx
// 007d16f4  03d2                 add edx, edx
// 007d16f6  03d2                 add edx, edx
// 007d16f8  52                   push edx
// 007d16f9  8d04c1               lea eax, [ecx + eax*8]
// 007d16fc  55                   push ebp
// 007d16fd  50                   push eax
// 007d16fe  e87185f4ff           call 0x719c74
// 007d1703  83c40c               add esp, 0xc
// 007d1706  5b                   pop ebx
// 007d1707  897e08               mov dword ptr [esi + 8], edi
// 007d170a  5f                   pop edi
// 007d170b  5e                   pop esi
// 007d170c  5d                   pop ebp
// 007d170d  c20800               ret 8
// 007d1710  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d1713  3bc5                 cmp eax, ebp
// 007d1715  7524                 jne 0x7d173b
// 007d1717  8b4608               mov eax, dword ptr [esi + 8]
// 007d171a  99                   cdq 
// 007d171b  83e207               and edx, 7
// 007d171e  03c2                 add eax, edx
// 007d1720  c1f803               sar eax, 3
// 007d1723  83f804               cmp eax, 4
// 007d1726  7d07                 jge 0x7d172f
// 007d1728  b804000000           mov eax, 4
// 007d172d  eb0c                 jmp 0x7d173b
// 007d172f  3d00040000           cmp eax, 0x400
// 007d1734  7e05                 jle 0x7d173b
// 007d1736  b800040000           mov eax, 0x400
// 007d173b  03c3                 add eax, ebx
// 007d173d  3bf8                 cmp edi, eax
// 007d173f  7d06                 jge 0x7d1747
// 007d1741  89442414             mov dword ptr [esp + 0x14], eax
// 007d1745  eb06                 jmp 0x7d174d
// 007d1747  897c2414             mov dword ptr [esp + 0x14], edi
// 007d174b  8bc7                 mov eax, edi
// 007d174d  3bc3                 cmp eax, ebx
// 007d174f  7d05                 jge 0x7d1756
// 007d1751  e88e75f4ff           call 0x718ce4
// 007d1756  8d2cc500000000       lea ebp, [eax*8]
// 007d175d  55                   push ebp
// 007d175e  e8b775f4ff           call 0x718d1a
// 007d1763  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d1766  8b5604               mov edx, dword ptr [esi + 4]
// 007d1769  03c9                 add ecx, ecx
// 007d176b  03c9                 add ecx, ecx
// 007d176d  03c9                 add ecx, ecx
// 007d176f  51                   push ecx
// 007d1770  52                   push edx
// 007d1771  8bd8                 mov ebx, eax
// 007d1773  55                   push ebp
// 007d1774  53                   push ebx
// 007d1775  e85617c3ff           call 0x402ed0
// 007d177a  8b4608               mov eax, dword ptr [esi + 8]
// 007d177d  8bcf                 mov ecx, edi
// 007d177f  2bc8                 sub ecx, eax
// 007d1781  03c9                 add ecx, ecx
// 007d1783  03c9                 add ecx, ecx
// 007d1785  03c9                 add ecx, ecx
// 007d1787  51                   push ecx
// 007d1788  8d14c3               lea edx, [ebx + eax*8]
// 007d178b  6a00                 push 0
// 007d178d  52                   push edx
// 007d178e  e8e184f4ff           call 0x719c74
// 007d1793  8b4604               mov eax, dword ptr [esi + 4]
// 007d1796  50                   push eax
// 007d1797  e84275f4ff           call 0x718cde
// 007d179c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007d17a0  83c424               add esp, 0x24
// 007d17a3  895e04               mov dword ptr [esi + 4], ebx
// 007d17a6  894e0c               mov dword ptr [esi + 0xc], ecx
// 007d17a9  5b                   pop ebx
// 007d17aa  897e08               mov dword ptr [esi + 8], edi
// 007d17ad  5f                   pop edi
// 007d17ae  5e                   pop esi
// 007d17af  5d                   pop ebp
// 007d17b0  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ?SetSize@?$CArray@VCSize@@V1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
