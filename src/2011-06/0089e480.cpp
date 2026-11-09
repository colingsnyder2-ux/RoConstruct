// from server: 100% by auto
// roc 2011-06 0089e480  unit: CXTPKeyboardManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089e480
//
// 0089e480  56                   push esi
// 0089e481  8bf1                 mov esi, ecx
// 0089e483  e808feffff           call 0x89e290
// 0089e488  f644240801           test byte ptr [esp + 8], 1
// 0089e48d  7406                 je 0x89e495
// 0089e48f  56                   push esi
// 0089e490  e817e11200           call 0x9cc5ac
// 0089e495  8bc6                 mov eax, esi
// 0089e497  5e                   pop esi
// 0089e498  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
