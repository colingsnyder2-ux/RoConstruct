// from server: 100% by auto
// roc 2012-06 009fe930  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009fe930
//
// 009fe930  8b442404             mov eax, dword ptr [esp + 4]
// 009fe934  56                   push esi
// 009fe935  50                   push eax
// 009fe936  8bf1                 mov esi, ecx
// 009fe938  e89381f8ff           call 0x986ad0
// 009fe93d  8bce                 mov ecx, esi
// 009fe93f  e87ce3ffff           call 0x9fccc0
// 009fe944  5e                   pop esi
// 009fe945  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
