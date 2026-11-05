// from server: 100% by auto
// roc 2008-06 0071f9d0  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071f9d0
//
// 0071f9d0  56                   push esi
// 0071f9d1  8bf1                 mov esi, ecx
// 0071f9d3  e8e8feffff           call 0x71f8c0
// 0071f9d8  f644240801           test byte ptr [esp + 8], 1
// 0071f9dd  7406                 je 0x71f9e5
// 0071f9df  56                   push esi
// 0071f9e0  e8b9c50900           call 0x7bbf9e
// 0071f9e5  8bc6                 mov eax, esi
// 0071f9e7  5e                   pop esi
// 0071f9e8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
