// from server: 100% by auto
// roc 2007-08 006a3790  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a3790
//
// 006a3790  56                   push esi
// 006a3791  8bf1                 mov esi, ecx
// 006a3793  e838feffff           call 0x6a35d0
// 006a3798  f644240801           test byte ptr [esp + 8], 1
// 006a379d  7406                 je 0x6a37a5
// 006a379f  56                   push esi
// 006a37a0  e8834b0900           call 0x738328
// 006a37a5  8bc6                 mov eax, esi
// 006a37a7  5e                   pop esi
// 006a37a8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
