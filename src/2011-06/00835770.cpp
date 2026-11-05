// from server: 100% by auto
// roc 2011-06 00835770  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00835770
//
// 00835770  8b442404             mov eax, dword ptr [esp + 4]
// 00835774  56                   push esi
// 00835775  50                   push eax
// 00835776  8bf1                 mov esi, ecx
// 00835778  e84557fdff           call 0x80aec2
// 0083577d  8bce                 mov ecx, esi
// 0083577f  e8ecdeffff           call 0x833670
// 00835784  5e                   pop esi
// 00835785  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
