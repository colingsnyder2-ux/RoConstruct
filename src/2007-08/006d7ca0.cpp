// from server: 100% by auto
// roc 2007-08 006d7ca0  unit: CXTPDockingPaneBase  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d7ca0
//
// 006d7ca0  56                   push esi
// 006d7ca1  8bf1                 mov esi, ecx
// 006d7ca3  8b4604               mov eax, dword ptr [esi + 4]
// 006d7ca6  57                   push edi
// 006d7ca7  33ff                 xor edi, edi
// 006d7ca9  3bc7                 cmp eax, edi
// 006d7cab  7409                 je 0x6d7cb6
// 006d7cad  8d4900               lea ecx, [ecx]
// 006d7cb0  8b00                 mov eax, dword ptr [eax]
// 006d7cb2  3bc7                 cmp eax, edi
// 006d7cb4  75fa                 jne 0x6d7cb0
// 006d7cb6  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006d7cb9  897e0c               mov dword ptr [esi + 0xc], edi
// 006d7cbc  897e10               mov dword ptr [esi + 0x10], edi
// 006d7cbf  897e08               mov dword ptr [esi + 8], edi
// 006d7cc2  897e04               mov dword ptr [esi + 4], edi
// 006d7cc5  e8b289f5ff           call 0x63067c
// 006d7cca  897e14               mov dword ptr [esi + 0x14], edi
// 006d7ccd  5f                   pop edi
// 006d7cce  5e                   pop esi
// 006d7ccf  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ?RemoveAll@?$CList@PAVIControlSiteFactory@@PAV1@@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
