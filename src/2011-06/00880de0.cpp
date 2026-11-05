// from server: 100% by auto
// roc 2011-06 00880de0  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00880de0
//
// 00880de0  56                   push esi
// 00880de1  8bf1                 mov esi, ecx
// 00880de3  e888ffffff           call 0x880d70
// 00880de8  f644240801           test byte ptr [esp + 8], 1
// 00880ded  7406                 je 0x880df5
// 00880def  56                   push esi
// 00880df0  e8b7b71400           call 0x9cc5ac
// 00880df5  8bc6                 mov eax, esi
// 00880df7  5e                   pop esi
// 00880df8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
