// from server: 100% by auto
// roc 2008-06 00732a60  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00732a60
//
// 00732a60  8b442404             mov eax, dword ptr [esp + 4]
// 00732a64  56                   push esi
// 00732a65  50                   push eax
// 00732a66  8bf1                 mov esi, ecx
// 00732a68  e843a8f7ff           call 0x6ad2b0
// 00732a6d  8bce                 mov ecx, esi
// 00732a6f  e87ce3ffff           call 0x730df0
// 00732a74  5e                   pop esi
// 00732a75  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
