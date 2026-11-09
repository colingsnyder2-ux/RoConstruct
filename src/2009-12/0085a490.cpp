// from server: 100% by auto
// roc 2009-12 0085a490  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a490
//
// 0085a490  56                   push esi
// 0085a491  8bf1                 mov esi, ecx
// 0085a493  e898fdffff           call 0x85a230
// 0085a498  f644240801           test byte ptr [esp + 8], 1
// 0085a49d  7406                 je 0x85a4a5
// 0085a49f  56                   push esi
// 0085a4a0  e87fbf0c00           call 0x926424
// 0085a4a5  8bc6                 mov eax, esi
// 0085a4a7  5e                   pop esi
// 0085a4a8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
