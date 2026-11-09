// from server: 100% by auto
// roc 2010-06 007c8b60  unit: PAVCXTPCommandBarKeyboardTip::?$CArray  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8b60
//
// 007c8b60  83ec14               sub esp, 0x14
// 007c8b63  53                   push ebx
// 007c8b64  55                   push ebp
// 007c8b65  8b2d3cbc9e00         mov ebp, dword ptr [0x9ebc3c]
// 007c8b6b  56                   push esi
// 007c8b6c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007c8b70  57                   push edi
// 007c8b71  894c2410             mov dword ptr [esp + 0x10], ecx
// 007c8b75  85f6                 test esi, esi
// 007c8b77  0f8486000000         je 0x7c8c03
// 007c8b7d  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007c8b80  8d442414             lea eax, [esp + 0x14]
// 007c8b84  50                   push eax
// 007c8b85  51                   push ecx
// 007c8b86  ffd5                 call ebp
// 007c8b88  8b4654               mov eax, dword ptr [esi + 0x54]
// 007c8b8b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007c8b8f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c8b93  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007c8b97  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007c8b9b  a900a00000           test eax, 0xa000
// 007c8ba0  7436                 je 0x7c8bd8
// 007c8ba2  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007c8ba6  83c5ec               add ebp, -0x14
// 007c8ba9  3bea                 cmp ebp, edx
// 007c8bab  7d25                 jge 0x7c8bd2
// 007c8bad  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 007c8bb1  83c514               add ebp, 0x14
// 007c8bb4  3bea                 cmp ebp, edx
// 007c8bb6  7e1a                 jle 0x7c8bd2
// 007c8bb8  8d6fec               lea ebp, [edi - 0x14]
// 007c8bbb  3be9                 cmp ebp, ecx
// 007c8bbd  7d13                 jge 0x7c8bd2
// 007c8bbf  8d6b14               lea ebp, [ebx + 0x14]
// 007c8bc2  3be9                 cmp ebp, ecx
// 007c8bc4  7e0c                 jle 0x7c8bd2
// 007c8bc6  5f                   pop edi
// 007c8bc7  8bc6                 mov eax, esi
// 007c8bc9  5e                   pop esi
// 007c8bca  5d                   pop ebp
// 007c8bcb  5b                   pop ebx
// 007c8bcc  83c414               add esp, 0x14
// 007c8bcf  c20c00               ret 0xc
// 007c8bd2  8b2d3cbc9e00         mov ebp, dword ptr [0x9ebc3c]
// 007c8bd8  a900500000           test eax, 0x5000
// 007c8bdd  7424                 je 0x7c8c03
// 007c8bdf  83c7ec               add edi, -0x14
// 007c8be2  3bf9                 cmp edi, ecx
// 007c8be4  7d1d                 jge 0x7c8c03
// 007c8be6  83c314               add ebx, 0x14
// 007c8be9  3bd9                 cmp ebx, ecx
// 007c8beb  7e16                 jle 0x7c8c03
// 007c8bed  8b442418             mov eax, dword ptr [esp + 0x18]
// 007c8bf1  83c0ec               add eax, -0x14
// 007c8bf4  3bc2                 cmp eax, edx
// 007c8bf6  7d0b                 jge 0x7c8c03
// 007c8bf8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007c8bfc  83c114               add ecx, 0x14
// 007c8bff  3bca                 cmp ecx, edx
// 007c8c01  7fc3                 jg 0x7c8bc6
// 007c8c03  8b742410             mov esi, dword ptr [esp + 0x10]
// 007c8c07  33db                 xor ebx, ebx
// 007c8c09  895c2430             mov dword ptr [esp + 0x30], ebx
// 007c8c0d  81c690000000         add esi, 0x90
// 007c8c13  8b06                 mov eax, dword ptr [esi]
// 007c8c15  8b4820               mov ecx, dword ptr [eax + 0x20]
// 007c8c18  8d542414             lea edx, [esp + 0x14]
// 007c8c1c  52                   push edx
// 007c8c1d  51                   push ecx
// 007c8c1e  ffd5                 call ebp
// 007c8c20  8b16                 mov edx, dword ptr [esi]
// 007c8c22  8b4254               mov eax, dword ptr [edx + 0x54]
// 007c8c25  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007c8c29  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c8c2d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007c8c31  a900a00000           test eax, 0xa000
// 007c8c36  742c                 je 0x7c8c64
// 007c8c38  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007c8c3c  83c3ec               add ebx, -0x14
// 007c8c3f  3bda                 cmp ebx, edx
// 007c8c41  7d1d                 jge 0x7c8c60
// 007c8c43  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007c8c47  83c314               add ebx, 0x14
// 007c8c4a  3bda                 cmp ebx, edx
// 007c8c4c  7e12                 jle 0x7c8c60
// 007c8c4e  8d5fec               lea ebx, [edi - 0x14]
// 007c8c51  3bd9                 cmp ebx, ecx
// 007c8c53  7d0b                 jge 0x7c8c60
// 007c8c55  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007c8c59  83c314               add ebx, 0x14
// 007c8c5c  3bd9                 cmp ebx, ecx
// 007c8c5e  7f50                 jg 0x7c8cb0
// 007c8c60  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 007c8c64  a900500000           test eax, 0x5000
// 007c8c69  7428                 je 0x7c8c93
// 007c8c6b  83c7ec               add edi, -0x14
// 007c8c6e  3bf9                 cmp edi, ecx
// 007c8c70  7d21                 jge 0x7c8c93
// 007c8c72  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007c8c76  83c014               add eax, 0x14
// 007c8c79  3bc1                 cmp eax, ecx
// 007c8c7b  7e16                 jle 0x7c8c93
// 007c8c7d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007c8c81  83c1ec               add ecx, -0x14
// 007c8c84  3bca                 cmp ecx, edx
// 007c8c86  7d0b                 jge 0x7c8c93
// 007c8c88  8b442420             mov eax, dword ptr [esp + 0x20]
// 007c8c8c  83c014               add eax, 0x14
// 007c8c8f  3bc2                 cmp eax, edx
// 007c8c91  7f36                 jg 0x7c8cc9
// 007c8c93  43                   inc ebx
// 007c8c94  83c604               add esi, 4
// 007c8c97  83fb04               cmp ebx, 4
// 007c8c9a  895c2430             mov dword ptr [esp + 0x30], ebx
// 007c8c9e  0f8c6fffffff         jl 0x7c8c13
// 007c8ca4  5f                   pop edi
// 007c8ca5  5e                   pop esi
// 007c8ca6  5d                   pop ebp
// 007c8ca7  33c0                 xor eax, eax
// 007c8ca9  5b                   pop ebx
// 007c8caa  83c414               add esp, 0x14
// 007c8cad  c20c00               ret 0xc
// 007c8cb0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c8cb4  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c8cb8  8b849190000000       mov eax, dword ptr [ecx + edx*4 + 0x90]
// 007c8cbf  5f                   pop edi
// 007c8cc0  5e                   pop esi
// 007c8cc1  5d                   pop ebp
// 007c8cc2  5b                   pop ebx
// 007c8cc3  83c414               add esp, 0x14
// 007c8cc6  c20c00               ret 0xc
// 007c8cc9  8b442410             mov eax, dword ptr [esp + 0x10]
// 007c8ccd  8b849890000000       mov eax, dword ptr [eax + ebx*4 + 0x90]
// 007c8cd4  5f                   pop edi
// 007c8cd5  5e                   pop esi
// 007c8cd6  5d                   pop ebp
// 007c8cd7  5b                   pop ebx
// 007c8cd8  83c414               add esp, 0x14
// 007c8cdb  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?CanDock@CXTPCommandBars@@QBEPAVCXTPDockBar@@VCPoint@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
