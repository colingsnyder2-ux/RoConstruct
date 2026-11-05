// from server: 100% by auto
// roc 2009-12 008553a0  unit: PAUHWND__::?$CArray  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008553a0
//
// 008553a0  55                   push ebp
// 008553a1  56                   push esi
// 008553a2  57                   push edi
// 008553a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008553a7  33ed                 xor ebp, ebp
// 008553a9  3bfd                 cmp edi, ebp
// 008553ab  8bf1                 mov esi, ecx
// 008553ad  7d05                 jge 0x8553b4
// 008553af  e858e7f9ff           call 0x7f3b0c
// 008553b4  8b442414             mov eax, dword ptr [esp + 0x14]
// 008553b8  3bc5                 cmp eax, ebp
// 008553ba  7c03                 jl 0x8553bf
// 008553bc  894610               mov dword ptr [esi + 0x10], eax
// 008553bf  3bfd                 cmp edi, ebp
// 008553c1  751f                 jne 0x8553e2
// 008553c3  8b4604               mov eax, dword ptr [esi + 4]
// 008553c6  3bc5                 cmp eax, ebp
// 008553c8  740c                 je 0x8553d6
// 008553ca  50                   push eax
// 008553cb  e836e7f9ff           call 0x7f3b06
// 008553d0  83c404               add esp, 4
// 008553d3  896e04               mov dword ptr [esi + 4], ebp
// 008553d6  5f                   pop edi
// 008553d7  896e0c               mov dword ptr [esi + 0xc], ebp
// 008553da  896e08               mov dword ptr [esi + 8], ebp
// 008553dd  5e                   pop esi
// 008553de  5d                   pop ebp
// 008553df  c20800               ret 8
// 008553e2  8b4e04               mov ecx, dword ptr [esi + 4]
// 008553e5  53                   push ebx
// 008553e6  3bcd                 cmp ecx, ebp
// 008553e8  7532                 jne 0x85541c
// 008553ea  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 008553ed  3bfd                 cmp edi, ebp
// 008553ef  7e02                 jle 0x8553f3
// 008553f1  8bef                 mov ebp, edi
// 008553f3  8d1cad00000000       lea ebx, [ebp*4]
// 008553fa  53                   push ebx
// 008553fb  e842e7f9ff           call 0x7f3b42
// 00855400  53                   push ebx
// 00855401  6a00                 push 0
// 00855403  50                   push eax
// 00855404  894604               mov dword ptr [esi + 4], eax
// 00855407  e898f6f9ff           call 0x7f4aa4
// 0085540c  83c410               add esp, 0x10
// 0085540f  5b                   pop ebx
// 00855410  897e08               mov dword ptr [esi + 8], edi
// 00855413  5f                   pop edi
// 00855414  896e0c               mov dword ptr [esi + 0xc], ebp
// 00855417  5e                   pop esi
// 00855418  5d                   pop ebp
// 00855419  c20800               ret 8
// 0085541c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0085541f  3bfb                 cmp edi, ebx
// 00855421  7f2b                 jg 0x85544e
// 00855423  8b4608               mov eax, dword ptr [esi + 8]
// 00855426  3bf8                 cmp edi, eax
// 00855428  0f8eb5000000         jle 0x8554e3
// 0085542e  8bd7                 mov edx, edi
// 00855430  2bd0                 sub edx, eax
// 00855432  03d2                 add edx, edx
// 00855434  03d2                 add edx, edx
// 00855436  52                   push edx
// 00855437  8d0481               lea eax, [ecx + eax*4]
// 0085543a  55                   push ebp
// 0085543b  50                   push eax
// 0085543c  e863f6f9ff           call 0x7f4aa4
// 00855441  83c40c               add esp, 0xc
// 00855444  5b                   pop ebx
// 00855445  897e08               mov dword ptr [esi + 8], edi
// 00855448  5f                   pop edi
// 00855449  5e                   pop esi
// 0085544a  5d                   pop ebp
// 0085544b  c20800               ret 8
// 0085544e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00855451  3bc5                 cmp eax, ebp
// 00855453  7524                 jne 0x855479
// 00855455  8b4608               mov eax, dword ptr [esi + 8]
// 00855458  99                   cdq 
// 00855459  83e207               and edx, 7
// 0085545c  03c2                 add eax, edx
// 0085545e  c1f803               sar eax, 3
// 00855461  83f804               cmp eax, 4
// 00855464  7d07                 jge 0x85546d
// 00855466  b804000000           mov eax, 4
// 0085546b  eb0c                 jmp 0x855479
// 0085546d  3d00040000           cmp eax, 0x400
// 00855472  7e05                 jle 0x855479
// 00855474  b800040000           mov eax, 0x400
// 00855479  03c3                 add eax, ebx
// 0085547b  3bf8                 cmp edi, eax
// 0085547d  7d06                 jge 0x855485
// 0085547f  89442414             mov dword ptr [esp + 0x14], eax
// 00855483  eb06                 jmp 0x85548b
// 00855485  897c2414             mov dword ptr [esp + 0x14], edi
// 00855489  8bc7                 mov eax, edi
// 0085548b  3bc3                 cmp eax, ebx
// 0085548d  7d05                 jge 0x855494
// 0085548f  e878e6f9ff           call 0x7f3b0c
// 00855494  8d2c8500000000       lea ebp, [eax*4]
// 0085549b  55                   push ebp
// 0085549c  e8a1e6f9ff           call 0x7f3b42
// 008554a1  8b4e08               mov ecx, dword ptr [esi + 8]
// 008554a4  8b5604               mov edx, dword ptr [esi + 4]
// 008554a7  03c9                 add ecx, ecx
// 008554a9  03c9                 add ecx, ecx
// 008554ab  51                   push ecx
// 008554ac  52                   push edx
// 008554ad  8bd8                 mov ebx, eax
// 008554af  55                   push ebp
// 008554b0  53                   push ebx
// 008554b1  e8ead6baff           call 0x402ba0
// 008554b6  8b4608               mov eax, dword ptr [esi + 8]
// 008554b9  8bcf                 mov ecx, edi
// 008554bb  2bc8                 sub ecx, eax
// 008554bd  03c9                 add ecx, ecx
// 008554bf  03c9                 add ecx, ecx
// 008554c1  51                   push ecx
// 008554c2  8d1483               lea edx, [ebx + eax*4]
// 008554c5  6a00                 push 0
// 008554c7  52                   push edx
// 008554c8  e8d7f5f9ff           call 0x7f4aa4
// 008554cd  8b4604               mov eax, dword ptr [esi + 4]
// 008554d0  50                   push eax
// 008554d1  e830e6f9ff           call 0x7f3b06
// 008554d6  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008554da  83c424               add esp, 0x24
// 008554dd  895e04               mov dword ptr [esi + 4], ebx
// 008554e0  894e0c               mov dword ptr [esi + 0xc], ecx
// 008554e3  5b                   pop ebx
// 008554e4  897e08               mov dword ptr [esi + 8], edi
// 008554e7  5f                   pop edi
// 008554e8  5e                   pop esi
// 008554e9  5d                   pop ebp
// 008554ea  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetSize@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
