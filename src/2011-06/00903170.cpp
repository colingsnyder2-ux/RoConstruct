// from server: 100% by auto
// roc 2011-06 00903170  unit: CXTButtonThemeOffice2003  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00903170
//
// 00903170  c70124e4ad00         mov dword ptr [ecx], 0xade424
// 00903176  8b4904               mov ecx, dword ptr [ecx + 4]
// 00903179  85c9                 test ecx, ecx
// 0090317b  7407                 je 0x903184
// 0090317d  51                   push ecx
// 0090317e  ff15c81aa400         call dword ptr [0xa41ac8]
// 00903184  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\docmapi.cpp (function ??1_AFX_MAIL_STATE@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/docmapi.cpp
