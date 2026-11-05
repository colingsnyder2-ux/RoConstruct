// from server: 100% by auto
// roc 2008-06 006d9db0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 339 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006d9db0
//
// 006d9db0  55                   push ebp
// 006d9db1  56                   push esi
// 006d9db2  57                   push edi
// 006d9db3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006d9db7  33ed                 xor ebp, ebp
// 006d9db9  3bfd                 cmp edi, ebp
// 006d9dbb  8bf1                 mov esi, ecx
// 006d9dbd  7d05                 jge 0x6d9dc4
// 006d9dbf  e8806bfcff           call 0x6a0944
// 006d9dc4  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d9dc8  3bc5                 cmp eax, ebp
// 006d9dca  7c03                 jl 0x6d9dcf
// 006d9dcc  894610               mov dword ptr [esi + 0x10], eax
// 006d9dcf  3bfd                 cmp edi, ebp
// 006d9dd1  751f                 jne 0x6d9df2
// 006d9dd3  8b4604               mov eax, dword ptr [esi + 4]
// 006d9dd6  3bc5                 cmp eax, ebp
// 006d9dd8  740c                 je 0x6d9de6
// 006d9dda  50                   push eax
// 006d9ddb  e86a6bfcff           call 0x6a094a
// 006d9de0  83c404               add esp, 4
// 006d9de3  896e04               mov dword ptr [esi + 4], ebp
// 006d9de6  5f                   pop edi
// 006d9de7  896e0c               mov dword ptr [esi + 0xc], ebp
// 006d9dea  896e08               mov dword ptr [esi + 8], ebp
// 006d9ded  5e                   pop esi
// 006d9dee  5d                   pop ebp
// 006d9def  c20800               ret 8
// 006d9df2  8b4e04               mov ecx, dword ptr [esi + 4]
// 006d9df5  53                   push ebx
// 006d9df6  3bcd                 cmp ecx, ebp
// 006d9df8  7532                 jne 0x6d9e2c
// 006d9dfa  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 006d9dfd  3bfd                 cmp edi, ebp
// 006d9dff  7e02                 jle 0x6d9e03
// 006d9e01  8bef                 mov ebp, edi
// 006d9e03  8d1ced00000000       lea ebx, [ebp*8]
// 006d9e0a  53                   push ebx
// 006d9e0b  e8466bfcff           call 0x6a0956
// 006d9e10  53                   push ebx
// 006d9e11  6a00                 push 0
// 006d9e13  50                   push eax
// 006d9e14  894604               mov dword ptr [esi + 4], eax
// 006d9e17  e8e878fcff           call 0x6a1704
// 006d9e1c  83c410               add esp, 0x10
// 006d9e1f  5b                   pop ebx
// 006d9e20  897e08               mov dword ptr [esi + 8], edi
// 006d9e23  5f                   pop edi
// 006d9e24  896e0c               mov dword ptr [esi + 0xc], ebp
// 006d9e27  5e                   pop esi
// 006d9e28  5d                   pop ebp
// 006d9e29  c20800               ret 8
// 006d9e2c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006d9e2f  3bfb                 cmp edi, ebx
// 006d9e31  7f2d                 jg 0x6d9e60
// 006d9e33  8b4608               mov eax, dword ptr [esi + 8]
// 006d9e36  3bf8                 cmp edi, eax
// 006d9e38  0f8ebb000000         jle 0x6d9ef9
// 006d9e3e  8bd7                 mov edx, edi
// 006d9e40  2bd0                 sub edx, eax
// 006d9e42  03d2                 add edx, edx
// 006d9e44  03d2                 add edx, edx
// 006d9e46  03d2                 add edx, edx
// 006d9e48  52                   push edx
// 006d9e49  8d04c1               lea eax, [ecx + eax*8]
// 006d9e4c  55                   push ebp
// 006d9e4d  50                   push eax
// 006d9e4e  e8b178fcff           call 0x6a1704
// 006d9e53  83c40c               add esp, 0xc
// 006d9e56  5b                   pop ebx
// 006d9e57  897e08               mov dword ptr [esi + 8], edi
// 006d9e5a  5f                   pop edi
// 006d9e5b  5e                   pop esi
// 006d9e5c  5d                   pop ebp
// 006d9e5d  c20800               ret 8
// 006d9e60  8b4610               mov eax, dword ptr [esi + 0x10]
// 006d9e63  3bc5                 cmp eax, ebp
// 006d9e65  7524                 jne 0x6d9e8b
// 006d9e67  8b4608               mov eax, dword ptr [esi + 8]
// 006d9e6a  99                   cdq 
// 006d9e6b  83e207               and edx, 7
// 006d9e6e  03c2                 add eax, edx
// 006d9e70  c1f803               sar eax, 3
// 006d9e73  83f804               cmp eax, 4
// 006d9e76  7d07                 jge 0x6d9e7f
// 006d9e78  b804000000           mov eax, 4
// 006d9e7d  eb0c                 jmp 0x6d9e8b
// 006d9e7f  3d00040000           cmp eax, 0x400
// 006d9e84  7e05                 jle 0x6d9e8b
// 006d9e86  b800040000           mov eax, 0x400
// 006d9e8b  03c3                 add eax, ebx
// 006d9e8d  3bf8                 cmp edi, eax
// 006d9e8f  7d06                 jge 0x6d9e97
// 006d9e91  89442414             mov dword ptr [esp + 0x14], eax
// 006d9e95  eb06                 jmp 0x6d9e9d
// 006d9e97  897c2414             mov dword ptr [esp + 0x14], edi
// 006d9e9b  8bc7                 mov eax, edi
// 006d9e9d  3bc3                 cmp eax, ebx
// 006d9e9f  7d05                 jge 0x6d9ea6
// 006d9ea1  e89e6afcff           call 0x6a0944
// 006d9ea6  8d2cc500000000       lea ebp, [eax*8]
// 006d9ead  55                   push ebp
// 006d9eae  e8a36afcff           call 0x6a0956
// 006d9eb3  8b4e08               mov ecx, dword ptr [esi + 8]
// 006d9eb6  8b5604               mov edx, dword ptr [esi + 4]
// 006d9eb9  03c9                 add ecx, ecx
// 006d9ebb  03c9                 add ecx, ecx
// 006d9ebd  03c9                 add ecx, ecx
// 006d9ebf  51                   push ecx
// 006d9ec0  52                   push edx
// 006d9ec1  8bd8                 mov ebx, eax
// 006d9ec3  55                   push ebp
// 006d9ec4  53                   push ebx
// 006d9ec5  e84679d2ff           call 0x401810
// 006d9eca  8b4608               mov eax, dword ptr [esi + 8]
// 006d9ecd  8bcf                 mov ecx, edi
// 006d9ecf  2bc8                 sub ecx, eax
// 006d9ed1  03c9                 add ecx, ecx
// 006d9ed3  03c9                 add ecx, ecx
// 006d9ed5  03c9                 add ecx, ecx
// 006d9ed7  51                   push ecx
// 006d9ed8  8d14c3               lea edx, [ebx + eax*8]
// 006d9edb  6a00                 push 0
// 006d9edd  52                   push edx
// 006d9ede  e82178fcff           call 0x6a1704
// 006d9ee3  8b4604               mov eax, dword ptr [esi + 4]
// 006d9ee6  50                   push eax
// 006d9ee7  e85e6afcff           call 0x6a094a
// 006d9eec  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006d9ef0  83c424               add esp, 0x24
// 006d9ef3  895e04               mov dword ptr [esi + 4], ebx
// 006d9ef6  894e0c               mov dword ptr [esi + 0xc], ecx
// 006d9ef9  5b                   pop ebx
// 006d9efa  897e08               mov dword ptr [esi + 8], edi
// 006d9efd  5f                   pop edi
// 006d9efe  5e                   pop esi
// 006d9eff  5d                   pop ebp
// 006d9f00  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ?SetSize@?$CArray@VCSize@@V1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
