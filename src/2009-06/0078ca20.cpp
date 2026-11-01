// from server: 100% by auto
// roc 2009-06 0078ca20  unit: CXTPPropertyGridView  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ca20
//
// 0078ca20  53                   push ebx
// 0078ca21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0078ca25  56                   push esi
// 0078ca26  57                   push edi
// 0078ca27  33ff                 xor edi, edi
// 0078ca29  3bdf                 cmp ebx, edi
// 0078ca2b  8bf1                 mov esi, ecx
// 0078ca2d  7d05                 jge 0x78ca34
// 0078ca2f  e8b0c2f8ff           call 0x718ce4
// 0078ca34  8b442414             mov eax, dword ptr [esp + 0x14]
// 0078ca38  3bc7                 cmp eax, edi
// 0078ca3a  7c03                 jl 0x78ca3f
// 0078ca3c  894610               mov dword ptr [esi + 0x10], eax
// 0078ca3f  3bdf                 cmp ebx, edi
// 0078ca41  751f                 jne 0x78ca62
// 0078ca43  8b4604               mov eax, dword ptr [esi + 4]
// 0078ca46  3bc7                 cmp eax, edi
// 0078ca48  740c                 je 0x78ca56
// 0078ca4a  50                   push eax
// 0078ca4b  e88ec2f8ff           call 0x718cde
// 0078ca50  83c404               add esp, 4
// 0078ca53  897e04               mov dword ptr [esi + 4], edi
// 0078ca56  897e0c               mov dword ptr [esi + 0xc], edi
// 0078ca59  897e08               mov dword ptr [esi + 8], edi
// 0078ca5c  5f                   pop edi
// 0078ca5d  5e                   pop esi
// 0078ca5e  5b                   pop ebx
// 0078ca5f  c20800               ret 8
// 0078ca62  8b5604               mov edx, dword ptr [esi + 4]
// 0078ca65  55                   push ebp
// 0078ca66  3bd7                 cmp edx, edi
// 0078ca68  7533                 jne 0x78ca9d
// 0078ca6a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0078ca6d  3bdd                 cmp ebx, ebp
// 0078ca6f  7e02                 jle 0x78ca73
// 0078ca71  8beb                 mov ebp, ebx
// 0078ca73  8d7cad00             lea edi, [ebp + ebp*4]
// 0078ca77  03ff                 add edi, edi
// 0078ca79  03ff                 add edi, edi
// 0078ca7b  57                   push edi
// 0078ca7c  e899c2f8ff           call 0x718d1a
// 0078ca81  57                   push edi
// 0078ca82  6a00                 push 0
// 0078ca84  50                   push eax
// 0078ca85  894604               mov dword ptr [esi + 4], eax
// 0078ca88  e8e7d1f8ff           call 0x719c74
// 0078ca8d  83c410               add esp, 0x10
// 0078ca90  896e0c               mov dword ptr [esi + 0xc], ebp
// 0078ca93  5d                   pop ebp
// 0078ca94  5f                   pop edi
// 0078ca95  895e08               mov dword ptr [esi + 8], ebx
// 0078ca98  5e                   pop esi
// 0078ca99  5b                   pop ebx
// 0078ca9a  c20800               ret 8
// 0078ca9d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0078caa0  3bd9                 cmp ebx, ecx
// 0078caa2  7f31                 jg 0x78cad5
// 0078caa4  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078caa7  3bd9                 cmp ebx, ecx
// 0078caa9  0f8ec6000000         jle 0x78cb75
// 0078caaf  8bc3                 mov eax, ebx
// 0078cab1  2bc1                 sub eax, ecx
// 0078cab3  8d0480               lea eax, [eax + eax*4]
// 0078cab6  03c0                 add eax, eax
// 0078cab8  03c0                 add eax, eax
// 0078caba  50                   push eax
// 0078cabb  8d0c89               lea ecx, [ecx + ecx*4]
// 0078cabe  8d148a               lea edx, [edx + ecx*4]
// 0078cac1  57                   push edi
// 0078cac2  52                   push edx
// 0078cac3  e8acd1f8ff           call 0x719c74
// 0078cac8  83c40c               add esp, 0xc
// 0078cacb  5d                   pop ebp
// 0078cacc  5f                   pop edi
// 0078cacd  895e08               mov dword ptr [esi + 8], ebx
// 0078cad0  5e                   pop esi
// 0078cad1  5b                   pop ebx
// 0078cad2  c20800               ret 8
// 0078cad5  8b4610               mov eax, dword ptr [esi + 0x10]
// 0078cad8  3bc7                 cmp eax, edi
// 0078cada  7524                 jne 0x78cb00
// 0078cadc  8b4608               mov eax, dword ptr [esi + 8]
// 0078cadf  99                   cdq 
// 0078cae0  83e207               and edx, 7
// 0078cae3  03c2                 add eax, edx
// 0078cae5  c1f803               sar eax, 3
// 0078cae8  83f804               cmp eax, 4
// 0078caeb  7d07                 jge 0x78caf4
// 0078caed  b804000000           mov eax, 4
// 0078caf2  eb0c                 jmp 0x78cb00
// 0078caf4  3d00040000           cmp eax, 0x400
// 0078caf9  7e05                 jle 0x78cb00
// 0078cafb  b800040000           mov eax, 0x400
// 0078cb00  8d3c01               lea edi, [ecx + eax]
// 0078cb03  3bdf                 cmp ebx, edi
// 0078cb05  7d06                 jge 0x78cb0d
// 0078cb07  897c2414             mov dword ptr [esp + 0x14], edi
// 0078cb0b  eb06                 jmp 0x78cb13
// 0078cb0d  895c2414             mov dword ptr [esp + 0x14], ebx
// 0078cb11  8bfb                 mov edi, ebx
// 0078cb13  3bf9                 cmp edi, ecx
// 0078cb15  7d05                 jge 0x78cb1c
// 0078cb17  e8c8c1f8ff           call 0x718ce4
// 0078cb1c  8d3cbf               lea edi, [edi + edi*4]
// 0078cb1f  03ff                 add edi, edi
// 0078cb21  03ff                 add edi, edi
// 0078cb23  57                   push edi
// 0078cb24  e8f1c1f8ff           call 0x718d1a
// 0078cb29  8b4e04               mov ecx, dword ptr [esi + 4]
// 0078cb2c  8be8                 mov ebp, eax
// 0078cb2e  8b4608               mov eax, dword ptr [esi + 8]
// 0078cb31  8d0480               lea eax, [eax + eax*4]
// 0078cb34  03c0                 add eax, eax
// 0078cb36  03c0                 add eax, eax
// 0078cb38  50                   push eax
// 0078cb39  51                   push ecx
// 0078cb3a  57                   push edi
// 0078cb3b  55                   push ebp
// 0078cb3c  e88f63c7ff           call 0x402ed0
// 0078cb41  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078cb44  8bc3                 mov eax, ebx
// 0078cb46  2bc1                 sub eax, ecx
// 0078cb48  8d1480               lea edx, [eax + eax*4]
// 0078cb4b  03d2                 add edx, edx
// 0078cb4d  03d2                 add edx, edx
// 0078cb4f  52                   push edx
// 0078cb50  8d0489               lea eax, [ecx + ecx*4]
// 0078cb53  8d4c8500             lea ecx, [ebp + eax*4]
// 0078cb57  6a00                 push 0
// 0078cb59  51                   push ecx
// 0078cb5a  e815d1f8ff           call 0x719c74
// 0078cb5f  8b5604               mov edx, dword ptr [esi + 4]
// 0078cb62  52                   push edx
// 0078cb63  e876c1f8ff           call 0x718cde
// 0078cb68  8b442438             mov eax, dword ptr [esp + 0x38]
// 0078cb6c  83c424               add esp, 0x24
// 0078cb6f  896e04               mov dword ptr [esi + 4], ebp
// 0078cb72  89460c               mov dword ptr [esi + 0xc], eax
// 0078cb75  5d                   pop ebp
// 0078cb76  5f                   pop edi
// 0078cb77  895e08               mov dword ptr [esi + 8], ebx
// 0078cb7a  5e                   pop esi
// 0078cb7b  5b                   pop ebx
// 0078cb7c  c20800               ret 8
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetSize@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
