// from server: 100% by auto
// roc 2011-06 008bf430  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf430
//
// 008bf430  56                   push esi
// 008bf431  8bf1                 mov esi, ecx
// 008bf433  e868feffff           call 0x8bf2a0
// 008bf438  f644240801           test byte ptr [esp + 8], 1
// 008bf43d  7406                 je 0x8bf445
// 008bf43f  56                   push esi
// 008bf440  e867d11000           call 0x9cc5ac
// 008bf445  8bc6                 mov eax, esi
// 008bf447  5e                   pop esi
// 008bf448  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
