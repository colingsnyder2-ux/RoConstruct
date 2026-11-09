// from server: 100% by auto
// roc 2008-06 0070e1d0  unit: CXTPStatusBar  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e1d0
//
// 0070e1d0  55                   push ebp
// 0070e1d1  56                   push esi
// 0070e1d2  57                   push edi
// 0070e1d3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0070e1d7  33ed                 xor ebp, ebp
// 0070e1d9  3bfd                 cmp edi, ebp
// 0070e1db  8bf1                 mov esi, ecx
// 0070e1dd  7d05                 jge 0x70e1e4
// 0070e1df  e86027f9ff           call 0x6a0944
// 0070e1e4  8b442414             mov eax, dword ptr [esp + 0x14]
// 0070e1e8  3bc5                 cmp eax, ebp
// 0070e1ea  7c03                 jl 0x70e1ef
// 0070e1ec  894610               mov dword ptr [esi + 0x10], eax
// 0070e1ef  3bfd                 cmp edi, ebp
// 0070e1f1  751f                 jne 0x70e212
// 0070e1f3  8b4604               mov eax, dword ptr [esi + 4]
// 0070e1f6  3bc5                 cmp eax, ebp
// 0070e1f8  740c                 je 0x70e206
// 0070e1fa  50                   push eax
// 0070e1fb  e84a27f9ff           call 0x6a094a
// 0070e200  83c404               add esp, 4
// 0070e203  896e04               mov dword ptr [esi + 4], ebp
// 0070e206  5f                   pop edi
// 0070e207  896e0c               mov dword ptr [esi + 0xc], ebp
// 0070e20a  896e08               mov dword ptr [esi + 8], ebp
// 0070e20d  5e                   pop esi
// 0070e20e  5d                   pop ebp
// 0070e20f  c20800               ret 8
// 0070e212  8b4e04               mov ecx, dword ptr [esi + 4]
// 0070e215  53                   push ebx
// 0070e216  3bcd                 cmp ecx, ebp
// 0070e218  7532                 jne 0x70e24c
// 0070e21a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0070e21d  3bfd                 cmp edi, ebp
// 0070e21f  7e02                 jle 0x70e223
// 0070e221  8bef                 mov ebp, edi
// 0070e223  8d1cad00000000       lea ebx, [ebp*4]
// 0070e22a  53                   push ebx
// 0070e22b  e82627f9ff           call 0x6a0956
// 0070e230  53                   push ebx
// 0070e231  6a00                 push 0
// 0070e233  50                   push eax
// 0070e234  894604               mov dword ptr [esi + 4], eax
// 0070e237  e8c834f9ff           call 0x6a1704
// 0070e23c  83c410               add esp, 0x10
// 0070e23f  5b                   pop ebx
// 0070e240  897e08               mov dword ptr [esi + 8], edi
// 0070e243  5f                   pop edi
// 0070e244  896e0c               mov dword ptr [esi + 0xc], ebp
// 0070e247  5e                   pop esi
// 0070e248  5d                   pop ebp
// 0070e249  c20800               ret 8
// 0070e24c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0070e24f  3bfb                 cmp edi, ebx
// 0070e251  7f2b                 jg 0x70e27e
// 0070e253  8b4608               mov eax, dword ptr [esi + 8]
// 0070e256  3bf8                 cmp edi, eax
// 0070e258  0f8eb5000000         jle 0x70e313
// 0070e25e  8bd7                 mov edx, edi
// 0070e260  2bd0                 sub edx, eax
// 0070e262  03d2                 add edx, edx
// 0070e264  03d2                 add edx, edx
// 0070e266  52                   push edx
// 0070e267  8d0481               lea eax, [ecx + eax*4]
// 0070e26a  55                   push ebp
// 0070e26b  50                   push eax
// 0070e26c  e89334f9ff           call 0x6a1704
// 0070e271  83c40c               add esp, 0xc
// 0070e274  5b                   pop ebx
// 0070e275  897e08               mov dword ptr [esi + 8], edi
// 0070e278  5f                   pop edi
// 0070e279  5e                   pop esi
// 0070e27a  5d                   pop ebp
// 0070e27b  c20800               ret 8
// 0070e27e  8b4610               mov eax, dword ptr [esi + 0x10]
// 0070e281  3bc5                 cmp eax, ebp
// 0070e283  7524                 jne 0x70e2a9
// 0070e285  8b4608               mov eax, dword ptr [esi + 8]
// 0070e288  99                   cdq 
// 0070e289  83e207               and edx, 7
// 0070e28c  03c2                 add eax, edx
// 0070e28e  c1f803               sar eax, 3
// 0070e291  83f804               cmp eax, 4
// 0070e294  7d07                 jge 0x70e29d
// 0070e296  b804000000           mov eax, 4
// 0070e29b  eb0c                 jmp 0x70e2a9
// 0070e29d  3d00040000           cmp eax, 0x400
// 0070e2a2  7e05                 jle 0x70e2a9
// 0070e2a4  b800040000           mov eax, 0x400
// 0070e2a9  03c3                 add eax, ebx
// 0070e2ab  3bf8                 cmp edi, eax
// 0070e2ad  7d06                 jge 0x70e2b5
// 0070e2af  89442414             mov dword ptr [esp + 0x14], eax
// 0070e2b3  eb06                 jmp 0x70e2bb
// 0070e2b5  897c2414             mov dword ptr [esp + 0x14], edi
// 0070e2b9  8bc7                 mov eax, edi
// 0070e2bb  3bc3                 cmp eax, ebx
// 0070e2bd  7d05                 jge 0x70e2c4
// 0070e2bf  e88026f9ff           call 0x6a0944
// 0070e2c4  8d2c8500000000       lea ebp, [eax*4]
// 0070e2cb  55                   push ebp
// 0070e2cc  e88526f9ff           call 0x6a0956
// 0070e2d1  8b4e08               mov ecx, dword ptr [esi + 8]
// 0070e2d4  8b5604               mov edx, dword ptr [esi + 4]
// 0070e2d7  03c9                 add ecx, ecx
// 0070e2d9  03c9                 add ecx, ecx
// 0070e2db  51                   push ecx
// 0070e2dc  52                   push edx
// 0070e2dd  8bd8                 mov ebx, eax
// 0070e2df  55                   push ebp
// 0070e2e0  53                   push ebx
// 0070e2e1  e82a35cfff           call 0x401810
// 0070e2e6  8b4608               mov eax, dword ptr [esi + 8]
// 0070e2e9  8bcf                 mov ecx, edi
// 0070e2eb  2bc8                 sub ecx, eax
// 0070e2ed  03c9                 add ecx, ecx
// 0070e2ef  03c9                 add ecx, ecx
// 0070e2f1  51                   push ecx
// 0070e2f2  8d1483               lea edx, [ebx + eax*4]
// 0070e2f5  6a00                 push 0
// 0070e2f7  52                   push edx
// 0070e2f8  e80734f9ff           call 0x6a1704
// 0070e2fd  8b4604               mov eax, dword ptr [esi + 4]
// 0070e300  50                   push eax
// 0070e301  e84426f9ff           call 0x6a094a
// 0070e306  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0070e30a  83c424               add esp, 0x24
// 0070e30d  895e04               mov dword ptr [esi + 4], ebx
// 0070e310  894e0c               mov dword ptr [esi + 0xc], ecx
// 0070e313  5b                   pop ebx
// 0070e314  897e08               mov dword ptr [esi + 8], edi
// 0070e317  5f                   pop edi
// 0070e318  5e                   pop esi
// 0070e319  5d                   pop ebp
// 0070e31a  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetSize@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
