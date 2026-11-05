// from server: 100% by auto
// roc 2008-06 0071ce70  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071ce70
//
// 0071ce70  56                   push esi
// 0071ce71  8bf1                 mov esi, ecx
// 0071ce73  e808feffff           call 0x71cc80
// 0071ce78  f644240801           test byte ptr [esp + 8], 1
// 0071ce7d  7406                 je 0x71ce85
// 0071ce7f  56                   push esi
// 0071ce80  e819f10900           call 0x7bbf9e
// 0071ce85  8bc6                 mov eax, esi
// 0071ce87  5e                   pop esi
// 0071ce88  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
