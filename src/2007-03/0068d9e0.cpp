// from server: 100% by auto
// roc 2007-03 0068d9e0  unit: seg_00680000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d9e0
//
// 0068d9e0  56                   push esi
// 0068d9e1  8bf1                 mov esi, ecx
// 0068d9e3  e888ffffff           call 0x68d970
// 0068d9e8  f644240801           test byte ptr [esp + 8], 1
// 0068d9ed  7406                 je 0x68d9f5
// 0068d9ef  56                   push esi
// 0068d9f0  e87fd00a00           call 0x73aa74
// 0068d9f5  8bc6                 mov eax, esi
// 0068d9f7  5e                   pop esi
// 0068d9f8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
