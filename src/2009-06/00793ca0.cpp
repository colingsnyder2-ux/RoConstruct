// from server: 100% by auto
// roc 2009-06 00793ca0  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793ca0
//
// 00793ca0  56                   push esi
// 00793ca1  8bf1                 mov esi, ecx
// 00793ca3  e808feffff           call 0x793ab0
// 00793ca8  f644240801           test byte ptr [esp + 8], 1
// 00793cad  7406                 je 0x793cb5
// 00793caf  56                   push esi
// 00793cb0  e80f820b00           call 0x84bec4
// 00793cb5  8bc6                 mov eax, esi
// 00793cb7  5e                   pop esi
// 00793cb8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
