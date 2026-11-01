// from server: 100% by auto
// roc 2009-06 007548d0  unit: CXTPReportSelectedRows  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007548d0
//
// 007548d0  8b8164040000         mov eax, dword ptr [ecx + 0x464]
// 007548d6  83f806               cmp eax, 6
// 007548d9  7405                 je 0x7548e0
// 007548db  83f807               cmp eax, 7
// 007548de  7506                 jne 0x7548e6
// 007548e0  8b8168040000         mov eax, dword ptr [ecx + 0x468]
// 007548e6  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?GetCurrentSystemTheme@CXTPColorManager@@QBE?AW4XTPCurrentSystemTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
