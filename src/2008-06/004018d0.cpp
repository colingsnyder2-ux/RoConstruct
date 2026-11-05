// from server: 100% by auto
// roc 2008-06 004018d0  unit: CAboutRobloxDialog  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004018d0
//
// 004018d0  ff15d8228000         call dword ptr [0x8022d8]
// 004018d6  85c0                 test eax, eax
// 004018d8  7e0a                 jle 0x4018e4
// 004018da  25ffff0000           and eax, 0xffff
// 004018df  0d00000780           or eax, 0x80070000
// 004018e4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winctrl3.cpp
