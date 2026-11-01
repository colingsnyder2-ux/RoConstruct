// from server: 100% by auto
// roc 2009-06 007bd240  unit: CXTPRibbonBar  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd240
//
// 007bd240  53                   push ebx
// 007bd241  56                   push esi
// 007bd242  57                   push edi
// 007bd243  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007bd247  33db                 xor ebx, ebx
// 007bd249  3bfb                 cmp edi, ebx
// 007bd24b  8bf1                 mov esi, ecx
// 007bd24d  7d05                 jge 0x7bd254
// 007bd24f  e890baf5ff           call 0x718ce4
// 007bd254  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bd258  3bc3                 cmp eax, ebx
// 007bd25a  7c03                 jl 0x7bd25f
// 007bd25c  894610               mov dword ptr [esi + 0x10], eax
// 007bd25f  3bfb                 cmp edi, ebx
// 007bd261  751f                 jne 0x7bd282
// 007bd263  8b4604               mov eax, dword ptr [esi + 4]
// 007bd266  3bc3                 cmp eax, ebx
// 007bd268  740c                 je 0x7bd276
// 007bd26a  50                   push eax
// 007bd26b  e86ebaf5ff           call 0x718cde
// 007bd270  83c404               add esp, 4
// 007bd273  895e04               mov dword ptr [esi + 4], ebx
// 007bd276  5f                   pop edi
// 007bd277  895e0c               mov dword ptr [esi + 0xc], ebx
// 007bd27a  895e08               mov dword ptr [esi + 8], ebx
// 007bd27d  5e                   pop esi
// 007bd27e  5b                   pop ebx
// 007bd27f  c20800               ret 8
// 007bd282  8b4e04               mov ecx, dword ptr [esi + 4]
// 007bd285  55                   push ebp
// 007bd286  3bcb                 cmp ecx, ebx
// 007bd288  7530                 jne 0x7bd2ba
// 007bd28a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007bd28d  3bfd                 cmp edi, ebp
// 007bd28f  7e02                 jle 0x7bd293
// 007bd291  8bef                 mov ebp, edi
// 007bd293  8bdd                 mov ebx, ebp
// 007bd295  c1e304               shl ebx, 4
// 007bd298  53                   push ebx
// 007bd299  e87cbaf5ff           call 0x718d1a
// 007bd29e  53                   push ebx
// 007bd29f  6a00                 push 0
// 007bd2a1  50                   push eax
// 007bd2a2  894604               mov dword ptr [esi + 4], eax
// 007bd2a5  e8cac9f5ff           call 0x719c74
// 007bd2aa  83c410               add esp, 0x10
// 007bd2ad  896e0c               mov dword ptr [esi + 0xc], ebp
// 007bd2b0  5d                   pop ebp
// 007bd2b1  897e08               mov dword ptr [esi + 8], edi
// 007bd2b4  5f                   pop edi
// 007bd2b5  5e                   pop esi
// 007bd2b6  5b                   pop ebx
// 007bd2b7  c20800               ret 8
// 007bd2ba  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007bd2bd  3bfd                 cmp edi, ebp
// 007bd2bf  7f2c                 jg 0x7bd2ed
// 007bd2c1  8b4608               mov eax, dword ptr [esi + 8]
// 007bd2c4  3bf8                 cmp edi, eax
// 007bd2c6  0f8eb3000000         jle 0x7bd37f
// 007bd2cc  8bd7                 mov edx, edi
// 007bd2ce  2bd0                 sub edx, eax
// 007bd2d0  c1e204               shl edx, 4
// 007bd2d3  52                   push edx
// 007bd2d4  c1e004               shl eax, 4
// 007bd2d7  03c1                 add eax, ecx
// 007bd2d9  53                   push ebx
// 007bd2da  50                   push eax
// 007bd2db  e894c9f5ff           call 0x719c74
// 007bd2e0  83c40c               add esp, 0xc
// 007bd2e3  5d                   pop ebp
// 007bd2e4  897e08               mov dword ptr [esi + 8], edi
// 007bd2e7  5f                   pop edi
// 007bd2e8  5e                   pop esi
// 007bd2e9  5b                   pop ebx
// 007bd2ea  c20800               ret 8
// 007bd2ed  8b4610               mov eax, dword ptr [esi + 0x10]
// 007bd2f0  3bc3                 cmp eax, ebx
// 007bd2f2  7524                 jne 0x7bd318
// 007bd2f4  8b4608               mov eax, dword ptr [esi + 8]
// 007bd2f7  99                   cdq 
// 007bd2f8  83e207               and edx, 7
// 007bd2fb  03c2                 add eax, edx
// 007bd2fd  c1f803               sar eax, 3
// 007bd300  83f804               cmp eax, 4
// 007bd303  7d07                 jge 0x7bd30c
// 007bd305  b804000000           mov eax, 4
// 007bd30a  eb0c                 jmp 0x7bd318
// 007bd30c  3d00040000           cmp eax, 0x400
// 007bd311  7e05                 jle 0x7bd318
// 007bd313  b800040000           mov eax, 0x400
// 007bd318  8d1c28               lea ebx, [eax + ebp]
// 007bd31b  3bfb                 cmp edi, ebx
// 007bd31d  7d06                 jge 0x7bd325
// 007bd31f  895c2414             mov dword ptr [esp + 0x14], ebx
// 007bd323  eb06                 jmp 0x7bd32b
// 007bd325  897c2414             mov dword ptr [esp + 0x14], edi
// 007bd329  8bdf                 mov ebx, edi
// 007bd32b  3bdd                 cmp ebx, ebp
// 007bd32d  7d05                 jge 0x7bd334
// 007bd32f  e8b0b9f5ff           call 0x718ce4
// 007bd334  c1e304               shl ebx, 4
// 007bd337  53                   push ebx
// 007bd338  e8ddb9f5ff           call 0x718d1a
// 007bd33d  8b4e04               mov ecx, dword ptr [esi + 4]
// 007bd340  8be8                 mov ebp, eax
// 007bd342  8b4608               mov eax, dword ptr [esi + 8]
// 007bd345  c1e004               shl eax, 4
// 007bd348  50                   push eax
// 007bd349  51                   push ecx
// 007bd34a  53                   push ebx
// 007bd34b  55                   push ebp
// 007bd34c  e87f5bc4ff           call 0x402ed0
// 007bd351  8b4608               mov eax, dword ptr [esi + 8]
// 007bd354  8bd7                 mov edx, edi
// 007bd356  2bd0                 sub edx, eax
// 007bd358  c1e204               shl edx, 4
// 007bd35b  52                   push edx
// 007bd35c  c1e004               shl eax, 4
// 007bd35f  03c5                 add eax, ebp
// 007bd361  6a00                 push 0
// 007bd363  50                   push eax
// 007bd364  e80bc9f5ff           call 0x719c74
// 007bd369  8b4604               mov eax, dword ptr [esi + 4]
// 007bd36c  50                   push eax
// 007bd36d  e86cb9f5ff           call 0x718cde
// 007bd372  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007bd376  83c424               add esp, 0x24
// 007bd379  896e04               mov dword ptr [esi + 4], ebp
// 007bd37c  894e0c               mov dword ptr [esi + 0xc], ecx
// 007bd37f  5d                   pop ebp
// 007bd380  897e08               mov dword ptr [esi + 8], edi
// 007bd383  5f                   pop edi
// 007bd384  5e                   pop esi
// 007bd385  5b                   pop ebx
// 007bd386  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetSize@?$CArray@UtagRECT@@AAU1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
