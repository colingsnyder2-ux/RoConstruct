// from server: 100% by auto
// roc 2007-03 0045b220  unit: seg_00450000  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045b220
//
// 0045b220  55                   push ebp
// 0045b221  56                   push esi
// 0045b222  57                   push edi
// 0045b223  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0045b227  33ed                 xor ebp, ebp
// 0045b229  3bfd                 cmp edi, ebp
// 0045b22b  8bf1                 mov esi, ecx
// 0045b22d  7d05                 jge 0x45b234
// 0045b22f  e87a311c00           call 0x61e3ae
// 0045b234  8b442414             mov eax, dword ptr [esp + 0x14]
// 0045b238  3bc5                 cmp eax, ebp
// 0045b23a  7c03                 jl 0x45b23f
// 0045b23c  894610               mov dword ptr [esi + 0x10], eax
// 0045b23f  3bfd                 cmp edi, ebp
// 0045b241  751f                 jne 0x45b262
// 0045b243  8b4604               mov eax, dword ptr [esi + 4]
// 0045b246  3bc5                 cmp eax, ebp
// 0045b248  740c                 je 0x45b256
// 0045b24a  50                   push eax
// 0045b24b  e864311c00           call 0x61e3b4
// 0045b250  83c404               add esp, 4
// 0045b253  896e04               mov dword ptr [esi + 4], ebp
// 0045b256  5f                   pop edi
// 0045b257  896e0c               mov dword ptr [esi + 0xc], ebp
// 0045b25a  896e08               mov dword ptr [esi + 8], ebp
// 0045b25d  5e                   pop esi
// 0045b25e  5d                   pop ebp
// 0045b25f  c20800               ret 8
// 0045b262  8b4e04               mov ecx, dword ptr [esi + 4]
// 0045b265  3bcd                 cmp ecx, ebp
// 0045b267  53                   push ebx
// 0045b268  7532                 jne 0x45b29c
// 0045b26a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0045b26d  3bfd                 cmp edi, ebp
// 0045b26f  7e02                 jle 0x45b273
// 0045b271  8bef                 mov ebp, edi
// 0045b273  8d1cad00000000       lea ebx, [ebp*4]
// 0045b27a  53                   push ebx
// 0045b27b  e840311c00           call 0x61e3c0
// 0045b280  53                   push ebx
// 0045b281  6a00                 push 0
// 0045b283  50                   push eax
// 0045b284  894604               mov dword ptr [esi + 4], eax
// 0045b287  e8903d1c00           call 0x61f01c
// 0045b28c  83c410               add esp, 0x10
// 0045b28f  5b                   pop ebx
// 0045b290  897e08               mov dword ptr [esi + 8], edi
// 0045b293  5f                   pop edi
// 0045b294  896e0c               mov dword ptr [esi + 0xc], ebp
// 0045b297  5e                   pop esi
// 0045b298  5d                   pop ebp
// 0045b299  c20800               ret 8
// 0045b29c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0045b29f  3bfb                 cmp edi, ebx
// 0045b2a1  7f2b                 jg 0x45b2ce
// 0045b2a3  8b4608               mov eax, dword ptr [esi + 8]
// 0045b2a6  3bf8                 cmp edi, eax
// 0045b2a8  0f8eb5000000         jle 0x45b363
// 0045b2ae  8bd7                 mov edx, edi
// 0045b2b0  2bd0                 sub edx, eax
// 0045b2b2  03d2                 add edx, edx
// 0045b2b4  03d2                 add edx, edx
// 0045b2b6  52                   push edx
// 0045b2b7  8d0481               lea eax, [ecx + eax*4]
// 0045b2ba  55                   push ebp
// 0045b2bb  50                   push eax
// 0045b2bc  e85b3d1c00           call 0x61f01c
// 0045b2c1  83c40c               add esp, 0xc
// 0045b2c4  5b                   pop ebx
// 0045b2c5  897e08               mov dword ptr [esi + 8], edi
// 0045b2c8  5f                   pop edi
// 0045b2c9  5e                   pop esi
// 0045b2ca  5d                   pop ebp
// 0045b2cb  c20800               ret 8
// 0045b2ce  8b4610               mov eax, dword ptr [esi + 0x10]
// 0045b2d1  3bc5                 cmp eax, ebp
// 0045b2d3  7524                 jne 0x45b2f9
// 0045b2d5  8b4608               mov eax, dword ptr [esi + 8]
// 0045b2d8  99                   cdq 
// 0045b2d9  83e207               and edx, 7
// 0045b2dc  03c2                 add eax, edx
// 0045b2de  c1f803               sar eax, 3
// 0045b2e1  83f804               cmp eax, 4
// 0045b2e4  7d07                 jge 0x45b2ed
// 0045b2e6  b804000000           mov eax, 4
// 0045b2eb  eb0c                 jmp 0x45b2f9
// 0045b2ed  3d00040000           cmp eax, 0x400
// 0045b2f2  7e05                 jle 0x45b2f9
// 0045b2f4  b800040000           mov eax, 0x400
// 0045b2f9  03c3                 add eax, ebx
// 0045b2fb  3bf8                 cmp edi, eax
// 0045b2fd  7d06                 jge 0x45b305
// 0045b2ff  89442414             mov dword ptr [esp + 0x14], eax
// 0045b303  eb06                 jmp 0x45b30b
// 0045b305  897c2414             mov dword ptr [esp + 0x14], edi
// 0045b309  8bc7                 mov eax, edi
// 0045b30b  3bc3                 cmp eax, ebx
// 0045b30d  7d05                 jge 0x45b314
// 0045b30f  e89a301c00           call 0x61e3ae
// 0045b314  8d2c8500000000       lea ebp, [eax*4]
// 0045b31b  55                   push ebp
// 0045b31c  e89f301c00           call 0x61e3c0
// 0045b321  8b4e08               mov ecx, dword ptr [esi + 8]
// 0045b324  8b5604               mov edx, dword ptr [esi + 4]
// 0045b327  03c9                 add ecx, ecx
// 0045b329  03c9                 add ecx, ecx
// 0045b32b  51                   push ecx
// 0045b32c  52                   push edx
// 0045b32d  8bd8                 mov ebx, eax
// 0045b32f  55                   push ebp
// 0045b330  53                   push ebx
// 0045b331  e85a65faff           call 0x401890
// 0045b336  8b4608               mov eax, dword ptr [esi + 8]
// 0045b339  8bcf                 mov ecx, edi
// 0045b33b  2bc8                 sub ecx, eax
// 0045b33d  03c9                 add ecx, ecx
// 0045b33f  03c9                 add ecx, ecx
// 0045b341  51                   push ecx
// 0045b342  8d1483               lea edx, [ebx + eax*4]
// 0045b345  6a00                 push 0
// 0045b347  52                   push edx
// 0045b348  e8cf3c1c00           call 0x61f01c
// 0045b34d  8b4604               mov eax, dword ptr [esi + 4]
// 0045b350  50                   push eax
// 0045b351  e85e301c00           call 0x61e3b4
// 0045b356  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0045b35a  83c424               add esp, 0x24
// 0045b35d  895e04               mov dword ptr [esi + 4], ebx
// 0045b360  894e0c               mov dword ptr [esi + 0xc], ecx
// 0045b363  5b                   pop ebx
// 0045b364  897e08               mov dword ptr [esi + 8], edi
// 0045b367  5f                   pop edi
// 0045b368  5e                   pop esi
// 0045b369  5d                   pop ebp
// 0045b36a  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?SetSize@?$CArray@HABH@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
