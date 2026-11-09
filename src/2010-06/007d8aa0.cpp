// from server: 100% by auto
// roc 2010-06 007d8aa0  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d8aa0
//
// 007d8aa0  56                   push esi
// 007d8aa1  8bf1                 mov esi, ecx
// 007d8aa3  e848f40700           call 0x857ef0
// 007d8aa8  f644240801           test byte ptr [esp + 8], 1
// 007d8aad  7406                 je 0x7d8ab5
// 007d8aaf  56                   push esi
// 007d8ab0  e80becffff           call 0x7d76c0
// 007d8ab5  8bc6                 mov eax, esi
// 007d8ab7  5e                   pop esi
// 007d8ab8  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
