// from server: 100% by auto
// roc 2009-12 008f0090  unit: CXTPRibbonControls  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f0090
//
// 008f0090  56                   push esi
// 008f0091  8bf1                 mov esi, ecx
// 008f0093  e8d86af5ff           call 0x846b70
// 008f0098  c7060ce6a000         mov dword ptr [esi], 0xa0e60c
// 008f009e  8bc6                 mov eax, esi
// 008f00a0  5e                   pop esi
// 008f00a1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
