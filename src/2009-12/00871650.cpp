// from server: 100% by auto
// roc 2009-12 00871650  unit: CXTPRibbonTheme  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871650
//
// 00871650  56                   push esi
// 00871651  8bf1                 mov esi, ecx
// 00871653  e888590700           call 0x8e6fe0
// 00871658  c706180fa000         mov dword ptr [esi], 0xa00f18
// 0087165e  8bc6                 mov eax, esi
// 00871660  5e                   pop esi
// 00871661  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
