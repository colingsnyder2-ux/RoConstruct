// from server: 100% by auto
// roc 2008-06 006ce030  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ce030
//
// 006ce030  8b442404             mov eax, dword ptr [esp + 4]
// 006ce034  56                   push esi
// 006ce035  50                   push eax
// 006ce036  8bf1                 mov esi, ecx
// 006ce038  e88d33fdff           call 0x6a13ca
// 006ce03d  8bce                 mov ecx, esi
// 006ce03f  e8ecdeffff           call 0x6cbf30
// 006ce044  5e                   pop esi
// 006ce045  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
