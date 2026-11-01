// from server: 100% by auto
// roc 2009-12 008f3400  unit: CXTColorSelectorCtrlThemeOfficeXP  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3400
//
// 008f3400  56                   push esi
// 008f3401  8bf1                 mov esi, ecx
// 008f3403  e868ffffff           call 0x8f3370
// 008f3408  c706b4f9a000         mov dword ptr [esi], 0xa0f9b4
// 008f340e  8bc6                 mov eax, esi
// 008f3410  5e                   pop esi
// 008f3411  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
