// from server: 100% by auto
// roc 2009-06 0079b0d0  unit: CXTPResourceManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b0d0
//
// 0079b0d0  56                   push esi
// 0079b0d1  8bf1                 mov esi, ecx
// 0079b0d3  e8e8feffff           call 0x79afc0
// 0079b0d8  f644240801           test byte ptr [esp + 8], 1
// 0079b0dd  7406                 je 0x79b0e5
// 0079b0df  56                   push esi
// 0079b0e0  e8df0d0b00           call 0x84bec4
// 0079b0e5  8bc6                 mov eax, esi
// 0079b0e7  5e                   pop esi
// 0079b0e8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
