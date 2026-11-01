// from server: 100% by auto
// roc 2009-12 0082f730  unit: CXTPReportSelectedRows  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082f730
//
// 0082f730  8b8164040000         mov eax, dword ptr [ecx + 0x464]
// 0082f736  83f806               cmp eax, 6
// 0082f739  7405                 je 0x82f740
// 0082f73b  83f807               cmp eax, 7
// 0082f73e  7506                 jne 0x82f746
// 0082f740  8b8168040000         mov eax, dword ptr [ecx + 0x468]
// 0082f746  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetCurrentSystemTheme@CXTPColorManager@@QBE?AW4XTPCurrentSystemTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
