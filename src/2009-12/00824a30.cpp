// from server: 100% by auto
// roc 2009-12 00824a30  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00824a30
//
// 00824a30  56                   push esi
// 00824a31  8bf1                 mov esi, ecx
// 00824a33  e878f30700           call 0x8a3db0
// 00824a38  f644240801           test byte ptr [esp + 8], 1
// 00824a3d  7406                 je 0x824a45
// 00824a3f  56                   push esi
// 00824a40  e81becffff           call 0x823660
// 00824a45  8bc6                 mov eax, esi
// 00824a47  5e                   pop esi
// 00824a48  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
