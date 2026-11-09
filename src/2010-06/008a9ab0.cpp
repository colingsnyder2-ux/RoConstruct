// from server: 100% by auto
// roc 2010-06 008a9ab0  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a9ab0
//
// 008a9ab0  c701cc3fa700         mov dword ptr [ecx], 0xa73fcc
// 008a9ab6  8b4904               mov ecx, dword ptr [ecx + 4]
// 008a9ab9  85c9                 test ecx, ecx
// 008a9abb  7407                 je 0x8a9ac4
// 008a9abd  51                   push ecx
// 008a9abe  ff1584bb9e00         call dword ptr [0x9ebb84]
// 008a9ac4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
