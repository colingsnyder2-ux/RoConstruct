// from server: 100% by auto
// roc 2009-06 007d3370  unit: CXTPDockingPaneKeyboardHook  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d3370
//
// 007d3370  56                   push esi
// 007d3371  8bf1                 mov esi, ecx
// 007d3373  e8e8feffff           call 0x7d3260
// 007d3378  f644240801           test byte ptr [esp + 8], 1
// 007d337d  7406                 je 0x7d3385
// 007d337f  56                   push esi
// 007d3380  e83f8b0700           call 0x84bec4
// 007d3385  8bc6                 mov eax, esi
// 007d3387  5e                   pop esi
// 007d3388  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
