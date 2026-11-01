// from server: 100% by auto
// roc 2009-12 008b2a90  unit: CXTPDockingPaneTabbedContainer  size: 260 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b2a90
//
// 008b2a90  83ec28               sub esp, 0x28
// 008b2a93  56                   push esi
// 008b2a94  8b742430             mov esi, dword ptr [esp + 0x30]
// 008b2a98  57                   push edi
// 008b2a99  56                   push esi
// 008b2a9a  8bf9                 mov edi, ecx
// 008b2a9c  e8efdeffff           call 0x8b0990
// 008b2aa1  8b07                 mov eax, dword ptr [edi]
// 008b2aa3  8b5014               mov edx, dword ptr [eax + 0x14]
// 008b2aa6  8bcf                 mov ecx, edi
// 008b2aa8  ffd2                 call edx
// 008b2aaa  85c0                 test eax, eax
// 008b2aac  0f85da000000         jne 0x8b2b8c
// 008b2ab2  53                   push ebx
// 008b2ab3  8d5fac               lea ebx, [edi - 0x54]
// 008b2ab6  8bcb                 mov ecx, ebx
// 008b2ab8  e8d3fdffff           call 0x8b2890
// 008b2abd  85c0                 test eax, eax
// 008b2abf  744b                 je 0x8b2b0c
// 008b2ac1  8b4710               mov eax, dword ptr [edi + 0x10]
// 008b2ac4  85c0                 test eax, eax
// 008b2ac6  7405                 je 0x8b2acd
// 008b2ac8  83c0e0               add eax, -0x20
// 008b2acb  eb02                 jmp 0x8b2acf
// 008b2acd  33c0                 xor eax, eax
// 008b2acf  83b89000000000       cmp dword ptr [eax + 0x90], 0
// 008b2ad6  741a                 je 0x8b2af2
// 008b2ad8  6a00                 push 0
// 008b2ada  56                   push esi
// 008b2adb  8bcb                 mov ecx, ebx
// 008b2add  c7462000000000       mov dword ptr [esi + 0x20], 0
// 008b2ae4  e8c7f2ffff           call 0x8b1db0
// 008b2ae9  5b                   pop ebx
// 008b2aea  5f                   pop edi
// 008b2aeb  5e                   pop esi
// 008b2aec  83c428               add esp, 0x28
// 008b2aef  c20400               ret 4
// 008b2af2  6a00                 push 0
// 008b2af4  56                   push esi
// 008b2af5  8bcb                 mov ecx, ebx
// 008b2af7  c7462400000000       mov dword ptr [esi + 0x24], 0
// 008b2afe  e8adf2ffff           call 0x8b1db0
// 008b2b03  5b                   pop ebx
// 008b2b04  5f                   pop edi
// 008b2b05  5e                   pop esi
// 008b2b06  83c428               add esp, 0x28
// 008b2b09  c20400               ret 4
// 008b2b0c  8bcf                 mov ecx, edi
// 008b2b0e  e87d7cfaff           call 0x85a790
// 008b2b13  89442438             mov dword ptr [esp + 0x38], eax
// 008b2b17  85c0                 test eax, eax
// 008b2b19  7466                 je 0x8b2b81
// 008b2b1b  eb03                 jmp 0x8b2b20
// 008b2b1d  8d4900               lea ecx, [ecx]
// 008b2b20  8d442438             lea eax, [esp + 0x38]
// 008b2b24  50                   push eax
// 008b2b25  8bcf                 mov ecx, edi
// 008b2b27  e8e4030400           call 0x8f2f10
// 008b2b2c  8b10                 mov edx, dword ptr [eax]
// 008b2b2e  8b5210               mov edx, dword ptr [edx + 0x10]
// 008b2b31  8d4c240c             lea ecx, [esp + 0xc]
// 008b2b35  51                   push ecx
// 008b2b36  8bc8                 mov ecx, eax
// 008b2b38  ffd2                 call edx
// 008b2b3a  8b4618               mov eax, dword ptr [esi + 0x18]
// 008b2b3d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008b2b41  3bc1                 cmp eax, ecx
// 008b2b43  7f02                 jg 0x8b2b47
// 008b2b45  8bc1                 mov eax, ecx
// 008b2b47  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008b2b4b  894618               mov dword ptr [esi + 0x18], eax
// 008b2b4e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008b2b51  3bc1                 cmp eax, ecx
// 008b2b53  7f02                 jg 0x8b2b57
// 008b2b55  8bc1                 mov eax, ecx
// 008b2b57  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008b2b5b  89461c               mov dword ptr [esi + 0x1c], eax
// 008b2b5e  8b4620               mov eax, dword ptr [esi + 0x20]
// 008b2b61  3bc1                 cmp eax, ecx
// 008b2b63  7c02                 jl 0x8b2b67
// 008b2b65  8bc1                 mov eax, ecx
// 008b2b67  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008b2b6b  894620               mov dword ptr [esi + 0x20], eax
// 008b2b6e  8b4624               mov eax, dword ptr [esi + 0x24]
// 008b2b71  3bc1                 cmp eax, ecx
// 008b2b73  7c02                 jl 0x8b2b77
// 008b2b75  8bc1                 mov eax, ecx
// 008b2b77  837c243800           cmp dword ptr [esp + 0x38], 0
// 008b2b7c  894624               mov dword ptr [esi + 0x24], eax
// 008b2b7f  759f                 jne 0x8b2b20
// 008b2b81  6a00                 push 0
// 008b2b83  56                   push esi
// 008b2b84  8bcb                 mov ecx, ebx
// 008b2b86  e825f2ffff           call 0x8b1db0
// 008b2b8b  5b                   pop ebx
// 008b2b8c  5f                   pop edi
// 008b2b8d  5e                   pop esi
// 008b2b8e  83c428               add esp, 0x28
// 008b2b91  c20400               ret 4
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?GetMinMaxInfo@CXTPDockingPaneTabbedContainer@@UBEXPAUtagMINMAXINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
