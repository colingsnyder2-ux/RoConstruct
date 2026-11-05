// from server: 100% by auto
// roc 2007-08 00659110  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00659110
//
// 00659110  8b442404             mov eax, dword ptr [esp + 4]
// 00659114  56                   push esi
// 00659115  50                   push eax
// 00659116  8bf1                 mov esi, ecx
// 00659118  e80578fdff           call 0x630922
// 0065911d  8bce                 mov ecx, esi
// 0065911f  e8ece2ffff           call 0x657410
// 00659124  5e                   pop esi
// 00659125  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
