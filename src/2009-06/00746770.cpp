// from server: 100% by auto
// roc 2009-06 00746770  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00746770
//
// 00746770  8b442404             mov eax, dword ptr [esp + 4]
// 00746774  56                   push esi
// 00746775  50                   push eax
// 00746776  8bf1                 mov esi, ecx
// 00746778  e8dd30fdff           call 0x71985a
// 0074677d  8bce                 mov ecx, esi
// 0074677f  e8ecdeffff           call 0x744670
// 00746784  5e                   pop esi
// 00746785  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
