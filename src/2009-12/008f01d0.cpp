// from server: 100% by auto
// roc 2009-12 008f01d0  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f01d0
//
// 008f01d0  56                   push esi
// 008f01d1  8bf1                 mov esi, ecx
// 008f01d3  e89869f5ff           call 0x846b70
// 008f01d8  c7068ce6a000         mov dword ptr [esi], 0xa0e68c
// 008f01de  8bc6                 mov eax, esi
// 008f01e0  5e                   pop esi
// 008f01e1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
