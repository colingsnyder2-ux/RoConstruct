// from server: 100% by auto
// roc 2009-06 00749c40  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00749c40
//
// 00749c40  56                   push esi
// 00749c41  8bf1                 mov esi, ecx
// 00749c43  e868f30700           call 0x7c8fb0
// 00749c48  f644240801           test byte ptr [esp + 8], 1
// 00749c4d  7406                 je 0x749c55
// 00749c4f  56                   push esi
// 00749c50  e8fbebffff           call 0x748850
// 00749c55  8bc6                 mov eax, esi
// 00749c57  5e                   pop esi
// 00749c58  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
