// from server: 100% by auto
// roc 2009-06 0077f3d0  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f3d0
//
// 0077f3d0  56                   push esi
// 0077f3d1  8bf1                 mov esi, ecx
// 0077f3d3  e898fdffff           call 0x77f170
// 0077f3d8  f644240801           test byte ptr [esp + 8], 1
// 0077f3dd  7406                 je 0x77f3e5
// 0077f3df  56                   push esi
// 0077f3e0  e8dfca0c00           call 0x84bec4
// 0077f3e5  8bc6                 mov eax, esi
// 0077f3e7  5e                   pop esi
// 0077f3e8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
