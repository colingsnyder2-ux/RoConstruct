// from server: 100% by auto
// roc 2011-06 008b92b0  unit: CXTPDockingPaneBase  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b92b0
//
// 008b92b0  53                   push ebx
// 008b92b1  56                   push esi
// 008b92b2  8bf1                 mov esi, ecx
// 008b92b4  57                   push edi
// 008b92b5  8b7e04               mov edi, dword ptr [esi + 4]
// 008b92b8  33db                 xor ebx, ebx
// 008b92ba  3bfb                 cmp edi, ebx
// 008b92bc  7421                 je 0x8b92df
// 008b92be  395e08               cmp dword ptr [esi + 8], ebx
// 008b92c1  761c                 jbe 0x8b92df
// 008b92c3  8b5608               mov edx, dword ptr [esi + 8]
// 008b92c6  8bcf                 mov ecx, edi
// 008b92c8  8b01                 mov eax, dword ptr [ecx]
// 008b92ca  3bc3                 cmp eax, ebx
// 008b92cc  7409                 je 0x8b92d7
// 008b92ce  8bff                 mov edi, edi
// 008b92d0  8b4008               mov eax, dword ptr [eax + 8]
// 008b92d3  3bc3                 cmp eax, ebx
// 008b92d5  75f9                 jne 0x8b92d0
// 008b92d7  83c104               add ecx, 4
// 008b92da  83ea01               sub edx, 1
// 008b92dd  75e9                 jne 0x8b92c8
// 008b92df  57                   push edi
// 008b92e0  e81f10f5ff           call 0x80a304
// 008b92e5  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 008b92e8  83c404               add esp, 4
// 008b92eb  895e04               mov dword ptr [esi + 4], ebx
// 008b92ee  895e0c               mov dword ptr [esi + 0xc], ebx
// 008b92f1  895e10               mov dword ptr [esi + 0x10], ebx
// 008b92f4  e8cf18f5ff           call 0x80abc8
// 008b92f9  5f                   pop edi
// 008b92fa  895e14               mov dword ptr [esi + 0x14], ebx
// 008b92fd  5e                   pop esi
// 008b92fe  5b                   pop ebx
// 008b92ff  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
