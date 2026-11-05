// from server: 100% by auto
// roc 2009-12 008d0c80  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d0c80
//
// 008d0c80  56                   push esi
// 008d0c81  8bf1                 mov esi, ecx
// 008d0c83  e8481afaff           call 0x8726d0
// 008d0c88  c706bcaaa000         mov dword ptr [esi], 0xa0aabc
// 008d0c8e  8bc6                 mov eax, esi
// 008d0c90  5e                   pop esi
// 008d0c91  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
