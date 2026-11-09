// from server: 100% by auto
// roc 2009-06 007a1130  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a1130
//
// 007a1130  8b442404             mov eax, dword ptr [esp + 4]
// 007a1134  56                   push esi
// 007a1135  50                   push eax
// 007a1136  8bf1                 mov esi, ecx
// 007a1138  e88308f8ff           call 0x7219c0
// 007a113d  8bce                 mov ecx, esi
// 007a113f  e87ce3ffff           call 0x79f4c0
// 007a1144  5e                   pop esi
// 007a1145  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxribbonedit.cpp (function ?OnAfterChangeRect@CMFCRibbonEdit@@UAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonedit.cpp
