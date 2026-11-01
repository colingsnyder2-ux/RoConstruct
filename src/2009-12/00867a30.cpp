// from server: 100% by auto
// roc 2009-12 00867a30  unit: CXTPPropertyGridView  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867a30
//
// 00867a30  53                   push ebx
// 00867a31  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00867a35  56                   push esi
// 00867a36  57                   push edi
// 00867a37  33ff                 xor edi, edi
// 00867a39  3bdf                 cmp ebx, edi
// 00867a3b  8bf1                 mov esi, ecx
// 00867a3d  7d05                 jge 0x867a44
// 00867a3f  e8c8c0f8ff           call 0x7f3b0c
// 00867a44  8b442414             mov eax, dword ptr [esp + 0x14]
// 00867a48  3bc7                 cmp eax, edi
// 00867a4a  7c03                 jl 0x867a4f
// 00867a4c  894610               mov dword ptr [esi + 0x10], eax
// 00867a4f  3bdf                 cmp ebx, edi
// 00867a51  751f                 jne 0x867a72
// 00867a53  8b4604               mov eax, dword ptr [esi + 4]
// 00867a56  3bc7                 cmp eax, edi
// 00867a58  740c                 je 0x867a66
// 00867a5a  50                   push eax
// 00867a5b  e8a6c0f8ff           call 0x7f3b06
// 00867a60  83c404               add esp, 4
// 00867a63  897e04               mov dword ptr [esi + 4], edi
// 00867a66  897e0c               mov dword ptr [esi + 0xc], edi
// 00867a69  897e08               mov dword ptr [esi + 8], edi
// 00867a6c  5f                   pop edi
// 00867a6d  5e                   pop esi
// 00867a6e  5b                   pop ebx
// 00867a6f  c20800               ret 8
// 00867a72  8b5604               mov edx, dword ptr [esi + 4]
// 00867a75  55                   push ebp
// 00867a76  3bd7                 cmp edx, edi
// 00867a78  7533                 jne 0x867aad
// 00867a7a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00867a7d  3bdd                 cmp ebx, ebp
// 00867a7f  7e02                 jle 0x867a83
// 00867a81  8beb                 mov ebp, ebx
// 00867a83  8d7cad00             lea edi, [ebp + ebp*4]
// 00867a87  03ff                 add edi, edi
// 00867a89  03ff                 add edi, edi
// 00867a8b  57                   push edi
// 00867a8c  e8b1c0f8ff           call 0x7f3b42
// 00867a91  57                   push edi
// 00867a92  6a00                 push 0
// 00867a94  50                   push eax
// 00867a95  894604               mov dword ptr [esi + 4], eax
// 00867a98  e807d0f8ff           call 0x7f4aa4
// 00867a9d  83c410               add esp, 0x10
// 00867aa0  896e0c               mov dword ptr [esi + 0xc], ebp
// 00867aa3  5d                   pop ebp
// 00867aa4  5f                   pop edi
// 00867aa5  895e08               mov dword ptr [esi + 8], ebx
// 00867aa8  5e                   pop esi
// 00867aa9  5b                   pop ebx
// 00867aaa  c20800               ret 8
// 00867aad  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00867ab0  3bd9                 cmp ebx, ecx
// 00867ab2  7f31                 jg 0x867ae5
// 00867ab4  8b4e08               mov ecx, dword ptr [esi + 8]
// 00867ab7  3bd9                 cmp ebx, ecx
// 00867ab9  0f8ec6000000         jle 0x867b85
// 00867abf  8bc3                 mov eax, ebx
// 00867ac1  2bc1                 sub eax, ecx
// 00867ac3  8d0480               lea eax, [eax + eax*4]
// 00867ac6  03c0                 add eax, eax
// 00867ac8  03c0                 add eax, eax
// 00867aca  50                   push eax
// 00867acb  8d0c89               lea ecx, [ecx + ecx*4]
// 00867ace  8d148a               lea edx, [edx + ecx*4]
// 00867ad1  57                   push edi
// 00867ad2  52                   push edx
// 00867ad3  e8cccff8ff           call 0x7f4aa4
// 00867ad8  83c40c               add esp, 0xc
// 00867adb  5d                   pop ebp
// 00867adc  5f                   pop edi
// 00867add  895e08               mov dword ptr [esi + 8], ebx
// 00867ae0  5e                   pop esi
// 00867ae1  5b                   pop ebx
// 00867ae2  c20800               ret 8
// 00867ae5  8b4610               mov eax, dword ptr [esi + 0x10]
// 00867ae8  3bc7                 cmp eax, edi
// 00867aea  7524                 jne 0x867b10
// 00867aec  8b4608               mov eax, dword ptr [esi + 8]
// 00867aef  99                   cdq 
// 00867af0  83e207               and edx, 7
// 00867af3  03c2                 add eax, edx
// 00867af5  c1f803               sar eax, 3
// 00867af8  83f804               cmp eax, 4
// 00867afb  7d07                 jge 0x867b04
// 00867afd  b804000000           mov eax, 4
// 00867b02  eb0c                 jmp 0x867b10
// 00867b04  3d00040000           cmp eax, 0x400
// 00867b09  7e05                 jle 0x867b10
// 00867b0b  b800040000           mov eax, 0x400
// 00867b10  8d3c01               lea edi, [ecx + eax]
// 00867b13  3bdf                 cmp ebx, edi
// 00867b15  7d06                 jge 0x867b1d
// 00867b17  897c2414             mov dword ptr [esp + 0x14], edi
// 00867b1b  eb06                 jmp 0x867b23
// 00867b1d  895c2414             mov dword ptr [esp + 0x14], ebx
// 00867b21  8bfb                 mov edi, ebx
// 00867b23  3bf9                 cmp edi, ecx
// 00867b25  7d05                 jge 0x867b2c
// 00867b27  e8e0bff8ff           call 0x7f3b0c
// 00867b2c  8d3cbf               lea edi, [edi + edi*4]
// 00867b2f  03ff                 add edi, edi
// 00867b31  03ff                 add edi, edi
// 00867b33  57                   push edi
// 00867b34  e809c0f8ff           call 0x7f3b42
// 00867b39  8b4e04               mov ecx, dword ptr [esi + 4]
// 00867b3c  8be8                 mov ebp, eax
// 00867b3e  8b4608               mov eax, dword ptr [esi + 8]
// 00867b41  8d0480               lea eax, [eax + eax*4]
// 00867b44  03c0                 add eax, eax
// 00867b46  03c0                 add eax, eax
// 00867b48  50                   push eax
// 00867b49  51                   push ecx
// 00867b4a  57                   push edi
// 00867b4b  55                   push ebp
// 00867b4c  e84fb0b9ff           call 0x402ba0
// 00867b51  8b4e08               mov ecx, dword ptr [esi + 8]
// 00867b54  8bc3                 mov eax, ebx
// 00867b56  2bc1                 sub eax, ecx
// 00867b58  8d1480               lea edx, [eax + eax*4]
// 00867b5b  03d2                 add edx, edx
// 00867b5d  03d2                 add edx, edx
// 00867b5f  52                   push edx
// 00867b60  8d0489               lea eax, [ecx + ecx*4]
// 00867b63  8d4c8500             lea ecx, [ebp + eax*4]
// 00867b67  6a00                 push 0
// 00867b69  51                   push ecx
// 00867b6a  e835cff8ff           call 0x7f4aa4
// 00867b6f  8b5604               mov edx, dword ptr [esi + 4]
// 00867b72  52                   push edx
// 00867b73  e88ebff8ff           call 0x7f3b06
// 00867b78  8b442438             mov eax, dword ptr [esp + 0x38]
// 00867b7c  83c424               add esp, 0x24
// 00867b7f  896e04               mov dword ptr [esi + 4], ebp
// 00867b82  89460c               mov dword ptr [esi + 0xc], eax
// 00867b85  5d                   pop ebp
// 00867b86  5f                   pop edi
// 00867b87  895e08               mov dword ptr [esi + 8], ebx
// 00867b8a  5e                   pop esi
// 00867b8b  5b                   pop ebx
// 00867b8c  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetSize@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
