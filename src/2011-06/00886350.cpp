// from server: 100% by auto
// roc 2011-06 00886350  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00886350
//
// 00886350  8b442404             mov eax, dword ptr [esp + 4]
// 00886354  56                   push esi
// 00886355  50                   push eax
// 00886356  8bf1                 mov esi, ecx
// 00886358  e86384f8ff           call 0x80e7c0
// 0088635d  8bce                 mov ecx, esi
// 0088635f  e87ce3ffff           call 0x8846e0
// 00886364  5e                   pop esi
// 00886365  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
