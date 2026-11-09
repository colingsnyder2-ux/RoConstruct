// from server: 100% by auto
// roc 2010-06 00865ad0  unit: CXTPDockingPaneTabbedContainer  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00865ad0
//
// 00865ad0  51                   push ecx
// 00865ad1  53                   push ebx
// 00865ad2  55                   push ebp
// 00865ad3  56                   push esi
// 00865ad4  8bf1                 mov esi, ecx
// 00865ad6  85f6                 test esi, esi
// 00865ad8  7405                 je 0x865adf
// 00865ada  8d4654               lea eax, [esi + 0x54]
// 00865add  eb02                 jmp 0x865ae1
// 00865adf  33c0                 xor eax, eax
// 00865ae1  8d5e54               lea ebx, [esi + 0x54]
// 00865ae4  50                   push eax
// 00865ae5  8bcb                 mov ecx, ebx
// 00865ae7  e824eeffff           call 0x864910
// 00865aec  8bc8                 mov ecx, eax
// 00865aee  e85d6ef8ff           call 0x7ec950
// 00865af3  85c0                 test eax, eax
// 00865af5  7447                 je 0x865b3e
// 00865af7  83f801               cmp eax, 1
// 00865afa  7442                 je 0x865b3e
// 00865afc  8b4e7c               mov ecx, dword ptr [esi + 0x7c]
// 00865aff  33ed                 xor ebp, ebp
// 00865b01  2b4e74               sub ecx, dword ptr [esi + 0x74]
// 00865b04  894e5c               mov dword ptr [esi + 0x5c], ecx
// 00865b07  8bcb                 mov ecx, ebx
// 00865b09  e8b296f9ff           call 0x7ff1c0
// 00865b0e  8944240c             mov dword ptr [esp + 0xc], eax
// 00865b12  85c0                 test eax, eax
// 00865b14  7446                 je 0x865b5c
// 00865b16  57                   push edi
// 00865b17  8d542410             lea edx, [esp + 0x10]
// 00865b1b  52                   push edx
// 00865b1c  8bcb                 mov ecx, ebx
// 00865b1e  e83d150400           call 0x8a7060
// 00865b23  8bf8                 mov edi, eax
// 00865b25  8b07                 mov eax, dword ptr [edi]
// 00865b27  8b5014               mov edx, dword ptr [eax + 0x14]
// 00865b2a  8bcf                 mov ecx, edi
// 00865b2c  ffd2                 call edx
// 00865b2e  85c0                 test eax, eax
// 00865b30  7522                 jne 0x865b54
// 00865b32  85ed                 test ebp, ebp
// 00865b34  7418                 je 0x865b4e
// 00865b36  8b4658               mov eax, dword ptr [esi + 0x58]
// 00865b39  894704               mov dword ptr [edi + 4], eax
// 00865b3c  eb16                 jmp 0x865b54
// 00865b3e  8b4678               mov eax, dword ptr [esi + 0x78]
// 00865b41  2b4670               sub eax, dword ptr [esi + 0x70]
// 00865b44  bd01000000           mov ebp, 1
// 00865b49  894658               mov dword ptr [esi + 0x58], eax
// 00865b4c  ebb9                 jmp 0x865b07
// 00865b4e  8b4e5c               mov ecx, dword ptr [esi + 0x5c]
// 00865b51  894f08               mov dword ptr [edi + 8], ecx
// 00865b54  837c241000           cmp dword ptr [esp + 0x10], 0
// 00865b59  75bc                 jne 0x865b17
// 00865b5b  5f                   pop edi
// 00865b5c  5e                   pop esi
// 00865b5d  5d                   pop ebp
// 00865b5e  5b                   pop ebx
// 00865b5f  59                   pop ecx
// 00865b60  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneTabbedContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneTabbedContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneTabbedContainer.cpp
