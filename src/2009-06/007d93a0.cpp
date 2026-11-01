// from server: 100% by auto
// roc 2009-06 007d93a0  unit: CXTPDockingPaneSplitterWnd  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d93a0
//
// 007d93a0  51                   push ecx
// 007d93a1  53                   push ebx
// 007d93a2  57                   push edi
// 007d93a3  8bf9                 mov edi, ecx
// 007d93a5  83bf9000000000       cmp dword ptr [edi + 0x90], 0
// 007d93ac  740b                 je 0x7d93b9
// 007d93ae  8b4744               mov eax, dword ptr [edi + 0x44]
// 007d93b1  2b473c               sub eax, dword ptr [edi + 0x3c]
// 007d93b4  894724               mov dword ptr [edi + 0x24], eax
// 007d93b7  eb09                 jmp 0x7d93c2
// 007d93b9  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 007d93bc  2b4f40               sub ecx, dword ptr [edi + 0x40]
// 007d93bf  894f28               mov dword ptr [edi + 0x28], ecx
// 007d93c2  8d5f20               lea ebx, [edi + 0x20]
// 007d93c5  8bcb                 mov ecx, ebx
// 007d93c7  e8d4bdfaff           call 0x7851a0
// 007d93cc  89442408             mov dword ptr [esp + 8], eax
// 007d93d0  85c0                 test eax, eax
// 007d93d2  7440                 je 0x7d9414
// 007d93d4  56                   push esi
// 007d93d5  8d54240c             lea edx, [esp + 0xc]
// 007d93d9  52                   push edx
// 007d93da  8bcb                 mov ecx, ebx
// 007d93dc  e88fee0300           call 0x818270
// 007d93e1  8bf0                 mov esi, eax
// 007d93e3  8b06                 mov eax, dword ptr [esi]
// 007d93e5  8b5014               mov edx, dword ptr [eax + 0x14]
// 007d93e8  8bce                 mov ecx, esi
// 007d93ea  ffd2                 call edx
// 007d93ec  85c0                 test eax, eax
// 007d93ee  751c                 jne 0x7d940c
// 007d93f0  398790000000         cmp dword ptr [edi + 0x90], eax
// 007d93f6  740b                 je 0x7d9403
// 007d93f8  8b4624               mov eax, dword ptr [esi + 0x24]
// 007d93fb  2b461c               sub eax, dword ptr [esi + 0x1c]
// 007d93fe  894604               mov dword ptr [esi + 4], eax
// 007d9401  eb09                 jmp 0x7d940c
// 007d9403  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 007d9406  2b4e20               sub ecx, dword ptr [esi + 0x20]
// 007d9409  894e08               mov dword ptr [esi + 8], ecx
// 007d940c  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007d9411  75c2                 jne 0x7d93d5
// 007d9413  5e                   pop esi
// 007d9414  5f                   pop edi
// 007d9415  5b                   pop ebx
// 007d9416  59                   pop ecx
// 007d9417  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneSplitterContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
