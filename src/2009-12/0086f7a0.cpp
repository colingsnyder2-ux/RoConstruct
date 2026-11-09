// from server: 100% by auto
// roc 2009-12 0086f7a0  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086f7a0
//
// 0086f7a0  56                   push esi
// 0086f7a1  8bf1                 mov esi, ecx
// 0086f7a3  e888ffffff           call 0x86f730
// 0086f7a8  f644240801           test byte ptr [esp + 8], 1
// 0086f7ad  7406                 je 0x86f7b5
// 0086f7af  56                   push esi
// 0086f7b0  e86f6c0b00           call 0x926424
// 0086f7b5  8bc6                 mov eax, esi
// 0086f7b7  5e                   pop esi
// 0086f7b8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
