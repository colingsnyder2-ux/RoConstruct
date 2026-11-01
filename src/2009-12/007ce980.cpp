// from server: 100% by auto
// roc 2009-12 007ce980  unit: RBX::PartDropTool  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ce980
//
// 007ce980  55                   push ebp
// 007ce981  8bec                 mov ebp, esp
// 007ce983  83e4c0               and esp, 0xffffffc0
// 007ce986  83ec3c               sub esp, 0x3c
// 007ce989  53                   push ebx
// 007ce98a  8bd8                 mov ebx, eax
// 007ce98c  8b4608               mov eax, dword ptr [esi + 8]
// 007ce98f  b903000000           mov ecx, 3
// 007ce994  3bc1                 cmp eax, ecx
// 007ce996  7506                 jne 0x7ce99e
// 007ce998  89742418             mov dword ptr [esp + 0x18], esi
// 007ce99c  eb41                 jmp 0x7ce9df
// 007ce99e  83f804               cmp eax, 4
// 007ce9a1  0f8519010000         jne 0x7ceac0
// 007ce9a7  8b0e                 mov ecx, dword ptr [esi]
// 007ce9a9  8d442418             lea eax, [esp + 0x18]
// 007ce9ad  50                   push eax
// 007ce9ae  83c110               add ecx, 0x10
// 007ce9b1  51                   push ecx
// 007ce9b2  e8d9b7fcff           call 0x79a190
// 007ce9b7  83c408               add esp, 8
// 007ce9ba  85c0                 test eax, eax
// 007ce9bc  0f84fe000000         je 0x7ceac0
// 007ce9c2  dd442418             fld qword ptr [esp + 0x18]
// 007ce9c6  8d542430             lea edx, [esp + 0x30]
// 007ce9ca  dd5c2430             fstp qword ptr [esp + 0x30]
// 007ce9ce  c744243803000000     mov dword ptr [esp + 0x38], 3
// 007ce9d6  89542418             mov dword ptr [esp + 0x18], edx
// 007ce9da  b903000000           mov ecx, 3
// 007ce9df  8b4308               mov eax, dword ptr [ebx + 8]
// 007ce9e2  3bc1                 cmp eax, ecx
// 007ce9e4  743d                 je 0x7cea23
// 007ce9e6  83f804               cmp eax, 4
// 007ce9e9  0f85d1000000         jne 0x7ceac0
// 007ce9ef  8b0b                 mov ecx, dword ptr [ebx]
// 007ce9f1  8d442420             lea eax, [esp + 0x20]
// 007ce9f5  50                   push eax
// 007ce9f6  83c110               add ecx, 0x10
// 007ce9f9  51                   push ecx
// 007ce9fa  e891b7fcff           call 0x79a190
// 007ce9ff  83c408               add esp, 8
// 007cea02  85c0                 test eax, eax
// 007cea04  0f84b6000000         je 0x7ceac0
// 007cea0a  dd442420             fld qword ptr [esp + 0x20]
// 007cea0e  c744242803000000     mov dword ptr [esp + 0x28], 3
// 007cea16  dd5c2420             fstp qword ptr [esp + 0x20]
// 007cea1a  8d5c2420             lea ebx, [esp + 0x20]
// 007cea1e  b903000000           mov ecx, 3
// 007cea23  8b542418             mov edx, dword ptr [esp + 0x18]
// 007cea27  dd02                 fld qword ptr [edx]
// 007cea29  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007cea2c  dd542418             fst qword ptr [esp + 0x18]
// 007cea30  83c0fb               add eax, -5
// 007cea33  dd03                 fld qword ptr [ebx]
// 007cea35  dd542420             fst qword ptr [esp + 0x20]
// 007cea39  83f806               cmp eax, 6
// 007cea3c  0f87d7000000         ja 0x7ceb19
// 007cea42  ff248524eb7c00       jmp dword ptr [eax*4 + 0x7ceb24]
// 007cea49  dec1                 faddp st(1)
// 007cea4b  894f08               mov dword ptr [edi + 8], ecx
// 007cea4e  dd1f                 fstp qword ptr [edi]
// 007cea50  5b                   pop ebx
// 007cea51  8be5                 mov esp, ebp
// 007cea53  5d                   pop ebp
// 007cea54  c3                   ret 
// 007cea55  dee9                 fsubp st(1)
// 007cea57  894f08               mov dword ptr [edi + 8], ecx
// 007cea5a  dd1f                 fstp qword ptr [edi]
// 007cea5c  5b                   pop ebx
// 007cea5d  8be5                 mov esp, ebp
// 007cea5f  5d                   pop ebp
// 007cea60  c3                   ret 
// 007cea61  dec9                 fmulp st(1)
// 007cea63  894f08               mov dword ptr [edi + 8], ecx
// 007cea66  dd1f                 fstp qword ptr [edi]
// 007cea68  5b                   pop ebx
// 007cea69  8be5                 mov esp, ebp
// 007cea6b  5d                   pop ebp
// 007cea6c  c3                   ret 
// 007cea6d  def9                 fdivp st(1)
// 007cea6f  894f08               mov dword ptr [edi + 8], ecx
// 007cea72  dd1f                 fstp qword ptr [edi]
// 007cea74  5b                   pop ebx
// 007cea75  8be5                 mov esp, ebp
// 007cea77  5d                   pop ebp
// 007cea78  c3                   ret 
// 007cea79  def9                 fdivp st(1)
// 007cea7b  83ec08               sub esp, 8
// 007cea7e  dd1c24               fstp qword ptr [esp]
// 007cea81  e830660200           call 0x7f50b6
// 007cea86  dc4c2428             fmul qword ptr [esp + 0x28]
// 007cea8a  83c408               add esp, 8
// 007cea8d  c7470803000000       mov dword ptr [edi + 8], 3
// 007cea94  dc6c2418             fsubr qword ptr [esp + 0x18]
// 007cea98  dd1f                 fstp qword ptr [edi]
// 007cea9a  5b                   pop ebx
// 007cea9b  8be5                 mov esp, ebp
// 007cea9d  5d                   pop ebp
// 007cea9e  c3                   ret 
// 007cea9f  e80c660200           call 0x7f50b0
// 007ceaa4  dd1f                 fstp qword ptr [edi]
// 007ceaa6  c7470803000000       mov dword ptr [edi + 8], 3
// 007ceaad  5b                   pop ebx
// 007ceaae  8be5                 mov esp, ebp
// 007ceab0  5d                   pop ebp
// 007ceab1  c3                   ret 
// 007ceab2  ddd8                 fstp st(0)
// 007ceab4  894f08               mov dword ptr [edi + 8], ecx
// 007ceab7  d9e0                 fchs 
// 007ceab9  dd1f                 fstp qword ptr [edi]
// 007ceabb  5b                   pop ebx
// 007ceabc  8be5                 mov esp, ebp
// 007ceabe  5d                   pop ebp
// 007ceabf  c3                   ret 
// 007ceac0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 007ceac3  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007ceac6  50                   push eax
// 007ceac7  56                   push esi
// 007ceac8  51                   push ecx
// 007ceac9  e8b2f3ffff           call 0x7cde80
// 007ceace  83c40c               add esp, 0xc
// 007cead1  83780800             cmp dword ptr [eax + 8], 0
// 007cead5  7517                 jne 0x7ceaee
// 007cead7  8b550c               mov edx, dword ptr [ebp + 0xc]
// 007ceada  8b4508               mov eax, dword ptr [ebp + 8]
// 007ceadd  52                   push edx
// 007ceade  53                   push ebx
// 007ceadf  50                   push eax
// 007ceae0  e89bf3ffff           call 0x7cde80
// 007ceae5  83c40c               add esp, 0xc
// 007ceae8  83780800             cmp dword ptr [eax + 8], 0
// 007ceaec  7418                 je 0x7ceb06
// 007ceaee  8b4d08               mov ecx, dword ptr [ebp + 8]
// 007ceaf1  50                   push eax
// 007ceaf2  51                   push ecx
// 007ceaf3  8bcb                 mov ecx, ebx
// 007ceaf5  8bd6                 mov edx, esi
// 007ceaf7  8bc7                 mov eax, edi
// 007ceaf9  e832f5ffff           call 0x7ce030
// 007ceafe  83c408               add esp, 8
// 007ceb01  5b                   pop ebx
// 007ceb02  8be5                 mov esp, ebp
// 007ceb04  5d                   pop ebp
// 007ceb05  c3                   ret 
// 007ceb06  8b5508               mov edx, dword ptr [ebp + 8]
// 007ceb09  53                   push ebx
// 007ceb0a  56                   push esi
// 007ceb0b  52                   push edx
// 007ceb0c  e81fcbfcff           call 0x79b630
// 007ceb11  83c40c               add esp, 0xc
// 007ceb14  5b                   pop ebx
// 007ceb15  8be5                 mov esp, ebp
// 007ceb17  5d                   pop ebp
// 007ceb18  c3                   ret 
// 007ceb19  ddd8                 fstp st(0)
// 007ceb1b  5b                   pop ebx
// 007ceb1c  ddd8                 fstp st(0)
// 007ceb1e  8be5                 mov esp, ebp
// 007ceb20  5d                   pop ebp
// 007ceb21  c3                   ret 
// 007ceb22  8bff                 mov edi, edi
// 007ceb24  49                   dec ecx
// 007ceb25  ea7c0055ea7c00       ljmp 0x7c:0xea55007c
// 007ceb2c  61                   popal 
// 007ceb2d  ea7c006dea7c00       ljmp 0x7c:0xea6d007c
// 007ceb34  79ea                 jns 0x7ceb20
// 007ceb36  7c00                 jl 0x7ceb38
// 007ceb38  9f                   lahf 
// 007ceb39  ea7c00b2ea7c00       ljmp 0x7c:0xeab2007c
// library lua-5.1.2/lvm.c (function _Arith)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lvm.c
