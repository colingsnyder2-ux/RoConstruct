// from server: 100% by auto
// roc 2009-12 00871010  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871010
//
// 00871010  56                   push esi
// 00871011  8bf1                 mov esi, ecx
// 00871013  e808feffff           call 0x870e20
// 00871018  f644240801           test byte ptr [esp + 8], 1
// 0087101d  7406                 je 0x871025
// 0087101f  56                   push esi
// 00871020  e8ff530b00           call 0x926424
// 00871025  8bc6                 mov eax, esi
// 00871027  5e                   pop esi
// 00871028  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
