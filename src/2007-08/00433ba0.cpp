// from server: 100% by auto
// roc 2007-08 00433ba0  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433ba0
//
// 00433ba0  56                   push esi
// 00433ba1  8bf1                 mov esi, ecx
// 00433ba3  e832ca1f00           call 0x6305da
// 00433ba8  c7066cbb7800         mov dword ptr [esi], 0x78bb6c
// 00433bae  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00433bb5  8bc6                 mov eax, esi
// 00433bb7  5e                   pop esi
// 00433bb8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
