// from server: 100% by auto
// roc 2010-06 0085c0d0  unit: CXTPDockingPaneBase  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c0d0
//
// 0085c0d0  56                   push esi
// 0085c0d1  8bf1                 mov esi, ecx
// 0085c0d3  8b4604               mov eax, dword ptr [esi + 4]
// 0085c0d6  57                   push edi
// 0085c0d7  33ff                 xor edi, edi
// 0085c0d9  3bc7                 cmp eax, edi
// 0085c0db  7409                 je 0x85c0e6
// 0085c0dd  8d4900               lea ecx, [ecx]
// 0085c0e0  8b00                 mov eax, dword ptr [eax]
// 0085c0e2  3bc7                 cmp eax, edi
// 0085c0e4  75fa                 jne 0x85c0e0
// 0085c0e6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0085c0e9  897e0c               mov dword ptr [esi + 0xc], edi
// 0085c0ec  897e10               mov dword ptr [esi + 0x10], edi
// 0085c0ef  897e08               mov dword ptr [esi + 8], edi
// 0085c0f2  897e04               mov dword ptr [esi + 4], edi
// 0085c0f5  e80ac4f4ff           call 0x7a8504
// 0085c0fa  897e14               mov dword ptr [esi + 0x14], edi
// 0085c0fd  5f                   pop edi
// 0085c0fe  5e                   pop esi
// 0085c0ff  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxcolorbar.cpp (function ?RemoveAll@?$CList@KK@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorbar.cpp
