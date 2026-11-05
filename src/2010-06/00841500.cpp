// from server: 100% by auto
// roc 2010-06 00841500  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841500
//
// 00841500  56                   push esi
// 00841501  8bf1                 mov esi, ecx
// 00841503  e808feffff           call 0x841310
// 00841508  f644240801           test byte ptr [esp + 8], 1
// 0084150d  7406                 je 0x841515
// 0084150f  56                   push esi
// 00841510  e84bb81300           call 0x97cd60
// 00841515  8bc6                 mov eax, esi
// 00841517  5e                   pop esi
// 00841518  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
