// from server: 100% by auto
// roc 2010-06 007bd9c0  unit: CXTPCommandBar  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd9c0
//
// 007bd9c0  53                   push ebx
// 007bd9c1  56                   push esi
// 007bd9c2  8bf1                 mov esi, ecx
// 007bd9c4  57                   push edi
// 007bd9c5  8b7e04               mov edi, dword ptr [esi + 4]
// 007bd9c8  33db                 xor ebx, ebx
// 007bd9ca  3bfb                 cmp edi, ebx
// 007bd9cc  7421                 je 0x7bd9ef
// 007bd9ce  395e08               cmp dword ptr [esi + 8], ebx
// 007bd9d1  761c                 jbe 0x7bd9ef
// 007bd9d3  8b5608               mov edx, dword ptr [esi + 8]
// 007bd9d6  8bcf                 mov ecx, edi
// 007bd9d8  8b01                 mov eax, dword ptr [ecx]
// 007bd9da  3bc3                 cmp eax, ebx
// 007bd9dc  7409                 je 0x7bd9e7
// 007bd9de  8bff                 mov edi, edi
// 007bd9e0  8b4008               mov eax, dword ptr [eax + 8]
// 007bd9e3  3bc3                 cmp eax, ebx
// 007bd9e5  75f9                 jne 0x7bd9e0
// 007bd9e7  83c104               add ecx, 4
// 007bd9ea  83ea01               sub edx, 1
// 007bd9ed  75e9                 jne 0x7bd9d8
// 007bd9ef  57                   push edi
// 007bd9f0  e851a2feff           call 0x7a7c46
// 007bd9f5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007bd9f8  83c404               add esp, 4
// 007bd9fb  895e04               mov dword ptr [esi + 4], ebx
// 007bd9fe  895e0c               mov dword ptr [esi + 0xc], ebx
// 007bda01  895e10               mov dword ptr [esi + 0x10], ebx
// 007bda04  e8fbaafeff           call 0x7a8504
// 007bda09  5f                   pop edi
// 007bda0a  895e14               mov dword ptr [esi + 0x14], ebx
// 007bda0d  5e                   pop esi
// 007bda0e  5b                   pop ebx
// 007bda0f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
