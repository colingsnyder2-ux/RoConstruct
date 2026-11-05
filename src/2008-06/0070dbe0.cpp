// from server: 100% by auto
// roc 2008-06 0070dbe0  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070dbe0
//
// 0070dbe0  56                   push esi
// 0070dbe1  8bf1                 mov esi, ecx
// 0070dbe3  e898fdffff           call 0x70d980
// 0070dbe8  f644240801           test byte ptr [esp + 8], 1
// 0070dbed  7406                 je 0x70dbf5
// 0070dbef  56                   push esi
// 0070dbf0  e8a9e30a00           call 0x7bbf9e
// 0070dbf5  8bc6                 mov eax, esi
// 0070dbf7  5e                   pop esi
// 0070dbf8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
