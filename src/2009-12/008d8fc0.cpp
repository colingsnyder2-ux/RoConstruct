// from server: 100% by auto
// roc 2009-12 008d8fc0  unit: CXTSplitterWndThemeFactory  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d8fc0
//
// 008d8fc0  56                   push esi
// 008d8fc1  8bf1                 mov esi, ecx
// 008d8fc3  e8580ff8ff           call 0x859f20
// 008d8fc8  c7066caca000         mov dword ptr [esi], 0xa0ac6c
// 008d8fce  8bc6                 mov eax, esi
// 008d8fd0  5e                   pop esi
// 008d8fd1  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ??0CStatusCmdUI@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
