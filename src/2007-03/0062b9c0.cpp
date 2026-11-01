// from server: 100% by auto
// roc 2007-03 0062b9c0  unit: seg_00620000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b9c0
//
// 0062b9c0  53                   push ebx
// 0062b9c1  56                   push esi
// 0062b9c2  8bf1                 mov esi, ecx
// 0062b9c4  57                   push edi
// 0062b9c5  8b7e04               mov edi, dword ptr [esi + 4]
// 0062b9c8  33db                 xor ebx, ebx
// 0062b9ca  3bfb                 cmp edi, ebx
// 0062b9cc  7421                 je 0x62b9ef
// 0062b9ce  395e08               cmp dword ptr [esi + 8], ebx
// 0062b9d1  761c                 jbe 0x62b9ef
// 0062b9d3  8b5608               mov edx, dword ptr [esi + 8]
// 0062b9d6  8bcf                 mov ecx, edi
// 0062b9d8  8b01                 mov eax, dword ptr [ecx]
// 0062b9da  3bc3                 cmp eax, ebx
// 0062b9dc  7409                 je 0x62b9e7
// 0062b9de  8bff                 mov edi, edi
// 0062b9e0  8b4008               mov eax, dword ptr [eax + 8]
// 0062b9e3  3bc3                 cmp eax, ebx
// 0062b9e5  75f9                 jne 0x62b9e0
// 0062b9e7  83c104               add ecx, 4
// 0062b9ea  83ea01               sub edx, 1
// 0062b9ed  75e9                 jne 0x62b9d8
// 0062b9ef  57                   push edi
// 0062b9f0  e8bf29ffff           call 0x61e3b4
// 0062b9f5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0062b9f8  83c404               add esp, 4
// 0062b9fb  895e04               mov dword ptr [esi + 4], ebx
// 0062b9fe  895e0c               mov dword ptr [esi + 0xc], ebx
// 0062ba01  895e10               mov dword ptr [esi + 0x10], ebx
// 0062ba04  e80131ffff           call 0x61eb0a
// 0062ba09  5f                   pop edi
// 0062ba0a  895e14               mov dword ptr [esi + 0x14], ebx
// 0062ba0d  5e                   pop esi
// 0062ba0e  5b                   pop ebx
// 0062ba0f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
