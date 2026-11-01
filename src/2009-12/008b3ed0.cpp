// from server: 100% by auto
// roc 2009-12 008b3ed0  unit: CXTPDockingPaneSplitterWnd  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b3ed0
//
// 008b3ed0  51                   push ecx
// 008b3ed1  53                   push ebx
// 008b3ed2  57                   push edi
// 008b3ed3  8bf9                 mov edi, ecx
// 008b3ed5  83bf9000000000       cmp dword ptr [edi + 0x90], 0
// 008b3edc  740b                 je 0x8b3ee9
// 008b3ede  8b4744               mov eax, dword ptr [edi + 0x44]
// 008b3ee1  2b473c               sub eax, dword ptr [edi + 0x3c]
// 008b3ee4  894724               mov dword ptr [edi + 0x24], eax
// 008b3ee7  eb09                 jmp 0x8b3ef2
// 008b3ee9  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 008b3eec  2b4f40               sub ecx, dword ptr [edi + 0x40]
// 008b3eef  894f28               mov dword ptr [edi + 0x28], ecx
// 008b3ef2  8d5f20               lea ebx, [edi + 0x20]
// 008b3ef5  8bcb                 mov ecx, ebx
// 008b3ef7  e89468faff           call 0x85a790
// 008b3efc  89442408             mov dword ptr [esp + 8], eax
// 008b3f00  85c0                 test eax, eax
// 008b3f02  7440                 je 0x8b3f44
// 008b3f04  56                   push esi
// 008b3f05  8d54240c             lea edx, [esp + 0xc]
// 008b3f09  52                   push edx
// 008b3f0a  8bcb                 mov ecx, ebx
// 008b3f0c  e8ffef0300           call 0x8f2f10
// 008b3f11  8bf0                 mov esi, eax
// 008b3f13  8b06                 mov eax, dword ptr [esi]
// 008b3f15  8b5014               mov edx, dword ptr [eax + 0x14]
// 008b3f18  8bce                 mov ecx, esi
// 008b3f1a  ffd2                 call edx
// 008b3f1c  85c0                 test eax, eax
// 008b3f1e  751c                 jne 0x8b3f3c
// 008b3f20  398790000000         cmp dword ptr [edi + 0x90], eax
// 008b3f26  740b                 je 0x8b3f33
// 008b3f28  8b4624               mov eax, dword ptr [esi + 0x24]
// 008b3f2b  2b461c               sub eax, dword ptr [esi + 0x1c]
// 008b3f2e  894604               mov dword ptr [esi + 4], eax
// 008b3f31  eb09                 jmp 0x8b3f3c
// 008b3f33  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 008b3f36  2b4e20               sub ecx, dword ptr [esi + 0x20]
// 008b3f39  894e08               mov dword ptr [esi + 8], ecx
// 008b3f3c  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008b3f41  75c2                 jne 0x8b3f05
// 008b3f43  5e                   pop esi
// 008b3f44  5f                   pop edi
// 008b3f45  5b                   pop ebx
// 008b3f46  59                   pop ecx
// 008b3f47  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneSplitterContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
