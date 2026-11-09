// from server: 100% by auto
// roc 2007-08 006ddde0  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ddde0
//
// 006ddde0  56                   push esi
// 006ddde1  8bf1                 mov esi, ecx
// 006ddde3  e8e8feffff           call 0x6ddcd0
// 006ddde8  f644240801           test byte ptr [esp + 8], 1
// 006ddded  7406                 je 0x6dddf5
// 006dddef  56                   push esi
// 006dddf0  e833a50500           call 0x738328
// 006dddf5  8bc6                 mov eax, esi
// 006dddf7  5e                   pop esi
// 006dddf8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
