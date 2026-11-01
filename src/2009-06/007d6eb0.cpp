// from server: 100% by auto
// roc 2009-06 007d6eb0  unit: CXTPDockingPaneTabbedContainer  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d6eb0
//
// 007d6eb0  51                   push ecx
// 007d6eb1  53                   push ebx
// 007d6eb2  55                   push ebp
// 007d6eb3  56                   push esi
// 007d6eb4  8bf1                 mov esi, ecx
// 007d6eb6  85f6                 test esi, esi
// 007d6eb8  7405                 je 0x7d6ebf
// 007d6eba  8d4654               lea eax, [esi + 0x54]
// 007d6ebd  eb02                 jmp 0x7d6ec1
// 007d6ebf  33c0                 xor eax, eax
// 007d6ec1  8d5e54               lea ebx, [esi + 0x54]
// 007d6ec4  50                   push eax
// 007d6ec5  8bcb                 mov ecx, ebx
// 007d6ec7  e834eeffff           call 0x7d5d00
// 007d6ecc  8bc8                 mov ecx, eax
// 007d6ece  e8ed6af8ff           call 0x75d9c0
// 007d6ed3  85c0                 test eax, eax
// 007d6ed5  7447                 je 0x7d6f1e
// 007d6ed7  83f801               cmp eax, 1
// 007d6eda  7442                 je 0x7d6f1e
// 007d6edc  8b4e7c               mov ecx, dword ptr [esi + 0x7c]
// 007d6edf  33ed                 xor ebp, ebp
// 007d6ee1  2b4e74               sub ecx, dword ptr [esi + 0x74]
// 007d6ee4  894e5c               mov dword ptr [esi + 0x5c], ecx
// 007d6ee7  8bcb                 mov ecx, ebx
// 007d6ee9  e8b2e2faff           call 0x7851a0
// 007d6eee  8944240c             mov dword ptr [esp + 0xc], eax
// 007d6ef2  85c0                 test eax, eax
// 007d6ef4  7446                 je 0x7d6f3c
// 007d6ef6  57                   push edi
// 007d6ef7  8d542410             lea edx, [esp + 0x10]
// 007d6efb  52                   push edx
// 007d6efc  8bcb                 mov ecx, ebx
// 007d6efe  e86d130400           call 0x818270
// 007d6f03  8bf8                 mov edi, eax
// 007d6f05  8b07                 mov eax, dword ptr [edi]
// 007d6f07  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d6f0a  8bcf                 mov ecx, edi
// 007d6f0c  ffd2                 call edx
// 007d6f0e  85c0                 test eax, eax
// 007d6f10  7522                 jne 0x7d6f34
// 007d6f12  85ed                 test ebp, ebp
// 007d6f14  7418                 je 0x7d6f2e
// 007d6f16  8b4658               mov eax, dword ptr [esi + 0x58]
// 007d6f19  894704               mov dword ptr [edi + 4], eax
// 007d6f1c  eb16                 jmp 0x7d6f34
// 007d6f1e  8b4678               mov eax, dword ptr [esi + 0x78]
// 007d6f21  2b4670               sub eax, dword ptr [esi + 0x70]
// 007d6f24  bd01000000           mov ebp, 1
// 007d6f29  894658               mov dword ptr [esi + 0x58], eax
// 007d6f2c  ebb9                 jmp 0x7d6ee7
// 007d6f2e  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 007d6f31  894f08               mov dword ptr [edi + 8], ecx
// 007d6f34  837c241000           cmp dword ptr [esp + 0x10], 0
// 007d6f39  75bc                 jne 0x7d6ef7
// 007d6f3b  5f                   pop edi
// 007d6f3c  5e                   pop esi
// 007d6f3d  5d                   pop ebp
// 007d6f3e  5b                   pop ebx
// 007d6f3f  59                   pop ecx
// 007d6f40  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneTabbedContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
