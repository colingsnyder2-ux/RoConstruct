// from server: 100% by auto
// roc 2010-06 008292c0  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008292c0
//
// 008292c0  8b442404             mov eax, dword ptr [esp + 4]
// 008292c4  56                   push esi
// 008292c5  50                   push eax
// 008292c6  8bf1                 mov esi, ecx
// 008292c8  e81330f8ff           call 0x7ac2e0
// 008292cd  8bce                 mov ecx, esi
// 008292cf  e87ce3ffff           call 0x827650
// 008292d4  5e                   pop esi
// 008292d5  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
