// from server: 100% by auto
// roc 2009-06 006ea940  unit: RBX::PartDropTool  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ea940
//
// 006ea940  55                   push ebp
// 006ea941  8bec                 mov ebp, esp
// 006ea943  83e4c0               and esp, 0xffffffc0
// 006ea946  83ec3c               sub esp, 0x3c
// 006ea949  53                   push ebx
// 006ea94a  8bd8                 mov ebx, eax
// 006ea94c  8b4608               mov eax, dword ptr [esi + 8]
// 006ea94f  b903000000           mov ecx, 3
// 006ea954  3bc1                 cmp eax, ecx
// 006ea956  7506                 jne 0x6ea95e
// 006ea958  89742418             mov dword ptr [esp + 0x18], esi
// 006ea95c  eb41                 jmp 0x6ea99f
// 006ea95e  83f804               cmp eax, 4
// 006ea961  0f8519010000         jne 0x6eaa80
// 006ea967  8b0e                 mov ecx, dword ptr [esi]
// 006ea969  8d442418             lea eax, [esp + 0x18]
// 006ea96d  50                   push eax
// 006ea96e  83c110               add ecx, 0x10
// 006ea971  51                   push ecx
// 006ea972  e839e3fdff           call 0x6c8cb0
// 006ea977  83c408               add esp, 8
// 006ea97a  85c0                 test eax, eax
// 006ea97c  0f84fe000000         je 0x6eaa80
// 006ea982  dd442418             fld qword ptr [esp + 0x18]
// 006ea986  8d542430             lea edx, [esp + 0x30]
// 006ea98a  dd5c2430             fstp qword ptr [esp + 0x30]
// 006ea98e  c744243803000000     mov dword ptr [esp + 0x38], 3
// 006ea996  89542418             mov dword ptr [esp + 0x18], edx
// 006ea99a  b903000000           mov ecx, 3
// 006ea99f  8b4308               mov eax, dword ptr [ebx + 8]
// 006ea9a2  3bc1                 cmp eax, ecx
// 006ea9a4  743d                 je 0x6ea9e3
// 006ea9a6  83f804               cmp eax, 4
// 006ea9a9  0f85d1000000         jne 0x6eaa80
// 006ea9af  8b0b                 mov ecx, dword ptr [ebx]
// 006ea9b1  8d442420             lea eax, [esp + 0x20]
// 006ea9b5  50                   push eax
// 006ea9b6  83c110               add ecx, 0x10
// 006ea9b9  51                   push ecx
// 006ea9ba  e8f1e2fdff           call 0x6c8cb0
// 006ea9bf  83c408               add esp, 8
// 006ea9c2  85c0                 test eax, eax
// 006ea9c4  0f84b6000000         je 0x6eaa80
// 006ea9ca  dd442420             fld qword ptr [esp + 0x20]
// 006ea9ce  c744242803000000     mov dword ptr [esp + 0x28], 3
// 006ea9d6  dd5c2420             fstp qword ptr [esp + 0x20]
// 006ea9da  8d5c2420             lea ebx, [esp + 0x20]
// 006ea9de  b903000000           mov ecx, 3
// 006ea9e3  8b542418             mov edx, dword ptr [esp + 0x18]
// 006ea9e7  dd02                 fld qword ptr [edx]
// 006ea9e9  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006ea9ec  dd542418             fst qword ptr [esp + 0x18]
// 006ea9f0  83c0fb               add eax, -5
// 006ea9f3  dd03                 fld qword ptr [ebx]
// 006ea9f5  dd542420             fst qword ptr [esp + 0x20]
// 006ea9f9  83f806               cmp eax, 6
// 006ea9fc  0f87d7000000         ja 0x6eaad9
// 006eaa02  ff2485e4aa6e00       jmp dword ptr [eax*4 + 0x6eaae4]
// 006eaa09  dec1                 faddp st(1)
// 006eaa0b  894f08               mov dword ptr [edi + 8], ecx
// 006eaa0e  dd1f                 fstp qword ptr [edi]
// 006eaa10  5b                   pop ebx
// 006eaa11  8be5                 mov esp, ebp
// 006eaa13  5d                   pop ebp
// 006eaa14  c3                   ret 
// 006eaa15  dee9                 fsubp st(1)
// 006eaa17  894f08               mov dword ptr [edi + 8], ecx
// 006eaa1a  dd1f                 fstp qword ptr [edi]
// 006eaa1c  5b                   pop ebx
// 006eaa1d  8be5                 mov esp, ebp
// 006eaa1f  5d                   pop ebp
// 006eaa20  c3                   ret 
// 006eaa21  dec9                 fmulp st(1)
// 006eaa23  894f08               mov dword ptr [edi + 8], ecx
// 006eaa26  dd1f                 fstp qword ptr [edi]
// 006eaa28  5b                   pop ebx
// 006eaa29  8be5                 mov esp, ebp
// 006eaa2b  5d                   pop ebp
// 006eaa2c  c3                   ret 
// 006eaa2d  def9                 fdivp st(1)
// 006eaa2f  894f08               mov dword ptr [edi + 8], ecx
// 006eaa32  dd1f                 fstp qword ptr [edi]
// 006eaa34  5b                   pop ebx
// 006eaa35  8be5                 mov esp, ebp
// 006eaa37  5d                   pop ebp
// 006eaa38  c3                   ret 
// 006eaa39  def9                 fdivp st(1)
// 006eaa3b  83ec08               sub esp, 8
// 006eaa3e  dd1c24               fstp qword ptr [esp]
// 006eaa41  e83af80200           call 0x71a280
// 006eaa46  dc4c2428             fmul qword ptr [esp + 0x28]
// 006eaa4a  83c408               add esp, 8
// 006eaa4d  c7470803000000       mov dword ptr [edi + 8], 3
// 006eaa54  dc6c2418             fsubr qword ptr [esp + 0x18]
// 006eaa58  dd1f                 fstp qword ptr [edi]
// 006eaa5a  5b                   pop ebx
// 006eaa5b  8be5                 mov esp, ebp
// 006eaa5d  5d                   pop ebp
// 006eaa5e  c3                   ret 
// 006eaa5f  e88cf80200           call 0x71a2f0
// 006eaa64  dd1f                 fstp qword ptr [edi]
// 006eaa66  c7470803000000       mov dword ptr [edi + 8], 3
// 006eaa6d  5b                   pop ebx
// 006eaa6e  8be5                 mov esp, ebp
// 006eaa70  5d                   pop ebp
// 006eaa71  c3                   ret 
// 006eaa72  ddd8                 fstp st(0)
// 006eaa74  894f08               mov dword ptr [edi + 8], ecx
// 006eaa77  d9e0                 fchs 
// 006eaa79  dd1f                 fstp qword ptr [edi]
// 006eaa7b  5b                   pop ebx
// 006eaa7c  8be5                 mov esp, ebp
// 006eaa7e  5d                   pop ebp
// 006eaa7f  c3                   ret 
// 006eaa80  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006eaa83  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006eaa86  50                   push eax
// 006eaa87  56                   push esi
// 006eaa88  51                   push ecx
// 006eaa89  e8a2f3ffff           call 0x6e9e30
// 006eaa8e  83c40c               add esp, 0xc
// 006eaa91  83780800             cmp dword ptr [eax + 8], 0
// 006eaa95  7517                 jne 0x6eaaae
// 006eaa97  8b550c               mov edx, dword ptr [ebp + 0xc]
// 006eaa9a  8b4508               mov eax, dword ptr [ebp + 8]
// 006eaa9d  52                   push edx
// 006eaa9e  53                   push ebx
// 006eaa9f  50                   push eax
// 006eaaa0  e88bf3ffff           call 0x6e9e30
// 006eaaa5  83c40c               add esp, 0xc
// 006eaaa8  83780800             cmp dword ptr [eax + 8], 0
// 006eaaac  7418                 je 0x6eaac6
// 006eaaae  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006eaab1  50                   push eax
// 006eaab2  51                   push ecx
// 006eaab3  8bcb                 mov ecx, ebx
// 006eaab5  8bd6                 mov edx, esi
// 006eaab7  8bc7                 mov eax, edi
// 006eaab9  e822f5ffff           call 0x6e9fe0
// 006eaabe  83c408               add esp, 8
// 006eaac1  5b                   pop ebx
// 006eaac2  8be5                 mov esp, ebp
// 006eaac4  5d                   pop ebp
// 006eaac5  c3                   ret 
// 006eaac6  8b5508               mov edx, dword ptr [ebp + 8]
// 006eaac9  53                   push ebx
// 006eaaca  56                   push esi
// 006eaacb  52                   push edx
// 006eaacc  e85fe0fdff           call 0x6c8b30
// 006eaad1  83c40c               add esp, 0xc
// 006eaad4  5b                   pop ebx
// 006eaad5  8be5                 mov esp, ebp
// 006eaad7  5d                   pop ebp
// 006eaad8  c3                   ret 
// 006eaad9  ddd8                 fstp st(0)
// 006eaadb  5b                   pop ebx
// 006eaadc  ddd8                 fstp st(0)
// 006eaade  8be5                 mov esp, ebp
// 006eaae0  5d                   pop ebp
// 006eaae1  c3                   ret 
// 006eaae2  8bff                 mov edi, edi
// 006eaae4  09aa6e0015aa         or dword ptr [edx - 0x55eaff92], ebp
// 006eaaea  6e                   outsb dx, byte ptr [esi]
// 006eaaeb  0021                 add byte ptr [ecx], ah
// 006eaaed  aa                   stosb byte ptr es:[edi], al
// 006eaaee  6e                   outsb dx, byte ptr [esi]
// 006eaaef  002daa6e0039         add byte ptr [0x39006eaa], ch
// 006eaaf5  aa                   stosb byte ptr es:[edi], al
// 006eaaf6  6e                   outsb dx, byte ptr [esi]
// 006eaaf7  005faa               add byte ptr [edi - 0x56], bl
// 006eaafa  6e                   outsb dx, byte ptr [esi]
// 006eaafb  0072aa               add byte ptr [edx - 0x56], dh
// 006eaafe  6e                   outsb dx, byte ptr [esi]
// library lua-5.1.2/lvm.c (function _Arith)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lvm.c
