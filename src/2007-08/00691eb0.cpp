// from server: 100% by auto
// roc 2007-08 00691eb0  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00691eb0
//
// 00691eb0  56                   push esi
// 00691eb1  8bf1                 mov esi, ecx
// 00691eb3  e8a8fdffff           call 0x691c60
// 00691eb8  f644240801           test byte ptr [esp + 8], 1
// 00691ebd  7406                 je 0x691ec5
// 00691ebf  56                   push esi
// 00691ec0  e863640a00           call 0x738328
// 00691ec5  8bc6                 mov eax, esi
// 00691ec7  5e                   pop esi
// 00691ec8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
