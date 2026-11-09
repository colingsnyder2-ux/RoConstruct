// from server: 100% by auto
// roc 2007-03 00680b90  unit: seg_00680000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00680b90
//
// 00680b90  56                   push esi
// 00680b91  8bf1                 mov esi, ecx
// 00680b93  e8a8fcffff           call 0x680840
// 00680b98  f644240801           test byte ptr [esp + 8], 1
// 00680b9d  7406                 je 0x680ba5
// 00680b9f  56                   push esi
// 00680ba0  e8cf9e0b00           call 0x73aa74
// 00680ba5  8bc6                 mov eax, esi
// 00680ba7  5e                   pop esi
// 00680ba8  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
