// from server: 100% by auto
// roc 2007-08 006ffab0  unit: CXTSplitterWnd  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ffab0
//
// 006ffab0  55                   push ebp
// 006ffab1  56                   push esi
// 006ffab2  57                   push edi
// 006ffab3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ffab7  33ed                 xor ebp, ebp
// 006ffab9  3bfd                 cmp edi, ebp
// 006ffabb  8bf1                 mov esi, ecx
// 006ffabd  7d05                 jge 0x6ffac4
// 006ffabf  e85c04f3ff           call 0x62ff20
// 006ffac4  8b442414             mov eax, dword ptr [esp + 0x14]
// 006ffac8  3bc5                 cmp eax, ebp
// 006ffaca  7c03                 jl 0x6ffacf
// 006ffacc  894610               mov dword ptr [esi + 0x10], eax
// 006ffacf  3bfd                 cmp edi, ebp
// 006ffad1  751f                 jne 0x6ffaf2
// 006ffad3  8b4604               mov eax, dword ptr [esi + 4]
// 006ffad6  3bc5                 cmp eax, ebp
// 006ffad8  740c                 je 0x6ffae6
// 006ffada  50                   push eax
// 006ffadb  e84604f3ff           call 0x62ff26
// 006ffae0  83c404               add esp, 4
// 006ffae3  896e04               mov dword ptr [esi + 4], ebp
// 006ffae6  5f                   pop edi
// 006ffae7  896e0c               mov dword ptr [esi + 0xc], ebp
// 006ffaea  896e08               mov dword ptr [esi + 8], ebp
// 006ffaed  5e                   pop esi
// 006ffaee  5d                   pop ebp
// 006ffaef  c20800               ret 8
// 006ffaf2  8b4e04               mov ecx, dword ptr [esi + 4]
// 006ffaf5  3bcd                 cmp ecx, ebp
// 006ffaf7  53                   push ebx
// 006ffaf8  7532                 jne 0x6ffb2c
// 006ffafa  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 006ffafd  3bfd                 cmp edi, ebp
// 006ffaff  7e02                 jle 0x6ffb03
// 006ffb01  8bef                 mov ebp, edi
// 006ffb03  8d1cad00000000       lea ebx, [ebp*4]
// 006ffb0a  53                   push ebx
// 006ffb0b  e82204f3ff           call 0x62ff32
// 006ffb10  53                   push ebx
// 006ffb11  6a00                 push 0
// 006ffb13  50                   push eax
// 006ffb14  894604               mov dword ptr [esi + 4], eax
// 006ffb17  e87010f3ff           call 0x630b8c
// 006ffb1c  83c410               add esp, 0x10
// 006ffb1f  5b                   pop ebx
// 006ffb20  897e08               mov dword ptr [esi + 8], edi
// 006ffb23  5f                   pop edi
// 006ffb24  896e0c               mov dword ptr [esi + 0xc], ebp
// 006ffb27  5e                   pop esi
// 006ffb28  5d                   pop ebp
// 006ffb29  c20800               ret 8
// 006ffb2c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 006ffb2f  3bfb                 cmp edi, ebx
// 006ffb31  7f2b                 jg 0x6ffb5e
// 006ffb33  8b4608               mov eax, dword ptr [esi + 8]
// 006ffb36  3bf8                 cmp edi, eax
// 006ffb38  0f8eb5000000         jle 0x6ffbf3
// 006ffb3e  8bd7                 mov edx, edi
// 006ffb40  2bd0                 sub edx, eax
// 006ffb42  03d2                 add edx, edx
// 006ffb44  03d2                 add edx, edx
// 006ffb46  52                   push edx
// 006ffb47  8d0481               lea eax, [ecx + eax*4]
// 006ffb4a  55                   push ebp
// 006ffb4b  50                   push eax
// 006ffb4c  e83b10f3ff           call 0x630b8c
// 006ffb51  83c40c               add esp, 0xc
// 006ffb54  5b                   pop ebx
// 006ffb55  897e08               mov dword ptr [esi + 8], edi
// 006ffb58  5f                   pop edi
// 006ffb59  5e                   pop esi
// 006ffb5a  5d                   pop ebp
// 006ffb5b  c20800               ret 8
// 006ffb5e  8b4610               mov eax, dword ptr [esi + 0x10]
// 006ffb61  3bc5                 cmp eax, ebp
// 006ffb63  7524                 jne 0x6ffb89
// 006ffb65  8b4608               mov eax, dword ptr [esi + 8]
// 006ffb68  99                   cdq 
// 006ffb69  83e207               and edx, 7
// 006ffb6c  03c2                 add eax, edx
// 006ffb6e  c1f803               sar eax, 3
// 006ffb71  83f804               cmp eax, 4
// 006ffb74  7d07                 jge 0x6ffb7d
// 006ffb76  b804000000           mov eax, 4
// 006ffb7b  eb0c                 jmp 0x6ffb89
// 006ffb7d  3d00040000           cmp eax, 0x400
// 006ffb82  7e05                 jle 0x6ffb89
// 006ffb84  b800040000           mov eax, 0x400
// 006ffb89  03c3                 add eax, ebx
// 006ffb8b  3bf8                 cmp edi, eax
// 006ffb8d  7d06                 jge 0x6ffb95
// 006ffb8f  89442414             mov dword ptr [esp + 0x14], eax
// 006ffb93  eb06                 jmp 0x6ffb9b
// 006ffb95  897c2414             mov dword ptr [esp + 0x14], edi
// 006ffb99  8bc7                 mov eax, edi
// 006ffb9b  3bc3                 cmp eax, ebx
// 006ffb9d  7d05                 jge 0x6ffba4
// 006ffb9f  e87c03f3ff           call 0x62ff20
// 006ffba4  8d2c8500000000       lea ebp, [eax*4]
// 006ffbab  55                   push ebp
// 006ffbac  e88103f3ff           call 0x62ff32
// 006ffbb1  8b4e08               mov ecx, dword ptr [esi + 8]
// 006ffbb4  8b5604               mov edx, dword ptr [esi + 4]
// 006ffbb7  03c9                 add ecx, ecx
// 006ffbb9  03c9                 add ecx, ecx
// 006ffbbb  51                   push ecx
// 006ffbbc  52                   push edx
// 006ffbbd  8bd8                 mov ebx, eax
// 006ffbbf  55                   push ebp
// 006ffbc0  53                   push ebx
// 006ffbc1  e8ba1cd0ff           call 0x401880
// 006ffbc6  8b4608               mov eax, dword ptr [esi + 8]
// 006ffbc9  8bcf                 mov ecx, edi
// 006ffbcb  2bc8                 sub ecx, eax
// 006ffbcd  03c9                 add ecx, ecx
// 006ffbcf  03c9                 add ecx, ecx
// 006ffbd1  51                   push ecx
// 006ffbd2  8d1483               lea edx, [ebx + eax*4]
// 006ffbd5  6a00                 push 0
// 006ffbd7  52                   push edx
// 006ffbd8  e8af0ff3ff           call 0x630b8c
// 006ffbdd  8b4604               mov eax, dword ptr [esi + 4]
// 006ffbe0  50                   push eax
// 006ffbe1  e84003f3ff           call 0x62ff26
// 006ffbe6  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006ffbea  83c424               add esp, 0x24
// 006ffbed  895e04               mov dword ptr [esi + 4], ebx
// 006ffbf0  894e0c               mov dword ptr [esi + 0xc], ecx
// 006ffbf3  5b                   pop ebx
// 006ffbf4  897e08               mov dword ptr [esi + 8], edi
// 006ffbf7  5f                   pop edi
// 006ffbf8  5e                   pop esi
// 006ffbf9  5d                   pop ebp
// 006ffbfa  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?SetSize@?$CArray@HABH@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
