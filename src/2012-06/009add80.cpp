// from server: 100% by auto
// roc 2012-06 009add80  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009add80
//
// 009add80  8b442404             mov eax, dword ptr [esp + 4]
// 009add84  56                   push esi
// 009add85  50                   push eax
// 009add86  8bf1                 mov esi, ecx
// 009add88  e8a351fdff           call 0x982f30
// 009add8d  8bce                 mov ecx, esi
// 009add8f  e8dcdeffff           call 0x9abc70
// 009add94  5e                   pop esi
// 009add95  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
