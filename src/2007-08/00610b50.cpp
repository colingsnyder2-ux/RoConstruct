// from server: 100% by auto
// roc 2007-08 00610b50  unit: RBX::Ball  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00610b50
//
// 00610b50  55                   push ebp
// 00610b51  8bec                 mov ebp, esp
// 00610b53  83e4c0               and esp, 0xffffffc0
// 00610b56  83ec3c               sub esp, 0x3c
// 00610b59  53                   push ebx
// 00610b5a  8bd8                 mov ebx, eax
// 00610b5c  8b4608               mov eax, dword ptr [esi + 8]
// 00610b5f  b903000000           mov ecx, 3
// 00610b64  3bc1                 cmp eax, ecx
// 00610b66  7506                 jne 0x610b6e
// 00610b68  89742418             mov dword ptr [esp + 0x18], esi
// 00610b6c  eb41                 jmp 0x610baf
// 00610b6e  83f804               cmp eax, 4
// 00610b71  0f8519010000         jne 0x610c90
// 00610b77  8b0e                 mov ecx, dword ptr [esi]
// 00610b79  8d442418             lea eax, [esp + 0x18]
// 00610b7d  50                   push eax
// 00610b7e  83c110               add ecx, 0x10
// 00610b81  51                   push ecx
// 00610b82  e859dfffff           call 0x60eae0
// 00610b87  83c408               add esp, 8
// 00610b8a  85c0                 test eax, eax
// 00610b8c  0f84fe000000         je 0x610c90
// 00610b92  dd442418             fld qword ptr [esp + 0x18]
// 00610b96  8d542430             lea edx, [esp + 0x30]
// 00610b9a  dd5c2430             fstp qword ptr [esp + 0x30]
// 00610b9e  c744243803000000     mov dword ptr [esp + 0x38], 3
// 00610ba6  89542418             mov dword ptr [esp + 0x18], edx
// 00610baa  b903000000           mov ecx, 3
// 00610baf  8b4308               mov eax, dword ptr [ebx + 8]
// 00610bb2  3bc1                 cmp eax, ecx
// 00610bb4  743d                 je 0x610bf3
// 00610bb6  83f804               cmp eax, 4
// 00610bb9  0f85d1000000         jne 0x610c90
// 00610bbf  8b0b                 mov ecx, dword ptr [ebx]
// 00610bc1  8d442420             lea eax, [esp + 0x20]
// 00610bc5  50                   push eax
// 00610bc6  83c110               add ecx, 0x10
// 00610bc9  51                   push ecx
// 00610bca  e811dfffff           call 0x60eae0
// 00610bcf  83c408               add esp, 8
// 00610bd2  85c0                 test eax, eax
// 00610bd4  0f84b6000000         je 0x610c90
// 00610bda  dd442420             fld qword ptr [esp + 0x20]
// 00610bde  c744242803000000     mov dword ptr [esp + 0x28], 3
// 00610be6  dd5c2420             fstp qword ptr [esp + 0x20]
// 00610bea  8d5c2420             lea ebx, [esp + 0x20]
// 00610bee  b903000000           mov ecx, 3
// 00610bf3  8b542418             mov edx, dword ptr [esp + 0x18]
// 00610bf7  dd02                 fld qword ptr [edx]
// 00610bf9  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00610bfc  dd542418             fst qword ptr [esp + 0x18]
// 00610c00  83c0fb               add eax, -5
// 00610c03  83f806               cmp eax, 6
// 00610c06  dd03                 fld qword ptr [ebx]
// 00610c08  dd542420             fst qword ptr [esp + 0x20]
// 00610c0c  0f87d7000000         ja 0x610ce9
// 00610c12  ff2485f40c6100       jmp dword ptr [eax*4 + 0x610cf4]
// 00610c19  dec1                 faddp st(1)
// 00610c1b  894f08               mov dword ptr [edi + 8], ecx
// 00610c1e  dd1f                 fstp qword ptr [edi]
// 00610c20  5b                   pop ebx
// 00610c21  8be5                 mov esp, ebp
// 00610c23  5d                   pop ebp
// 00610c24  c3                   ret 
// 00610c25  dee9                 fsubp st(1)
// 00610c27  894f08               mov dword ptr [edi + 8], ecx
// 00610c2a  dd1f                 fstp qword ptr [edi]
// 00610c2c  5b                   pop ebx
// 00610c2d  8be5                 mov esp, ebp
// 00610c2f  5d                   pop ebp
// 00610c30  c3                   ret 
// 00610c31  dec9                 fmulp st(1)
// 00610c33  894f08               mov dword ptr [edi + 8], ecx
// 00610c36  dd1f                 fstp qword ptr [edi]
// 00610c38  5b                   pop ebx
// 00610c39  8be5                 mov esp, ebp
// 00610c3b  5d                   pop ebp
// 00610c3c  c3                   ret 
// 00610c3d  def9                 fdivp st(1)
// 00610c3f  894f08               mov dword ptr [edi + 8], ecx
// 00610c42  dd1f                 fstp qword ptr [edi]
// 00610c44  5b                   pop ebx
// 00610c45  8be5                 mov esp, ebp
// 00610c47  5d                   pop ebp
// 00610c48  c3                   ret 
// 00610c49  def9                 fdivp st(1)
// 00610c4b  83ec08               sub esp, 8
// 00610c4e  dd1c24               fstp qword ptr [esp]
// 00610c51  e8d2040200           call 0x631128
// 00610c56  dc4c2428             fmul qword ptr [esp + 0x28]
// 00610c5a  83c408               add esp, 8
// 00610c5d  c7470803000000       mov dword ptr [edi + 8], 3
// 00610c64  dc6c2418             fsubr qword ptr [esp + 0x18]
// 00610c68  dd1f                 fstp qword ptr [edi]
// 00610c6a  5b                   pop ebx
// 00610c6b  8be5                 mov esp, ebp
// 00610c6d  5d                   pop ebp
// 00610c6e  c3                   ret 
// 00610c6f  e82a050200           call 0x63119e
// 00610c74  dd1f                 fstp qword ptr [edi]
// 00610c76  c7470803000000       mov dword ptr [edi + 8], 3
// 00610c7d  5b                   pop ebx
// 00610c7e  8be5                 mov esp, ebp
// 00610c80  5d                   pop ebp
// 00610c81  c3                   ret 
// 00610c82  ddd8                 fstp st(0)
// 00610c84  894f08               mov dword ptr [edi + 8], ecx
// 00610c87  d9e0                 fchs 
// 00610c89  dd1f                 fstp qword ptr [edi]
// 00610c8b  5b                   pop ebx
// 00610c8c  8be5                 mov esp, ebp
// 00610c8e  5d                   pop ebp
// 00610c8f  c3                   ret 
// 00610c90  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00610c93  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00610c96  50                   push eax
// 00610c97  56                   push esi
// 00610c98  51                   push ecx
// 00610c99  e8d2f3ffff           call 0x610070
// 00610c9e  83c40c               add esp, 0xc
// 00610ca1  83780800             cmp dword ptr [eax + 8], 0
// 00610ca5  7511                 jne 0x610cb8
// 00610ca7  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00610caa  8b4508               mov eax, dword ptr [ebp + 8]
// 00610cad  52                   push edx
// 00610cae  53                   push ebx
// 00610caf  50                   push eax
// 00610cb0  e8bbf3ffff           call 0x610070
// 00610cb5  83c40c               add esp, 0xc
// 00610cb8  83780806             cmp dword ptr [eax + 8], 6
// 00610cbc  7518                 jne 0x610cd6
// 00610cbe  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00610cc1  50                   push eax
// 00610cc2  51                   push ecx
// 00610cc3  8bcb                 mov ecx, ebx
// 00610cc5  8bd6                 mov edx, esi
// 00610cc7  8bc7                 mov eax, edi
// 00610cc9  e852f5ffff           call 0x610220
// 00610cce  83c408               add esp, 8
// 00610cd1  5b                   pop ebx
// 00610cd2  8be5                 mov esp, ebp
// 00610cd4  5d                   pop ebp
// 00610cd5  c3                   ret 
// 00610cd6  8b5508               mov edx, dword ptr [ebp + 8]
// 00610cd9  53                   push ebx
// 00610cda  56                   push esi
// 00610cdb  52                   push edx
// 00610cdc  e8ff65fbff           call 0x5c72e0
// 00610ce1  83c40c               add esp, 0xc
// 00610ce4  5b                   pop ebx
// 00610ce5  8be5                 mov esp, ebp
// 00610ce7  5d                   pop ebp
// 00610ce8  c3                   ret 
// 00610ce9  ddd8                 fstp st(0)
// 00610ceb  5b                   pop ebx
// 00610cec  ddd8                 fstp st(0)
// 00610cee  8be5                 mov esp, ebp
// 00610cf0  5d                   pop ebp
// 00610cf1  c3                   ret 
// 00610cf2  8bff                 mov edi, edi
// 00610cf4  190c61               sbb dword ptr [ecx], ecx
// 00610cf7  00250c610031         add byte ptr [0x3100610c], ah
// 00610cfd  0c61                 or al, 0x61
// 00610cff  003d0c610049         add byte ptr [0x4900610c], bh
// 00610d05  0c61                 or al, 0x61
// 00610d07  006f0c               add byte ptr [edi + 0xc], ch
// 00610d0a  61                   popal 
// library lua-5.1/lvm.c (function _Arith)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
