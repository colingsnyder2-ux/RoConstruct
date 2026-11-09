// from server: 100% by auto
// roc 2009-06 00752510  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00752510
//
// 00752510  55                   push ebp
// 00752511  56                   push esi
// 00752512  57                   push edi
// 00752513  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00752517  33ed                 xor ebp, ebp
// 00752519  3bfd                 cmp edi, ebp
// 0075251b  8bf1                 mov esi, ecx
// 0075251d  7d05                 jge 0x752524
// 0075251f  e8c067fcff           call 0x718ce4
// 00752524  8b442414             mov eax, dword ptr [esp + 0x14]
// 00752528  3bc5                 cmp eax, ebp
// 0075252a  7c03                 jl 0x75252f
// 0075252c  894610               mov dword ptr [esi + 0x10], eax
// 0075252f  3bfd                 cmp edi, ebp
// 00752531  751f                 jne 0x752552
// 00752533  8b4604               mov eax, dword ptr [esi + 4]
// 00752536  3bc5                 cmp eax, ebp
// 00752538  740c                 je 0x752546
// 0075253a  50                   push eax
// 0075253b  e89e67fcff           call 0x718cde
// 00752540  83c404               add esp, 4
// 00752543  896e04               mov dword ptr [esi + 4], ebp
// 00752546  5f                   pop edi
// 00752547  896e0c               mov dword ptr [esi + 0xc], ebp
// 0075254a  896e08               mov dword ptr [esi + 8], ebp
// 0075254d  5e                   pop esi
// 0075254e  5d                   pop ebp
// 0075254f  c20800               ret 8
// 00752552  8b4e04               mov ecx, dword ptr [esi + 4]
// 00752555  53                   push ebx
// 00752556  3bcd                 cmp ecx, ebp
// 00752558  7532                 jne 0x75258c
// 0075255a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0075255d  3bfd                 cmp edi, ebp
// 0075255f  7e02                 jle 0x752563
// 00752561  8bef                 mov ebp, edi
// 00752563  8d1cad00000000       lea ebx, [ebp*4]
// 0075256a  53                   push ebx
// 0075256b  e8aa67fcff           call 0x718d1a
// 00752570  53                   push ebx
// 00752571  6a00                 push 0
// 00752573  50                   push eax
// 00752574  894604               mov dword ptr [esi + 4], eax
// 00752577  e8f876fcff           call 0x719c74
// 0075257c  83c410               add esp, 0x10
// 0075257f  5b                   pop ebx
// 00752580  897e08               mov dword ptr [esi + 8], edi
// 00752583  5f                   pop edi
// 00752584  896e0c               mov dword ptr [esi + 0xc], ebp
// 00752587  5e                   pop esi
// 00752588  5d                   pop ebp
// 00752589  c20800               ret 8
// 0075258c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0075258f  3bfb                 cmp edi, ebx
// 00752591  7f2b                 jg 0x7525be
// 00752593  8b4608               mov eax, dword ptr [esi + 8]
// 00752596  3bf8                 cmp edi, eax
// 00752598  0f8eb5000000         jle 0x752653
// 0075259e  8bd7                 mov edx, edi
// 007525a0  2bd0                 sub edx, eax
// 007525a2  03d2                 add edx, edx
// 007525a4  03d2                 add edx, edx
// 007525a6  52                   push edx
// 007525a7  8d0481               lea eax, [ecx + eax*4]
// 007525aa  55                   push ebp
// 007525ab  50                   push eax
// 007525ac  e8c376fcff           call 0x719c74
// 007525b1  83c40c               add esp, 0xc
// 007525b4  5b                   pop ebx
// 007525b5  897e08               mov dword ptr [esi + 8], edi
// 007525b8  5f                   pop edi
// 007525b9  5e                   pop esi
// 007525ba  5d                   pop ebp
// 007525bb  c20800               ret 8
// 007525be  8b4610               mov eax, dword ptr [esi + 0x10]
// 007525c1  3bc5                 cmp eax, ebp
// 007525c3  7524                 jne 0x7525e9
// 007525c5  8b4608               mov eax, dword ptr [esi + 8]
// 007525c8  99                   cdq 
// 007525c9  83e207               and edx, 7
// 007525cc  03c2                 add eax, edx
// 007525ce  c1f803               sar eax, 3
// 007525d1  83f804               cmp eax, 4
// 007525d4  7d07                 jge 0x7525dd
// 007525d6  b804000000           mov eax, 4
// 007525db  eb0c                 jmp 0x7525e9
// 007525dd  3d00040000           cmp eax, 0x400
// 007525e2  7e05                 jle 0x7525e9
// 007525e4  b800040000           mov eax, 0x400
// 007525e9  03c3                 add eax, ebx
// 007525eb  3bf8                 cmp edi, eax
// 007525ed  7d06                 jge 0x7525f5
// 007525ef  89442414             mov dword ptr [esp + 0x14], eax
// 007525f3  eb06                 jmp 0x7525fb
// 007525f5  897c2414             mov dword ptr [esp + 0x14], edi
// 007525f9  8bc7                 mov eax, edi
// 007525fb  3bc3                 cmp eax, ebx
// 007525fd  7d05                 jge 0x752604
// 007525ff  e8e066fcff           call 0x718ce4
// 00752604  8d2c8500000000       lea ebp, [eax*4]
// 0075260b  55                   push ebp
// 0075260c  e80967fcff           call 0x718d1a
// 00752611  8b4e08               mov ecx, dword ptr [esi + 8]
// 00752614  8b5604               mov edx, dword ptr [esi + 4]
// 00752617  03c9                 add ecx, ecx
// 00752619  03c9                 add ecx, ecx
// 0075261b  51                   push ecx
// 0075261c  52                   push edx
// 0075261d  8bd8                 mov ebx, eax
// 0075261f  55                   push ebp
// 00752620  53                   push ebx
// 00752621  e8aa08cbff           call 0x402ed0
// 00752626  8b4608               mov eax, dword ptr [esi + 8]
// 00752629  8bcf                 mov ecx, edi
// 0075262b  2bc8                 sub ecx, eax
// 0075262d  03c9                 add ecx, ecx
// 0075262f  03c9                 add ecx, ecx
// 00752631  51                   push ecx
// 00752632  8d1483               lea edx, [ebx + eax*4]
// 00752635  6a00                 push 0
// 00752637  52                   push edx
// 00752638  e83776fcff           call 0x719c74
// 0075263d  8b4604               mov eax, dword ptr [esi + 4]
// 00752640  50                   push eax
// 00752641  e89866fcff           call 0x718cde
// 00752646  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0075264a  83c424               add esp, 0x24
// 0075264d  895e04               mov dword ptr [esi + 4], ebx
// 00752650  894e0c               mov dword ptr [esi + 0xc], ecx
// 00752653  5b                   pop ebx
// 00752654  897e08               mov dword ptr [esi + 8], edi
// 00752657  5f                   pop edi
// 00752658  5e                   pop esi
// 00752659  5d                   pop ebp
// 0075265a  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetSize@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
