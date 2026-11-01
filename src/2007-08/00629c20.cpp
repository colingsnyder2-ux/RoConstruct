// from server: 100% by auto
// roc 2007-08 00629c20  unit: RBX::AssemblyStage  size: 576 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00629c20
//
// 00629c20  8b442408             mov eax, dword ptr [esp + 8]
// 00629c24  83f80e               cmp eax, 0xe
// 00629c27  0f87f5010000         ja 0x629e22
// 00629c2d  53                   push ebx
// 00629c2e  56                   push esi
// 00629c2f  57                   push edi
// 00629c30  ff2485249e6200       jmp dword ptr [eax*4 + 0x629e24]
// 00629c37  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00629c3b  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00629c3f  56                   push esi
// 00629c40  53                   push ebx
// 00629c41  e8baf3ffff           call 0x629000
// 00629c46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00629c4a  8b4714               mov eax, dword ptr [edi + 0x14]
// 00629c4d  50                   push eax
// 00629c4e  8d4e14               lea ecx, [esi + 0x14]
// 00629c51  51                   push ecx
// 00629c52  53                   push ebx
// 00629c53  e8c8ebffff           call 0x628820
// 00629c58  8b16                 mov edx, dword ptr [esi]
// 00629c5a  8917                 mov dword ptr [edi], edx
// 00629c5c  8b4604               mov eax, dword ptr [esi + 4]
// 00629c5f  894704               mov dword ptr [edi + 4], eax
// 00629c62  8b4e08               mov ecx, dword ptr [esi + 8]
// 00629c65  894f08               mov dword ptr [edi + 8], ecx
// 00629c68  8b560c               mov edx, dword ptr [esi + 0xc]
// 00629c6b  89570c               mov dword ptr [edi + 0xc], edx
// 00629c6e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00629c71  894710               mov dword ptr [edi + 0x10], eax
// 00629c74  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00629c77  83c414               add esp, 0x14
// 00629c7a  894f14               mov dword ptr [edi + 0x14], ecx
// 00629c7d  5f                   pop edi
// 00629c7e  5e                   pop esi
// 00629c7f  5b                   pop ebx
// 00629c80  c3                   ret 
// 00629c81  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00629c85  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00629c89  56                   push esi
// 00629c8a  53                   push ebx
// 00629c8b  e870f3ffff           call 0x629000
// 00629c90  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00629c94  8b5710               mov edx, dword ptr [edi + 0x10]
// 00629c97  52                   push edx
// 00629c98  8d4610               lea eax, [esi + 0x10]
// 00629c9b  50                   push eax
// 00629c9c  53                   push ebx
// 00629c9d  e87eebffff           call 0x628820
// 00629ca2  8b0e                 mov ecx, dword ptr [esi]
// 00629ca4  890f                 mov dword ptr [edi], ecx
// 00629ca6  8b5604               mov edx, dword ptr [esi + 4]
// 00629ca9  895704               mov dword ptr [edi + 4], edx
// 00629cac  8b4608               mov eax, dword ptr [esi + 8]
// 00629caf  894708               mov dword ptr [edi + 8], eax
// 00629cb2  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00629cb5  894f0c               mov dword ptr [edi + 0xc], ecx
// 00629cb8  8b5610               mov edx, dword ptr [esi + 0x10]
// 00629cbb  895710               mov dword ptr [edi + 0x10], edx
// 00629cbe  8b4614               mov eax, dword ptr [esi + 0x14]
// 00629cc1  83c414               add esp, 0x14
// 00629cc4  894714               mov dword ptr [edi + 0x14], eax
// 00629cc7  5f                   pop edi
// 00629cc8  5e                   pop esi
// 00629cc9  5b                   pop ebx
// 00629cca  c3                   ret 
// 00629ccb  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00629ccf  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629cd3  56                   push esi
// 00629cd4  57                   push edi
// 00629cd5  e886f7ffff           call 0x629460
// 00629cda  83c408               add esp, 8
// 00629cdd  833e0b               cmp dword ptr [esi], 0xb
// 00629ce0  754d                 jne 0x629d2f
// 00629ce2  8b0f                 mov ecx, dword ptr [edi]
// 00629ce4  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00629ce7  8b5608               mov edx, dword ptr [esi + 8]
// 00629cea  8b0c90               mov ecx, dword ptr [eax + edx*4]
// 00629ced  83e13f               and ecx, 0x3f
// 00629cf0  80f915               cmp cl, 0x15
// 00629cf3  753a                 jne 0x629d2f
// 00629cf5  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629cf9  8bc3                 mov eax, ebx
// 00629cfb  8bcf                 mov ecx, edi
// 00629cfd  e8eeebffff           call 0x6288f0
// 00629d02  8b17                 mov edx, dword ptr [edi]
// 00629d04  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 00629d07  8b4608               mov eax, dword ptr [esi + 8]
// 00629d0a  8b5308               mov edx, dword ptr [ebx + 8]
// 00629d0d  8d0481               lea eax, [ecx + eax*4]
// 00629d10  8b08                 mov ecx, dword ptr [eax]
// 00629d12  c1e217               shl edx, 0x17
// 00629d15  81e1ffff7f00         and ecx, 0x7fffff
// 00629d1b  0bd1                 or edx, ecx
// 00629d1d  8910                 mov dword ptr [eax], edx
// 00629d1f  c7030b000000         mov dword ptr [ebx], 0xb
// 00629d25  8b5608               mov edx, dword ptr [esi + 8]
// 00629d28  5f                   pop edi
// 00629d29  5e                   pop esi
// 00629d2a  895308               mov dword ptr [ebx + 8], edx
// 00629d2d  5b                   pop ebx
// 00629d2e  c3                   ret 
// 00629d2f  56                   push esi
// 00629d30  57                   push edi
// 00629d31  e85af6ffff           call 0x629390
// 00629d36  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00629d3a  56                   push esi
// 00629d3b  6a15                 push 0x15
// 00629d3d  e88efcffff           call 0x6299d0
// 00629d42  83c410               add esp, 0x10
// 00629d45  5f                   pop edi
// 00629d46  5e                   pop esi
// 00629d47  5b                   pop ebx
// 00629d48  c3                   ret 
// 00629d49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00629d4d  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629d51  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629d55  50                   push eax
// 00629d56  6a0c                 push 0xc
// 00629d58  e873fcffff           call 0x6299d0
// 00629d5d  83c408               add esp, 8
// 00629d60  5f                   pop edi
// 00629d61  5e                   pop esi
// 00629d62  5b                   pop ebx
// 00629d63  c3                   ret 
// 00629d64  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00629d68  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629d6c  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629d70  51                   push ecx
// 00629d71  6a0d                 push 0xd
// 00629d73  e858fcffff           call 0x6299d0
// 00629d78  83c408               add esp, 8
// 00629d7b  5f                   pop edi
// 00629d7c  5e                   pop esi
// 00629d7d  5b                   pop ebx
// 00629d7e  c3                   ret 
// 00629d7f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00629d83  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629d87  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629d8b  52                   push edx
// 00629d8c  6a0e                 push 0xe
// 00629d8e  e83dfcffff           call 0x6299d0
// 00629d93  83c408               add esp, 8
// 00629d96  5f                   pop edi
// 00629d97  5e                   pop esi
// 00629d98  5b                   pop ebx
// 00629d99  c3                   ret 
// 00629d9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00629d9e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629da2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629da6  50                   push eax
// 00629da7  6a0f                 push 0xf
// 00629da9  e822fcffff           call 0x6299d0
// 00629dae  83c408               add esp, 8
// 00629db1  5f                   pop edi
// 00629db2  5e                   pop esi
// 00629db3  5b                   pop ebx
// 00629db4  c3                   ret 
// 00629db5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00629db9  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629dbd  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629dc1  51                   push ecx
// 00629dc2  6a10                 push 0x10
// 00629dc4  e807fcffff           call 0x6299d0
// 00629dc9  83c408               add esp, 8
// 00629dcc  5f                   pop edi
// 00629dcd  5e                   pop esi
// 00629dce  5b                   pop ebx
// 00629dcf  c3                   ret 
// 00629dd0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00629dd4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00629dd8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00629ddc  52                   push edx
// 00629ddd  6a11                 push 0x11
// 00629ddf  e8ecfbffff           call 0x6299d0
// 00629de4  83c408               add esp, 8
// 00629de7  5f                   pop edi
// 00629de8  5e                   pop esi
// 00629de9  5b                   pop ebx
// 00629dea  c3                   ret 
// 00629deb  6a01                 push 1
// 00629ded  6a17                 push 0x17
// 00629def  eb1a                 jmp 0x629e0b
// 00629df1  6a00                 push 0
// 00629df3  6a17                 push 0x17
// 00629df5  eb14                 jmp 0x629e0b
// 00629df7  6a01                 push 1
// 00629df9  6a18                 push 0x18
// 00629dfb  eb0e                 jmp 0x629e0b
// 00629dfd  6a01                 push 1
// 00629dff  eb08                 jmp 0x629e09
// 00629e01  6a00                 push 0
// 00629e03  6a18                 push 0x18
// 00629e05  eb04                 jmp 0x629e0b
// 00629e07  6a00                 push 0
// 00629e09  6a19                 push 0x19
// 00629e0b  8b442424             mov eax, dword ptr [esp + 0x24]
// 00629e0f  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00629e13  8b742418             mov esi, dword ptr [esp + 0x18]
// 00629e17  e864fcffff           call 0x629a80
// 00629e1c  83c408               add esp, 8
// 00629e1f  5f                   pop edi
// 00629e20  5e                   pop esi
// 00629e21  5b                   pop ebx
// 00629e22  c3                   ret 
// 00629e23  90                   nop 
// 00629e24  49                   dec ecx
// 00629e25  9d                   popfd 
// 00629e26  6200                 bound eax, qword ptr [eax]
// 00629e28  649d                 popfd 
// 00629e2a  6200                 bound eax, qword ptr [eax]
// 00629e2c  7f9d                 jg 0x629dcb
// 00629e2e  6200                 bound eax, qword ptr [eax]
// 00629e30  9a9d6200b59d62       lcall 0x629d, 0xb500629d
// 00629e37  00d0                 add al, dl
// 00629e39  9d                   popfd 
// 00629e3a  6200                 bound eax, qword ptr [eax]
// 00629e3c  cb                   retf 
// 00629e3d  9c                   pushfd 
// 00629e3e  6200                 bound eax, qword ptr [eax]
// 00629e40  f1                   int1 
// 00629e41  9d                   popfd 
// 00629e42  6200                 bound eax, qword ptr [eax]
// 00629e44  eb9d                 jmp 0x629de3
// 00629e46  6200                 bound eax, qword ptr [eax]
// 00629e48  f79d6200fd9d         neg dword ptr [ebp - 0x6202ff9e]
// 00629e4e  6200                 bound eax, qword ptr [eax]
// 00629e50  019e6200079e         add dword ptr [esi - 0x61f8ff9e], ebx
// 00629e56  6200                 bound eax, qword ptr [eax]
// 00629e58  37                   aaa 
// 00629e59  9c                   pushfd 
// 00629e5a  6200                 bound eax, qword ptr [eax]
// library lua-5.1.1/lcode.c (function _luaK_posfix)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
