// from server: 100% by auto
// roc 2011-06 0083eb40  unit: CInstanceRecord::CNameItem  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0083eb40
//
// 0083eb40  55                   push ebp
// 0083eb41  56                   push esi
// 0083eb42  57                   push edi
// 0083eb43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0083eb47  33ed                 xor ebp, ebp
// 0083eb49  3bfd                 cmp edi, ebp
// 0083eb4b  8bf1                 mov esi, ecx
// 0083eb4d  7d05                 jge 0x83eb54
// 0083eb4f  e8b6b7fcff           call 0x80a30a
// 0083eb54  8b442414             mov eax, dword ptr [esp + 0x14]
// 0083eb58  3bc5                 cmp eax, ebp
// 0083eb5a  7c03                 jl 0x83eb5f
// 0083eb5c  894610               mov dword ptr [esi + 0x10], eax
// 0083eb5f  3bfd                 cmp edi, ebp
// 0083eb61  751f                 jne 0x83eb82
// 0083eb63  8b4604               mov eax, dword ptr [esi + 4]
// 0083eb66  3bc5                 cmp eax, ebp
// 0083eb68  740c                 je 0x83eb76
// 0083eb6a  50                   push eax
// 0083eb6b  e894b7fcff           call 0x80a304
// 0083eb70  83c404               add esp, 4
// 0083eb73  896e04               mov dword ptr [esi + 4], ebp
// 0083eb76  5f                   pop edi
// 0083eb77  896e0c               mov dword ptr [esi + 0xc], ebp
// 0083eb7a  896e08               mov dword ptr [esi + 8], ebp
// 0083eb7d  5e                   pop esi
// 0083eb7e  5d                   pop ebp
// 0083eb7f  c20800               ret 8
// 0083eb82  8b4e04               mov ecx, dword ptr [esi + 4]
// 0083eb85  53                   push ebx
// 0083eb86  3bcd                 cmp ecx, ebp
// 0083eb88  7532                 jne 0x83ebbc
// 0083eb8a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0083eb8d  3bfd                 cmp edi, ebp
// 0083eb8f  7e02                 jle 0x83eb93
// 0083eb91  8bef                 mov ebp, edi
// 0083eb93  8d1cad00000000       lea ebx, [ebp*4]
// 0083eb9a  53                   push ebx
// 0083eb9b  e8a0b7fcff           call 0x80a340
// 0083eba0  53                   push ebx
// 0083eba1  6a00                 push 0
// 0083eba3  50                   push eax
// 0083eba4  894604               mov dword ptr [esi + 4], eax
// 0083eba7  e838c7fcff           call 0x80b2e4
// 0083ebac  83c410               add esp, 0x10
// 0083ebaf  5b                   pop ebx
// 0083ebb0  897e08               mov dword ptr [esi + 8], edi
// 0083ebb3  5f                   pop edi
// 0083ebb4  896e0c               mov dword ptr [esi + 0xc], ebp
// 0083ebb7  5e                   pop esi
// 0083ebb8  5d                   pop ebp
// 0083ebb9  c20800               ret 8
// 0083ebbc  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0083ebbf  3bfb                 cmp edi, ebx
// 0083ebc1  7f2b                 jg 0x83ebee
// 0083ebc3  8b4608               mov eax, dword ptr [esi + 8]
// 0083ebc6  3bf8                 cmp edi, eax
// 0083ebc8  0f8eb5000000         jle 0x83ec83
// 0083ebce  8bd7                 mov edx, edi
// 0083ebd0  2bd0                 sub edx, eax
// 0083ebd2  03d2                 add edx, edx
// 0083ebd4  03d2                 add edx, edx
// 0083ebd6  52                   push edx
// 0083ebd7  8d0481               lea eax, [ecx + eax*4]
// 0083ebda  55                   push ebp
// 0083ebdb  50                   push eax
// 0083ebdc  e803c7fcff           call 0x80b2e4
// 0083ebe1  83c40c               add esp, 0xc
// 0083ebe4  5b                   pop ebx
// 0083ebe5  897e08               mov dword ptr [esi + 8], edi
// 0083ebe8  5f                   pop edi
// 0083ebe9  5e                   pop esi
// 0083ebea  5d                   pop ebp
// 0083ebeb  c20800               ret 8
// 0083ebee  8b4610               mov eax, dword ptr [esi + 0x10]
// 0083ebf1  3bc5                 cmp eax, ebp
// 0083ebf3  7524                 jne 0x83ec19
// 0083ebf5  8b4608               mov eax, dword ptr [esi + 8]
// 0083ebf8  99                   cdq 
// 0083ebf9  83e207               and edx, 7
// 0083ebfc  03c2                 add eax, edx
// 0083ebfe  c1f803               sar eax, 3
// 0083ec01  83f804               cmp eax, 4
// 0083ec04  7d07                 jge 0x83ec0d
// 0083ec06  b804000000           mov eax, 4
// 0083ec0b  eb0c                 jmp 0x83ec19
// 0083ec0d  3d00040000           cmp eax, 0x400
// 0083ec12  7e05                 jle 0x83ec19
// 0083ec14  b800040000           mov eax, 0x400
// 0083ec19  03c3                 add eax, ebx
// 0083ec1b  3bf8                 cmp edi, eax
// 0083ec1d  7d06                 jge 0x83ec25
// 0083ec1f  89442414             mov dword ptr [esp + 0x14], eax
// 0083ec23  eb06                 jmp 0x83ec2b
// 0083ec25  897c2414             mov dword ptr [esp + 0x14], edi
// 0083ec29  8bc7                 mov eax, edi
// 0083ec2b  3bc3                 cmp eax, ebx
// 0083ec2d  7d05                 jge 0x83ec34
// 0083ec2f  e8d6b6fcff           call 0x80a30a
// 0083ec34  8d2c8500000000       lea ebp, [eax*4]
// 0083ec3b  55                   push ebp
// 0083ec3c  e8ffb6fcff           call 0x80a340
// 0083ec41  8b4e08               mov ecx, dword ptr [esi + 8]
// 0083ec44  8b5604               mov edx, dword ptr [esi + 4]
// 0083ec47  03c9                 add ecx, ecx
// 0083ec49  03c9                 add ecx, ecx
// 0083ec4b  51                   push ecx
// 0083ec4c  52                   push edx
// 0083ec4d  8bd8                 mov ebx, eax
// 0083ec4f  55                   push ebp
// 0083ec50  53                   push ebx
// 0083ec51  e86a49bcff           call 0x4035c0
// 0083ec56  8b4608               mov eax, dword ptr [esi + 8]
// 0083ec59  8bcf                 mov ecx, edi
// 0083ec5b  2bc8                 sub ecx, eax
// 0083ec5d  03c9                 add ecx, ecx
// 0083ec5f  03c9                 add ecx, ecx
// 0083ec61  51                   push ecx
// 0083ec62  8d1483               lea edx, [ebx + eax*4]
// 0083ec65  6a00                 push 0
// 0083ec67  52                   push edx
// 0083ec68  e877c6fcff           call 0x80b2e4
// 0083ec6d  8b4604               mov eax, dword ptr [esi + 4]
// 0083ec70  50                   push eax
// 0083ec71  e88eb6fcff           call 0x80a304
// 0083ec76  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0083ec7a  83c424               add esp, 0x24
// 0083ec7d  895e04               mov dword ptr [esi + 4], ebx
// 0083ec80  894e0c               mov dword ptr [esi + 0xc], ecx
// 0083ec83  5b                   pop ebx
// 0083ec84  897e08               mov dword ptr [esi + 8], edi
// 0083ec87  5f                   pop edi
// 0083ec88  5e                   pop esi
// 0083ec89  5d                   pop ebp
// 0083ec8a  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?SetSize@?$CArray@PAVCMFCRibbonBaseElement@@PAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
