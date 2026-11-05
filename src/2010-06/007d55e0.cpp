// from server: 100% by auto
// roc 2010-06 007d55e0  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d55e0
//
// 007d55e0  8b442404             mov eax, dword ptr [esp + 4]
// 007d55e4  56                   push esi
// 007d55e5  50                   push eax
// 007d55e6  8bf1                 mov esi, ecx
// 007d55e8  e8e131fdff           call 0x7a87ce
// 007d55ed  8bce                 mov ecx, esi
// 007d55ef  e8ecdeffff           call 0x7d34e0
// 007d55f4  5e                   pop esi
// 007d55f5  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
