// from server: 100% by auto
// roc 2011-06 008bd710  unit: CXTPDockingPaneWindowSelect  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bd710
//
// 008bd710  55                   push ebp
// 008bd711  56                   push esi
// 008bd712  57                   push edi
// 008bd713  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008bd717  33ed                 xor ebp, ebp
// 008bd719  3bfd                 cmp edi, ebp
// 008bd71b  8bf1                 mov esi, ecx
// 008bd71d  7d05                 jge 0x8bd724
// 008bd71f  e8e6cbf4ff           call 0x80a30a
// 008bd724  8b442414             mov eax, dword ptr [esp + 0x14]
// 008bd728  3bc5                 cmp eax, ebp
// 008bd72a  7c03                 jl 0x8bd72f
// 008bd72c  894610               mov dword ptr [esi + 0x10], eax
// 008bd72f  3bfd                 cmp edi, ebp
// 008bd731  751f                 jne 0x8bd752
// 008bd733  8b4604               mov eax, dword ptr [esi + 4]
// 008bd736  3bc5                 cmp eax, ebp
// 008bd738  740c                 je 0x8bd746
// 008bd73a  50                   push eax
// 008bd73b  e8c4cbf4ff           call 0x80a304
// 008bd740  83c404               add esp, 4
// 008bd743  896e04               mov dword ptr [esi + 4], ebp
// 008bd746  5f                   pop edi
// 008bd747  896e0c               mov dword ptr [esi + 0xc], ebp
// 008bd74a  896e08               mov dword ptr [esi + 8], ebp
// 008bd74d  5e                   pop esi
// 008bd74e  5d                   pop ebp
// 008bd74f  c20800               ret 8
// 008bd752  8b4e04               mov ecx, dword ptr [esi + 4]
// 008bd755  53                   push ebx
// 008bd756  3bcd                 cmp ecx, ebp
// 008bd758  7532                 jne 0x8bd78c
// 008bd75a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 008bd75d  3bfd                 cmp edi, ebp
// 008bd75f  7e02                 jle 0x8bd763
// 008bd761  8bef                 mov ebp, edi
// 008bd763  8d1ced00000000       lea ebx, [ebp*8]
// 008bd76a  53                   push ebx
// 008bd76b  e8d0cbf4ff           call 0x80a340
// 008bd770  53                   push ebx
// 008bd771  6a00                 push 0
// 008bd773  50                   push eax
// 008bd774  894604               mov dword ptr [esi + 4], eax
// 008bd777  e868dbf4ff           call 0x80b2e4
// 008bd77c  83c410               add esp, 0x10
// 008bd77f  5b                   pop ebx
// 008bd780  897e08               mov dword ptr [esi + 8], edi
// 008bd783  5f                   pop edi
// 008bd784  896e0c               mov dword ptr [esi + 0xc], ebp
// 008bd787  5e                   pop esi
// 008bd788  5d                   pop ebp
// 008bd789  c20800               ret 8
// 008bd78c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 008bd78f  3bfb                 cmp edi, ebx
// 008bd791  7f2d                 jg 0x8bd7c0
// 008bd793  8b4608               mov eax, dword ptr [esi + 8]
// 008bd796  3bf8                 cmp edi, eax
// 008bd798  0f8ebb000000         jle 0x8bd859
// 008bd79e  8bd7                 mov edx, edi
// 008bd7a0  2bd0                 sub edx, eax
// 008bd7a2  03d2                 add edx, edx
// 008bd7a4  03d2                 add edx, edx
// 008bd7a6  03d2                 add edx, edx
// 008bd7a8  52                   push edx
// 008bd7a9  8d04c1               lea eax, [ecx + eax*8]
// 008bd7ac  55                   push ebp
// 008bd7ad  50                   push eax
// 008bd7ae  e831dbf4ff           call 0x80b2e4
// 008bd7b3  83c40c               add esp, 0xc
// 008bd7b6  5b                   pop ebx
// 008bd7b7  897e08               mov dword ptr [esi + 8], edi
// 008bd7ba  5f                   pop edi
// 008bd7bb  5e                   pop esi
// 008bd7bc  5d                   pop ebp
// 008bd7bd  c20800               ret 8
// 008bd7c0  8b4610               mov eax, dword ptr [esi + 0x10]
// 008bd7c3  3bc5                 cmp eax, ebp
// 008bd7c5  7524                 jne 0x8bd7eb
// 008bd7c7  8b4608               mov eax, dword ptr [esi + 8]
// 008bd7ca  99                   cdq 
// 008bd7cb  83e207               and edx, 7
// 008bd7ce  03c2                 add eax, edx
// 008bd7d0  c1f803               sar eax, 3
// 008bd7d3  83f804               cmp eax, 4
// 008bd7d6  7d07                 jge 0x8bd7df
// 008bd7d8  b804000000           mov eax, 4
// 008bd7dd  eb0c                 jmp 0x8bd7eb
// 008bd7df  3d00040000           cmp eax, 0x400
// 008bd7e4  7e05                 jle 0x8bd7eb
// 008bd7e6  b800040000           mov eax, 0x400
// 008bd7eb  03c3                 add eax, ebx
// 008bd7ed  3bf8                 cmp edi, eax
// 008bd7ef  7d06                 jge 0x8bd7f7
// 008bd7f1  89442414             mov dword ptr [esp + 0x14], eax
// 008bd7f5  eb06                 jmp 0x8bd7fd
// 008bd7f7  897c2414             mov dword ptr [esp + 0x14], edi
// 008bd7fb  8bc7                 mov eax, edi
// 008bd7fd  3bc3                 cmp eax, ebx
// 008bd7ff  7d05                 jge 0x8bd806
// 008bd801  e804cbf4ff           call 0x80a30a
// 008bd806  8d2cc500000000       lea ebp, [eax*8]
// 008bd80d  55                   push ebp
// 008bd80e  e82dcbf4ff           call 0x80a340
// 008bd813  8b4e08               mov ecx, dword ptr [esi + 8]
// 008bd816  8b5604               mov edx, dword ptr [esi + 4]
// 008bd819  03c9                 add ecx, ecx
// 008bd81b  03c9                 add ecx, ecx
// 008bd81d  03c9                 add ecx, ecx
// 008bd81f  51                   push ecx
// 008bd820  52                   push edx
// 008bd821  8bd8                 mov ebx, eax
// 008bd823  55                   push ebp
// 008bd824  53                   push ebx
// 008bd825  e8965db4ff           call 0x4035c0
// 008bd82a  8b4608               mov eax, dword ptr [esi + 8]
// 008bd82d  8bcf                 mov ecx, edi
// 008bd82f  2bc8                 sub ecx, eax
// 008bd831  03c9                 add ecx, ecx
// 008bd833  03c9                 add ecx, ecx
// 008bd835  03c9                 add ecx, ecx
// 008bd837  51                   push ecx
// 008bd838  8d14c3               lea edx, [ebx + eax*8]
// 008bd83b  6a00                 push 0
// 008bd83d  52                   push edx
// 008bd83e  e8a1daf4ff           call 0x80b2e4
// 008bd843  8b4604               mov eax, dword ptr [esi + 4]
// 008bd846  50                   push eax
// 008bd847  e8b8caf4ff           call 0x80a304
// 008bd84c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008bd850  83c424               add esp, 0x24
// 008bd853  895e04               mov dword ptr [esi + 4], ebx
// 008bd856  894e0c               mov dword ptr [esi + 0xc], ecx
// 008bd859  5b                   pop ebx
// 008bd85a  897e08               mov dword ptr [esi + 8], edi
// 008bd85d  5f                   pop edi
// 008bd85e  5e                   pop esi
// 008bd85f  5d                   pop ebp
// 008bd860  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ?SetSize@?$CArray@VCSize@@V1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
