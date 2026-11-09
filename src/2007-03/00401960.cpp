// from server: 100% by auto
// roc 2007-03 00401960  unit: seg_00400000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401960
//
// 00401960  ff15c0d27700         call dword ptr [0x77d2c0]
// 00401966  85c0                 test eax, eax
// 00401968  7e0a                 jle 0x401974
// 0040196a  25ffff0000           and eax, 0xffff
// 0040196f  0d00000780           or eax, 0x80070000
// 00401974  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl3.cpp
