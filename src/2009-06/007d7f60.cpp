// from server: 100% by auto
// roc 2009-06 007d7f60  unit: CXTPDockingPaneTabbedContainer  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d7f60
//
// 007d7f60  83ec28               sub esp, 0x28
// 007d7f63  56                   push esi
// 007d7f64  8b742430             mov esi, dword ptr [esp + 0x30]
// 007d7f68  57                   push edi
// 007d7f69  56                   push esi
// 007d7f6a  8bf9                 mov edi, ecx
// 007d7f6c  e8dfdeffff           call 0x7d5e50
// 007d7f71  8b07                 mov eax, dword ptr [edi]
// 007d7f73  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d7f76  8bcf                 mov ecx, edi
// 007d7f78  ffd2                 call edx
// 007d7f7a  85c0                 test eax, eax
// 007d7f7c  0f85da000000         jne 0x7d805c
// 007d7f82  53                   push ebx
// 007d7f83  8d5fac               lea ebx, [edi - 0x54]
// 007d7f86  8bcb                 mov ecx, ebx
// 007d7f88  e8d3fdffff           call 0x7d7d60
// 007d7f8d  85c0                 test eax, eax
// 007d7f8f  744b                 je 0x7d7fdc
// 007d7f91  8b4710               mov eax, dword ptr [edi + 0x10]
// 007d7f94  85c0                 test eax, eax
// 007d7f96  7405                 je 0x7d7f9d
// 007d7f98  83c0e0               add eax, -0x20
// 007d7f9b  eb02                 jmp 0x7d7f9f
// 007d7f9d  33c0                 xor eax, eax
// 007d7f9f  83b89000000000       cmp dword ptr [eax + 0x90], 0
// 007d7fa6  741a                 je 0x7d7fc2
// 007d7fa8  6a00                 push 0
// 007d7faa  56                   push esi
// 007d7fab  8bcb                 mov ecx, ebx
// 007d7fad  c7462000000000       mov dword ptr [esi + 0x20], 0
// 007d7fb4  e8b7f2ffff           call 0x7d7270
// 007d7fb9  5b                   pop ebx
// 007d7fba  5f                   pop edi
// 007d7fbb  5e                   pop esi
// 007d7fbc  83c428               add esp, 0x28
// 007d7fbf  c20400               ret 4
// 007d7fc2  6a00                 push 0
// 007d7fc4  56                   push esi
// 007d7fc5  8bcb                 mov ecx, ebx
// 007d7fc7  c7462400000000       mov dword ptr [esi + 0x24], 0
// 007d7fce  e89df2ffff           call 0x7d7270
// 007d7fd3  5b                   pop ebx
// 007d7fd4  5f                   pop edi
// 007d7fd5  5e                   pop esi
// 007d7fd6  83c428               add esp, 0x28
// 007d7fd9  c20400               ret 4
// 007d7fdc  8bcf                 mov ecx, edi
// 007d7fde  e8bdd1faff           call 0x7851a0
// 007d7fe3  89442438             mov dword ptr [esp + 0x38], eax
// 007d7fe7  85c0                 test eax, eax
// 007d7fe9  7466                 je 0x7d8051
// 007d7feb  eb03                 jmp 0x7d7ff0
// 007d7fed  8d4900               lea ecx, [ecx]
// 007d7ff0  8d442438             lea eax, [esp + 0x38]
// 007d7ff4  50                   push eax
// 007d7ff5  8bcf                 mov ecx, edi
// 007d7ff7  e874020400           call 0x818270
// 007d7ffc  8b10                 mov edx, dword ptr [eax]
// 007d7ffe  8b5210               mov edx, dword ptr [edx + 0x10]
// 007d8001  8d4c240c             lea ecx, [esp + 0xc]
// 007d8005  51                   push ecx
// 007d8006  8bc8                 mov ecx, eax
// 007d8008  ffd2                 call edx
// 007d800a  8b4618               mov eax, dword ptr [esi + 0x18]
// 007d800d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007d8011  3bc1                 cmp eax, ecx
// 007d8013  7f02                 jg 0x7d8017
// 007d8015  8bc1                 mov eax, ecx
// 007d8017  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007d801b  894618               mov dword ptr [esi + 0x18], eax
// 007d801e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007d8021  3bc1                 cmp eax, ecx
// 007d8023  7f02                 jg 0x7d8027
// 007d8025  8bc1                 mov eax, ecx
// 007d8027  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007d802b  89461c               mov dword ptr [esi + 0x1c], eax
// 007d802e  8b4620               mov eax, dword ptr [esi + 0x20]
// 007d8031  3bc1                 cmp eax, ecx
// 007d8033  7c02                 jl 0x7d8037
// 007d8035  8bc1                 mov eax, ecx
// 007d8037  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007d803b  894620               mov dword ptr [esi + 0x20], eax
// 007d803e  8b4624               mov eax, dword ptr [esi + 0x24]
// 007d8041  3bc1                 cmp eax, ecx
// 007d8043  7c02                 jl 0x7d8047
// 007d8045  8bc1                 mov eax, ecx
// 007d8047  837c243800           cmp dword ptr [esp + 0x38], 0
// 007d804c  894624               mov dword ptr [esi + 0x24], eax
// 007d804f  759f                 jne 0x7d7ff0
// 007d8051  6a00                 push 0
// 007d8053  56                   push esi
// 007d8054  8bcb                 mov ecx, ebx
// 007d8056  e815f2ffff           call 0x7d7270
// 007d805b  5b                   pop ebx
// 007d805c  5f                   pop edi
// 007d805d  5e                   pop esi
// 007d805e  83c428               add esp, 0x28
// 007d8061  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneTabbedContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
