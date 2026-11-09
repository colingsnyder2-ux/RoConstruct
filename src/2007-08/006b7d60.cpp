// from server: 100% by auto
// roc 2007-08 006b7d60  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b7d60
//
// 006b7d60  8b442404             mov eax, dword ptr [esp + 4]
// 006b7d64  56                   push esi
// 006b7d65  50                   push eax
// 006b7d66  8bf1                 mov esi, ecx
// 006b7d68  e8a342f8ff           call 0x63c010
// 006b7d6d  8bce                 mov ecx, esi
// 006b7d6f  e80ce4ffff           call 0x6b6180
// 006b7d74  5e                   pop esi
// 006b7d75  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
