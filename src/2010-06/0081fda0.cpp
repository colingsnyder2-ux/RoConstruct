// from server: 100% by auto
// roc 2010-06 0081fda0  unit: CXTPPropertyGridItemEnum  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fda0
//
// 0081fda0  33c0                 xor eax, eax
// 0081fda2  394104               cmp dword ptr [ecx + 4], eax
// 0081fda5  0f95c0               setne al
// 0081fda8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2003.cpp (function ?IsWindowsThemingSupported@CMFCVisualManagerOffice2003@@UBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2003.cpp
