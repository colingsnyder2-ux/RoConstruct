// from server: 100% by auto
// roc 2009-06 00729de0  unit: CXTPCommandBarList  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00729de0
//
// 00729de0  83ec14               sub esp, 0x14
// 00729de3  53                   push ebx
// 00729de4  55                   push ebp
// 00729de5  8b2df4ed8900         mov ebp, dword ptr [0x89edf4]
// 00729deb  56                   push esi
// 00729dec  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00729df0  57                   push edi
// 00729df1  894c2410             mov dword ptr [esp + 0x10], ecx
// 00729df5  85f6                 test esi, esi
// 00729df7  0f8486000000         je 0x729e83
// 00729dfd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00729e00  8d442414             lea eax, [esp + 0x14]
// 00729e04  50                   push eax
// 00729e05  51                   push ecx
// 00729e06  ffd5                 call ebp
// 00729e08  8b4654               mov eax, dword ptr [esi + 0x54]
// 00729e0b  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00729e0f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00729e13  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00729e17  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00729e1b  a900a00000           test eax, 0xa000
// 00729e20  7436                 je 0x729e58
// 00729e22  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00729e26  83c5ec               add ebp, -0x14
// 00729e29  3bea                 cmp ebp, edx
// 00729e2b  7d25                 jge 0x729e52
// 00729e2d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00729e31  83c514               add ebp, 0x14
// 00729e34  3bea                 cmp ebp, edx
// 00729e36  7e1a                 jle 0x729e52
// 00729e38  8d6fec               lea ebp, [edi - 0x14]
// 00729e3b  3be9                 cmp ebp, ecx
// 00729e3d  7d13                 jge 0x729e52
// 00729e3f  8d6b14               lea ebp, [ebx + 0x14]
// 00729e42  3be9                 cmp ebp, ecx
// 00729e44  7e0c                 jle 0x729e52
// 00729e46  5f                   pop edi
// 00729e47  8bc6                 mov eax, esi
// 00729e49  5e                   pop esi
// 00729e4a  5d                   pop ebp
// 00729e4b  5b                   pop ebx
// 00729e4c  83c414               add esp, 0x14
// 00729e4f  c20c00               ret 0xc
// 00729e52  8b2df4ed8900         mov ebp, dword ptr [0x89edf4]
// 00729e58  a900500000           test eax, 0x5000
// 00729e5d  7424                 je 0x729e83
// 00729e5f  83c7ec               add edi, -0x14
// 00729e62  3bf9                 cmp edi, ecx
// 00729e64  7d1d                 jge 0x729e83
// 00729e66  83c314               add ebx, 0x14
// 00729e69  3bd9                 cmp ebx, ecx
// 00729e6b  7e16                 jle 0x729e83
// 00729e6d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00729e71  83c0ec               add eax, -0x14
// 00729e74  3bc2                 cmp eax, edx
// 00729e76  7d0b                 jge 0x729e83
// 00729e78  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00729e7c  83c114               add ecx, 0x14
// 00729e7f  3bca                 cmp ecx, edx
// 00729e81  7fc3                 jg 0x729e46
// 00729e83  8b742410             mov esi, dword ptr [esp + 0x10]
// 00729e87  33db                 xor ebx, ebx
// 00729e89  895c2430             mov dword ptr [esp + 0x30], ebx
// 00729e8d  81c690000000         add esi, 0x90
// 00729e93  8b06                 mov eax, dword ptr [esi]
// 00729e95  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00729e98  8d542414             lea edx, [esp + 0x14]
// 00729e9c  52                   push edx
// 00729e9d  51                   push ecx
// 00729e9e  ffd5                 call ebp
// 00729ea0  8b16                 mov edx, dword ptr [esi]
// 00729ea2  8b4254               mov eax, dword ptr [edx + 0x54]
// 00729ea5  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00729ea9  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00729ead  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00729eb1  a900a00000           test eax, 0xa000
// 00729eb6  742c                 je 0x729ee4
// 00729eb8  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00729ebc  83c3ec               add ebx, -0x14
// 00729ebf  3bda                 cmp ebx, edx
// 00729ec1  7d1d                 jge 0x729ee0
// 00729ec3  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00729ec7  83c314               add ebx, 0x14
// 00729eca  3bda                 cmp ebx, edx
// 00729ecc  7e12                 jle 0x729ee0
// 00729ece  8d5fec               lea ebx, [edi - 0x14]
// 00729ed1  3bd9                 cmp ebx, ecx
// 00729ed3  7d0b                 jge 0x729ee0
// 00729ed5  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00729ed9  83c314               add ebx, 0x14
// 00729edc  3bd9                 cmp ebx, ecx
// 00729ede  7f50                 jg 0x729f30
// 00729ee0  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00729ee4  a900500000           test eax, 0x5000
// 00729ee9  7428                 je 0x729f13
// 00729eeb  83c7ec               add edi, -0x14
// 00729eee  3bf9                 cmp edi, ecx
// 00729ef0  7d21                 jge 0x729f13
// 00729ef2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00729ef6  83c014               add eax, 0x14
// 00729ef9  3bc1                 cmp eax, ecx
// 00729efb  7e16                 jle 0x729f13
// 00729efd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00729f01  83c1ec               add ecx, -0x14
// 00729f04  3bca                 cmp ecx, edx
// 00729f06  7d0b                 jge 0x729f13
// 00729f08  8b442420             mov eax, dword ptr [esp + 0x20]
// 00729f0c  83c014               add eax, 0x14
// 00729f0f  3bc2                 cmp eax, edx
// 00729f11  7f36                 jg 0x729f49
// 00729f13  43                   inc ebx
// 00729f14  83c604               add esi, 4
// 00729f17  83fb04               cmp ebx, 4
// 00729f1a  895c2430             mov dword ptr [esp + 0x30], ebx
// 00729f1e  0f8c6fffffff         jl 0x729e93
// 00729f24  5f                   pop edi
// 00729f25  5e                   pop esi
// 00729f26  5d                   pop ebp
// 00729f27  33c0                 xor eax, eax
// 00729f29  5b                   pop ebx
// 00729f2a  83c414               add esp, 0x14
// 00729f2d  c20c00               ret 0xc
// 00729f30  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00729f34  8b542430             mov edx, dword ptr [esp + 0x30]
// 00729f38  8b849190000000       mov eax, dword ptr [ecx + edx*4 + 0x90]
// 00729f3f  5f                   pop edi
// 00729f40  5e                   pop esi
// 00729f41  5d                   pop ebp
// 00729f42  5b                   pop ebx
// 00729f43  83c414               add esp, 0x14
// 00729f46  c20c00               ret 0xc
// 00729f49  8b442410             mov eax, dword ptr [esp + 0x10]
// 00729f4d  8b849890000000       mov eax, dword ptr [eax + ebx*4 + 0x90]
// 00729f54  5f                   pop edi
// 00729f55  5e                   pop esi
// 00729f56  5d                   pop ebp
// 00729f57  5b                   pop ebx
// 00729f58  83c414               add esp, 0x14
// 00729f5b  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?CanDock@CXTPCommandBars@@QBEPAVCXTPDockBar@@VCPoint@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
