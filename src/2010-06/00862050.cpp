// from server: 100% by auto
// roc 2010-06 00862050  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00862050
//
// 00862050  56                   push esi
// 00862051  8bf1                 mov esi, ecx
// 00862053  e848ffffff           call 0x861fa0
// 00862058  f644240801           test byte ptr [esp + 8], 1
// 0086205d  7406                 je 0x862065
// 0086205f  56                   push esi
// 00862060  e8fbac1100           call 0x97cd60
// 00862065  8bc6                 mov eax, esi
// 00862067  5e                   pop esi
// 00862068  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
