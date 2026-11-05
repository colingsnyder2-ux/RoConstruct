// from server: 100% by auto
// roc 2008-06 006d14e0  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006d14e0
//
// 006d14e0  56                   push esi
// 006d14e1  8bf1                 mov esi, ecx
// 006d14e3  e8b8f40700           call 0x7509a0
// 006d14e8  f644240801           test byte ptr [esp + 8], 1
// 006d14ed  7406                 je 0x6d14f5
// 006d14ef  56                   push esi
// 006d14f0  e81becffff           call 0x6d0110
// 006d14f5  8bc6                 mov eax, esi
// 006d14f7  5e                   pop esi
// 006d14f8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
