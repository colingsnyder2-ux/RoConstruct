// from server: 100% by auto
// roc 2011-06 00838c30  unit: CXTPReportRow_Batch  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00838c30
//
// 00838c30  56                   push esi
// 00838c31  8bf1                 mov esi, ecx
// 00838c33  e8b8a10700           call 0x8b2df0
// 00838c38  f644240801           test byte ptr [esp + 8], 1
// 00838c3d  7406                 je 0x838c45
// 00838c3f  56                   push esi
// 00838c40  e80becffff           call 0x837850
// 00838c45  8bc6                 mov eax, esi
// 00838c47  5e                   pop esi
// 00838c48  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxstate.cpp (function ??_GAFX_MODULE_THREAD_STATE@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstate.cpp
