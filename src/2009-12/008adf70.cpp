// from server: 100% by auto
// roc 2009-12 008adf70  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008adf70
//
// 008adf70  56                   push esi
// 008adf71  8bf1                 mov esi, ecx
// 008adf73  e848ffffff           call 0x8adec0
// 008adf78  f644240801           test byte ptr [esp + 8], 1
// 008adf7d  7406                 je 0x8adf85
// 008adf7f  56                   push esi
// 008adf80  e89f840700           call 0x926424
// 008adf85  8bc6                 mov eax, esi
// 008adf87  5e                   pop esi
// 008adf88  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
