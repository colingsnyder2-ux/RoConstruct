// from server: 100% by auto
// roc 2008-06 00718610  unit: CXTPPropertyGridItemEnum  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00718610
//
// 00718610  33c0                 xor eax, eax
// 00718612  394104               cmp dword ptr [ecx + 4], eax
// 00718615  0f95c0               setne al
// 00718618  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2003.cpp (function ?IsWindowsThemingSupported@CMFCVisualManagerOffice2003@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2003.cpp
