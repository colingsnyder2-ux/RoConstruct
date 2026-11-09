// from server: 100% by auto
// roc 2011-06 0086bbc0  unit: CXTThemeManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086bbc0
//
// 0086bbc0  56                   push esi
// 0086bbc1  8bf1                 mov esi, ecx
// 0086bbc3  e898fdffff           call 0x86b960
// 0086bbc8  f644240801           test byte ptr [esp + 8], 1
// 0086bbcd  7406                 je 0x86bbd5
// 0086bbcf  56                   push esi
// 0086bbd0  e8d7091600           call 0x9cc5ac
// 0086bbd5  8bc6                 mov eax, esi
// 0086bbd7  5e                   pop esi
// 0086bbd8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
