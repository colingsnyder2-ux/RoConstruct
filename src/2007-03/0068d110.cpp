// from server: 100% by auto
// roc 2007-03 0068d110  unit: seg_00680000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d110
//
// 0068d110  56                   push esi
// 0068d111  8bf1                 mov esi, ecx
// 0068d113  e838feffff           call 0x68cf50
// 0068d118  f644240801           test byte ptr [esp + 8], 1
// 0068d11d  7406                 je 0x68d125
// 0068d11f  56                   push esi
// 0068d120  e84fd90a00           call 0x73aa74
// 0068d125  8bc6                 mov eax, esi
// 0068d127  5e                   pop esi
// 0068d128  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
