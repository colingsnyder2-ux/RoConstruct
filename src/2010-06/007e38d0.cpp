// from server: 100% by auto
// roc 2010-06 007e38d0  unit: CXTPReportSelectedRows  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e38d0
//
// 007e38d0  8b8164040000         mov eax, dword ptr [ecx + 0x464]
// 007e38d6  83f806               cmp eax, 6
// 007e38d9  7405                 je 0x7e38e0
// 007e38db  83f807               cmp eax, 7
// 007e38de  7506                 jne 0x7e38e6
// 007e38e0  8b8168040000         mov eax, dword ptr [ecx + 0x468]
// 007e38e6  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?GetCurrentSystemTheme@CXTPColorManager@@QBE?AW4XTPCurrentSystemTheme@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
