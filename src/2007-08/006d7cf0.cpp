// from server: 100% by auto
// roc 2007-08 006d7cf0  unit: CXTPDockingPaneBase  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d7cf0
//
// 006d7cf0  53                   push ebx
// 006d7cf1  56                   push esi
// 006d7cf2  8bf1                 mov esi, ecx
// 006d7cf4  57                   push edi
// 006d7cf5  8b7e04               mov edi, dword ptr [esi + 4]
// 006d7cf8  33db                 xor ebx, ebx
// 006d7cfa  3bfb                 cmp edi, ebx
// 006d7cfc  7421                 je 0x6d7d1f
// 006d7cfe  395e08               cmp dword ptr [esi + 8], ebx
// 006d7d01  761c                 jbe 0x6d7d1f
// 006d7d03  8b5608               mov edx, dword ptr [esi + 8]
// 006d7d06  8bcf                 mov ecx, edi
// 006d7d08  8b01                 mov eax, dword ptr [ecx]
// 006d7d0a  3bc3                 cmp eax, ebx
// 006d7d0c  7409                 je 0x6d7d17
// 006d7d0e  8bff                 mov edi, edi
// 006d7d10  8b4008               mov eax, dword ptr [eax + 8]
// 006d7d13  3bc3                 cmp eax, ebx
// 006d7d15  75f9                 jne 0x6d7d10
// 006d7d17  83c104               add ecx, 4
// 006d7d1a  83ea01               sub edx, 1
// 006d7d1d  75e9                 jne 0x6d7d08
// 006d7d1f  57                   push edi
// 006d7d20  e80182f5ff           call 0x62ff26
// 006d7d25  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006d7d28  83c404               add esp, 4
// 006d7d2b  895e04               mov dword ptr [esi + 4], ebx
// 006d7d2e  895e0c               mov dword ptr [esi + 0xc], ebx
// 006d7d31  895e10               mov dword ptr [esi + 0x10], ebx
// 006d7d34  e84389f5ff           call 0x63067c
// 006d7d39  5f                   pop edi
// 006d7d3a  895e14               mov dword ptr [esi + 0x14], ebx
// 006d7d3d  5e                   pop esi
// 006d7d3e  5b                   pop ebx
// 006d7d3f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
