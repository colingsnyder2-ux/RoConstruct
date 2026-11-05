// from server: 100% by auto
// roc 2010-06 00866b80  unit: CXTPDockingPaneTabbedContainer  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00866b80
//
// 00866b80  83ec28               sub esp, 0x28
// 00866b83  56                   push esi
// 00866b84  8b742430             mov esi, dword ptr [esp + 0x30]
// 00866b88  57                   push edi
// 00866b89  56                   push esi
// 00866b8a  8bf9                 mov edi, ecx
// 00866b8c  e8cfdeffff           call 0x864a60
// 00866b91  8b07                 mov eax, dword ptr [edi]
// 00866b93  8b5014               mov edx, dword ptr [eax + 0x14]
// 00866b96  8bcf                 mov ecx, edi
// 00866b98  ffd2                 call edx
// 00866b9a  85c0                 test eax, eax
// 00866b9c  0f85da000000         jne 0x866c7c
// 00866ba2  53                   push ebx
// 00866ba3  8d5fac               lea ebx, [edi - 0x54]
// 00866ba6  8bcb                 mov ecx, ebx
// 00866ba8  e8d3fdffff           call 0x866980
// 00866bad  85c0                 test eax, eax
// 00866baf  744b                 je 0x866bfc
// 00866bb1  8b4710               mov eax, dword ptr [edi + 0x10]
// 00866bb4  85c0                 test eax, eax
// 00866bb6  7405                 je 0x866bbd
// 00866bb8  83c0e0               add eax, -0x20
// 00866bbb  eb02                 jmp 0x866bbf
// 00866bbd  33c0                 xor eax, eax
// 00866bbf  83b89000000000       cmp dword ptr [eax + 0x90], 0
// 00866bc6  741a                 je 0x866be2
// 00866bc8  6a00                 push 0
// 00866bca  56                   push esi
// 00866bcb  8bcb                 mov ecx, ebx
// 00866bcd  c7462000000000       mov dword ptr [esi + 0x20], 0
// 00866bd4  e8b7f2ffff           call 0x865e90
// 00866bd9  5b                   pop ebx
// 00866bda  5f                   pop edi
// 00866bdb  5e                   pop esi
// 00866bdc  83c428               add esp, 0x28
// 00866bdf  c20400               ret 4
// 00866be2  6a00                 push 0
// 00866be4  56                   push esi
// 00866be5  8bcb                 mov ecx, ebx
// 00866be7  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00866bee  e89df2ffff           call 0x865e90
// 00866bf3  5b                   pop ebx
// 00866bf4  5f                   pop edi
// 00866bf5  5e                   pop esi
// 00866bf6  83c428               add esp, 0x28
// 00866bf9  c20400               ret 4
// 00866bfc  8bcf                 mov ecx, edi
// 00866bfe  e8bd85f9ff           call 0x7ff1c0
// 00866c03  89442438             mov dword ptr [esp + 0x38], eax
// 00866c07  85c0                 test eax, eax
// 00866c09  7466                 je 0x866c71
// 00866c0b  eb03                 jmp 0x866c10
// 00866c0d  8d4900               lea ecx, [ecx]
// 00866c10  8d442438             lea eax, [esp + 0x38]
// 00866c14  50                   push eax
// 00866c15  8bcf                 mov ecx, edi
// 00866c17  e844040400           call 0x8a7060
// 00866c1c  8b10                 mov edx, dword ptr [eax]
// 00866c1e  8b5210               mov edx, dword ptr [edx + 0x10]
// 00866c21  8d4c240c             lea ecx, [esp + 0xc]
// 00866c25  51                   push ecx
// 00866c26  8bc8                 mov ecx, eax
// 00866c28  ffd2                 call edx
// 00866c2a  8b4618               mov eax, dword ptr [esi + 0x18]
// 00866c2d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00866c31  3bc1                 cmp eax, ecx
// 00866c33  7f02                 jg 0x866c37
// 00866c35  8bc1                 mov eax, ecx
// 00866c37  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00866c3b  894618               mov dword ptr [esi + 0x18], eax
// 00866c3e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00866c41  3bc1                 cmp eax, ecx
// 00866c43  7f02                 jg 0x866c47
// 00866c45  8bc1                 mov eax, ecx
// 00866c47  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00866c4b  89461c               mov dword ptr [esi + 0x1c], eax
// 00866c4e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00866c51  3bc1                 cmp eax, ecx
// 00866c53  7c02                 jl 0x866c57
// 00866c55  8bc1                 mov eax, ecx
// 00866c57  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00866c5b  894620               mov dword ptr [esi + 0x20], eax
// 00866c5e  8b4624               mov eax, dword ptr [esi + 0x24]
// 00866c61  3bc1                 cmp eax, ecx
// 00866c63  7c02                 jl 0x866c67
// 00866c65  8bc1                 mov eax, ecx
// 00866c67  837c243800           cmp dword ptr [esp + 0x38], 0
// 00866c6c  894624               mov dword ptr [esi + 0x24], eax
// 00866c6f  759f                 jne 0x866c10
// 00866c71  6a00                 push 0
// 00866c73  56                   push esi
// 00866c74  8bcb                 mov ecx, ebx
// 00866c76  e815f2ffff           call 0x865e90
// 00866c7b  5b                   pop ebx
// 00866c7c  5f                   pop edi
// 00866c7d  5e                   pop esi
// 00866c7e  83c428               add esp, 0x28
// 00866c81  c20400               ret 4
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneTabbedContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
