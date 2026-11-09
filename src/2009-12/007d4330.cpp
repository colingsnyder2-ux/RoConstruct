// from server: 100% by auto
// roc 2009-12 007d4330  unit: seg_007d0000  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4330
//
// 007d4330  83ec18               sub esp, 0x18
// 007d4333  53                   push ebx
// 007d4334  56                   push esi
// 007d4335  8bf0                 mov esi, eax
// 007d4337  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 007d433a  56                   push esi
// 007d433b  e8f0230000           call 0x7d6730
// 007d4340  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007d4343  8d81fcfeffff         lea eax, [ecx - 0x104]
// 007d4349  83c404               add esp, 4
// 007d434c  83f81b               cmp eax, 0x1b
// 007d434f  770e                 ja 0x7d435f
// 007d4351  0fb68034447d00       movzx eax, byte ptr [eax + 0x7d4434]
// 007d4358  ff24852c447d00       jmp dword ptr [eax*4 + 0x7d442c]
// 007d435f  83f93b               cmp ecx, 0x3b
// 007d4362  0f84ad000000         je 0x7d4415
// 007d4368  57                   push edi
// 007d4369  8d7c240c             lea edi, [esp + 0xc]
// 007d436d  e8cee4ffff           call 0x7d2840
// 007d4372  8bf0                 mov esi, eax
// 007d4374  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d4378  5f                   pop edi
// 007d4379  83f80d               cmp eax, 0xd
// 007d437c  744c                 je 0x7d43ca
// 007d437e  83f80e               cmp eax, 0xe
// 007d4381  7447                 je 0x7d43ca
// 007d4383  83fe01               cmp esi, 1
// 007d4386  751f                 jne 0x7d43a7
// 007d4388  8d4c2408             lea ecx, [esp + 8]
// 007d438c  51                   push ecx
// 007d438d  53                   push ebx
// 007d438e  e8fd880000           call 0x7dcc90
// 007d4393  83c408               add esp, 8
// 007d4396  56                   push esi
// 007d4397  50                   push eax
// 007d4398  53                   push ebx
// 007d4399  e832840000           call 0x7dc7d0
// 007d439e  83c40c               add esp, 0xc
// 007d43a1  5e                   pop esi
// 007d43a2  5b                   pop ebx
// 007d43a3  83c418               add esp, 0x18
// 007d43a6  c3                   ret 
// 007d43a7  8d542408             lea edx, [esp + 8]
// 007d43ab  52                   push edx
// 007d43ac  53                   push ebx
// 007d43ad  e85e880000           call 0x7dcc10
// 007d43b2  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 007d43b6  83c408               add esp, 8
// 007d43b9  56                   push esi
// 007d43ba  50                   push eax
// 007d43bb  53                   push ebx
// 007d43bc  e80f840000           call 0x7dc7d0
// 007d43c1  83c40c               add esp, 0xc
// 007d43c4  5e                   pop esi
// 007d43c5  5b                   pop ebx
// 007d43c6  83c418               add esp, 0x18
// 007d43c9  c3                   ret 
// 007d43ca  6aff                 push -1
// 007d43cc  8d44240c             lea eax, [esp + 0xc]
// 007d43d0  50                   push eax
// 007d43d1  53                   push ebx
// 007d43d2  e8297f0000           call 0x7dc300
// 007d43d7  83c40c               add esp, 0xc
// 007d43da  837c24080d           cmp dword ptr [esp + 8], 0xd
// 007d43df  751c                 jne 0x7d43fd
// 007d43e1  83fe01               cmp esi, 1
// 007d43e4  7517                 jne 0x7d43fd
// 007d43e6  8b0b                 mov ecx, dword ptr [ebx]
// 007d43e8  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007d43eb  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d43ef  8b0c82               mov ecx, dword ptr [edx + eax*4]
// 007d43f2  8d0482               lea eax, [edx + eax*4]
// 007d43f5  83e1dd               and ecx, 0xffffffdd
// 007d43f8  83c91d               or ecx, 0x1d
// 007d43fb  8908                 mov dword ptr [eax], ecx
// 007d43fd  0fb64332             movzx eax, byte ptr [ebx + 0x32]
// 007d4401  83ceff               or esi, 0xffffffff
// 007d4404  56                   push esi
// 007d4405  50                   push eax
// 007d4406  53                   push ebx
// 007d4407  e8c4830000           call 0x7dc7d0
// 007d440c  83c40c               add esp, 0xc
// 007d440f  5e                   pop esi
// 007d4410  5b                   pop ebx
// 007d4411  83c418               add esp, 0x18
// 007d4414  c3                   ret 
// 007d4415  33f6                 xor esi, esi
// 007d4417  33c0                 xor eax, eax
// 007d4419  56                   push esi
// 007d441a  50                   push eax
// 007d441b  53                   push ebx
// 007d441c  e8af830000           call 0x7dc7d0
// 007d4421  83c40c               add esp, 0xc
// 007d4424  5e                   pop esi
// 007d4425  5b                   pop ebx
// 007d4426  83c418               add esp, 0x18
// 007d4429  c3                   ret 
// 007d442a  8bff                 mov edi, edi
// 007d442c  15447d005f           adc eax, 0x5f007d44
// 007d4431  43                   inc ebx
// 007d4432  7d00                 jge 0x7d4434
// 007d4434  0000                 add byte ptr [eax], al
// 007d4436  0001                 add byte ptr [ecx], al
// 007d4438  0101                 add dword ptr [ecx], eax
// 007d443a  0101                 add dword ptr [ecx], eax
// 007d443c  0101                 add dword ptr [ecx], eax
// 007d443e  0101                 add dword ptr [ecx], eax
// 007d4440  0101                 add dword ptr [ecx], eax
// 007d4442  0101                 add dword ptr [ecx], eax
// 007d4444  0001                 add byte ptr [ecx], al
// 007d4446  0101                 add dword ptr [ecx], eax
// 007d4448  0101                 add dword ptr [ecx], eax
// 007d444a  0101                 add dword ptr [ecx], eax
// 007d444c  0101                 add dword ptr [ecx], eax
// 007d444e  0100                 add dword ptr [eax], eax
// library lua-5.1/lparser.c (function _retstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
