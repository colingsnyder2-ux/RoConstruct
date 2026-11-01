// from server: 100% by auto
// roc 2009-12 008b19f0  unit: CXTPDockingPaneTabbedContainer  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b19f0
//
// 008b19f0  51                   push ecx
// 008b19f1  53                   push ebx
// 008b19f2  55                   push ebp
// 008b19f3  56                   push esi
// 008b19f4  8bf1                 mov esi, ecx
// 008b19f6  85f6                 test esi, esi
// 008b19f8  7405                 je 0x8b19ff
// 008b19fa  8d4654               lea eax, [esi + 0x54]
// 008b19fd  eb02                 jmp 0x8b1a01
// 008b19ff  33c0                 xor eax, eax
// 008b1a01  8d5e54               lea ebx, [esi + 0x54]
// 008b1a04  50                   push eax
// 008b1a05  8bcb                 mov ecx, ebx
// 008b1a07  e834eeffff           call 0x8b0840
// 008b1a0c  8bc8                 mov ecx, eax
// 008b1a0e  e81d6df8ff           call 0x838730
// 008b1a13  85c0                 test eax, eax
// 008b1a15  7447                 je 0x8b1a5e
// 008b1a17  83f801               cmp eax, 1
// 008b1a1a  7442                 je 0x8b1a5e
// 008b1a1c  8b4e7c               mov ecx, dword ptr [esi + 0x7c]
// 008b1a1f  33ed                 xor ebp, ebp
// 008b1a21  2b4e74               sub ecx, dword ptr [esi + 0x74]
// 008b1a24  894e5c               mov dword ptr [esi + 0x5c], ecx
// 008b1a27  8bcb                 mov ecx, ebx
// 008b1a29  e8628dfaff           call 0x85a790
// 008b1a2e  8944240c             mov dword ptr [esp + 0xc], eax
// 008b1a32  85c0                 test eax, eax
// 008b1a34  7446                 je 0x8b1a7c
// 008b1a36  57                   push edi
// 008b1a37  8d542410             lea edx, [esp + 0x10]
// 008b1a3b  52                   push edx
// 008b1a3c  8bcb                 mov ecx, ebx
// 008b1a3e  e8cd140400           call 0x8f2f10
// 008b1a43  8bf8                 mov edi, eax
// 008b1a45  8b07                 mov eax, dword ptr [edi]
// 008b1a47  8b5014               mov edx, dword ptr [eax + 0x14]
// 008b1a4a  8bcf                 mov ecx, edi
// 008b1a4c  ffd2                 call edx
// 008b1a4e  85c0                 test eax, eax
// 008b1a50  7522                 jne 0x8b1a74
// 008b1a52  85ed                 test ebp, ebp
// 008b1a54  7418                 je 0x8b1a6e
// 008b1a56  8b4658               mov eax, dword ptr [esi + 0x58]
// 008b1a59  894704               mov dword ptr [edi + 4], eax
// 008b1a5c  eb16                 jmp 0x8b1a74
// 008b1a5e  8b4678               mov eax, dword ptr [esi + 0x78]
// 008b1a61  2b4670               sub eax, dword ptr [esi + 0x70]
// 008b1a64  bd01000000           mov ebp, 1
// 008b1a69  894658               mov dword ptr [esi + 0x58], eax
// 008b1a6c  ebb9                 jmp 0x8b1a27
// 008b1a6e  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 008b1a71  894f08               mov dword ptr [edi + 8], ecx
// 008b1a74  837c241000           cmp dword ptr [esp + 0x10], 0
// 008b1a79  75bc                 jne 0x8b1a37
// 008b1a7b  5f                   pop edi
// 008b1a7c  5e                   pop esi
// 008b1a7d  5d                   pop ebp
// 008b1a7e  5b                   pop ebx
// 008b1a7f  59                   pop ecx
// 008b1a80  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneTabbedContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
