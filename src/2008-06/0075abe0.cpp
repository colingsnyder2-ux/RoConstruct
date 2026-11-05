// from server: 100% by auto
// roc 2008-06 0075abe0  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0075abe0
//
// 0075abe0  56                   push esi
// 0075abe1  8bf1                 mov esi, ecx
// 0075abe3  e848ffffff           call 0x75ab30
// 0075abe8  f644240801           test byte ptr [esp + 8], 1
// 0075abed  7406                 je 0x75abf5
// 0075abef  56                   push esi
// 0075abf0  e8a9130600           call 0x7bbf9e
// 0075abf5  8bc6                 mov eax, esi
// 0075abf7  5e                   pop esi
// 0075abf8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
