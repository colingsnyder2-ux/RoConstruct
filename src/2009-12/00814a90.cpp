// from server: 100% by auto
// roc 2009-12 00814a90  unit: PAVCXTPCommandBarKeyboardTip::?$CArray  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814a90
//
// 00814a90  83ec14               sub esp, 0x14
// 00814a93  53                   push ebx
// 00814a94  55                   push ebp
// 00814a95  8b2d70cc9800         mov ebp, dword ptr [0x98cc70]
// 00814a9b  56                   push esi
// 00814a9c  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00814aa0  57                   push edi
// 00814aa1  894c2410             mov dword ptr [esp + 0x10], ecx
// 00814aa5  85f6                 test esi, esi
// 00814aa7  0f8486000000         je 0x814b33
// 00814aad  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00814ab0  8d442414             lea eax, [esp + 0x14]
// 00814ab4  50                   push eax
// 00814ab5  51                   push ecx
// 00814ab6  ffd5                 call ebp
// 00814ab8  8b4654               mov eax, dword ptr [esi + 0x54]
// 00814abb  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00814abf  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00814ac3  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00814ac7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00814acb  a900a00000           test eax, 0xa000
// 00814ad0  7436                 je 0x814b08
// 00814ad2  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00814ad6  83c5ec               add ebp, -0x14
// 00814ad9  3bea                 cmp ebp, edx
// 00814adb  7d25                 jge 0x814b02
// 00814add  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00814ae1  83c514               add ebp, 0x14
// 00814ae4  3bea                 cmp ebp, edx
// 00814ae6  7e1a                 jle 0x814b02
// 00814ae8  8d6fec               lea ebp, [edi - 0x14]
// 00814aeb  3be9                 cmp ebp, ecx
// 00814aed  7d13                 jge 0x814b02
// 00814aef  8d6b14               lea ebp, [ebx + 0x14]
// 00814af2  3be9                 cmp ebp, ecx
// 00814af4  7e0c                 jle 0x814b02
// 00814af6  5f                   pop edi
// 00814af7  8bc6                 mov eax, esi
// 00814af9  5e                   pop esi
// 00814afa  5d                   pop ebp
// 00814afb  5b                   pop ebx
// 00814afc  83c414               add esp, 0x14
// 00814aff  c20c00               ret 0xc
// 00814b02  8b2d70cc9800         mov ebp, dword ptr [0x98cc70]
// 00814b08  a900500000           test eax, 0x5000
// 00814b0d  7424                 je 0x814b33
// 00814b0f  83c7ec               add edi, -0x14
// 00814b12  3bf9                 cmp edi, ecx
// 00814b14  7d1d                 jge 0x814b33
// 00814b16  83c314               add ebx, 0x14
// 00814b19  3bd9                 cmp ebx, ecx
// 00814b1b  7e16                 jle 0x814b33
// 00814b1d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00814b21  83c0ec               add eax, -0x14
// 00814b24  3bc2                 cmp eax, edx
// 00814b26  7d0b                 jge 0x814b33
// 00814b28  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00814b2c  83c114               add ecx, 0x14
// 00814b2f  3bca                 cmp ecx, edx
// 00814b31  7fc3                 jg 0x814af6
// 00814b33  8b742410             mov esi, dword ptr [esp + 0x10]
// 00814b37  33db                 xor ebx, ebx
// 00814b39  895c2430             mov dword ptr [esp + 0x30], ebx
// 00814b3d  81c690000000         add esi, 0x90
// 00814b43  8b06                 mov eax, dword ptr [esi]
// 00814b45  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00814b48  8d542414             lea edx, [esp + 0x14]
// 00814b4c  52                   push edx
// 00814b4d  51                   push ecx
// 00814b4e  ffd5                 call ebp
// 00814b50  8b16                 mov edx, dword ptr [esi]
// 00814b52  8b4254               mov eax, dword ptr [edx + 0x54]
// 00814b55  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00814b59  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00814b5d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00814b61  a900a00000           test eax, 0xa000
// 00814b66  742c                 je 0x814b94
// 00814b68  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00814b6c  83c3ec               add ebx, -0x14
// 00814b6f  3bda                 cmp ebx, edx
// 00814b71  7d1d                 jge 0x814b90
// 00814b73  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00814b77  83c314               add ebx, 0x14
// 00814b7a  3bda                 cmp ebx, edx
// 00814b7c  7e12                 jle 0x814b90
// 00814b7e  8d5fec               lea ebx, [edi - 0x14]
// 00814b81  3bd9                 cmp ebx, ecx
// 00814b83  7d0b                 jge 0x814b90
// 00814b85  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00814b89  83c314               add ebx, 0x14
// 00814b8c  3bd9                 cmp ebx, ecx
// 00814b8e  7f50                 jg 0x814be0
// 00814b90  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00814b94  a900500000           test eax, 0x5000
// 00814b99  7428                 je 0x814bc3
// 00814b9b  83c7ec               add edi, -0x14
// 00814b9e  3bf9                 cmp edi, ecx
// 00814ba0  7d21                 jge 0x814bc3
// 00814ba2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00814ba6  83c014               add eax, 0x14
// 00814ba9  3bc1                 cmp eax, ecx
// 00814bab  7e16                 jle 0x814bc3
// 00814bad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00814bb1  83c1ec               add ecx, -0x14
// 00814bb4  3bca                 cmp ecx, edx
// 00814bb6  7d0b                 jge 0x814bc3
// 00814bb8  8b442420             mov eax, dword ptr [esp + 0x20]
// 00814bbc  83c014               add eax, 0x14
// 00814bbf  3bc2                 cmp eax, edx
// 00814bc1  7f36                 jg 0x814bf9
// 00814bc3  43                   inc ebx
// 00814bc4  83c604               add esi, 4
// 00814bc7  83fb04               cmp ebx, 4
// 00814bca  895c2430             mov dword ptr [esp + 0x30], ebx
// 00814bce  0f8c6fffffff         jl 0x814b43
// 00814bd4  5f                   pop edi
// 00814bd5  5e                   pop esi
// 00814bd6  5d                   pop ebp
// 00814bd7  33c0                 xor eax, eax
// 00814bd9  5b                   pop ebx
// 00814bda  83c414               add esp, 0x14
// 00814bdd  c20c00               ret 0xc
// 00814be0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00814be4  8b542430             mov edx, dword ptr [esp + 0x30]
// 00814be8  8b849190000000       mov eax, dword ptr [ecx + edx*4 + 0x90]
// 00814bef  5f                   pop edi
// 00814bf0  5e                   pop esi
// 00814bf1  5d                   pop ebp
// 00814bf2  5b                   pop ebx
// 00814bf3  83c414               add esp, 0x14
// 00814bf6  c20c00               ret 0xc
// 00814bf9  8b442410             mov eax, dword ptr [esp + 0x10]
// 00814bfd  8b849890000000       mov eax, dword ptr [eax + ebx*4 + 0x90]
// 00814c04  5f                   pop edi
// 00814c05  5e                   pop esi
// 00814c06  5d                   pop ebp
// 00814c07  5b                   pop ebx
// 00814c08  83c414               add esp, 0x14
// 00814c0b  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?CanDock@CXTPCommandBars@@QBEPAVCXTPDockBar@@VCPoint@@PAV2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
