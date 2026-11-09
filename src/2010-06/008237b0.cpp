// from server: 100% by auto
// roc 2010-06 008237b0  unit: CXTPMouseManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008237b0
//
// 008237b0  56                   push esi
// 008237b1  8bf1                 mov esi, ecx
// 008237b3  e888ffffff           call 0x823740
// 008237b8  f644240801           test byte ptr [esp + 8], 1
// 008237bd  7406                 je 0x8237c5
// 008237bf  56                   push esi
// 008237c0  e89b951500           call 0x97cd60
// 008237c5  8bc6                 mov eax, esi
// 008237c7  5e                   pop esi
// 008237c8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
