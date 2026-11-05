// from server: 100% by auto
// roc 2010-06 00867fc0  unit: CXTPDockingPaneSplitterWnd  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00867fc0
//
// 00867fc0  51                   push ecx
// 00867fc1  53                   push ebx
// 00867fc2  57                   push edi
// 00867fc3  8bf9                 mov edi, ecx
// 00867fc5  83bf9000000000       cmp dword ptr [edi + 0x90], 0
// 00867fcc  740b                 je 0x867fd9
// 00867fce  8b4744               mov eax, dword ptr [edi + 0x44]
// 00867fd1  2b473c               sub eax, dword ptr [edi + 0x3c]
// 00867fd4  894724               mov dword ptr [edi + 0x24], eax
// 00867fd7  eb09                 jmp 0x867fe2
// 00867fd9  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 00867fdc  2b4f40               sub ecx, dword ptr [edi + 0x40]
// 00867fdf  894f28               mov dword ptr [edi + 0x28], ecx
// 00867fe2  8d5f20               lea ebx, [edi + 0x20]
// 00867fe5  8bcb                 mov ecx, ebx
// 00867fe7  e8d471f9ff           call 0x7ff1c0
// 00867fec  89442408             mov dword ptr [esp + 8], eax
// 00867ff0  85c0                 test eax, eax
// 00867ff2  7440                 je 0x868034
// 00867ff4  56                   push esi
// 00867ff5  8d54240c             lea edx, [esp + 0xc]
// 00867ff9  52                   push edx
// 00867ffa  8bcb                 mov ecx, ebx
// 00867ffc  e85ff00300           call 0x8a7060
// 00868001  8bf0                 mov esi, eax
// 00868003  8b06                 mov eax, dword ptr [esi]
// 00868005  8b5014               mov edx, dword ptr [eax + 0x14]
// 00868008  8bce                 mov ecx, esi
// 0086800a  ffd2                 call edx
// 0086800c  85c0                 test eax, eax
// 0086800e  751c                 jne 0x86802c
// 00868010  398790000000         cmp dword ptr [edi + 0x90], eax
// 00868016  740b                 je 0x868023
// 00868018  8b4624               mov eax, dword ptr [esi + 0x24]
// 0086801b  2b461c               sub eax, dword ptr [esi + 0x1c]
// 0086801e  894604               mov dword ptr [esi + 4], eax
// 00868021  eb09                 jmp 0x86802c
// 00868023  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00868026  2b4e20               sub ecx, dword ptr [esi + 0x20]
// 00868029  894e08               mov dword ptr [esi + 8], ecx
// 0086802c  837c240c00           cmp dword ptr [esp + 0xc], 0
// 00868031  75c2                 jne 0x867ff5
// 00868033  5e                   pop esi
// 00868034  5f                   pop edi
// 00868035  5b                   pop ebx
// 00868036  59                   pop ecx
// 00868037  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneSplitterContainer.cpp (function ?NormalizeDockingSize@CXTPDockingPaneSplitterContainer@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneSplitterContainer.cpp
