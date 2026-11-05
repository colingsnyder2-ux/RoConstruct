// from server: 100% by auto
// roc 2010-06 0080e420  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e420
//
// 0080e420  56                   push esi
// 0080e421  8bf1                 mov esi, ecx
// 0080e423  e878fdffff           call 0x80e1a0
// 0080e428  f644240801           test byte ptr [esp + 8], 1
// 0080e42d  7406                 je 0x80e435
// 0080e42f  56                   push esi
// 0080e430  e82be91600           call 0x97cd60
// 0080e435  8bc6                 mov eax, esi
// 0080e437  5e                   pop esi
// 0080e438  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
