// from server: 100% by auto
// roc 2010-06 0081ba40  unit: CXTPPropertyGridView  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081ba40
//
// 0081ba40  53                   push ebx
// 0081ba41  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0081ba45  56                   push esi
// 0081ba46  57                   push edi
// 0081ba47  33ff                 xor edi, edi
// 0081ba49  3bdf                 cmp ebx, edi
// 0081ba4b  8bf1                 mov esi, ecx
// 0081ba4d  7d05                 jge 0x81ba54
// 0081ba4f  e8f8c1f8ff           call 0x7a7c4c
// 0081ba54  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081ba58  3bc7                 cmp eax, edi
// 0081ba5a  7c03                 jl 0x81ba5f
// 0081ba5c  894610               mov dword ptr [esi + 0x10], eax
// 0081ba5f  3bdf                 cmp ebx, edi
// 0081ba61  751f                 jne 0x81ba82
// 0081ba63  8b4604               mov eax, dword ptr [esi + 4]
// 0081ba66  3bc7                 cmp eax, edi
// 0081ba68  740c                 je 0x81ba76
// 0081ba6a  50                   push eax
// 0081ba6b  e8d6c1f8ff           call 0x7a7c46
// 0081ba70  83c404               add esp, 4
// 0081ba73  897e04               mov dword ptr [esi + 4], edi
// 0081ba76  897e0c               mov dword ptr [esi + 0xc], edi
// 0081ba79  897e08               mov dword ptr [esi + 8], edi
// 0081ba7c  5f                   pop edi
// 0081ba7d  5e                   pop esi
// 0081ba7e  5b                   pop ebx
// 0081ba7f  c20800               ret 8
// 0081ba82  8b5604               mov edx, dword ptr [esi + 4]
// 0081ba85  55                   push ebp
// 0081ba86  3bd7                 cmp edx, edi
// 0081ba88  7533                 jne 0x81babd
// 0081ba8a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0081ba8d  3bdd                 cmp ebx, ebp
// 0081ba8f  7e02                 jle 0x81ba93
// 0081ba91  8beb                 mov ebp, ebx
// 0081ba93  8d7cad00             lea edi, [ebp + ebp*4]
// 0081ba97  03ff                 add edi, edi
// 0081ba99  03ff                 add edi, edi
// 0081ba9b  57                   push edi
// 0081ba9c  e8e1c1f8ff           call 0x7a7c82
// 0081baa1  57                   push edi
// 0081baa2  6a00                 push 0
// 0081baa4  50                   push eax
// 0081baa5  894604               mov dword ptr [esi + 4], eax
// 0081baa8  e837d1f8ff           call 0x7a8be4
// 0081baad  83c410               add esp, 0x10
// 0081bab0  896e0c               mov dword ptr [esi + 0xc], ebp
// 0081bab3  5d                   pop ebp
// 0081bab4  5f                   pop edi
// 0081bab5  895e08               mov dword ptr [esi + 8], ebx
// 0081bab8  5e                   pop esi
// 0081bab9  5b                   pop ebx
// 0081baba  c20800               ret 8
// 0081babd  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0081bac0  3bd9                 cmp ebx, ecx
// 0081bac2  7f31                 jg 0x81baf5
// 0081bac4  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081bac7  3bd9                 cmp ebx, ecx
// 0081bac9  0f8ec6000000         jle 0x81bb95
// 0081bacf  8bc3                 mov eax, ebx
// 0081bad1  2bc1                 sub eax, ecx
// 0081bad3  8d0480               lea eax, [eax + eax*4]
// 0081bad6  03c0                 add eax, eax
// 0081bad8  03c0                 add eax, eax
// 0081bada  50                   push eax
// 0081badb  8d0c89               lea ecx, [ecx + ecx*4]
// 0081bade  8d148a               lea edx, [edx + ecx*4]
// 0081bae1  57                   push edi
// 0081bae2  52                   push edx
// 0081bae3  e8fcd0f8ff           call 0x7a8be4
// 0081bae8  83c40c               add esp, 0xc
// 0081baeb  5d                   pop ebp
// 0081baec  5f                   pop edi
// 0081baed  895e08               mov dword ptr [esi + 8], ebx
// 0081baf0  5e                   pop esi
// 0081baf1  5b                   pop ebx
// 0081baf2  c20800               ret 8
// 0081baf5  8b4610               mov eax, dword ptr [esi + 0x10]
// 0081baf8  3bc7                 cmp eax, edi
// 0081bafa  7524                 jne 0x81bb20
// 0081bafc  8b4608               mov eax, dword ptr [esi + 8]
// 0081baff  99                   cdq 
// 0081bb00  83e207               and edx, 7
// 0081bb03  03c2                 add eax, edx
// 0081bb05  c1f803               sar eax, 3
// 0081bb08  83f804               cmp eax, 4
// 0081bb0b  7d07                 jge 0x81bb14
// 0081bb0d  b804000000           mov eax, 4
// 0081bb12  eb0c                 jmp 0x81bb20
// 0081bb14  3d00040000           cmp eax, 0x400
// 0081bb19  7e05                 jle 0x81bb20
// 0081bb1b  b800040000           mov eax, 0x400
// 0081bb20  8d3c01               lea edi, [ecx + eax]
// 0081bb23  3bdf                 cmp ebx, edi
// 0081bb25  7d06                 jge 0x81bb2d
// 0081bb27  897c2414             mov dword ptr [esp + 0x14], edi
// 0081bb2b  eb06                 jmp 0x81bb33
// 0081bb2d  895c2414             mov dword ptr [esp + 0x14], ebx
// 0081bb31  8bfb                 mov edi, ebx
// 0081bb33  3bf9                 cmp edi, ecx
// 0081bb35  7d05                 jge 0x81bb3c
// 0081bb37  e810c1f8ff           call 0x7a7c4c
// 0081bb3c  8d3cbf               lea edi, [edi + edi*4]
// 0081bb3f  03ff                 add edi, edi
// 0081bb41  03ff                 add edi, edi
// 0081bb43  57                   push edi
// 0081bb44  e839c1f8ff           call 0x7a7c82
// 0081bb49  8b4e04               mov ecx, dword ptr [esi + 4]
// 0081bb4c  8be8                 mov ebp, eax
// 0081bb4e  8b4608               mov eax, dword ptr [esi + 8]
// 0081bb51  8d0480               lea eax, [eax + eax*4]
// 0081bb54  03c0                 add eax, eax
// 0081bb56  03c0                 add eax, eax
// 0081bb58  50                   push eax
// 0081bb59  51                   push ecx
// 0081bb5a  57                   push edi
// 0081bb5b  55                   push ebp
// 0081bb5c  e88f70beff           call 0x402bf0
// 0081bb61  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081bb64  8bc3                 mov eax, ebx
// 0081bb66  2bc1                 sub eax, ecx
// 0081bb68  8d1480               lea edx, [eax + eax*4]
// 0081bb6b  03d2                 add edx, edx
// 0081bb6d  03d2                 add edx, edx
// 0081bb6f  52                   push edx
// 0081bb70  8d0489               lea eax, [ecx + ecx*4]
// 0081bb73  8d4c8500             lea ecx, [ebp + eax*4]
// 0081bb77  6a00                 push 0
// 0081bb79  51                   push ecx
// 0081bb7a  e865d0f8ff           call 0x7a8be4
// 0081bb7f  8b5604               mov edx, dword ptr [esi + 4]
// 0081bb82  52                   push edx
// 0081bb83  e8bec0f8ff           call 0x7a7c46
// 0081bb88  8b442438             mov eax, dword ptr [esp + 0x38]
// 0081bb8c  83c424               add esp, 0x24
// 0081bb8f  896e04               mov dword ptr [esi + 4], ebp
// 0081bb92  89460c               mov dword ptr [esi + 0xc], eax
// 0081bb95  5d                   pop ebp
// 0081bb96  5f                   pop edi
// 0081bb97  895e08               mov dword ptr [esi + 8], ebx
// 0081bb9a  5e                   pop esi
// 0081bb9b  5b                   pop ebx
// 0081bb9c  c20800               ret 8
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?SetSize@?$CArray@UWNDRECT@CXTPPropertyGridView@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
