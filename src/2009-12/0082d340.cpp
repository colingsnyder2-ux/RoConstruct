// from server: 100% by auto
// roc 2009-12 0082d340  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082d340
//
// 0082d340  55                   push ebp
// 0082d341  56                   push esi
// 0082d342  57                   push edi
// 0082d343  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0082d347  33ed                 xor ebp, ebp
// 0082d349  3bfd                 cmp edi, ebp
// 0082d34b  8bf1                 mov esi, ecx
// 0082d34d  7d05                 jge 0x82d354
// 0082d34f  e8b867fcff           call 0x7f3b0c
// 0082d354  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082d358  3bc5                 cmp eax, ebp
// 0082d35a  7c03                 jl 0x82d35f
// 0082d35c  894610               mov dword ptr [esi + 0x10], eax
// 0082d35f  3bfd                 cmp edi, ebp
// 0082d361  751f                 jne 0x82d382
// 0082d363  8b4604               mov eax, dword ptr [esi + 4]
// 0082d366  3bc5                 cmp eax, ebp
// 0082d368  740c                 je 0x82d376
// 0082d36a  50                   push eax
// 0082d36b  e89667fcff           call 0x7f3b06
// 0082d370  83c404               add esp, 4
// 0082d373  896e04               mov dword ptr [esi + 4], ebp
// 0082d376  5f                   pop edi
// 0082d377  896e0c               mov dword ptr [esi + 0xc], ebp
// 0082d37a  896e08               mov dword ptr [esi + 8], ebp
// 0082d37d  5e                   pop esi
// 0082d37e  5d                   pop ebp
// 0082d37f  c20800               ret 8
// 0082d382  8b4e04               mov ecx, dword ptr [esi + 4]
// 0082d385  53                   push ebx
// 0082d386  3bcd                 cmp ecx, ebp
// 0082d388  7532                 jne 0x82d3bc
// 0082d38a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0082d38d  3bfd                 cmp edi, ebp
// 0082d38f  7e02                 jle 0x82d393
// 0082d391  8bef                 mov ebp, edi
// 0082d393  8d1ced00000000       lea ebx, [ebp*8]
// 0082d39a  53                   push ebx
// 0082d39b  e8a267fcff           call 0x7f3b42
// 0082d3a0  53                   push ebx
// 0082d3a1  6a00                 push 0
// 0082d3a3  50                   push eax
// 0082d3a4  894604               mov dword ptr [esi + 4], eax
// 0082d3a7  e8f876fcff           call 0x7f4aa4
// 0082d3ac  83c410               add esp, 0x10
// 0082d3af  5b                   pop ebx
// 0082d3b0  897e08               mov dword ptr [esi + 8], edi
// 0082d3b3  5f                   pop edi
// 0082d3b4  896e0c               mov dword ptr [esi + 0xc], ebp
// 0082d3b7  5e                   pop esi
// 0082d3b8  5d                   pop ebp
// 0082d3b9  c20800               ret 8
// 0082d3bc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0082d3bf  3bfb                 cmp edi, ebx
// 0082d3c1  7f2d                 jg 0x82d3f0
// 0082d3c3  8b4608               mov eax, dword ptr [esi + 8]
// 0082d3c6  3bf8                 cmp edi, eax
// 0082d3c8  0f8ebb000000         jle 0x82d489
// 0082d3ce  8bd7                 mov edx, edi
// 0082d3d0  2bd0                 sub edx, eax
// 0082d3d2  03d2                 add edx, edx
// 0082d3d4  03d2                 add edx, edx
// 0082d3d6  03d2                 add edx, edx
// 0082d3d8  52                   push edx
// 0082d3d9  8d04c1               lea eax, [ecx + eax*8]
// 0082d3dc  55                   push ebp
// 0082d3dd  50                   push eax
// 0082d3de  e8c176fcff           call 0x7f4aa4
// 0082d3e3  83c40c               add esp, 0xc
// 0082d3e6  5b                   pop ebx
// 0082d3e7  897e08               mov dword ptr [esi + 8], edi
// 0082d3ea  5f                   pop edi
// 0082d3eb  5e                   pop esi
// 0082d3ec  5d                   pop ebp
// 0082d3ed  c20800               ret 8
// 0082d3f0  8b4610               mov eax, dword ptr [esi + 0x10]
// 0082d3f3  3bc5                 cmp eax, ebp
// 0082d3f5  7524                 jne 0x82d41b
// 0082d3f7  8b4608               mov eax, dword ptr [esi + 8]
// 0082d3fa  99                   cdq 
// 0082d3fb  83e207               and edx, 7
// 0082d3fe  03c2                 add eax, edx
// 0082d400  c1f803               sar eax, 3
// 0082d403  83f804               cmp eax, 4
// 0082d406  7d07                 jge 0x82d40f
// 0082d408  b804000000           mov eax, 4
// 0082d40d  eb0c                 jmp 0x82d41b
// 0082d40f  3d00040000           cmp eax, 0x400
// 0082d414  7e05                 jle 0x82d41b
// 0082d416  b800040000           mov eax, 0x400
// 0082d41b  03c3                 add eax, ebx
// 0082d41d  3bf8                 cmp edi, eax
// 0082d41f  7d06                 jge 0x82d427
// 0082d421  89442414             mov dword ptr [esp + 0x14], eax
// 0082d425  eb06                 jmp 0x82d42d
// 0082d427  897c2414             mov dword ptr [esp + 0x14], edi
// 0082d42b  8bc7                 mov eax, edi
// 0082d42d  3bc3                 cmp eax, ebx
// 0082d42f  7d05                 jge 0x82d436
// 0082d431  e8d666fcff           call 0x7f3b0c
// 0082d436  8d2cc500000000       lea ebp, [eax*8]
// 0082d43d  55                   push ebp
// 0082d43e  e8ff66fcff           call 0x7f3b42
// 0082d443  8b4e08               mov ecx, dword ptr [esi + 8]
// 0082d446  8b5604               mov edx, dword ptr [esi + 4]
// 0082d449  03c9                 add ecx, ecx
// 0082d44b  03c9                 add ecx, ecx
// 0082d44d  03c9                 add ecx, ecx
// 0082d44f  51                   push ecx
// 0082d450  52                   push edx
// 0082d451  8bd8                 mov ebx, eax
// 0082d453  55                   push ebp
// 0082d454  53                   push ebx
// 0082d455  e84657bdff           call 0x402ba0
// 0082d45a  8b4608               mov eax, dword ptr [esi + 8]
// 0082d45d  8bcf                 mov ecx, edi
// 0082d45f  2bc8                 sub ecx, eax
// 0082d461  03c9                 add ecx, ecx
// 0082d463  03c9                 add ecx, ecx
// 0082d465  03c9                 add ecx, ecx
// 0082d467  51                   push ecx
// 0082d468  8d14c3               lea edx, [ebx + eax*8]
// 0082d46b  6a00                 push 0
// 0082d46d  52                   push edx
// 0082d46e  e83176fcff           call 0x7f4aa4
// 0082d473  8b4604               mov eax, dword ptr [esi + 4]
// 0082d476  50                   push eax
// 0082d477  e88a66fcff           call 0x7f3b06
// 0082d47c  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0082d480  83c424               add esp, 0x24
// 0082d483  895e04               mov dword ptr [esi + 4], ebx
// 0082d486  894e0c               mov dword ptr [esi + 0xc], ecx
// 0082d489  5b                   pop ebx
// 0082d48a  897e08               mov dword ptr [esi + 8], edi
// 0082d48d  5f                   pop edi
// 0082d48e  5e                   pop esi
// 0082d48f  5d                   pop ebp
// 0082d490  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ?SetSize@?$CArray@VCSize@@V1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
