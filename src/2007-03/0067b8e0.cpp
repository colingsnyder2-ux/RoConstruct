// from server: 100% by auto
// roc 2007-03 0067b8e0  unit: seg_00670000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067b8e0
//
// 0067b8e0  56                   push esi
// 0067b8e1  8bf1                 mov esi, ecx
// 0067b8e3  e8a8fdffff           call 0x67b690
// 0067b8e8  f644240801           test byte ptr [esp + 8], 1
// 0067b8ed  7406                 je 0x67b8f5
// 0067b8ef  56                   push esi
// 0067b8f0  e87ff10b00           call 0x73aa74
// 0067b8f5  8bc6                 mov eax, esi
// 0067b8f7  5e                   pop esi
// 0067b8f8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
